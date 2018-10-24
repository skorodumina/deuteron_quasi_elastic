#include "TROOT.h"
#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "THnSparse.h"
#include "TH3.h"
#include "TF1.h"
#include "TF2.h"
#include "TF3.h"
#include "TMacro.h"
#include "TCanvas.h"
#include "TVirtualFitter.h"
#include "TMath.h"
#include <math.h>
#include "TGraphErrors.h"
#include "TGraph.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TH3F.h"
#include "TText.h"
#include "TStyle.h"
#include "TGObject.h"
#include "TObject.h"
#include "TSystem.h"
#include "TMinuit.h"
#include <TRint.h>
#include <stdio.h>
#include <dlfcn.h>
#include <TGClient.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <TGButton.h>
#include <TGFrame.h>
#include <TRootEmbeddedCanvas.h>
#include <TGButtonGroup.h>
#include <RQ_OBJECT.h>
#include <TGNumberEntry.h>
#include <TGProgressBar.h>
#include <TGLabel.h>
#include <stdio.h>
#include <dlfcn.h>
#include "MyMainFrame.h"
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <TGFileDialog.h>
#include <GuiTypes.h>
#include <TGDoubleSlider.h>
#include <TGComboBox.h>
#include <TLeaf.h>
#include <TBranch.h>
#include <TLorentzVector.h>
#include <TError.h> 
#include <auto_ptr.h>
#ifndef __CINT__
#include <cstdlib>
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include <RooLandau.h> 
#include <RooNumConvPdf.h>
#include <RooDataHist.h>
#include "RooBinning.h"
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <cstring>
#include <getopt.h>
#include <cstdlib>
#include "global.h"
#include "output.h"



 using namespace std; 
 

#define _USE_MATH_DEFINES


    void MyMainFrame::MainFrame(UChar_t flag, Float_t E_beam, Short_t nfiles, Short_t nfiles_empty, Short_t nfiles_sim, string inp_files[],string inp_files_empty[], string inp_files_sim[], string outfile_in) { 


	inpfile_inp = inp_files[0];
	outfile_inp = outfile_in;
	
	E0 = E_beam;

        n_files = nfiles;
	n_files_empty = nfiles_empty;
	n_files_sim = nfiles_sim;

//sozdaem massiv strok (novie)
        file = new string[nfiles];
	file_empty = new string[nfiles_empty];
	file_sim = new string[nfiles_sim];

//prisvaevaem novim massivam strok massivi strok iz input faila 
        file = inp_files;
	file_empty = inp_files_empty;
	file_sim = inp_files_sim;
	data_sim = flag;
	

DoDraw();


   
}

void MyMainFrame::DoDraw() {

 
 
       t20tot21(); 
   
}








    void MyMainFrame::t20tot21() { 
     gROOT->SetBatch(true);
gROOT->ProcessLine( "gErrorIgnoreLevel = kWarning; " );
    ostringstream adc_num;
    ostringstream tdc_num;
    ostringstream ref_tdc;
    ostringstream qqq;
    ostringstream qqq1;
    
	 
    Long64_t j;
 Double_t fract_integ[3][6][18];   
 Double_t * adc_offset;
 adc_offset = new Double_t [12];
 Double_t * adc_cut;
 adc_cut = new Double_t [12]; 
 Short_t m, ti;
 Long64_t i,nstart,nstop,n_incl,n_elast, k_long;
 
 
TH1I *hist_adc_off[12]; 

 TFile *finp;
 Int_t block_total = 0;
 Int_t block_last = 0;
 Float_t Qfull = 0.;
  Float_t Qfull_empty = 0.;
  Float_t Qfull_sim = 0.; 
 
  Int_t block_curr = 0;
 Int_t block_prev = 0;
  Short_t m_old=0;
  
Float_t Epeak[13] = {1.739, 1.694, 1.649, 1.602, 1.556, 1.51, 1.464, 1.418, 1.374, 1.33, 1.287, 1.246, 1.206};  
  
  
   Float_t P_EL_old,th_EL_old,Q2_old,P_EL_new,th_EL_new,W_new,Q2_new;
 bool selection;
 bool selection_pim_miss, selection_0_miss;
 bool selection_pim_miss_sim, selection_0_miss_sim;
 bool selection_pim_miss_empt, selection_0_miss_empt; 
 

 
  
	UChar_t pdhit;
	
	
	Float_t * p; 
        p = new Float_t [20];
	
        Float_t m_deutron,NpheCC_EL,Nphe_pip,Nphe_pim,ECtot_EL;
	Float_t p_miss_1,p_miss_2,p_miss_3,p_miss_4,p_miss_sqr;
	Float_t beta_nom_pip,beta_nom_pim,beta_nom_p,delta_t_pip,delta_t_pim,delta_t_p;
	Float_t p_fid_a_1, p_fid_b_1;
	Float_t  x_EL,y_EL;
	Float_t  ECin_EL,ECout_EL;
	Int_t block, block_tot;
        Long64_t gpart,k,last_i,last_k;
	Float_t  q_l,Qdiff,Qcurr,Qprev,Qtotal,deltaQ;
	Int_t sc_part_local;
	Float_t sc_pd_local,sc_sect_local;
	Float_t sc_z,fid_a,fid_b,a,b;
	Float_t nx,ny,nz,par1,par2,th_min;
	Float_t sx,sy,sz,px,py,pz;
	Float_t delta_mom_p; 
	Double_t delta_p_el_sim; 
	Float_t E_gamma,E_p_gamma_lab,P_p_gamma_lab,beta1,gamma;
	Float_t pip_fid_a_1,pip_fid_b_1;
	Float_t th_min_1,par1_1,par2_1, pim_fid_a_1,pim_fid_b_1;
	Float_t W_old;
	Float_t pf_x,pf_y,pf_z,pxel_new,pyel_new,pzel_new;
   	Double_t integ, err, err1, old_bin_cont, new_bin_cont;
	
	Double_t Var1[5],Var2[5],Var3[5]; 
	Double_t Var_1[5],Var_2[5],Var_3[5]; 
	
 	bool cut_fiduch;
	bool bool_el_id_data;
	bool bool_el_id_sim;
	

	
	m_proton = 0.938272;
	//m_proton = 0.93957;
	m_deutron = 1.875612;
	m_pip = 0.13957;
	  
  
	TLorentzVector P4_D,P4_P,P4_PIm_miss,P4_PIp_miss,P4_PIp_miss_d,P4_P_miss,P4_PIm_miss_0;
	TLorentzVector P4_PP_rot,P4_PP_rot_1,P4_PP_rot_2,P4_PP_rot_3,P4_PP_rot_2_boost;
	TLorentzVector  P4_PP_cor, P4_PIp_cor, P4_PIm_cor;
	TLorentzVector  P4_miss_0,P4_miss_0_d,P4_PIm_miss_d;
	TLorentzVector  P4_miss_0_en_comp,P4_PIm_miss_en_comp;
	TLorentzVector  P4_ELP_for_miss_en_comp;
	
	TVector3 V3_dir_gamma,P3_PP_rot,uz,ux;
		
	Float_t th_gamma, phi_gamma;
		 
	P4_EL.SetXYZT(0,0,2.039,2.039);
	
	 


global();



        TFile *nphefile = new TFile("norm_nphe_5july18_aft_cc_match_gt50.root","READ");
	
	
        norm_nphe_s1 = (TH2F*)nphefile->Get("h_cc_nphe_final_s1");
	norm_nphe_s2 = (TH2F*)nphefile->Get("h_cc_nphe_final_s2");
	norm_nphe_s3 = (TH2F*)nphefile->Get("h_cc_nphe_final_s3");
	norm_nphe_s4 = (TH2F*)nphefile->Get("h_cc_nphe_final_s4");
	norm_nphe_s5 = (TH2F*)nphefile->Get("h_cc_nphe_final_s5");
	norm_nphe_s6 = (TH2F*)nphefile->Get("h_cc_nphe_final_s6");	
//cout << norm_nphe_s1->GetBinContent(int((theta_cc+5.)*199./60. +1.),int((ph_cc+25.)*199./50.)+1.)<< "\n";
 //       cout << " bin content1 = " << norm_nphe_s1->GetBinContent(100,100) << "\n";
	
      
	

      // cout << " bin content2 = " << avrg_nphe_sector1->GetBinContent(100,100) << "\n";

ifstream input("phel_integr_fract_12July18.txt");
if(input.is_open()){
i=0;
    while(!input.eof()){
          string line1,t_str, e_str,r_str,fr_str;
	   Int_t t,e,r;
	   Double_t fr;
           getline(input,line1); //read number
	   if (line1.length() != 0){ 
              t_str= line1.substr(0,line1.find(","));
            t = atof(t_str.c_str());
		   
	    e_str = line1.substr(t_str.length()+1,line1.substr(t_str.length()+1).find(","));
            e = atof(e_str.c_str());
	    	    
	    r_str = line1.substr(t_str.length()+e_str.length()+2, line1.substr(t_str.length()+e_str.length()+2).find(","));
            r = atof(r_str.c_str());
	    
	    fr_str = line1.substr(t_str.length()+e_str.length()+r_str.length()+3);
	    fr = atof(fr_str.c_str());
	    	    	    
	    //cout << t<< "   " << e << "   " << r << "   " << fr <<" \n";
	    fract_integ[t][e][r] = fr;
	    i=i+1;
	    	    };
	    
    };
};

input.close();
//for(k=0; k<3; k++){
//for(i=0; i<6; i++){
//for(j=0; j<18; j++){

//cout << k << "," << i << "," <<j << "," << fract_integ[k][i][j]<< "\n";
//};
//};
//};



  for (m=1; m<=n_files; m++) {

//sozdaem fail s imenem, vzyatim iz masiva strok  
  finp = new TFile(file[m-1].c_str()); 
  
  
  
 cout << "Processing file " << m << "\n"; 
 
 
 //cout << " bin content3 = " << norm_nphe_s1->GetBinContent(100,100) << "\n";
//berem derevo iz faila    
  TTree *t21 = (TTree*)finp->Get("t21");
  
  TBranch *br_indtype = t21->GetBranch("indtype");
    TBranch *br_npart = t21->GetBranch("npart");
    TBranch *br_p_el = t21->GetBranch("P_EL");
    TBranch *br_block = t21->GetBranch("block");
    TBranch *br_deltaQ = t21->GetBranch("deltaQ");
    TBranch *br_LiveTime = t21->GetBranch("LiveTime");
    TBranch *br_n_incl = t21->GetBranch("n_incl");
    TBranch *br_n_elast = t21->GetBranch("n_elast");
    TBranch *br_ph_EL = t21->GetBranch("ph_EL");
    TBranch *br_th_EL = t21->GetBranch("th_EL");
    TBranch *br_W = t21->GetBranch("W");
    TBranch *br_Q2 = t21->GetBranch("Q2");
    TBranch *br_nphe_el = t21->GetBranch("NpheCC_EL");
    TBranch *br_ectot_el = t21->GetBranch("ECtot_EL");
    TBranch *br_ecin_el = t21->GetBranch("ECin_EL");
    TBranch *br_ecout_el = t21->GetBranch("ECout_EL");
    TBranch *br_x_EL = t21->GetBranch("x_EL");
    TBranch *br_y_EL = t21->GetBranch("y_EL");
    TBranch *br_z_EL = t21->GetBranch("z_EL");
    TBranch *br_PdHit_EL = t21->GetBranch("PdHit_EL");
    TBranch *br_sc_x = t21->GetBranch("sc_x");
    TBranch *br_sc_y = t21->GetBranch("sc_y");
    TBranch *br_sc_z = t21->GetBranch("sc_z");
    TBranch *br_pmt_hit = t21->GetBranch("pmt_hit");
    TBranch *br_segment = t21->GetBranch("segment");
    TBranch *br_theta_cc = t21->GetBranch("theta_cc");
    TBranch *br_ph_cc = t21->GetBranch("ph_cc");
    TBranch *br_sector = t21->GetBranch("sector");

 
    
  Bool_t adc_cut_switch,tdc_cut_switch;
  
  Qdiff = 0.;
  Qcurr = 0.;
  Qprev = 0.;
  Qtotal = 0.;
  k = 0;
  block = 0;
  last_k = 0;
  nstart = 0;
  nstop = 0;
  n_incl = 0;
  n_elast = 0;
  

//tsikl po sobitiyam. ih odinakovoe kol-vo v kazdoi peremennoi  
  for (i=0; i<br_sector->GetEntries(); i++) { 
  
  Qprev = Qcurr;


   br_indtype->GetEntry(i);
   br_npart->GetEntry(i);
   br_p_el->GetEntry(i);
   br_block->GetEntry(i);
   br_deltaQ->GetEntry(i);
   br_LiveTime->GetEntry(i);
   br_n_incl->GetEntry(i);
   br_n_elast->GetEntry(i);
   br_ph_EL->GetEntry(i);
   br_th_EL->GetEntry(i);
   br_W->GetEntry(i);
   br_Q2->GetEntry(i);
   br_nphe_el->GetEntry(i);
   br_ectot_el->GetEntry(i);
   br_ecin_el->GetEntry(i);
   br_ecout_el->GetEntry(i);
   br_x_EL->GetEntry(i);
   br_y_EL->GetEntry(i);
   br_z_EL->GetEntry(i);
   br_PdHit_EL->GetEntry(i);
   br_sc_x->GetEntry(i);
   br_sc_y->GetEntry(i);
   br_sc_z->GetEntry(i);
   br_pmt_hit->GetEntry(i);
   br_segment->GetEntry(i);
   br_theta_cc->GetEntry(i);
   br_ph_cc->GetEntry(i);
   br_sector->GetEntry(i);

  

  indtype = br_indtype->GetLeaf("indtype")->GetValue(); 
  npart = br_npart->GetLeaf("npart")->GetValue();
  P_EL = br_p_el->GetLeaf("P_EL")->GetValue();

  th_EL = br_th_EL->GetLeaf("th_EL")->GetValue();
  ph_EL = br_ph_EL->GetLeaf("ph_EL")->GetValue();

  

 
  PdHit_EL = br_PdHit_EL->GetLeaf("PdHit_EL")->GetValue();
  
  z_EL = br_z_EL->GetLeaf("z_EL")->GetValue();
  W = br_W->GetLeaf("W")->GetValue();
  Q2 = br_Q2->GetLeaf("Q2")->GetValue();
  segment = br_segment->GetLeaf("segment")->GetValue();
  pmt_hit = br_pmt_hit->GetLeaf("pmt_hit")->GetValue();

 sector =  int(br_sector->GetLeaf("sector")->GetValue());
nphe = br_nphe_el->GetLeaf("NpheCC_EL")->GetValue();
theta_cc = br_theta_cc->GetLeaf("theta_cc")->GetValue();
ph_cc = br_ph_cc->GetLeaf("ph_cc")->GetValue();  
 
  
  
  
//p_fid_a = 24.*(1-exp(-1.*0.08*(th_P-9.)));
//p_fid_b = -1.*25.*(1-exp(-1.*0.1*(th_P-10.)));
  //pip_fid_a = 24.*(1-exp(-1.*0.08*(th_PIp-9.)));
  // pip_fid_b = -1.*25.*(1-exp(-1.*0.1*(th_PIp-10.))); 
  
 
  if (br_ectot_el->GetLeaf("ECtot_EL")->GetValue() > (br_ecout_el->GetLeaf("ECout_EL")->GetValue()+br_ecin_el->GetLeaf("ECin_EL")->GetValue())) { 
          ECT  = br_ectot_el->GetLeaf("ECtot_EL")->GetValue();  
         } else {
          ECT  = (br_ecout_el->GetLeaf("ECout_EL")->GetValue()+br_ecin_el->GetLeaf("ECin_EL")->GetValue());    
          };
	  
	  //quatity check   
	     
	     block_curr = br_block->GetLeaf("block")->GetValue(); 

    if ((m_old != 0) && (m != m_old))block_total=block_total+block_prev;
    
    m_old=m;


   LiveTime=br_LiveTime->GetLeaf("LiveTime")->GetValue();
   
   inclusive = br_n_incl->GetLeaf("n_incl")->GetValue()/br_deltaQ->GetLeaf("deltaQ")->GetValue();
   elastic =  br_n_elast->GetLeaf("n_elast")->GetValue()/br_deltaQ->GetLeaf("deltaQ")->GetValue(); 

   if (block_curr != block_prev) {

   hist_ltime->Fill(block_total+block_curr,LiveTime);
   
   hist_ltime_1d->Fill(LiveTime);
   hist_n_incl->Fill(block_total+block_curr,inclusive);
hist_n_incl_1d->Fill(inclusive);  
 hist_n_elast->Fill(block_total+block_curr,elastic);
hist_n_elast_1d->Fill(elastic); 

 
//old if ((LiveTime > 0.8) && (LiveTime <0.9) && (inclusive > 195000) &&(inclusive < 210000) && (elastic > 50000) && (elastic < 58000)){

if ((LiveTime > 0.8) && (LiveTime <0.9) && (inclusive > 85000) &&(inclusive < 100000) && (elastic > 24000) && (elastic < 28000)){ 
 Qfull = Qfull + br_deltaQ->GetLeaf("deltaQ")->GetValue();
  };
   
  
   
   block_prev = block_curr;
   };   
	  


	  
//cout<<segment<<"\n";	  

//MOM CORR
/*
P_EL_new = corrfunc.correct_pel_e1_2039_2250_feb09(P_EL,th_EL,ph_EL);
th_EL_new = corrfunc.correct_thel_e1_2039_2250_feb09(P_EL,th_EL,ph_EL);
P_EL_old = P_EL;
P_EL = P_EL_new;
th_EL_old = th_EL;
th_EL = th_EL_new;



W_new = pow(float((E0+m_proton-P_EL)),2);
W_new = W_new -pow(P_EL*sin(th_EL*M_PI/180.)*cos(ph_EL*M_PI/180.),2);
W_new = W_new -pow(P_EL*sin(th_EL*M_PI/180.)*sin(ph_EL*M_PI/180.),2);
W_new = W_new -pow(float(E0 - P_EL*cos(th_EL*M_PI/180.)),2);
W_new = sqrt(W_new);
W = W_new;  

Q2_new = pow(float(E0-P_EL),2);
Q2_new = Q2_new -pow(P_EL*sin(th_EL*M_PI/180.)*cos(ph_EL*M_PI/180.),2);
Q2_new = Q2_new -pow(P_EL*sin(th_EL*M_PI/180.)*sin(ph_EL*M_PI/180.),2);
Q2_new = Q2_new -pow(float(E0 - P_EL*cos(th_EL*M_PI/180.)),2);
Q2 = -Q2_new;

*/   
 
 

//Missing mass pim
/*p_miss_1 = -P_EL*cos(ph_EL*M_PI/180.)*sin(th_EL*M_PI/180.)-P_P*cos(ph_P*M_PI/180.)*sin(th_P*M_PI/180.)-P_PIp*cos(ph_PIp*M_PI/180.)*sin(th_PIp*M_PI/180.);
p_miss_2 = -P_EL*sin(ph_EL*M_PI/180.)*sin(th_EL*M_PI/180.)-P_P*sin(ph_P*M_PI/180.)*sin(th_P*M_PI/180.)-P_PIp*sin(ph_PIp*M_PI/180.)*sin(th_PIp*M_PI/180.);
p_miss_3 = E0-P_EL*cos(th_EL*M_PI/180.)-P_P*cos(th_P*M_PI/180.)-P_PIp*cos(th_PIp*M_PI/180.);
p_miss_4 = E0+m_proton-P_EL-sqrt(m_proton*m_proton+P_P*P_P)-sqrt(m_pip*m_pip+P_PIp*P_PIp);

p_miss_sqr = p_miss_4*p_miss_4-p_miss_3*p_miss_3-p_miss_2*p_miss_2-p_miss_1*p_miss_1;*/

P4_ELP_reg.SetXYZT(P_EL*cos(ph_EL*M_PI/180.)*sin(th_EL*M_PI/180.),P_EL*sin(ph_EL*M_PI/180.)*sin(th_EL*M_PI/180.),P_EL*cos(th_EL*M_PI/180.),P_EL);









///ENERGY LOSS

/*
delta_mom_p = corrfunc.correct_energy_theta_pf(P_P, th_P);

//cout << "theta = " << th_P << " P_P = " << P_P << " delta_p = " << delta_mom_p << "\n";

P4_PP_cor.SetXYZT((delta_mom_p+P_P)*cos(ph_P*M_PI/180.)*sin(th_P*M_PI/180.),(delta_mom_p+P_P)*sin(ph_P*M_PI/180.)*sin(th_P*M_PI/180.),(delta_mom_p+P_P)*cos(th_P*M_PI/180.),sqrt((delta_mom_p+P_P)*(delta_mom_p+P_P)+m_proton*m_proton));

P4_PIm_cor = P4_EL + P4_P - P4_ELP_reg - P4_PP_cor - P4_PIp_reg;
P4_PIp_cor = P4_EL + P4_P - P4_ELP_reg - P4_PP_cor - P4_PIm_reg;
*/






/*
if(P4_PIm_miss[0] == 0.) {
if(P4_PIm_miss[1] > 0.) ph_PIm_miss = 90.;
if(P4_PIm_miss[1] < 0.) ph_PIm_miss = 270.;

};


if ((P4_PIm_miss[1]>0)&&(P4_PIm_miss[0]>0)&&(P4_PIm_miss[0] != 0.)) {
ph_PIm_miss = (180./M_PI)*atan(P4_PIm_miss[1]/P4_PIm_miss[0]);
};


if ((P4_PIm_miss[1]>0)&&(P4_PIm_miss[0]<0)&&(P4_PIm_miss[0] != 0.)) {
ph_PIm_miss = 180. - (180./M_PI)*atan(abs(P4_PIm_miss[1]/P4_PIm_miss[0]));
};

if ((P4_PIm_miss[1]<0)&&(P4_PIm_miss[0]<0)&&(P4_PIm_miss[0] != 0.)) {
ph_PIm_miss = 180. + (180./M_PI)*atan(abs(P4_PIm_miss[1]/P4_PIm_miss[0]));
};

if ((P4_PIm_miss[1]<0)&&(P4_PIm_miss[0]>0)&&(P4_PIm_miss[0] != 0.)) {
ph_PIm_miss = 360. - (180./M_PI)*atan(abs(P4_PIm_miss[1]/P4_PIm_miss[0]));
};*/


bool_el_id_data=false;

bool_el_id_data=particle_ID_data.Electron_cuts_data(); 




if (bool_el_id_data) {

if ((th_EL>=22.)&&(th_EL<=48.)&&(npart<=2)) h_w_inclusive[sector-1][int((th_EL-22)/2.)]->Fill(P_EL/Epeak[int((th_EL-22)/2.)],fract_integ[pmt_hit+1][sector-1][segment]);
if ((W>=0.8)&&(W<=1.)&&(ph_EL>=0)&&(ph_EL<360.)) h_th_el_arr_elast[int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((W>=1.2)&&(W<=1.3)&&(ph_EL>=0)&&(ph_EL<360.)) h_th_el_arr_delta[int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((W>=1.45)&&(W<=1.55)&&(ph_EL>=0)&&(ph_EL<360.)) h_th_el_arr_w15[int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((W>=1.65)&&(W<=1.75)&&(ph_EL>=0)&&(ph_EL<360.)) h_th_el_arr_w17[int((ph_EL)/2.)] -> Fill(th_EL, 1.);

if ((W>=0.8)&&(W<1.9)&&(ph_EL>=0)&&(ph_EL<360.)) h_th_el_arr_incl[int((W-0.8)/0.01)][int((ph_EL)/2.)] -> Fill(th_EL, 1.);



if ((th_EL>=20.)&&(th_EL<50.)&&(ph_EL>=0)&&(ph_EL<360.)) h_w_arr_incl[int(th_EL-20.)][int((ph_EL)/2.)] -> Fill(W, 1.);



};//konets ifa el cutov







    };// konets tsicla po sobitiyam (po i)
  
  
  t21->Delete();

 finp->Close();  
 
     };//konets tsicla po failam (po m)
    
    
 /////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////// 
 
 block_curr = 0;
 block_prev = 0;
 m_old=0;
  
 for (m=1; m<=n_files_empty; m++) {
  
  finp = new TFile(file_empty[m-1].c_str()); 
  
  
  
 cout << "Processing file with empty target " << m << "\n"; 
  
  
  // cout << " bin content3 = " << avrg_nphe_sector1->GetBinContent(100,100) << "\n";
  
  TTree *t21 = (TTree*)finp->Get("t21");
  TBranch *br_indtype = t21->GetBranch("indtype");
    TBranch *br_npart = t21->GetBranch("npart");
    TBranch *br_p_el = t21->GetBranch("P_EL");
    TBranch *br_block = t21->GetBranch("block");
    TBranch *br_deltaQ = t21->GetBranch("deltaQ");
    TBranch *br_LiveTime = t21->GetBranch("LiveTime");
    TBranch *br_n_incl = t21->GetBranch("n_incl");
    TBranch *br_n_elast = t21->GetBranch("n_elast");
    TBranch *br_ph_EL = t21->GetBranch("ph_EL");
    TBranch *br_th_EL = t21->GetBranch("th_EL");
    TBranch *br_W = t21->GetBranch("W");
    TBranch *br_Q2 = t21->GetBranch("Q2");
    TBranch *br_nphe_el = t21->GetBranch("NpheCC_EL");
    TBranch *br_ectot_el = t21->GetBranch("ECtot_EL");
    TBranch *br_ecin_el = t21->GetBranch("ECin_EL");
    TBranch *br_ecout_el = t21->GetBranch("ECout_EL");
    TBranch *br_x_EL = t21->GetBranch("x_EL");
    TBranch *br_y_EL = t21->GetBranch("y_EL");
    TBranch *br_z_EL = t21->GetBranch("z_EL");
    TBranch *br_PdHit_EL = t21->GetBranch("PdHit_EL");
    TBranch *br_sc_x = t21->GetBranch("sc_x");
    TBranch *br_sc_y = t21->GetBranch("sc_y");
    TBranch *br_sc_z = t21->GetBranch("sc_z");
    TBranch *br_pmt_hit = t21->GetBranch("pmt_hit");
    TBranch *br_segment = t21->GetBranch("segment");
    TBranch *br_theta_cc = t21->GetBranch("theta_cc");
    TBranch *br_ph_cc = t21->GetBranch("ph_cc");
    TBranch *br_sector = t21->GetBranch("sector");
     
    
    
   
   

  Bool_t adc_cut_switch,tdc_cut_switch;
  
  Qdiff = 0.;
  Qcurr = 0.;
  Qprev = 0.;
  Qtotal = 0.;
  k = 0;
  block = 0;
  last_k = 0;
  nstart = 0;
  nstop = 0;
  n_incl = 0;
  n_elast = 0;
  
  
  for (i=0; i<br_sector->GetEntries(); i++) { 
  
  Qprev = Qcurr;

br_indtype->GetEntry(i);
   br_npart->GetEntry(i);
   br_p_el->GetEntry(i);
   br_block->GetEntry(i);
   br_deltaQ->GetEntry(i);
   br_LiveTime->GetEntry(i);
   br_n_incl->GetEntry(i);
   br_n_elast->GetEntry(i);
   br_ph_EL->GetEntry(i);
   br_th_EL->GetEntry(i);
   br_W->GetEntry(i);
   br_Q2->GetEntry(i);
   br_nphe_el->GetEntry(i);
   br_ectot_el->GetEntry(i);
   br_ecin_el->GetEntry(i);
   br_ecout_el->GetEntry(i);
   br_x_EL->GetEntry(i);
   br_y_EL->GetEntry(i);
   br_z_EL->GetEntry(i);
   br_PdHit_EL->GetEntry(i);
   br_sc_x->GetEntry(i);
   br_sc_y->GetEntry(i);
   br_sc_z->GetEntry(i);
   br_pmt_hit->GetEntry(i);
   br_segment->GetEntry(i);
   br_theta_cc->GetEntry(i);
   br_ph_cc->GetEntry(i);
   br_sector->GetEntry(i);


  
  
  
  P_EL = br_p_el->GetLeaf("P_EL")->GetValue();
   th_EL = br_th_EL->GetLeaf("th_EL")->GetValue();
  ph_EL = br_ph_EL->GetLeaf("ph_EL")->GetValue();
  
  npart = br_npart->GetLeaf("npart")->GetValue();
 
  PdHit_EL = br_PdHit_EL->GetLeaf("PdHit_EL")->GetValue();
 
  z_EL = br_z_EL->GetLeaf("z_EL")->GetValue();
  W = br_W->GetLeaf("W")->GetValue();
  Q2 = br_Q2->GetLeaf("Q2")->GetValue();
  segment = br_segment->GetLeaf("segment")->GetValue();
  pmt_hit = br_pmt_hit->GetLeaf("pmt_hit")->GetValue();

 
  indtype = br_indtype->GetLeaf("indtype")->GetValue();
  sector =  int(br_sector->GetLeaf("sector")->GetValue());
nphe = br_nphe_el->GetLeaf("NpheCC_EL")->GetValue();
theta_cc = br_theta_cc->GetLeaf("theta_cc")->GetValue();
ph_cc = br_ph_cc->GetLeaf("ph_cc")->GetValue();  
  
  if (br_ectot_el->GetLeaf("ECtot_EL")->GetValue() > (br_ecout_el->GetLeaf("ECout_EL")->GetValue()+br_ecin_el->GetLeaf("ECin_EL")->GetValue())) { 
          ECT  = br_ectot_el->GetLeaf("ECtot_EL")->GetValue();  
         } else {
          ECT  = (br_ecout_el->GetLeaf("ECout_EL")->GetValue()+br_ecin_el->GetLeaf("ECin_EL")->GetValue());    
          };
	  
	  //quatity check   
	     
	     block_curr = br_block->GetLeaf("block")->GetValue(); 

    if ((m_old != 0) && (m != m_old))block_total=block_total+block_prev;
    
    m_old=m;


   LiveTime=br_LiveTime->GetLeaf("LiveTime")->GetValue();
   
   inclusive = br_n_incl->GetLeaf("n_incl")->GetValue()/br_deltaQ->GetLeaf("deltaQ")->GetValue();
   elastic =  br_n_elast->GetLeaf("n_elast")->GetValue()/br_deltaQ->GetLeaf("deltaQ")->GetValue(); 

   if (block_curr != block_prev) {


 
 Qfull_empty = Qfull_empty + br_deltaQ->GetLeaf("deltaQ")->GetValue();
 
   
  
   
   block_prev = block_curr;
   };   
	  
  
 
  


P4_ELP_reg.SetXYZT(P_EL*cos(ph_EL*M_PI/180.)*sin(th_EL*M_PI/180.),P_EL*sin(ph_EL*M_PI/180.)*sin(th_EL*M_PI/180.),P_EL*cos(th_EL*M_PI/180.),P_EL);



//bool_el_id_empt=particle_ID_empty.Electron_cuts_empty(); 


//if (bool_el_id_empt) {



// }; //konec ifa electronnih cutov
    };// konets tsicla po sobitiyam (po i)
  
  
  t21->Delete();

 finp->Close();  
 
     };//konets tsicla po failam (po m)  
  
  
  
  
  
  
//////////////////////////////////////////-sim  
 block_curr = 0;
 block_prev = 0;
 m_old=0;
 
for (m=1; m<=n_files_sim; m++) {
  
  finp = new TFile(file_sim[m-1].c_str()); 
  
  
  
 cout << "Processing file with simulation " << m << "\n"; 
  
  
  // cout << " bin content3 = " << avrg_nphe_sector1->GetBinContent(100,100) << "\n";
    
  TTree *t21 = (TTree*)finp->Get("t21");
 
  TBranch *br_indtype = t21->GetBranch("indtype");
    TBranch *br_npart = t21->GetBranch("npart");
    TBranch *br_p_el = t21->GetBranch("P_EL");
    TBranch *br_block = t21->GetBranch("block");
    TBranch *br_deltaQ = t21->GetBranch("deltaQ");
    TBranch *br_LiveTime = t21->GetBranch("LiveTime");
    TBranch *br_n_incl = t21->GetBranch("n_incl");
    TBranch *br_n_elast = t21->GetBranch("n_elast");
    TBranch *br_ph_EL = t21->GetBranch("ph_EL");
    TBranch *br_th_EL = t21->GetBranch("th_EL");
    TBranch *br_W = t21->GetBranch("W");
    TBranch *br_Q2 = t21->GetBranch("Q2");
    TBranch *br_nphe_el = t21->GetBranch("NpheCC_EL");
    TBranch *br_ectot_el = t21->GetBranch("ECtot_EL");
    TBranch *br_ecin_el = t21->GetBranch("ECin_EL");
    TBranch *br_ecout_el = t21->GetBranch("ECout_EL");
    TBranch *br_x_EL = t21->GetBranch("x_EL");
    TBranch *br_y_EL = t21->GetBranch("y_EL");
    TBranch *br_z_EL = t21->GetBranch("z_EL");
    TBranch *br_PdHit_EL = t21->GetBranch("PdHit_EL");
    TBranch *br_sc_x = t21->GetBranch("sc_x");
    TBranch *br_sc_y = t21->GetBranch("sc_y");
    TBranch *br_sc_z = t21->GetBranch("sc_z");
    TBranch *br_pmt_hit = t21->GetBranch("pmt_hit");
    TBranch *br_segment = t21->GetBranch("segment");
    TBranch *br_theta_cc = t21->GetBranch("theta_cc");
    TBranch *br_ph_cc = t21->GetBranch("ph_cc");
    TBranch *br_sector = t21->GetBranch("sector");
   

  Bool_t adc_cut_switch,tdc_cut_switch;
  
  Qdiff = 0.;
  Qcurr = 0.;
  Qprev = 0.;
  Qtotal = 0.;
  k = 0;
  block = 0;
  last_k = 0;
  nstart = 0;
  nstop = 0;
  n_incl = 0;
  n_elast = 0;
  
  
  for (i=0; i<br_sector->GetEntries(); i++) { 
  
  Qprev = Qcurr;
br_indtype->GetEntry(i);
   br_npart->GetEntry(i);
   br_p_el->GetEntry(i);
   br_block->GetEntry(i);
   br_deltaQ->GetEntry(i);
   br_LiveTime->GetEntry(i);
   br_n_incl->GetEntry(i);
   br_n_elast->GetEntry(i);
   br_ph_EL->GetEntry(i);
   br_th_EL->GetEntry(i);
   br_W->GetEntry(i);
   br_Q2->GetEntry(i);
   br_nphe_el->GetEntry(i);
   br_ectot_el->GetEntry(i);
   br_ecin_el->GetEntry(i);
   br_ecout_el->GetEntry(i);
   br_x_EL->GetEntry(i);
   br_y_EL->GetEntry(i);
   br_z_EL->GetEntry(i);
   br_PdHit_EL->GetEntry(i);
   br_sc_x->GetEntry(i);
   br_sc_y->GetEntry(i);
   br_sc_z->GetEntry(i);
   br_pmt_hit->GetEntry(i);
   br_segment->GetEntry(i);
   br_theta_cc->GetEntry(i);
   br_ph_cc->GetEntry(i);
   br_sector->GetEntry(i);
   

  
  P_EL = br_p_el->GetLeaf("P_EL")->GetValue();
 
  th_EL = br_th_EL->GetLeaf("th_EL")->GetValue();
  ph_EL = br_ph_EL->GetLeaf("ph_EL")->GetValue();
  
  npart = br_npart->GetLeaf("npart")->GetValue();
  
  PdHit_EL = br_PdHit_EL->GetLeaf("PdHit_EL")->GetValue();
  
  z_EL = br_z_EL->GetLeaf("z_EL")->GetValue();
  W = br_W->GetLeaf("W")->GetValue();
  Q2 = br_Q2->GetLeaf("Q2")->GetValue();
  segment = br_segment->GetLeaf("segment")->GetValue();
  pmt_hit = br_pmt_hit->GetLeaf("pmt_hit")->GetValue();
  
 
  
  indtype = br_indtype->GetLeaf("indtype")->GetValue();
  sector =  int(br_sector->GetLeaf("sector")->GetValue());
nphe = br_nphe_el->GetLeaf("NpheCC_EL")->GetValue();
theta_cc = br_theta_cc->GetLeaf("theta_cc")->GetValue();
ph_cc = br_ph_cc->GetLeaf("ph_cc")->GetValue();  
  
//  pf_x = br_pf_x->GetLeaf("pf_x")->GetValue();
 //  pf_y = br_pf_y->GetLeaf("pf_y")->GetValue();
 //  pf_z = br_pf_z->GetLeaf("pf_z")->GetValue();

 //----------ELECTRON MOMENTUM CORRECTION FOR SIM---------- 
  if (indtype==1){
  delta_p_el_sim = corrfunc.corr_el_mom_sim(P_EL, th_EL);
//  P_EL = P_EL + delta_p_el_sim;
  };
  
//-------------------------------------------------------- 
  if (br_ectot_el->GetLeaf("ECtot_EL")->GetValue() > (br_ecout_el->GetLeaf("ECout_EL")->GetValue()+br_ecin_el->GetLeaf("ECin_EL")->GetValue())) { 
          ECT  = br_ectot_el->GetLeaf("ECtot_EL")->GetValue();  
         } else {
          ECT  = (br_ecout_el->GetLeaf("ECout_EL")->GetValue()+br_ecin_el->GetLeaf("ECin_EL")->GetValue());    
          };
	  
	  //quatity check   
	     
	     block_curr = br_block->GetLeaf("block")->GetValue(); 

    if ((m_old != 0) && (m != m_old))block_total=block_total+block_prev;
    
    m_old=m;


   LiveTime=br_LiveTime->GetLeaf("LiveTime")->GetValue();
   
   inclusive = br_n_incl->GetLeaf("n_incl")->GetValue()/br_deltaQ->GetLeaf("deltaQ")->GetValue();
   elastic =  br_n_elast->GetLeaf("n_elast")->GetValue()/br_deltaQ->GetLeaf("deltaQ")->GetValue(); 

   if (block_curr != block_prev) {


 
 Qfull_sim = Qfull_sim + br_deltaQ->GetLeaf("deltaQ")->GetValue();
 
   
  
   
   block_prev = block_curr;
   };   
	  
  
 

  
//fermi_bonn();



P4_ELP_reg.SetXYZT(P_EL*cos(ph_EL*M_PI/180.)*sin(th_EL*M_PI/180.),P_EL*sin(ph_EL*M_PI/180.)*sin(th_EL*M_PI/180.),P_EL*cos(th_EL*M_PI/180.),P_EL);


if(indtype==2){

if ((th_EL>22.)&&(th_EL<48.)) h_w_inclusive_sim_gen[sector-1][int((th_EL-22.)/2.)]->Fill(P_EL/Epeak[int((th_EL-22)/2.)],1.);
if ((W>=0.8)&&(W<=1.)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_elast_sim_gen[int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((W>=1.2)&&(W<=1.3)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_delta_sim_gen[int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((W>=1.45)&&(W<=1.55)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_w15_sim_gen[int((ph_EL)/2.)] -> Fill(th_EL, 1.);

if ((W>=0.8)&&(W<1.9)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_incl_sim_gen[int((W-0.8)/0.01)][int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((th_EL>=20.)&&(th_EL<50.)&&(ph_EL>=0)&&(ph_EL<360.)) h_w_arr_incl_sim_gen[int(th_EL-20.)][int((ph_EL)/2.)] -> Fill(W,1.);


};
bool_el_id_sim=false; 

bool_el_id_sim=particle_ID_sim.Electron_cuts_sim();

if ((indtype==1)&&(bool_el_id_sim)) {

if ((th_EL>22.)&&(th_EL<48.)&&(npart<=2)) h_w_inclusive_sim[sector-1][int((th_EL-22.)/2.)]->Fill(P_EL/Epeak[int((th_EL-22)/2.)],1.);

if ((W>=0.8)&&(W<=1.0)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_elast_sim[int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((W>=1.2)&&(W<=1.3)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_delta_sim[int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((W>=1.45)&&(W<=1.55)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_w15_sim[int((ph_EL)/2.)] -> Fill(th_EL, 1.);
if ((W>=1.65)&&(W<=1.75)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_w17_sim[int((ph_EL)/2.)] -> Fill(th_EL, 1.);

if ((W>=0.8)&&(W<1.9)&&(ph_EL>0)&&(ph_EL<360.)) h_th_el_arr_incl_sim[int((W-0.8)/0.01)][int((ph_EL)/2.)] -> Fill(th_EL, 1.);

if ((th_EL>=20.)&&(th_EL<50.)&&(ph_EL>=0)&&(ph_EL<360.)) h_w_arr_incl_sim[int(th_EL-20.)][int((ph_EL)/2.)] -> Fill(W, 1.);


};//konets ifa electronnix cutov



//if ((indtype==2)&&(th_EL>=20.)&&(th_EL<=50.))    h_w_arr_sim[int(th_EL-20.)]->Fill(W, 1.);


 
    };// konets tsicla po sobitiyam (po i)
  
  
  t21->Delete();

 finp->Close(); 
 
  outFile = new TFile(outfile_inp.c_str(),"recreate");
 
     };//konets tsicla po failam (po m)  
 








 
 
 
 
 
 
 nphefile->Close(); 
  output();
     
 	outFile->Close();

	/*hist_sector1->Delete();
	hist_nphe_sector1->Delete();
	hist_sector2->Delete();
	hist_nphe_sector2->Delete();
	hist_sector3->Delete();
	hist_nphe_sector3->Delete();
	hist_sector4->Delete();
	hist_nphe_sector4->Delete();
	hist_sector5->Delete();
	hist_nphe_sector5->Delete();
	hist_sector6->Delete();
	hist_nphe_sector6->Delete();*/
	
	cout << "Qfull = " << Qfull << "\n";
	cout << "Qfull_empty = " << Qfull_empty << "\n";
	cout << "Qfull_sim = " << Qfull_sim << "\n";
	
    };

    
     

















