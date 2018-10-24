#ifndef J_QE_ANA_CALC_H_
#define J_QE_ANA_CALC_H_

#include "qe_ana_defines.h"
#include "qe_ana_includes.h"

Double_t McGee(Double_t *x,Double_t *par);
Double_t get_mcgee_p(Double_t p);
Double_t Hulthen(Double_t *x, Double_t *par);
Double_t BW(Double_t *x, Double_t *par);
Double_t theta_rf_f1(Double_t *x, Double_t *par);

void calc_scattering_range(Double_t Ebeam, Double_t pfermi,
			   Double_t theta_fermi, Double_t theta_min_lab,
			   Double_t theta_max_lab, Double_t &theta_min, 
			   Double_t &theta_max);
vector4_t v4boost(vector4_t vec, vector3_t beta);
Double_t ge_p(Double_t qsq);
Double_t gm_p(Double_t qsq);
Double_t ge_n(Double_t qsq);
Double_t gm_n(Double_t qsq);
Double_t gd(Double_t qsq);
Double_t tau(Double_t qsq);
Double_t epsilon(Double_t qsq, Double_t ezero);
Double_t calc_eprime(Double_t ezero, Double_t theta);
Double_t calc_qsq(Double_t ezero, Double_t theta);
Double_t calc_neutron_xsec(Double_t *x, Double_t *par);
Double_t calc_proton_xsec(Double_t *x, Double_t *par);
Double_t mott_xsec(Double_t ezero, Double_t theta);
vector3_t z_rotate(float phi,vector3_t vec);
vector3_t y_rotate(float phi,vector3_t vec);

Double_t calc_rest_frame_energy(Double_t Ebeam,Double_t pfermi,
				Double_t theta_fermi);
Double_t calc_theta_rf(Double_t Ebeam,Double_t pfermi,
		       Double_t theta_fermi,Double_t theta_lab);
Double_t calc_theta_lab(Double_t Ebeam, Double_t pfermi, Double_t theta_fermi,
			Double_t theta_rf);
Double_t jacobian(Double_t *x,Double_t *par);

class Jqe_ana_calc{
 public:
  Jqe_ana_calc(float ezero, float current, FF_PARAM_t param);
  float calc_tau(float qsq, HADRON_TYPE_t htype);
  float calc_alpha_sq(float qsq, HADRON_TYPE_t htype);
  float calc_epsilon(float qsq, HADRON_TYPE_t htype);
  float calc_mott_ratio(float qsq);
  float calc_tau_ratio(float qsq);
  float calc_epsilon_tau_ratio(float qsq);
  float calc_ff_factor(float qsq);
  float calc_gep(float qsq);
  float calc_gmp(float qsq);
  float calc_gen(float qsq);
  float calc_gmn(float qsq);
  float calc_gd(float qsq);
  float calc_gmp_brash(float qsq);
  float calc_gep_brash(float qsq);
  float calc_gmp_arrington(float qsq);
  float calc_gep_arrington(float qsq);
  float calc_gen_galster(float qsq);
  void fill_ff_histos(void);
  
  void extract_gmn(TH1F *hin,TH1F *hout, TH1F *hout_2);
  void generate_expected_neutron_spectrum(TH1F *proton_dist, 
					  TH1F *expected_neutron_dist);
  float calc_elastic_p(float e_theta);
  void generate_qe_event(HADRON_TYPE_t htype, vector3_t &expected3, 
			 vector3_t &real3, vector3_t &electron3, float &Qsq, 
			 float &theta_pq, float &phi_pq, float &wsq, float helicity_sign,
			 float pfermi_threshold, int ALTpVersion);
  float calc_elastic_Eprime(Double_t cos_theta);
  void fill_weight_table_neutron(void);
  void fill_weight_table_proton(void);
  void fill_restframe_xsec_tables(void);
  float get_electron_angle(HADRON_TYPE_t htype, float pfermi,
			   float theta_fermi);
  void close_histos(void);
  float generate_ALTp_phi(float pfermi2, float Q2, float helicity_sign, int ALTpVersion);

 private:
  float init_energy,Itorus;
  float theta_min_lab,theta_max_lab;
  float Emax,Emin;
  FF_PARAM_t fftype;

  TF1 *hult_func;
  TF1 *breit_wigner;
  TF1 *mcgee_func;
  TF1 *neutron_xsec;
  TF1 *proton_xsec;
  //TF1 *cos_func;
  TAxis *x_axis,*y_axis;
  TRandom3 *rand;
  TH1F *xsec_histo_neutron;
  TH1F *xsec_histo_proton;
  TH2F *weight_table_neutron, *ezero_table;
  TH2F *weight_table_proton;
  TH1F *qsq_neutron;
  TH1F *qsq_proton;
  TH2F *delta_ezero_table, *hult_table;
  TH2F *integrated_xsec_table_neutron;
  TH2F *integrated_xsec_table_proton;
  TH1F *wsq_dist,*theta_gn_dist,*nu_dist;
  TH2F *wsq_vs_qsq,*wsq_vs_theta_gn;
  TH2F *eprime_vs_angle,*hprime_vs_angle;
  TH2F *htheta_vs_etheta;
  TH2F *eprime_vs_pfct;
  TH2F *theta_gn_vs_qsq;
  TH2F *neutron_restframe_xsec,*proton_restframe_xsec;
  TH1F *gmp_histo,*gep_histo,*gen_histo,*reduced_xsec_histo_p;
  TH1F *reduced_xsec_histo_n;

  TH1F *epsilon_histo,*epsilon_tau_histo;

  TFile *rootfile;

  //bw resonance parameters
  Double_t *delta_pars;
  Double_t *N1440_pars;
  Double_t *delta_1620_pars;

};

#endif
