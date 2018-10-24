#include "pde_includes.h"
#include "queeg.h"
#include <TRandom3.h>
#include <TSystem.h>

	   

 //----
void PrintUsage(void){
   cout << "Usage:" << endl
	<< "\t-h\t Print this message" << endl
	<< "\t-o\t Name of output text file" << endl
	<< "\t-E\t Beam energy in GeV (4.2 is default)" << endl
	<< "\t-I\t Torus Current (3375A is default), can be +/-" << endl
	<< "\t-N\t Number of events to generate" << endl
	<< "\t-F\t Neutron fraction of events (0 to 1, default is 0.5)" << endl
     //<< "\t-R\t torus current is a negative number" << endl 
	<< "\t-H\t helicity sign is a negative number" << endl 
	<< "\t-V\t ALTp: 0 - no effect, 1 - normal torus polarity, 2 - reversed." << endl 
        << "\t-L\t Output in the LUND format " << endl
        << "\t-B\t Target Center in cm " << endl 
        << "\t-S\t Target Length in cm " << endl
        << "\t-r\t Target Radius in cm" << endl 
        << "\t-D\t Minimum electron scattering angle queeg will output" << endl
        << "\t-U\t Maximum electron scattering angle queeg will output" << endl
        << "\t-T\t Minimum value of fermi momentum (or p_m) to be accepted" << endl
	<< endl;
}

int main(int argc, char **argv){

  // define variables and set defaults.
  char *argptr;
  char* beam_vz_end;
  char* torus_current_end;
  int counter=0,nevents=100, ALTpVersion=0;
  float ebeam=4.2,nfrac=0.5,Itorus=3375.0, pfermi_threshold=0.0;
  vector3_t expected3,real3,electron3;
  vector3_t vert;
  vert.x = vert.y = vert.z = 0.0;
  HADRON_TYPE_t htype;
  float qsq,theta_pq,phi_pq,wsq;
  float helicity_sign = 1.0, minimum_angle = 0, maximum_angle = 180;
  float beam_vz=0.0, spread_vr=0.0, targetRadius=0.0; 
  bool lund_format = false; 
  int flag = 0;

  // set default name of output file.
  char outfile[256];
  sprintf(outfile,"queeg.out");
  

  cout << "\n" << endl;
  cout << "/----------------------- queeg: QUasi-Elastic Event Generator"
       << " -----------------------/" << "\n" << endl;
  cout << "queeg built on: " << __DATE__ << " " << __TIME__ << endl << endl;

  // read arguments and set parameters.
  while (counter<argc) {
     argptr = argv[counter];
     //cout << "argv(" << counter << ") = " << argv[counter] << endl;
     if (*argptr == '-'){
       argptr++;
       switch(*argptr){
       case 'h':               // print usage.
	 PrintUsage();
	 exit(0);
	 break;
       case 'o':               // output filename
	 ++argptr;
	 sprintf(outfile,++argptr);
	 cout << "Will write text to the file " << outfile << endl;
	 counter++;
	 break;
       case 'E':               // beam energy
	 ++argptr;
	 ebeam = atof(++argptr);
	 cout << "Setting beam energy to " << ebeam << " GeV" << endl;
	 counter++;
	 break;
       case 'I':               // torus current - used to select limits on thrown events.
	 Itorus = strtof(argv[counter+1], &torus_current_end);
	 cout << "Using torus current " << Itorus << endl;
	 counter++;
	 counter++;
	 break;
       case 'N':               // number of events.
	 ++argptr;
	 nevents = atoi(++argptr);
	 cout << "Number of events to be generated is " << nevents << endl;
	 counter++;
	 break;
       case 'F':               // fraction of neutrons
	 ++argptr;
	 nfrac = atof(++argptr);
	 cout << "Percentage of neutron events is " << 100*nfrac << endl;
	 counter++;
	 break;
      case 'H':               // set beam helicity to negative.
	 ++argptr;
	 helicity_sign = -1.0;
	 cout << "Setting beam helicity negative" << endl;
	 counter++;
	 break;
      case 'V':               // select version of ALTp, fifth structure function.
	 ++argptr;
	 ALTpVersion = atoi(++argptr);
	 cout << "Using ALTp version " << ALTpVersion << "." << endl;
	 counter++;
	 break;
      case 'T':               // threshold on pmiss/pfermi
	 ++argptr;
	 pfermi_threshold = atof(++argptr);
	 cout << "Setting pfermi threshold to " << pfermi_threshold << " GeV/c." << endl;
	 counter++;
	 break;
      case 'L':               // use LUND output format.
	 lund_format = true;
	 cout << "Producing output in LUND format" << endl;
	 counter++;
	 break;
      case 'B':               // center of target.
	 beam_vz = strtof(argv[counter+1], &beam_vz_end);
	 cout << "The target position is " << argv[counter+1] << " cm" <<endl; 
	 counter++;
	 counter++;
	 break;
      case 'S':               // width of target.
	 argptr++; 
	 spread_vr = atof(++argptr);
	 cout<< "The target full-width is " << spread_vr << " cm" <<endl; 
	 counter++;
	 break; 
      case 'r':               // target radius
	 ++argptr;
	 targetRadius = atof(++argptr);
	 cout << "Target radius is " << targetRadius << " cm" << endl; 
	 counter++;
	 break; 
      case 'D':               // minimum electron scattering angle in final sample.
         ++argptr;
         minimum_angle = atof(++argptr);
         cout << "Setting the minimum scattering angle to = " << minimum_angle << " degrees" << endl;
	 counter++;
         break;
      case 'U':               // upper limit on electron scattering angle in final sample.
         ++argptr;
         maximum_angle = atof(++argptr);
         cout << "Setting the maximum scattering angle to = " << maximum_angle << " degrees" << endl;
	 counter++;
         break;
      default:
	 cout << "I don't understand you...Try again" << endl;
	 exit(0);
	 break;
       } // end of case
     } else {
       counter++;
     } // end of if test on dash
  } // end of while loop
  //  cout << "counter = " << counter << " argc = " << argc << endl;


  // sim parameters, output file, etc.
   if(Itorus > 3000){
     flag = -1;
   } else if (Itorus > 0 && Itorus < 3000){
     flag = -2;
   } else{
     flag = -3;
   }

   // output file.
   gsim_out = fopen(outfile,"w");   

  
   //bos output 
char mess[256];
initbos();
bankList( &bcs_, "E=", "HEADPARTMCTKMCVXMCEV" );
sprintf( mess, "OPEN BOSOUTPUT UNIT=1 FILE=\"%s\" WRITE STATUS=NEW RECL=3600", "out_bos_file.bos");
     fparm_c( mess );   
   
   
   Jqe_ana_calc calc_obj(ebeam,Itorus,(FF_PARAM_t)BRASH);
   TRandom3 jrand;

   /////////////////////////////////                        /////////////////////////////////
   ///////////////////////////////// loop over events here. /////////////////////////////////
   /////////////////////////////////                        /////////////////////////////////
   cout << "Loop over events." << endl;

   while(counter<nevents){

     // select neutron or proton event.
     if(jrand.Rndm() > nfrac){
       htype = (HADRON_TYPE_t)PROTON;
     } else {
       htype = (HADRON_TYPE_t)NEUTRON;
     }

     // simulate qe event from CLAS12 origin here. put cut on electron angle in here.
     calc_obj.generate_qe_event(htype,expected3,real3,electron3, 
     				 qsq,theta_pq,phi_pq,wsq, helicity_sign,
     				 pfermi_threshold, ALTpVersion);

     // distribute the events in the target region.
     vert = spread_vertex(beam_vz, spread_vr, targetRadius);

     // write out results.
     if (lund_format == false) {
       event_write(htype,electron3,real3,expected3,vert, nevents, minimum_angle, maximum_angle);
       event_write_bos(counter,htype, electron3, real3, expected3, vert);
     }
     else {
       event_write_lund(htype, electron3, real3, expected3, vert, nevents, ebeam, minimum_angle, maximum_angle);
        event_write_bos(counter,htype, electron3, real3, expected3, vert);
     }

     // next event
     counter++;
   } // end of loop over events.

   // finish up.
    calc_obj.close_histos();
    close_fpack_unit("BOSOUTPUT");
   cout << endl << "Finishing up." << endl;
  // gSystem->Exit(0);
   //return 0;


}


vector3_t spread_vertex(float vZ, float vR, float targetRadius)
{
  // randomly distribute the vertex in the z-component, vZ, and in a circular region of radius 
  // targetRadius (where this is the region of the target illuminated by the beam) in the x-y
  // plane. Von Neumann rejection is used to get a uniform distribution of vertices in this circle.
  float tgtLength=vR; 
  float tgtCenter=vZ;
  float tgtRadius=targetRadius; 
  float vr=0;
  vector3_t vert;

  // z-component.
  jrand = new TRandom3(0);
  vert.z = ((jrand->Rndm()) * tgtLength) - (tgtLength/2) + tgtCenter;
 
  // x-y components are uniformly distributed in a circle of radius vR.
  do 
    {
      vert.x = ((jrand->Rndm())*2*tgtRadius)- tgtRadius;
      vert.y = ((jrand->Rndm())*2*tgtRadius)- tgtRadius;
      vr = sqrt(pow(vert.x,2)+ pow(vert.y,2));
       
    } while(vr > tgtRadius);

  return vert;
}
  

void event_write_lund(HADRON_TYPE_t htype,vector3_t electron, vector3_t real,
		      vector3_t expected,vector3_t vert, int nevents, double energy,
		      float minimum_angle, float maximum_angle){

  // write out simulated event data in LUND format.
  float E,Ereal,Eexp;
  float theta, EPrime, qSquared, bjorkenX, targetPolarization, beamPolarization, wSquared;
  float nu, y; 
  int pid; 

  targetPolarization = 0.0;
  beamPolarization = 0.0;
  E= energy;                           //beam energy
  EPrime = v3mag(electron);            //EPrime, E = p^2*c^2 Z
  Ereal = sqrt(M_nucleon*M_nucleon + v3mag(real)*v3mag(real) );
  Eexp = sqrt(M_nucleon*M_nucleon + v3mag(expected)*v3mag(expected) );
  theta = acos(( electron.z / ( sqrt (pow(electron.x,2)+pow(electron.y,2)+pow(electron.z,2))))); 
  nu = E-EPrime;  //pronounced new 
  y = nu/E;
  qSquared = 4 * E * EPrime * pow( sin(theta/2),2); 
  bjorkenX = qSquared/(2*M_nucleon* v3mag(real));
  wSquared = pow(M_nucleon,2) + 2*M_nucleon*nu - qSquared;
  

  if(htype == NEUTRON){
    pid = 13;
  } else if(htype == PROTON){
    pid = 14;
  } else {
    pid = 0;
    return; 
  }

  //  write out the events that pass the angle cut define by -D and -U limits.

  //cout << "theta = " << theta  << " theta = " << theta*57.296 <<  " " << jDEG2RAD  << " " << jDEG2RAD*minimum_angle  << " " << jDEG2RAD*maximum_angle  << endl;
  
  if (theta >= jDEG2RAD*minimum_angle && theta <= jDEG2RAD*maximum_angle)
    {
      fprintf(gsim_out,"           %d  %d.  %d.  %.3f  %.3f  %.3f ", 2,1,1,targetPolarization,beamPolarization,bjorkenX);
      fprintf(gsim_out,"%.3f  %.3f %.3f  %.3f \n",y,wSquared,qSquared, nu);

      fprintf(gsim_out,"    %-4.d%-9d%-9d%-9d%-9d%-9d",1,-1,1,11,0,0);
      fprintf(gsim_out,"%-9.4f%-9.4f%-9.4f",electron.x,electron.y,electron.z);
      fprintf(gsim_out,"%-9.4f%-9.4f%-9.4f%-9.4f%-9.4f\n" , EPrime,M_nucleon, vert.x, vert.y, vert.z);

      fprintf(gsim_out,"    %-4d%-9d%-9d%-9d%-9d%-9d",2,1,1,2112,0,0);
      fprintf(gsim_out,"%-9.4f%-9.4f%-9.4f",real.x,real.y,real.z);
      fprintf(gsim_out,"%-9.4f%-9.4f%-9.4f%-9.4f%-9.4f\n",EPrime, M_nucleon, vert.x,vert.y,vert.z);
    } // end of test on final electron angle.
  


}

void event_write(HADRON_TYPE_t htype,vector3_t electron,
		 vector3_t real,vector3_t expected,vector3_t vert, int nevents,
		 float minimum_angle, float maximum_angle){
  // write out data in original, Jeff Lachniet format.
  float E,Ereal,Eexp,theta;
  int pid;
  E = v3mag(electron);
  Ereal = sqrt(M_nucleon*M_nucleon + v3mag(real)*v3mag(real) );
  Eexp = sqrt(M_nucleon*M_nucleon + v3mag(expected)*v3mag(expected) );
  theta = acos(( electron.z / ( sqrt (pow(electron.x,2)+pow(electron.y,2)+pow(electron.z,2))))); 
  
  if(htype == NEUTRON){
    pid = 13;
  } else if(htype == PROTON){
    pid = 14;
  } else {
    pid = 0;
    return; 
  } 
  
  //  write out the events that pass the angle cut define by -D and -U limits.
  if (theta >= jDEG2RAD*minimum_angle && theta <= jDEG2RAD*maximum_angle)
    {  
      fprintf(gsim_out,"2 \n");
      fprintf(gsim_out,"3 %f %f %f %f\n",E,electron.x,electron.y,electron.z);
      fprintf(gsim_out,"%f %f %f\n",vert.x,vert.y,vert.z);
      fprintf(gsim_out,"%d %f %f %f %f\n",pid,Ereal,real.x,real.y,real.z);
      fprintf(gsim_out,"%f %f %f\n",vert.x,vert.y,vert.z);
    } // end of test on final electron angle.

}


void event_write_bos(Int_t i,HADRON_TYPE_t htype,vector3_t electron, vector3_t real,
		      vector3_t expected,vector3_t vert){
// cout << "eee \n";
 float EPrime;
 EPrime = v3mag(electron);

//Create HEAD-bank anyway       
clasHEAD_t* HEAD ;
if ( ( HEAD = (clasHEAD_t*)makeBank( &bcs_, "HEAD", 0, sizeof(head_t)/4, 4 ) ) )
    {
      HEAD->head[0].version = 1; 
      HEAD->head[0].nevent = i ;
      HEAD->head[0].nrun = 1;
      HEAD->head[0].evtclass = 7 ;
      HEAD->head[0].type = -2 ;
      HEAD->head[0].time = 0;
      HEAD->head[0].trigbits = 1 ;
    }
    
clasMCEV_t* MCEV ;
if ( ( MCEV = (clasMCEV_t*)makeBank( &bcs_, "MCEV", 0, sizeof(mcev_t)/4, 1 ) ) )
    {
      MCEV->mcev[0].i1 = 100000*((float) rand() / (RAND_MAX)); 
      MCEV->mcev[0].i2 =100000*((float) rand() / (RAND_MAX)) ;
    
    } 
    
//-----------------------------------------------------------------------    
//Create MCTK & MCVX banks if needed  
    
clasMCTK_t* MCTK ;
if ( ( MCTK = (clasMCTK_t*)makeBank( &bcs_, "MCTK", 0, sizeof(mctk_t)/4, 2 ) ) )
    {
    
    //electron
      MCTK->mctk[0].cx = electron.x/EPrime; 
      MCTK->mctk[0].cy = electron.y/EPrime; 
      MCTK->mctk[0].cz = electron.z/EPrime; 
      MCTK->mctk[0].pmom = EPrime;
      MCTK->mctk[0].mass = 0.001;
      MCTK->mctk[0].charge = -1.;
      MCTK->mctk[0].id = 11;
      MCTK->mctk[0].flag = 0;
      MCTK->mctk[0].beg_vtx = 1;
      MCTK->mctk[0].end_vtx = 0;
      MCTK->mctk[0].parent = 0;
      
     
       
     //proton
     
      MCTK->mctk[1].cx = real.x/EPrime; 
      MCTK->mctk[1].cy = real.y/EPrime; 
      MCTK->mctk[1].cz = real.z/EPrime; 
      MCTK->mctk[1].pmom = EPrime;
      MCTK->mctk[1].mass = 0.938272;
      MCTK->mctk[1].charge = 1.;
      MCTK->mctk[1].id = 2212;
      MCTK->mctk[1].flag = 0;
      MCTK->mctk[1].beg_vtx = 1;
      MCTK->mctk[1].end_vtx = 0;
      MCTK->mctk[1].parent = 0;
      
      
      
    } //end MCTK bank creation 

clasMCVX_t* MCVX ;
if ( ( MCVX = (clasMCVX_t*)makeBank( &bcs_, "MCVX", 0, sizeof(mcvx_t)/4, 1 ) ) )
    {
      MCVX->mcvx[0].x = vert.x; 
      MCVX->mcvx[0].y = vert.y;
      MCVX->mcvx[0].z = vert.z;
      MCVX->mcvx[0].tof = 0.;
      MCVX->mcvx[0].flag = 0;
    }    //end MCVX bank creation   

//-------------------------------------------------


putBOS( &bcs_, 1, "E" );
dropAllBanks( &bcs_, "E");
cleanBanks( &bcs_ );
}


