#ifndef OVERLOADS_H_
#define OVERLOADS_H_

#include "ec_nde_defines.h"
#include "ec_nde_includes.h"

//we need to overload some operators so they will work on our defined 
//enum types
//prototypes...see overloads.cpp for implementation
ostream& operator<< (ostream& out,EVENT_STATUS_t& es);
ostream& operator<< (ostream& out,PRINT_LEVEL_t& pl);
ostream& operator<< (ostream& out,HISTO_TYPE_t& ht);
ostream& operator<< (ostream& out,CUTS_t& cut);
ostream& operator<< (ostream& out,vector3_t& vec);
ostream& operator<< (ostream& out,ec_triple_t& ect);
ostream& operator<< (ostream& out,pixel_triple_t& pt);
ostream& operator<< (ostream& out,pixel_pair_t& pp);
#endif
