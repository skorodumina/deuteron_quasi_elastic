#ifndef J_MOM_CORR_CALC_H_
#define J_MOM_CORR_CALC_H_

#include "mom_corr2_includes.h"
#include "Jmom_corr2_util.h"

class Jmom_corr2_calc{
 public:
  Jmom_corr2_calc(char *inputfile);
  vector4_t get_corrected_vector(vector4_t xvec);
  int get_sector(vector4_t xvec);
  int get_sector(float phi);
 private:
  TFile *infile;
  TTree *tree;
  float *alpha;
  Jmom_corr2_util *util;
  mc2_event_t parm;
};

#endif
  
