#ifndef J_MOM_CORR2_H_
#define J_MOM_CORR2_H_

#include "mom_corr2_includes.h"

class Jmom_corr2_util{
 public:
  Jmom_corr2_util(float energy);
  int get_theta_index(float theta);
  int get_phi_index(float phi);
  int get_index(float theta,float phi);
  int get_ntheta_bins(void);
  int get_nphi_bins(void);
  int get_nbins();
  int get_sector(float phi);
 private:
  int nbins_theta,nbins_phi;
  int theta_min, theta_max;
};

#endif
