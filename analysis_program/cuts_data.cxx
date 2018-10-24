#include <TMath.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h> 
#include <math.h>
#include "cuts_data.h"
#include "global.h"
#include <iostream>



using namespace std;

ostringstream qqq1;

   bool cuts_data::Electron_cuts_data(){
   


   
   bool cuts_data;
   Float_t th_min,th_max,par1,par2,par3,fid_a,fid_b;
   Short_t i;
  


 
   Float_t ph_el_arr[3][6][18] = {{{1000.,22.,20.,20.,25.,23.,26.,22.,25.,27.,27.,29.,29.,29.,32.,30.,29.,1000.},
                             {1000.,27.,20.,19.,22.,20.,23.,21.,23.,23.,25.,24.,26.,31.,30.,27.,25.,1000.},
                             {1000.,25.,23.,23.,25.,25.,22.,24.,31.,28.,27.,31.,35.,36.,49.,43.,41.,1000.},
                             {1000.,18.,23.,20.,20.,21.,25.,27.,24.,24.,27.,29.,22.,26.,43.,45.,30.,1000.},
                             {1000.,25.,25.,28.,26.,25.,26.,22.,24.,27.,30.,30.,45.,31.,35.,45.,35.,1000.},
                             {1000.,26.,22.,25.,25.,30.,27.,27.,25.,35.,29.,37.,30.,30.,40.,43.,40.,1000.}},
			     
			     {{1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
                             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
		             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
	                     {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
		             {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.},
			     {1000.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1000.}},
			     
			     {{1000.,22.,21.,18.,21.,20.,20.,22.,25.,25.,29.,25.,25.,30.,30.,30.,25.,1000.},
                             {1000.,25.,24.,18.,19.,23.,24.,25.,29.,28.,26.,23.,26.,44.,39.,38.,35.,1000.},
			     {1000.,24.,22.,25.,28.,23.,23.,25.,24.,30.,30.,28.,28.,35.,36.,37.,35.,1000.},
			     {1000.,25.,23.,23.,23.,20.,26.,31.,24.,27.,28.,28.,23.,25.,32.,24.,28.,1000.},
			     {1000.,23.,21.,21.,23.,45.,45.,30.,25.,31.,30.,35.,47.,30.,45.,55.,40.,1000.},
			     {1000.,25.,22.,22.,25.,35.,33.,23.,26.,30.,40.,35.,27.,40.,75.,40.,40.,1000.}}};
			     
			     
     

Float_t th_vs_seg_cc_arr[2][6][18] = {{{0., 13.0577, 14.8198, 16.9854, 18.8497, 20.7722, 23.1202, 24.7399, 26.3693, 28.2569, 31.6481, 33.7044, 37.5222, 40.1851, 42.4846, 45., 45., 0.},
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
//for (i=0;i<18;i++){
//cout << ph_el[0][5][i] << "\n";
//};

 cuts_data = false; 
   
if ((LiveTime > 0.8) && (LiveTime <0.9) && (inclusive > 85000) &&(inclusive < 100000) && (elastic > 24000) && (elastic < 28000)){

//old if ((LiveTime > 0.8) && (LiveTime <0.9) && (inclusive > 195000) &&(inclusive < 210000) && (elastic > 50000) && (elastic < 58000)){
 
//calorimeter threshold cut + manually remove the first and last cc segments
if ((P_EL > 0.461)&&(segment!=0)&&(segment!=17)) {

 //  th_min=(9.5+17./(P_EL+0.2));
   
   
 
  
   th_min= (11.7398+8.21504/(0.433327*P_EL+0.158076));
   par1=0.85+1.1*P_EL;
   par2=-62.8-30.*P_EL; 
   par3 = 0.0047*P_EL + 0.0079;

   fid_a = 41.3*pow((sin((th_EL-th_min)*par3)),(par1+par2/th_EL+1485./th_EL/th_EL))+1.; 
   fid_b = -41.3*pow((sin((th_EL-th_min)*par3)),(par1+par2/th_EL+1485./th_EL/th_EL))-1.; 
     
   th_max = 76.8617 -76.537*P_EL + 77.9387*P_EL*P_EL-28.389*P_EL*P_EL*P_EL;
  

	switch (sector) {
	
case 1 : 
 
// ectot vs p cut
if ((ECT/P_EL > -0.0557144*P_EL*P_EL+0.180989*P_EL+0.0630868) && (ECT/P_EL < 0.0218734*P_EL*P_EL-0.0607997*P_EL+0.395324)) {
 
	hist_ectot_sector1->Fill(P_EL,ECT/P_EL,1.); 
 
//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

	nphe_sector1->Fill(nphe,1.);
//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){



//th_cc vs seg cut	
if ((theta_cc > th_vs_seg_cc_arr[1][0][segment])&&(theta_cc <th_vs_seg_cc_arr[0][0][segment])){

//	th_cc_vs_seg_1->Fill(segment+1,theta_cc,1.);	
		
	h_cc_nphe_total_s1->Fill(theta_cc, ph_cc,1.);
	if (nphe > 50) h_cc_nphe_final_s1->Fill(theta_cc, ph_cc,1.);


// geometrical cut on number of photoelectrons
if (norm_nphe_s1->GetBinContent(norm_nphe_s1->GetXaxis()->FindBin(theta_cc),norm_nphe_s1->GetYaxis()->FindBin(ph_cc))>0.7){
//if (norm_nphe_s1->GetBinContent(int((theta_cc+5.)*200./60.)+1,int((ph_cc+25.)*200./50.)+1) > 0.8) {

	nphe_sector1_after->Fill(nphe,1.);
	

//nphe cut after poisson fit
if (nphe > ph_el_arr[pmt_hit+1][0][segment]){

	if (pmt_hit == -1) ph_el_left[0][segment]->Fill(nphe,1.);
	if (pmt_hit == 0) ph_el_both[0][segment]->Fill(nphe,1.);
	if (pmt_hit == 1) ph_el_right[0][segment]->Fill(nphe,1.);


//vertex cut
if ((z_EL>-2.65) && (z_EL<1.85)){

if ((ph_EL >= 330) && (ph_EL <= 360)){

	ph_vs_th_1 -> Fill(th_EL,ph_EL-360,1.);

	if ((P_EL < 1.75999) && (P_EL > 0.4)){
	ph_vs_th_1pe[int((P_EL*100-40)/8)]->Fill(th_EL,ph_EL-360,1);
	};

//fiducial cut 
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+360) && (ph_EL < fid_a+360)){
	
	if ((P_EL < 1.75999) && (P_EL > 0.4)){
	ph_vs_th_1pe_fid[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-360,1.);
	};

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)) th_vs_p_e_2[0]->Fill(P_EL,th_EL,1.);

//	hist_z_el_1->Fill(z_EL,1.);

   cuts_data = true;
      
   }; //fiducial
   }; //second part of sector 1
   
if ((ph_EL >= 0) && (ph_EL <= 30)) {
  
	ph_vs_th_1 -> Fill(th_EL,ph_EL,1.); 
	if ((P_EL < 1.75999) &&(P_EL > 0.4)){
	ph_vs_th_1pe[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL,1.);
	};

//fiducial cut 	
if ((th_EL > th_min) && (th_EL < th_max) && (ph_EL > fid_b) && (ph_EL < fid_a)){

	if ((P_EL < 1.75999) &&(P_EL > 0.4)){
	ph_vs_th_1pe_fid[int((P_EL*100-40)/8)] -> Fill(th_EL,ph_EL,1.);
	};
 
	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)) th_vs_p_e_2[0]->Fill(P_EL,th_EL,1.); 

//	hist_z_el_1->Fill(z_EL,1.);

   cuts_data = true; 
   	
   }; //fiducial
   }; //first part of sector 1
 };//vertex cut
 };//nphe cut after poisson fit
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

 
// ectot vs p cut
if ((ECT/P_EL > -0.0637287*P_EL*P_EL+0.199291*P_EL+0.0617286) && (ECT/P_EL < 0.0130875*P_EL*P_EL-0.0380366*P_EL+0.436297)) {

	hist_ectot_sector2->Fill(P_EL,ECT/P_EL,1.); 
  
//~fid cuts in Cherenkov plane
 if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

	nphe_sector2->Fill(nphe,1.);

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){



//th_cc vs seg cut
if ((theta_cc >th_vs_seg_cc_arr[1][1][segment])&&(theta_cc <th_vs_seg_cc_arr[0][1][segment])){
	
//	th_cc_vs_seg_2->Fill(segment+1,theta_cc,1.);
		
	h_cc_nphe_total_s2->Fill(theta_cc, ph_cc,1.);
	if (nphe > 50) h_cc_nphe_final_s2->Fill(theta_cc, ph_cc,1.);


// geometrical cut on number of photoelectrons
if (norm_nphe_s2->GetBinContent(norm_nphe_s2->GetXaxis()->FindBin(theta_cc),norm_nphe_s2->GetYaxis()->FindBin(ph_cc))>0.65){

	nphe_sector2_after->Fill(nphe,1.);
	
//nphe cut after poisson fit	
if (nphe > ph_el_arr[pmt_hit+1][1][segment]){

	if (pmt_hit == -1) ph_el_left[1][segment]->Fill(nphe,1.);
	if (pmt_hit == 0) ph_el_both[1][segment]->Fill(nphe,1.);
	if (pmt_hit == 1) ph_el_right[1][segment]->Fill(nphe,1.);


	
	ph_vs_th_2 -> Fill(th_EL,ph_EL-60,1.);

	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_2pe[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-60,1.);
	}; 

//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+60) && (ph_EL < fid_a+60)&&(PdHit_EL!=16)){
	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_2pe_fid[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-60,1.);
	};


	
//th_vs_p    	
if ((th_EL > (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.158076))+18.3)||(th_EL < (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.158076))+16.)){
//if ((th_EL > (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.125)) +3.05)||(th_EL < (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.14)) +2.3)){
//if (th_EL > (11.7398+8.5/(0.433327*(P_EL+0.1)+0.15)) +3.3){
//if ((th_EL > (11.7398+8.5/(0.433327*(P_EL+0.1)+0.15)) +6.)||(th_EL < (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.14)) +4.7)){


	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)) th_vs_p_e_2[1]->Fill(P_EL,th_EL,1.);
	
//vertex cut
if ((z_EL>-2.35) && (z_EL<2.15)){

//	hist_z_el_2->Fill(z_EL,1.);

   cuts_data = true; 
    
    };//vertex cut
    };//th_vs_p      
//    };//th_vs_p  
  //  };//th_vs_p         
   };//fiducial 
   };//nphe cut after poisson fit
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


 // ectot vs p cut 
if ((ECT/P_EL > -0.0450008*P_EL*P_EL+0.146354*P_EL+0.0768507) && (ECT/P_EL < 0.020841*P_EL*P_EL-0.0494426*P_EL+0.377883)){ 
	hist_ectot_sector3->Fill(P_EL,ECT/P_EL,1.);  
  
//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

	nphe_sector3->Fill(nphe,1.); 

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){


	
//th_cc vs seg cut
if ((theta_cc > th_vs_seg_cc_arr[1][2][segment])&&(theta_cc < th_vs_seg_cc_arr[0][2][segment])){	
	
//	th_cc_vs_seg_3->Fill(segment+1,theta_cc,1.);
		
	h_cc_nphe_total_s3->Fill(theta_cc, ph_cc,1.);
	if (nphe > 50) h_cc_nphe_final_s3->Fill(theta_cc, ph_cc,1.);


// geometrical cut on number of photoelectrons
if (norm_nphe_s3->GetBinContent(norm_nphe_s3->GetXaxis()->FindBin(theta_cc),norm_nphe_s3->GetYaxis()->FindBin(ph_cc))>0.7){

	nphe_sector3_after->Fill(nphe,1.);
	

//nphe cut after poisson fit	
if (nphe > ph_el_arr[pmt_hit+1][2][segment]){

	if (pmt_hit == -1) ph_el_left[2][segment]->Fill(nphe,1.);
	if (pmt_hit == 0) ph_el_both[2][segment]->Fill(nphe,1.);
	if (pmt_hit == 1) ph_el_right[2][segment]->Fill(nphe,1.);

	
	ph_vs_th_3 -> Fill(th_EL,ph_EL-120,1.);

	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_3pe[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-120,1.);
	};
//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+120) && (ph_EL < fid_a+120)&&(PdHit_EL!=44)){

	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_3pe_fid[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-120,1.);
	}; 

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)) th_vs_p_e_2[2]->Fill(P_EL,th_EL,1.);


//vertex cut
if ((z_EL>-2.25) && (z_EL< 2.25)){

//	hist_z_el_3->Fill(z_EL,1.);

  cuts_data = true; 

   };//vertex cut
   };//fiducial 
   };//nphe cut after poisson fit
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

 
// ectot vs p cut 
if ((ECT/P_EL > -0.0509612*P_EL*P_EL+0.163016*P_EL+0.0787492) && (ECT/P_EL < 0.0135551*P_EL*P_EL-0.042061*P_EL+0.387975)){
  
	hist_ectot_sector4->Fill(P_EL,ECT/P_EL,1.);

//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

	nphe_sector4->Fill(nphe,1.);
	
//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){

//th_cc vs seg cut
if ((theta_cc >th_vs_seg_cc_arr[1][3][segment])&&(theta_cc <th_vs_seg_cc_arr[0][3][segment])){

//	th_cc_vs_seg_4->Fill(segment+1,theta_cc,1.);
		
	h_cc_nphe_total_s4->Fill(theta_cc, ph_cc,1.);
	if (nphe > 50) h_cc_nphe_final_s4->Fill(theta_cc, ph_cc,1.);

// geometrical cut on number of photoelectrons
if (norm_nphe_s4->GetBinContent(norm_nphe_s4->GetXaxis()->FindBin(theta_cc),norm_nphe_s4->GetYaxis()->FindBin(ph_cc))>0.65){

	nphe_sector4_after->Fill(nphe,1.);


//nphe cut after poisson fit 	
if (nphe > ph_el_arr[pmt_hit+1][3][segment]){

	if (pmt_hit == -1) ph_el_left[3][segment]->Fill(nphe,1.);
	if (pmt_hit == 0) ph_el_both[3][segment]->Fill(nphe,1.);
	if (pmt_hit == 1) ph_el_right[3][segment]->Fill(nphe,1.);

	ph_vs_th_4 -> Fill(th_EL,ph_EL-180,1);

	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_4pe[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-180,1.);
		};
//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+180) && (ph_EL < fid_a+180)){

	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_4pe_fid[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-180,1.);
	};


//th_vs_p    	
//if ((th_EL > (11.7398+5./(0.433327*(P_EL+0.1)+0.015)) +8.)||(th_EL < (11.7398+12./(0.433327*(P_EL+0.1)+0.24)) -0.4)){
//if ((th_EL > (11.7398+5./(0.433327*(P_EL+0.1)+0.04)) +15.6)||(th_EL < (11.7398+5./(0.433327*(P_EL+0.1)+0.04)) +14.1)){

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)) th_vs_p_e_2[3]->Fill(P_EL,th_EL,1.); 


//vertex cut
if ((z_EL>-2.45) && (z_EL< 2.05)){

//	hist_z_el_4->Fill(z_EL,1.);

   cuts_data = true; 
   };//vertex cut 
//   };//th_vs_p
//   };//th_vs_p
   };//fiducial 
   };//nphe cut after poisson fit 
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

  
// ectot vs p cut 
if ((ECT/P_EL > -0.0584054*P_EL*P_EL+0.18591*P_EL+0.0577907) && (ECT/P_EL < 0.0180595*P_EL*P_EL-0.052512*P_EL+0.404114)&&(PdHit_EL != 17)){

	hist_ectot_sector5->Fill(P_EL,ECT/P_EL,1.);   

//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {
	
	nphe_sector5->Fill(nphe,1.);	
	
//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){

	
//th_cc vs seg cut
if ((theta_cc >th_vs_seg_cc_arr[1][4][segment])&&(theta_cc <th_vs_seg_cc_arr[0][4][segment])){	
	
	//th_cc_vs_seg_5->Fill(segment+1,theta_cc,1.);
			
	h_cc_nphe_total_s5->Fill(theta_cc, ph_cc,1.);
	if (nphe > 50) h_cc_nphe_final_s5->Fill(theta_cc, ph_cc,1.);
	
// geometrical cut on number of photoelectrons
if (norm_nphe_s5->GetBinContent(norm_nphe_s5->GetXaxis()->FindBin(theta_cc),norm_nphe_s5->GetYaxis()->FindBin(ph_cc))>0.8){

	nphe_sector5_after->Fill(nphe,1.);
	

//nphe cut after poisson fit 	
if (nphe > ph_el_arr[pmt_hit+1][4][segment]){

	if (pmt_hit == -1) ph_el_left[4][segment]->Fill(nphe,1.);
	if (pmt_hit == 0) ph_el_both[4][segment]->Fill(nphe,1.);
	if (pmt_hit == 1) ph_el_right[4][segment]->Fill(nphe,1.);


	ph_vs_th_5 -> Fill(th_EL,ph_EL-240,1);
  
	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_5pe[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-240,1.);
		};
//fiducial cut
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+240) && (ph_EL < fid_a+240)&&(PdHit_EL!=17)){


 
//th_vs_p
if ((th_EL > (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.158076))+19.9)||(th_EL < (11.7398+8.21504/(0.433327*(P_EL+0.1)+0.158076))+17.6)){
if ((th_EL > (11.7398+4.3/(0.433327*(P_EL+0.1)+0.158076))+15.8)||(th_EL < (11.7398+4.5/(0.433327*(P_EL+0.1)+0.158076))+13.5)){

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)) th_vs_p_e_2[4]->Fill(P_EL,th_EL,1.);
	
	
	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_5pe_fid[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-240,1.);
	};


//vertex cut
if ((z_EL>-2.9) && (z_EL< 1.6)){
  
//	hist_z_el_5->Fill(z_EL,1.);  
	
   cuts_data = true; 
   
   };//vertex cut
   };//th_vs_p
  };//th_vs_p   
   };//fiducial 
   };//nphe cut after poisson fit    
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


// ectot vs p cut  
if ((ECT/P_EL > -0.03943*P_EL*P_EL+0.149493*P_EL+0.0789496) && (ECT/P_EL < 0.0123265*P_EL*P_EL-0.0290198*P_EL+0.380917)){

	hist_ectot_sector6->Fill(P_EL,ECT/P_EL,1.);   

//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {

	nphe_sector6->Fill(nphe,1.);

//phi_cc matching
if (((ph_cc>0)&&(pmt_hit==1))||((ph_cc<0)&&(pmt_hit==-1))||(pmt_hit==0)){


//th_cc vs seg cut 
if ((theta_cc >th_vs_seg_cc_arr[1][5][segment])&&(theta_cc <th_vs_seg_cc_arr[0][5][segment])){

//	th_cc_vs_seg_6->Fill(segment+1,theta_cc,1.);
	
	h_cc_nphe_total_s6->Fill(theta_cc, ph_cc,1.);
	if (nphe > 50) h_cc_nphe_final_s6->Fill(theta_cc, ph_cc,1.);


// geometrical cut on number of photoelectrons
if (norm_nphe_s6->GetBinContent(norm_nphe_s6->GetXaxis()->FindBin(theta_cc),norm_nphe_s6->GetYaxis()->FindBin(ph_cc))>0.8){

	nphe_sector6_after->Fill(nphe,1.);	
	

//nphe cut after poisson fit	
if (nphe > ph_el_arr[pmt_hit+1][5][segment]){

	if (pmt_hit == -1) ph_el_left[5][segment]->Fill(nphe,1.);
	if (pmt_hit == 0) ph_el_both[5][segment]->Fill(nphe,1.);
	if (pmt_hit == 1) ph_el_right[5][segment]->Fill(nphe,1.);


	ph_vs_th_6 -> Fill(th_EL,ph_EL-300,1); 

	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_6pe[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-300,1.);
	};

//fiducial cut	
if ((th_EL > th_min) && (th_EL < th_max)&& (ph_EL > fid_b+300) && (ph_EL < fid_a+300)){

	if ((P_EL < 1.75999) &&(P_EL > 0.4))  {
	ph_vs_th_6pe_fid[int((P_EL*100-40)/8)] ->Fill(th_EL,ph_EL-300,1.);
	};

//th_vs_p 
//if ((th_EL > (11.7398+5./(0.433327*(P_EL+0.1)+0.015)) +8.3)||(th_EL < (11.7398+12./(0.433327*(P_EL+0.1)+0.27)) +0.3)){

	if ((W>1.3)&&(W<1.825)&&(Q2>0.4)&&(Q2<1.)) th_vs_p_e_2[5]->Fill(P_EL,th_EL,1.); 

//vertex cut
if ((z_EL>-3.) && (z_EL<1.5)){

//	hist_z_el_6->Fill(z_EL,1.);
	
   cuts_data = true; 
   
   };//vertex  
//   };//th_vs_p
   };//fiducial
   };//nphe cut after poisson fit
   };//geometrical cut on number of photoelectrons
   };//th_cc vs seg cut      
   };//phi_cc matching
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane
   };//~fid cuts in Cherenkov plane   
 
 };//ectot vs p cut
 break;      
 
   
   };//end of switch
  };//end of calorimeter threshold cut
  };//end of quality check cuts
   

   
   
   return cuts_data;
   
   };



    
   
   
