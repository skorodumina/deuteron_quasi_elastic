#ifndef J_SC_NDE_EFF_H
#define J_SC_NDE_EFF_H

#include "ec_nde_defines.h"
#include "Jsc_geom.h"

Double_t sceff(Double_t *x, Double_t *par);
extern float sc_p_low,sc_p_high;

class Jsc_nde_eff{
 public:
  Jsc_nde_eff(int run,Jsc_geom *insc_geom);
  Jsc_nde_eff(int run);
  void load_histos(char *histofile);
  float get_eff(float p);
  float get_eff(float p, int sector);
  float get_eff(float p, int sector, int paddle);
  float get_eff(float pval, TF1 *func,float scale);
  float get_eff_fiducial(float p, int sector, int paddle);
  float internal_get_eff(float p, int sector, int paddle);
  float get_error(float p, int sector, int paddle);
  float calc_chisq_ndf(TH1F *h, TF1 *func,float scale);
  void calc_scale_factor(TH1F *h, TF1 *func,float &scale_factor,
			 float &scale_error);
  Double_t eval_par_deriv(float pval, int parno);
  void fill_histos(int sector,int paddle, float scale, TF1 *func, TMinuit *gm);
  void do_fits(void);

 private:
  int runno;
  TFile *infile,*outfile;
  char input_file[256];
  double scparms[1+NSECTOR][5];
  bool_t is_first;
  
  float chisq_ndf_array[1+NSECTOR][1+N_SC_PADDLE];
  float scale_factor_array[1+NSECTOR][1+N_SC_PADDLE];
  float scale_error_array[1+NSECTOR][1+N_SC_PADDLE];

  Jsc_geom *sc_geom;

  TH1F *eff[1+NSECTOR][1+N_SC_PADDLE];
  TH1F *nfound_exact[1+NSECTOR][1+N_SC_PADDLE];
  TH1F *nrecon[1+NSECTOR][1+N_SC_PADDLE];
  TF1 *func,*scaled_func;
  TF1 *eff_func;

  TH1F *eff_fit[1+NSECTOR][1+N_SC_PADDLE];
  TH1F *eff_error[1+NSECTOR][1+N_SC_PADDLE];

};

#endif 
