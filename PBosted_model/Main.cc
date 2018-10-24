#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "F1F209Wrapper.hh"

static const double kDEG = 3.14159265358979323846 / 180.0;

int main()
{
    const double M = 0.9383;

    double F1n, F2n, F1p, F2p, F1d, F2d, r;
    double F1be, F2be, rbe;
    double F1dqe, F2dqe;
    double Q2, W2, nu, x, fr;
double Epeak[13] = {1.739, 1.694, 1.649, 1.602, 1.556, 1.51, 1.464, 1.418, 1.374, 1.33, 1.287, 1.246, 1.206};

    F1F209Wrapper *model = new F1F209Wrapper();

    for (int i = 1; i <= 2; i++) {
        Q2 = 1.0 * i;
        for (int j = 1; j <= 5; j++) {
            W2 = 1. + 0.5 * j;
            nu = (W2 - M * M + Q2) / 2. / M;
            x = Q2 / 2. / M / nu;
            model->GetF1F2IN09(0., 1., Q2, W2, F1n, F2n, r);
            model->GetF1F2IN09(1., 1., Q2, W2, F1p, F2p, r);
            model->GetF1F2IN09(1., 2., Q2, W2, F1d, F2d, r);
            model->GetF1F2IN09(4., 9., Q2, W2, F1be, F2be, rbe);
         //   printf("%5.3lf %5.3lf %5.3lf %5.3lf %5.3lf %5.3lf %5.3lf %5.3lf %5.3lf %5.3lf\n", Q2, W2, x, F2n, F2p, F2d, F1p, F1be, r, rbe);
        }
    }

  //  for (int i = 1; i <= 3; i++) {
  //      Q2 = 1.0 * i;
   //     W2 = M*M;
  //      model->GetF1F2QE09(1., 2., Q2, W2, F1dqe, F2dqe);
       // printf("%5.3lf %5.3lf %5.3lf\n", Q2, F1dqe, F2dqe);
  //  }
    for (int i = 0; i <30; i++) {
  //   printf("%9.6lf %9.6lf\n",0.8+i/100., model->GetXS(1.,2.,2.039,0.8+i/100.,27.));
//     printf("%9.6lf\n", model->GetXS(1.,2.,2.039,1.3,20));
//   printf("%9.6lf %9.6lf %9.6lf\n",model->GetXSelas(2.039, 20.+i) ,  model->GetRadCorrFact(2.039, 20.+i,0.002683,1.),model->GetXSelas_rad(2.039, 20.+i,0.002683,1.)) ;
//     printf("%9.6lf\n",model->GetXSelas(2.039, 20.+i));

 //      printf("%9.6lf\n",model->GetXSelas_rad(2.039, 20.+i,0.002683,1.71)-model->GetXSelas_rad(2.039, 20.+i,0.002683,1.7));

   };
   for (int i = 1; i <= 40; i++) {
//   fr = 0.95 + 0.002*i;
// fr = 0.8 + 0.008*i;
  fr = 0.8 + 0.01*i;
//   printf("%9.6lf ",fr);
//   model->GetXS(1.,2.,0.449,fr*0.304,90);


  printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,2.039,fr*Epeak[0],23));
//    printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,0.449,fr*0.304,90));
//    printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,0.557,fr*0.350,90));  
//  printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,0.718,fr*0.407,90));  
  
//   printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,0.865,fr*0.450,90)); 
//   printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,1.104,fr*0.507,90)); 
//     printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,1.598,fr*0.664,80)); 


// printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,9.744,fr*0.304,90));

//  printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,9.761,fr*8.43234,180./3.14159*acos(1. - 2.495/2./9.761/(fr*8.43234))));  

//     printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,12.589,fr*10.4647,180./3.14159*acos(1. - 3.989/2./12.589/(fr*10.4647))));  
//     printf("%9.6lf  %9.6lf\n",fr,model->GetXS(1.,2.,15.742,fr*12.549,180./3.14159*acos(1. - 5.996/2./15.742/(fr*12.549)))); 

      };
   
//  printf("%9.6lf",model->GetXS(1.,2.,9.744,fr*8.41434,180./3.14159*acos(1. - 2.495/2./9.744/(fr*8.41434))));  
   
//  model->GetXS(1.,2.,2.039,0.8+1./100.,27.);
//  printf("%9.6lf\n",model->GetXS_Ferm_p(1.2,2.039,36.));
   
   /* printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,21));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,23));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,25));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,29));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,31));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,33));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,35));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,37));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,39));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,41));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,43));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,45));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,47));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.,49));*/
    
    
   //  printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.3,11.8));
   //  printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.35,11.8));
    
   
/*    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.31886,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.40128,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.48371,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.56614,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.64857,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.731,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.81343,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.89586,27));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.97828,27));
   */
   

/*printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.31886,27)); 
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.35183 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.3848  ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.40128 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.41777 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.48371 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.51668 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.54966 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.58263 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.6156  ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.64857 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.68154 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.71451 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.74748 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.78046 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.81343 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.8464  ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.87937 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.91234 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.94531 ,27));
printf("%9.6lf\n",model->GetXS(1.,2.,2.039,1.97828,27));*/



/* printf("%9.6lf\n",model->GetRadCorrFact(2.039, 23,0.002246,0.998059));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 25,0.002246,0.998037)); 
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 27,0.002246,0.998014)); 
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 29,0.002246,0.99799)); 
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 31,0.002246,0.997967));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 33,0.002246,0.997944));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 35,0.002246,0.997922));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 37,0.002246,0.9979));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 39,0.002246,0.997878));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 41,0.002246,0.997857));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 43,0.002246,0.997838));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 45,0.002246,0.997819));
 printf("%9.6lf\n",model->GetRadCorrFact(2.039, 47,0.002246,0.997801));
*/






 /*  printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4025,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4075,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4125,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4175,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4225,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4275,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4325,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4375,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4425,11.4));
    printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4475,11.4));*/
    
    
       
    
    
    
    
     //printf("%9.6lf\n", 00000000);
    
   //  printf("%9.6lf\n",model->GetXS(1.,2.,2.5,2.4025,11.8));
    
    
///   printf("%9.6lf\n",model->GetXSelas(2.039,21.));
 //  printf("%9.6lf\n",model->GetXSelas_rad(2.039,21.,0.002683,1.066));
    
  //  printf("%9.6lf\n",model->GetRadCorrFact(2.039, 23,0.002246181,1.1));
    
      
//    printf("%9.6lf\n",model->GetRadCorrFact(2.039, 22.5,0.002246,1.));
//    printf("%9.6lf\n",model->GetRadCorrFact(2.039, 27.5,0.002246,1.));    
 //   printf("%9.6lf\n",model->GetRadCorrFact(2.039, 32.5,0.002246,1.));  
 ///    printf("%9.6lf\n",model->GetRadCorrFact(2.039, 37.5,0.002246,1.));
 //    printf("%9.6lf\n",model->GetRadCorrFact(2.039, 42.5,0.002246,1.)); 
 //   printf("%9.6lf\n",model->GetRadCorrFact(2.039, 47.5,0.002246,1.));         
           
    
//   printf("%9.6lf\n",model->Get;

}
