#ifndef J_NDE_PARS_H_
#define J_NDE_PARS_H_

#include "ec_nde_defines.h"
#include <TObject.h>

/* here are (some of) the include files from "ec_nde_includes.h". For unknown 
reason, if "ntypes.h" is included, rootcint will not generate raweventDict, 
complaining about "long long" and cannot open long.dl. None of this is 
understood. As a consequence, the vector3_t and vector4_t structures cannot be used.
*/

//other necessary headers (CLAS packages and standard library)
extern "C" {
  #include <stdlib.h>
  #include <stdio.h>
}

#include <iostream>
#include <fstream>
#include <unistd.h>

struct nde_pars_t{
  Double_t p0;
  Double_t p1;
  Double_t p2;
  Double_t p3;
  Double_t p4;
  Double_t tran;
  Double_t scale;
};

class Jnde_pars : public TObject {
 public:
  Jnde_pars();
  //~Jnde_pars();
  void assign_pars(int pixel, nde_pars_t pars);
  nde_pars_t get_pars(void);

  int findex;
  Double_t fpar0;
  Double_t fpar1;
  Double_t fpar2;
  Double_t fpar3;
  Double_t fpar4;
  Double_t fpartran;
  Double_t fscale;

  /* Note the following line does NOT end in a semi-colon
     If the semi-colon is included, ROOT will go apeshit
  */

  ClassDef(Jnde_pars,1)
};

#endif  
