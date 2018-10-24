void my_bosted_comp(){
gStyle->SetOptStat(0);
gStyle->SetTitleY(0.975);
gStyle->SetTitleSize(0.08);

Float_t Eo, Ef, theta, Mott, Q2,;
Float_t Mn, Mp,mu_n, mu_p;
mu_p = 2.793;
mu_n = -1.913;
Mp = 0.938272;
Mn = 0.939565;

Eo = 2.039;
Ef = 1.246;
theta = theta*3.1415/180;
Q2 = 4.*Eo*Ef*sin(theta/2)*sin(theta/2);



Mott = (2. / 137. * Ef / Q2 * cos(theta / 2.))*(2. / 137. * Ef / Q2 * cos(theta / 2.)); // mott






};
