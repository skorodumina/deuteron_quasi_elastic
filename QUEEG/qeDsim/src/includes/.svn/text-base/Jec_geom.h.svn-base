#ifndef J_EC_GEOM_H_
#define J_EC_GEOM_H_

#include "ec_nde_defines.h"
#include "ec_nde_includes.h"
#include "nde_overloads.h"

extern "C"{
int cceffn_out(int run_number, int sector_number, float *point,
	       float *dir, float *Nphe,float *Nphe_err, float *cc_eff,
	       float *Theta, float *Phy);
}

class Jec_geom{
 public:
  Jec_geom(void);
  void set_pixel_density(int np);
  vector3_t clas2ec(vector3_t clas,vector_type_t vt);
  vector3_t ec2clas(vector3_t ec,vector_type_t vt,int sector);
  ec_triple_t calc_uvw(vector3_t vertex,vector4_t p);
  ec_triple_t calc_uvw(vector3_t vertex,vector3_t dir);
  vector3_t calc_xyz(vector3_t vertex,vector4_t p);
  vector3_t calc_xyz(vector3_t vertex,vector3_t dir);
  int uvw2pixel(ec_triple_t triple);
  int uvw2pixel(float u,float v,float w);
  int xyz2pixel(float x,float y,float z);
  int xyz2pixel(vector3_t p);
  int ij2pixel(float i,float j);
  pixel_triple_t xyz2strips(float fx,float fy,float fz);
  pixel_triple_t xyz2strips(vector3_t vec);
  pixel_triple_t xyz2strips_physical(float fx,float fy,float fz);
  pixel_triple_t xyz2strips_physical(vector3_t vec);
  void pixel2strips(int pixel,int& u,int& v, int& w);
  pixel_triple_t  pixel2strips(int pixel);
  pixel_triple_t uvw2strips(ec_triple_t ec);
  vector3_t uvw2xy(ec_triple_t ec);
  int strips2pixel(pixel_triple_t pt);
  int strips2pixel(int u,int v,int w);
  bool_t good_pixel(pixel_triple_t);
  bool_t good_pixel(int u,int v,int w);
  bool_t proj_fid(vector3_t vert,vector4_t pmom);
  float distance_to_edge(vector3_t pos,CORNER_t c1, CORNER_t c2);
  int find_electron(clasEVNT_t *EVNT, clasECPB_t *ECPB, float &cc_eff);
  bool_t check_timing(vector3_t vertex,vector4_t p,float rel_time,
		      float& del);
  bool_t check_direction(vector3_t ec_crossing);
  bool_t check_angles(vector3_t recon,vector3_t found, 
		      vector3_t vertex,float& delta_r);
  bool_t check_layer(float ein,float eout,float beta);
  bool_t check_energy(float energy); 
  bool_t check_fiducial(vector3_t point);
  float calc_ctheta(vector4_t p);
  float sample_frac(float p);
  float p2energy(float p);

  int get_sector(vector3_t dir);
  int get_sector(vector4_t p);
  int get_sector(float phi);
  vector3_t vert(CORNER_t corner,int sector);
  vector3_t dir(CORNER_t,int sector);
  vector3_t perp(int sector);
  vector3_t hat(CORNER_t c1, CORNER_t c2,int sector);
  vector3_t delta(int sector);
  vector3_t get_clas_origin(void);
  float get_ylow(void);
  float get_yhigh(void);
  float get_ecwidth(void);
  float get_thickness(void);
  //float edge_length(void);
  float strip_width(void);
  int n_strips(void);
  int n_pixel(void);
  void set_runno(int runno);
  void set_cuts(float delta_r,float tlow,float t_high,float edep);

 private:
  //ec geometry (all in clas coordinates)
  vector3_t u_vert[7],v_vert[7],w_vert[7]; //index by sector number. element 0
                                           //is value in ec coordinates 
                                           //(which is sector independent 
  vector3_t u_dir[7],v_dir[7],w_dir[7]; //unit vectors along u,v,w axis
  vector3_t uv_hat[7],uw_hat[7],vw_hat[7];
  vector3_t ec_perp[7];
  vector3_t clas_origin;
  float fedge_length,fstrip_width;
  float ec_theta,ec_phi,rho,ec_disp,height,alpha;
  float ylow,yhigh;
  float edge_uv,edge_vw,edge_uw;
  float ecwidth;
  float thickness;
  int runno;

  //used to move from clas to ec or ec to clas coordinates
  float rot[4][4]; //rotate from clas to ec (0 components not used)
  float rot_inv[4][4]; //rotate from ec to clas
  vector3_t fdelta[7]; //vector from clas origin to ec origin in sector  
                       //also give location of a point on the ec plane

  //pixel scheme
  int npix,n_macro_strips;
  float macro_strip_width;

  //cut parameters
  float delta_r_, time_cut_low_,time_cut_high_,edep_;

};

#endif
