void Integrate_data(){
gStyle->SetOptStat(0);
gStyle->SetTitleY(0.975);
gStyle->SetTitleSize(0.08);

TCanvas *c = new TCanvas("c","c",0,0,1000,600);
c->Divide(3,3);

Short_t j,k;
ostringstream qqq;

Float_t h, Integral[8],w;
Short_t nl, nr, NL, NR;
Float_t E_beam[6] = {0.449,0.557,0.718,0.865,1.104,1.598};
Float_t Q2[6] = {0.273,0.389,0.584,0.779,1.120,1.752};
Float_t Ef_peak[8] = {0.304,0.350,0.407,0.450,0.507,0.664,8.43234, 10.4647,};


Float_t Right_limit[8];
Float_t Left_limit[8];

for (j=0; j<8; j++){
Right_limit[j] = 0.;
Left_limit[j] = 0.;
Integral[j] = 0.;
};


Float_t Xsec_Durand[6] = {0.713111, 0.31405, 0.107971, 0.045611, 0.0131869, 0.0026376};
//Float_t Xsec_Durand[6] = {0.742107,0.332662,0.117926,0.0514028,0.0157113,0.00348409};
Float_t Xsec_Kocevar[6] = {0.727656,0.339405,0.122581,0.0536327,0.016373,0.00358437};

//0.7488310708898944,0.770412442042344,0.7884151025082398,0.8058722278085023,0.8260570289369309,0.8435141542371936,0.8587891388749233,0.8751551938439194,0.8838837564940506,0.9051596279537456,0.9291631752416066,0.9498935115356685,0.9706238478297303,0.9908086489581588,1.0104479149209542,1.0295416457181163,1.0508175171778114,1.068274642478074,1.0857317677783365,1.103188893078599,1.1179183425506956,1.140285284341657,1.1631977612982516,1.1888379140830123,1.2095682503770742,1.2275709108429695,1.2515744581308308,1.270668188927993,1.2864887087313561


//3.8410639706503957,8.501245009912338,8.749022400983165,6.656399918104626,12.700605473024211,15.732916779820982,19.54208456604829,19.676181790920737,21.359454850504278,27.070937967770192,36.239961749652366,52.646202675404055,62.3677473537532,68.18912970042598,58.18930807422112,43.39803128335285,29.055425658411252,20.50093013637712,13.394785467946747,10.299458547957954,6.531881066437336,4.891710686277179,1.9153572439948334,2.173721258081855,1.8682215653272465,0.8904713110408693,0.9237435548062081,1.0616217164701993,1.083551149861023



Float_t Ef_1[29] = {0.7488310708898944,0.770412442042344,0.7884151025082398,0.8058722278085023,0.8260570289369309,0.8435141542371936,0.8587891388749233,0.8751551938439194,0.8838837564940506,0.9051596279537456,0.9291631752416066,0.9498935115356685,0.9706238478297303,0.9908086489581588,1.0104479149209542,1.0295416457181163,1.0508175171778114,1.068274642478074,1.0857317677783365,1.103188893078599,1.1179183425506956,1.140285284341657,1.1631977612982516,1.1888379140830123,1.2095682503770742,1.2275709108429695,1.2515744581308308,1.270668188927993,1.2864887087313561};

Float_t Xsec_1[29] = {3.8410639706503957,8.501245009912338,8.749022400983165,6.656399918104626,12.700605473024211,15.732916779820982,19.54208456604829,19.676181790920737,21.359454850504278,27.070937967770192,36.239961749652366,52.646202675404055,62.3677473537532,68.18912970042598,58.18930807422112,43.39803128335285,29.055425658411252,20.50093013637712,13.394785467946747,10.299458547957954,6.531881066437336,4.891710686277179,1.9153572439948334,2.173721258081855,1.8682215653272465,0.8904713110408693,0.9237435548062081,1.0616217164701993,1.083551149861023};

//0.7500812299539814, 0.7717381931855158, 0.7899306814484267, 0.8075595570120394, 0.8268560289127506, 0.8444238948542744, 0.8590487728350302, 0.8754806977176594, 0.8842617254683217, 0.905908520429508,0.9286854460093898, 0.9496161042160557, 0.9694514944452194, 0.9905085297262123, 1.009408439083345,  1.0289533073025614, 1.0496660740017665, 1.0673733905080651, 1.085067633523916,  1.1021227281178823, 1.1174245223818158, 1.139159926556036,  1.162080660530842,  1.1879022567749735
//3.917766776677638,8.61042354235417,8.61042354235417,6.685231023102233,12.460808580858043,15.589246424642454,19.43963146314627,19.43963146314627,21.244499449944954,26.779427942794257,35.92409240924093,52.16790429042902,61.9141914191419,67.68976897689771,57.702832783278325,42.9029152915291,28.58429592959294,20.161578657865732,12.821782178217802,9.813668866886644,6.203932893289277,4.399064906490651,1.631600660065999,1.6316006600659,1.3909515951594926,0.5486798679867775,0.42835533553352434,0.42835533553352434,0.42835533553352434


//-------------
Float_t Ef_2[29] = {0.7347517730496455,0.7546099290780142, 0.773758865248227,  0.7914893617021277, 0.8092198581560284, 0.8276595744680851, 0.8439716312056739, 0.8602836879432624, 0.8666666666666668, 0.8907801418439716, 0.9113475177304966, 0.932033096926714,  0.9515366430260048, 0.9716312056737589, 0.991725768321513,  1.0100472813238772, 1.0307328605200947, 1.0472813238770686, 1.064420803782506,  1.0803782505910167, 1.0981087470449173, 1.1170212765957448, 1.1394799054373523, 1.1631205673758866, 1.1855791962174942, 1.2092198581560285, 1.2251773049645391, 1.2446808510638299, 1.2618203309692673};


Float_t Xsec_2[29] = {4.535085924713599,4.097620021822195,4.3093630660120255,6.25221631205676,5.454684942716881,5.306021549372645,5.951138843426122,9.120294599018024,7.315875613747977,9.47354064375341,12.02869271685762,18.454008683397007,23.07672417712311,27.458912984178937,31.180044098927084,27.6299668121477,19.632205855610152,15.301304782687822,9.648146253864383,6.278925713766171,4.712163575195518,3.2052134478996663,1.7575070467358103,0.9705741953082736,0.9050793326059647,0.9594926350245885,1.135945171849471,0.3500068194217363,0.4059829059829383};

Float_t Ef_3[25] = {0.7538110791966698, 0.7898090463165469, 0.8265051021864883, 0.8619491665762531, 0.874390564238441,  0.8968978591944998, 0.9188269824863953, 0.9425462965606639, 0.9610535001513241, 0.9823844655980722, 1.003701155201261,  1.022462468807282,  1.040018901216873,  1.0600564752371218, 1.0741410224930192, 1.0926027813150148, 1.1083395195322094, 1.128025907800892,  1.1521461351484594, 1.174779295458569,  1.197921627522304,  1.21713810260715,   1.2378142826959648, 1.2565322929098552, 1.2747530279064192};


Float_t Xsec_3[25] = {2.521959102563372,1.6075627708841296,2.504828090291852,2.218397565112113,2.7268460093306857,3.5502766658481733,4.59104276471696,5.92183690134248,9.063721655312605,9.983657014292959,10.662045100244953,8.103471314119943,5.158307684401066,4.194060107011708,2.5045996767948964,1.5442256116247108,1.1431695798904542,0.9035257526700491,0.6844391401754422,0.30417825389299935,0.205770105622193,0.34852854121814403,0.1894956439642499,0.23156179631986618,0.19306460485415755};


Float_t Ef_4[33] = {0.6235966281241871,0.6403614244165428, 0.6557459033836988, 0.6735097302026436, 0.6863123950722376, 0.7008057269868293, 0.7150744248185192, 0.7364102291267645, 0.7537203542124802, 0.7729797711096924, 0.7894342176822493, 0.8075660305975267, 0.8234825376557662, 0.8400330448558795, 0.8587190536993687, 0.865694533115793,  0.8861938710363908, 0.907302085550117,  0.9297684495519141, 0.9501909389704666, 0.9691193161665603, 0.9876486722943416, 1.0070514412049845, 1.0266300749568464, 1.0445579437705421, 1.0624148755054268, 1.078820552836301,  1.0946513442576435, 1.1138871154619185, 1.159220342389634,  1.1799162351327706, 1.220793726797664,  1.239988118039299,};


Float_t Xsec_4[33] = {4.230230230230228,4.1201201201201165,3.684684684684683,3.524524524524523,3.499499499499496,2.7487487487487456,2.7587587587587556,2.168168168168167,1.877877877877875,1.6526526526526482,0.9269269269269227,1.1871871871871846,0.6166166166166107,1.2322322322322279,1.2822822822822797,0.9919919919919877,1.567567567567563,1.7477477477477432,2.328328328328327,3.164164164164161,4.060060060060058,4.640640640640639,3.929929929929928,2.6236236236236223,1.9079079079079033,1.4324324324324298,0.8718718718718694,0.5915915915915875,0.4464464464464406,0.25125125125124725,0.1611611611611572,0.056056056056053905,0.051051051051047125};



Float_t Ef_5[33] = {0.6379334530355737,0.668580032169977,  0.6960891033554032, 0.7279429918078776, 0.7406510679684283, 0.7606058055586727, 0.7803884711779446, 0.7968643623985338, 0.814169752740059,  0.8301630943029213, 0.8484653798675793, 0.8642660756368531, 0.8713752665245204, 0.8914534470504619, 0.9156716417910448, 0.9364558785022258, 0.9566575019638647, 0.9775820147383384, 0.9953577974787714, 1.0151694534844573, 1.0340898889013581, 1.0509576179254108, 1.068365877380017,  1.0858021920472822, 1.1010819960348632, 1.1215464033217373, 1.144417012680956,  1.1661813114876742, 1.1896990610855496, 1.2096734373246552, 1.2290904500056112, 1.2444151423334455, 1.2643754909662217};

Float_t Xsec_5[33] = {1.5304773126846953,1.580069576927392,1.4627800845397072,1.538585269143006,1.340450005611042,1.3019769573186686,0.6172427336999213,0.6217502712003888,0.8313320614970259,0.42567238993004786,0.48261511988927275,0.4132065237721161,0.45601877828900506,.5224722253394685,0.6079377548348486,0.7745389593386447,0.9459189017319414,1.2317547600344136,1.3411700894026106,1.1810776942355874,0.7634477986009784,0.6010174690457486,0.3980380054614141,0.21890547263681448,0.20673886208057546,0.10148505592338886,0.04150301125948985,0.0411569969700345,0.031244155164028342,0.009463958403470585,0.01392473721617371,0.039913215875508,0.006209553735082807};

Float_t Ef_6[28] = {0.740660290538158,0.7679750058056026, 0.7842797182347528, 0.8041886347802903, 0.820607739083317,  0.8383352541993861, 0.8532266249236674, 0.8599869266429857, 0.8820202637033724, 0.9035773263264729, 0.9253225334789753, 0.9449239681078899, 0.9652005728194589, 0.9838225807838855, 1.0046012626110592, 1.0221008540686527, 1.0399939363705957, 1.056399064222867,  1.0715495368419248, 1.0873440013073359, 1.1095773091246874, 1.1296797457576098, 1.1538514797836017, 1.1758729906164267, 1.195852864527338,  1.2142620003956415, 1.2344353943939383, 1.2534240154128002};

Float_t Xsec_6[28] = {0.452324391271814,0.4805043563521889,0.34285738859693593,.3209824513117794,0.305174010395612,0.3565098723914204,0.252989526979567,0.220288932658763,0.17541520809860023,0.14143308075378158,0.18065028483289858,0.24105148781110053,0.2536575296515773,0.27776583209337113,0.2818999945527678,0.20075057124262807,0.15650184489149943,0.08382716792669731,0.0601603779805675,0.0413301567369353,0.015209245386337056,0.011482191851513779,0.00047591606675378983,0.010048709722735527,0.,0.,0.0019007973027593827,0.004833701738240048};

//-----------------------------

Float_t Ef_7[41];
Float_t Xsec_7[41];

//Float_t Ef_7_tmp[37] = {8.846,8.800,8.754,8.696,8.650,8.627,8.604,8.593,8.581,8.570,8.559,8.547,8.536,8.524,8.513,8.5,8.489,8.477,8.466,8.454,8.443,8.431,8.420,8.408,8.397,8.385,8.374,8.362,8.351,8.339,8.328,8.305,8.247,8.201,8.155,8.098,8.052};
//Float_t Xsec_7_tmp[37] = {0.291,0.564,1.01,1.68,3.13,4.51,5.9,6.94,9.01,9.69,12.2,15.3,17.6,21.7,25.3,29.7,35.5,40.5,45.2,49.,51.1,54.1,52.1,48.2,44.6,40.7,38.7,33.8,31.8,28.4,27.4,25.8,27.8,35.9,43.8,48.6,50.1};



Float_t Ef_7_tmp[41] = {8.846,8.800,8.754,8.696,8.673,8.662,8.650,8.639,8.627,8.616,8.604,8.593,8.581,8.570,8.559,8.547,8.536,8.524,8.513,8.5,8.489,8.477,8.466,8.454,8.443,8.431,8.420,8.408,8.397,8.385,8.374,8.362,8.351,8.339,8.328,8.305,8.247,8.201,8.155,8.098,8.052};
Float_t Xsec_7_tmp[41] = {0.291,0.564,1.01,1.68,2.35,2.43,3.13,3.48,4.51,4.88,5.9,6.94,9.01,9.69,12.2,15.3,17.6,21.7,25.3,29.7,35.5,40.5,45.2,49.,51.1,54.1,52.1,48.2,44.6,40.7,38.7,33.8,31.8,28.4,27.4,25.8,27.8,35.9,43.8,48.6,50.1};

Float_t Ef_8[42];
Float_t Xsec_8[42];

//Float_t Ef_8_tmp[35] = {10.904,10.846,10.802,10.744,10.7,10.671,10.656,10.642,10.627,10.613,10.597,10.582,10.568,10.553,10.539,10.524,10.509,10.495,10.480,10.466,10.451,10.436,10.422,10.407,10.393,10.378,10.364,10.349,10.334,10.305,10.247,10.203,10.145,10.101,10.057};
//Float_t Xsec_8_tmp[35] = {0.136,0.150,0.258,0.457,0.69,0.931,1.2,1.32,1.69,1.92,2.25,2.50,2.93,3.37,3.97,4.59,5.11,5.75,5.96,6.23,6.02,6.31,6.06,5.56,4.99,5.,4.60,4.69,4.59,4.54,5.6,6.78,8.08,8.55,10.};


Float_t Ef_8_tmp[42] = {10.904,10.846,10.802,10.788,10.773,10.758,10.744,10.729,10.715,10.7,10.685,10.671,10.656,10.642,10.627,10.613,10.597,10.582,10.568,10.553,10.539,10.524,10.509,10.495,10.480,10.466,10.451,10.436,10.422,10.407,10.393,10.378,10.364,10.349,10.334,10.320,10.305,10.247,10.203,10.145,10.101,10.057};
Float_t Xsec_8_tmp[42] = {0.136,0.150,0.258,0.360,0.292,0.370,0.457,0.506,0.572,0.69,0.776,0.931,1.2,1.32,1.69,1.92,2.25,2.50,2.93,3.37,3.97,4.59,5.11,5.75,5.96,6.23,6.02,6.31,6.06,5.56,4.99,5.,4.60,4.69,4.59,4.56,4.54,5.6,6.78,8.08,8.55,10.};

for (j=0; j<41; j++){
Ef_7[j] = Ef_7_tmp[40-j];
Xsec_7[j] = Xsec_7_tmp[40-j];
};

for (j=0; j<42; j++){
Ef_8[j] = Ef_8_tmp[41-j];
Xsec_8[j] = Xsec_8_tmp[41-j];
};

for(j=0; j<41; j++){
Ef_7[j] = Ef_7[j]/Ef_peak[6];
};
for(j=0; j<42; j++){
Ef_8[j] = Ef_8[j]/Ef_peak[7];

};
//------------------


for(j=0; j<29; j++){
Xsec_1[j] = 10.*Xsec_1[j];
Xsec_2[j] = 10.*Xsec_2[j];
};
for(j=0; j<25; j++){
Xsec_3[j] = 10.*Xsec_3[j];
};
for(j=0; j<33; j++){
Xsec_4[j] = 10.*Xsec_4[j];
Xsec_5[j] = 10.*Xsec_5[j];
};
for(j=0; j<28; j++){
Xsec_6[j] = 10.*Xsec_6[j];
};


TGraphErrors * gr_1 = new TGraphErrors(29, Ef_1,Xsec_1, 0, 0);
TGraphErrors * gr_2 = new TGraphErrors(29, Ef_2,Xsec_2, 0, 0);
TGraphErrors * gr_3 = new TGraphErrors(25, Ef_3,Xsec_3, 0, 0);

TGraphErrors * gr_4 = new TGraphErrors(33, Ef_4,Xsec_4, 0, 0);
TGraphErrors * gr_5 = new TGraphErrors(33, Ef_5,Xsec_5, 0, 0);
TGraphErrors * gr_6 = new TGraphErrors(28, Ef_6,Xsec_6, 0, 0);

TGraphErrors * gr_7 = new TGraphErrors(41, Ef_7,Xsec_7, 0, 0);
TGraphErrors * gr_8 = new TGraphErrors(42, Ef_8,Xsec_8, 0, 0);

c->cd(1);
c->cd(1)->SetLeftMargin(0.15);
c->cd(1)->SetBottomMargin(0.13);

Double_t par[6] = {0.,0.,0.,0.,0.,0.};


gr_1->SetMarkerStyle(20);
gr_1->Draw("apl");

TF1 *g1 = new TF1("m1","gaus",Ef_1[10],Ef_1[28]);
TF1 *g11 = new TF1("m11","pol2",Ef_1[0],Ef_1[28]);
TF1 *total = new TF1("mstotal","gaus(0)+pol2(3)",Ef_1[0],Ef_1[28]);
gr_1->Fit(g1,"NRQ");
gr_1->Fit(g11,"NRQ");
g1->GetParameters(&par[0]);
g11->GetParameters(&par[3]);
total->SetParameters(par);
gr_1->Fit(total,"QR+");
gr_1->Draw();

/*TF1 *g1 = new TF1("m1","gaus",Ef_1[10],Ef_1[28]);
gr_1->Fit(g1, "RQ");*/

Left_limit[0] = total->GetParameter(1)-total->GetParameter(2);
Right_limit[0] = total->GetParameter(1)+3*total->GetParameter(2);

cout << "mu = "<<total->GetParameter(1) <<", sigma = "<<total->GetParameter(2)<< ", Left =  "<<Left_limit[0] << ", Right =  "<< Right_limit[0]<<endl;

TLegend*leg1 =  new TLegend(0.67,0.75,0.99,0.9);
leg1->SetHeader("#splitline{Q^{2}    = 0.273 GeV^{2} }{E'_{peak} = 0.304 GeV }");
leg1->SetTextSize(.045);
leg1->Draw();

c->cd(2);
c->cd(2)->SetLeftMargin(0.15);
c->cd(2)->SetBottomMargin(0.13);


gr_2->SetMarkerStyle(20);
//gr_1->GetXaxis()->SetRangeUser(0.951*Ef_peak[0],1.051*Ef_peak[0]);
gr_2->Draw("apl");


//TF1 *g2 = new TF1("m2","gaus",Ef_2[11],Ef_2[28]);
//gr_2->Fit(g2, "RQ");
Double_t par2[6] = {0.,0.,0.,0.,0.,0.};
TF1 *g2 = new TF1("m2","gaus",Ef_2[11],Ef_2[28]);
TF1 *g22 = new TF1("m22","pol2",Ef_2[0],Ef_2[28]);
TF1 *total2 = new TF1("mstotal2","gaus(0)+pol2(3)",Ef_2[0],Ef_2[28]);
gr_2->Fit(g2,"NRQ");
gr_2->Fit(g22,"NRQ");
g2->GetParameters(&par2[0]);
g22->GetParameters(&par2[3]);
total2->SetParameters(par2);
gr_2->Fit(total2,"QR+");
gr_2->Draw();

Left_limit[1] = total2->GetParameter(1)-total2->GetParameter(2);
Right_limit[1] =total2->GetParameter(1)+3*total2->GetParameter(2);

cout << "mu = "<<total2->GetParameter(1) <<", sigma = "<<total2->GetParameter(2)<< ", Left =  "<<Left_limit[1] << ", Right =  "<< Right_limit[1]<<endl;

TLegend*leg2 = new TLegend(0.67,0.75,0.99,0.9);
leg2->SetHeader("#splitline{Q^{2}    = 0.389 GeV^{2} }{E'_{peak} = 0.350 GeV }");
leg2->SetTextSize(.045);
leg2->Draw();



c->cd(3);
c->cd(3)->SetLeftMargin(0.15);
c->cd(3)->SetBottomMargin(0.13);



gr_3->SetMarkerStyle(20);
//gr_1->GetXaxis()->SetRangeUser(0.951*Ef_peak[0],1.051*Ef_peak[0]);
gr_3->Draw("apl");

//TF1 *g3 = new TF1("m3","gaus",Ef_3[7],Ef_3[24]);
//gr_3->Fit(g3, "RQ");

Double_t par3[6] = {0.,0.,0.,0.,0.,0.};
TF1 *g3 = new TF1("m3","gaus",Ef_3[7],Ef_3[24]);
TF1 *g33 = new TF1("m33","pol2",Ef_3[0],Ef_3[24]);
TF1 *total3 = new TF1("mstotal3","gaus(0)+pol2(3)",Ef_3[0],Ef_3[24]);
gr_3->Fit(g3,"NRQ");
gr_3->Fit(g33,"NRQ");
g3->GetParameters(&par3[0]);
g33->GetParameters(&par3[3]);
total3->SetParameters(par3);
gr_3->Fit(total3,"QR+");
gr_3->Draw();

Left_limit[2] =total3->GetParameter(1)-total3->GetParameter(2);
Right_limit[2] = total3->GetParameter(1)+3*total3->GetParameter(2);

cout << "mu = "<<total3->GetParameter(1) <<", sigma = "<<total3->GetParameter(2)<< ", Left =  "<<Left_limit[2] << ", Right =  "<< Right_limit[2]<<endl;

TLegend*leg3 =  new TLegend(0.67,0.75,0.99,0.9);
leg3->SetHeader("#splitline{Q^{2}    = 0.584 GeV^{2} }{E'_{peak} = 0.407 GeV }");
leg3->SetTextSize(.045);
leg3->Draw();


c->cd(4);
c->cd(4)->SetLeftMargin(0.15);
c->cd(4)->SetBottomMargin(0.13);


gr_4->SetMarkerStyle(20);
//gr_1->GetXaxis()->SetRangeUser(0.951*Ef_peak[0],1.051*Ef_peak[0]);
gr_4->Draw("apl");

//TF1 *g4 = new TF1("m4","gaus",Ef_4[19],Ef_4[32]);
//gr_4->Fit(g4, "RQ");

Double_t par4[7] = {0.,0.,0.,0.,0.,0.,0.};
TF1 *g4 = new TF1("m4","gaus",Ef_4[19],Ef_4[32]);
TF1 *g44 = new TF1("m44","pol3",Ef_4[0],Ef_4[32]);
TF1 *total4 = new TF1("mstotal4","gaus(0)+pol3(3)",Ef_4[0],Ef_4[32]);
gr_4->Fit(g4,"NRQ");
gr_4->Fit(g44,"NRQ");
g4->GetParameters(&par4[0]);
g44->GetParameters(&par4[3]);
total4->SetParameters(par4);
gr_4->Fit(total4,"QR+");
gr_4->Draw();

Left_limit[3] =total4->GetParameter(1)-total4->GetParameter(2);
Right_limit[3]=total4->GetParameter(1)+3*total4->GetParameter(2);

cout << "mu = "<<total4->GetParameter(1) <<", sigma = "<<total4->GetParameter(2)<< ", Left =  "<<Left_limit[3] << ", Right =  "<< Right_limit[3]<<endl;

TLegend*leg4 = new TLegend(0.67,0.75,0.99,0.9);
leg4->SetHeader("#splitline{Q^{2}    = 0.779 GeV^{2} }{E'_{peak} = 0.450 GeV }");
leg4->SetTextSize(.045);
leg4->Draw();



c->cd(5);
c->cd(5)->SetLeftMargin(0.15);
c->cd(5)->SetBottomMargin(0.13);



gr_5->SetMarkerStyle(20);
gr_5->Draw("apl");

//TF1 *g5 = new TF1("m5","gaus",Ef_5[16],Ef_5[32]);
//gr_5->Fit(g5, "RQ");

Double_t par5[7] = {0.,0.,0.,0.,0.,0.,0.};
TF1 *g5 = new TF1("m5","gaus",Ef_5[16],Ef_5[32]);
TF1 *g55 = new TF1("m55","pol3",Ef_5[0],Ef_5[32]);
TF1 *total5 = new TF1("mstotal5","gaus(0)+pol3(3)",Ef_5[0],Ef_5[32]);
gr_5->Fit(g5,"NRQ");
gr_5->Fit(g55,"NRQ");
g5->GetParameters(&par5[0]);
g55->GetParameters(&par5[3]);
total5->SetParameters(par5);
gr_5->Fit(total5,"QR+");
gr_5->Draw();

TF1 *g51 = new TF1("m51","gaus",Ef_5[0],Ef_5[32]);
g51->SetParameter(0.,total5->GetParameter(0));
g51->SetParameter(1.,total5->GetParameter(1));
g51->SetParameter(2.,total5->GetParameter(2));
g51->Draw("same");

Left_limit[4] =total5->GetParameter(1)-total5->GetParameter(2);
Right_limit[4]=total5->GetParameter(1)+3*total5->GetParameter(2);

cout << "mu = "<<total5->GetParameter(1) <<", sigma = "<<total5->GetParameter(2)<< ", Left =  "<<Left_limit[4] << ", Right =  "<< Right_limit[4]<<endl;

TLegend*leg5 = new TLegend(0.67,0.75,0.99,0.9);
leg5->SetHeader("#splitline{Q^{2}    = 1.120 GeV^{2} }{E'_{peak} = 0.507 GeV }");
leg5->SetTextSize(.045);
leg5->Draw();



c->cd(6);
c->cd(6)->SetLeftMargin(0.15);
c->cd(6)->SetBottomMargin(0.13);



gr_6->SetMarkerStyle(20);
gr_6->Draw("apl");

//TF1 *g6 = new TF1("m6","gaus",Ef_6[12],Ef_6[27]);
//gr_6->Fit(g6, "RQ");

Double_t par6[7] = {0.,0.,0.,0.,0.,0.,0.};
TF1 *g6 = new TF1("m6","gaus",Ef_6[12],Ef_6[27]);
TF1 *g66 = new TF1("m66","pol3",Ef_6[0],Ef_6[27]);
TF1 *total6 = new TF1("mstotal6","gaus(0)+pol3(3)",Ef_6[0],Ef_6[27]);
gr_6->Fit(g6,"NRQ");
gr_6->Fit(g66,"NRQ");
g6->GetParameters(&par6[0]);
g66->GetParameters(&par6[3]);
total6->SetParameters(par6);
gr_6->Fit(total6,"QR+");
gr_6->Draw();

TF1 *g61 = new TF1("m61","gaus",Ef_6[0],Ef_6[27]);
g61->SetParameter(0.,total6->GetParameter(0));
g61->SetParameter(1.,total6->GetParameter(1));
g61->SetParameter(2.,total6->GetParameter(2));
g61->Draw("same");

Left_limit[5]  =total6->GetParameter(1)-total6->GetParameter(2);
Right_limit[5] =total6->GetParameter(1)+3*total6->GetParameter(2);

cout << "mu = "<<total6->GetParameter(1) <<", sigma = "<<total6->GetParameter(2)<< ", Left =  "<<Left_limit[5] << ", Right =  "<< Right_limit[5]<<endl;

TLegend*leg6 = new TLegend(0.67,0.75,0.99,0.9); 
leg6->SetHeader("#splitline{Q^{2}    = 1.752 GeV^{2} }{E'_{peak} = 0.664 GeV }");
leg6->SetTextSize(.045);
leg6->Draw();


c->cd(7);
c->cd(7)->SetLeftMargin(0.15);
c->cd(7)->SetBottomMargin(0.13);



gr_7->SetMarkerStyle(20);
gr_7->Draw("apl");

//TF1 *g7 = new TF1("m7","gaus",Ef_7[6],Ef_7[40]);
//gr_7->Fit(g7, "RQ");

Double_t par7[6] = {0.,0.,0.,0.,0.,0.};
TF1 *g7 = new TF1("m7","gaus",Ef_7[6],Ef_7[40]);
TF1 *g77 = new TF1("m77","pol2",Ef_7[0],Ef_7[40]);
TF1 *total7 = new TF1("mstotal7","gaus(0)+pol2(3)",Ef_7[0],Ef_7[40]);
gr_7->Fit(g7,"NRQ");
gr_7->Fit(g77,"NRQ");
g7->GetParameters(&par7[0]);
g77->GetParameters(&par7[3]);
total7->SetParameters(par7);
gr_7->Fit(total7,"QR+");
gr_7->Draw();

TF1 *g71 = new TF1("m71","gaus",Ef_7[0],Ef_7[38]);
g71->SetParameter(0.,total7->GetParameter(0));
g71->SetParameter(1.,total7->GetParameter(1));
g71->SetParameter(2.,total7->GetParameter(2));
g71->Draw("same");

Left_limit[6]  =total7->GetParameter(1)-total7->GetParameter(2);
Right_limit[6] =total7->GetParameter(1)+3*total7->GetParameter(2);

cout << "mu = "<<total7->GetParameter(1) <<", sigma = "<<total7->GetParameter(2)<< ", Left =  "<<Left_limit[6] << ", Right =  "<< Right_limit[6]<<endl;

c->cd(8);
c->cd(8)->SetLeftMargin(0.15);
c->cd(8)->SetBottomMargin(0.13);



gr_8->SetMarkerStyle(20);
gr_8->Draw("apl");

//TF1 *g8 = new TF1("m8","gaus",Ef_8[6],Ef_8[38]);
//gr_8->Fit(g8, "RQ");

Double_t par8[7] = {0.,0.,0.,0.,0.,0.,0.};
TF1 *g8 = new TF1("m8","gaus",Ef_8[8],Ef_8[38]);
TF1 *g88 = new TF1("m88","pol3",Ef_8[0],Ef_8[38]);
TF1 *total8 = new TF1("mstotal8","gaus(0)+pol3(3)",Ef_8[0],Ef_8[38]);
gr_8->Fit(g8,"NRQ");
gr_8->Fit(g88,"NRQ");
g8->GetParameters(&par8[0]);
g88->GetParameters(&par8[3]);
total8->SetParameters(par8);
gr_8->Fit(total8,"QR+");
gr_8->Draw();

TF1 *g81 = new TF1("m81","gaus",Ef_8[0],Ef_8[38]);
g81->SetParameter(0.,total8->GetParameter(0));
g81->SetParameter(1.,total8->GetParameter(1));
g81->SetParameter(2.,total8->GetParameter(2));
g81->Draw("same");

Left_limit[7]  =total8->GetParameter(1)-total8->GetParameter(2);
Right_limit[7] =total8->GetParameter(1)+3*total8->GetParameter(2);

cout << "mu = "<<total8->GetParameter(1) <<", sigma = "<<total8->GetParameter(2)<< ", Left =  "<<Left_limit[7] << ", Right =  "<< Right_limit[7]<<endl;

//------------------------------------
Float_t A_left[8], B_left[8], C_left[8], Y_left[8];
Float_t A_right[8], B_right[8], C_right[8], Y_right[8];

Short_t Kmax[8], Kmin[8];
Float_t Left_arr[2][8];
Float_t Right_arr[2][8];

Float_t Xsect_left[2][8];
Float_t Xsect_right[2][8];


//--LEFT--------------------
k=0;
do {
k++;
}while (Ef_1[k] < Left_limit[0]);

Left_arr[0][0] = Ef_1[k-1];
Left_arr[1][0] = Ef_1[k]; 

Xsect_left[0][0] = Xsec_1[k-1];
Xsect_left[1][0] = Xsec_1[k];
Kmin[0] = k;

cout << endl<<"#,    x1<--left limit-->x2  "<<endl;
cout << k<<" "<<Left_arr[0][0]<<" "<< Left_limit[0]<<" "<< Left_arr[1][0]<<endl;

k=0;
do {
k++;
}while (Ef_2[k] < Left_limit[1]);

Left_arr[0][1] = Ef_2[k-1];
Left_arr[1][1] = Ef_2[k]; 
Xsect_left[0][1] = Xsec_2[k-1];
Xsect_left[1][1] = Xsec_2[k];
Kmin[1] = k;
cout<< k<<" "<<Left_arr[0][1]<<" "<< Left_limit[1]<<" "<< Left_arr[1][1]<<endl;

k=0;
do {
k++;
}while (Ef_3[k] < Left_limit[2]);

Left_arr[0][2] = Ef_3[k-1];
Left_arr[1][2] = Ef_3[k]; 
Xsect_left[0][2] = Xsec_3[k-1];
Xsect_left[1][2] = Xsec_3[k];
Kmin[2] = k;
cout << k<<" "<<Left_arr[0][2]<<" "<< Left_limit[2]<<" "<< Left_arr[1][2]<<endl;

k=0;
do {
k++;
}while (Ef_4[k] < Left_limit[3]);

Left_arr[0][3] = Ef_4[k-1];
Left_arr[1][3] = Ef_4[k]; 
Xsect_left[0][3] = Xsec_4[k-1];
Xsect_left[1][3] = Xsec_4[k];
Kmin[3] = k;
cout << k<<" "<<Left_arr[0][3]<<" "<< Left_limit[3]<<" "<< Left_arr[1][3]<<endl;


k=0;
do {
k++;
}while (Ef_5[k] < Left_limit[4]);

Left_arr[0][4] = Ef_5[k-1];
Left_arr[1][4] = Ef_5[k]; 
Xsect_left[0][4] = Xsec_5[k-1];
Xsect_left[1][4] = Xsec_5[k];
Kmin[4] = k;
cout << k<<" "<<Left_arr[0][4]<<" "<< Left_limit[4]<<" "<< Left_arr[1][4]<<endl;

k=0;
do {
k++;
}while (Ef_6[k] < Left_limit[5]);

Left_arr[0][5] = Ef_6[k-1];
Left_arr[1][5] = Ef_6[k]; 
Xsect_left[0][5] = Xsec_6[k-1];
Xsect_left[1][5] = Xsec_6[k];
Kmin[5] = k;
cout << k<<" "<<Left_arr[0][5]<<" "<< Left_limit[5]<<" "<< Left_arr[1][5]<<endl;

k=0;
do {
k++;
}while (Ef_7[k] < Left_limit[6]);

Left_arr[0][6] = Ef_7[k-1];
Left_arr[1][6] = Ef_7[k]; 
Xsect_left[0][6] = Xsec_7[k-1];
Xsect_left[1][6] = Xsec_7[k];
Kmin[6] = k;
cout << k<<" "<<Left_arr[0][6]<<" "<< Left_limit[6]<<" "<< Left_arr[1][6]<<endl;


k=0;
do {
k++;
}while (Ef_8[k] < Left_limit[7]);

Left_arr[0][7] = Ef_8[k-1];
Left_arr[1][7] = Ef_8[k]; 
Xsect_left[0][7] = Xsec_8[k-1];
Xsect_left[1][7] = Xsec_8[k];
Kmin[7] = k;
cout << k<<" "<<Left_arr[0][7]<<" "<< Left_limit[7]<<" "<< Left_arr[1][7]<<endl;
cout << endl;

//--RIGHT--------------------
k=0;
do {
k++;
}while (Ef_1[k] < Right_limit[0]);

Right_arr[0][0] = Ef_1[k-1];
Right_arr[1][0] = Ef_1[k]; 
Xsect_right[0][0] = Xsec_1[k-1];
Xsect_right[1][0] = Xsec_1[k];
Kmax[0] = k-1;

cout << endl<<"#,   x1<-right limit->x2  "<<endl;
cout << k<<" "<<Right_arr[0][0]<<" "<< Right_limit[0]<<" "<< Right_arr[1][0]<<endl;

k=0;
do {
k++;
}while (Ef_2[k] < Right_limit[1]);

Right_arr[0][1] = Ef_2[k-1];
Right_arr[1][1] = Ef_2[k]; 
Xsect_right[0][1] = Xsec_2[k-1];
Xsect_right[1][1] = Xsec_2[k];
Kmax[1] = k-1;
cout << k<<" "<<Right_arr[0][1]<<" "<< Right_limit[1]<<" "<< Right_arr[1][1]<<endl;

k=0;
do {
k++;
}while (Ef_3[k] < Right_limit[2]);

Right_arr[0][2] = Ef_3[k-1];
Right_arr[1][2] = Ef_3[k];
Xsect_right[0][2] = Xsec_3[k-1];
Xsect_right[1][2] = Xsec_3[k];
Kmax[2] = k-1;
cout << k<<" "<<Right_arr[0][2]<<" "<< Right_limit[2]<<" "<< Right_arr[1][2]<<endl;

k=0;
do {
k++;
}while (Ef_4[k] < Right_limit[3]);

Right_arr[0][3] = Ef_4[k-1];
Right_arr[1][3] = Ef_4[k]; 
Xsect_right[0][3] = Xsec_4[k-1];
Xsect_right[1][3] = Xsec_4[k];
Kmax[3] = k-1;
cout << k<<" "<<Right_arr[0][3]<<" "<< Right_limit[3]<<" "<< Right_arr[1][3]<<endl;


k=0;
do {
k++;
}while (Ef_5[k] < Right_limit[4]);

Right_arr[0][4] = Ef_5[k-1];
Right_arr[1][4] = Ef_5[k]; 
Xsect_right[0][4] = Xsec_5[k-1];
Xsect_right[1][4] = Xsec_5[k];
Kmax[4] = k-1;

cout << k<<" "<<Right_arr[0][4]<<" "<< Right_limit[4]<<" "<< Right_arr[1][4]<<endl;

k=0;
do {
k++;
}while (Ef_6[k] < Right_limit[5]);

Right_arr[0][5] = Ef_6[k-1];
Right_arr[1][5] = Ef_6[k]; 
Xsect_right[0][5] = Xsec_6[k-1];
Xsect_right[1][5] = Xsec_6[k];
Kmax[5] = k-1;
cout << k<<" "<<Right_arr[0][5]<<" "<< Right_limit[5]<<" "<< Right_arr[1][5]<<endl;

k=0;
do {
k++;
}while (Ef_7[k] < Right_limit[6]);

Right_arr[0][6] = Ef_7[k-1];
Right_arr[1][6] = Ef_7[k]; 
Xsect_right[0][6] = Xsec_7[k-1];
Xsect_right[1][6] = Xsec_7[k];
Kmax[6] = k-1;
cout << k<<" "<<Right_arr[0][6]<<" "<< Right_limit[6]<<" "<< Right_arr[1][6]<<endl;


k=0;
do {
k++;
}while (Ef_8[k] < Right_limit[7]);

Right_arr[0][7] = Ef_8[k-1];
Right_arr[1][7] = Ef_8[k]; 
Xsect_right[0][7] = Xsec_8[k-1];
Xsect_right[1][7] = Xsec_8[k];
Kmax[7] = k-1;

cout << k<<" "<<Right_arr[0][7]<<" "<< Right_limit[7]<<" "<< Right_arr[1][7]<<endl;
cout << endl;
//---------------------------------
TLine *line_left[8];
TLine *line_left2[8];

TLine *line_right[8];
TLine *line_right2[8];

cout << endl<<"#,       y1<--y(limit)-->y2  "<<endl;
for(j=0; j<8; j++){

line_left[j] = new TLine(Left_limit[j],0.,Left_limit[j],1.5*Xsect_left[1][j]);

A_left[j] = Xsect_left[0][j] - Xsect_left[1][j];
B_left[j] = Left_arr[1][j] -  Left_arr[0][j];
C_left[j] = Left_arr[0][j]*Xsect_left[1][j] - Left_arr[1][j]*Xsect_left[0][j];

Y_left[j] = -A_left[j]/B_left[j]*Left_limit[j] - C_left[j]/B_left[j];

cout <<j<<" LEFT  "<< Xsect_left[0][j]<<" "<<Y_left[j]<<" "<<Xsect_left[1][j]<<" \n";

line_left2[j] = new TLine(0.5*Left_arr[0][j],Y_left[j],1.5*Left_arr[0][j],Y_left[j]);

//-------------
line_right[j] = new TLine(Right_limit[j],0.,Right_limit[j],2.5*Xsect_right[1][j]);

A_right[j] = Xsect_right[0][j] - Xsect_right[1][j];
B_right[j] = Right_arr[1][j] -  Right_arr[0][j];
C_right[j] = Right_arr[0][j]*Xsect_right[1][j] - Right_arr[1][j]*Xsect_right[0][j];

Y_right[j] = -A_right[j]/B_right[j]*Right_limit[j] - C_right[j]/B_right[j];

cout <<j<<" RIGHT "<< Xsect_right[0][j]<<" "<<Y_right[j]<<" "<<Xsect_right[1][j]<<" \n";
cout <<endl;

line_right2[j] = new TLine(0.5*Right_arr[0][j],Y_right[j],2.5*Right_arr[0][j],Y_right[j]);


c->cd(j+1);
line_left[j]->SetLineColor(43);
line_left[j]->SetLineWidth(2);
line_left[j]->Draw("same");

line_left2[j]->SetLineColor(43);
line_left2[j]->SetLineWidth(2);
line_left2[j]->Draw("same");

line_right[j]->SetLineColor(43);
line_right[j]->SetLineWidth(2);
line_right[j]->Draw("same");

line_right2[j]->SetLineColor(43);
line_right2[j]->SetLineWidth(2);
line_right2[j]->Draw("same");
};

Short_t Kfin[8], dim[8];

for(j=0; j<8; j++){
Integral[j]=0.;
Kfin[j] = Kmax[j] - Kmin[j]+1;
if ((Kfin[j] % 2) == 0) dim[j] = Kfin[j]+1;
if (!((Kfin[j] % 2) == 0)) dim[j] = Kfin[j]+2;
};

/*dim[0] = Kfin[0]+1;
dim[1] = Kfin[1]+1;
dim[2] = Kfin[2]+2;
dim[3] = Kfin[3]+1;
dim[4] = Kfin[4]+1;
dim[5] = Kfin[5]+1;
dim[6] = Kfin[6]+1;
dim[7] = Kfin[7]+2;*/

for(j=0; j<8; j++){
cout <<" "<<Kfin[j]<<" "<<dim[j]<< endl;
};

///-----------------INTEGRAL #1-----------------
Float_t Fin_arr_x1[dim[0]];
Float_t Fin_arr_y1[dim[0]];

Fin_arr_x1[0] = Left_limit[0];
Fin_arr_y1[0] = Y_left[0];

Fin_arr_x1[dim[0]-1] =Right_limit[0];
Fin_arr_y1[dim[0]-1] = Y_right[0];

for(j=1; j<dim[0]-1; j++){
Fin_arr_x1[j] = Ef_1[Kmin[0]+j-1];
Fin_arr_y1[j] = Xsec_1[Kmin[0]+j-1];
};
//cout<< endl;
//for (j=0; j<dim[0]; j++){
//cout << Fin_arr_x1[j] <<" "<< Fin_arr_y1[j] <<" fin\n";
//};


for(Int_t i=2;i<=dim[0];i += 2){
h = abs(Fin_arr_x1[i] - Fin_arr_x1[i-2]);
Integral[0] += (Fin_arr_y1[i-2] + 4.*Fin_arr_y1[i-1] + Fin_arr_y1[i])*h; 
};
Integral[0] /= 6.0;

cout <<" Int " << Integral[0]<<" \n";

///-----------------INTEGRAL #2-----------------


Float_t Fin_arr_x2[dim[1]];
Float_t Fin_arr_y2[dim[1]];

Fin_arr_x2[0] = Left_limit[1];
Fin_arr_y2[0] = Y_left[1];

Fin_arr_x2[dim[1]-1] =Right_limit[1];
Fin_arr_y2[dim[1]-1] = Y_right[1];

for(j=1; j<dim[1]-1; j++){
Fin_arr_x2[j] = Ef_2[Kmin[1]+j-1];
Fin_arr_y2[j] = Xsec_2[Kmin[1]+j-1];
};
cout<< endl;
//for (j=0; j<dim[1]; j++){
//cout << Fin_arr_x2[j] <<" "<< Fin_arr_y2[j] <<" fin\n";
//};


for(Int_t i=2;i<=dim[1];i += 2){
h = abs(Fin_arr_x2[i] - Fin_arr_x2[i-2]);
Integral[1] += (Fin_arr_y2[i-2] + 4.*Fin_arr_y2[i-1] + Fin_arr_y2[i])*h; 
};
Integral[1] /= 6.0;

//cout <<" Int " << Integral[1]<<" \n";

///-----------------INTEGRAL #3-----------------


Float_t Fin_arr_x3[dim[2]];
Float_t Fin_arr_y3[dim[2]];

Fin_arr_x3[0] = Left_limit[2];
Fin_arr_y3[0] = Y_left[2];

Fin_arr_x3[dim[2]-1] =Right_limit[2];
Fin_arr_y3[dim[2]-1] = Y_right[2];

for(j=1; j<dim[2]-1; j++){
Fin_arr_x3[j] = Ef_3[Kmin[2]+j-1];
Fin_arr_y3[j] = Xsec_3[Kmin[2]+j-1];
};
//cout<< endl;
//for (j=0; j<dim[2]; j++){
//cout << Fin_arr_x3[j] <<" "<< Fin_arr_y3[j] <<" fin\n";
//};


for(Int_t i=2;i<=dim[2];i += 2){
h = abs(Fin_arr_x3[i] - Fin_arr_x3[i-2]);
Integral[2] += (Fin_arr_y3[i-2] + 4.*Fin_arr_y3[i-1] + Fin_arr_y3[i])*h; 
};
Integral[2] /= 6.0;

//cout <<" Int " << Integral[2]<<" \n";


///-----------------INTEGRAL #4-----------------

Float_t Fin_arr_x4[dim[3]];
Float_t Fin_arr_y4[dim[3]];

Fin_arr_x4[0] = Left_limit[3];
Fin_arr_y4[0] = Y_left[3];

Fin_arr_x4[dim[3]-1] =Right_limit[3];
Fin_arr_y4[dim[3]-1] = Y_right[3];

for(j=1; j<dim[3]-1; j++){
Fin_arr_x4[j] = Ef_4[Kmin[3]+j-1];
Fin_arr_y4[j] = Xsec_4[Kmin[3]+j-1];
};
cout<< endl;
for (j=0; j<dim[3]; j++){
cout << Fin_arr_x4[j] <<" "<< Fin_arr_y4[j] <<" fin\n";
};


for(Int_t i=2;i<=dim[3];i += 2){
h = abs(Fin_arr_x4[i] - Fin_arr_x4[i-2]);
Integral[3] += (Fin_arr_y4[i-2] + 4.*Fin_arr_y4[i-1] + Fin_arr_y4[i])*h; 
};
Integral[3] /= 6.0;

//cout <<" Int " << Integral[3]<<" \n";

///-----------------INTEGRAL #5-----------------

Float_t Fin_arr_x5[dim[4]];
Float_t Fin_arr_y5[dim[4]];

Fin_arr_x5[0] = Left_limit[4];
Fin_arr_y5[0] = Y_left[4];

Fin_arr_x5[dim[4]-1] =Right_limit[4];
Fin_arr_y5[dim[4]-1] = Y_right[4];

for(j=1; j<dim[4]-1; j++){
Fin_arr_x5[j] = Ef_5[Kmin[4]+j-1];
Fin_arr_y5[j] = Xsec_5[Kmin[4]+j-1];
};
//cout<< endl;
//for (j=0; j<dim[4]; j++){
//cout << Fin_arr_x5[j] <<" "<< Fin_arr_y5[j] <<" fin\n";
//};


for(Int_t i=2;i<=dim[4];i += 2){
h = abs(Fin_arr_x5[i] - Fin_arr_x5[i-2]);
Integral[4] += (Fin_arr_y5[i-2] + 4.*Fin_arr_y5[i-1] + Fin_arr_y5[i])*h; 
};
Integral[4] /= 6.0;

//cout <<" Int " << Integral[4]<<" \n";

///-----------------INTEGRAL #6-----------------

Float_t Fin_arr_x6[dim[5]];
Float_t Fin_arr_y6[dim[5]];

Fin_arr_x6[0] = Left_limit[5];
Fin_arr_y6[0] = Y_left[5];

Fin_arr_x6[dim[5]-1] =Right_limit[5];
Fin_arr_y6[dim[5]-1] = Y_right[5];

for(j=1; j<dim[5]-1; j++){
Fin_arr_x6[j] = Ef_6[Kmin[5]+j-1];
Fin_arr_y6[j] = Xsec_6[Kmin[5]+j-1];
};
//cout<< endl;
//for (j=0; j<dim[5]; j++){
///cout << Fin_arr_x6[j] <<" "<< Fin_arr_y6[j] <<" fin\n";
//};
//cout<< endl;

for(Int_t i=2;i<=dim[5];i += 2){
h = abs(Fin_arr_x6[i] - Fin_arr_x6[i-2]);
Integral[5] += (Fin_arr_y6[i-2] + 4.*Fin_arr_y6[i-1] + Fin_arr_y6[i])*h; 
};
Integral[5] /= 6.0;

//cout <<" Int " << Integral[5]<<" \n";

///-----------------INTEGRAL #7-----------------

Float_t Fin_arr_x7[dim[6]];
Float_t Fin_arr_y7[dim[6]];

Fin_arr_x7[0] = Left_limit[6];
Fin_arr_y7[0] = Y_left[6];

Fin_arr_x7[dim[6]-1] =Right_limit[6];
Fin_arr_y7[dim[6]-1] = Y_right[6];

for(j=1; j<dim[6]-1; j++){
Fin_arr_x7[j] = Ef_7[Kmin[6]+j-1];
Fin_arr_y7[j] = Xsec_7[Kmin[6]+j-1];
};
//cout<< endl;
//for (j=0; j<dim[6]; j++){
//cout <<j<<" "<< Fin_arr_x7[j] <<" "<< Fin_arr_y7[j] <<" fin\n";
//};
//cout<< endl;
//cout <<" Int " << Integral[6]<<" \n";
for(Int_t i=2;i<=dim[6]-1;i += 2){
h = abs(Fin_arr_x7[i] - Fin_arr_x7[i-2]);
Integral[6] += (Fin_arr_y7[i-2] + 4.*Fin_arr_y7[i-1] + Fin_arr_y7[i])*h; 
};
Integral[6] /= 6.0;

//cout <<" Int " << Integral[6]<<" \n";


///-----------------INTEGRAL #8-----------------

Float_t Fin_arr_x8[dim[7]];
Float_t Fin_arr_y8[dim[7]];

Fin_arr_x8[0] = Left_limit[7];
Fin_arr_y8[0] = Y_left[7];

Fin_arr_x8[dim[7]-1] =Right_limit[7];
Fin_arr_y8[dim[7]-1] = Y_right[7];

for(j=1; j<dim[7]-1; j++){
Fin_arr_x8[j] = Ef_8[Kmin[7]+j-1];
Fin_arr_y8[j] = Xsec_8[Kmin[7]+j-1];
};
//cout<< endl;
//for (j=0; j<dim[7]; j++){
//cout <<j<<" "<< Fin_arr_x8[j] <<" "<< Fin_arr_y8[j] <<" fin\n";
//};//*Ef_peak[7]
//cout<< endl;
//cout <<" Int " << Integral[7]<<" \n";
for(Int_t i=2;i<=dim[7]-1;i += 2){
h = abs(Fin_arr_x8[i] - Fin_arr_x8[i-2]);
Integral[7] += (Fin_arr_y8[i-2] + 4.*Fin_arr_y8[i-1] + Fin_arr_y8[i])*h; 
};
Integral[7] /= 6.0;

//cout <<" Int " << Integral[7]<<" \n";

cout <<"#, Integral"<< endl;
for (j=0; j<8; j++){
cout <<j<<" " << Integral[j]<<" \n";
};

};



