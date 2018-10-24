#include "TROOT.h"
#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "TF2.h"
#include "TF3.h"
#include "TMacro.h"
#include "TCanvas.h"
#include "TVirtualFitter.h"
#include "TMath.h"
#include <math.h>
#include "TGraphErrors.h"
#include "TGraph.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TH3F.h"
#include "TText.h"
#include "TStyle.h"
#include "TGObject.h"
#include "TObject.h"
#include "TSystem.h"
#include "TMinuit.h"
#include <TRint.h>
#include <stdio.h>
#include <dlfcn.h>
#include "global.h"
#include <stdio.h>
#include <dlfcn.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring> 
#include <cstdlib>
#include "global.h"


 using namespace std; 


Int_t ti,io,jo,tj;
ostringstream qqq3;
 
int output() {

    outFile->cd();
     outFile->mkdir("sector1");
     outFile->mkdir("sector2");
     outFile->mkdir("sector3");
     outFile->mkdir("sector4");
     outFile->mkdir("sector5");
     outFile->mkdir("sector6");
     
         
   
     
     outFile->mkdir("s1_el_fid_sim");
     outFile->mkdir("s2_el_fid_sim");
     outFile->mkdir("s3_el_fid_sim");
     outFile->mkdir("s4_el_fid_sim");
     outFile->mkdir("s5_el_fid_sim");
     outFile->mkdir("s6_el_fid_sim");
     
     outFile->mkdir("s1_p_fid_sim");
     outFile->mkdir("s2_p_fid_sim");
     outFile->mkdir("s3_p_fid_sim");
     outFile->mkdir("s4_p_fid_sim");
     outFile->mkdir("s5_p_fid_sim");
     outFile->mkdir("s6_p_fid_sim");
     
    
     
    
     
     
     
    outFile->mkdir("th_vs_p");  
    outFile->mkdir("th_vs_p_sim"); 
    
    
     outFile->mkdir("elast_data");
   outFile->mkdir("elast_sim");
   
  outFile->mkdir("delta_data");
   outFile->mkdir("delta_sim");  
    
     outFile->mkdir("w15_data");
     outFile->mkdir("w15_sim");
     
    outFile->mkdir("w17_data");   
   outFile->mkdir("w17_sim"); 
    
   outFile->mkdir("incl_w_data");
   outFile->mkdir("incl_w_sim"); 
   outFile->mkdir("incl_w_sim_gen");   
     
   outFile->mkdir("INCLUSIVE_2018") ;    
      
  TDirectory *dir, *dir1, *dir2,*dir0;  
   
    
  
//photoelectrons

 for(jo=0; jo<6; jo++){
qqq3.str("");    
  qqq3 <<"ph_el_sector_" << jo+1;    
outFile->mkdir(qqq3.str().c_str());  
outFile->cd(qqq3.str().c_str());
dir = outFile->GetDirectory(qqq3.str().c_str());
dir->cd();
dir->mkdir("left");

qqq3.str("");    
  qqq3 <<"ph_el_sector_" << jo+1 << "/left";
 dir1 = outFile->GetDirectory(qqq3.str().c_str());
dir1->cd(); 
for (io=0; io<20; io++){
ph_el_left[jo][io]->SetDirectory(dir1); 
};


dir->mkdir("both");
qqq3.str("");    
  qqq3 <<"ph_el_sector_" << jo+1 << "/both";
 dir1 = outFile->GetDirectory(qqq3.str().c_str());
dir1->cd(); 
for (io=0; io<20; io++){
ph_el_both[jo][io]->SetDirectory(dir1);
}
dir->mkdir("right");
qqq3.str("");    
  qqq3 <<"ph_el_sector_" << jo+1 << "/right";
 dir1 = outFile->GetDirectory(qqq3.str().c_str());
dir1->cd(); 
for (io=0; io<20; io++){
ph_el_right[jo][io]->SetDirectory(dir1);
}


outFile->cd(); 
   
};  


outFile->mkdir("incl_data"); 
outFile->cd("incl_data");
dir0 = outFile->GetDirectory("incl_data");
dir0->cd();

 for(jo=0; jo<110; jo++){
qqq3.str("");    
  qqq3 <<"w_" << 100.*(0.8+jo/100.);    
dir0->mkdir(qqq3.str().c_str());  
//outFile->cd(qqq3.str().c_str());
qqq3.str("");    
  qqq3 <<"incl_data/w_" << 100.*(0.8+jo/100.); 

dir = outFile->GetDirectory(qqq3.str().c_str());
dir->cd();

for (io=0; io<180; io++){
h_th_el_arr_incl[jo][io]->SetDirectory(dir);
};

};

outFile->cd();

outFile->mkdir("incl_sim"); 
outFile->cd("incl_sim");
dir0 = outFile->GetDirectory("incl_sim");
dir0->cd();

 for(jo=0; jo<110; jo++){
qqq3.str("");    
  qqq3 <<"w_" << 100.*(0.8+jo/100.);    
dir0->mkdir(qqq3.str().c_str());  
//outFile->cd(qqq3.str().c_str());
qqq3.str("");    
  qqq3 <<"incl_sim/w_" << 100.*(0.8+jo/100.); 

dir = outFile->GetDirectory(qqq3.str().c_str());
dir->cd();

for (io=0; io<180; io++){
h_th_el_arr_incl_sim[jo][io]->SetDirectory(dir);
};

};

outFile->cd();


outFile->mkdir("incl_sim_gen"); 
outFile->cd("incl_sim_gen");
dir0 = outFile->GetDirectory("incl_sim_gen");
dir0->cd();

 for(jo=0; jo<110; jo++){
qqq3.str("");    
  qqq3 <<"w_" << 100.*(0.8+jo/100.);    
dir0->mkdir(qqq3.str().c_str());  
//outFile->cd(qqq3.str().c_str());
qqq3.str("");    
  qqq3 <<"incl_sim_gen/w_" << 100.*(0.8+jo/100.); 

dir = outFile->GetDirectory(qqq3.str().c_str());
dir->cd();

for (io=0; io<180; io++){
h_th_el_arr_incl_sim_gen[jo][io]->SetDirectory(dir);
};

};

outFile->cd();




      hist_ectot_sector1->Write("", TObject::kOverwrite); 
      hist_ectot_sector2->Write("", TObject::kOverwrite);
      hist_ectot_sector3->Write("", TObject::kOverwrite);
      hist_ectot_sector4->Write("", TObject::kOverwrite);
      hist_ectot_sector5->Write("", TObject::kOverwrite);
      hist_ectot_sector6->Write("", TObject::kOverwrite);
      hist_ectot_sector1_sim->Write("", TObject::kOverwrite); 
      hist_ectot_sector2_sim->Write("", TObject::kOverwrite);
      hist_ectot_sector3_sim->Write("", TObject::kOverwrite);
      hist_ectot_sector4_sim->Write("", TObject::kOverwrite);
      hist_ectot_sector5_sim->Write("", TObject::kOverwrite);
      hist_ectot_sector6_sim->Write("", TObject::kOverwrite);
     
      
      
      hist_ltime->Write("", TObject::kOverwrite); 
      hist_n_incl->Write("", TObject::kOverwrite);
      hist_n_elast->Write("", TObject::kOverwrite); 
      hist_ltime_1d->Write("", TObject::kOverwrite); 
      hist_n_incl_1d->Write("", TObject::kOverwrite);
      hist_n_elast_1d->Write("", TObject::kOverwrite); 
            
     // hist_sector1->Write("", TObject::kOverwrite);
    //  hist_nphe_sector1->Write("", TObject::kOverwrite);
      

      W_incl->Write("", TObject::kOverwrite);
     
    
      

    
 
 



hist_z_el_1->Write("", TObject::kOverwrite); 
hist_z_el_2->Write("", TObject::kOverwrite); 
hist_z_el_3->Write("", TObject::kOverwrite); 
hist_z_el_4->Write("", TObject::kOverwrite); 
hist_z_el_5->Write("", TObject::kOverwrite); 
hist_z_el_6->Write("", TObject::kOverwrite); 

hist_z_el_1_empty->Write("", TObject::kOverwrite); 
hist_z_el_2_empty->Write("", TObject::kOverwrite); 
hist_z_el_3_empty->Write("", TObject::kOverwrite); 
hist_z_el_4_empty->Write("", TObject::kOverwrite); 
hist_z_el_5_empty->Write("", TObject::kOverwrite); 
hist_z_el_6_empty->Write("", TObject::kOverwrite); 


hist_z_el_1_sim_1->Write("", TObject::kOverwrite); 
hist_z_el_2_sim_1->Write("", TObject::kOverwrite); 
hist_z_el_3_sim_1->Write("", TObject::kOverwrite); 
hist_z_el_4_sim_1->Write("", TObject::kOverwrite); 
hist_z_el_5_sim_1->Write("", TObject::kOverwrite); 
hist_z_el_6_sim_1->Write("", TObject::kOverwrite); 


hist_z_el_1_sim_2->Write("", TObject::kOverwrite); 
hist_z_el_2_sim_2->Write("", TObject::kOverwrite); 
hist_z_el_3_sim_2->Write("", TObject::kOverwrite); 
hist_z_el_4_sim_2->Write("", TObject::kOverwrite); 
hist_z_el_5_sim_2->Write("", TObject::kOverwrite); 
hist_z_el_6_sim_2->Write("", TObject::kOverwrite); 









h_cc_nphe_total_s1 -> Write("", TObject::kOverwrite);
h_cc_nphe_total_s2 -> Write("", TObject::kOverwrite);
h_cc_nphe_total_s3 -> Write("", TObject::kOverwrite);
h_cc_nphe_total_s4 -> Write("", TObject::kOverwrite);
h_cc_nphe_total_s5 -> Write("", TObject::kOverwrite);
h_cc_nphe_total_s6 -> Write("", TObject::kOverwrite);


h_cc_nphe_final_s1 -> Write("", TObject::kOverwrite);
h_cc_nphe_final_s2 -> Write("", TObject::kOverwrite);
h_cc_nphe_final_s3 -> Write("", TObject::kOverwrite);
h_cc_nphe_final_s4 -> Write("", TObject::kOverwrite);
h_cc_nphe_final_s5 -> Write("", TObject::kOverwrite);
h_cc_nphe_final_s6 -> Write("", TObject::kOverwrite);


/*norm_nphe_s1 -> Write("", TObject::kOverwrite);
norm_nphe_s2 -> Write("", TObject::kOverwrite);
norm_nphe_s3 -> Write("", TObject::kOverwrite);
norm_nphe_s4 -> Write("", TObject::kOverwrite);
norm_nphe_s5 -> Write("", TObject::kOverwrite);
norm_nphe_s6 -> Write("", TObject::kOverwrite);*/


    //  hist_sector1->Write("", TObject::kOverwrite);
    //  hist_nphe_sector1->Write("", TObject::kOverwrite);
	
     // avrg_nphe_sector1->Write("", TObject::kOverwrite);
      
     // hist_sector2->Write("", TObject::kOverwrite);
     // hist_nphe_sector2->Write("", TObject::kOverwrite);
      
     
     // avrg_nphe_sector2->Write("", TObject::kOverwrite);
            
     // hist_sector3->Write("", TObject::kOverwrite);
     // hist_nphe_sector3->Write("", TObject::kOverwrite); 
      
 

     // avrg_nphe_sector3->Write("", TObject::kOverwrite);     
      
      
    //  hist_sector4->Write("", TObject::kOverwrite);
     // hist_nphe_sector4->Write("", TObject::kOverwrite); 
      
      

     // avrg_nphe_sector4->Write("", TObject::kOverwrite);     
         
        
     // hist_sector5->Write("", TObject::kOverwrite);
     // hist_nphe_sector5->Write("", TObject::kOverwrite); 
      

      //avrg_nphe_sector5->Write("", TObject::kOverwrite);     
      
      
      
      
      //hist_sector6->Write("", TObject::kOverwrite);  
     // hist_nphe_sector6->Write("", TObject::kOverwrite);    
      

     // avrg_nphe_sector6->Write("", TObject::kOverwrite);     
      
        
      nphe_sector1->Write("", TObject::kOverwrite); 
      nphe_sector1_after->Write("", TObject::kOverwrite);  
      nphe_sector2->Write("", TObject::kOverwrite); 
      nphe_sector2_after->Write("", TObject::kOverwrite);        
      nphe_sector3->Write("", TObject::kOverwrite); 
      nphe_sector3_after->Write("", TObject::kOverwrite);  
      nphe_sector4->Write("", TObject::kOverwrite); 
      nphe_sector4_after->Write("", TObject::kOverwrite);   
      nphe_sector5->Write("", TObject::kOverwrite); 
      nphe_sector5_after->Write("", TObject::kOverwrite);  
      nphe_sector6->Write("", TObject::kOverwrite); 
      nphe_sector6_after->Write("", TObject::kOverwrite); 
      
     
      //z_el_1->Write("", TObject::kOverwrite);
      //z_el_2->Write("", TObject::kOverwrite);
      //z_el_3->Write("", TObject::kOverwrite);
      //z_el_4->Write("", TObject::kOverwrite);
      //z_el_5->Write("", TObject::kOverwrite);
      //z_el_6->Write("", TObject::kOverwrite);
     
//th_vs_p_e_1->Write("", TObject::kOverwrite);  
//th_vs_p_e_2->Write("", TObject::kOverwrite); 
//th_vs_p_p_1->Write("", TObject::kOverwrite);  
//th_vs_p_p_2->Write("", TObject::kOverwrite);  
//th_vs_p_pip_1->Write("", TObject::kOverwrite);  
//th_vs_p_pip_2->Write("", TObject::kOverwrite); 
      
    
    
     

      
              
 outFile->cd("sector1");
 for (ti=0; ti<17; ti++){
  ph_vs_th_1pe[ti]->Write("", TObject::kOverwrite); 
  ph_vs_th_1pe_fid[ti]->Write("", TObject::kOverwrite);
  };
 ph_vs_th_1->Write("", TObject::kOverwrite);
 
  outFile->cd("sector2");
  for (ti=0; ti<17; ti++){
  ph_vs_th_2pe[ti]->Write("", TObject::kOverwrite); 
  ph_vs_th_2pe_fid[ti]->Write("", TObject::kOverwrite);
  };
 ph_vs_th_2->Write("", TObject::kOverwrite);
 
  outFile->cd("sector3");
  for (ti=0; ti<17; ti++){
  ph_vs_th_3pe[ti]->Write("", TObject::kOverwrite); 
  ph_vs_th_3pe_fid[ti]->Write("", TObject::kOverwrite);
  };
   ph_vs_th_3->Write("", TObject::kOverwrite);
 
  outFile->cd("sector4");
  for (ti=0; ti<17; ti++){
  ph_vs_th_4pe[ti]->Write("", TObject::kOverwrite); 
  ph_vs_th_4pe_fid[ti]->Write("", TObject::kOverwrite);
  };
 ph_vs_th_4->Write("", TObject::kOverwrite);
 
  outFile->cd("sector5");
  for (ti=0; ti<17; ti++){
  ph_vs_th_5pe[ti]->Write("", TObject::kOverwrite); 
  ph_vs_th_5pe_fid[ti]->Write("", TObject::kOverwrite);
  };
 ph_vs_th_5->Write("", TObject::kOverwrite);
 
  outFile->cd("sector6");
  for (ti=0; ti<17; ti++){
  ph_vs_th_6pe[ti]->Write("", TObject::kOverwrite); 
  ph_vs_th_6pe_fid[ti]->Write("", TObject::kOverwrite);
  };
 ph_vs_th_6->Write("", TObject::kOverwrite);
 

 
 ///////////////
outFile->cd("s1_el_fid_sim");
 for (ti=0; ti<7; ti++){
 ph_vs_th_el_sim[0][ti]->Write("", TObject::kOverwrite); 
 };
 
 outFile->cd("s2_el_fid_sim");
  for (ti=0; ti<7; ti++){
ph_vs_th_el_sim[1][ti]->Write("", TObject::kOverwrite); 
 };

 outFile->cd("s3_el_fid_sim");
  for (ti=0; ti<7; ti++){
 ph_vs_th_el_sim[2][ti]->Write("", TObject::kOverwrite); 
 };
  
 outFile->cd("s4_el_fid_sim"); 
  for (ti=0; ti<7; ti++){
 ph_vs_th_el_sim[3][ti]->Write("", TObject::kOverwrite); 
 };
  
  outFile->cd("s5_el_fid_sim");
   for (ti=0; ti<7; ti++){
ph_vs_th_el_sim[4][ti]->Write("", TObject::kOverwrite); 
 };
  
 outFile->cd("s6_el_fid_sim");
  for (ti=0; ti<7; ti++){
 ph_vs_th_el_sim[5][ti]->Write("", TObject::kOverwrite); 
 };
  

 

  //outFile->cd("y_sc_vs_x_sc");
/*  for (jo=0; jo<6; jo++){
  for (ti=0; ti<57; ti++){
  
outFile->cd("y_sc_vs_x_sc_p");
 y_sc_vs_x_sc_p[jo][ti]->Write("", TObject::kOverwrite); 
outFile->cd("y_sc_vs_x_sc_pim");
 y_sc_vs_x_sc_pim[jo][ti]->Write("", TObject::kOverwrite);  
 outFile->cd("y_sc_vs_x_sc_pip");
 y_sc_vs_x_sc_pip[jo][ti]->Write("", TObject::kOverwrite); 
 outFile->cd("y_sc_vs_x_sc_el");
 y_sc_vs_x_sc_el[jo][ti]->Write("", TObject::kOverwrite); 
 };
  };*/
 
 
///oooo
  outFile->cd("th_vs_p");
  for (ti=0; ti<6; ti++){ 
th_vs_p_e_1[ti]->Write("", TObject::kOverwrite);  
th_vs_p_e_2[ti]->Write("", TObject::kOverwrite); 

 
 
 }; 
 outFile->cd("th_vs_p_sim");
for (ti=0; ti<6; ti++){ 
th_vs_p_e_1_sim[ti]->Write("", TObject::kOverwrite);  
th_vs_p_e_2_sim[ti]->Write("", TObject::kOverwrite); 
 
 };  


   
   
outFile->cd("elast_data");
for (ti=0; ti<180; ti++){ 
h_th_el_arr_elast[ti]->Write("", TObject::kOverwrite);  
 }; 
 
 outFile->cd("elast_sim");
for (ti=0; ti<180; ti++){ 
h_th_el_arr_elast_sim[ti]->Write("", TObject::kOverwrite);
h_th_el_arr_elast_sim_gen[ti]->Write("", TObject::kOverwrite);
 }; 
    
   
 outFile->cd("delta_data");
for (ti=0; ti<180; ti++){ 
h_th_el_arr_delta[ti]->Write("", TObject::kOverwrite);  
 }; 
 
 outFile->cd("delta_sim");
for (ti=0; ti<180; ti++){ 
h_th_el_arr_delta_sim[ti]->Write("", TObject::kOverwrite);
h_th_el_arr_delta_sim_gen[ti]->Write("", TObject::kOverwrite);
 };   
   
   
  outFile->cd("w15_data");
for (ti=0; ti<180; ti++){ 
h_th_el_arr_w15[ti]->Write("", TObject::kOverwrite);  
 }; 
 
 outFile->cd("w15_sim");
for (ti=0; ti<180; ti++){ 
h_th_el_arr_w15_sim[ti]->Write("", TObject::kOverwrite);
h_th_el_arr_w15_sim_gen[ti]->Write("", TObject::kOverwrite);
 };  
   
   
   
   
  outFile->cd("w17_data");
for (ti=0; ti<180; ti++){ 
h_th_el_arr_w17[ti]->Write("", TObject::kOverwrite);  
 }; 
 
 outFile->cd("w17_sim");
for (ti=0; ti<180; ti++){ 
h_th_el_arr_w17_sim[ti]->Write("", TObject::kOverwrite);
h_th_el_arr_w17_sim_gen[ti]->Write("", TObject::kOverwrite);
 };     
   
   
   outFile->cd("incl_w_data"); 
   for (jo=0; jo<30; jo++){ 
    for (ti=0; ti<180; ti++){
   h_w_arr_incl[jo][ti]->Write("", TObject::kOverwrite);
   
    }; 
  }; 
  
    outFile->cd("incl_w_sim"); 
    
    for (jo=0; jo<30; jo++){  
   for (ti=0; ti<180; ti++){ 
     h_w_arr_incl_sim[jo][ti]->Write("", TObject::kOverwrite);
   
   };  
  };  
  
  
  outFile->cd("incl_w_sim_gen"); 
     for (jo=0; jo<30; jo++){  
   for (ti=0; ti<180; ti++){ 
     h_w_arr_incl_sim_gen[jo][ti]->Write("", TObject::kOverwrite); 
  }; 
};


  outFile->cd("INCLUSIVE_2018"); 
     for (jo=0; jo<6; jo++){  
   for (ti=0; ti<13; ti++){ 
    h_w_inclusive[jo][ti]->Write("", TObject::kOverwrite); 
    h_w_inclusive_sim[jo][ti]->Write("", TObject::kOverwrite);    
    h_w_inclusive_sim_gen[jo][ti]->Write("", TObject::kOverwrite);    
    
  }; 
};

   
 
 outFile->cd();
 for (ti=0; ti<6; ti++){
 th_cc_vs_seg[ti]->Write("", TObject::kOverwrite); 
 };
 
outFile->cd();
 for (ti=0; ti<6; ti++){
 th_cc_vs_seg_sim[ti]->Write("", TObject::kOverwrite); 
 };
  


  

 
 
 
 
 
// TMacro *W_dep;
// W_dep = macros.W_plot();
// W_dep->Write("", TObject::kOverwrite);
// macros.W_plot_write();
 
    outFile->Write();
    
      nphe_sector1->Delete();
      nphe_sector1_after->Delete();
      nphe_sector2->Delete();
      nphe_sector2_after->Delete();     
      nphe_sector3->Delete();
      nphe_sector3_after->Delete();
      nphe_sector4->Delete();
      nphe_sector4_after->Delete();      
      nphe_sector5->Delete();
      nphe_sector5_after->Delete();
      nphe_sector6->Delete();
      nphe_sector6_after->Delete();     
};
