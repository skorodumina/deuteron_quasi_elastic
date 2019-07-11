#include <TLorentzVector.h>
void Kocevar(){

//P. Kocevar, Zeitschrift fur Physik, vol. 209, pp. 457-469, 1968.

gStyle->SetOptStat(0);
gStyle->SetTitleY(0.975);
gStyle->SetTitleSize(0.08);

//my
//Float_t Epeak_arr[13] = {1.739, 1.694, 1.649, 1.602, 1.556, 1.51, 1.464, 1.418, 1.374, 1.33, 1.287, 1.246, 1.206};

Float_t Ebeam_arr[8] = {0.449, 0.557, 0.718, 0.865, 1.104, 1.598, 9.761, 12.589};
Float_t Epeak_arr[8] = {0.304,0.350, 0.407,0.450,0.507,0.664,8.432,10.465}; 
Float_t Theta_arr[8] = {90.,90.,90.,90.,90.,80.,10.,10.}; 
Float_t Q2_arr[8];

Short_t i;


for (i=0;i<8;i++){
Theta_arr[i] = Theta_arr[i]*3.14159/180.;
Q2_arr[i] = 4.*Ebeam_arr[i]*Epeak_arr[i]*sin(Theta_arr[i]/2.)*sin(Theta_arr[i]/2.);
}
Q2_arr[6] = 2.495;
Q2_arr[7] = 3.989;

//Theta_arr[6] = acos(1. - Q2_arr[6]/2./Ebeam_arr[6]/Epeak_arr[6]);
//Theta_arr[7] = acos(1. - Q2_arr[7]/2./Ebeam_arr[7]/Epeak_arr[7]);

Double_t Ef, Q2, theta, Eo;
Double_t Mp, Mn, tau_n, tau_p, eps_n, eps_p, eps, eps_tmp;
Double_t Mott, Xsec, Xsec_p, Xsec_n;
Double_t Ge_p,  Ge_n, Gm_p, Gm_n, Gd,M;
Double_t mu_n, mu_p,nu,q;
Float_t q_star, p_star, w_star;
Float_t pi, Epeak;
Float_t p, pc, Ec,tau;

Float_t I,C1,C2;
Float_t a11,a12,a13,a14;
Float_t a21,a22,a23,a24;

mu_p = 2.793;
mu_n = -1.913;
Mp = 0.938272;
Mn = 0.939565;
M = 0.5*(Mp+Mn);

for (i=0;i<8;i++){ 
//cout << Q2_arr[i]<<" q2\n";
pc = sqrt(Q2_arr[i])/2.;
Ec = sqrt(M*M+pc*pc);

tau = Q2_arr[i]/4./M/M;

Mott = 389.379*(2./137.*Epeak_arr[i]/Q2_arr[i]*cos(Theta_arr[i]/2.))*(2./137.*Epeak_arr[i]/Q2_arr[i]*cos(Theta_arr[i]/2.)); // mott

Gd = 1./(1. + Q2_arr[i]/0.71)/(1. + Q2_arr[i]/0.71);

q = sqrt(Q2_arr[i]);

//Form-factors from P.E.Bosted, Phys.Rev., vol. C51, pp. 409-411, 1995.
 Ge_p = 1/(1.0 + 0.62*q + 0.68*q*q + 2.80*q*q*q + 0.83*q*q*q*q);
 Ge_n= (1.25*-1.913*tau)/(1+18.3*tau)*Gd; 

 Gm_p = mu_p/(1.0 + 0.35*q + 2.44*q*q + 0.50*q*q*q + 1.04*q*q*q*q + 0.34*q*q*q*q*q);
 Gm_n= mu_n/( 1.0 - 1.74*q + 9.29*q*q - 7.63*q*q*q + 4.63*q*q*q*q);   

a11 = 10.71;
a12 = -0.22;
a13 = 1.14;
a14 = 0.15;

C1 = 1.-0.01*(a11/Q2_arr[i] + a12 +a13*Q2_arr[i]*exp(-a14*Q2_arr[i]));

a21 = -7.73;
a22 = 1.64;
a23 = 0.9;
a24 = 0.15;

C2 = 1.-0.01*(a21/Q2_arr[i] + a22 +a23*Q2_arr[i]*exp(-a24*Q2_arr[i]));

I = C1*(Ge_p*Ge_p + Ge_n*Ge_n +tau*(Gm_p*Gm_p + Gm_n*Gm_n))/(1.+tau) + C2*2.*tan(Theta_arr[i]/2.)*tan(Theta_arr[i]/2.)*tau*(Gm_p*Gm_p + Gm_n*Gm_n);

Xsec =  Mott*I;
Xsec =  Xsec*M*M/3.14159;
Xsec =  Xsec*2.963/0.1973269788/Ec/pc;

//See Eq.(50) from P. Kocevar, Zeitschrift fur Physik, vol. 209, pp. 457-469, 1968.
//the numerical coefficient 2.963 is in fm// I assume that there is a typo in Kocevar and 2.963 should be instead of 2,963.

cout <<Xsec<<endl;//mub/GeV/sr

};
//*389.379*1000.
};
