void quasiel_peak_new(){
gStyle->SetOptStat(0);
gStyle->SetTitleY(0.975);
gStyle->SetTitleSize(0.25);



TCanvas *c2 = new TCanvas("c2","c2",0,0,600,800);
c2 -> Divide (3,4);

TCanvas *c = new TCanvas("c","c",0,0,1000,250);
c -> Divide (2,1);

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

TH1F *h_bosted[13];
TH1F *h_bosted_skor[13];

TH1F *h_ratio = new TH1F("h_ratio","h_ratio",13,22.,48.);
TH1F *h_ratio2 = new TH1F("h_ratio2","h_ratio2",13,22.,48.);
//TH1F *h_ratio3 = new TH1F("h_ratio3","h_ratio3",13,22.,48.);


for(j=0; j<13; j++){
qqq.str("");
qqq << "bosted_" <<j+1;
h_bosted[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),40, 0.805,1.205);

qqq.str("");
qqq << "bosted_skor_" <<j+1;
h_bosted_skor[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),40, 0.805,1.205);
};

//TH1F *h_bosted = new TH1F("h_bosted","h_bosted",40,0.805*Epeak[0],1.205*Epeak[0]); 
//TH1F *h_bosted2 = new TH1F("h_bosted2","h_bosted2",40,0.805*Epeak[1],1.205*Epeak[1]);
////TH1F *h_bosted3 = new TH1F("h_bosted3","h_bosted3",40,0.805*Epeak[2],1.205*Epeak[2]);
//TH1F *h_bosted4 = new TH1F("h_bosted4","h_bosted4",40,0.805*Epeak[3],1.205*Epeak[2]);

//Float_t Bosted_max[13] = {1.76354,0.977557,0.562603,0.336301,0.207163,0.131472,0.0858266,0.057567,0.0394164,0.0276667,0.0198342,0.0144601,0.0107435}; 

//Float_t Bosted_max[13] = {1.89975,1.0637,0.618521,0.373377,0.232327,0.148901,0.0981291,0.0664078,0.0458885,0.0324802,0.0234711,0.0172507,0.0129149};

//Float_t Bosted_max[13] = {1.8166,0.977403,0.562988,0.336074,0.207151,0.131536,0.0858658,0.0575282,0.0394379,0.0276645,0.0198163,0.0144612,0.0117111};

Float_t Bosted_max[13] = {1.8166,1.01359, 0.587575,0.353051,0.218836,0.139677,0.0916234,0.06167,0.0424369,0.0298789,0.0214749,0.0157149,0.0117111};

Float_t bosted[13][40]={{0.005437,0.006390,0.007651,0.009269,0.011321,0.013069,0.016454,0.021451,0.025645,0.034766,0.048376,0.064226,0.096703,0.138440,0.213572,0.337865,0.591832,1.065118,1.759547,2.042397,1.377923,0.733517,0.295493,0.136609,0.058942,0.027285,0.017667,0.009926,0.006868,0.004358,0.003279,0.002471,0.001611,0.001181,0.000853,0.000653,0.000378,0.000000,0.000000,0.000000},
{0.003809,0.004480,0.005330,0.006387,0.007818,0.008899,0.011264,0.014479,0.018918,0.023269,0.032330,0.042344,0.063785,0.090068,0.142822,0.225183,0.374050,0.651412,0.996427,1.154178,0.832855,0.451440,0.216091,0.111394,0.045482,0.023307,0.013147,0.008706,0.005555,0.003552,0.002615,0.001959,0.001480,0.001112,0.000770,0.000562,0.000433,0.000306,0.000210,0.000154},
{0.002736,0.003192,0.003802,0.004570,0.005542,0.006399,0.007896,0.010150,0.013362,0.016460,0.022513,0.031609,0.042939,0.065392,0.096127,0.149950,0.248594,0.404544,0.607696,0.678555,0.499632,0.286893,0.144452,0.075767,0.038292,0.019713,0.010673,0.006619,0.004004,0.002926,0.002060,0.001628,0.001219,0.000920,0.000739,0.000552,0.000408,0.000320,0.000229,0.000175},
{0.001962,0.002288,0.002691,0.003232,0.003937,0.004839,0.006006,0.007155,0.009202,0.012295,0.015656,0.021858,0.031371,0.043453,0.066068,0.099568,0.165529,0.253748,0.370615,0.413050,0.322941,0.199105,0.111593,0.057604,0.030264,0.017144,0.009482,0.005382,0.003481,0.002160,0.001605,0.001145,0.000911,0.000683,0.000589,0.000475,0.000357,0.000283,0.000208,0.000162},
{0.001464,0.001691,0.001991,0.002367,0.002877,0.003490,0.004353,0.005583,0.006711,0.008779,0.011927,0.016494,0.022007,0.032223,0.046683,0.072655,0.113112,0.168399,0.236027,0.259719,0.206704,0.131963,0.076331,0.040760,0.022943,0.013546,0.008145,0.004658,0.002867,0.001703,0.001209,0.000992,0.000764,0.000562,0.000452,0.000341,0.000314,0.000236,0.000189,0.000139},
{0.001095,0.001266,0.001495,0.001783,0.002144,0.002601,0.003236,0.004085,0.005223,0.006893,0.008628,0.011843,0.016800,0.022824,0.033859,0.050188,0.073669,0.114776,0.154745,0.168157,0.136190,0.089801,0.053378,0.030866,0.017985,0.010146,0.006147,0.003848,0.002321,0.001460,0.001205,0.000768,0.000577,0.000449,0.000383,0.000287,0.000231,0.000199,0.000161,0.000128},
{0.000873,0.001013,0.001186,0.001420,0.001688,0.002094,0.002395,0.003026,0.003863,0.005073,0.006677,0.009083,0.012193,0.017388,0.025496,0.037336,0.055099,0.080173,0.104205,0.111851,0.092159,0.062623,0.039327,0.023319,0.013399,0.008636,0.004997,0.002946,0.002031,0.001280,0.000848,0.000623,0.000454,0.000376,0.000292,0.000232,0.000199,0.000161,0.000122,0.000111},
{0.000667,0.000775,0.000908,0.001070,0.001273,0.001550,0.001906,0.002372,0.003052,0.003964,0.004974,0.006737,0.009278,0.013048,0.018021,0.025644,0.038826,0.056080,0.071187,0.076290,0.065098,0.044680,0.029179,0.017682,0.010864,0.006572,0.004398,0.002674,0.001898,0.001148,0.000750,0.000538,0.000382,0.000303,0.000231,0.000210,0.000155,0.000126,0.000107,0.000087},
{0.000552,0.000635,0.000746,0.000884,0.001055,0.001270,0.001481,0.001844,0.002367,0.003005,0.003929,0.005399,0.007293,0.009701,0.014020,0.020221,0.029450,0.040118,0.050286,0.053245,0.045368,0.031935,0.020853,0.013999,0.008126,0.005283,0.003346,0.002187,0.001447,0.000957,0.000627,0.000476,0.000330,0.000255,0.000191,0.000171,0.000125,0.000113,0.000087,0.000078},
{0.000427,0.000498,0.000576,0.000683,0.000815,0.000980,0.001209,0.001514,0.001914,0.002444,0.003150,0.004205,0.005528,0.007523,0.010722,0.015354,0.021631,0.028700,0.035921,0.037981,0.032897,0.023915,0.016036,0.010244,0.006608,0.004213,0.002776,0.001755,0.001222,0.000778,0.000564,0.000377,0.000291,0.000210,0.000164,0.000131,0.000104,0.000092,0.000074,0.000063},
{0.000358,0.000413,0.000479,0.000569,0.000669,0.000806,0.001000,0.001227,0.001551,0.001894,0.002439,0.003247,0.004360,0.006010,0.008333,0.011548,0.016199,0.021377,0.026181,0.027646,0.024336,0.018232,0.012219,0.008089,0.005437,0.003384,0.002260,0.001580,0.000993,0.000716,0.000465,0.000347,0.000250,0.000177,0.000144,0.000114,0.000089,0.000077,0.000060,0.000053},
{0.000287,0.000331,0.000384,0.000456,0.000537,0.000647,0.000788,0.000985,0.001220,0.001554,0.002001,0.002621,0.003561,0.004758,0.006573,0.009066,0.012346,0.016208,0.019637,0.020495,0.018019,0.013484,0.009302,0.006298,0.004130,0.003044,0.001775,0.001246,0.000900,0.000576,0.000423,0.000300,0.000206,0.000160,0.000131,0.000094,0.000076,0.000062,0.000051,0.000044},
{0.000246,0.000280,0.000331,0.000387,0.000455,0.000550,0.000671,0.000825,0.001023,0.001311,0.001657,0.002167,0.002863,0.003919,0.005259,0.007049,0.009602,0.012500,0.014988,0.015464,0.013580,0.010393,0.007409,0.004855,0.003373,0.002283,0.001516,0.001017,0.000722,0.000498,0.000346,0.000247,0.000188,0.000149,0.000105,0.000081,0.000068,0.000052,0.000043,0.000038}};

Float_t bosted_skor[13][40]={{0.022781,0.026394,0.030707,0.035890,0.042170,0.049848,0.059332,0.071189,0.086213,0.105547,0.130872,0.164708,0.210911,0.275459,0.367634,0.501467,0.696327,0.971735,1.316588,1.566347,1.288936,0.623177,0.222412,0.074844,0.025868,0.009335,0.003510,0.001367,0.000549,0.000226,0.000095,0.000041,0.000018,0.000008,0.000003,0.000002,0.000001,0.000000,0.000000,0.000000},
{0.016294,0.018745,0.021654,0.025130,0.029318,0.034411,0.040666,0.048440,0.058229,0.070738,0.086991,0.108494,0.137501,0.177395,0.233221,0.312192,0.423494,0.574844,0.756572,0.886707,0.764339,0.415888,0.166358,0.061017,0.022602,0.008669,0.003450,0.001420,0.000601,0.000261,0.000115,0.000052,0.000024,0.000011,0.000005,0.000002,0.000001,0.000001,0.000000,0.000000},
{0.011874,0.013579,0.015593,0.017991,0.020868,0.024350,0.028609,0.033876,0.040476,0.048861,0.059681,0.073874,0.092814,0.118498,0.153783,0.202524,0.269181,0.356478,0.456328,0.522805,0.456602,0.266994,0.116738,0.046180,0.018215,0.007383,0.003091,0.001335,0.000592,0.000269,0.000125,0.000059,0.000028,0.000014,0.000007,0.000003,0.000002,0.000001,0.000000,0.000000},
{0.008684,0.009876,0.011278,0.012939,0.014923,0.017314,0.020223,0.023802,0.028259,0.033883,0.041080,0.050429,0.062753,0.079217,0.101422,0.131422,0.171408,0.222332,0.279166,0.318027,0.288336,0.184317,0.088513,0.037643,0.015701,0.006671,0.002915,0.001310,0.000604,0.000285,0.000137,0.000067,0.000033,0.000017,0.000009,0.000004,0.000002,0.000001,0.000001,0.000000},
{0.006487,0.007343,0.008347,0.009532,0.010943,0.012637,0.014690,0.017206,0.020324,0.024235,0.029208,0.035613,0.043967,0.054981,0.069591,0.088930,0.114078,0.145161,0.178576,0.200245,0.182899,0.122584,0.062933,0.028447,0.012485,0.005541,0.002519,0.001175,0.000561,0.000274,0.000136,0.000069,0.000035,0.000018,0.000010,0.000005,0.000003,0.000001,0.000001,0.000000},
{0.004907,0.005532,0.006262,0.007121,0.008141,0.009362,0.010836,0.012634,0.014853,0.017621,0.021115,0.025579,0.031343,0.038844,0.048641,0.061365,0.077541,0.097001,0.117228,0.129735,0.119267,0.083166,0.045239,0.021595,0.009923,0.004580,0.002156,0.001039,0.000512,0.000258,0.000132,0.000069,0.000036,0.000019,0.000011,0.000006,0.000003,0.000002,0.000001,0.000001},
{0.003752,0.004214,0.004751,0.005383,0.006130,0.007020,0.008092,0.009394,0.010992,0.012975,0.015461,0.018611,0.022636,0.027811,0.034470,0.042971,0.053564,0.066020,0.078636,0.086266,0.080090,0.058040,0.033324,0.016733,0.008019,0.003835,0.001863,0.000924,0.000468,0.000242,0.000127,0.000068,0.000037,0.000020,0.000011,0.000006,0.000004,0.000002,0.000001,0.000001},
{0.002895,0.003239,0.003639,0.004108,0.004660,0.005315,0.006102,0.007053,0.008214,0.009646,0.011428,0.013668,0.016501,0.020102,0.024672,0.030418,0.037459,0.045594,0.053722,0.058736,0.055394,0.041860,0.025384,0.013395,0.006680,0.003300,0.001648,0.000838,0.000435,0.000230,0.000123,0.000067,0.000037,0.000021,0.000012,0.000007,0.000004,0.000002,0.000001,0.000001},
{0.002279,0.002542,0.002848,0.003205,0.003624,0.004122,0.004716,0.005432,0.006303,0.007372,0.008695,0.010344,0.012413,0.015014,0.018274,0.022310,0.027166,0.032651,0.037957,0.041019,0.038584,0.029612,0.018534,0.010141,0.005230,0.002661,0.001365,0.000711,0.000377,0.000204,0.000112,0.000062,0.000035,0.000020,0.000012,0.000007,0.000004,0.000002,0.000001,0.000001},
{0.001805,0.002007,0.002242,0.002515,0.002835,0.003213,0.003664,0.004205,0.004859,0.005658,0.006641,0.007857,0.009369,0.011251,0.013582,0.016430,0.019808,0.023564,0.027148,0.029220,0.027721,0.021855,0.014224,0.008092,0.004313,0.002256,0.001184,0.000630,0.000341,0.000187,0.000105,0.000059,0.000034,0.000020,0.000012,0.000007,0.000004,0.000003,0.000002,0.000001},
{0.001445,0.001603,0.001785,0.001996,0.002244,0.002535,0.002881,0.003295,0.003794,0.004399,0.005139,0.006048,0.007169,0.008550,0.010243,0.012288,0.014682,0.017310,0.019789,0.021234,0.020307,0.016400,0.011058,0.006521,0.003585,0.001924,0.001032,0.000560,0.000308,0.000172,0.000098,0.000056,0.000033,0.000019,0.000012,0.000007,0.000004,0.000003,0.000002,0.000001},
{0.001176,0.001301,0.001446,0.001613,0.001809,0.002039,0.002311,0.002635,0.003024,0.003494,0.004066,0.004764,0.005619,0.006662,0.007928,0.009439,0.011182,0.013062,0.014790,0.015745,0.015025,0.012244,0.008426,0.005098,0.002874,0.001577,0.000863,0.000477,0.000267,0.000152,0.000087,0.000051,0.000030,0.000018,0.000011,0.000007,0.000004,0.000003,0.000002,0.000001},
{0.000966,0.001066,0.001182,0.001316,0.001472,0.001655,0.001870,0.002127,0.002433,0.002802,0.003248,0.003790,0.004448,0.005244,0.006202,0.007332,0.008619,0.009986,0.011219,0.011875,0.011336,0.009337,0.006559,0.004068,0.002348,0.001316,0.000734,0.000412,0.000234,0.000135,0.000079,0.000047,0.000028,0.000017,0.000010,0.000006,0.000004,0.000003,0.000002,0.000001}};


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
Float_t Bosted_Qelast[13];
Float_t Bosted_Qelast_skor[13];

Float_t cut,nl,nr,w;
Float_t Gamma[40];

//Float_t rc[13] = {0.877593, 0.876729, 0.876000, 0.875389, 0.874882, 0.874469, 0.874140, 0.873885, 0.873698, 0.873571, 0.873500, 0.873478, 0.873501};

//Float_t rc_097[13] = {0.847895, 0.846657, 0.845572, 0.844621, 0.843789, 0.843063, 0.842432, 0.841885, 0.841415, 0.841014, 0.840677, 0.840397, 0.840168};

//new
//Float_t rc_097[13] = {0.825199, 0.823690, 0.822349, 0.821155, 0.820090, 0.819139,0.842431, 0.841884, 0.841415, 0.841014, 0.840677, 0.840397, 0.840168};

Float_t rc_var[13] = {0.822190, 0.828043, 0.832516, 0.832372, 0.836209, 0.838439, 0.839362, 0.839023, 0.842672, 0.842814, 0.843573, 0.844429, 0.842711};

Float_t Integral_data[13] ={0.0509779,0.0315616 ,0.0193192 ,0.0128869 ,0.00855009 ,0.00571586 ,0.00393479 ,0.00277849 ,0.00203 ,0.0015161 ,0.00113393 ,0.000861753,0.000646116};

Float_t Left_limit[13] = {0.981065, 0.978381, 0.976077, 0.975683, 0.973612, 0.972233, 0.971487, 0.971377, 0.969381, 0.969118, 0.968577, 0.96802  , 0.968774};
 
Float_t  Right_limit[13] = { 1.05198, 1.05944, 1.06425, 1.06899, 1.07356, 1.07663, 1.08073, 1.083, 1.08364, 1.08475, 1.08806, 1.08595, 1.08027};

  

Float_t fermiint[13] ={1.07614, 1.08281, 1.09302, 1.10366, 1.11839, 1.12768, 1.16337, 1.16144, 1.16262,  1.17558, 1.15453, 1.1563, 1.1451};

Float_t param_Qelast[13]={1.865E-1, 1.142E-1, 7.212E-2, 4.694E-2, 3.135E-2, 2.145E-2, 1.502E-2, 1.075E-2, 7.830E-3, 5.818E-3, 4.398E-3, 3.375E-3};




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


for (k=1;k<=40;k++){

Ef =  h_bosted[j-1]->GetBinCenter(k);

Q2 = 4.*Eo*Ef*sin(3.14159/180.*theta/2.)*sin(3.14159/180.*theta/2.);
theta = 23+ 2*(j-1); 
W = sqrt(M*M + 2.*M*(Eo - Ef) - Q2); 

nu = Eo - Ef;
eps = 1./(1. + 2.*(1. + nu*nu/Q2)*tan(3.14159/180.*theta/2.)*tan(3.14159/180.*theta/2.));

Gamma[k-1] = alpha*Ef*(W*W - M*M)/2./2./3.14159/3.14159/Q2/M/Eo/(1-eps);

//cout << j <<" "<< k <<" "<< Gamma[k-1]<<" gammmmmaaaaaa\n";
h_bosted[j-1]->SetBinContent(k,bosted[j-1][k-1]);
h_bosted[j-1]->SetBinError(k,0.);

h_bosted_skor[j-1]->SetBinContent(k,bosted_skor[j-1][k-1]);
h_bosted_skor[j-1]->SetBinError(k,0.);
};


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
h_data_hist[j-1]->SetMaximum(1.1*h_bosted[j-1]->GetMaximum());
h_data_hist[j-1]->SetMarkerStyle(20);
h_data_hist[j-1]->SetMarkerSize(0.8);
h_data_hist[j-1]->SetMarkerColor(kBlack);
h_data_hist[j-1]->SetLineColor(kBlack);
h_data_hist[j-1]->GetXaxis()->SetRangeUser(0.85,1.15);
h_data_hist[j-1]->Draw("e1pX0");

h_data_hist[j-1]->GetXaxis()->SetTitle("E'/E'_{peak}");
h_data_hist[j-1]->GetXaxis()->SetTitleSize(0.07);
h_data_hist[j-1]->GetXaxis()->SetLabelSize(0.06);
h_data_hist[j-1]->GetXaxis()->SetNdivisions(6+400);
h_data_hist[j-1]->GetYaxis()->SetTitle("d^{2}#sigma/(d#Omega dE') (#mub/GeV/sr)");
h_data_hist[j-1]->GetYaxis()->SetTitleSize(0.07);
h_data_hist[j-1]->GetYaxis()->SetLabelSize(0.06);
h_data_hist[j-1]->GetYaxis()->SetNdivisions(6+400);
h_data_hist[j-1]->GetYaxis()->SetTitleOffset(1.15);

h_bosted[j-1]->SetLineWidth(2);
h_bosted[j-1]->SetLineColor(kBlue);


h_bosted[j-1]->Scale(Bosted_max[j-1]/h_bosted[j-1]->GetMaximum());
h_bosted_skor[j-1]->Scale(Bosted_max[j-1]/h_bosted_skor[j-1]->GetMaximum());


h_quegg[0][j-1]->Scale(Bosted_max[j-1]/h_quegg[0][j-1]->GetMaximum());

h_bosted[j-1]->Draw("hist same");
h_bosted_skor[j-1]->SetLineWidth(2);
h_bosted_skor[j-1]->SetLineColor(kGreen+2);
h_bosted_skor[j-1]->Draw("hist same");

TLine *line_2 = new TLine(Left_limit[j-1],0.,Left_limit[j-1],h_bosted[j-1]->GetMaximum());
//line_2->SetLineStyle(2);
line_2->SetLineColor(43);
line_2->SetLineWidth(2);
line_2->Draw("same");

TLine *line_21 = new TLine(Right_limit[j-1],0.,Right_limit[j-1],h_bosted[j-1]->GetMaximum());
//line_21->SetLineStyle(2);
line_21->SetLineColor(43);
line_21->SetLineWidth(2);
line_21->Draw("same");

TLine *line_4 = new TLine(0.85,Bosted_max[j-1],1.15,Bosted_max[j-1]);
line_4->SetLineStyle(2);
line_4->SetLineColor(kGreen+1);
line_4->SetLineWidth(2);
line_4->Draw("same");


TLegend*leg6 = new TLegend(0.62,0.8,0.99,0.9); 
qqq.str("");
qqq << "E'_{peak} = "<<Epeak[j-1] <<" GeV";


leg6->SetHeader(qqq.str().c_str());
leg6->SetTextSize(.055);
leg6->Draw("same");


nl = h_data_hist[j-1]->GetXaxis()->FindBin(Left_limit[j-1]);
nr = h_data_hist[j-1]->GetXaxis()->FindBin(Right_limit[j-1]);
w = h_data_hist[j-1]->GetBinWidth(1);

//my_Qelast[j-1] = h_data_hist[j-1]->Integral(nl,nr)*w/rc_var[j-1];

//my_Qelast[j-1] = Integral_data[j-1]/rc_var[j-1];

my_Qelast[j-1] = h_data_hist[j-1]->Integral(nl+1,nr-1)*w + h_data_hist[j-1]->GetBinContent(nl)*(h_data_hist[j-1]->GetBinLowEdge(nl)+w -Left_limit[j-1]) + h_data_hist[j-1]->GetBinContent(nr)*(Right_limit[j-1] - h_data_hist[j-1]->GetBinLowEdge(nr));
my_Qelast[j-1] =my_Qelast[j-1]/rc_var[j-1];

// << j<< " "<<my_Qelast[j-1]<<endl;
h_data_hist[j-1]->IntegralAndError(nl,nr,Int_err[j-1]);
//cout << Int_err[j-1] <<" rrr\n";

Int_err[j-1] = Int_err[j-1]/h_data_hist[j-1]->Integral(nl,nr);


Bosted_Qelast[j-1] = h_bosted[j-1]->Integral(nl+1,nr-1)*w + h_bosted[j-1]->GetBinContent(nl)*(h_bosted[j-1]->GetBinLowEdge(nl)+w -Left_limit[j-1]) + h_bosted[j-1]->GetBinContent(nr)*(Right_limit[j-1] - h_bosted[j-1]->GetBinLowEdge(nr));

Bosted_Qelast_skor[j-1] = h_bosted_skor[j-1]->Integral(nl+1,nr-1)*w + h_bosted_skor[j-1]->GetBinContent(nl)*(h_bosted_skor[j-1]->GetBinLowEdge(nl)+w -Left_limit[j-1]) + h_bosted_skor[j-1]->GetBinContent(nr)*(Right_limit[j-1] - h_bosted_skor[j-1]->GetBinLowEdge(nr));

//cout <<"int test "<< my_Qelast[j-1]/(h_data_hist[j-1]->Integral(nl,nr)*w/rc_var[j-1])<< endl;
//cout <<"int test "<< Bosted_Qelast[j-1]/(h_bosted[j-1]->Integral(nl,nr)*w)<< endl;
//cout <<"int test "<< Bosted_Qelast_skor[j-1]/(h_bosted_skor[j-1]->Integral(nl,nr)*w)<< endl;


//Bosted_Qelast[j-1] = h_bosted[j-1]->Integral(nl,nr)*w;

//Bosted_Qelast_skor[j-1] = h_bosted_skor[j-1]->Integral(nl,nr)*w;




//cout <<"test "<< h_data_hist[j-1]->GetBinWidth(1)<<" "<<h_bosted[j-1]->GetBinWidth(1)<<" "<<h_bosted_skor[j-1]->GetBinWidth(1)<<endl;



//Bosted_Qelast_skor[j-1] = h_quegg[0][j-1]->Integral(h_quegg[0][j-1]->GetXaxis()->FindBin(cut),40)*h_quegg[0][j-1]->GetBinWidth(1);
};


for (j=1;j<=13;j++){
cout << my_Qelast[j-1] <<" "<<Bosted_Qelast[j-1]<<" "<<my_Qelast[j-1]/Bosted_Qelast[j-1]<<" tt\n";
};

cout << endl;

for (j=1;j<=13;j++){
cout << my_Qelast[j-1] <<" "<<Bosted_Qelast_skor[j-1]<<" "<<my_Qelast[j-1]/Bosted_Qelast_skor[j-1]<<" tt\n";
h_ratio->SetBinContent(j,my_Qelast[j-1]/Bosted_Qelast[j-1]);
h_ratio->SetBinError(j,Int_err[j-1]*my_Qelast[j-1]/Bosted_Qelast[j-1]);

h_ratio2->SetBinContent(j,my_Qelast[j-1]/Bosted_Qelast_skor[j-1]);
h_ratio2->SetBinError(j,Int_err[j-1]*my_Qelast[j-1]/Bosted_Qelast_skor[j-1]);

//h_ratio3->SetBinContent(j,0.5*(my_Qelast[j-1]/Bosted_Qelast_skor[j-1]+my_Qelast[j-1]/Bosted_Qelast[j-1]));
//h_ratio3->SetBinError(j,Int_err[j-1]*(my_Qelast[j-1]/Bosted_Qelast_skor[j-1]+my_Qelast[j-1]/Bosted_Qelast[j-1]));


};
c->cd(1);
c->cd(1)->SetTopMargin(0.125);
c->cd(1)->SetLeftMargin(0.11);
c->cd(1)->SetBottomMargin(0.16);
h_ratio->SetMinimum(0.75);
h_ratio->SetMaximum(1.25);
h_ratio->SetMarkerStyle(20);
h_ratio->SetMarkerSize(1.1);
h_ratio->SetMarkerColor(kBlue);
h_ratio->SetTitle(" ");
h_ratio->GetXaxis()->SetTitle("#theta_{e'} (deg)");
h_ratio->GetXaxis()->SetTitleSize(0.075);
h_ratio->GetXaxis()->SetLabelSize(0.06);
h_ratio->GetXaxis()->SetNdivisions(6+400);
h_ratio->GetYaxis()->SetTitle("#sigma_{exp}/#sigma_{par}^{1}");
h_ratio->GetYaxis()->SetTitleOffset(0.55);
h_ratio->GetYaxis()->SetTitleSize(0.08);
h_ratio->GetYaxis()->SetLabelSize(0.06);
h_ratio->GetYaxis()->SetNdivisions(6+400);
h_ratio->Draw("e1pX0");

TLine *line_4 = new TLine(22,1,48,1);
line_4->SetLineColor(kRed);
//line_4->SetLineWidth(2);
line_4->Draw("same");

TLine *line_5 = new TLine(22,0.95,48,0.95);
line_5->SetLineColor(kGreen+1);
line_5->SetLineStyle(2);
//line_5->SetLineWidth(2);
line_5->Draw("same");

TLine *line_6 = new TLine(22,1.05,48,1.05);
line_6->SetLineColor(kGreen+1);
line_6->SetLineStyle(2);
//line_6->SetLineWidth(2);
line_6->Draw("same");

TLine *line_7 = new TLine(22,1.1,48,1.1);
line_7->SetLineColor(kGreen-8);
line_7->SetLineStyle(2);
//line_7->SetLineWidth(2);
line_7->Draw("same");

TLine *line_8 = new TLine(22,0.9,48,0.9);
line_8->SetLineColor(kGreen-8);
line_8->SetLineStyle(2);
//line_8->SetLineWidth(2);
line_8->Draw("same");

c->cd(2);
c->cd(2)->SetTopMargin(0.125);
c->cd(2)->SetLeftMargin(0.11);
c->cd(2)->SetBottomMargin(0.16);
h_ratio2->SetMinimum(0.75);
h_ratio2->SetMaximum(1.25);
h_ratio2->SetMarkerStyle(20);
h_ratio2->SetMarkerColor(kGreen+2);




h_ratio2->Draw(" same e1pX0");
h_ratio2->SetTitle(" ");
h_ratio2->GetXaxis()->SetTitle("#theta_{e'} (deg)");
h_ratio2->GetXaxis()->SetTitleSize(0.075);
h_ratio2->GetXaxis()->SetLabelSize(0.06);
h_ratio2->GetXaxis()->SetNdivisions(6+400);
h_ratio2->GetYaxis()->SetTitle("#sigma_{exp}/#sigma_{par}^{2}");
h_ratio2->GetYaxis()->SetTitleOffset(0.55);
h_ratio2->GetYaxis()->SetTitleSize(0.08);
h_ratio2->GetYaxis()->SetLabelSize(0.06);
h_ratio2->GetYaxis()->SetNdivisions(6+400);
line_4->Draw("same");
line_5->Draw("same");
line_6->Draw("same");
line_7->Draw("same");
line_8->Draw("same");

c->cd();
TPad*newpad2 = new TPad("newpad","a transparent pad",0.,0.,1.,1.);
 newpad2->SetFillStyle(4000);
 newpad2->Draw();
  newpad2->cd();

 TLatex tex1;  

tex1.SetTextSize(0.09);
tex1.DrawLatex(0.45,0.92,"Not normalized");  


//Bosted_Qelast[0] = h_bosted->Integral()*h_bosted->GetBinWidth(1);
////Bosted_Qelast[1] = h_bosted->Integral()*h_bosted2->GetBinWidth(1);
//Bosted_Qelast[2] = h_bosted3->Integral()*h_bosted3->GetBinWidth(1);

//cout << endl;
//cout << my_Qelast[0] <<" "<<Bosted_Qelast[0] <<" "<< my_Qelast[0]/Bosted_Qelast[0]  << endl ;
//cout <<my_Qelast[1]  <<" "<<Bosted_Qelast[1] <<" "<< my_Qelast[1]/Bosted_Qelast[1] <<   endl ;

//cout << my_Qelast[2] <<" "<<Bosted_Qelast[2] <<" "<< my_Qelast[2]/Bosted_Qelast[2]  <<  endl ;
};
