#ifndef J_QE_ANA_DEFINES_H_
#define J_QE_ANA_DEFINES_H_

using namespace std;

#include "ec_nde_defines.h"

//define output tree names
#define QE_OUTPUT_TREE "qe_output_tree"
#define QE_BRANCH_NAME "qe_branch_name"

//histogram specifications
#define qe_NBINS 33
//#define qe_NBINS 150
#define qe_QSQ_LOW 0.0
#define qe_QSQ_HIGH 5.0

//hadron types
enum HADRON_TYPE_t {PROTON,NEUTRON};
enum FF_PARAM_t {DIPOLE,BOSTED,BRASH,LOMON,ARRINGTON};

//cuts

//cut on allowed proton delta_beta region
#define qe_PROTON_DELTA_BETA_MAX 0.8
#define qe_PROTON_DELTA_BETA_MIN -0.8

//wsq region for quasi elastic scattering
#define qe_WSQ_MIN 0.0
#define qe_WSQ_MAX 2.5

//D2 target region
#define D2_Z_MIN -13.0
#define D2_Z_MAX -7.0

//qe version of neutron selection cuts
#define qe_DELTA_CUT_EC 60.0
#define qe_TIME_CUT_LOW_EC -20.0
#define qe_TIME_CUT_HIGH_EC 20.0
#define qe_E_CUT_EC 0.015
#define qe_DELTA_CUT_LAC 90.0
#define qe_TIME_CUT_LOW_LAC -2000.0
#define qe_TIME_CUT_HIGH_LAC 2000.0
#define qe_E_CUT_LAC 0.015
#define qe_SC_ADJ_PADDLE 2
#define qe_SC_TIME_MIN -50.0
#define qe_SC_TIME_MAX 50.0
#define qe_E_CUT_SC 1.0 //scrc reports energy in MeV

//qe thet_gn cut parameters and final W2 cut
#define qe_THETA_GN_MAX 3.0
#define qe_WSQ_FINAL_LOW 0.6
#define qe_WSQ_FINAL_HIGH 1.1

//fiducial cut values
#define qe_EC_NDE_MIN 0.05
#define qe_LAC_NDE_MIN 0.05
#define qe_PDE_MIN 0.85
//#define qe_PDE_MIN 0.65
#define qe_SC_NDE_MIN 0.01

//histo parameters for ratio vs. phi plots
#define qe_NQSQ_BINS 15
#define qe_QSQ_MAX 2.5

//qe event generator
#define qe_N_QE_EVENTS 1e6

enum QE_REACTION_TYPE_t {qe_READ_ENTRY,qe_PROTON,qe_NEUTRON,qe_FILE_END};




#endif
