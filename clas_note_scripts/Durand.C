#include <TLorentzVector.h>

void Durand(){
//L. Durand,  Phys. Rev., vol. 123, pp. 1393-1422, 1961

gStyle->SetOptStat(0);
gStyle->SetTitleY(0.975);
gStyle->SetTitleSize(0.08);
//my
//Float_t Epeak_arr[13] = {1.739, 1.694, 1.649, 1.602, 1.556, 1.51, 1.464, 1.418, 1.374, 1.33, 1.287, 1.246, 1.206};

Float_t Ebeam_arr[21] = {0.449, 0.557, 0.718, 0.865, 1.104, 1.598, 9.761, 12.589,2.039,2.039,2.039,2.039,2.039,2.039,2.039,2.039,2.039,2.039,2.039,2.039,2.039};
Float_t Epeak_arr[21] = {0.304,0.350, 0.407,0.450,0.507,0.664,8.432,10.465,1.739, 1.694, 1.649, 1.602, 1.556, 1.51, 1.464, 1.418, 1.374, 1.33, 1.287, 1.246, 1.206}; 
Float_t Theta_arr[21] = {90.,90.,90.,90.,90.,80.,0.,0.,23.,25.,27.,29.,31.,33.,35.,37.,39.,41.,43.,45.,47.}; 
Float_t Q2_arr[21];

Short_t i;



for (i=0;i<21;i++){
Theta_arr[i] = Theta_arr[i]*3.14159/180.;
Q2_arr[i] = 4.*Ebeam_arr[i]*Epeak_arr[i]*sin(Theta_arr[i]/2.)*sin(Theta_arr[i]/2.);
}
Q2_arr[6] = 2.495;
Q2_arr[7] = 3.989;

Theta_arr[6] = acos(1. - Q2_arr[6]/2./Ebeam_arr[6]/Epeak_arr[6]);
Theta_arr[7] = acos(1. - Q2_arr[7]/2./Ebeam_arr[7]/Epeak_arr[7]);


Double_t Mp, Mn, eps,tau;
Double_t Mott, Xsec, Xsec2, Xsec_p, Xsec_n,E;
Double_t Ge_p,  Ge_n, Gm_p, Gm_n, Gd,M;
Double_t mu_n, mu_p,nu,q,p;


mu_p = 2.793;
mu_n = -1.913;
Mp = 0.938272;
Mn = 0.939565;
M = 0.5*(Mp+Mn);

//theta = 47;

//Eo = 2.039;
//Epeak = Epeak_arr[12];
//Ef =Epeak_arr[12];

//theta = theta*3.14159/180;
//pi = 3.14159;

//Q2 = 4.*Eo*Epeak*sin(theta/2)*sin(theta/2);
 
TLorentzVector P4_Eini, P4_Efin, P4_gamma;

for (i=0;i<21;i++){

P4_Eini.SetXYZT(0.,0.,Ebeam_arr[i],Ebeam_arr[i]);

P4_Efin.SetXYZT(Epeak_arr[i]*sin(Theta_arr[i])*cos(50.*3.1415/180),Epeak_arr[i]*sin(Theta_arr[i])*sin(50.*3.1415/180),Epeak_arr[i]*cos(Theta_arr[i]),Epeak_arr[i]);

P4_gamma = P4_Eini - P4_Efin;
p = P4_gamma.Vect().Mag()/2.;
E = sqrt(M*M+p*p);
tau = Q2_arr[i]/4./M/M;
eps = 1./(1. + 2.*(1.+tau)*tan(Theta_arr[i]/2.)*tan(Theta_arr[i]/2.));

// mott
Mott = 389.379*(2./137.*Epeak_arr[i]/Q2_arr[i]*cos(Theta_arr[i]/2.))*(2./137.*Epeak_arr[i]/Q2_arr[i]*cos(Theta_arr[i]/2.)); 

Gd = 1./(1. + Q2_arr[i]/0.71)/(1. + Q2_arr[i]/0.71);

q = sqrt(Q2_arr[i]);

//Form-factors from P. E. Bosted,Phys.Rev., vol. C51, pp. 409-411, 1995.

 Ge_p = 1/(1.0 + 0.62*q + 0.68*q*q + 2.80*q*q*q + 0.83*q*q*q*q);
 Ge_n= (1.25*mu_n*tau)/(1+18.3*tau)*Gd; 

 Gm_p = mu_p/(1.0 + 0.35*q + 2.44*q*q + 0.50*q*q*q + 1.04*q*q*q*q + 0.34*q*q*q*q*q);
 Gm_n= mu_n/( 1.0 - 1.74*q + 9.29*q*q - 7.63*q*q*q + 4.63*q*q*q*q);   
 

Xsec =  Mott*((Ge_p*Ge_p + Ge_n*Ge_n +tau*(Gm_p*Gm_p + Gm_n*Gm_n))/(1+tau) +2*tan(Theta_arr[i]/2.)*tan(Theta_arr[i]/2.)*tau*(Gm_p*Gm_p + Gm_n*Gm_n));

//Xsec2 =  Mott*(Ge_p*Ge_p + Ge_n*Ge_n +tau/eps*(Gm_p*Gm_p + Gm_n*Gm_n))/(1+tau);
//cout << Xsec << " "<< Xsec2<<" bb\n";

Xsec = Xsec*(Mn*Mp/E/p);
Xsec = Xsec*(4.57e-3);//mub/sr/MeV

//see Eq.(84) L. Durand,  Phys. Rev., vol. 123, pp. 1393-1422, 1961

cout << Xsec*1000. <<endl;//mub/sr/GeV

//<<" "<<Xsec2*1000.*(Mn*Mp/E/p)*(4.57e-3)
};


};
