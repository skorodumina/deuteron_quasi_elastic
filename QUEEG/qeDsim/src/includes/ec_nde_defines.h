#ifndef EC_NDE_DEFINES_H_
#define EC_NDE_DEFINES_H_

using namespace std;

//ec geometry
#define N_STRIPS 36

#define NEC_LAYER 2

//lac geometry
#define NLAC_SECTOR 2
#define NLAC_STRIP_X 24
#define NLAC_STRIP_Y 40
#define LAC_PIX_X 2
#define LAC_PIX_Y 4


//sc geometry
#define N_SC_PANEL 4
#define N_SC_PADDLE 48
#define BAD_PANEL -1
#define OFF_PADDLE -1
#define SC_NORMAL_OFFSET 0.0

//tree and branch names
#define RAW_EVENT_TREE "event_output_tree"
#define RAW_EVENT_BRANCH "event_output_branch"
#define PAR_TREE_NAME "parameter_output_tree"
#define PAR_BRANCH "parameter_output_branch"
#define LAC_EVENT_TREE "lac_event_output_tree"
#define LAC_EVENT_BRANCH "lac_event_branch"
#define LAC_PAR_TREE_NAME "lac_parameter_output_tree"
#define LAC_PAR_BRANCH "lac_par_output_branch"
#define SC_EVENT_TREE "sc_event_tree"
#define SC_EVENT_BRANCH "sc_event_branch"
#define NT_BRANCH_NAME "nt_branch"

//event type flags
#define NOT_FOUND_ANGLE -999.0
#define NOT_FOUND_P  -999.0
#define NOT_FOUND_TRIPLE -1

//electron definition cuts
#define EC_MIN_ENERGY_ELECTRON 0.1
#define EC_ELECTRON_FIDUCIAL_EDGE 10.0
//#define EC_PE_MATCH_LOW -0.2
//#define EC_PE_MATCH_HIGH 0.1
#define EC_PE_MATCH_LOW -100000
#define EC_PE_MATCH_HIGH 100000

//cc cuts
#define CC_EFF_MIN 0.0

//allowed mass region for candidate neutrons 
#define MASS_LOW 0.9
#define MASS_HIGH 0.95
//#define MASS_HIGH 0.96
//#define MASS_HIGH 0.97
//#define MASS_HIGH 0.95

//allowed mass region for candidate piplus
#define PIPLUS_LOW 0.05
#define PIPLUS_HIGH 0.20

//allowed delta beta region for candidate piplus
#define PIPLUS_DELTA_BETA_MIN -0.04
#define PIPLUS_DELTA_BETA_MAX 0.04
//#define PIPLUS_DELTA_BETA_MIN -0.02
//#define PIPLUS_DELTA_BETA_MAX 0.02


//allowed mass region for candidate pizero
#define PIZERO_LOW 0.05
#define PIZERO_HIGH 0.20

//timing cuts
#define TIME_CUT_LOW_EC -100.00
#define TIME_CUT_HIGH_EC 100.0
#define TIME_CUT_LOW_LAC -2000.00 //for e1b, lac timing is not related to TOF
#define TIME_CUT_HIGH_LAC 2000.1  //so this cut cannot be used
#define PI_TIME 0.65

//angle cuts for match reconstructed and found neutron
#define THETA_CUT_LOW -10.0
#define THETA_CUT_HIGH 10.0
#define PHI_CUT_LOW -10.0
#define PHI_CUT_HIGH 10.0
#define DELTA_CUT_EC 60.0
//#define DELTA_CUT_EC 64.5
//#define DELTA_CUT_EC 400.0
#define DELTA_CUT_LAC 60.0

//neutron beta cut
#define BETA_CUT_EC 5.0 //turning off beta cut for now
#define BETA_CUT_LAC 5.0
#define LAYER_CUT_EC 100 
#define LAYER_CUT_LAC 100

//neutron energy deposited cut
#define E_CUT_EC 0.015 //ecpb reports energy in GeV
#define E_CUT_LAC 0.015 //lcpb reports energy in GeV
//#define E_CUT_LAC 0.0
#define E_CUT_SC 5.0 //scrc reports energy in MeV

//optional fiducial cut
#define FIDUCIAL_CUT_DISTANCE 30.0
//#define FIDUCIAL_CUT_DISTANCE 50.0
#define NEUTRON_FIDUCIAL_CUT_DISTANCE 30.0 //not currently used
#define FIDUCIAL_CUT_STRIP 0
#define FIDUCIAL_CUT_STRIP_X_LAC 0
#define FIDUCIAL_CUT_STRIP_Y_LAC 0
#define FIDUCIAL_CUT_DISTANCE_LAC 15.0

//sc cuts
#define SC_ADJ_PADDLE 1
//#define SC_ADJ_PADDLE 2
#define SC_TIME_MIN -0.8
#define SC_TIME_MAX 2.8

#define SC_THETA_MIN 7.7
#define SC_PANEL2_THETA_MIN 46
#define DELTA_PADDLE 1
#define SC_NDE_CHISQNDF_MAX 4.0

//limits for efficiency fitting
#define EC_NDE_FIT_P_LOW 0.25
#define EC_NDE_FIT_P_HIGH 4.0
#define LAC_NDE_FIT_P_LOW 0.25
#define LAC_NDE_FIT_P_HIGH 1.5
#define NDE_ERR_MAX 0.06

enum PRINT_LEVEL_t {VERBOSE,LESS_VERBOSE};
enum CORNER_t {U,V,W};
enum HISTO_TYPE_t {DIAGNOSTIC,EFF_MAP};
enum STACK_t {INNER,OUTER};
enum CUTS_t {NONE,MASS,ENERGY,DIR,ANGLE,WRONGPID,
	     TIMING,BETA,LAYER,BANK,MISSING};
enum vector_type_t {POSITION,DIRECTION};

enum VIEW_t {X,Y};

struct ec_triple_t{
  float u;
  float v;
  float w;
};

struct pixel_triple_t{
  int u;
  int v;
  int w;
};

struct pixel_pair_t{
  int x;
  int y;
};

/* For unknown reason, rootcint is unable to include ntypes.h, so this 
   structure is needed to have vector-like types in Jec_raw_event
 */
struct alt_vector_t{
  float x;
  float y;
  float z;
};




#endif


































