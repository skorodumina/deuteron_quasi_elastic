#include "Jqe_ana_calc.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TRotation.h"
#include "TLorentzRotation.h"

Jqe_ana_calc::Jqe_ana_calc(float ezero,float current,FF_PARAM_t param){
  init_energy = ezero;
  Itorus = current;
  fftype = param;

  cout << "Jqe_ana_calc object initialized with E=" << init_energy 
       << " Itorus=" << Itorus << endl;

  delta_pars = new Double_t[2];
  delta_pars[0] = 1.232;
  delta_pars[1] = 0.12;

  N1440_pars = new Double_t[2];
  N1440_pars[0] = 1.440;
  N1440_pars[1] = 0.35;
  
  delta_1620_pars = new Double_t[2];
  delta_1620_pars[0] = 1.620;
  delta_1620_pars[1] = 0.15;
  
  //open output file, book histos
  cout << "booking histograms" << endl;
  rootfile = new TFile("Jqe_ana_calc_output.root","RECREATE");
  weight_table_neutron = new TH2F("weight_table_neutron",
  				  "weight_table_neutron",100,-1,1,100,0,0.6);
  weight_table_proton = new TH2F("weight_table_proton","weight_table_proton",
  				 100,-1,1,100,0,0.6);
  ezero_table = new TH2F("ezero_table","ezero_table",100,-1,1,100,0,0.6);
  delta_ezero_table = new TH2F("delta_ezero_table","delta_ezero_table",
  			       100,-1,1,100,0,0.6);
  hult_table = new TH2F("hult_table","hult_table",100,-1,1,100,0,0.6);
  integrated_xsec_table_neutron = new TH2F("integrated_xsec_table_neutron",
  				   "integrated_xsec_table_neutron",100,-1,1,
  					   100,0,0.6);
  integrated_xsec_table_proton = new TH2F("integrated_xsec_table_proton",
  				   "integrated_xsec_table_proton",100,-1,1,
  					  100,0,0.6);
  qsq_neutron = new TH1F("qsq_neutron","qsq_neutron",100,0,5);
  qsq_proton = new TH1F("qsq_proton","qsq_proton",100,0,5);

  wsq_dist = new TH1F("wsq_dist","wsq_dist",100,0,2);
  nu_dist = new TH1F("nu_dist","nu_dist",100,0,4.2);
  wsq_vs_qsq = new TH2F("wsq_vs_qsq","wsq_vs_qsq",100,0,5,100,0,2);
  theta_gn_dist = new TH1F("theta_gn_dist","theta_gn_dist",200,0,10);
  wsq_vs_theta_gn = new TH2F("wsq_vs_theta_gn","wsq_vs_theta_gn",
   			     100,0,10,200,0,3);
  eprime_vs_angle = new TH2F("eprime_vs_angle","eprime_vs_angle",
  			     100,0,60,100,0,5);
  hprime_vs_angle = new TH2F("hprime_vs_angle","hprime_vs_angle",
  			     100,0,80,100,0,5);
  htheta_vs_etheta = new TH2F("htheta_vs_etheta","htheta_vs_etheta",
  			      100,0,60,100,0,80);
  eprime_vs_pfct = new TH2F("eprime_vs_pfct","eprime_vs_pfct",100,-1,1,
  			    100,0,4);
  theta_gn_vs_qsq = new TH2F("theta_gn_vs_qsq","theta_gn_vs_qsq",
  			     100,0,5,200,0,10);

  gmp_histo = new TH1F("gmp_histo","gmp_histo",300,0,5);
  gep_histo = new TH1F("gep_histo","gep_histo",300,0,5);
  gen_histo = new TH1F("gen_histo","gen_histo",300,0,5);
  reduced_xsec_histo_p = new TH1F("reduced_xsec_histo_p",
  				  "reduced_xsec_histo_p",300,0,5);
  reduced_xsec_histo_n = new TH1F("reduced_xsec_histo_n",
  				  "reduced_xsec_histo_n",300,0,5);
  epsilon_histo = new TH1F("epsilon_histo","epsilon_histo",300,0,5);
  epsilon_tau_histo = new TH1F("epsilon_tau_histo","epsilon_tau_histo",300,0,5);
  
  fill_ff_histos();

  //initialize functions
  hult_func = new TF1("hult_func",Hulthen,0,0.75,0);
  rand = new TRandom3(0); //0 sets seed to current clock time
  neutron_xsec = new TF1("neutron_xsec",calc_neutron_xsec,0,PI,3);
  proton_xsec = new TF1("proton_xsec",calc_proton_xsec,0,PI,3); 

}

float Jqe_ana_calc::calc_tau(float qsq, HADRON_TYPE_t htype){
  if(htype == PROTON){
    return qsq/(4*M_proton*M_proton);
  } else{
    return qsq/(4*M_neutron*M_neutron);
  }

}

float Jqe_ana_calc::calc_alpha_sq(float qsq, HADRON_TYPE_t htype){
  float num,denom,mass;

  if(htype==PROTON){
    mass = M_proton;
  } else{
    mass = M_neutron;
  }

  num = qsq;
  denom = 4*init_energy*init_energy - 2*qsq*init_energy/mass;

  return num/denom;
}

float Jqe_ana_calc::calc_epsilon(float qsq, HADRON_TYPE_t htype){
  float tau,alpha_sq,tansq;

  tau = calc_tau(qsq,htype);
  alpha_sq = calc_alpha_sq(qsq,htype);
  tansq = alpha_sq/(1-alpha_sq);

  return 1/(1+2*(1+tau)*tansq);
}

float Jqe_ana_calc::calc_mott_ratio(float qsq){
  float alpha_sq_n,alpha_sq_p,num,denom;

  alpha_sq_n = calc_alpha_sq(qsq,(HADRON_TYPE_t)NEUTRON);
  alpha_sq_p = calc_alpha_sq(qsq,(HADRON_TYPE_t)PROTON);

  num = (1+(2*init_energy/M_neutron)*alpha_sq_n) * 
    (1-alpha_sq_p) * alpha_sq_n * alpha_sq_n;
 
  denom = (1+(2*init_energy/M_proton)*alpha_sq_p) * 
    (1-alpha_sq_n) * alpha_sq_p * alpha_sq_p;

  return num/denom;
}

float Jqe_ana_calc::calc_tau_ratio(float qsq){
  return (1+calc_tau(qsq,(HADRON_TYPE_t)NEUTRON))/(1+calc_tau(qsq,(HADRON_TYPE_t)PROTON));
}

float Jqe_ana_calc::calc_epsilon_tau_ratio(float qsq){
  return calc_epsilon(qsq,(HADRON_TYPE_t)NEUTRON)/calc_tau(qsq,(HADRON_TYPE_t)NEUTRON);
}

float Jqe_ana_calc::calc_ff_factor(float qsq){
  float ge_sq,gm_sq,ratio;

  ge_sq = calc_gep(qsq)*calc_gep(qsq);
  gm_sq = calc_gmp(qsq)*calc_gmp(qsq);
  ratio = calc_tau(qsq,(HADRON_TYPE_t)PROTON)/calc_epsilon(qsq,(HADRON_TYPE_t)PROTON);

  return (ge_sq + ratio*gm_sq);
}

float Jqe_ana_calc::calc_gep(float qsq){
  float q,denom,val;

  switch(fftype){
  case DIPOLE:
    return calc_gd(qsq);
    break;
  case BOSTED:
    q = sqrt(qsq);
    denom = 1.0 + 0.62*q + 0.68*pow(q,(float)2) + 2.80*pow(q,(float)3) 
      + 0.83*pow(q,(float)4);
    val = 1/denom;
    return val;
    break;
  case BRASH:
    return calc_gep_brash(qsq);
    break;
  case ARRINGTON:
    return calc_gep_arrington(qsq);
    break;
  default:
    return 0;
    break;
  }

}

float Jqe_ana_calc::calc_gmp(float qsq){
  float q,denom,val;

  switch(fftype){
  case DIPOLE:
    return 2.793*calc_gd(qsq);
    break;
  case BOSTED:
    q = sqrt(qsq);
    denom = 1.0 + 0.35*q + 2.44*pow(q,(float)2) + 0.50*pow(q,(float)3) 
      + 1.04*pow(q,(float)4) + 0.34*pow(q,(float)5);
    val = 2.793/denom;
    return val;
    break;
  case BRASH:
    return calc_gmp_brash(qsq);
    break;
  case ARRINGTON:
    return calc_gmp_arrington(qsq);
    break;
  default:
    return 0;
    break;
  }

}

float Jqe_ana_calc::calc_gen(float qsq){
  //Double_t gd,val,temp;

  switch(fftype){
  case DIPOLE:
    return 0;
    break;
  case BOSTED:
    /*************
    temp = 1+qsq/0.71;
    gd = pow((double)temp,(double)-2);
    val = (-1.0*1.25*-1.913*calc_tau(qsq,(HADRON_TYPE_t)NEUTRON)*gd) / 
      (1+18.3*calc_tau(qsq,(HADRON_TYPE_t)NEUTRON));
    return val;
    **************/
    return calc_gen_galster(qsq);
    break;
  case BRASH: //uses bosted result
    /******
    temp = 1+qsq/0.71;
    gd = pow((double)temp,(double)-2);
    val = (-1.0*1.25*-1.913*calc_tau(qsq,(HADRON_TYPE_t)NEUTRON)*gd) / 
      (1+18.3*calc_tau(qsq,(HADRON_TYPE_t)NEUTRON));
    return val;
    ********/
    return calc_gen_galster(qsq);
    break;
  case ARRINGTON:
    return calc_gen_galster(qsq);
    break;
  default:
    return 0;
    break;
  }

}

float Jqe_ana_calc::calc_gd(float qsq){
   return pow((double)(1+qsq/0.71),(double)-2.0);
}

void Jqe_ana_calc::extract_gmn(TH1F *hin,TH1F *hout, TH1F *hout_2){
  int i;
  float content,error;
  float val,sigma;
  float qsq;
  float gmn,err;

  for(i=0;i<hin->GetNbinsX();i++){
    content = hin->GetBinContent(i);
    error = hin->GetBinError(i);
    qsq = hin->GetBinCenter(i);

    val = content*calc_mott_ratio(qsq)*calc_tau_ratio(qsq)*calc_ff_factor(qsq);
    sigma = error*calc_mott_ratio(qsq)*calc_tau_ratio(qsq)*calc_ff_factor(qsq);

    cout << "qsq=" << qsq << " ff_factor=" << calc_ff_factor(qsq) << " R=" << content
	 << " ff*R=" << calc_ff_factor(qsq)*content << " Ge^2=" 
	 << calc_gen(qsq)*calc_gen(qsq) << endl; 
    
    val -= calc_gen(qsq)*calc_gen(qsq);
    val *= calc_epsilon_tau_ratio(qsq);
    sigma *= calc_epsilon_tau_ratio(qsq);
    gmn = sqrt(val);
    err = 0.5*(sigma/gmn);

    if(content>0){
      hout->SetBinContent(i,gmn);
      hout->SetBinError(i,err);
      hout_2->SetBinContent(i,gmn/(1.913*calc_gd(qsq)));
      hout_2->SetBinError(i,err/(1.913*calc_gd(qsq)));
    }
  }
}
    
float Jqe_ana_calc::calc_gep_brash(float qsq){
  float ratio;

  ratio = 1.0 - 0.13*(qsq-0.04);
  
  return (ratio/2.793)*calc_gmp_brash(qsq);
}

float Jqe_ana_calc::calc_gmp_brash(float qsq){
  float denom,q;

  q = sqrt(qsq);
  denom = 1 + 0.116*q + 2.874*pow(q,(float)2.0) + 0.241*pow(q,(float)3) 
    + 1.006*pow(q,(float)4) + 0.345*pow(q,(float)5);

  return 2.793/denom;
}

float Jqe_ana_calc::calc_gep_arrington(float qsq){
  float denom,q;

  q = sqrt(qsq);
  denom = 1 -16.44073*q + 59.36728*pow(q,(float)2.0) - 68.84415*pow(q,(float)3.0) + 37.12551*pow(q,(float)4.0)
    - 6.21407*pow(q,(float)5.0);

  return 1/denom;
}

float Jqe_ana_calc::calc_gmp_arrington(float qsq){
  float denom,q;
  
  q = sqrt(qsq);
  denom = 1 + 3.54722*q - 7.31098*pow(q,(float)2.0) + 11.01649*pow(q,(float)3.0) - 3.68674*pow(q,(float)4.0)
    + 1.08228*pow(q,(float)5.0);
  
  return 2.793/denom;
}
  
float Jqe_ana_calc::calc_gen_galster(float qsq){
  //Double_t gd,temp;
  Double_t num,denom,val,eta;

  //galster parameterization
  eta = 5.6;
  num = -1*-1.913*calc_tau(qsq,(HADRON_TYPE_t)NEUTRON)*calc_gd(qsq);
  denom = 1+eta*calc_tau(qsq,(HADRON_TYPE_t)NEUTRON);
  
  val = num/denom;

  return val;
 
}

float Jqe_ana_calc::calc_gmn(float qsq){
  Double_t num,denom;
  Double_t tau;

  tau = qsq/(4*0.9383*0.9383);

  //kelly fit
  num = 1 +2.33*tau;
  denom = 1 + 14.72*tau + 24.20*pow(tau,2.0) + 84.1*pow(tau,3.0);

  return (float)(-1.913*num/denom);
}



float Jqe_ana_calc::calc_elastic_p(float e_theta){
  //calculate momentum of elastically scattered electron from
  //given scattering angle

  float mass,cos_theta;
  float num,denom;

  mass = 0.5*(M_proton+M_neutron);
  cos_theta = cos(jDEG2RAD*e_theta); //input angle is in degrees
  
  num = init_energy;
  denom = 1 + init_energy*(1-cos_theta)*(1/mass);

  return num/denom;
}

void Jqe_ana_calc::generate_expected_neutron_spectrum(TH1F *proton_dist, 
						      TH1F *expected_neutron_dist){
  float num,denom,qsq,ratio,val;
  int i;

  for(i=0;i<proton_dist->GetNbinsX();i++){
    qsq = proton_dist->GetBinCenter(i);
    
    num = calc_epsilon_tau_ratio(qsq)*calc_gen(qsq)*calc_gen(qsq) 
      + 1.913*1.913*calc_gd(qsq)*calc_gd(qsq);
    denom = calc_epsilon_tau_ratio(qsq)*calc_gep(qsq)*calc_gep(qsq) 
      + calc_gmp(qsq)*calc_gmp(qsq);
    ratio = num/denom;
    val = ratio*proton_dist->GetBinContent(i);

    expected_neutron_dist->SetBinContent(i,val);
    expected_neutron_dist->SetBinError(i,sqrt(val));
  }
    
}

float Jqe_ana_calc::calc_elastic_Eprime(Double_t cos_theta){
  float num,denom;

  num = init_energy;
  denom = 1 + (init_energy/M_nucleon)*(1-cos_theta);

  return num/denom;
}

void Jqe_ana_calc::generate_qe_event(HADRON_TYPE_t htype, 
				     vector3_t &expected3, 
				     vector3_t &real3,vector3_t &electron3, 
				     float &Qsq, float &theta_pq,
				     float &phi_pq, float &wsq, float helicity_sign,
				     float pfermi_threshold, int ALTpVersion){
  
  static bool_t is_first = true_;
  vector3_t pfermi3,e_in3,e_out3,nuc3;
  vector3_t e_hat,qvec;
//   vector3_t p_pq_lab;
  vector3_t nuc_hat;

  TLorentzVector beam4, tgt4, e_scatt4, p_pq4, pCM_pq4, deuteron4;
  TLorentzVector neutron4, pCM_n4, pCM_p4, q4, qCM4;
  TVector3 pCM_pq3, beta, pCM_n3, pCM_p3, qCM3, p_pq3, beam3, tgt3, e_scatt3;
  TVector3 neutron3, q3, prod3, reac3, sq3, prod_hat, reac_hat, sqhat;

  vector3_t snorm,rnorm,sqnorm;
  Double_t Eprime, E_N_prime, E_spectator, pfermi;
  Double_t old_Eprime, pfsq, nuc3mag;
  Double_t cos_theta, sin_theta, phi, phi_pq_rad, phi_pq2;
  Double_t scattered_theta;
  Double_t nu, nucleon_theta, theta_q, theta_q2, theta_pq2;
  Double_t ezero_arr[1];
  //Double_t theta_min,theta_max;
  Double_t theta, theta_rf, dtheta, theta_resolution=0.004;
  //Double_t center;
  Double_t rperp,rpar, perp, para;
  Double_t phi_rot, theta_e, Q2=0;
  Double_t Mp=0.938272, Md=1.875613, Mn=0.93956533, pCM_n3mag=0, pLAB_n3mag=0;
  //Double_t par_vec[3],x_vec[0];
  //Double_t E_rf;
  int j, big_enough=0, pfermi_threshold_tries;

  // put the cut on the min and max electron angles here.
 
  if (init_energy > 4.5){ // CLAS12 simulation.
    theta_min_lab = jDEG2RAD*5.0;
    theta_max_lab = jDEG2RAD*37.0;
  } else if (init_energy > 4 and init_energy < 4.5){ //+3375A CLAS6 data
     theta_min_lab = jDEG2RAD*13.0;
     theta_max_lab = jDEG2RAD*65.0;
   } else if(init_energy < 4 && Itorus>0){ //+2250A CLAS6 data
     theta_min_lab = jDEG2RAD*12.0;
     theta_max_lab = jDEG2RAD*52.0;
   } else if(init_energy < 4 && Itorus<0){ //-2250A CLAS6 data
     theta_min_lab = jDEG2RAD*8.0;
     theta_max_lab = jDEG2RAD*45.0;
   } else{
     cout << "error in scattering range selection" << endl;
     exit(0);
   }

  ezero_arr[0] = init_energy;
  
  // generate the weight tabels as functions of p_fermi and theta_N here.

  if(is_first == true_){
    is_first = false_;
    TF1 *cos_func = new TF1("cos_func","cos(x)",-1.0*PI,PI);
    cout << "building xsec weight tables" << endl;
    fill_weight_table_neutron();
    fill_weight_table_proton();
    fill_restframe_xsec_tables();
  }
  
  //setup initial state
  e_in3.z = init_energy;
  e_in3.x = e_in3.y = 0.0;

  //pick fermi momentum in lab frame and direction from xsec table.
  // modified to get more high pfermi events above some threshold.
  // Note this has a potentially infinite loop in it if your threshold
  // is wacky.
  big_enough = 0;
  pfermi_threshold_tries = 0;
  if(htype == PROTON){
    while (big_enough == 0){
      weight_table_proton->GetRandom2(cos_theta,pfermi);
      if (pfermi > pfermi_threshold) {
      	//cout << "passed threshold = " << pfermi_threshold << endl;
       	big_enough=1;
      } else {
      	pfermi_threshold_tries = pfermi_threshold_tries + 1;
      	if (pfermi_threshold_tries > 1000000) {
      	  cout << "No pfermi throws above threshold after 1000000 attempts!!!!!!!!!!!!!!! " << endl;
      	  exit(EXIT_FAILURE);
      	}
      }
    }
  } else{
    weight_table_neutron->GetRandom2(cos_theta,pfermi);
  }
  sin_theta = sqrt(1 - cos_theta*cos_theta);
  phi = 2*PI*rand->Rndm();
  pfermi3.z = pfermi*cos_theta;
  pfermi3.x = pfermi*sin_theta*cos(phi);
  pfermi3.y = pfermi*sin_theta*sin(phi);
  
  //pick scattered electron dir
  // smear the electron angle here for the analysis note stuff. gpg 7/16/08
  theta_rf = get_electron_angle(htype,pfermi,acos(cos_theta));
  theta = calc_theta_lab(init_energy,pfermi,acos(cos_theta),theta_rf);
  //cout << "theta_rf=" << theta_rf << " theta=" << theta << endl;
  dtheta = theta_resolution*rand->Rndm() - (theta_resolution/2);
  theta = theta + dtheta;
  //cout << "dtheta =" << dtheta << " theta=" << theta << endl << endl;

  cos_theta = cos(theta);
  sin_theta = sqrt(1 - cos_theta*cos_theta);
  // comment out the random rotation in phi. it's convenient to do things
  // at phi=0 in order to modify phi_pq below. when we're done with that
  // then we'll rotate all the vectors by a random phi about the 
  // 3-momentum transfer axis.
  // 
  // phi = 2*PI*rand->Rndm();
  phi = 0;
  e_hat.z = cos_theta;
  e_hat.x = sin_theta*cos(phi);
  e_hat.y = sin_theta*sin(phi);
  
  //iterate to find Eprime
  old_Eprime = 0;
  E_spectator = sqrt(M_nucleon*M_nucleon + pfermi*pfermi);
  Eprime = calc_elastic_Eprime(cos_theta); //use elastic value as first guess
  for(j=0;j<1000;j++){
    e_out3 = v3mult(Eprime,e_hat);
      
    nuc3 = v3sub( v3add(e_in3,pfermi3), e_out3);
    pfsq = v3dot(nuc3,nuc3); //p^2 of scattered nucleon
    E_N_prime = sqrt(M_nucleon*M_nucleon + pfsq); //energy of scattered nucleon

    old_Eprime = Eprime;
    Eprime = init_energy + M_deuteron - E_N_prime - E_spectator;

    if( fabs(old_Eprime - Eprime) < 0.0001){
      break;
    }
  }
    
  Eprime = old_Eprime;
  e_out3 = v3mult(Eprime,e_hat);
  qvec = v3sub(e_in3,e_out3);
  nuc3 = v3sub( v3add(e_in3,pfermi3), e_out3);
  nuc3mag = v3mag(nuc3);
  nuc_hat = v3norm(nuc3);

  theta_q = v3angle_deg(qvec,e_in3); 
  theta_e = v3angle_deg(e_in3,e_out3);
  //cout << "theta_e=" << theta_e << " Eprime=" << Eprime << endl << endl;

  // need this later.
  Q2 = 4*init_energy*Eprime*sin(theta_e*jDEG2RAD/2);

  // we now start the calculation of the new modified phi_pq to simulate the
  // fifth structure function.
  //
  // get theta_pq and phi_pq for modified phi_pq.

  snorm = v3norm(v3cross(e_in3,e_out3));
  rnorm = v3norm(v3cross(nuc3,qvec));
  sqnorm = v3norm(v3cross(qvec,snorm));
  theta_pq = v3angle_deg(qvec,nuc3);
  rpar = v3dot(rnorm,snorm);
  rperp = v3dot(rnorm,sqnorm);
  phi_pq = jRAD2DEG*atan2(rperp,rpar);

  // start the process to generate a new phi_pq and calculate the associated 
  // vectors. this is done to mimic the sin(phi_pq) dependence for the ALTp analysis.
  // nuc3 is the 3-vector for the ejected proton. i am using the ROOT routines 
  // herer instead of the ones used above because i'm familiar with them and
  // can't find any documentation for the others.
  //                                         gpg, 8/1/06.

  // generate needed 4-vectors in the lab.
  beam4.SetPxPyPzE(0,0,init_energy,init_energy);
  tgt4.SetPxPyPzE(0.0,0.0,0.0,Md);
  e_scatt4.SetPxPyPzE(e_out3.x, e_out3.y, e_out3.z, Eprime);
  p_pq4.SetPxPyPzE(nuc3.x, nuc3.y, nuc3.z, sqrt(pow(nuc3mag,2) + pow(Mp,2)) );
  // get other 4-vectors in the lab from 4-momentum conservation.
  deuteron4 = beam4 + tgt4 - e_scatt4;
  neutron4 = beam4 + tgt4 - e_scatt4 - p_pq4;
  q4 = beam4 - e_scatt4;

  // vector needed for boosts later.
  beta = -deuteron4.BoostVector();

  // lab 3-momenta
  beam3 = beam4.Vect();
  tgt3 = tgt4.Vect();
  e_scatt3 = e_scatt4.Vect();
  p_pq3 = p_pq4.Vect();
  neutron3 = neutron4.Vect();
  q3 = q4.Vect();

  // get the current phi_pq in the lab system. 
  //   prod - refers to production plane (e and e').
  //   reac - refers to reaction plane (p and q or p and n).
  //   hat - unit vector.
  prod3 = beam3.Cross(e_scatt3);
  prod_hat = prod3.Unit();
  reac3 = p_pq3.Cross(q3);
  reac_hat = reac3.Unit();
  perp = reac_hat.Perp(prod_hat); // component of reac_hat transverse to prod_hat
  para = reac_hat.Dot(prod_hat); // component of reac_hat parallel to prod_hat
  phi_pq_rad = atan2(perp,para);

  // start in the lab.
  pCM_n4 = neutron4; // not boosted to CM system yet.
  pCM_n3 = pCM_n4.Vect();
  theta_q2 = beam3.Angle(q3); // angle of q3.
  pLAB_n3mag = pCM_n3.Mag(); // save the initial neutron lab momentum for later.
  // cout << "before pm= " << pLAB_n3mag << " " << p_pq3.Mag() << endl;
  // rotate the necessary vectors so the z-axis is along q3.
  pCM_n3.RotateY(theta_q2);
  beta.RotateY(theta_q2); // beta is the 3-vec needed for the boost.
  q3.RotateY(theta_q2);
  p_pq3.RotateY(theta_q2);
  // reload 4-vectors (still in the lab) with the rotated components.
  pCM_n4.SetPxPyPzE(pCM_n3.X(), pCM_n3.Y(), pCM_n3.Z(), pCM_n4.E());
  q4.SetPxPyPzE(q3.X(), q3.Y(), q3.Z(), q4.E());
  p_pq4.SetPxPyPzE(p_pq3.X(), p_pq3.Y(), p_pq3.Z(), p_pq4.E());
  // boost to the gamma-D CM frame with the z-axis in the q3 direction..
  pCM_n4.Boost(beta);
  q4.Boost(beta);
  p_pq4.Boost(beta);
  // 3-vecs in gamma-D CM frame.
  pCM_n3 = pCM_n4.Vect();
  q3 = q4.Vect();
  p_pq3 = p_pq4.Vect();
  // pq angles relative to q3.
  theta_pq2 = q3.Angle(pCM_n3);
  phi_pq2 = atan2(pCM_n3.Y(),pCM_n3.X());
  // generate 'new' value of phi_pq2 and 'new' value of pCM_n3.
  pCM_n3mag = pCM_n3.Mag();
  // select the 'new' value at random. this is for the CLAS12 GMn simulation.
  phi_pq2 = generate_ALTp_phi(pLAB_n3mag, Q2, helicity_sign, ALTpVersion);
  //phi_pq2 = 2*PI*rand->Rndm();
  pCM_n3.SetXYZ(pCM_n3mag*sin(theta_pq2)*cos(phi_pq2),
		pCM_n3mag*sin(theta_pq2)*sin(phi_pq2),
		pCM_n3mag*cos(theta_pq2));
  // cout << "after pm= " << pCM_n3mag << " " << p_pq3.Mag() <<  endl;
  // reload 4-vectors in boosted frame.
  pCM_n4.SetPxPyPzE(pCM_n3.X(), pCM_n3.Y(), pCM_n3.Z(), sqrt(pCM_n3*pCM_n3 + Mn*Mn) );
  // unboost.
  pCM_n4.Boost(-beta);
  q4.Boost(-beta);
  // 3-vecs back in lab frame.
  pCM_n3 = pCM_n4.Vect();
  q3 = q4.Vect();
  // rotate back to lab frame with beam along z axis.
  pCM_n3.RotateY(-theta_q2);
  q3.RotateY(-theta_q2);
  // generate the modified neutron 4-vec in the lab along with the modified p_pq4.
  neutron4.SetPxPyPzE(pCM_n3.X(), pCM_n3.Y(), pCM_n3.Z(), sqrt(pCM_n3*pCM_n3 + Mn*Mn));
  neutron3 = neutron4.Vect();
  p_pq4 = beam4 + tgt4 - e_scatt4 - neutron4;
  p_pq3 = p_pq4.Vect();
  // reload q4.
  q4.SetPxPyPzE(q3.X(), q3.Y(), q3.Z(), q4.E());
  // convert back to other format.
  nuc3.x = p_pq3.X();
  nuc3.y = p_pq3.Y();
  nuc3.z = p_pq3.Z();

  // done with modified phi_pq.

//   cout << endl;

  //assign output vectors
  //
  // vectors:  electron3 - final scattered electron momentum 3-vector
  //           expected3 - 3-vector of momentum transfer q.
  //           real3 - 3-vector of proton momentum
  //
  //  all of the above are in the lab.

  phi_rot = PI*(2*rand->Rndm() - 1);
  expected3 = z_rotate(phi_rot,qvec);
  real3 = z_rotate(phi_rot,nuc3);
  electron3 = z_rotate(phi_rot,e_out3);

  //fill diagnostic histograms
  scattered_theta = acos(e_hat.z);
  nucleon_theta = acos(nuc_hat.z);
  Qsq = 4*init_energy*Eprime*pow(sin(scattered_theta/2.0),2.0);
  nu = init_energy - Eprime;
  wsq = M_nucleon*M_nucleon - Qsq +2*M_nucleon*nu;
  if(htype == PROTON){
    qsq_proton->Fill(Qsq);
  } else{
    qsq_neutron->Fill(Qsq);
  }

  snorm = v3norm(v3cross(e_in3,e_out3));
  rnorm = v3norm(v3cross(nuc3,qvec));
  sqnorm = v3norm(v3cross(qvec,snorm));
  theta_pq = v3angle_deg(qvec,nuc3);
  rpar = v3dot(rnorm,snorm);
  rperp = v3dot(rnorm,sqnorm);
  phi_pq = jRAD2DEG*atan2(rperp,rpar);

  if(htype == NEUTRON){
    wsq_dist->Fill(wsq);
    nu_dist->Fill(nu);
    theta_gn_dist->Fill(theta_pq);
    theta_gn_vs_qsq->Fill(Qsq,theta_pq);
    wsq_vs_qsq->Fill(Qsq,wsq);
    wsq_vs_theta_gn->Fill(theta_pq,wsq);
    eprime_vs_angle->Fill(jRAD2DEG*scattered_theta,Eprime);
    hprime_vs_angle->Fill(jRAD2DEG*nucleon_theta,v3mag(nuc3));
    htheta_vs_etheta->Fill(jRAD2DEG*scattered_theta,jRAD2DEG*nucleon_theta);
    eprime_vs_pfct->Fill(pfermi*cos(nucleon_theta),Eprime);
   }

  return;
}

void Jqe_ana_calc::fill_weight_table_neutron(void){
  Double_t hult_val;
  Double_t E_rf;
  int i,j;
  Double_t cos_theta;
  Double_t pfermi,integrated_xsec;
  Double_t theta_min,theta_max,theta_fermi;
  Double_t par_vec[3];

  x_axis = weight_table_neutron->GetXaxis();
  y_axis = weight_table_neutron->GetYaxis();

  for(i=1;i<weight_table_neutron->GetNbinsX();i++){
    for(j=1;j<weight_table_neutron->GetNbinsY();j++){

      pfermi = y_axis->GetBinCenter(j);
      cos_theta = x_axis->GetBinCenter(i);
      theta_fermi = acos(cos_theta);
      E_rf = calc_rest_frame_energy(init_energy,pfermi,theta_fermi);

      par_vec[0] = init_energy;
      par_vec[1] = pfermi;
      par_vec[2] = theta_fermi;

      calc_scattering_range(init_energy,pfermi,theta_fermi,
			    theta_min_lab,theta_max_lab,
			    theta_min,theta_max);
      integrated_xsec = neutron_xsec->Integral(theta_min,theta_max,
					       par_vec,.001);
      hult_val = hult_func->Eval(pfermi);
      
      ezero_table->SetBinContent(i,j,E_rf);
      delta_ezero_table->SetBinContent(i,j,E_rf - init_energy);
      hult_table->SetBinContent(i,j,hult_val);
      integrated_xsec_table_neutron->SetBinContent(i,j,integrated_xsec);
      weight_table_neutron->SetBinContent(i,j,1000*hult_val*integrated_xsec);
    }
  }

  //rootfile->Write();
}

void Jqe_ana_calc::fill_weight_table_proton(void){
  Double_t hult_val;
  Double_t E_rf;
  int i,j;
  Double_t cos_theta;
  Double_t pfermi,integrated_xsec;
  Double_t theta_min,theta_max,theta_fermi;
  Double_t par_vec[3];

  x_axis = weight_table_proton->GetXaxis();
  y_axis = weight_table_proton->GetYaxis();

  for(i=1;i<weight_table_proton->GetNbinsX();i++){
    for(j=1;j<weight_table_proton->GetNbinsY();j++){

      pfermi = y_axis->GetBinCenter(j);
      cos_theta = x_axis->GetBinCenter(i);
      theta_fermi = acos(cos_theta);
      E_rf = calc_rest_frame_energy(init_energy,pfermi,theta_fermi);

      par_vec[0] = init_energy;
      par_vec[1] = pfermi;
      par_vec[2] = theta_fermi;

      calc_scattering_range(init_energy,pfermi,theta_fermi,theta_min_lab,
			    theta_max_lab,
			    theta_min,theta_max);
      integrated_xsec = proton_xsec->Integral(theta_min,theta_max,
					       par_vec,.001);
      hult_val = hult_func->Eval(pfermi);
      
      ezero_table->SetBinContent(i,j,E_rf);
      delta_ezero_table->SetBinContent(i,j,E_rf - init_energy);
      hult_table->SetBinContent(i,j,hult_val);
      integrated_xsec_table_proton->SetBinContent(i,j,integrated_xsec);
      weight_table_proton->SetBinContent(i,j,1000*hult_val*integrated_xsec);
    }
  }

  //rootfile->Write();
}

void Jqe_ana_calc::fill_restframe_xsec_tables(){
  int i,j;
  Double_t x[1],par[3];
  int nbins_theta, nbins_e;
  TAxis *e_axis,*theta_axis;

  nbins_theta = 100;
  nbins_e = 100;

  Emax = calc_rest_frame_energy(init_energy,0.7,-1.0*PI);
  Emin = calc_rest_frame_energy(init_energy,0.7,0);
  cout << "building restframe xsec tables..." 
       << " Emin=" << Emin << " Emax= " << Emax << endl;
  
//   CLAS6 angle range: 10-60 deg. CLAS12 angle range: 5-55 deg.
  neutron_restframe_xsec = new TH2F("neutron_restframe_xsec",
				    "neutron_restframe_xsec",
				    nbins_e,Emin,Emax,nbins_theta,
				    jDEG2RAD*5.0,jDEG2RAD*55.0);

  proton_restframe_xsec = new TH2F("proton_restframe_xsec",
				   "proton_restframe_xsec",
				   nbins_e,Emin,Emax,nbins_theta,
				   jDEG2RAD*5.0,jDEG2RAD*55.0);
  
  //rootfile->Add(neutron_restframe_xsec);
  //rootfile->Add(proton_restframe_xsec);

  par[1] = 0.0; //set pfermi=0
  par[2] = 0.0; //set theta_fermi=0
 
  for(i=0;i<nbins_theta;i++){
    for(j=0;j<nbins_e;j++){
      
      e_axis = neutron_restframe_xsec->GetXaxis();
      theta_axis = neutron_restframe_xsec->GetYaxis();
      par[0] = e_axis->GetBinCenter(j);
      x[0] = theta_axis->GetBinCenter(i);
      neutron_restframe_xsec->SetBinContent(j,i,calc_neutron_xsec(x,par));

      e_axis = proton_restframe_xsec->GetXaxis();
      theta_axis = proton_restframe_xsec->GetYaxis();
      par[0] = e_axis->GetBinCenter(j);
      x[0] = theta_axis->GetBinCenter(i);
      proton_restframe_xsec->SetBinContent(j,i,calc_proton_xsec(x,par));
    }
  }

  //rootfile->Write();
}

float Jqe_ana_calc::get_electron_angle(HADRON_TYPE_t htype,float pfermi, 
				       float theta_fermi){
  TH1D *projy;
  TAxis *e_axis;
  int ebin, icounter;
  float angle;
  float E_rf;
  float theta_min_rf,theta_max_rf;

  E_rf = calc_rest_frame_energy(init_energy,pfermi,theta_fermi);
  theta_min_rf = calc_theta_rf(init_energy,pfermi,theta_fermi,theta_min_lab);
  theta_max_rf = calc_theta_rf(init_energy,pfermi,theta_fermi,theta_max_lab);
  // cout << "theta_min_rf=" << theta_min_rf << endl;

  if(E_rf > Emax) E_rf = Emax;

  angle = 0.0;
  if(htype == NEUTRON){
    e_axis = neutron_restframe_xsec->GetXaxis();
    ebin = e_axis->FindBin(E_rf);
    projy = neutron_restframe_xsec->ProjectionY("",ebin,ebin);
    while(angle<theta_min_rf){
      angle = projy->GetRandom();
    }
    //cout << "e-n, electron angle=" << angle << endl;
  } else if(htype == PROTON){
    e_axis = proton_restframe_xsec->GetXaxis();
    ebin = e_axis->FindBin(E_rf);
    projy = proton_restframe_xsec->ProjectionY("",ebin,ebin);
    icounter = 0;
    while(angle<theta_min_rf){
      angle = projy->GetRandom();
      icounter++;
    }
    //cout << "e-p, electron angle=" << angle << " E_rf=" << E_rf << " counter=" << icounter << endl;
  } else{
    angle = 0;
  }

  return angle;

}
  
void Jqe_ana_calc::close_histos(void){
  rootfile->Write();
}


void Jqe_ana_calc::fill_ff_histos(){
  int i;
  float qsq,gmp,gep,gen,gmn,xsec,ratio;

  for(i=0;i<gmp_histo->GetNbinsX();i++){
    qsq = gmp_histo->GetBinCenter(i);
    
    gen_histo->SetBinContent(i,calc_gen(qsq));
    
    gmp = calc_gmp(qsq);
    gep = calc_gep(qsq);
    ratio = calc_tau(qsq,(HADRON_TYPE_t)PROTON)/calc_epsilon(qsq,(HADRON_TYPE_t)PROTON);
    xsec = gep*gep + ratio*gmp*gmp;
    gmp_histo->SetBinContent(i,gmp);
    gep_histo->SetBinContent(i,gep);
    reduced_xsec_histo_p->SetBinContent(i,xsec);
    
    gmn = calc_gmn(qsq);
    gen = calc_gen(qsq);
    ratio = calc_tau(qsq,(HADRON_TYPE_t)NEUTRON)/calc_epsilon(qsq,(HADRON_TYPE_t)NEUTRON);
    xsec = gen*gen + ratio*gmn*gmn;   
    reduced_xsec_histo_n->SetBinContent(i,xsec);
    

    epsilon_histo->SetBinContent(i,calc_epsilon(qsq,(HADRON_TYPE_t)NEUTRON));
    epsilon_tau_histo->SetBinContent(i,1/ratio);

  }

  //rootfile->Write();

}

float Jqe_ana_calc::generate_ALTp_phi(float pfermi2, float Q2, float helicity_sign, int ALTpVersion) {

  // use van neumann rejection to pick phi from a distribution that
  // is 1 + amp*sin(phi).

  float x1, x2, fnvalue, phi=0, amp;
  //  float peak=-0.17;
  //  float wid=0.065;
  //  float pfermi20=0.25;
  //  peak=0.5;
  //  wid=0.035;
  //  pfermi20=0.15;

  // float amp = -0.0385*exp( -(pfermi2-0.231)*(pfermi2-0.231)/(2*0.0558*0.0558) );
  //     amp = -helicity_sign*0.20*exp( -(pfermi2-0.15)*(pfermi2-0.15)/(2*0.03*0.03) );
//   amp =  helicity_sign*0.1;
//   float amp = -helicity_sign*(1.2*Q2 - 0.15)*peak*exp(-(pfermi2-pfermi20)*(pfermi2-pfermi20)/(2.0*wid*wid));
//  float amp = -helicity_sign*0.5*((0.05*pfermi2) + (-8.0*pfermi2*pfermi2) + (-5.0*pfermi2*pfermi2*pfermi2))*exp(-10.0*pfermi2);

// amp from Calina's thesis for normal polarity.
  //amp = -helicity_sign*((-0.0344*pow(pfermi2,2) + 0.3204*pow(pfermi2,4))/(1 - 11.1479*pow(pfermi2,1) + 35.4709*pow(pfermi2,2) - 119.206*pow(pfermi2,4) + 227.042*pow(pfermi2,6)));


  if (ALTpVersion == 1) {
    // amp and maxamp from Liam fits (2013) to normal polarity data.
    //amp = -helicity_sign*(-0.0300*pow(pfermi2,2) + 0.2500*pow(pfermi2,4))/(1 - 10.8248*pow(pfermi2,1) + 35.8475*pow(pfermi2,2) - 148.861*pow(pfermi2,4) + 358.321*pow(pfermi2,6));
    // gpg fits (2014) to normal polarity data.
    amp = -helicity_sign*(-0.0320*pow(pfermi2,2) + 0.2300*pow(pfermi2,4))/(1 - 10.7458*pow(pfermi2,1) + 35.6440*pow(pfermi2,2) - 147.00*pow(pfermi2,4) + 361.00*pow(pfermi2,6));
  }
  else if (ALTpVersion == 2) {
    // amp and maxamp from Liam fits (2013) to reversed polarity data.
    amp = -helicity_sign*(-0.0676*pow(pfermi2,2) - 0.0153*pow(pfermi2,4))/(1 - 9.7132*pow(pfermi2,1) + 26.8037*pow(pfermi2,2) - 10.8657*pow(pfermi2,4) + 1.194*pow(pfermi2,6));
  }
  else
  {
    phi = 2*PI*rand->Rndm();
    return phi;
  }

  int done = 0;
  int icounter;
  while (done == 0) {
    x1 = (1 + fabs(amp))*rand->Rndm();
    x2 = 2*PI*rand->Rndm();
    fnvalue = 1 + amp*sin(x2);
    if (x1 < fnvalue) {
      done = 1;
      phi = x2;
    }
    icounter++;
  } // end of while.

  return phi;

}



/********************non-object utilities********************************/

Double_t Hulthen(Double_t *x, Double_t *par){
  Double_t p2,hult;

  //hulthen parameters
  Double_t A2 = 2.088e-3;
  Double_t B2 = 6.76e-2;

  p2 = x[0]*x[0];

  /*****
  p2 /= 1.5;
  A2 *= 1.2;
  ***/

  hult = ((p2+A2)*(p2+B2));
  hult = p2*pow(hult,-2.0);
  
  return hult;
  /***
  if(x[0]<0.5){
    return 1;
  } else{
    return 0;
  }
  ***/

}

Double_t BW(Double_t *x, Double_t *par){
  Double_t e,e0,gamma;

  e = x[0];
  e0 = par[0];
  gamma = par[1];

  return 1/( (e-e0)*(e-e0) + (gamma/2)*(gamma/2));
}

Double_t McGee(Double_t *x, Double_t *par){
  return get_mcgee_p(x[0]);
}

Double_t get_mcgee_p(Double_t pval){
  float p,s,d,a,b,c;
  int counter;
  static bool_t is_first = true_;
  char line[512];
  static Double_t p_arr[250];
  static Double_t wav_arr[250]; 
  static TSpline3 *spline;

  if(is_first == true_){
    cout << "reading in McGee parameter file" << endl;
    ifstream f_in("/home/lachniet/qe/mcgeep.dat");
    if(!f_in){
      cout << "couldn't open McGee parameter file" << endl;
      exit(0);
    }
    counter = 0;
    while(f_in.getline(line,512)){
      sscanf(line,"%f,%f,%f,%f%f%f",&p,&s,&d,&a,&b,&c);
      if(p>500) break;
      p_arr[counter] = p/1000;
      wav_arr[counter] = p*p*(d*d+s*s);
      counter++;
    }

    spline = new TSpline3("spline",p_arr,wav_arr,counter);
    is_first = false_;
  }

  return spline->Eval(pval);
}

Double_t calc_neutron_xsec(Double_t *x, Double_t *par){
  Double_t Ebeam,pfermi,theta_fermi,theta_rf;
  Double_t E_rf,res,a,b,qsq;
  
  //all angle arguments passed and received in radians

  theta_rf = x[0];
  Ebeam = par[0];
  pfermi = par[1];
  theta_fermi = par[2];

  E_rf = calc_rest_frame_energy(Ebeam,pfermi,theta_fermi);

  qsq = calc_qsq(E_rf,theta_rf);

  a = ge_n(qsq)*ge_n(qsq) + tau(qsq)*gm_n(qsq)*gm_n(qsq);
  a /= (1+tau(qsq));

  b = 2*tau(qsq)*gm_n(qsq)*gm_n(qsq)*tan(theta_rf/2.0);

  res = mott_xsec(E_rf,theta_rf)*(a+b)*jacobian(x,par);
  
  return res;
}

Double_t calc_proton_xsec(Double_t *x, Double_t *par){
  Double_t Ebeam,pfermi,theta_fermi,theta_rf;
  Double_t E_rf,res,a,b,qsq;

  //all angle arguments passed and received in radians

  theta_rf = x[0];
  Ebeam = par[0];
  pfermi = par[1];
  theta_fermi = par[2]; 

  E_rf = calc_rest_frame_energy(Ebeam,pfermi,theta_fermi);

  qsq = calc_qsq(E_rf,theta_rf);
  a = ge_p(qsq)*ge_p(qsq) + tau(qsq)*gm_p(qsq)*gm_p(qsq);
  a /= (1+tau(qsq));

  b = 2*tau(qsq)*gm_p(qsq)*gm_p(qsq)*tan(theta_rf/2.0);

  res = mott_xsec(E_rf,theta_rf)*(a+b)*jacobian(x,par);

  return res;
}

Double_t mott_xsec(Double_t ezero, Double_t theta){
  Double_t res;
  Double_t eprime,qsq;
  static Double_t alpha_sq = 5.3279e-5;
  
  eprime = ezero/(1+(ezero/M_nucleon)*(1-cos(theta))); 
  qsq = 4*ezero*eprime*pow(sin(theta/2),2);
  
  res = alpha_sq;
  res *= 1/(4*ezero*ezero*pow(sin(theta/2),4.0));
  res *= eprime/ezero;
  res *= (pow(cos(theta/2),2) + (qsq/2*M_nucleon)*pow(sin(theta/2),2.0));

  return res;
}

/****ignore this--use new version
void calc_scattering_range(Double_t init_energy, Double_t Itorus,
			   vector3_t beta_vec,Double_t ezero,
			   Double_t &theta_min, Double_t &theta_max){ 
  vector4_t ein,eout_min,eout_max;
  vector4_t ein_b,eout_min_b,eout_max_b;
  Double_t eprime,cos_theta_min,cos_theta_max;
  
  if(init_energy > 4){ //+3375A data
    theta_min = jDEG2RAD*14.0;
    theta_max = jDEG2RAD*52.0;
  } else if(init_energy < 4 && Itorus>0){ //+2250A data
    theta_min = jDEG2RAD*12.0;
    theta_max = jDEG2RAD*52.0;
  } else if(init_energy < 4 && Itorus<0){ //-2250A data
    theta_min = jDEG2RAD*8.0;
    theta_max = jDEG2RAD*45.0;
  } else {
    cout << "error in scattering range selection" << endl;
    exit(0);
  }

  ein.t = ezero;
  ein.space.z = ezero;
  ein.space.x = ein.space.y = 0;

  eprime = ezero/(1+(ezero/M_nucleon)*(1-cos(theta_min)));
  eout_min.t = eprime;
  eout_min.space.z = eprime*cos(theta_min);
  eout_min.space.x = eprime*sin(theta_min);
  eout_min.space.y = 0.0;

  eprime = ezero/(1+(ezero/M_nucleon)*(1-cos(theta_max)));
  eout_max.t = eprime;
  eout_max.space.z = eprime*cos(theta_max);
  eout_max.space.x = eprime*sin(theta_max);
  eout_max.space.y = 0.0;
  
  ein_b = v4boost(ein,beta_vec);
  eout_min_b = v4boost(eout_min,beta_vec);
  eout_max_b = v4boost(eout_max,beta_vec);

  cos_theta_min = 1 - ((ein.t*eout_min.t)/(ein_b.t*eout_min_b.t))*(1-cos(theta_min));
  cos_theta_max = 1 - ((ein.t*eout_max.t)/(ein_b.t*eout_max_b.t))*(1-cos(theta_max));

  if(fabs(cos_theta_min) > 1.0 || fabs(cos_theta_max) > 1.0){
    cout << "$#$#$#$@$#%$%$#$##$#$%#^#%^" << endl;
    cout << "angle out of bounds" << endl;
    theta_min = 0;
    theta_max = 90.0;
  }

  theta_min = acos(cos_theta_min);
  theta_max = acos(cos_theta_max);
}
***/

void calc_scattering_range(Double_t Ebeam, Double_t pfermi,
			   Double_t theta_fermi, Double_t theta_min_lab,
			   Double_t theta_max_lab, Double_t &theta_min, 
			   Double_t &theta_max){
  
  theta_min = calc_theta_rf(Ebeam,pfermi,theta_fermi,theta_min_lab);
  theta_max = calc_theta_rf(Ebeam,pfermi,theta_fermi,theta_max_lab);
}

vector4_t v4boost(vector4_t vec, vector3_t beta){
  float gamma,beta_sq;
  vector4_t res;
  
  beta_sq = v3dot(beta,beta);
  gamma = pow((double)(1-beta_sq),(double)-0.5);

  //from Jackson eqn 11.19
  res.t = gamma*(vec.t - v3dot(beta,vec.space));
  res.space = vec.space; 
  res.space = v3add(res.space,
		    v3mult( ((gamma-1)/beta_sq)*v3dot(beta,vec.space),beta)); 
  res.space = v3add(res.space,v3mult(-1.0*gamma*vec.t,beta));

  return res;
}

//Brash parameterization of nucleon form factors

Double_t ge_p(Double_t qsq){
  Double_t denom,val,q;
  
  q = sqrt(qsq);
  denom = 1.0 + 0.62*q + 0.68*pow(q,2) + 2.80*pow(q,3) + 0.83*pow(q,4);
  val = 1/denom;

  return val;
}

Double_t gm_p(Double_t qsq){
  Double_t q,denom,val;

  q = sqrt(qsq);
  denom = 1.0 + 0.35*q + 2.44*pow(q,2) + 0.50*pow(q,3) + 1.04*pow(q,4)
    + 0.34*pow(q,5);
  
  val = 2.793/denom;
  return val;
}

Double_t ge_n(Double_t qsq){
  Double_t gd,val,temp;

  temp = 1+qsq/0.71;
  gd = pow(temp,-2);
  val = (-1.0*1.25*-1.913*tau(qsq)*gd)/(1+18.3*tau(qsq));

  return val;
}

Double_t gd(Double_t qsq){
  return pow(1+qsq/0.71,-2.0);
}

Double_t gm_n(Double_t qsq){
  Double_t q,denom,val;

  q = sqrt(qsq);
  denom = 1.0 - 1.74*q + 9.29*pow(q,2) - 7.63*pow(q,3) + 4.63*pow(q,4);
  val = -1.913/denom;

  return val;
}
  
Double_t tau(Double_t qsq){
  return  qsq/(4*0.93828*0.93828);
}

Double_t epsilon(Double_t qsq, Double_t ezero){
  Double_t tansq,alphasq;
  Double_t denom,val;

  alphasq = qsq/(4*ezero*ezero-2*qsq*ezero/0.938);
  tansq = alphasq/(1-alphasq);
  
  denom = 1+2*(1+tau(qsq))*tansq;
  val = 1/denom;

  return val;
}

Double_t calc_eprime(Double_t ezero,Double_t theta){
  Double_t res;
  
  res = ezero;
  res /= (1+(ezero/M_nucleon)*(1-cos(theta)));

  return res;
}


Double_t calc_qsq(Double_t ezero, Double_t theta){
  Double_t eprime,res;

  eprime = calc_eprime(ezero,theta);
  res = 4*ezero*eprime*sin(theta/2.0);

  return res;
}

vector3_t z_rotate(float phi, vector3_t vec){
  //rotate a given vector by phi about the z-axis

  vector3_t result;
  result.z = vec.z;

  result.x = vec.x * cos(phi) + vec.y * sin(phi);
  result.y = vec.x * (-1.0*sin(phi)) + vec.y * cos(phi);

  return result;
}
  
vector3_t y_rotate(float phi, vector3_t vec){
  //rotate a given vector by phi about the y-axis

  vector3_t result;
  result.y = vec.y;

  result.x = vec.x * cos(phi) + vec.z * (-1.0*sin(phi));
  result.z = vec.x * sin(phi) + vec.z * cos(phi);

  return result;
}
  
Double_t calc_rest_frame_energy(Double_t Ebeam,Double_t pfermi,
				Double_t theta_fermi){ 
  Double_t E_rf,E_n;

  //calculates energy of electron in nucleon rest frame

  E_n = sqrt(M_nucleon*M_nucleon + pfermi*pfermi);
  E_rf = (1/M_nucleon)*Ebeam*(E_n - pfermi*cos(theta_fermi));

  return E_rf;
}

Double_t calc_theta_rf(Double_t Ebeam,Double_t pfermi,
				Double_t theta_fermi,Double_t theta_lab){
  Double_t E_rf,E_n;
  Double_t arg1,arg2,theta_rf;
  
  //calculates rest frame electron scattering angle given lab frame scattering 
  //angle
  
  E_rf = calc_rest_frame_energy(Ebeam,pfermi,theta_fermi);
  E_n = sqrt(M_nucleon*M_nucleon + pfermi*pfermi);

  arg1 = (1-cos(theta_lab))/
    (E_n - pfermi*cos(theta_lab-theta_fermi));

  arg1 *= (M_nucleon*Ebeam/E_rf);

  arg2 = 1 - arg1;

  if(arg2<=1 && arg2>=-1){
    theta_rf = acos(arg2);
  } else{
    // cout << "at theta_rf = " << theta_rf << " arg=" << arg << endl;
    theta_rf = 0;
  }

  return theta_rf;
}

Double_t calc_theta_lab(Double_t Ebeam, Double_t pfermi, Double_t theta_fermi,
			Double_t theta_rf){
  Double_t theta_min,theta_max,theta_mid;
  Double_t epsilon,epsilon_min;
  int iter = 0;

  //calculates lab frame electron scattering angle given rest frame scattering
  //angle using simple-minded bisection method.
  
  epsilon_min = 0.001;

  theta_min = 0;
  theta_max = PI;
  theta_mid = 0.5*(theta_min+theta_max);
  epsilon = calc_theta_rf(Ebeam,pfermi,theta_fermi,theta_mid) - theta_rf;
  
  while( fabs(epsilon) > epsilon_min){
    theta_mid = 0.5*(theta_min+theta_max);
    epsilon = calc_theta_rf(Ebeam,pfermi,theta_fermi,theta_mid) - theta_rf;
    if(epsilon < 0){
      theta_min = theta_mid;
    } else if(epsilon > 0){
      theta_max = theta_mid;
    }
    iter++;
    if(iter>500){
      cout << "couldn't find solution at: pfermi=" << pfermi << " theta_fermi=" 
	   << theta_fermi << " theta_rf=" << theta_rf <<  " ...bailed" << endl;
      return theta_rf;
    }
  }

  return theta_mid;
}

Double_t theta_rf_f1(Double_t *x, Double_t *par){
  Double_t theta_lab,Ebeam,pfermi,theta_fermi;

  theta_lab = x[0];
  Ebeam = par[0];
  pfermi = par[1];
  theta_fermi = par[2];

  return calc_theta_rf(Ebeam,pfermi,theta_fermi,theta_lab);
}

Double_t jacobian(Double_t *x, Double_t *par){
  Double_t theta_lab,theta_rf,Ebeam;
  Double_t arg1,arg2,pfermi,theta_fermi;
  static TF1 *get_theta_rf = new TF1("get_theta_rf",theta_rf_f1,0,PI,3);

  theta_rf = x[0];
  Ebeam = par[0];
  pfermi = par[1];
  theta_fermi = par[2];


  if(pfermi == 0.0){
    return 1.0;
  }

  theta_lab = calc_theta_lab(Ebeam,pfermi,theta_fermi,theta_rf);
  arg1 = sin(theta_rf)/sin(theta_lab);
  
  arg2 = get_theta_rf->Derivative(theta_lab,par);

  return arg1*arg2;
}

