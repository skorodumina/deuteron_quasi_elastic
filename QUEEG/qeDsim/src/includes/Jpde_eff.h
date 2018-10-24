#ifndef J_PDE_EFF_H_
#define J_PDE_EFF_H_

#include "pde_defines.h"
#include "pde_includes.h"
#include "Jpde_selector.h"
#include "Jsc_geom.h"
#include "Jec_geom.h"

class Jpde_eff{
 public:
  Jpde_eff(int runno,int flag);
  Jpde_eff(int runno, Jsc_geom *geom_ptr,int flag);
  void init(int runno,int flag);
  float get_eff(int sector,int paddle,float p);
  float get_error(int sector,int paddle,float p);
  float swim2eff(vector3_t vert,vector3_t pmom);
  int swim2paddle(vector3_t vert,vector3_t pmom);
  void load_histos(char *histofile);
  int get_sector(vector3_t vec);
  vector3_t lab2bogdan_s1(vector3_t lab_vec);
  vector3_t bogdan_s12lab(vector3_t bvec, int sector);
  float count_hbtr(vector3_t pvec,vector3_t vert, vector3_t &rglk_vec,
		   vector3_t &hbtr_vec,int &nhbtr);
  vector3_t swim_electron_to_ec(vector3_t vert, vector3_t pmom);
  void count_wires(float ntheta, int sector, int &nwire1, 
			  int &nwire2, int &nwire3, int mode);
			  
			  
 
 private:
  TFile *infile;
  char input_file[256];
  
  Jsc_geom *sc_geom;
  Jec_geom *ec_geom;

  TH1F *av_eff_vs_paddle[NSECTOR+1];
  TH1F *eff_vs_paddle[NSECTOR+1][N_SC_PADDLE+1];
  
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
};

#endif
