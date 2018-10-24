#ifndef J_PDE_SELECTOR_H_
#define J_PDE_SELECTOR_H_

#include "pde_defines.h"
#include "pde_includes.h"
#include "Jec_geom.h"
#include "Jsc_geom.h"
#include "pde_ntuple_def.h"
#include "Jmom_corr2_calc.h"

/**********************
extern "C"{
  #include "runselect.h"
}
**********************/

//prototype for external call 
extern "C"{
void trk_swim2pln_(float pln[8], float vins[9], float vect[9], float tintp[7], 
		   float *sint, float *zangle, float *minstep, float *maxstep, 
		   float *lmax, int *l_int, int *stepnumber);
  void make_dc1_digi_();
  void make_dc1_digi_sector_(int *sector);
  float prob_(float *a,int *b);
  //void ProcessHitBased();
}

class Jpde_selector{
 public:
  Jpde_selector(void);
  void set_max_events(int max);
  void set_momentum_correction(char *momcfile);
  void book_diagnostic_histos(void);
  void select_events(char *file_list,char *output_file);
  void file2output(char *infile);
  int extract_runno(char *infile);
  void get_beam_parameters(int runno);
  void setup_kinematics(void);
  void setup_currents(void);
  pde_EVENT_STATUS_t read_event(void);
  
  bool_t is_proton(clasEVNT_t *EVNT, clasSCPB_t *scpb,clasTRKS_t *TRKS, 
		   int ind_el,int ind_prot);
  bool_t check_vertex(vector3_t vert);
  bool_t check_elastic(vector4_t x);
  float calc_qsq(vector4_t x);
  float calc_w(vector4_t x);
  float calc_elastic_electron(vector4_t x);
  float calc_elastic_proton(float theta_p); //theta in DEG
  float calc_elastic_ep(float theta_p);
  float calc_theta_p(float etheta);
  float calc_theta_ep(float e_mom);
  float calc_qsq_p(float theta_p);
  void get_paddle(vector3_t p_init,vector3_t vert,
		  int &scpaddle,float &pathlen);
  vector3_t lab2bogdan_s1(vector3_t lab_vec);
  vector3_t bogdan_s12lab(vector3_t bvec,int sector);
  vector4_t get_corrected_momentum(vector4_t xvec);

  void reset_bos_pointers(void);
  void reset_common(void);

  //UPITT momentum corrections for e1b/e1c data
  vector4_t PittsMomCorr(vector4_t invec,int charge,float TorusCurrent);
  float DeltaBp(float Bp,float Theta,float Phi,int Sect);
  float BpIntercept(float Theta,float Phi,int Sect);
  float BpSlope(float Theta,float Phi,int Sect);

 private:
  FILE *input_list;
  TFile *file;
  TTree *nt;
  pde_event_t event;
  Jec_geom *ec_geom;
  Jsc_geom *sc_geom;
  Jmom_corr2_calc *mom_corr_calc;
  //  Jrunselect *runselect;

  //bos pointers
  clasHEAD_t *HEAD;
  clasEVNT_t *EVNT;
  clasPART_t *PART;
  clasTRKS_t *TRKS;
  clasSCPB_t *SCPB;
  clasECPB_t *ECPB;

  bool_t maxed_out;
  bool_t do_mom_corr;

  //kinematic quantities
  float beam_energy;
  vector3_t beam3_dir; //beam direction (assumed straight along z)
  vector3_t beam3; //beam 3-momentum
  vector4_t beam4; //beam 4-momentum
  vector4_t nucleon4; //initial nucleon 4-momentum
  vector3_t electron3;
  vector4_t electron4;
  vector3_t e_transverse; //direction perpendicular to scattering plane
  vector3_t dir; //scattered electron direction
  vector3_t temp3;
  vector3_t proton3;
  vector4_t proton4;
  vector4_t expected4;
  vector4_t temp4;

  //variables used in read_event
  part_t *electron_part;
  part_t *proton_part;
  part_t *temp_part;

  //control variables
  int max_events;
  int runno;
  float Itorus,Imini;

  //global variables
  float hdbeta,hdmass1,delta_beta,delta_t;

  //arrays and vars for trk_swim2pln
  float pln[8];      //plane parameters (see sdaswin.inc)
  float vins[9];     //trk vector starting values
  float vect[9];     //trk vector return values
  float tintp[7];    //trk plane crossing
  float lmax;        //max track length before giving up
  int l_int;         // ==1 if trk intercepted plane
  float sint;        //trklength from vect to tintp
  float zangle;      //replaces tcl variable trk_zangle
  float minstep;     //replaces tcl variable trk_zstep(1)
  float maxstep;     //replaces tcl variable trk_zstep(2)
  int stepnumber;  //used to determine if "first" step

  //diagnostic histograms
  TH1F *proton_mass, *proton_mass_passed;
  TH1F *W_dist, *W_dist_passed;
  TH1F *vert_z;
  TH1F *p_minus_e;
  TH1F *ein_dist;
  TH2F *z_vs_p;
  TH2F *z_vs_theta;
  TH1F *delta_beta_dist;
  TH2F *delta_beta_vs_p;
  TH1F *p_dist,*p_dist_b,*p_dist_c;
  TH1F *p_dist_dump,*proton_mom_dump,*proton_theta_dump;
  TH2F *proton_mom_vs_theta_dump;
  TH1F *time_dist[1+NSECTOR][1+N_SC_PADDLE];
};

#endif

  


