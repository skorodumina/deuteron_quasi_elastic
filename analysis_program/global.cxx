#include "TROOT.h"
#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "THnSparse.h"
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
#include "global.h"
#include <stdio.h>
#include <dlfcn.h>
#include <sstream>
#include <TLorentzVector.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring> 
#include <cstdlib>

 using namespace std; 
 
Int_t npart,segment,sector,indtype,n_P,n_PIp,n_PIm;
Short_t pmt_hit;
Int_t PdHit_EL; 
 
 Float_t m_proton,m_pip,beta;
 
 Float_t LiveTime,inclusive,elastic,P_EL,th_EL,z_EL,ph_EL,ECT,nphe,theta_cc,ph_cc;
 
TLorentzVector P4_EL,P4_ELP_reg;
Float_t W,Q2;






Float_t sc_x,sc_y;
 



THnSparse* whatever;

/*TH2F *hist_sector1 = new TH2F("cc_sector1","cc_sector1",200, -5., 55.,200., -25., 25.);
TH2F *hist_sector2 = new TH2F("cc_sector2","cc_sector2",200, -5., 55.,200., -25., 25.);
TH2F *hist_sector3 = new TH2F("cc_sector3","cc_sector3",200, -5., 55.,200., -25., 25.);
TH2F *hist_sector4 = new TH2F("cc_sector4","cc_sector4",200, -5., 55.,200., -25., 25.);
TH2F *hist_sector5 = new TH2F("cc_sector5","cc_sector5",200, -5., 55.,200., -25., 25.);
TH2F *hist_sector6 = new TH2F("cc_sector6","cc_sector6",200, -5., 55.,200., -25., 25.);*/

TH1F *nphe_sector1 = new TH1F("nphe_sector1","nphe_sector1",501, -1., 500.);
TH1F *nphe_sector1_after = new TH1F("nphe_sector1_after","nphe_sector1_after",501, -1., 500.);
TH1F *nphe_sector2 = new TH1F("nphe_sector2","nphe_sector2",501, -1., 500.);
TH1F *nphe_sector2_after = new TH1F("nphe_sector2_after","nphe_sector2_after",501, -1., 500.);
TH1F *nphe_sector3 = new TH1F("nphe_sector3","nphe_sector3",501, -1., 500.);
TH1F *nphe_sector3_after = new TH1F("nphe_sector3_after","nphe_sector3_after",501, -1., 500.);
TH1F *nphe_sector4 = new TH1F("nphe_sector4","nphe_sector4",501, -1., 500.);
TH1F *nphe_sector4_after = new TH1F("nphe_sector4_after","nphe_sector4_after",501, -1., 500.);
TH1F *nphe_sector5 = new TH1F("nphe_sector5","nphe_sector5",501, -1., 500.);
TH1F *nphe_sector5_after = new TH1F("nphe_sector5_after","nphe_sector5_after",501, -1., 500.);
TH1F *nphe_sector6 = new TH1F("nphe_sector6","nphe_sector6",501, -1., 500.);
TH1F *nphe_sector6_after = new TH1F("nphe_sector6_after","nphe_sector6_after",501, -1., 500.);


/*TH2F *hist_nphe_sector1 = new TH2F("cc_nphe_sector1","cc_nphe_sector1",200, -5., 55.,200., -25., 25.);
TH2F *hist_nphe_sector2 = new TH2F("cc_nphe_sector2","cc_nphe_sector2",200, -5., 55.,200., -25., 25.);
TH2F *hist_nphe_sector3 = new TH2F("cc_nphe_sector3","cc_nphe_sector3",200, -5., 55.,200., -25., 25.);
TH2F *hist_nphe_sector4 = new TH2F("cc_nphe_sector4","cc_nphe_sector4",200, -5., 55.,200., -25., 25.);
TH2F *hist_nphe_sector5 = new TH2F("cc_nphe_sector5","cc_nphe_sector5",200, -5., 55.,200., -25., 25.);
TH2F *hist_nphe_sector6 = new TH2F("cc_nphe_sector6","cc_nphe_sector6",200, -5., 55.,200., -25., 25.);*/

TH2F  *avrg_nphe_sector1,*avrg_nphe_sector2,*avrg_nphe_sector3,*avrg_nphe_sector4,*avrg_nphe_sector5,*avrg_nphe_sector6;

TH2F  *norm_nphe_s1,*norm_nphe_s2,*norm_nphe_s3,*norm_nphe_s4,*norm_nphe_s5,*norm_nphe_s6;


TH2F *ph_vs_th_el_sim[6][7];


TH2F *h_cc_nphe_total_s1 = new TH2F("h_cc_nphe_total_s1","h_cc_nphe_total_s1",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_total_s2 = new TH2F("h_cc_nphe_total_s2","h_cc_nphe_total_s2",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_total_s3 = new TH2F("h_cc_nphe_total_s3","h_cc_nphe_total_s3",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_total_s4 = new TH2F("h_cc_nphe_total_s4","h_cc_nphe_total_s4",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_total_s5 = new TH2F("h_cc_nphe_total_s5","h_cc_nphe_total_s5",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_total_s6 = new TH2F("h_cc_nphe_total_s6","h_cc_nphe_total_s6",200, -5., 55.,200., -25., 25.);


TH2F *h_cc_nphe_final_s1 = new TH2F("h_cc_nphe_final_s1","h_cc_nphe_final_s1",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_final_s2 = new TH2F("h_cc_nphe_final_s2","h_cc_nphe_final_s2",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_final_s3 = new TH2F("h_cc_nphe_final_s3","h_cc_nphe_final_s3",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_final_s4 = new TH2F("h_cc_nphe_final_s4","h_cc_nphe_final_s4",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_final_s5 = new TH2F("h_cc_nphe_final_s5","h_cc_nphe_final_s5",200, -5., 55.,200., -25., 25.);
TH2F *h_cc_nphe_final_s6 = new TH2F("h_cc_nphe_final_s6","h_cc_nphe_final_s6",200, -5., 55.,200., -25., 25.);




TH2F *hist_ectot_sector1 = new TH2F("ectot_sector1","ectot_sector1",220, -0.005, 2.195,80, -0.005, 0.795);
TH2F *hist_ectot_sector2 = new TH2F("ectot_sector2","ectot_sector2",220, -0.005, 2.195,80, -0.005, 0.795);
TH2F *hist_ectot_sector3 = new TH2F("ectot_sector3","ectot_sector3",220, -0.005, 2.195,80, -0.005, 0.795);
TH2F *hist_ectot_sector4 = new TH2F("ectot_sector4","ectot_sector4",220, -0.005, 2.195,80, -0.005, 0.795);
TH2F *hist_ectot_sector5 = new TH2F("ectot_sector5","ectot_sector5",220, -0.005, 2.195,80, -0.005, 0.795);
TH2F *hist_ectot_sector6 = new TH2F("ectot_sector6","ectot_sector6",220, -0.005, 2.195,80, -0.005, 0.795);

TH2F *hist_ectot_sector1_sim = new TH2F("ectot_sector1_sim","ectot_sector1_sim",440, -0.005, 2.195,160, -0.005, 0.795);
TH2F *hist_ectot_sector2_sim = new TH2F("ectot_sector2_sim","ectot_sector2_sim",440, -0.005, 2.195,160, -0.005, 0.795);
TH2F *hist_ectot_sector3_sim = new TH2F("ectot_sector3_sim","ectot_sector3_sim",440, -0.005, 2.195,160, -0.005, 0.795);
TH2F *hist_ectot_sector4_sim = new TH2F("ectot_sector4_sim","ectot_sector4_sim",440, -0.005, 2.195,160, -0.005, 0.795);
TH2F *hist_ectot_sector5_sim = new TH2F("ectot_sector5_sim","ectot_sector5_sim",440, -0.005, 2.195,160, -0.005, 0.795);
TH2F *hist_ectot_sector6_sim = new TH2F("ectot_sector6_sim","ectot_sector6_sim",440, -0.005, 2.195,160, -0.005, 0.795);


TH2F *W_incl = new TH2F("W_incl","W_incl",200, 0.8, 1.9,200., 0.2, 1.9);






TH1F *hist_z_el_1 = new TH1F("hist_z_el_1","hist_z_el_1",400, -10.,10.);
TH1F *hist_z_el_2 = new TH1F("hist_z_el_2","hist_z_el_2",400, -10.,10.);
TH1F *hist_z_el_3 = new TH1F("hist_z_el_3","hist_z_el_3",400, -10.,10.);
TH1F *hist_z_el_4 = new TH1F("hist_z_el_4","hist_z_el_4",400, -10.,10.);
TH1F *hist_z_el_5 = new TH1F("hist_z_el_5","hist_z_el_5",400, -10.,10.);
TH1F *hist_z_el_6 = new TH1F("hist_z_el_6","hist_z_el_6",400, -10.,10.);


TH1F *hist_z_el_1_empty = new TH1F("hist_z_el_1_empty","hist_z_el_1_empty",400, -10.,10.);
TH1F *hist_z_el_2_empty = new TH1F("hist_z_el_2_empty","hist_z_el_2_empty",400, -10.,10.);
TH1F *hist_z_el_3_empty = new TH1F("hist_z_el_3_empty","hist_z_el_3_empty",400, -10.,10.);
TH1F *hist_z_el_4_empty = new TH1F("hist_z_el_4_empty","hist_z_el_4_empty",400, -10.,10.);
TH1F *hist_z_el_5_empty = new TH1F("hist_z_el_5_empty","hist_z_el_5_empty",400, -10.,10.);
TH1F *hist_z_el_6_empty = new TH1F("hist_z_el_6_empty","hist_z_el_6_empty",400, -10.,10.);


TH1F *hist_z_el_1_sim_1 = new TH1F("hist_z_el_1_sim_1","hist_z_el_1_sim_1",400, -10.,10.);
TH1F *hist_z_el_2_sim_1 = new TH1F("hist_z_el_2_sim_1","hist_z_el_2_sim_1",400, -10.,10.);
TH1F *hist_z_el_3_sim_1 = new TH1F("hist_z_el_3_sim_1","hist_z_el_3_sim_1",400, -10.,10.);
TH1F *hist_z_el_4_sim_1 = new TH1F("hist_z_el_4_sim_1","hist_z_el_4_sim_1",400, -10.,10.);
TH1F *hist_z_el_5_sim_1 = new TH1F("hist_z_el_5_sim_1","hist_z_el_5_sim_1",400, -10.,10.);
TH1F *hist_z_el_6_sim_1 = new TH1F("hist_z_el_6_sim_1","hist_z_el_6_sim_1",400, -10.,10.);

TH1F *hist_z_el_1_sim_2 = new TH1F("hist_z_el_1_sim_2","hist_z_el_1_sim_2",400, -10.,10.);
TH1F *hist_z_el_2_sim_2 = new TH1F("hist_z_el_2_sim_2","hist_z_el_2_sim_2",400, -10.,10.);
TH1F *hist_z_el_3_sim_2 = new TH1F("hist_z_el_3_sim_2","hist_z_el_3_sim_2",400, -10.,10.);
TH1F *hist_z_el_4_sim_2 = new TH1F("hist_z_el_4_sim_2","hist_z_el_4_sim_2",400, -10.,10.);
TH1F *hist_z_el_5_sim_2 = new TH1F("hist_z_el_5_sim_2","hist_z_el_5_sim_2",400, -10.,10.);
TH1F *hist_z_el_6_sim_2 = new TH1F("hist_z_el_6_sim_2","hist_z_el_6_sim_2",400, -10.,10.);












TH2F *ph_vs_th_1 = new TH2F("ph_vs_th_1","ph_vs_th_1",200, 0., 60.,150., -35., 35.);
TH2F *ph_vs_th_2 = new TH2F("ph_vs_th_2","ph_vs_th_2",200, 0., 60.,150., -35., 35.);
TH2F *ph_vs_th_3 = new TH2F("ph_vs_th_3","ph_vs_th_3",200, 0., 60.,150., -35., 35.);
TH2F *ph_vs_th_4 = new TH2F("ph_vs_th_4","ph_vs_th_4",200, 0., 60.,150., -35., 35.);
TH2F *ph_vs_th_5 = new TH2F("ph_vs_th_5","ph_vs_th_5",200, 0., 60.,150., -35., 35.);
TH2F *ph_vs_th_6 = new TH2F("ph_vs_th_6","ph_vs_th_6",200, 0., 60.,150., -35., 35.);



ostringstream qqq;
Short_t i,j;
TH2F *ph_vs_th_1pe[17],*ph_vs_th_2pe[17],*ph_vs_th_3pe[17],*ph_vs_th_4pe[17],*ph_vs_th_5pe[17],*ph_vs_th_6pe[17];
TH2F *ph_vs_th_1pe_fid[17],*ph_vs_th_2pe_fid[17],*ph_vs_th_3pe_fid[17],*ph_vs_th_4pe_fid[17],*ph_vs_th_5pe_fid[17],*ph_vs_th_6pe_fid[17];






//photoelectrons
TH1F *ph_el_left[6][20];
TH1F *ph_el_both[6][20];
TH1F *ph_el_right[6][20];



 TH1F *h_th_el_arr_elast[180];
 TH1F *h_th_el_arr_elast_sim[180];
 TH1F *h_th_el_arr_elast_sim_gen[180];
 
 TH1F *h_th_el_arr_delta[180];
 TH1F *h_th_el_arr_delta_sim[180];
 TH1F *h_th_el_arr_delta_sim_gen[180];
 
 TH1F *h_th_el_arr_w15[180];
 TH1F *h_th_el_arr_w15_sim[180];
 TH1F *h_th_el_arr_w15_sim_gen[180];
 
 TH1F *h_th_el_arr_w17[180];
 TH1F *h_th_el_arr_w17_sim[180];
 TH1F *h_th_el_arr_w17_sim_gen[180];
 
 
  TH1F *h_th_el_arr_incl[110][180];
  TH1F *h_th_el_arr_incl_sim[110][180];
  TH1F *h_th_el_arr_incl_sim_gen[110][180]; 


  
TH1F *h_w_arr_incl[30][180];
TH1F *h_w_arr_incl_sim[30][180];
TH1F *h_w_arr_incl_sim_gen[30][180];  
  

TH1F *h_w_inclusive[6][13];
TH1F *h_w_inclusive_sim[6][13];
TH1F *h_w_inclusive_sim_gen[6][13]; 


TH1D *h_w_int[12];
TH2F *th_cc_vs_seg[6];
TH2F *th_cc_vs_seg_sim[6];
TH2F *th_vs_p_e_1[6], *th_vs_p_e_2[6];
TH2F *th_vs_p_e_1_sim[6], *th_vs_p_e_2_sim[6]; 
// booking proton histograms

TH2F *ph_vs_th_p_1 = new TH2F("ph_vs_th_p_1","ph_vs_th_p_1",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_2 = new TH2F("ph_vs_th_p_2","ph_vs_th_p_2",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_3 = new TH2F("ph_vs_th_p_3","ph_vs_th_p_3",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_4 = new TH2F("ph_vs_th_p_4","ph_vs_th_p_4",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_5 = new TH2F("ph_vs_th_p_5","ph_vs_th_p_5",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_6 = new TH2F("ph_vs_th_p_6","ph_vs_th_p_6",220, 0., 110.,150., -35., 35.);

TH2F *ph_vs_th_p_1_w = new TH2F("ph_vs_th_p_1_w","ph_vs_th_p_1_w",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_2_w = new TH2F("ph_vs_th_p_2_w","ph_vs_th_p_2_w",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_3_w = new TH2F("ph_vs_th_p_3_w","ph_vs_th_p_3_w",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_4_w = new TH2F("ph_vs_th_p_4_w","ph_vs_th_p_4_w",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_5_w = new TH2F("ph_vs_th_p_5_w","ph_vs_th_p_5_w",220, 0., 110.,150., -35., 35.);
TH2F *ph_vs_th_p_6_w = new TH2F("ph_vs_th_p_6_w","ph_vs_th_p_6_w",220, 0., 110.,150., -35., 35.);




TFile *outFile;

// bookking quality check histograms

TH1F *hist_ltime = new TH1F("ltime","ltime",35000, -.5, 34999.5);
TH1F *hist_ltime_1d = new TH1F("ltime_1d","ltime_1d",1100, 0., 1.1);
TH1F *hist_n_incl = new TH1F("n_incl","n_incl",35000, -.5, 34999.5);
TH1F *hist_n_incl_1d = new TH1F("n_incl_1d","n_incl_1d",1000, 0., 300000.);
TH1F *hist_n_elast = new TH1F("n_elast","n_elast",35000, -.5, 34999.5);
TH1F *hist_n_elast_1d = new TH1F("n_elast_1d","n_elast_1d",1000, 0., 80000.);



int global() {


// loops for electron histograms

for (i=0; i<17; i++) {
qqq << "ph_vs_th_1pe[" << i << "]";
ph_vs_th_1pe[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_2pe[" <<i << "]";
ph_vs_th_2pe[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_3pe[" << i << "]";
ph_vs_th_3pe[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_4pe[" << i << "]";
ph_vs_th_4pe[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_5pe[" << i << "]";
ph_vs_th_5pe[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_6pe[" << i << "]";
ph_vs_th_6pe[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_1pe_fid[" << i << "]";
ph_vs_th_1pe_fid[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_2pe_fid[" << i << "]";
ph_vs_th_2pe_fid[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_3pe_fid[" << i << "]";
ph_vs_th_3pe_fid[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_4pe_fid[" << i << "]";
ph_vs_th_4pe_fid[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_5pe_fid[" << i << "]";
ph_vs_th_5pe_fid[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};


for (i=0; i<17; i++) {
qqq << "ph_vs_th_6pe_fid[" << i << "]";
ph_vs_th_6pe_fid[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),200, 0., 60.,150., -35., 35.);
qqq.str("");
};













   










for(j=0; j<12; j++){
qqq << "w_int_" << j+1;
h_w_int[j] = new TH1D(qqq.str().c_str(),qqq.str().c_str(),21, 1.3,1.825);
qqq.str("");
};

for (i=0; i<6; i++) {
for(j=0; j<20; j++){
qqq << "sector_" << i+1 << "_left_" << j+1 ;
ph_el_left[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),500, 0.,500);
qqq.str("");
};
};

for (i=0; i<6; i++) {
for(j=0; j<20; j++){
qqq << "sector_" << i+1 << "_both_" << j+1 ;
ph_el_both[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),500, 0.,500);
qqq.str("");
};
};

for (i=0; i<6; i++) {
for(j=0; j<20; j++){
qqq << "sector_" << i+1 << "_right_" << j+1 ;
ph_el_right[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),500, 0.,500);
qqq.str("");
};
};

for (i=0; i<6; i++) {
qqq << "th_cc_vs_seg_" << i+1;
th_cc_vs_seg[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),20, -0.5,19.5,200,0.,50.);
qqq.str("");

qqq << "th_cc_vs_seg_sim_" << i+1;
th_cc_vs_seg_sim[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),20, -0.5,19.5,200,0.,50.);
qqq.str("");





qqq << "th_vs_p_e_1_" << i+1;
th_vs_p_e_1[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),440, 0.,2.2,180,0.,60.);
qqq.str("");
qqq << "th_vs_p_e_2_" << i+1;
th_vs_p_e_2[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),440, 0.,2.2,180,0.,60.);
qqq.str("");


qqq << "th_vs_p_e_1_sim_" << i+1;
th_vs_p_e_1_sim[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),440, 0.,2.2,180,0.,60.);
qqq.str("");
qqq << "th_vs_p_e_2_sim_" << i+1;
th_vs_p_e_2_sim[i] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),440, 0.,2.2,180,0.,60.);
qqq.str("");

};

for (i=0; i<6; i++) {
for(j=0; j<7; j++){
qqq << "ph_vs_th_el_sim_" << i+1 << "_" << j+1;
ph_vs_th_el_sim[i][j] = new TH2F(qqq.str().c_str(),qqq.str().c_str(),240, 0., 60.,210., -35., 35.);
qqq.str("");
};
};

Float_t Epeak[13] = {1.739, 1.694, 1.649, 1.602, 1.556, 1.51, 1.464, 1.418, 1.374, 1.33, 1.287, 1.246, 1.206};


for (i=0; i<6; i++) {
for(j=0; j<13; j++){


qqq << "h_w_inclusive_" << i+1 << "_" << j+1;
h_w_inclusive[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),40, 0.805,1.205);
qqq.str("");

qqq << "h_w_inclusive_sim_" << i+1 << "_" << j+1;
h_w_inclusive_sim[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),40,0.805,1.205);
qqq.str("");

qqq << "h_w_inclusive_sim_gen_" << i+1 << "_" << j+1;
h_w_inclusive_sim_gen[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),40, 0.805,1.205);
qqq.str("");

};
};

for (i=0; i<180; i++) {
qqq.str("");
qqq << "h_th_el_arr_elast_ph_" << 2*i+1 ;
h_th_el_arr_elast[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_elast_sim_ph_" << 2*i+1 ;
h_th_el_arr_elast_sim[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_elast_sim_gen_ph_" << 2*i+1 ;
h_th_el_arr_elast_sim_gen[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");


qqq << "h_th_el_arr_delta_ph_" << 2*i+1 ;
h_th_el_arr_delta[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_delta_sim_ph_" << 2*i+1 ;
h_th_el_arr_delta_sim[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_delta_sim_gen_ph_" << 2*i+1 ;
h_th_el_arr_delta_sim_gen[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");


qqq << "h_th_el_arr_w15_ph_" << 2*i+1 ;
h_th_el_arr_w15[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_w15_sim_ph_" << 2*i+1 ;
h_th_el_arr_w15_sim[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_w15_sim_gen_ph_" << 2*i+1 ;
h_th_el_arr_w15_sim_gen[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");



qqq << "h_th_el_arr_w17_ph_" << 2*i+1 ;
h_th_el_arr_w17[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_w17_sim_ph_" << 2*i+1 ;
h_th_el_arr_w17_sim[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_w17_sim_gen_ph_" << 2*i+1 ;
h_th_el_arr_w17_sim_gen[i]= new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");


for(j=0; j<110; j++){

qqq.str("");
qqq << "h_th_el_arr_incl_w_" <<100*(0.8+j/100.) << "_ph_"<<2*i+1;
h_th_el_arr_incl[j][i] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_incl_sim_w_" <<100*(0.8+j/100.) << "_ph_"<<2*i+1;
h_th_el_arr_incl_sim[j][i] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");

qqq << "h_th_el_arr_incl_sim_gen_w_" <<100*(0.8+j/100.) << "_ph_"<<2*i+1;
h_th_el_arr_incl_sim_gen[j][i] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),30,19.5,49.5);
qqq.str("");



};
};

for(i=0; i<30; i++){
for(j=0; j<180; j++){


qqq.str("");
qqq << "h_w_arr_incl_th_" <<20.+ i<< "_ph_"<<2*j+1;
h_w_arr_incl[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),110,0.8,1.9);
qqq.str("");

qqq << "h_w_arr_incl_sim_th_" <<20.+i<< "_ph_"<<2*j+1;
h_w_arr_incl_sim[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),110,0.8,1.9);
qqq.str("");

qqq << "h_w_arr_incl_sim_gen_th_" <<20.+i<< "_ph_"<<2*j+1;
h_w_arr_incl_sim_gen[i][j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),110,0.8,1.9);
qqq.str("");



};
};


};
