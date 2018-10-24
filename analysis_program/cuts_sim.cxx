#include <TMath.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h> 
#include <math.h>
#include "cuts_sim.h"
#include "global.h"
#include <iostream>



using namespace std;




 bool cuts_sim::Electron_cuts_sim(){
   
   
   

   
   bool cuts_sim;
   Float_t th_min,th_max,par1,par2,par3,fid_a,fid_b;
   Short_t i;
  
  
   Float_t ph_el_arr_sim[3][6][18] = {{{1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
                             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
		             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
	                     {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
		             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
			     {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.}},
			     
			     {{1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
                             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
		             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
	                     {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
		             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
			     {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.}},
			     
			     {{1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
                             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
		             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
	                     {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
		             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
			     {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.}}};

	
Float_t th_vs_seg_cc_arr[2][6][18] = {{{0.,13.0577,14.8198,16.9854,18.8497,20.7722, 23.1202, 24.7399, 26.3693, 28.2569, 31.6481, 33.7044, 37.5222, 40.1851, 42.4846, 45.,45.,0.},
                             {0., 12.3663, 14.5647, 16.3118, 18.7031, 20.8298, 22.5443, 24.8247, 26.3913, 28.6392, 31.5305, 33.566, 37.5775, 40.1132, 42.5322, 45., 45., 0.},
                             {0., 12.76, 14.6586, 16.6821, 18.6648, 20.5538, 22.5573, 24.962, 26.4137, 28.3029, 31.6033, 33.7665, 37.4934, 40.0381, 42.3285, 44.8663, 45.,0.},
                             {0., 13.0839, 14.7751, 16.7626, 18.6895, 20.9305, 23.1239, 24.7276, 26.5469, 28.1259, 31.2627, 33.6781, 37.3355, 39.6646, 42.5703, 45., 45., 0.},
                             {0., 12.6631, 16.052, 17.1266, 18.7471, 20.7836, 23.0648, 25.0117, 27.5244, 29.9016, 32.6042, 34.7115, 36.9986, 39.1818, 42.0926, 45., 45., 0.},
                             {0., 12.7948, 14.7214, 16.7988, 18.5596, 20.5496, 22.8541, 24.4748, 26.3951, 28.4766, 31.5388, 33.7486, 37.3584, 40.1278, 42.5831, 45., 45., 0.}},
			     
			     
			    {{0., 11., 11., 11.6061, 13.2822, 15.2113, 16.8047, 19.1317, 21.1941, 22.8422, 23.7821, 26.5811, 27.7998, 31.2606, 34.2189, 36.2558, 39.5832, 0.},
                             {0., 11., 11., 11.6132, 12.6424, 14.3677, 16.8573, 18.49, 20.9482, 22.5705, 23.7656, 26.4239, 27.6032, 30.7262, 33.8834, 36.3639, 38.9472, 0.},
		             {0., 11., 11., 11.643, 13.0375, 14.9574, 16.9836, 18.6356, 21.1218, 22.8459, 23.7062, 26.2906, 27.8548, 31.3241, 34.3427, 36.7193, 39.2374, 0.},
	                     {0., 11., 11., 11.7798, 13.2277, 14.8726, 16.6899, 19.1786, 21.0299, 22.9571, 23.9678, 26.1826, 27.4338, 31.2199, 33.6087, 36.1697, 39.178, 0.},
		             {0., 11., 11., 12.0142, 13.4243, 15.159, 16.8523, 19.0246, 20.7604, 22.5512, 24.7555, 26.934, 29.5094, 30.8662, 35.0397, 36.5057, 39.7693, 0.},
			     {0., 11., 11., 11.628, 13.1929, 15.0126, 16.3127, 19.0631, 20.872, 22.7261, 23.8125, 26.4752, 27.82, 30.8766, 34.2017, 36.4635, 40.1278, 0.}}};
			     
 cuts_sim = false; 

//calorimeter threshold cut + manually remove the first and last cc segments
if ((P_EL > 0.461)&&(segment!=0)&&(segment!=17)) {
     
   th_min= (11.7398+8.21504/(0.433327*P_EL+0.158076));
   par1=0.85+1.1*P_EL;
   par2=-62.8-30.*P_EL; 
   par3 = 0.0047*P_EL + 0.0079;

   fid_a = 41.3*pow((sin((th_EL-th_min)*par3)),(par1+par2/th_EL+1485./th_EL/th_EL))+1.; 
   fid_b = -41.3*pow((sin((th_EL-th_min)*par3)),(par1+par2/th_EL+1485./th_EL/th_EL))-1.; 
     
   th_max = 76.8617 -76.537*P_EL + 77.9387*P_EL*P_EL-28.389*P_EL*P_EL*P_EL;
  
   

	switch (sector) {
case 1 : 
if (indtype ==2) hist_z_el_1_sim_2->Fill(z_EL,1.);
/*if ((ph_EL >= 330) && (ph_EL <= 360)){
if ((P_EL < 1.79999) && (P_EL > 0.4)){
if (indtype==2) ph_vs_th_el_sim[0][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-360,1);
};
};
if ((ph_EL >= 0) && (ph_EL <= 30)) {
if ((P_EL < 1.75999) && (P_EL > 0.4)){
if (indtype==2) ph_vs_th_el_sim[0][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL,1);
};
};*/

// ectot vs p cut
if ((ECT/P_EL > -0.0724295*P_EL*P_EL+0.213588*P_EL-0.0148421) && (ECT/P_EL < 0.0136346*P_EL*P_EL-0.0537425*P_EL+0.360596)){

	if (indtype==1) hist_ectot_sector1_sim->Fill(P_EL,ECT/P_EL,1.); 

 //~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){

//th_cc vs seg cut
if ((theta_cc >th_vs_seg_cc_arr[1][0][segment])&&(theta_cc <th_vs_seg_cc_arr[0][0][segment])){

//	if (indtype==1) th_cc_vs_seg_1_sim->Fill(segment+1,theta_cc,1.);

// geometrical cut on number of photoelectrons
if (norm_nphe_s1->GetBinContent(norm_nphe_s1->GetXaxis()->FindBin(theta_cc),norm_nphe_s1->GetYaxis()->FindBin(ph_cc))>0.7){

//nphe cut that removes the 1 and 18 segments
if (nphe > ph_el_arr_sim[pmt_hit+1][0][segment]){

//vertex cut
if ((z_EL>-2.65) && (z_EL<1.85)){
	
if ((ph_EL >= 330) && (ph_EL <= 360)){

//fiducial cut		
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+360) && (ph_EL < fid_a+360)){

	if ((P_EL < 1.79999) && (P_EL > 0.4)){
	if (indtype==1) ph_vs_th_el_sim[0][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-360,1);
	};

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)&&(indtype==1)) th_vs_p_e_2_sim[0]->Fill(P_EL,th_EL,1.);
//	 hist_z_el_1_sim_1->Fill(z_EL,1.);

   cuts_sim = true;
   
 }; //fiducial
 }; //second part of sector 1
   
if ((ph_EL >= 0) && (ph_EL <= 30)) {

//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b) && (ph_EL < fid_a)){

	if ((P_EL < 1.75999) && (P_EL > 0.4)){
	if (indtype==1) ph_vs_th_el_sim[0][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL,1);
	};

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)&&(indtype==1)) th_vs_p_e_2_sim[0]->Fill(P_EL,th_EL,1.); 
//	if ((indtype==1)) hist_z_el_1_sim_1->Fill(z_EL,1.);
	
   cuts_sim = true; 

 }; //fiducial
 }; //first part of sector 1

 };//vertex cut
   };//nphe cut that removes the 1 and 18 segments
   };//geometrical cut on number of photoelectrons
   };//th_cc vs seg cut   
   };//phi_cc matching
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   
 }; // ectot vs p cut
 
 break;
 
case 2 : 
if (indtype ==2) hist_z_el_2_sim_2->Fill(z_EL,1.); 
//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[1][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-60,1);
//};

// ectot vs p cut
if ((ECT/P_EL > -0.0514781*P_EL*P_EL+0.170698*P_EL+0.00710391) && (ECT/P_EL < 0.012651*P_EL*P_EL-0.0528591*P_EL+0.35928)) {

	if (indtype==1) hist_ectot_sector2_sim->Fill(P_EL,ECT/P_EL,1.);
	  
//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){

//th_cc vs seg cut
if ((theta_cc >th_vs_seg_cc_arr[1][1][segment])&&(theta_cc <th_vs_seg_cc_arr[0][1][segment])){	

//	if (indtype==1) th_cc_vs_seg_2_sim->Fill(segment+1,theta_cc,1.);

// geometrical cut on number of photoelectrons
if (norm_nphe_s2->GetBinContent(norm_nphe_s2->GetXaxis()->FindBin(theta_cc),norm_nphe_s2->GetYaxis()->FindBin(ph_cc))>0.65){

//nphe cut that removes the 1 and 18 segments
if (nphe > ph_el_arr_sim[pmt_hit+1][1][segment]){


//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+60) && (ph_EL < fid_a+60)&&(PdHit_EL!=16)){

	if ((P_EL < 1.75999) && (P_EL > 0.4)){
	if (indtype==1) ph_vs_th_el_sim[1][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-60,1);
	};

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)&&(indtype==1)) th_vs_p_e_2_sim[1]->Fill(P_EL,th_EL,1.);

//th_vs_p
if ((th_EL > (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.158076))+18.3)||(th_EL < (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.158076))+16.)){
//if ((th_EL > (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.125)) +3.05)||(th_EL < (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.14)) +2.3)){

//if (th_EL > (11.7398+8.5/(0.433327*(P_EL+0.1)+0.15)) +3.3){
//if ((th_EL > (11.7398+8.5/(0.433327*(P_EL+0.1)+0.15)) +6.)||(th_EL < (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.14)) +4.7)){


//vertex cut
if ((z_EL>-2.35) && (z_EL<2.15)){

//	if ((indtype==1)) hist_z_el_2_sim_1->Fill(z_EL,1.);

   cuts_sim = true; 
   
   };//vertex cut
   };//th_vs_p
 //  };//th_vs_p   
 //  };//th_vs_p   
   };//fiducial 
   };//nphe cut that removes the 1 and 18 segments
   };//geometrical cut on number of photoelectrons
   };//th_cc vs seg cut   
   };//phi_cc matching
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane

 }; // ectot vs p cut

 break; 
 
case 3 : 
  
if (indtype ==2) hist_z_el_3_sim_2->Fill(z_EL,1.); 
//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[2][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-120,1);
//};

// ectot vs p cut
if ((ECT/P_EL > -0.0659335*P_EL*P_EL+0.199308*P_EL-0.00592097) && (ECT/P_EL < 0.0415148*P_EL*P_EL-0.111881*P_EL+0.387163)) { 

	if (indtype==1) hist_ectot_sector3_sim->Fill(P_EL,ECT/P_EL,1.);
	
//~fid cuts in Cherenkov plane 
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {  

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){

//th_cc vs seg cut
if ((theta_cc >th_vs_seg_cc_arr[1][2][segment])&&(theta_cc <th_vs_seg_cc_arr[0][2][segment])){	

//	if (indtype==1) th_cc_vs_seg_3_sim->Fill(segment+1,theta_cc,1.);

// geometrical cut on number of photoelectrons
if (norm_nphe_s3->GetBinContent(norm_nphe_s3->GetXaxis()->FindBin(theta_cc),norm_nphe_s3->GetYaxis()->FindBin(ph_cc))>0.7){

//nphe cut that removes the 1 and 18 segments
if (nphe > ph_el_arr_sim[pmt_hit+1][2][segment]){

//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+120) && (ph_EL < fid_a+120)&&(PdHit_EL!=44)){

	if ((P_EL < 1.75999) && (P_EL > 0.4)){
	if (indtype==1) ph_vs_th_el_sim[2][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-120,1);
	};

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)&&(indtype==1)) th_vs_p_e_2_sim[2]->Fill(P_EL,th_EL,1.);
 
 
//vertex cut
if ((z_EL>-2.25) && (z_EL< 2.25)){ 

//	if ((indtype==1)) hist_z_el_3_sim_1->Fill(z_EL,1.); 
 
   cuts_sim = true; 

   };//vertex cut
   };//fiducial 
   };//nphe cut that removes the 1 and 18 segments
   };//geometrical cut on number of photoelectrons
   };//th_cc vs seg cut   
   };//phi_cc matching
   };//~fid cuts in Cherenkov plane 
   };//~fid cuts in Cherenkov plane 
   };//~fid cuts in Cherenkov plane 
   };//~fid cuts in Cherenkov plane 
   
 }; // ectot vs p cut

 break;  
 
case 4 : 

//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[3][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-180,1);
//};
if (indtype ==2) hist_z_el_4_sim_2->Fill(z_EL,1.); 

// ectot vs p cut  
if ((ECT/P_EL > -0.00634486*P_EL*P_EL+0.0672081*P_EL+0.061873) && (ECT/P_EL < -0.0504573*P_EL*P_EL+0.0867658*P_EL+0.287867)) {

	if (indtype==1) hist_ectot_sector4_sim->Fill(P_EL,ECT/P_EL,1.); 

//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){

//th_cc vs seg cut
if ((theta_cc >th_vs_seg_cc_arr[1][3][segment])&&(theta_cc <th_vs_seg_cc_arr[0][3][segment])){

//	if (indtype==1) th_cc_vs_seg_4_sim->Fill(segment+1,theta_cc,1.);

// geometrical cut on number of photoelectrons
if (norm_nphe_s4->GetBinContent(norm_nphe_s4->GetXaxis()->FindBin(theta_cc),norm_nphe_s4->GetYaxis()->FindBin(ph_cc))>0.65){

//nphe cut that removes the 1 and 18 segments
if (nphe > ph_el_arr_sim[pmt_hit+1][3][segment]){

//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+180) && (ph_EL < fid_a+180)){


	if ((P_EL < 1.75999) && (P_EL > 0.4)){
	if (indtype==1) ph_vs_th_el_sim[3][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-180,1);
	};  

//th_vs_p 
//if ((th_EL > (11.7398+5./(0.433327*(P_EL+0.1)+0.015)) +8.)||(th_EL < (11.7398+12./(0.433327*(P_EL+0.1)+0.24)) -0.4)){   	
//if ((th_EL > (11.7398+5./(0.433327*(P_EL+0.1)+0.04)) +15.6)||(th_EL < (11.7398+5./(0.433327*(P_EL+0.1)+0.04)) +14.1)){	 


	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)&&(indtype==1)) th_vs_p_e_2_sim[3]->Fill(P_EL,th_EL,1.);

//vertex cut
if ((z_EL>-2.45) && (z_EL< 2.05)){
	
//	if ((indtype==1)) hist_z_el_4_sim_1->Fill(z_EL,1.);	
	
cuts_sim = true; 

   };//vertex cut
//   };//th_vs_p
//   };//th_vs_p
   }; //fiducial 
   };//nphe cut that removes the 1 and 18 segments
   };//geometrical cut on number of photoelectrons
   };//th_cc vs seg cut   
   };//phi_cc matching
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
      
     
 }; // ectot vs p cut

 break;  
 
case 5 : 
if (indtype ==2)  hist_z_el_5_sim_2->Fill(z_EL,1.); 
//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[4][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-240,1);
//}; 

// ectot vs p cut
if ((ECT/P_EL > -0.0578053*P_EL*P_EL+0.182369*P_EL+0.00157396) && (ECT/P_EL < -0.000865715*P_EL*P_EL-0.0193174*P_EL+0.340688)){

	if (indtype==1) hist_ectot_sector5_sim->Fill(P_EL,ECT/P_EL,1.);  
   
//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){

//th_cc vs seg cut
if ((theta_cc >th_vs_seg_cc_arr[1][4][segment])&&(theta_cc <th_vs_seg_cc_arr[0][4][segment])){	

//	if (indtype==1) th_cc_vs_seg_5_sim->Fill(segment+1,theta_cc,1.);
	
 // geometrical cut on number of photoelectrons
if (norm_nphe_s5->GetBinContent(norm_nphe_s5->GetXaxis()->FindBin(theta_cc),norm_nphe_s5->GetYaxis()->FindBin(ph_cc))>0.8){ 

//nphe cut that removes the 1 and 18 segments
if (nphe > ph_el_arr_sim[pmt_hit+1][4][segment]){ 

//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+240) && (ph_EL < fid_a+240)&&(PdHit_EL!=17)){

	if ((P_EL < 1.75999) && (P_EL > 0.4)){
	if (indtype==1) ph_vs_th_el_sim[4][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-240,1);
	};

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)&&(indtype==1)) th_vs_p_e_2_sim[4]->Fill(P_EL,th_EL,1.);
	
//th_vs_p
if ((th_EL > (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.158076))+19.9)||(th_EL < (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.158076))+17.6)){
if ((th_EL > (11.7398+4.3/(0.433327*(P_EL+0.1)+0.158076))+15.8)||(th_EL < (11.7398+4.5/(0.433327*(P_EL+0.1)+0.158076))+13.5)){





//vertex cut
if ((z_EL>-2.9) && (z_EL< 1.6)){

//	if ((indtype==1)) hist_z_el_5_sim_1->Fill(z_EL,1.);

   cuts_sim = true; 
  
}; //vertex cut  
};//th_vs_p
};//th_vs_p
}; //fiducial     
 


   };//nphe cut that removes the 1 and 18 segments
   };//geometrical cut on number of photoelectrons
   };//th_cc vs seg cut   
   };//phi_cc matching
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane

 }; // ectot vs p cut

 break;   
 
case 6 : 
if (indtype ==2) hist_z_el_6_sim_2->Fill(z_EL,1.);
//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[5][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-300,1);
//}; 
 
// ectot vs p cut
 if ((ECT/P_EL > -0.0514107*P_EL*P_EL+0.17164*P_EL+0.00253672) && (ECT/P_EL < 0.0123293*P_EL*P_EL-0.053898*P_EL+0.361742)) {
 
	if (indtype==1) hist_ectot_sector6_sim->Fill(P_EL,ECT/P_EL,1.);  

//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){

//th_cc vs seg cut 
if ((theta_cc >th_vs_seg_cc_arr[1][5][segment])&&(theta_cc <th_vs_seg_cc_arr[0][5][segment])){ 	

 //	if (indtype==1) th_cc_vs_seg_6_sim->Fill(segment+1,theta_cc,1.);

 // geometrical cut on number of photoelectrons
if (norm_nphe_s6->GetBinContent(norm_nphe_s6->GetXaxis()->FindBin(theta_cc),norm_nphe_s6->GetYaxis()->FindBin(ph_cc))>0.8){ 

//nphe cut that removes the 1 and 18 segments
if (nphe > ph_el_arr_sim[pmt_hit+1][5][segment]){

//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+300) && (ph_EL < fid_a+300)){

	if ((P_EL < 1.75999) && (P_EL > 0.4)){
	if (indtype==1) ph_vs_th_el_sim[5][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-300,1);
	};


//th_vs_p 
//if ((th_EL > (11.7398+5./(0.433327*(P_EL+0.1)+0.015)) +8.3)||(th_EL < (11.7398+12./(0.433327*(P_EL+0.1)+0.27)) +0.3)){


	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)&&(indtype==1)) th_vs_p_e_2_sim[5]->Fill(P_EL,th_EL,1.);


//vertex cut
if ((z_EL>-3.) && (z_EL<1.5)){

//	if ((indtype==1)) hist_z_el_6_sim_1->Fill(z_EL,1.);

   cuts_sim = true; 

   }; //vertex cut
//   };//th_vs_p   
   }; //fiducial 
   };//nphe cut that removes the 1 and 18 segments
   };//geometrical cut on number of photoelectrons  
   };//th_cc vs seg cut   
   };//phi_cc matching
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane

 }; // ectot vs p cut
 break;      
 
   
   }; // end of switch
   };  // end of calorimeter threshold cut
  
   
   return cuts_sim;
   
   };
   
   
  
