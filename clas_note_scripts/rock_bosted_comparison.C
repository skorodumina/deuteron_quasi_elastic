void rock_bosted_comparison(){
gStyle->SetOptStat(0);
gStyle->SetTitleY(0.98);
gStyle->SetTitleSize(0.08);

TCanvas *c = new TCanvas("c","c",0,0,700,300);
c->Divide(2,1);

Short_t j,k;
ostringstream qqq;

Float_t h, Integral1, Integral2,w;
Short_t nl, nr;
Float_t Xsec_Kocevar[2] = {0.0543097,0.0058387};


Float_t E_beam[6] = {9.761, 12.589,15.742,17.307,18.482,21.005};
Float_t Q2[6] = {2.495,3.989,5.996,7.109,7.988,10.004};
Float_t Ef_peak[6] = {8.43234, 10.4647, 12.549, 13.521,14.228,15.678};



//Float_t Left_limit[2]= {0.989922,0.986528};
//Float_t Right_limit[2]= {1.02722,1.03047};

//Float_t Left_limit[2]= {0.989855,0.985503};
//Float_t Right_limit[2]= {1.02743,1.03172};
//Float_t Integral_data[2] = {0.999497,0.148232};

//Positions of the integration limits as well as the integral values themselves come from the script Integrate_data.C
Float_t Left_limit[2]= {0.994249,0.99399};
Float_t Right_limit[2]= {1.02053,1.01807};
Float_t Integral_data[2] = {0.816735,0.0994188};

//test
//Float_t Left_limit[2]= {0.990964,0.99098};
//Float_t Right_limit[2]= {1.02053,1.01807};
//Float_t Integral_data[2] = {0.937077,0.114732};



//data S. Rock, et al, Phys. Rev., vol. D46, pp. 24-44, 1992. // SLAC-PUB-5239,1991.

Float_t Ef_1[41];
Float_t Xsec_1[41];
Float_t Xerr_1[41];


Float_t Ef_1_tmp[41] = {8.846,8.800,8.754,8.696,8.673,8.662,8.650,8.639,8.627,8.616,8.604,8.593,8.581,8.570,8.559,8.547,8.536,8.524,8.513,8.5,8.489,8.477,8.466,8.454,8.443,8.431,8.420,8.408,8.397,8.385,8.374,8.362,8.351,8.339,8.328,8.305,8.247,8.201,8.155,8.098,8.052};
Float_t Xsec_1_tmp[41] = {0.291,0.564,1.01,1.68,2.35,2.43,3.13,3.48,4.51,4.88,5.9,6.94,9.01,9.69,12.2,15.3,17.6,21.7,25.3,29.7,35.5,40.5,45.2,49.,51.1,54.1,52.1,48.2,44.6,40.7,38.7,33.8,31.8,28.4,27.4,25.8,27.8,35.9,43.8,48.6,50.1};

Float_t Xerr_1_tmp[41] = {0.05,0.068,0.1,0.11,0.13,0.15,0.16,0.21,0.20,0.21,0.24,0.27,0.32,0.37,0.4,0.4,0.6,0.7,0.8,0.7,1.0,0.8,0.8,1.,0.9,1.2,0.9,0.9,0.8,0.8,0.8,0.7,0.8,0.6,0.7,0.6,0.9,0.9,1.2,1.5,1.7};

Float_t Ef_2[42];
Float_t Xsec_2[42];
Float_t Xerr_2[42];

Float_t Ef_2_tmp[42] = {10.904,10.846,10.802,10.788,10.773,10.758,10.744,10.729,10.715,10.7,10.685,10.671,10.656,10.642,10.627,10.613,10.597,10.582,10.568,10.553,10.539,10.524,10.509,10.495,10.480,10.466,10.451,10.436,10.422,10.407,10.393,10.378,10.364,10.349,10.334,10.320,10.305,10.247,10.203,10.145,10.101,10.057};
Float_t Xsec_2_tmp[42] = {0.136,0.150,0.258,0.360,0.292,0.370,0.457,0.506,0.572,0.69,0.776,0.931,1.2,1.32,1.69,1.92,2.25,2.50,2.93,3.37,3.97,4.59,5.11,5.75,5.96,6.23,6.02,6.31,6.06,5.56,4.99,5.,4.60,4.69,4.59,4.56,4.54,5.6,6.78,8.08,8.55,10.};
Float_t Xerr_2_tmp[42] = {0.044,0.033,0.036,0.038,0.034,0.036,0.053,0.052,0.045,0.057,0.064,0.058,0.07,0.09,0.09,0.09,0.1,0.11,0.11,0.12,0.18,0.14,0.19,0.15,0.19,0.17,0.24,0.17,0.19,0.15,0.16,0.15,0.15,0.16,0.16,0.17,0.16,0.18,0.18,0.22,0.24,0.3};

Float_t Ef_3[36];
Float_t Xsec_3[36];
Float_t Xerr_3[36];

Float_t Ef_3_tmp[36] = {12.99,12.896,12.821,12.765,12.709,12.653,12.597,12.653,12.691,12.747,12.803,12.859,12.803,12.747,12.691,12.653,12.635,12.616,12.597,12.579,12.560,12.541,12.523,12.504,12.485,12.467,12.448,12.429,12.411,12.392,12.373,12.336,12.299,12.242,12.205,12.149};
Float_t Xsec_3_tmp[36] = {0.0384,0.0801,0.146,0.213,0.34,0.518,0.720,0.518,0.379,0.242,0.149,0.0953,0.149,0.242,0.379,0.518,0.599,0.647,0.72,0.798,0.856,0.907,0.954,0.888,0.925,0.891,0.922,0.872,0.92,0.946,1.,1.12,1.26,1.45,1.62,1.95};
Float_t Xerr_3_tmp[36] = {0.0059,0.0063,0.008,0.009,0.012,0.013,0.015,0.013,0.011,0.01,0.008,0.007,0.008,0.01,0.011,0.013,0.014,0.015,0.015,0.019,0.017,0.018,0.021,0.018,0.02,0.022,0.018,0.02,0.019,0.02,0.02,0.02,0.03,0.03,0.03,0.04};


for (j=0; j<41; j++){
Ef_1[j] = Ef_1_tmp[40-j];
Xsec_1[j] = Xsec_1_tmp[40-j];
Xerr_1[j] = Xerr_1_tmp[40-j];
//cout <<Ef_1[j] <<" "<<Xsec_1[j]<<" \n";
};

for (j=0; j<42; j++){
Ef_2[j] = Ef_2_tmp[41-j];
Xsec_2[j] = Xsec_2_tmp[41-j];
Xerr_2[j] = Xerr_2_tmp[41-j];
};

for (j=0; j<36; j++){
Ef_3[j] = Ef_3_tmp[35-j];
Xsec_3[j] = Xsec_3_tmp[35-j];
Xerr_3[j] = Xerr_3_tmp[35-j];
};

Float_t Xsec_bosted[3][50] = {{0.044004,0.043766,0.043530,0.043009,0.042300,0.041211,0.039733,0.037923,0.035538,0.033187,0.030756,0.028802,0.026995,0.025578,0.024889,0.025266,0.025937,0.028352,0.031769,0.035354,0.041699,0.047485,0.052999,0.057320,0.058540,0.056457,0.051624,0.044957,0.037813,0.031366,0.025051,0.019915,0.015838,0.012645,0.010153,0.008636,0.006404,0.005151,0.004181,0.003419,0.002768,0.002179,0.001766,0.001474,0.001265,0.001032,0.000878,0.000746,0.000626,0.000547},
//!
{0.009022,0.008720,0.008423,0.008155,0.007949,0.007819,0.007705,0.007603,0.007396,0.007094,0.006683,0.006287,0.005868,0.005508,0.005261,0.005034,0.004929,0.004904,0.005017,0.005238,0.005639,0.006007,0.006340,0.006688,0.006666,0.006492,0.006084,0.005432,0.004752,0.003968,0.003343,0.002820,0.002302,0.001874,0.001528,0.001268,0.001055,0.000881,0.000722,0.000635,0.000496,0.000415,0.000351,0.000293,0.000255,0.000216,0.000177,0.000143,0.000122,0.000105},
{0.002196,0.002103,0.002024,0.001950,0.001881,0.001802,0.001715,0.001635,0.001554,0.001466,0.001381,0.001312,0.001243,0.001190,0.001141,0.001103,0.001043,0.001000,0.000976,0.000956,0.000953,0.000952,0.000952,0.000951,0.000924,0.000889,0.000831,0.000759,0.000670,0.000590,0.000515,0.000434,0.000377,0.000318,0.000273,0.000231,0.000195,0.000164,0.000141,0.000121,0.000101,0.000089,0.000076,0.000048,0.000039,0.000033,0.000029,0.000026,0.000022}};

Float_t Xsec_bosted2[3][50] = {{0.046574,0.046490,0.046411,0.046131,0.045645,0.044747,0.043533,0.041840,0.039763,0.037567,0.035313,0.033348,0.031532,0.030113,0.029205,0.028827,0.028998,0.029783,0.031122,0.032998,0.035341,0.038009,0.040771,0.043253,0.044919,0.045115,0.043249,0.039149,0.033300,0.026699,0.020376,0.014992,0.010766,0.007619,0.005351,0.003746,0.002621,0.001836,0.001288,0.000905,0.000638,0.000450,0.000319,0.000226,0.000161,0.000115,0.000082,0.000059,0.000042,0.000030},
{0.009346,0.009061,0.008785,0.008537,0.008359,0.008243,0.008162,0.008060,0.007875,0.007574,0.007178,0.006769,0.006348,0.005952,0.005672,0.005373,0.005129,0.004946,0.004848,0.004817,0.004852,0.004943,0.005061,0.005175,0.005236,0.005196,0.005004,0.004635,0.004107,0.003477,0.002823,0.002215,0.001694,0.001274,0.000948,0.000703,0.000521,0.000387,0.000289,0.000217,0.000164,0.000124,0.000095,0.000073,0.000056,0.000044,0.000034,0.000016,0.000012,0.000009},
{0.002239,0.002150,0.002072,0.002000,0.001933,0.001856,0.001771,0.001692,0.001611,0.001523,0.001439,0.001364,0.001296,0.001232,0.001174,0.001124,0.001049,0.000987,0.000932,0.000887,0.000849,0.000820,0.000798,0.000779,0.000759,0.000734,0.000700,0.000653,0.000594,0.000525,0.000451,0.000377,0.000309,0.000249,0.000199,0.000157,0.000124,0.000098,0.000077,0.000061,0.000049,0.000039,0.000032,0.000013,0.000010,0.000008,0.000006,0.000004,0.000003,0.000003}};


//0.046125,0.046013,0.045907,0.045600,0.045087,0.044163,0.042928,0.041218,0.039133,0.036941,0.034711,0.032795,0.031065,0.029780,0.029073,0.028985,0.029562,0.030900,0.032977,0.035810,0.039355,0.043459,0.047800,0.051748,0.054265,0.054005,0.049906,0.042195,0.032651,0.023483,0.016054,0.010655,0.006971,0.004540,0.002960,0.001938,0.001275,0.000843,0.000560,0.000373,0.000249,0.000166,0.000111,0.000074,0.000050,0.000033,0.000022,0.000015,0.000010,0.000007



//0.001253,0.001520,0.001765,0.002072,0.002548,0.003066,0.003626,0.004535,0.005688,0.006947,0.008802,0.011265,0.014428,0.018436,0.024127,0.030425,0.038775,0.047267,0.053983,0.057004,0.054961,0.048448,0.039040,0.030938,0.023431,0.018191,0.013753,0.010008,0.007591,0.005669,0.004387,0.003380,0.002646,0.002008,0.001596,0.001281,0.000956,0.000788,0.000643,0.000551



TH1F *h_bosted[6];
TH1F *h_bosted2[6];



for(j=0; j<6; j++){
qqq.str("");
qqq << "bosted_" <<j+1;
h_bosted[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),50, 0.951,1.051);

qqq.str("");
qqq << "bosted2_" <<j+1;
h_bosted2[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),50, 0.951,1.051);
};

for(j=0; j<6; j++){
for(k=1; k<=50; k++){

h_bosted[j]->SetBinContent(k, 0.);
if (j<=2) h_bosted[j]->SetBinContent(k, Xsec_bosted[j][k-1]);

h_bosted2[j]->SetBinContent(k, 0.);
if (j<=2) h_bosted2[j]->SetBinContent(k, Xsec_bosted2[j][k-1]);
};
};

for(j=0; j<41; j++){
Ef_1[j] = Ef_1[j]/Ef_peak[0];
};
for(j=0; j<42; j++){
Ef_2[j] = Ef_2[j]/Ef_peak[1];
};
for(j=0; j<36; j++){
Ef_3[j] = Ef_3[j]/Ef_peak[2];
};


TGraphErrors * gr_1 = new TGraphErrors(41, Ef_1,Xsec_1, 0, Xerr_1);
TGraphErrors * gr_2 = new TGraphErrors(42, Ef_2,Xsec_2, 0, Xerr_2);
TGraphErrors * gr_3 = new TGraphErrors(36, Ef_3,Xsec_3, 0, Xerr_3);


c->cd(1);
c->cd(1)->SetLeftMargin(0.12);
c->cd(1)->SetBottomMargin(0.15);
qqq.str("");
qqq << "E_{beam} = 9.761 GeV,   #theta_{e'} = 10^{o}";
h_bosted[0]->SetTitle(qqq.str().c_str());
h_bosted[0]->Scale(1000.);
h_bosted[0]->SetLineWidth(2);
h_bosted[0]->SetLineColor(kBlue);
h_bosted[0]->GetXaxis()->SetTitle("E'/E'_{peak}");
h_bosted[0]->GetXaxis()->SetTitleSize(0.06);
h_bosted[0]->GetXaxis()->SetLabelSize(0.05);
h_bosted[0]->GetXaxis()->SetNdivisions(6+400);
h_bosted[0]->GetYaxis()->SetTitle("d^{2}#sigma/(d#Omega dE') (nb/GeV/sr)");
h_bosted[0]->GetYaxis()->SetTitleSize(0.055);
h_bosted[0]->GetYaxis()->SetLabelSize(0.05);
h_bosted[0]->Draw("hist");

h_bosted2[0]->Scale(1000.);
h_bosted2[0]->SetLineWidth(2);
h_bosted2[0]->SetLineColor(kGreen+2);
h_bosted2[0]->Draw("same hist");

gr_1->SetMarkerStyle(20);
gr_1->Draw("same p");

TLine *line_3 = new TLine(Ef_peak[0],0.,Ef_peak[0],h_bosted[0]->GetMaximum());
line_3->SetLineColor(kRed);
line_3->SetLineStyle(2);
line_3->SetLineWidth(2);
//line_3->Draw("same");

TLine *line_31 = new TLine(0.951,1000*Xsec_Kocevar[0],1.051,1000*Xsec_Kocevar[0]);
line_31->SetLineColor(kRed);
line_31->SetLineStyle(2);
line_31->SetLineWidth(2);
line_31->Draw("same");

TLine *line_32 = new TLine(0.951,1000*0.0371362,1.051,1000*0.0371362);
line_32->SetLineColor(kRed);
line_32->SetLineStyle(2);
line_32->SetLineWidth(2);
//line_32->Draw("same");


TLine *line_3111 = new TLine(Left_limit[0],0.,Left_limit[0],h_bosted[0]->GetMaximum());
line_3111->SetLineColor(43);
//line_3111->SetLineStyle(2);
line_3111->SetLineWidth(2);
line_3111->Draw("same");


TLine *line_312 = new TLine(Right_limit[0],0.,Right_limit[0],h_bosted[0]->GetMaximum());
line_312->SetLineColor(43);
//line_312->SetLineStyle(2);
line_312->SetLineWidth(2);
line_312->Draw("same");

Integral1 = 0.;
Integral2 = 0.;

h_bosted[0]->GetXaxis()->SetRangeUser(0.985,1.2);
h_bosted2[0]->GetXaxis()->SetRangeUser(0.985,1.2);
h_bosted[0]->Scale(1000*Xsec_Kocevar[0]/h_bosted[0]->GetMaximum());
h_bosted2[0]->Scale(1000*Xsec_Kocevar[0]/h_bosted2[0]->GetMaximum());

nl = h_bosted[0]->GetXaxis()->FindBin(Left_limit[0]);
nr = h_bosted[0]->GetXaxis()->FindBin(Right_limit[0]);
w = h_bosted[0]->GetBinWidth(1);

Integral1 = w*h_bosted[0]->Integral(nl+1,nr-1)+ h_bosted[0]->GetBinContent(nl)*(h_bosted[0]->GetBinLowEdge(nl)+w -Left_limit[0]) + h_bosted[0]->GetBinContent(nr)*(Right_limit[0] - h_bosted[0]->GetBinLowEdge(nr));

Integral2 = w*h_bosted2[0]->Integral(nl+1,nr-1)+ h_bosted2[0]->GetBinContent(nl)*(h_bosted2[0]->GetBinLowEdge(nl)+w -Left_limit[0] ) + h_bosted2[0]->GetBinContent(nr)*(Right_limit[0] - h_bosted2[0]->GetBinLowEdge(nr));

//cout << "test left  "<<Left_limit[0]<<" "<<h_bosted[0]->GetBinLowEdge(nl) <<" "<< h_bosted[0]->GetBinLowEdge(nl)+w -Left_limit[0] <<" bb\n";
//cout << "test right "<<Right_limit[0]<<" "<<h_bosted[0]->GetBinLowEdge(nr) <<" "<< Right_limit[0] - h_bosted[0]->GetBinLowEdge(nr) <<" bb\n";

cout << Integral_data[0]/Integral1 << " ";
cout << Integral_data[0]/Integral2 << endl;

TLegend*leg = new TLegend(0.7,0.75,0.99,0.9);
leg->SetHeader("#splitline{Q^{2}    = 2.495 GeV^{2} }{E'_{peak} = 8.432 GeV }");
//leg->SetHeader("Q^{2} = 2.495 GeV^{2}");
//leg->AddEntry("Histogram filled with random numbers","0");
leg->SetTextSize(.045);
leg->Draw();

//=============================================================

c->cd(2);
c->cd(2)->SetLeftMargin(0.12);
c->cd(2)->SetBottomMargin(0.15);

qqq.str("");
qqq << "E_{beam} = 12.589 GeV,   #theta_{e'} = 10^{o}";
h_bosted[1]->SetTitle(qqq.str().c_str());
h_bosted[1]->Scale(1000.);
h_bosted[1]->SetLineWidth(2);
h_bosted[1]->SetLineColor(kBlue);
h_bosted[1]->GetXaxis()->SetTitle("E'/E'_{peak}");
h_bosted[1]->GetXaxis()->SetTitleSize(0.06);
h_bosted[1]->GetXaxis()->SetLabelSize(0.05);
h_bosted[1]->GetXaxis()->SetNdivisions(6+400);
h_bosted[1]->GetYaxis()->SetTitle("d^{2}#sigma/(d#Omega dE') (nb/GeV/sr)");
h_bosted[1]->GetYaxis()->SetTitleSize(0.055);
h_bosted[1]->GetYaxis()->SetLabelSize(0.05);
h_bosted[1]->Draw("hist");

h_bosted2[1]->Scale(1000.);
h_bosted2[1]->SetLineWidth(2);
h_bosted2[1]->SetLineColor(kGreen+2);
h_bosted2[1]->Draw("same hist");

gr_2->SetMarkerStyle(20);
gr_2->Draw("same p");

TLine *line_41 = new TLine(0.951,1000*Xsec_Kocevar[1],1.051,1000*Xsec_Kocevar[1]);
line_41->SetLineColor(kRed);
line_41->SetLineStyle(2);
line_41->SetLineWidth(2);
line_41->Draw("same");

TLine *line_42 = new TLine(0.951,1000*0.00317725,1.051,1000*0.00317725);
line_42->SetLineColor(kRed);
line_42->SetLineStyle(2);
line_42->SetLineWidth(2);
//line_42->Draw("same");


TLine *line_412 = new TLine(Right_limit[1],0.,Right_limit[1],h_bosted[1]->GetMaximum());
line_412->SetLineColor(43);
//line_412->SetLineStyle(2);
line_412->SetLineWidth(2);
line_412->Draw("same");

TLine *line_4121 = new TLine(Left_limit[1],0.,Left_limit[1],h_bosted[1]->GetMaximum());
line_4121->SetLineColor(43);
//line_4121->SetLineStyle(2);
line_4121->SetLineWidth(2);
line_4121->Draw("same");


TLine *line_4111 = new TLine(Ef_2[11],0.,Ef_2[11],h_bosted[1]->GetMaximum());
line_4111->SetLineColor(43);
//line_411->SetLineStyle(2);
line_4111->SetLineWidth(2);
//line_4111->Draw("same");


Integral1 = 0;
Integral2 = 0;


h_bosted[1]->GetXaxis()->SetRangeUser(0.985,1.2);
h_bosted2[1]->GetXaxis()->SetRangeUser(0.985,1.2);
h_bosted[1]->Scale(1000*Xsec_Kocevar[1]/h_bosted[1]->GetMaximum());
h_bosted2[1]->Scale(1000*Xsec_Kocevar[1]/h_bosted2[1]->GetMaximum());


nl = h_bosted[1]->GetXaxis()->FindBin(Left_limit[1]);
nr = h_bosted[1]->GetXaxis()->FindBin(Right_limit[1]);
w = h_bosted[1]->GetBinWidth(1);

Integral1 = w*h_bosted[1]->Integral(nl+1,nr-1)+ h_bosted[1]->GetBinContent(nl)*(h_bosted[1]->GetBinLowEdge(nl)+w -Left_limit[1]) + h_bosted[1]->GetBinContent(nr)*(Right_limit[1] - h_bosted[1]->GetBinLowEdge(nr));

Integral2 = w*h_bosted2[1]->Integral(nl+1,nr-1)+ h_bosted2[1]->GetBinContent(nl)*(h_bosted2[1]->GetBinLowEdge(nl)+w -Left_limit[1] ) + h_bosted2[1]->GetBinContent(nr)*(Right_limit[1] - h_bosted2[1]->GetBinLowEdge(nr));

cout << "test left  "<<Left_limit[1]<<" "<<h_bosted[1]->GetBinLowEdge(nl) <<" "<< h_bosted[1]->GetBinLowEdge(nl)+w -Left_limit[1] <<" bb\n";
cout << "test right "<<Right_limit[1]<<" "<<h_bosted[1]->GetBinLowEdge(nr) <<" "<< Right_limit[1] - h_bosted[1]->GetBinLowEdge(nr) <<" bb\n";

cout << Integral_data[1]/Integral1 << " ";
cout << Integral_data[1]/Integral2 << endl;

TLegend*leg2 = new TLegend(0.7,0.75,0.99,0.9);
leg2->SetHeader("#splitline{Q^{2}    = 3.989  GeV^{2} }{E'_{peak} = 10.465 GeV }");
leg2->SetTextSize(.045);
leg2->Draw();

//==================================

/*c->cd(3);
c->cd(3)->SetLeftMargin(0.14);
c->cd(3)->SetBottomMargin(0.12);

qqq.str("");
qqq << "E_{beam} = 15.742 GeV";
h_bosted[2]->SetTitle(qqq.str().c_str());

h_bosted[2]->Scale(1000.);
//h_bosted[2]->Scale(0.95);
h_bosted[2]->SetLineWidth(2);
h_bosted[2]->SetLineColor(kBlue);

h_bosted[2]->GetXaxis()->SetTitle("E (GeV)");
h_bosted[2]->GetXaxis()->SetTitleSize(0.06);
h_bosted[2]->GetXaxis()->SetLabelSize(0.05);
h_bosted[2]->GetYaxis()->SetTitle("d^{2}#sigma/(d#Omega dE') (nb/GeV/sr)");
h_bosted[2]->GetYaxis()->SetTitleSize(0.055);
h_bosted[2]->GetYaxis()->SetLabelSize(0.05);

h_bosted[2]->Draw("hist");

h_bosted2[2]->Scale(1000.);
h_bosted2[2]->SetLineWidth(2);
h_bosted2[2]->SetLineColor(kGreen+2);
h_bosted2[2]->Draw("same hist");

gr_3->SetMarkerStyle(20);
gr_3->Draw("same p");


TLine *line_5 = new TLine(Ef_peak[2],0.,Ef_peak[2],h_bosted[2]->GetMaximum());
line_5->SetLineColor(kRed);
line_5->SetLineStyle(2);
line_5->SetLineWidth(2);
//line_5->Draw("same");

TLine *line_51 = new TLine(0.951*Ef_peak[2],1000.*0.000683942,1.051*Ef_peak[2],1000.*0.000683942);
line_51->SetLineColor(kRed);
line_51->SetLineStyle(2);
line_51->SetLineWidth(2);
line_51->Draw("same");


TLegend*leg3 = new TLegend(0.6,0.775,0.9,0.9);
//leg->SetHeader("#splitline{Q^{2} = 2.495 GeV^{2} }{E'_{peak} = 8.432 GeV }");
leg3->SetHeader("Q^{2} = 5.996 GeV^{2}");
leg3->SetTextSize(.04);
leg3->Draw();*/


};
