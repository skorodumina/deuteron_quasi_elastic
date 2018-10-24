#ifndef GLOBAL_H
#include "TROOT.h"
#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "TF2.h"
#include "TF3.h"
#include "TMacro.h"
#include "TCanvas.h"
#include "TVirtualFitter.h"
#include "TMath.h"
#include <math.h>
#include <TLorentzVector.h>
#include "TGraphErrors.h"
#include "TGraph.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TH3F.h"
#include "THnSparse.h"
#include "TText.h"
#include "TStyle.h"
#include "TGObject.h"
#include "TObject.h"
#include "TSystem.h"
#include "TMinuit.h"
#include <TRint.h>
#include <stdio.h>
#include <dlfcn.h>
#define GLOBAL_H

#endif

extern Int_t npart,segment,sector,indtype;
extern Short_t pmt_hit;
extern Int_t PdHit_EL;

extern Float_t m_proton,m_pip,beta;

extern Float_t LiveTime,inclusive,elastic,P_EL,th_EL,z_EL,ph_EL,ECT,nphe,theta_cc,ph_cc;

extern TLorentzVector P4_EL,P4_ELP_reg;



extern Float_t sc_x,sc_y;





extern TH2F *hist_ectot_sector1_sim,*hist_ectot_sector2_sim,*hist_ectot_sector3_sim,*hist_ectot_sector4_sim,*hist_ectot_sector5_sim,*hist_ectot_sector6_sim;
extern TH2F *hist_ectot_sector1,*hist_ectot_sector2,*hist_ectot_sector3,*hist_ectot_sector4,*hist_ectot_sector5,*hist_ectot_sector6;
extern TH2F *W_incl;


extern Float_t W,Q2;
extern TH2F *ph_vs_th_1,*ph_vs_th_2,*ph_vs_th_3,*ph_vs_th_4,*ph_vs_th_5,*ph_vs_th_6;
extern TH2F *ph_vs_th_1pe[17],*ph_vs_th_2pe[17],*ph_vs_th_3pe[17],*ph_vs_th_4pe[17],*ph_vs_th_5pe[17],*ph_vs_th_6pe[17];

extern TH2F *ph_vs_th_el_sim[6][7];


extern TH2F  *h_cc_nphe_total_s1,*h_cc_nphe_total_s2,*h_cc_nphe_total_s3,*h_cc_nphe_total_s4,*h_cc_nphe_total_s5,*h_cc_nphe_total_s6;

extern TH2F  *h_cc_nphe_final_s1,*h_cc_nphe_final_s2,*h_cc_nphe_final_s3,*h_cc_nphe_final_s4,*h_cc_nphe_final_s5,*h_cc_nphe_final_s6;


extern TH2F *ph_vs_th_1pe_fid[17],*ph_vs_th_2pe_fid[17],*ph_vs_th_3pe_fid[17],*ph_vs_th_4pe_fid[17],*ph_vs_th_5pe_fid[17],*ph_vs_th_6pe_fid[17];

extern TH2F *hist_sector1,*hist_sector2,*hist_sector3,*hist_sector4,*hist_sector5,*hist_sector6;
extern TH2F *hist_nphe_sector1,*hist_nphe_sector2,*hist_nphe_sector3,*hist_nphe_sector4,*hist_nphe_sector5,*hist_nphe_sector6;
extern TH1F *nphe_sector1,*nphe_sector2,*nphe_sector3,*nphe_sector4,*nphe_sector5,*nphe_sector6;
extern TH1F *nphe_sector1_after,*nphe_sector2_after,*nphe_sector3_after,*nphe_sector4_after,*nphe_sector5_after,*nphe_sector6_after;
extern TH2F  *ph_vs_th_p_1,*ph_vs_th_p_2,*ph_vs_th_p_3,*ph_vs_th_p_4,*ph_vs_th_p_5,*ph_vs_th_p_6;
extern TH2F  *ph_vs_th_p_1_w,*ph_vs_th_p_2_w,*ph_vs_th_p_3_w,*ph_vs_th_p_4_w,*ph_vs_th_p_5_w,*ph_vs_th_p_6_w;
extern TH2F  *ph_th_p_1[5],*ph_th_p_2[5],*ph_th_p_3[5],*ph_th_p_4[5],*ph_th_p_5[5],*ph_th_p_6[5];
extern TH1F *hist_z_el_1, *hist_z_el_2, *hist_z_el_3, *hist_z_el_4, *hist_z_el_5, *hist_z_el_6;
extern TH1F *hist_z_el_1_empty, *hist_z_el_2_empty, *hist_z_el_3_empty, *hist_z_el_4_empty, *hist_z_el_5_empty, *hist_z_el_6_empty;
extern TH1F *hist_z_el_1_sim_1, *hist_z_el_2_sim_1, *hist_z_el_3_sim_1, *hist_z_el_4_sim_1, *hist_z_el_5_sim_1, *hist_z_el_6_sim_1;
extern TH1F *hist_z_el_1_sim_2, *hist_z_el_2_sim_2, *hist_z_el_3_sim_2, *hist_z_el_4_sim_2, *hist_z_el_5_sim_2, *hist_z_el_6_sim_2;




extern TH2F  *norm_nphe_s1,*norm_nphe_s2,*norm_nphe_s3,*norm_nphe_s4,*norm_nphe_s5,*norm_nphe_s6;

extern TH2F  *avrg_nphe_sector1,*avrg_nphe_sector2,*avrg_nphe_sector3,*avrg_nphe_sector4,*avrg_nphe_sector5,*avrg_nphe_sector6;
extern TFile *outFile;
extern TH1F *hist_ltime,*hist_ltime_1d,*hist_n_incl,*hist_n_incl_1d,*hist_n_elast,*hist_n_elast_1d;
 



  //photoelectrons
  extern TH1F *ph_el_left[6][20];
  extern TH1F *ph_el_both[6][20];
  extern TH1F *ph_el_right[6][20];
  


 extern TH1F *h_th_el_arr_elast[180];
 extern TH1F *h_th_el_arr_elast_sim[180];
 extern TH1F *h_th_el_arr_elast_sim_gen[180];
 
 extern TH1F *h_th_el_arr_delta[180];
 extern TH1F *h_th_el_arr_delta_sim[180];
 extern TH1F *h_th_el_arr_delta_sim_gen[180];
 
 extern TH1F *h_th_el_arr_w15[180];
 extern TH1F *h_th_el_arr_w15_sim[180];
 extern TH1F *h_th_el_arr_w15_sim_gen[180];
 
 extern TH1F *h_th_el_arr_w17[180];
 extern TH1F *h_th_el_arr_w17_sim[180];
 extern TH1F *h_th_el_arr_w17_sim_gen[180];
 
 
  extern TH1F *h_th_el_arr_incl[110][180];
  extern TH1F *h_th_el_arr_incl_sim[110][180];
  extern TH1F *h_th_el_arr_incl_sim_gen[110][180]; 
  
  
  extern TH1F *h_w_arr_incl[30][180];
  extern TH1F *h_w_arr_incl_sim[30][180];
  extern TH1F *h_w_arr_incl_sim_gen[30][180];  
  

  extern TH1F *h_w_inclusive[6][13];
  extern TH1F *h_w_inclusive_sim[6][13];
  extern TH1F *h_w_inclusive_sim_gen[6][13]; 

extern TH1D *h_w_int[12];
extern TH2F *th_cc_vs_seg[6];
extern TH2F *th_cc_vs_seg_sim[6];
extern TH2F *th_vs_p_e_1[6], *th_vs_p_e_2[6], *th_vs_p_p_1[6],*th_vs_p_p_2[6],*th_vs_p_pip_1[6],*th_vs_p_pip_2[6],*th_vs_p_pim_1[6],*th_vs_p_pim_2[6];

extern TH2F *th_vs_p_e_1_sim[6], *th_vs_p_e_2_sim[6], *th_vs_p_p_1_sim[6],*th_vs_p_p_2_sim[6],*th_vs_p_pip_1_sim[6],*th_vs_p_pip_2_sim[6],*th_vs_p_pim_1_sim[6],*th_vs_p_pim_2_sim[6];

int global();
