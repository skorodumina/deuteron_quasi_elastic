#ifndef J_SC_GEOM_H_
#define J_SC_GEOM_H_

#include "ec_nde_defines.h"
//#include "ec_nde_includes.h"
#include "nde_overloads.h"

/***
Note that if any new arrays are added to this object, be sure to add code in 
the copy constructor so that the array elements get copied properly
****/

extern "C"{
  int initialize_tof_gc(int runno,int runno2);
}

class Jsc_geom{
 public:
  Jsc_geom(int runno);
  Jsc_geom(const Jsc_geom& old);
  void init_cal(int runno);
  void get_panel_intercept(vector3_t vertex, vector4_t p, 
			   vector3_t& intercept, int& panel);
  int get_paddle_hit(int panel, vector3_t intercept);
  vector3_t bar_center(int sector,int paddle);
  vector3_t bar_direction(int sector, int paddle);
  float get_pred_time(float beta, float path_len, float sc_vtime);
  int get_npaddle(int sector);
  bool_t check_sc_dir(int sector, int paddle, 
		      int& found, int& ind);
  bool_t check_sc_energy(int sector, int index, float& energy);
  bool_t check_sc_time(int sector, int index, float pred_time, float& delt);
  void check_sc(int sector, int paddle, float pred_time, int& paddle_found,
		float& delta_t, float& edep, vector3_t& hit_location,
		EVENT_STATUS_t& sc_type, 
		int& sc_number, CUTS_t& sc_cuts,int& status);
  vector3_t get_sc_norm(int sector, int panel);
  vector3_t get_sc_point(int sector, int panel);
  int count_ngamma(vector3_t vert,TH1F *ht,int nsec,int npaddle);
  void count_npaddle(int paddle, int sector, TH1F *edep_dist, 
		     int &np, int &cp,float &edep);
  int get_sector(vector3_t dir);
  int get_sector(vector4_t p);
  int get_sector(float phi);
  int get_panel(int paddle);
  int get_opposite_sector(int sector);
  float get_paddle_theta(int sector, int paddle);
  void set_cuts(float delta_pad,float tlow,float thigh,float edep);

 private:
  vector3_t norm[NSECTOR+1][N_SC_PANEL+1];
  vector3_t point[NSECTOR+1][N_SC_PANEL+1];
  float paddle_width[N_SC_PADDLE+1];
  float gap_size[NSECTOR+1][N_SC_PADDLE+1];
  int ref_id[N_SC_PANEL+1];
  int max_id[N_SC_PANEL+1];
  
  clasSC_t *SC;
  clasSCG_t *SCG;
  clasSC1_t *SC1;
  clasSCR_t *SCR;
  clasSCRC_t *SCRC;
  clasECPB_t *ECPB;

  //selection cuts
  float delta_paddle_,time_cut_low_,time_cut_high_,edep_;

};

#endif
