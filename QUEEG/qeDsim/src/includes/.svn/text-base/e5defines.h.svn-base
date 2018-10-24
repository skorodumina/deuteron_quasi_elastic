#ifndef E5_DEFINES_H_
#define E5_DEFINES_H_

using namespace std;

/***************************
 **** Defined Constants ****
 ***************************/

//physical and mathematical constants
#define PI 3.1415927

#define jRAD2DEG 180.0/3.14159
#define jDEG2RAD 3.14159/180.0
#define c_speed 30.00   //speed of light in cm/ns
                        //note that attempting to define a constant "c"
                        //will cause ROOT to go apeshit

//particle identification numbers
#define PROTON 2212
#define NEUTRON 2112
#define PIPLUS 211
#define PIZERO 111
#define PIMINUS -211
#define ELECTRON 11
#define PHOTON 22
#define HIGGS 25

#define GEANT_PROTON 14
#define GEANT_NEUTRON 13
#define GEANT_PIPLUS 8
#define GEANT_PIZERO 7
#define GEANT_PIMINUS 9
#define GEANT_PHOTON 1
#define GEANT_ELECTRON 3

//particle masses in GeV/c^2
#define M_proton 0.93827
#define M_neutron 0.93957
#define M_pi 0.13957
#define M_deuteron 1.8761
#define M_electron 0.000511
#define M_pizero 0.13498
#define M_nucleon 0.93892 //average nucleon mass

//vertex cuts for H2 target in cm
#define Z_MIN -3.0 
#define Z_MAX 3.0
#define TARGET_RADIUS 10.0 //this is way to big, and will effectively eliminate
                           //this cut until I can look up the right number

//geometry
#define NSECTOR 6

// A defined logical type.
typedef int bool_t;
#define true_ 1
#define false_ 0

//enumeration types
enum EVENT_STATUS_t {READ_ENTRY,RECONSTRUCTED,FOUND,FILE_END};
enum DETECTOR_t {NO_DETECTOR,EC,LAC,SC};

//some defines needed by pitt momentum corrections for e1b/e1c
#define DEG2RAD (M_PI/180.0)
#define MAX_TORUS_CURRENT 3860.0
#define NUM_SECT 6

#endif




