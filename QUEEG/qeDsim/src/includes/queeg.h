#ifndef QUEEG_H_
#define QUEEG_H_


//header files for ROOT classes
#include <TROOT.h>
#include <TF1.h>
#include <TEnv.h>
#include <TMinuit.h>
#include <TMath.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TAxis.h>
#include <TGraph.h>
#include <TNtuple.h>

//other necessary headers (CLAS packages and standard library)
extern "C" {
#include <signal.h>
#include <errno.h>
#include <ntypes.h>
#include <bostypes.h>
#include <clas_cern.h>
#include <ctype.h>
#include <kinematics.h>
#include <map_manager.h>
#include <trk.h>
#include <clasmdl.h>
#include <utility.h>
#include <pid.h>
#include <makebanks.h>
#include <call.h>
#include <bosddl.h>
#include <tagtnorm.h>
#include <vertex.h> 
  



extern void initbos();
extern int  getBOS(BOSbank *bcs, int lun, char *list);
extern void cleanBanks(BOSbank *bcs);
extern void dropAllBanks(BOSbank *bcs, char *list);
extern void *getBank(BOSbank *,const char *);
extern void open_fpack_unit(char *filename,char *dataname,int unitnum);
extern void close_fpack_unit(char *dataname);  
extern BOSbank bcs_ ;
extern BOSbank wcs_ ;        
}
  using namespace std; 
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>



#include "qe_ana_defines.h"
#include "qe_ana_includes.h"
#include "Jqe_ana_calc.h"
#include "Jec_geom.h"
#include "Jec_nde_eff.h"
#include "Jsc_geom.h"
#include "Jsc_nde_eff.h"
#include "Jpde_eff.h"
#include "Jqe_ana_calc.h"
#include <TRandom3.h>
#include "pde_includes.h"

		   


void PrintUsage(void);
void event_write(HADRON_TYPE_t htype,vector3_t electron,
		 vector3_t real,vector3_t expected, vector3_t vert, int nevents,
		 float minimum_angle, float maximum_angle);
void event_write_lund(HADRON_TYPE_t htype,vector3_t electron,
		 vector3_t real,vector3_t expected, vector3_t vert, 
		      int nevents, double energy, float minimum_angle, float maximum_angle);
		      
void event_write_bos(Int_t i,HADRON_TYPE_t htype,vector3_t electron, vector3_t real,vector3_t expected, vector3_t vert);		      
vector3_t spread_vertex(float vZ, float vR, float targetRadius);

//global objs
FILE *gsim_out;
Jec_nde_eff *ec_eff;
Jsc_nde_eff *sc_eff;
Jpde_eff *pde_eff;
Jec_geom *ec_geom;
Jsc_geom *sc_geom;
Jqe_ana_calc *calc_obj;
TRandom3 *jrand;

#endif
