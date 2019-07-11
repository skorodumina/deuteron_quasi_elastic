void my_data_int(){
gStyle->SetOptStat(0);
gStyle->SetTitleY(0.975);
gStyle->SetTitleSize(0.25);

TCanvas *c2 = new TCanvas("c2","c2",0,0,600,800);
c2 -> Divide (3,4);

Short_t i,j,k;
ostringstream qqq;

TH1F *h_data[6][13];
TH1F *h_sim[6][13];
TH1F *h_sim_gen[6][13];
TH1F *h_quegg[6][13];

TH1F *h_empty[6][13];
  
//TFile *MyFile1 = new TFile("out_data_3Oct.root","READ");    
//TFile *MyFile2 = new TFile("out_qqq.root","READ");

TFile *MyFile1 = new TFile("out_data_5Oct.root","READ");    
//TFile *MyFile2 = new TFile("out_qqq2.root","READ");
TFile *MyFile2 = new TFile("out_qqq4.root","READ");

TFile *MyFile3 = new TFile("out_data_empty_26july18.root","READ");

Float_t Epeak[13] = {1.739, 1.694, 1.649, 1.602, 1.556, 1.51, 1.464, 1.418, 1.374, 1.33, 1.287, 1.246, 1.206};

Float_t A_left[13], B_left[13], C_left[13], Y_left[13];
Float_t A_right[13], B_right[13], C_right[13], Y_right[13];

Short_t Kmax[13], Kmin[13];
Float_t Left_arr[2][13];
Float_t Right_arr[2][13];

Float_t Xsect_left[2][13];
Float_t Xsect_right[2][13];


TH1F *h_data_hist[13];
TH1F *h_empty_hist[13];
TH1F *h_sim_hist[13];
TH1F *h_gen_hist[13];
TH1F *h_eff_hist[13];

Double_t err_data[13];
Double_t err_empty[13];
Double_t err_eff[13][9];

Float_t my_Qelast[13];
Double_t Int_err[13];


Float_t cut;
Float_t Integral[13];
Short_t Kfin[13];
Short_t dim[13];

//Float_t rc[13] = {0.877593, 0.876729, 0.876000, 0.875389, 0.874882, 0.874469, 0.874140, 0.873885, 0.873698, 0.873571, 0.873500, 0.873478, 0.873501};

//Float_t rc_097[13] = {0.847895, 0.846657, 0.845572, 0.844621, 0.843789, 0.843063, 0.842432, 0.841885, 0.841415, 0.841014, 0.840677, 0.840397, 0.840168};

//new
Float_t rc_097[13] = {0.825199, 0.823690, 0.822349, 0.821155, 0.820090, 0.819139,0.842431, 0.841884, 0.841415, 0.841014, 0.840677, 0.840397, 0.840168};


Float_t fermiint[13] ={1.07614, 1.08281, 1.09302, 1.10366, 1.11839, 1.12768, 1.16337, 1.16144, 1.16262,  1.17558, 1.15453, 1.1563, 1.1451};

Float_t param_Qelast[13]={1.865E-1, 1.142E-1, 7.212E-2, 4.694E-2, 3.135E-2, 2.145E-2, 1.502E-2, 1.075E-2, 7.830E-3, 5.818E-3, 4.398E-3, 3.375E-3};

Float_t Left_limit[13]; 
Float_t Right_limit[13];
TLine *line_left[13];
TLine *line_right[13];
TLine *line_left2[13];
TLine *line_right2[13];


TH1F *h1, *h2, *h3, *h4,*h5, *h6;

TH1D *h_cos_th = new TH1D("h_cos_th","h_cos_th",13,22.,48.);  
Double_t temp,theta,Ef,W,Eo,M, nu, eps,Q2;   
Float_t alpha = 1./137;
Eo = 2.039;
M =0.5*(0.938272+ 0.939565); 


for (j=1;j<=13;j++){
Int_err[j-1] = 0.;

temp = cos((h_cos_th->GetBinLowEdge(j))*3.14159/180.)-cos(3.14159/180.*(h_cos_th->GetBinLowEdge(j)+h_cos_th->GetBinWidth(j)));
h_cos_th->SetBinContent(j,temp);
h_cos_th->SetBinError(j,0.);


for (i=0;i<6;i++){
MyFile1->cd();
qqq.str("");
qqq << "INCLUSIVE_2018/h_w_inclusive_"<<i+1<<"_" << j;
gDirectory->GetObject(qqq.str().c_str(),h_data[i][j-1]);
//cout << qqq.str().c_str()<<endl;

qqq.str("");
qqq << "INCLUSIVE_2018/h_w_inclusive_sim_gen_"<<i+1<<"_"  << j;
gDirectory->GetObject(qqq.str().c_str(),h_quegg[i][j-1]);

MyFile2->cd();
qqq.str("");
qqq << "INCLUSIVE_2018/h_w_inclusive_sim_"<<i+1<<"_"  << j;
gDirectory->GetObject(qqq.str().c_str(),h_sim[i][j-1]);

qqq.str("");
qqq << "INCLUSIVE_2018/h_w_inclusive_sim_gen_"<<i+1<<"_"  << j;
gDirectory->GetObject(qqq.str().c_str(),h_sim_gen[i][j-1]);

MyFile3->cd();
qqq.str("");
qqq << "INCLUSIVE_2018/h_w_inclusive_"<<i+1<<"_" << j;
gDirectory->GetObject(qqq.str().c_str(),h_empty[i][j-1]);

};

if ((j==9)||(j==10)){
for (k=1;k<h_data[1][j-1]->GetNbinsX();k++){
h_data[1][j-1]->SetBinContent(k,0.);
h_empty[1][j-1]->SetBinContent(k,0.);
h_sim[1][j-1]->SetBinContent(k,0.);
};
};

if ((j==6)||(j==10)){
for (k=1;k<h_data[4][j-1]->GetNbinsX();k++){
h_data[4][j-1]->SetBinContent(k,0.);
h_empty[4][j-1]->SetBinContent(k,0.);
h_sim[4][j-1]->SetBinContent(k,0.);
};
};

h_data[0][j-1]->Add(h_data[1][j-1]);
h_data[0][j-1]->Add(h_data[2][j-1]);
h_data[0][j-1]->Add(h_data[3][j-1]);
h_data[0][j-1]->Add(h_data[4][j-1]);
h_data[0][j-1]->Add(h_data[5][j-1]);


h_empty[0][j-1]->Add(h_empty[1][j-1]);
h_empty[0][j-1]->Add(h_empty[2][j-1]);
h_empty[0][j-1]->Add(h_empty[3][j-1]);
h_empty[0][j-1]->Add(h_empty[4][j-1]);
h_empty[0][j-1]->Add(h_empty[5][j-1]);

h_sim[0][j-1]->Add(h_sim[1][j-1]);
h_sim[0][j-1]->Add(h_sim[2][j-1]);
h_sim[0][j-1]->Add(h_sim[3][j-1]);
h_sim[0][j-1]->Add(h_sim[4][j-1]);
h_sim[0][j-1]->Add(h_sim[5][j-1]);


//----------------------
h_sim_gen[0][j-1]->Add(h_sim_gen[1][j-1]);
h_sim_gen[0][j-1]->Add(h_sim_gen[2][j-1]);
h_sim_gen[0][j-1]->Add(h_sim_gen[3][j-1]);
h_sim_gen[0][j-1]->Add(h_sim_gen[4][j-1]);
h_sim_gen[0][j-1]->Add(h_sim_gen[5][j-1]);


h_quegg[0][j-1]->Add(h_quegg[1][j-1]);
h_quegg[0][j-1]->Add(h_quegg[2][j-1]);
h_quegg[0][j-1]->Add(h_quegg[3][j-1]);
h_quegg[0][j-1]->Add(h_quegg[4][j-1]);
h_quegg[0][j-1]->Add(h_quegg[5][j-1]);



h_data_hist[j-1] = (TH1F*)h_data[0][j-1]->Clone("h_data_hist");
h_empty_hist[j-1] = (TH1F*)h_empty[0][j-1]->Clone("h_empty_hist");
h_sim_hist[j-1] = (TH1F*)h_sim[0][j-1]->Clone("h_sim_hist");
h_gen_hist[j-1] = (TH1F*)h_sim_gen[0][j-1]->Clone("h_gen_hist");

h_eff_hist[j-1] = (TH1F*)h_sim_hist[j-1]->Clone("h_eff_hist");
h_eff_hist[j-1]->Divide(h_gen_hist[j-1]);

Double_t par[7];

for (k=1;k<=40;k++){

err_eff[j-1][k-1] = sqrt(h_sim_hist[j-1]->GetBinContent(k)*(h_gen_hist[j-1]->GetBinContent(k) -h_sim_hist[j-1]->GetBinContent(k))/h_gen_hist[j-1]->GetBinContent(k)/h_gen_hist[j-1]->GetBinContent(k)/h_gen_hist[j-1]->GetBinContent(k));

h_eff_hist[j-1]->SetBinError(k,err_eff[j-1][k-1] );
h_data_hist[j-1]->SetBinError(k,1./sqrt(h_data_hist[j-1]->GetBinContent(k)) );
h_empty_hist[j-1]->SetBinError(k,1./sqrt(h_empty_hist[j-1]->GetBinContent(k)) );

if ((h_data_hist[j-1]->GetBinError(k)/h_data_hist[j-1]->GetBinContent(k)>0.1)||(h_empty_hist[j-1]->GetBinError(k)/h_empty_hist[j-1]->GetBinContent(k)>0.1)||(h_eff_hist[j-1]->GetBinError(k)/h_eff_hist[j-1]->GetBinContent(k)>0.1)){

h_data_hist[j-1]->SetBinError(k,0.);
h_empty_hist[j-1]->SetBinError(k,0.);
h_eff_hist[j-1]->SetBinError(k,0.);
}

};


h_data_hist[j-1]->Scale(1./3734.69);
h_empty_hist[j-1]->Scale(1./464.797);
h_data_hist[j-1]->Add(h_empty_hist[j-1],-1);


h_data_hist[j-1]->Scale(1.5873e-6);
h_data_hist[j-1]->Scale(1./2./3.14159);
h_data_hist[j-1]->Scale(1./h_data_hist[j-1]->GetBinWidth(1)/Epeak[j-1]);
//h_data_hist[j-1]->Scale(1./abs(Gamma[j-1]));

h_data_hist[j-1]->Divide(h_eff_hist[j-1]);
h_data_hist[j-1]->SetLineWidth(2);
h_data_hist[j-1]->Scale(1./h_cos_th->GetBinContent(j));

TGaxis::SetMaxDigits(3);

c2->cd(j);
c2->cd(j)->SetLeftMargin(0.15);
c2->cd(j)->SetBottomMargin(0.15);
qqq.str("");
qqq << "#theta_{e'} = "<<23+ 2*(j-1) <<" deg";

h_data_hist[j-1]->SetTitle(qqq.str().c_str());
h_data_hist[j-1]->SetTitleSize(0.15);

h_data_hist[j-1]->SetMinimum(0.);
//h_data_hist[j-1]->SetMaximum(1.1*h_bosted[j-1]->GetMaximum());
h_data_hist[j-1]->SetMarkerStyle(20);
h_data_hist[j-1]->SetMarkerSize(0.8);
h_data_hist[j-1]->SetMarkerColor(kBlack);
h_data_hist[j-1]->SetLineColor(kBlack);
//h_data_hist[j-1]->SetLineWidth(2);
h_data_hist[j-1]->GetXaxis()->SetRangeUser(0.85,1.15);
h_data_hist[j-1]->Draw("e1pX0L");

h_data_hist[j-1]->GetXaxis()->SetTitle("E'/E'_{peak}");
h_data_hist[j-1]->GetXaxis()->SetTitleSize(0.07);
h_data_hist[j-1]->GetXaxis()->SetLabelSize(0.06);
h_data_hist[j-1]->GetXaxis()->SetNdivisions(6+400);
h_data_hist[j-1]->GetYaxis()->SetTitle("d^{2}#sigma/(d#Omega dE') (#mub/GeV/sr)");
h_data_hist[j-1]->GetYaxis()->SetTitleSize(0.07);
h_data_hist[j-1]->GetYaxis()->SetLabelSize(0.06);
h_data_hist[j-1]->GetYaxis()->SetNdivisions(6+400);
h_data_hist[j-1]->GetYaxis()->SetTitleOffset(1.15);


TF1 *g1 = new TF1("m1","gaus",h_data_hist[j-1]->GetBinCenter(15),h_data_hist[j-1]->GetBinCenter(40));
TF1 *g11 = new TF1("m11","pol3",h_data_hist[j-1]->GetBinCenter(5),h_data_hist[j-1]->GetBinCenter(40));
TF1 *total = new TF1("mstotal","gaus(0)+pol3(3)",h_data_hist[j-1]->GetBinCenter(5),h_data_hist[j-1]->GetBinCenter(40));
h_data_hist[j-1]->Fit(g1,"NRQ");
h_data_hist[j-1]->Fit(g11,"NRQ");
g1->GetParameters(&par[0]);
g11->GetParameters(&par[3]);
total->SetParameters(par);
h_data_hist[j-1]->Fit(total,"QR+");
//h_data_hist[j-1]->Draw("e1pX0L");

TF1 *g81 = new TF1("m81","gaus",h_data_hist[j-1]->GetBinCenter(5),h_data_hist[j-1]->GetBinCenter(40));
g81->SetParameter(0.,total->GetParameter(0));
g81->SetParameter(1.,total->GetParameter(1));
g81->SetParameter(2.,total->GetParameter(2));
g81->Draw("same");

Left_limit[j-1]  =total->GetParameter(1)-total->GetParameter(2);
Right_limit[j-1] =total->GetParameter(1)+3*total->GetParameter(2);

cout << "mu = "<<total->GetParameter(1) <<", sigma = "<<total->GetParameter(2)<< ", Left =  "<<Left_limit[j-1] << ", Right =  "<< Right_limit[j-1]<<endl;

line_left[j-1] = new TLine(Left_limit[j-1],0.,Left_limit[j-1],1.1*h_data_hist[j-1]->GetMaximum());
line_left[j-1]->SetLineColor(43);
line_left[j-1]->SetLineWidth(2);
line_left[j-1]->Draw("same");


line_right[j-1] = new TLine(Right_limit[j-1],0.,Right_limit[j-1],1.1*h_data_hist[j-1]->GetMaximum());
line_right[j-1]->SetLineColor(43);
line_right[j-1]->SetLineWidth(2);
line_right[j-1]->Draw("same");

k=0;
do {
k++;
}while (h_data_hist[j-1]->GetBinCenter(k) < Left_limit[j-1]);

Left_arr[0][j-1] = h_data_hist[j-1]->GetBinCenter(k-1);
Left_arr[1][j-1] = h_data_hist[j-1]->GetBinCenter(k); 
Xsect_left[0][j-1] = h_data_hist[j-1]->GetBinContent(k-1);
Xsect_left[1][j-1] = h_data_hist[j-1]->GetBinContent(k);
Kmin[j-1] = k;
//cout << j<<" "<<k<<" "<<Left_arr[0][j-1]<<" "<< Left_limit[j-1]<<" "<< Left_arr[1][j-1]<<endl;


k=0;
do {
k++;
}while (h_data_hist[j-1]->GetBinCenter(k) < Right_limit[j-1]);

Right_arr[0][j-1] = h_data_hist[j-1]->GetBinCenter(k-1);
Right_arr[1][j-1] = h_data_hist[j-1]->GetBinCenter(k); 
Xsect_right[0][j-1] =  h_data_hist[j-1]->GetBinContent(k-1);
Xsect_right[1][j-1] =  h_data_hist[j-1]->GetBinContent(k);
Kmax[j-1] = k-1;


//cout <<j<<" "<< k<<" "<<Right_arr[0][j-1]<<" "<< Right_limit[j-1]<<" "<< Right_arr[1][j-1]<<endl;
//cout << endl;

A_left[j-1] = Xsect_left[0][j-1] - Xsect_left[1][j-1];
B_left[j-1] = Left_arr[1][j-1] -  Left_arr[0][j-1];
C_left[j-1] = Left_arr[0][j-1]*Xsect_left[1][j-1] - Left_arr[1][j-1]*Xsect_left[0][j-1];

Y_left[j-1] = -A_left[j-1]/B_left[j-1]*Left_limit[j-1] - C_left[j-1]/B_left[j-1];

//cout <<j<<" LEFT  "<< Xsect_left[0][j-1]<<" "<<Y_left[j-1]<<" "<<Xsect_left[1][j-1]<<" \n";
//
line_left2[j-1] = new TLine(0.5*Left_arr[0][j-1],Y_left[j-1],1.5*Left_arr[0][j-1],Y_left[j-1]);
line_left2[j-1]->SetLineColor(43);
line_left2[j-1]->SetLineWidth(2);
line_left2[j-1]->Draw("same");

A_right[j-1] = Xsect_right[0][j-1] - Xsect_right[1][j-1];
B_right[j-1] = Right_arr[1][j-1] -  Right_arr[0][j-1];
C_right[j-1] = Right_arr[0][j-1]*Xsect_right[1][j-1] - Right_arr[1][j-1]*Xsect_right[0][j-1];

Y_right[j-1] = -A_right[j-1]/B_right[j-1]*Right_limit[j-1] - C_right[j-1]/B_right[j-1];

//cout <<j<<" RIGHT "<< Xsect_right[0][j-1]<<" "<<Y_right[j-1]<<" "<<Xsect_right[1][j-1]<<" \n";
//cout <<endl;

line_right2[j-1] = new TLine(0.5*Right_arr[0][j-1],Y_right[j-1],1.5*Right_arr[0][j-1],Y_right[j-1]);


Integral[j-1]=0.;
Kfin[j-1] = Kmax[j-1] - Kmin[j-1]+1;

if ((Kfin[j-1] % 2) == 0) dim[j-1] = Kfin[j-1]+1;
if (!((Kfin[j-1] % 2) == 0)) dim[j-1] = Kfin[j-1]+2;

//cout <<" "<<Kfin[j-1]<<" "<< dim[j-1]<< endl;

TLegend*leg6 = new TLegend(0.62,0.8,0.99,0.9); 
qqq.str("");
qqq << "E'_{peak} = "<<Epeak[j-1] <<" GeV";


leg6->SetHeader(qqq.str().c_str());
leg6->SetTextSize(.055);
leg6->Draw("same");


};

//for(j=1; j<dim[0]-1; j++){

Float_t h;

for (j=1;j<=13;j++){

Float_t Fin_arr_x1[dim[j-1]];
Float_t Fin_arr_y1[dim[j-1]];

Fin_arr_x1[0] = Left_limit[j-1];
Fin_arr_y1[0] = Y_left[j-1];

Fin_arr_x1[dim[j-1]-1] =Right_limit[j-1];
Fin_arr_y1[dim[j-1]-1] = Y_right[j-1];

for(i=1; i<dim[j-1]-1; i++){
Fin_arr_x1[i] = h_data_hist[j-1]->GetBinCenter(Kmin[j-1]+i-1);
Fin_arr_y1[i] = h_data_hist[j-1]->GetBinContent(Kmin[j-1]+i-1);

};

//for(i=0; i<dim[j-1]; i++){
//cout <<j<<" "<<i+1<<" "<< Fin_arr_x1[i] <<" "<< Fin_arr_y1[i] <<" fin\n";
//};

for( i=2;i<=dim[j-1];i += 2){
h = abs(Fin_arr_x1[i] - Fin_arr_x1[i-2]);
Integral[j-1] += (Fin_arr_y1[i-2] + 4.*Fin_arr_y1[i-1] + Fin_arr_y1[i])*h; 
};
Integral[j-1] /= 6.0;

cout <<" Int " << Integral[j-1]<<" \n";

};


};
