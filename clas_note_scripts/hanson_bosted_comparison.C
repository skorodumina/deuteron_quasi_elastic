void hanson_bosted_comparison(){
gStyle->SetOptStat(0);
gStyle->SetTitleY(0.975);
gStyle->SetTitleSize(0.08);

TCanvas *c = new TCanvas("c","c",0,0,1000,600);
c->Divide(3,2);

Short_t j,k;
ostringstream qqq;

Float_t h, Integral1, Integral2,w;
Short_t nl, nr;
Float_t E_beam[6] = {0.449,0.557,0.718,0.865,1.104,1.598};
Float_t Q2[6] = {0.273,0.389,0.584,0.779,1.120,1.752};
Float_t Ef_peak[6] = {0.304,0.350,0.407,0.450,0.507,0.664};
Float_t Theta[6] = {90.,90.,90.,90.,90.,90.};



Float_t Xsec_Durand[6] = {0.713111, 0.31405, 0.107971, 0.045611, 0.0131869, 0.0026376};
//Float_t Xsec_Durand[6] = {0.742107,0.332662,0.117926,0.0514028,0.0157113,0.00348409};
Float_t Xsec_Kocevar[6] = {0.727656,0.339405,0.122581,0.0536327,0.016373,0.00358437};

//Float_t Left_limit[6]= {0.930765, 0.932336, 0.941109, 0.935456, 0.942918, 0.939813};
//Float_t Right_limit[6]= {1.14915,1.14826,1.13824,1.13387,1.13881,1.12872};
//Float_t Integral_data[8] = {76.3538,33.7656,10.6704,4.59732,1.3508,0.294046};


//Positions of the integration limits as well as the integral values themselves come from the script Integrate_data.C
Float_t Left_limit[6]= { 0.934379,0.94047,0.946527,0.937576,0.950886,0.956723};
Float_t Right_limit[6]= {1.13059,1.1257,1.12047,1.12393,1.1311,1.10956};
Float_t Integral_data[6] = {74.3252,31.7497,10.4629,4.47737,1.26355,0.254206};

//test
//Float_t Left_limit[6]= {0.909852, 0.917315, 0.924784, 0.914281, 0.928359, 0.937619};
//Float_t Right_limit[6]= {1.13059,1.1257,1.12047,1.12393,1.1311,1.10956};
//Float_t Integral_data[6] = {81.0519 ,36.0227 ,11.5748 ,4.98542 ,1.44924 ,0.291667};


 

//data K. M. Hanson et al, Phys. Rev., vol. D8, pp. 753-778, 1973.
Float_t Ef_1[24] = {0.7500812299539814, 0.7717381931855158, 0.7899306814484267, 0.8075595570120394, 0.8268560289127506, 0.8444238948542744, 0.8590487728350302, 0.8754806977176594, 0.8842617254683217, 0.905908520429508,  0.9286854460093898, 0.9496161042160557, 0.9694514944452194, 0.9905085297262123, 1.009408439083345,  1.0289533073025614, 1.0496660740017665, 1.0673733905080651, 1.085067633523916,  1.1021227281178823, 1.1174245223818158, 1.139159926556036,  1.162080660530842,  1.1879022567749735};

Float_t Xsec_1[24] = {3.917766776677638,8.61042354235417,8.61042354235417,6.685231023102233,12.460808580858043,15.589246424642454,19.43963146314627,19.43963146314627,21.244499449944954,26.779427942794257,35.92409240924093,52.16790429042902,61.9141914191419,67.68976897689771,57.702832783278325,42.9029152915291,28.58429592959294,20.161578657865732,12.821782178217802,9.813668866886644,6.203932893289277,4.399064906490651,1.631600660065999,1.6316006600659};


//-------------
Float_t Ef_2[25] = {0.7347517730496455,0.7546099290780142, 0.773758865248227,  0.7914893617021277, 0.8092198581560284, 0.8276595744680851, 0.8439716312056739, 0.8602836879432624, 0.8666666666666668, 0.8907801418439716, 0.9113475177304966, 0.932033096926714,  0.9515366430260048, 0.9716312056737589, 0.991725768321513,  1.0100472813238772, 1.0307328605200947, 1.0472813238770686, 1.064420803782506,  1.0803782505910167, 1.0981087470449173, 1.1170212765957448, 1.1394799054373523, 1.1631205673758866, 1.1855791962174942};


Float_t Xsec_2[25] = {4.535085924713599,4.097620021822195,4.3093630660120255,6.25221631205676,5.454684942716881,5.306021549372645,5.951138843426122,9.120294599018024,7.315875613747977,9.47354064375341,12.02869271685762,18.454008683397007,23.07672417712311,27.458912984178937,31.180044098927084,27.6299668121477,19.632205855610152,15.301304782687822,9.648146253864383,6.278925713766171,4.712163575195518,3.2052134478996663,1.7575070467358103,0.9705741953082736,0.9050793326059647};

//---------------------

Float_t Ef_3[21] = {0.7538110791966698, 0.7898090463165469, 0.8265051021864883, 0.8619491665762531, 0.874390564238441,  0.8968978591944998, 0.9188269824863953, 0.9425462965606639, 0.9610535001513241,  0.9823844655980722, 1.003701155201261, 1.022462468807282,  1.040018901216873,  1.0600564752371218, 1.0741410224930192, 1.0926027813150148, 1.1083395195322094, 1.128025907800892,  1.1521461351484594, 1.174779295458569,  1.197921627522304};


Float_t Xsec_3[21] = {2.521959102563372,1.6075627708841296,2.504828090291852,2.218397565112113,2.7268460093306857,3.5502766658481733,4.59104276471696,5.92183690134248,9.063721655312605,9.983657014292959,10.662045100244953,8.103471314119943,5.158307684401066,4.194060107011708,2.5045996767948964,1.5442256116247108,1.1431695798904542,0.9035257526700491,0.6844391401754422,0.30417825389299935,0.205770105622193};

//----------------
Float_t Ef_4[31] = {0.6235966281241871,0.6403614244165428, 0.6557459033836988, 0.6735097302026436, 0.6863123950722376, 0.7008057269868293, 0.7150744248185192, 0.7364102291267645, 0.7537203542124802, 0.7729797711096924, 0.7894342176822493, 0.8075660305975267, 0.8234825376557662, 0.8400330448558795, 0.8587190536993687, 0.865694533115793,  0.8861938710363908, 0.907302085550117,  0.9297684495519141, 0.9501909389704666, 0.9691193161665603, 0.9876486722943416, 1.0070514412049845, 1.0266300749568464, 1.0445579437705421, 1.0624148755054268, 1.078820552836301,  1.0946513442576435, 1.1138871154619185, 1.159220342389634,  1.1799162351327706};


Float_t Xsec_4[31] = {4.230230230230228,4.1201201201201165,3.684684684684683,3.524524524524523,3.499499499499496,2.7487487487487456,2.7587587587587556,2.168168168168167,1.877877877877875,1.6526526526526482,0.9269269269269227,1.1871871871871846,0.6166166166166107,1.2322322322322279,1.2822822822822797,0.9919919919919877,1.567567567567563,1.7477477477477432,2.328328328328327,3.164164164164161,4.060060060060058,4.640640640640639,3.929929929929928,2.6236236236236223,1.9079079079079033,1.4324324324324298,0.8718718718718694,0.5915915915915875,0.4464464464464406,0.25125125125124725,0.1611611611611572};

//-----------------------------

Float_t Ef_5[29] = {0.6379334530355737,0.668580032169977,  0.6960891033554032, 0.7279429918078776, 0.7406510679684283, 0.7606058055586727, 0.7803884711779446, 0.7968643623985338, 0.814169752740059,  0.8301630943029213, 0.8484653798675793, 0.8642660756368531, 0.8713752665245204, 0.8914534470504619, 0.9156716417910448, 0.9364558785022258, 0.9566575019638647, 0.9775820147383384, 0.9953577974787714, 1.0151694534844573, 1.0340898889013581, 1.0509576179254108, 1.068365877380017,  1.0858021920472822, 1.1010819960348632, 1.1215464033217373, 1.144417012680956,  1.1661813114876742, 1.1896990610855496};

Float_t Xsec_5[29] = {1.5304773126846953,1.580069576927392,1.4627800845397072,1.538585269143006,1.340450005611042,1.3019769573186686,0.6172427336999213,0.6217502712003888,0.8313320614970259,0.42567238993004786,0.48261511988927275,0.4132065237721161,0.45601877828900506,.5224722253394685,0.6079377548348486,0.7745389593386447,0.9459189017319414,1.2317547600344136,1.3411700894026106,1.1810776942355874,0.7634477986009784,0.6010174690457486,0.3980380054614141,0.21890547263681448,0.20673886208057546,0.10148505592338886,0.04150301125948985,0.0411569969700345,0.031244155164028342};

//----------------
Float_t Ef_6[25] = {0.740660290538158,0.7679750058056026, 0.7842797182347528, 0.8041886347802903, 0.820607739083317,  0.8383352541993861, 0.8532266249236674, 0.8599869266429857, 0.8820202637033724, 0.9035773263264729, 0.9253225334789753, 0.9449239681078899, 0.9652005728194589, 0.9838225807838855, 1.0046012626110592, 1.0221008540686527, 1.0399939363705957, 1.056399064222867,  1.0715495368419248, 1.0873440013073359, 1.1095773091246874, 1.1296797457576098, 1.1538514797836017, 1.1758729906164267, 1.195852864527338};

Float_t Xsec_6[25] = {0.452324391271814,0.4805043563521889,0.34285738859693593,.3209824513117794,0.305174010395612,0.3565098723914204,0.252989526979567,0.220288932658763,0.17541520809860023,0.14143308075378158,0.18065028483289858,0.24105148781110053,0.2536575296515773,0.27776583209337113,0.2818999945527678,0.20075057124262807,0.15650184489149943,0.08382716792669731,0.0601603779805675,0.0413301567369353,0.015209245386337056,0.011482191851513779,0.00047591606675378983,0.010048709722735527,0.};

//-----------------------------

Float_t Xsec_bosted[6][50] = {{0.083083,0.089221,0.089869,0.098420,0.108537,0.110471,0.126164,0.132348,0.154305,0.163509,0.188840,0.206849,0.241389,0.266056,0.320563,0.353200,0.414157,0.466270,0.526497,0.598294,0.679229,0.723103,0.765737,0.770190,0.767005,0.711253,0.639205,0.578420,0.480376,0.380449,0.321317,0.248951,0.217057,0.168802,0.121701,0.103553,0.080116,0.070390,0.055147,0.053447,0.033994,0.023844,0.022247,0.018251,0.018140,0.012575,0.012497,0.008958,0.008901,0.006589},
{0.051972,0.053180,0.051685,0.054047,0.053785,0.057901,0.058553,0.063695,0.066751,0.076277,0.081288,0.093183,0.100649,0.114202,0.131665,0.149823,0.178745,0.201830,0.232668,0.259196,0.295412,0.321941,0.340612,0.345525,0.343622,0.318220,0.290813,0.258121,0.214095,0.178531,0.154634,0.113272,0.096261,0.076785,0.059804,0.050530,0.037832,0.029395,0.025513,0.020582,0.018600,0.012842,0.011939,0.009685,0.006597,0.006550,0.004612,0.004579,0.003877,0.002867},
{0.021050,0.020404,0.020546,0.020064,0.020587,0.020584,0.021740,0.022137,0.024098,0.025016,0.028281,0.030717,0.033203,0.038691,0.043388,0.051558,0.057886,0.069157,0.073721,0.090810,0.101711,0.110436,0.118774,0.122715,0.121813,0.113790,0.104556,0.091009,0.077232,0.064339,0.054235,0.043429,0.032695,0.027497,0.021872,0.018604,0.014649,0.011893,0.010387,0.007592,0.006012,0.005230,0.003939,0.003470,0.002832,0.002092,0.001899,0.001562,0.001548,0.001125},
{0.010688,0.010326,0.009886,0.009762,0.009500,0.009656,0.009682,0.010192,0.010287,0.010811,0.011898,0.012809,0.014644,0.016043,0.018893,0.021039,0.025011,0.028209,0.032467,0.038148,0.042934,0.048357,0.051390,0.053556,0.053078,0.050021,0.046214,0.040262,0.034259,0.028517,0.023414,0.019263,.015301,0.013131,0.009610,0.007752,0.006431,0.005203,0.004432,0.003551,0.002662,0.002326,0.001900,0.001440,0.001269,0.001041,0.000938,0.000705,0.000593,0.000550},
{0.006733,0.005999,0.005379,0.004862,0.004464,0.004112,0.003931,0.003732,0.003650,0.003730,0.003787,0.004089,0.004388,0.004762,0.005445,0.006321,0.007276,0.008322,0.009846,0.011261,0.012727,0.014366,0.015610,0.016398,0.016213,0.015401,0.014050,0.012212,0.010367,0.008610,0.007053,0.005790,0.004588,0.003929,0.002958,0.002309,0.001912,0.001543,0.001249,0.001049,0.000864,0.000669,0.000569,0.000467,0.000385,0.000332,0.000263,0.000219,0.000196,0.000154},
{0.004041,0.003765,0.003460,0.003137,0.002811,0.002494,0.002220,0.001959,0.001757,0.001583,0.001444,0.001368,0.001331,0.001313,0.001396,0.001470,0.001581,0.001837,0.002110,0.002425,0.002790,0.003139,0.003475,0.003670,0.003613,0.003385,0.003057,0.002590,0.002174,0.001751,0.001391,0.001095,0.000893,0.000709,0.000550,0.000439,0.000345,0.000278,0.000222,0.000187,0.000151,0.000123,0.000100,0.000081,0.000067,0.000055,0.000048,0.000039,0.000033,0.000028}};

Float_t Xsec_bosted2[6][50] = {{0.129857,0.134864,0.140700,0.147462,0.155253,0.164185,0.174377,0.185955,0.199051,0.213802,0.230348,0.248825,0.269359,0.292053,0.316977,0.344137,0.373448,0.404684,0.437407,0.470874,0.503907,0.534744,0.560906,0.579162,0.585763,0.577113,0.550911,0.507414,0.450062,0.384809,0.318352,0.256266,0.201990,0.156833,0.120573,0.092160,0.070252,0.053526,0.040827,0.031207,0.023923,0.018400,0.014202,0.011003,0.008556,0.006679,0.005232,0.004114,0.003246,0.002570},
{0.074288,0.075008,0.076115,0.077674,0.079745,0.082392,0.085680,0.089674,0.094440,0.100044,0.106551,0.114024,0.122519,0.132082,0.142744,0.154507,0.167333,0.181120,0.195669,0.210643,0.225503,0.239437,0.251289,0.259539,0.262407,0.258175,0.245754,0.225309,0.198560,0.168412,0.138054,0.110048,0.085883,0.066036,0.050294,0.038100,0.028798,0.021766,0.016475,0.012501,0.009516,0.007270,0.005575,0.004291,0.003316,0.002573,0.002004,0.001566,0.001229,0.000967},
{0.029671,0.029724,0.029912,0.030241,0.030721,0.031387,0.032266,0.033389,0.034714,0.036408,0.038425,0.040794,0.043541,0.046691,0.050256,0.054244,0.058643,0.063423,0.068517,0.073813,0.079125,0.084172,0.088541,0.091682,0.092930,0.091620,0.087299,0.079981,0.070284,0.059307,0.048268,0.038142,0.029478,0.022435,0.016911,0.012680,0.009488,0.007102,0.005325,0.004004,0.003021,0.002288,0.001740,0.001328,0.001018,0.000784,0.000606,0.000470,0.000366,0.000286},
{0.014842,0.014563,0.014392,0.014319,0.014364,0.014513,0.014770,0.015136,0.015622,0.016246,0.017016,0.017946,0.019048,0.020333,0.021811,0.023471,0.025334,0.027374,0.029565,0.031859,0.034181,0.036408,0.038364,0.039806,0.040437,0.039949,0.038121,0.034937,0.030664,0.025798,0.020898,0.016415,0.012600,0.009519,0.007121,0.005299,0.003936,0.002924,0.002177,0.001626,0.001218,0.000917,0.000693,0.000526,0.000400,0.000306,0.000235,0.000182,0.000141,0.000109},
{0.008087,0.007435,0.006853,0.006407,0.006034,0.005763,0.005584,0.005475,0.005453,0.005500,0.005616,0.005805,0.006062,0.006387,0.006781,0.007245,0.007778,0.008373,0.009023,0.009713,0.010418,0.011100,0.011702,0.012148,0.012341,0.012181,0.011597,0.010583,0.009229,0.007699,0.006175,0.004798,0.003641,0.002721,0.002013,0.001483,0.001090,0.000803,0.000592,0.000438,0.000326,0.000243,0.000182,0.000137,0.000104,0.000079,0.000060,0.000046,0.000035,0.000027},
{0.004350,0.004086,0.003796,0.003484,0.003175,0.002879,0.002610,0.002367,0.002170,0.002009,0.001885,0.001801,0.001750,0.001732,0.001744,0.001784,0.001851,0.001944,0.002060,0.002195,0.002342,0.002490,0.002624,0.002722,0.002756,0.002699,0.002529,0.002253,0.001902,0.001527,0.001174,0.000875,0.000638,0.000459,0.000328,0.000234,0.000167,0.000120,0.000086,0.000062,0.000045,0.000033,0.000024,0.000018,0.000013,0.000010,0.000007,0.000005,0.000004,0.000003}};

//0.000522,0.000516,0.000509,0.000503,0.000497,0.000491,0.000485,0.000478,0.000472,0.000466,0.000461,0.000455,0.000449,0.000443,0.000437,0.000431,0.000426,0.000420,0.000415,0.000409,0.000404,0.000398,0.000393,0.000388,0.000382,0.000377,0.000372,0.000367,0.000362,0.000357,0.000352,0.000347,0.000342,0.000338,0.000333,0.000328,0.000324,0.000319,0.000314,0.000310,0.000306,0.000301,0.000297,0.000293,0.000289,0.000284,0.000280,0.000276,0.000272,0.000268


TH1F *h_bosted[6];
TH1F *h_bosted2[6];


for(j=0; j<6; j++){
qqq.str("");
qqq << "bosted_" <<j+1;
h_bosted[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),50, 0.804,1.204);

qqq.str("");
qqq << "bosted2_" <<j+1;
h_bosted2[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),50, 0.804,1.204);
};

for(j=0; j<6; j++){
for(k=1; k<=50; k++){

h_bosted[j]->SetBinContent(k, 0.);
h_bosted[j]->SetBinContent(k, Xsec_bosted[j][k-1]);

h_bosted2[j]->SetBinContent(k, 0.);
h_bosted2[j]->SetBinContent(k, Xsec_bosted2[j][k-1]);

};
};

for(j=0; j<24; j++){
Xsec_1[j] = 10.*Xsec_1[j];
};
for(j=0; j<25; j++){
Xsec_2[j] = 10.*Xsec_2[j];
};
for(j=0; j<21; j++){
Xsec_3[j] = 10.*Xsec_3[j];
};
for(j=0; j<31; j++){
Xsec_4[j] = 10.*Xsec_4[j];
};
for(j=0; j<29; j++){
Xsec_5[j] = 10.*Xsec_5[j];
};
for(j=0; j<25; j++){
Xsec_6[j] = 10.*Xsec_6[j];
};


TGraphErrors * gr_1 = new TGraphErrors(24, Ef_1,Xsec_1, 0, 0);
TGraphErrors * gr_2 = new TGraphErrors(25, Ef_2,Xsec_2, 0, 0);
TGraphErrors * gr_3 = new TGraphErrors(21, Ef_3,Xsec_3, 0, 0);

TGraphErrors * gr_4 = new TGraphErrors(31, Ef_4,Xsec_4, 0, 0);
TGraphErrors * gr_5 = new TGraphErrors(29, Ef_5,Xsec_5, 0, 0);
TGraphErrors * gr_6 = new TGraphErrors(25, Ef_6,Xsec_6, 0, 0);


c->cd(1);
c->cd(1)->SetLeftMargin(0.15);
c->cd(1)->SetBottomMargin(0.13);
qqq.str("");
qqq << "E_{beam} = 0.449 GeV,   #theta_{e'} = 90^{o}";
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

//Kocevar
TLine *line_31 = new TLine(0.8,1000*Xsec_Kocevar[0],1.2,1000*Xsec_Kocevar[0]);
line_31->SetLineColor(kRed);
line_31->SetLineStyle(2);
line_31->SetLineWidth(2);
line_31->Draw("same");

//Durand
TLine *line_311 = new TLine(0.8,1000*Xsec_Durand[0],1.2,1000*Xsec_Durand[0]);
line_311->SetLineColor(kGreen+1);
line_311->SetLineStyle(2);
line_311->SetLineWidth(2);
line_311->Draw("same");


TLine *line_3121 = new TLine(Left_limit[0],0.,Left_limit[0],h_bosted[0]->GetMaximum());
line_3121->SetLineColor(43);
//line_3121->SetLineStyle(2);
line_3121->SetLineWidth(2);
line_3121->Draw("same");


TLine *line_313 = new TLine(Right_limit[0],0.,Right_limit[0],h_bosted[0]->GetMaximum());
line_313->SetLineColor(43);
//line_312->SetLineStyle(2);
line_313->SetLineWidth(2);
line_313->Draw("same");

Integral1 = 0.;
Integral2 =0.;

h_bosted[0]->Scale(1000*Xsec_Durand[0]/h_bosted[0]->GetMaximum());
h_bosted2[0]->Scale(1000*Xsec_Durand[0]/h_bosted2[0]->GetMaximum());

nl = h_bosted[0]->GetXaxis()->FindBin(Left_limit[0]);
nr = h_bosted[0]->GetXaxis()->FindBin(Right_limit[0]);
w = h_bosted[0]->GetBinWidth(1);

//cout << nl<<" "<< nr<<" \n";

Integral1 = w*h_bosted[0]->Integral(nl+1,nr-1)+ h_bosted[0]->GetBinContent(nl)*(h_bosted[0]->GetBinLowEdge(nl)+w -Left_limit[0]) + h_bosted[0]->GetBinContent(nr)*(Right_limit[0] - h_bosted[0]->GetBinLowEdge(nr));


//cout << Integral1<<" "<< h_bosted[0]->Integral(,nr-1)


Integral2 = w*h_bosted2[0]->Integral(nl+1,nr-1)+ h_bosted2[0]->GetBinContent(nl)*(h_bosted2[0]->GetBinLowEdge(nl)+w -Left_limit[0] ) + h_bosted2[0]->GetBinContent(nr)*(Right_limit[0] - h_bosted2[0]->GetBinLowEdge(nr));

//cout << "test left  "<<Left_limit[0]<<" "<<h_bosted[0]->GetBinLowEdge(nl) <<" "<< h_bosted[0]->GetBinLowEdge(nl)+w -Left_limit[0] <<" bb\n";
//cout << "test right "<<Right_limit[0]<<" "<<h_bosted[0]->GetBinLowEdge(nr) <<" "<< Right_limit[0] - h_bosted[0]->GetBinLowEdge(nr) <<" bb\n";

cout << Integral_data[0]/Integral1 << " ";
cout << Integral_data[0]/Integral2 << endl;

cout << endl;
cout << "-----------------------"<<endl;

TLegend*leg1 =  new TLegend(0.67,0.75,0.99,0.9);
leg1->SetHeader("#splitline{Q^{2}    = 0.273 GeV^{2} }{E'_{peak} = 0.304 GeV }");
//leg1->SetHeader("#splitline{Q^{2}    = 0.273 GeV^{2} }{#splitline{E'_{peak} = 0.304 GeV }{#theta = 90^{o}}}");
leg1->SetTextSize(.045);
leg1->Draw();



c->cd(2);
c->cd(2)->SetLeftMargin(0.15);
c->cd(2)->SetBottomMargin(0.13);
qqq.str("");
qqq << "E_{beam} = 0.557 GeV,   #theta_{e'} = 90^{o}";
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

//Kocevar
TLine *line_41 = new TLine(0.8,1000*Xsec_Kocevar[1],1.2,1000*Xsec_Kocevar[1]);
line_41->SetLineColor(kRed);
line_41->SetLineStyle(2);
line_41->SetLineWidth(2);
line_41->Draw("same");

//Durand
//old 0.278318
TLine *line_411 = new TLine(0.8,1000*Xsec_Durand[1],1.2,1000*Xsec_Durand[1]);
line_411->SetLineColor(kGreen+1);
line_411->SetLineStyle(2);
line_411->SetLineWidth(2);
line_411->Draw("same");


TLine *line_4121 = new TLine(Left_limit[1],0.,Left_limit[1],h_bosted[1]->GetMaximum());
line_4121->SetLineColor(43);
//line_4121->SetLineStyle(2);
line_4121->SetLineWidth(2);
line_4121->Draw("same");


TLine *line_413 = new TLine(Right_limit[1],0.,Right_limit[1],h_bosted[1]->GetMaximum());
line_413->SetLineColor(43);
//line_413->SetLineStyle(2);
line_413->SetLineWidth(2);
line_413->Draw("same");

Integral1 = 0.;
Integral2 = 0.;

h_bosted[1]->Scale(1000*Xsec_Durand[1]/h_bosted[1]->GetMaximum());
h_bosted2[1]->Scale(1000*Xsec_Durand[1]/h_bosted2[1]->GetMaximum());

nl = h_bosted[1]->GetXaxis()->FindBin(Left_limit[1]);
nr = h_bosted[1]->GetXaxis()->FindBin(Right_limit[1]);
w = h_bosted[1]->GetBinWidth(1);

Integral1 = w*h_bosted[1]->Integral(nl+1,nr-1)+ h_bosted[1]->GetBinContent(nl)*(h_bosted[1]->GetBinLowEdge(nl)+w -Left_limit[1]) + h_bosted[1]->GetBinContent(nr)*(Right_limit[1] - h_bosted[1]->GetBinLowEdge(nr));

Integral2 = w*h_bosted2[1]->Integral(nl+1,nr-1)+ h_bosted2[1]->GetBinContent(nl)*(h_bosted2[1]->GetBinLowEdge(nl)+w -Left_limit[1] ) + h_bosted2[1]->GetBinContent(nr)*(Right_limit[1] - h_bosted2[1]->GetBinLowEdge(nr));

//cout << nl<<" "<< nr<<" \n";

//cout << "test left  "<<Left_limit[1]<<" "<<h_bosted[1]->GetBinLowEdge(nl) <<" "<< h_bosted[1]->GetBinLowEdge(nl)+w -Left_limit[1] <<" bb\n";
//cout << "test right "<<Right_limit[1]<<" "<<h_bosted[1]->GetBinLowEdge(nr) <<" "<< Right_limit[1] - h_bosted[1]->GetBinLowEdge(nr) <<" bb\n";

cout << Integral_data[1]/Integral1 << " ";
cout << Integral_data[1]/Integral2 << endl;

cout << endl;
cout << "-----------------------"<<endl;



TLegend*leg2 = new TLegend(0.67,0.75,0.99,0.9);
leg2->SetHeader("#splitline{Q^{2}    = 0.389 GeV^{2} }{E'_{peak} = 0.350 GeV }");
leg2->SetTextSize(.045);
leg2->Draw();



c->cd(3);
c->cd(3)->SetLeftMargin(0.15);
c->cd(3)->SetBottomMargin(0.13);
qqq.str("");
qqq << "E_{beam} = 0.718 GeV,   #theta_{e'} = 90^{o}";
h_bosted[2]->SetTitle(qqq.str().c_str());
h_bosted[2]->Scale(1000.);
h_bosted[2]->SetLineWidth(2);
h_bosted[2]->SetLineColor(kBlue);
h_bosted[2]->GetXaxis()->SetTitle("E'/E'_{peak}");
h_bosted[2]->GetXaxis()->SetTitleSize(0.06);
h_bosted[2]->GetXaxis()->SetLabelSize(0.05);
h_bosted[2]->GetXaxis()->SetNdivisions(6+400);
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

//Kocevar
TLine *line_51 = new TLine(0.8,1000*Xsec_Kocevar[2],1.2,1000*Xsec_Kocevar[2]);
line_51->SetLineColor(kRed);
line_51->SetLineStyle(2);
line_51->SetLineWidth(2);
line_51->Draw("same");

//Durand
TLine *line_511 = new TLine(0.8,1000*Xsec_Durand[2],1.2,1000*Xsec_Durand[2]);
line_511->SetLineColor(kGreen+1);
line_511->SetLineStyle(2);
line_511->SetLineWidth(2);
line_511->Draw("same");

TLine *line_5121 = new TLine(Left_limit[2],0.,Left_limit[2],h_bosted[2]->GetMaximum());
line_5121->SetLineColor(43);
//line_5121->SetLineStyle(2);
line_5121->SetLineWidth(2);
line_5121->Draw("same");

TLine *line_513 = new TLine(Right_limit[2],0.,Right_limit[2],h_bosted[2]->GetMaximum());
line_513->SetLineColor(43);
//line_513->SetLineStyle(2);
line_513->SetLineWidth(2);
line_513->Draw("same");

Integral1 = 0.;
Integral2 = 0.;

h_bosted[2]->Scale(1000*Xsec_Durand[2]/h_bosted[2]->GetMaximum());
h_bosted2[2]->Scale(1000*Xsec_Durand[2]/h_bosted2[2]->GetMaximum());

nl = h_bosted[2]->GetXaxis()->FindBin(Left_limit[2]);
nr = h_bosted[2]->GetXaxis()->FindBin(Right_limit[2]);
w = h_bosted[2]->GetBinWidth(1);

Integral1 = w*h_bosted[2]->Integral(nl+1,nr-1)+ h_bosted[2]->GetBinContent(nl)*(h_bosted[2]->GetBinLowEdge(nl)+w -Left_limit[2]) + h_bosted[2]->GetBinContent(nr)*(Right_limit[2] - h_bosted[2]->GetBinLowEdge(nr));

Integral2 = w*h_bosted2[2]->Integral(nl+1,nr-1)+ h_bosted2[2]->GetBinContent(nl)*(h_bosted2[2]->GetBinLowEdge(nl)+w -Left_limit[2]) + h_bosted2[2]->GetBinContent(nr)*(Right_limit[2] - h_bosted2[2]->GetBinLowEdge(nr));

//cout << "test left  "<<Left_limit[2]<<" "<<h_bosted[2]->GetBinLowEdge(nl) <<" "<< h_bosted[2]->GetBinLowEdge(nl)+w -Left_limit[2] <<" bb\n";
//cout << "test right "<<Right_limit[2]<<" "<<h_bosted[2]->GetBinLowEdge(nr) <<" "<< Right_limit[2] - h_bosted[2]->GetBinLowEdge(nr) <<" bb\n";

cout << Integral_data[2]/Integral1 << " ";
cout << Integral_data[2]/Integral2 << endl;

cout << endl;
cout << "-----------------------"<<endl;

TLegend*leg3 =  new TLegend(0.67,0.75,0.99,0.9);
leg3->SetHeader("#splitline{Q^{2}    = 0.584 GeV^{2} }{E'_{peak} = 0.407 GeV }");
leg3->SetTextSize(.045);
leg3->Draw();


c->cd(4);
c->cd(4)->SetLeftMargin(0.15);
c->cd(4)->SetBottomMargin(0.13);
qqq.str("");
qqq << "E_{beam} = 0.865 GeV,   #theta_{e'} = 90^{o}";
h_bosted[3]->SetTitle(qqq.str().c_str());
h_bosted[3]->Scale(1000.);
h_bosted[3]->SetLineWidth(2);
h_bosted[3]->SetLineColor(kBlue);
h_bosted[3]->GetXaxis()->SetTitle("E'/E'_{peak}");
h_bosted[3]->GetXaxis()->SetTitleSize(0.06);
h_bosted[3]->GetXaxis()->SetLabelSize(0.05);
h_bosted[3]->GetXaxis()->SetNdivisions(6+400);
h_bosted[3]->GetYaxis()->SetTitle("d^{2}#sigma/(d#Omega dE') (nb/GeV/sr)");
h_bosted[3]->GetYaxis()->SetTitleSize(0.055);
h_bosted[3]->GetYaxis()->SetLabelSize(0.05);
h_bosted[3]->Draw("hist");

h_bosted2[3]->Scale(1000.);
h_bosted2[3]->SetLineWidth(2);
h_bosted2[3]->SetLineColor(kGreen+2);
h_bosted2[3]->Draw("same hist");

gr_4->SetMarkerStyle(20);
gr_4->Draw("same p");

//Kocevar
TLine *line_61 = new TLine(0.8,1000*Xsec_Kocevar[3],1.2,1000*Xsec_Kocevar[3]);
line_61->SetLineColor(kRed);
line_61->SetLineStyle(2);
line_61->SetLineWidth(2);
line_61->Draw("same");


//Durand
TLine *line_611 = new TLine(0.8,1000*Xsec_Durand[3],1.2,1000*Xsec_Durand[3]);
line_611->SetLineColor(kGreen+1);
line_611->SetLineStyle(2);
line_611->SetLineWidth(2);
line_611->Draw("same");

TLine *line_6121 = new TLine(Left_limit[3],0.,Left_limit[3],h_bosted[3]->GetMaximum());
line_6121->SetLineColor(43);
//line_6121->SetLineStyle(2);
line_6121->SetLineWidth(2);
line_6121->Draw("same");

TLine *line_613 = new TLine(Right_limit[3],0.,Right_limit[3],h_bosted[3]->GetMaximum());
line_613->SetLineColor(43);
//line_613->SetLineStyle(2);
line_613->SetLineWidth(2);
line_613->Draw("same");

Integral1 = 0.;
Integral2 = 0.;

h_bosted[3]->Scale(1000*Xsec_Durand[3]/h_bosted[3]->GetMaximum());
h_bosted2[3]->Scale(1000*Xsec_Durand[3]/h_bosted2[3]->GetMaximum());

nl = h_bosted[3]->GetXaxis()->FindBin(Left_limit[3]);
nr = h_bosted[3]->GetXaxis()->FindBin(Right_limit[3]);
w = h_bosted[3]->GetBinWidth(1);

Integral1 = w*h_bosted[3]->Integral(nl+1,nr-1)+ h_bosted[3]->GetBinContent(nl)*(h_bosted[3]->GetBinLowEdge(nl)+w -Left_limit[3]) + h_bosted[3]->GetBinContent(nr)*(Right_limit[3] - h_bosted[3]->GetBinLowEdge(nr));

Integral2 = w*h_bosted2[3]->Integral(nl+1,nr-1)+ h_bosted2[3]->GetBinContent(nl)*(h_bosted2[3]->GetBinLowEdge(nl)+w -Left_limit[3] ) + h_bosted2[3]->GetBinContent(nr)*(Right_limit[3] - h_bosted2[3]->GetBinLowEdge(nr));

//cout << "test left  "<<Left_limit[3]<<" "<<h_bosted[3]->GetBinLowEdge(nl) <<" "<< h_bosted[3]->GetBinLowEdge(nl)+w -Left_limit[3] <<" bb\n";
//cout << "test right "<<Right_limit[3]<<" "<<h_bosted[3]->GetBinLowEdge(nr) <<" "<< Right_limit[3] - h_bosted[3]->GetBinLowEdge(nr) <<" bb\n";

cout << Integral_data[3]/Integral1 << " ";
cout << Integral_data[3]/Integral2 << endl;

cout << endl;
cout << "-----------------------"<<endl;

TLegend*leg4 = new TLegend(0.67,0.75,0.99,0.9);
leg4->SetHeader("#splitline{Q^{2}    = 0.779 GeV^{2} }{E'_{peak} = 0.450 GeV }");
leg4->SetTextSize(.045);
leg4->Draw();



c->cd(5);
c->cd(5)->SetLeftMargin(0.15);
c->cd(5)->SetBottomMargin(0.13);
qqq.str("");
qqq << "E_{beam} = 1.104 GeV,   #theta_{e'} = 90^{o}";
h_bosted[4]->SetTitle(qqq.str().c_str());
h_bosted[4]->Scale(1000.);
h_bosted[4]->SetLineWidth(2);
h_bosted[4]->SetLineColor(kBlue);
h_bosted[4]->GetXaxis()->SetTitle("E'/E'_{peak}");
h_bosted[4]->GetXaxis()->SetTitleSize(0.06);
h_bosted[4]->GetXaxis()->SetLabelSize(0.05);
h_bosted[4]->GetXaxis()->SetNdivisions(6+400);
h_bosted[4]->GetYaxis()->SetTitle("d^{2}#sigma/(d#Omega dE') (nb/GeV/sr)");
h_bosted[4]->GetYaxis()->SetTitleSize(0.055);
h_bosted[4]->GetYaxis()->SetLabelSize(0.05);
h_bosted[4]->Draw("hist");

h_bosted2[4]->Scale(1000.);
h_bosted2[4]->SetLineWidth(2);
h_bosted2[4]->SetLineColor(kGreen+2);
h_bosted2[4]->Draw("same hist");

gr_5->SetMarkerStyle(20);
gr_5->Draw("same p");

//Kocevar
TLine *line_71 = new TLine(0.8,1000*Xsec_Kocevar[4],1.2,1000*Xsec_Kocevar[4]);
line_71->SetLineColor(kRed);
line_71->SetLineStyle(2);
line_71->SetLineWidth(2);
line_71->Draw("same");

//Durand
TLine *line_72 = new TLine(0.8,1000*Xsec_Durand[4],1.2,1000*Xsec_Durand[4]);
line_72->SetLineColor(kGreen+1);
line_72->SetLineStyle(2);
line_72->SetLineWidth(2);
line_72->Draw("same");


TLine *line_7121 = new TLine(Left_limit[4],0.,Left_limit[4],h_bosted[4]->GetMaximum());
line_7121->SetLineColor(43);
//line_7121->SetLineStyle(2);
line_7121->SetLineWidth(2);
line_7121->Draw("same");


TLine *line_713 = new TLine(Right_limit[4],0.,Right_limit[4],h_bosted[4]->GetMaximum());
line_713->SetLineColor(43);
//line_713->SetLineStyle(2);
line_713->SetLineWidth(2);
line_713->Draw("same");

Integral1 = 0.;
Integral2 = 0.;

h_bosted[4]->Scale(1000*Xsec_Durand[4]/h_bosted[4]->GetMaximum());
h_bosted2[4]->Scale(1000*Xsec_Durand[4]/h_bosted2[4]->GetMaximum());

nl = h_bosted[4]->GetXaxis()->FindBin(Left_limit[4]);
nr = h_bosted[4]->GetXaxis()->FindBin(Right_limit[4]);
w = h_bosted[4]->GetBinWidth(1);

Integral1 = w*h_bosted[4]->Integral(nl+1,nr-1)+ h_bosted[4]->GetBinContent(nl)*(h_bosted[4]->GetBinLowEdge(nl)+w -Left_limit[4]) + h_bosted[4]->GetBinContent(nr)*(Right_limit[4] - h_bosted[4]->GetBinLowEdge(nr));

Integral2 = w*h_bosted2[4]->Integral(nl+1,nr-1)+ h_bosted2[4]->GetBinContent(nl)*(h_bosted2[4]->GetBinLowEdge(nl)+w -Left_limit[4] ) + h_bosted2[4]->GetBinContent(nr)*(Right_limit[4] - h_bosted2[4]->GetBinLowEdge(nr));

//cout << "test left  "<<Left_limit[4]<<" "<<h_bosted[4]->GetBinLowEdge(nl) <<" "<< h_bosted[4]->GetBinLowEdge(nl)+w -Left_limit[4] <<" bb\n";
//cout << "test right "<<Right_limit[4]<<" "<<h_bosted[4]->GetBinLowEdge(nr) <<" "<< Right_limit[4] - h_bosted[4]->GetBinLowEdge(nr) <<" bb\n";

cout << Integral_data[4]/Integral1 << " ";
cout << Integral_data[4]/Integral2 << endl;

cout << endl;
cout << "-----------------------"<<endl;


TLegend*leg5 = new TLegend(0.67,0.75,0.99,0.9);
leg5->SetHeader("#splitline{Q^{2}    = 1.120 GeV^{2} }{E'_{peak} = 0.507 GeV }");
leg5->SetTextSize(.045);
leg5->Draw();



c->cd(6);
c->cd(6)->SetLeftMargin(0.15);
c->cd(6)->SetBottomMargin(0.13);
qqq.str("");
qqq << "E_{beam} = 1.598 GeV,   #theta_{e'} = 80^{o}";
h_bosted[5]->SetTitle(qqq.str().c_str());
h_bosted[5]->Scale(1000.);
h_bosted[5]->SetLineWidth(2);
h_bosted[5]->SetLineColor(kBlue);
h_bosted[5]->GetXaxis()->SetTitle("E'/E'_{peak}");
h_bosted[5]->GetXaxis()->SetTitleSize(0.06);
h_bosted[5]->GetXaxis()->SetLabelSize(0.05);
h_bosted[5]->GetXaxis()->SetNdivisions(6+400);
h_bosted[5]->GetYaxis()->SetTitle("d^{2}#sigma/(d#Omega dE') (nb/GeV/sr)");
h_bosted[5]->GetYaxis()->SetTitleSize(0.055);
h_bosted[5]->GetYaxis()->SetLabelSize(0.05);
h_bosted[5]->Draw("hist");

h_bosted2[5]->Scale(1000.);
h_bosted2[5]->SetLineWidth(2);
h_bosted2[5]->SetLineColor(kGreen+2);
h_bosted2[5]->Draw("same hist");

gr_6->SetMarkerStyle(20);
gr_6->Draw("same p");


//Kocevar
TLine *line_81 = new TLine(0.8,1000*Xsec_Kocevar[5],1.2,1000*Xsec_Kocevar[5]);
line_81->SetLineColor(kRed);
line_81->SetLineStyle(2);
line_81->SetLineWidth(2);
line_81->Draw("same");

//Durand
//old 0.00265517
TLine *line_82 = new TLine(0.8,1000*Xsec_Durand[5],1.2,1000*Xsec_Durand[5]);
line_82->SetLineColor(kGreen+1);
line_82->SetLineStyle(2);
line_82->SetLineWidth(2);
line_82->Draw("same");

TLine *line_8121 = new TLine(Left_limit[5],0.,Left_limit[5],h_bosted[5]->GetMaximum());
line_8121->SetLineColor(43);
//line_8121->SetLineStyle(2);
line_8121->SetLineWidth(2);
line_8121->Draw("same");


TLine *line_813 = new TLine(Right_limit[5],0.,Right_limit[5],h_bosted[5]->GetMaximum());
line_813->SetLineColor(43);
//line_813->SetLineStyle(2);
line_813->SetLineWidth(2);
line_813->Draw("same");

Integral1 = 0.;
Integral2 = 0.;

h_bosted[5]->GetXaxis()->SetRangeUser(0.9,1.2);
h_bosted2[5]->GetXaxis()->SetRangeUser(0.9,1.2);
h_bosted[5]->Scale(1000.*Xsec_Durand[5]/h_bosted[5]->GetMaximum());
h_bosted2[5]->Scale(1000.*Xsec_Durand[5]/h_bosted2[5]->GetMaximum());

nl = h_bosted[5]->GetXaxis()->FindBin(Left_limit[5]);
nr = h_bosted[5]->GetXaxis()->FindBin(Right_limit[5]);
w = h_bosted[5]->GetBinWidth(1);

Integral1 = w*h_bosted[5]->Integral(nl+1,nr-1)+ h_bosted[5]->GetBinContent(nl)*(h_bosted[5]->GetBinLowEdge(nl)+w -Left_limit[5]) + h_bosted[5]->GetBinContent(nr)*(Right_limit[5] - h_bosted[5]->GetBinLowEdge(nr));

Integral2 = w*h_bosted2[5]->Integral(nl+1,nr-1)+ h_bosted2[5]->GetBinContent(nl)*(h_bosted2[5]->GetBinLowEdge(nl)+w -Left_limit[5] ) + h_bosted2[5]->GetBinContent(nr)*(Right_limit[5] - h_bosted2[5]->GetBinLowEdge(nr));

//cout << "test left  "<<Left_limit[5]<<" "<<h_bosted[5]->GetBinLowEdge(nl) <<" "<< h_bosted[5]->GetBinLowEdge(nl)+w -Left_limit[5] <<" bb\n";
//cout << "test right "<<Right_limit[5]<<" "<<h_bosted[5]->GetBinLowEdge(nr) <<" "<< Right_limit[5] - h_bosted[5]->GetBinLowEdge(nr) <<" bb\n";

cout << Integral_data[5]/Integral1 << " ";
cout << Integral_data[5]/Integral2 << endl;

cout << endl;
cout << "-----------------------"<<endl;

TLegend*leg6 = new TLegend(0.67,0.75,0.99,0.9); 
leg6->SetHeader("#splitline{Q^{2}    = 1.752 GeV^{2} }{E'_{peak} = 0.664 GeV }");
leg6->SetTextSize(.045);
leg6->Draw();


};
