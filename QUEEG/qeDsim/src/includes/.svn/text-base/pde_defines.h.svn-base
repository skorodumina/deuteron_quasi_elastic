#ifndef PDE_DEFINES_H_
#define PDE_DEFINES_H_

using namespace std;


//data location in ntuple file
#define PDE_BRANCH_NAME "pde_branch"

//vertex cuts for H2 target in cm
#define pde_Z_MIN -3.1 
#define pde_Z_MAX 3.1
#define TARGET_RADIUS 10.0 //this is way to big, and will effectively eliminate
                           //this cut until I can look up the right number


//timing cuts
#define PROTON_TIME 0.65
#define PROTON_MASS_LOW 0.8
#define PROTON_MASS_HIGH 1.1

//cuts on allowed delta_beta region
#define PROTON_DELTA_BETA_MIN -0.05
#define PROTON_DELTA_BETA_MAX 0.05

//#define PROTON_DELTA_BETA_MIN -100.0
//#define PROTON_DELTA_BETA_MAX 100.0

//cut on difference between observed and elastic energy
#define RATIO_E_LOW 0.95
#define RATIO_E_HIGH 1.05
//#define pde_WSQ_MIN 0.75
//#define pde_WSQ_MAX 1.05
//#define pde_WSQ_MIN 0.8
//#define pde_WSQ_MAX 0.925
#define pde_WSQ_MIN 0.5
#define pde_WSQ_MAX 1.0

#define COPLAN_LOW 176
#define COPLAN_HIGH 184
#define DELTA_THETA_HIGH 4
#define DELTA_THETA_LOW -4
#define DELTA_PHI_HIGH 5
#define DELTA_PHI_LOW -5

//values for missing proton events
#define DEFAULT -500.00
#define FOUND_PROTON 1
#define NO_PROTON 0

#define pde_DELTA_PADDLE 1

//cuts for beam energy determination
#define pde_DELTA_PHI_LOW 178.0
#define pde_DELTA_PHI_HIGH 182.0
#define pde_W_MAX 0.96

enum pde_EVENT_STATUS_t {pdeREAD_ENTRY,pdeELASTIC,pdeFOUND,pdeFILE_END};

#endif

