#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h> 
#include <math.h>

class mom_corr {
    private:
        public:
Double_t correct_thel_e1_2039_2250_feb09(double pe,double theta,double phi);
Double_t correct_pel_e1_2039_2250_feb09(double pe,double theta,double phi);
Double_t correct_energy_theta_pf(double pf,double theta);
Double_t corr_pr_mom_skor(double pf,double theta);
Double_t corr_el_mom_sim(double pf,double theta);

};
