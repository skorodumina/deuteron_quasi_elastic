#ifndef J_EC_NDE_EFF_H_
#define J_EC_NDE_EFF_H_

#include "ec_nde_defines.h"
#include "ec_nde_includes.h"
#include "Jnde_pars.h"
#include "Jec_geom.h"

Double_t eceff(Double_t *x, Double_t *par);

class Jec_nde_eff{
 public:
  Jec_nde_eff(void);
  void load_histos(char *histofile);
  Double_t eff_func(Double_t p,int sector, int pixel);
  Double_t eff_func(Double_t p,int sector);
  Double_t get_error(Double_t p, int sector, int pixel);
  void do_fits(void);
  float calc_chisq_ndf(TH1F *h, TF1 *func, float scale);
  void calc_scale_factor(int index, float &scale, float &scale_errot);
  void fill_histos(int index,TF1 *func);
  float eval_par_deriv(float pval,int parno,int index);
  void set_pixel_density(int np);
  int sp2index(int sector,int pixel);
  void index2sp(int index, int &sector, int &pixel);
  int get_npixels_total(void);

 private:
  int pixel_density;
  int npixels_sector;
  int npixels_total;
  TFile *file,*outfile;
  Jec_geom *ec_geom;
  TH1F **eff_histo;
  TH1F **eff_fit, **eff_error;
  Double_t ecparms[1+NSECTOR][5];
  Double_t *scale_factor_array,*scale_error_array;
  TF1 *eff_tf1,*dfunc;
};

#endif
