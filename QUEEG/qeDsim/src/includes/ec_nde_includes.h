#ifndef EC_NDE_INCLUDES_H_
#define EC_NDE_INCLUDES_H_

//headers needed by lots of different people

//global e5 defines
#include "e5defines.h"

//header files for ROOT classes
#include <TROOT.h>
#include <TF1.h>
#include <TEnv.h>
#include <TMinuit.h>
#include <TMath.h>
#include <TH1.h>
#include <TH2.h>
#include <TH1F.h>
#include <TProfile.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TAxis.h>
#include <TGraph.h>
#include <TChain.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TSpline.h>
#include <TVirtualFitter.h>
#include <TString.h>

//other necessary headers (CLAS packages and standard library)
extern "C" {
  #include <stdlib.h>
  #include <stdio.h>
  #include <ntypes.h>
  #include <bostypes.h>
  #include <clas_cern.h>
  #include <ctype.h>
  #include <kinematics.h>
  #include <map_manager.h>
  #include <utility.h>
  #include <printBOS.h>
  #include <unistd.h>
}

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

#endif








