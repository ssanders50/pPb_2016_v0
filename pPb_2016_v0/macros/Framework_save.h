#ifndef FRAMEWORK
#define FRAMEWORK
#ifndef DEBUG
#define DEBUG
bool debug = false;
#endif
#include <iostream>
#include <unistd.h>
#include <complex>
#include <cmath>
#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TRandom.h"
#include "TGraphErrors.h"
#include "../CMSSW_8_0_24/src/RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneList.h"
#ifndef EFFFILE
#define EFFFILE
string efffile = "eff.root";
#endif
using namespace hi;
using namespace std;
void check(int i){cout<<"at location "<<i<<endl;}
static const int nqxorder = 1;
int qxorders[nqxorder]={2};
static const uint minRunRange = 326381;
static const uint maxRunRange = 327565;
static const int MAXROI = 500;
static const int MAXRUNS = 500; 
class Framework{
public:
  Framework(string filelist="filelist.dat", int histbins = 100, double maxvn=1.2, int CS = 0);
  int SetROIRange(int order, int minNtrk, int maxNtrk, float *sub1, float *sub2, double minPt, double maxPt);
  bool AddFile();
  int GetN(){return maxevents;}
  int GetNrange(){return nrange;}
  void ShowAllROIRanges();
  void SetROIEP(int roi, int EPA1, int EPB1, int EPC1, int EPA2=-1, int EPB2=-1, int EPC2 = -1);  // separate for subevents 1 and 2
  double GetAvPt(int roi){return r[roi].pt/r[roi].ptcnt;}
  double GetwnA_sub1(int roi){return r[roi].wnA_sub1;}
  double GetwnA_sub2(int roi){return r[roi].wnA_sub2;}

  double GetqnA_sub1(int roi){return r[roi].qn_sub1/r[roi].wnA_sub1;}
  double GetqnA_sub2(int roi){return r[roi].qn_sub2/r[roi].wnA_sub2;}
  double GetVn_sub1(int roi) {return GetqnA_sub1(roi)/GetqABC_sub(0,roi);}
  double GetVn_sub2(int roi) {return GetqnA_sub2(roi)/GetqABC_sub(1,roi);}

  double GetqnAError_sub1(int roi){return sqrt(r[roi].qne_sub1)/r[roi].wnA_sub1;}
  double GetqnAError_sub2(int roi){return sqrt(r[roi].qne_sub2)/r[roi].wnA_sub2;}
  double GetVnErr_sub1(int roi) {return GetqnAError_sub1(roi)/GetqABC_sub(0,roi);}
  double GetVnErr_sub2(int roi) {return GetqnAError_sub2(roi)/GetqABC_sub(1,roi);}
  double GetAng_sub1(int roi) {return r[roi].ang_sub1;}
  double GetAng_sub2(int roi) {return r[roi].ang_sub2;}
  double GetVnSubEvt_sub1(int roi);
  double GetVnSubEvt_sub2(int roi);
  double GetVnErrSubEvt_sub1(int roi);
  double GetVnErrSubEvt_sub2(int roi);
  double GetqABC_sub(int sub, int roi);
  double GetRescor_sub(int sub, int roi) {return (foff)? r[roi].rescor_sub[sub]:1 ;}
  TH2F * qxtrk[3];
  double GetAB_sub1(int roi);
  double GetAB_sub2(int roi);
  double GetAC_sub1(int roi);
  double GetAC_sub2(int roi);
  double GetBC_sub1(int roi);
  double GetBC_sub2(int roi);
  double GetAngHFp(int roi) {return r[roi].angHFp;}
  double GetAvEta_sub1(int roi) {return (r[roi].minEta1+r[roi].maxEta1)/2.;}
  double GetAvEta_sub2(int roi) {return (r[roi].minEta2+r[roi].maxEta2)/2.;}
  double GetNtrk(int roi) {return r[roi].ntrk;}
  double GetVtx(int roi) {return r[roi].vtx;}
  TH1D * GetSpectra(int roi);
  TH2D * Get2d_sub1(int roi){return r[roi].vn2d_sub1;}
  TH2D * Get2d_sub2(int roi){return r[roi].vn2d_sub2;}
  TH1D * Get1d_sub1(int roi){return r[roi].vn1d_sub1;}
  TH1D * Get1d_sub2(int roi){return r[roi].vn1d_sub2;}
  TH1D * Get1dMult_sub1(int roi){return r[roi].vn1dMult_sub1;}
  TH1D * Get1dMult_sub2(int roi){return r[roi].vn1dMult_sub2;}
  int GetMinNtrk(int roi){return r[roi].minNtrk;}
  int GetMaxNtrk(int roi){return r[roi].maxNtrk;}
  int GetMinMult(){return minMult;}
  int GetMaxMult(){return maxMult;}
  int GetMinRun(){return minRun;}
  int GetMaxRun(){return maxRun;}
  TH1D * GetRuns(){return runs;}
  TH1D * GetMult_sub1(int roi){return r[roi].mult_sub1;}
  TH1D * GetMult_sub2(int roi){return r[roi].mult_sub2;}
  double GetVnxEvt_sub1(int roi){return vnxEvt_sub1[roi];}
  double GetVnyEvt_sub1(int roi){return vnyEvt_sub1[roi];}
  double GetVnxEvt_sub2(int roi){return vnxEvt_sub2[roi];}
  double GetVnyEvt_sub2(int roi){return vnyEvt_sub2[roi];}
  void SetMinMult(int val){minMult = val;}
  void SetMaxMult(int val){maxMult = val;}
  void SetMinRun(int val){minRun = val;}
  void SetMaxRun(int val){maxRun = val;}
  void SetRuns(int nruns, double * runs); 
  void SaveFrameworkRuns(int roi, TDirectory * dir);
  bool LoadOffsets(string offname);
  FILE * flist;
private:
  int CS_;
  TH1D * runbins=NULL;
  TRandom * ran;
  double vnxEvt_sub1[MAXROI];
  double vnyEvt_sub1[MAXROI];
  double vnxEvt_sub2[MAXROI];
  double vnyEvt_sub2[MAXROI];
  double GetVnSub_sub1(int roi,int i) {return r[roi].qnSub_sub1[i]/r[roi].wnASub_sub1[i]/GetqABC_sub1(roi);}
  double GetVnSub_sub2(int roi,int i) {return r[roi].qnSub_sub2[i]/r[roi].wnASub_sub2[i]/GetqABC_sub2(roi);}
  int maxevents;
  TFile * tf;
  TFile *foff;
  double centval;
  int ntrkval;
  int Noff;
  int minMult = -1;
  int maxMult = -1;
  uint minRun = 0;
  uint maxRun = 0;
  double vtx;
  double epang[NumEPNames];
  Double_t eporig[NumEPNames];
  Double_t qx[NumEPNames];
  Double_t qy[NumEPNames];
  Double_t q[NumEPNames];
  Double_t vn[NumEPNames];
  Double_t epmult[NumEPNames];
  Double_t sumw[NumEPNames];
  Double_t sumw2[NumEPNames];
  Double_t rescor[NumEPNames];
  Double_t rescorErr[NumEPNames];
  unsigned int runno_;
  TH2F * qcnt=nullptr;
  TH2F * avpt=nullptr;
  TH1D * runs=NULL;
  /* TH1D * runcnt; */
  /* TH1D * runqx; */
  /* TH1D * runqy; */
  TH1D * qdifx;
  TH1D * qdify;
  int nruns;
  double runlist[MAXRUNS];
  int nhistbins_;
  double maxvn_;
  struct range {
    int order;
    int orderIndx;
    int minNtrk;
    int maxNtrk;
    double minEta1;
    double maxEta1;
    double minEta2;
    double maxEta2;
    double minPt;
    double maxPt;
    int minEtaBin1;
    int maxEtaBin1;
    int minEtaBin2;
    int maxEtaBin2;
    int minPtBin;
    int maxPtBin;
    int A1=-1;
    int B1=-1;
    int C1=-1;
    int A2=-1;
    int B2=-1;
    int C2=-1;
    double qn_sub1=0;
    double qn_sub2=0;
    double qne_sub1=0;
    double qne_sub2=0;
    double pt = 0;
    double ptcnt = 0;
    double wn_sub1 = 0;
    double wn_sub2 = 0;
    double wne_sub1=0;
    double wne_sub2=0;
    double wnA_sub1 = 0;
    double wnA_sub2 = 0;
    double qAB_sub[2] = {0};
    double rAB_sub[2] = {0};
    double wAB_sub[2] = {0};
    double qAC_sub[2] = {0};
    double rAC_sub[2] = {0};
    double wAC_sub[2] = {0};
    double qBC_sub[2] = {0};
    double rBC_sub[2] = {0};
    double wBC_sub[2] = {0};
    double rescor_sub[2] = {0};
    double qnSub_sub1[10]={0,0,0,0,0,0,0,0,0,0};
    double qnSube_sub1[10]={0,0,0,0,0,0,0,0,0,0};
    double wnASub_sub1[10]={0,0,0,0,0,0,0,0,0,0};
    double qnSub_sub2[10]={0,0,0,0,0,0,0,0,0,0};
    double qnSube_sub2[10]={0,0,0,0,0,0,0,0,0,0};
    double wnASub_sub2[10]={0,0,0,0,0,0,0,0,0,0};
    TH2D * vn2d_sub1;
    TH2D * vn2d_sub2;
    TH2D * ptspec=NULL;
    TH1D * hAB_sub1;
    TH1D * hAB_sub2;
    TH1D * hAC_sub1;
    TH1D * hAC_sub2;
    TH1D * hBC_sub1;
    TH1D * hBC_sub2;
    TH1D * vn1d_sub1;
    TH1D * vn1d_sub2;
    TH1D * vn1dMult_sub1;
    TH1D * vn1dMult_sub2;
    TH1D * mult_sub1;
    TH1D * mult_sub2;
    TH1D * spec_NegEta;
    TH1D * spec_PosEta;
    double ang_sub1;
    double ang_sub2;
    double vtx;
    double ntrk;
    double angHFp;
  } r[500];
  int nrange = 0;
};

#include "FrameworkSrc/GetqABC.C"

Framework::Framework(string filelist,  int nhistbins, double maxvn, int CS){
  ran = new TRandom();
  nhistbins_ = nhistbins;
  maxvn_ = maxvn;
  CS_ = CS;
  cout<<"open: "<<filelist<<endl;
  flist = fopen(filelist.data(),"r");
  char buf[120];
  fgets(buf,120,flist);
  buf[strlen(buf)-1]=0;
  string infile = buf;
  cout<<"infile:"<<infile<<":"<<endl;
  tf = new TFile(infile.data(),"read");
  qxtrk[0] = (TH2F *) tf->Get("vnanalyzer/qxtrk2");
  qxtrk[0]->SetDirectory(0);
  cout<<"qxtrk[0] "<<qxtrk[0]<<endl;
  runs = new TH1D("runs","runs",maxRunRange-minRunRange+1,minRunRange,maxRunRange);
  runs->SetDirectory(0);
  fclose(flist);
  tf->Close();
  flist = fopen(filelist.data(),"r");
  cout<<"Return from Framework"<<endl;
}
int Framework::SetROIRange(int order, int minNtrk, int maxNtrk, float *sub1, float *sub2, double minPt, double maxPt) {
 
  int ifound = -1;
  for(int i = 0; i<nqxorder; i++) {
    if(order == qxorders[i]) ifound = i;
  }
  if(ifound<0) {
    cout<<"The requested vn order is not part of the replay. ABORT!"<<endl;
    return -1;
  }
  r[nrange].orderIndx = ifound;
  r[nrange].order = order;
  r[nrange].minNtrk = minNtrk;
  r[nrange].maxNtrk = maxNtrk;
  r[nrange].minEtaBin1 = qxtrk[0]->GetYaxis()->FindBin(sub1[0]+0.01);
  r[nrange].maxEtaBin1 = qxtrk[0]->GetYaxis()->FindBin(sub1[1]-0.01);
  r[nrange].minEtaBin2 = qxtrk[0]->GetYaxis()->FindBin(sub2[0]+0.01);
  r[nrange].maxEtaBin2 = qxtrk[0]->GetYaxis()->FindBin(sub2[1]-0.01);
  r[nrange].minPtBin = qxtrk[0]->GetXaxis()->FindBin(minPt+0.01);
  r[nrange].maxPtBin = qxtrk[0]->GetXaxis()->FindBin(maxPt-0.01);
  r[nrange].minEta1 = qxtrk[0]->GetYaxis()->GetBinLowEdge(r[nrange].minEtaBin1);
  r[nrange].maxEta1 = qxtrk[0]->GetYaxis()->GetBinLowEdge(r[nrange].maxEtaBin1)+qxtrk[0]->GetYaxis()->GetBinWidth(r[nrange].maxEtaBin1);
  r[nrange].minEta2 = qxtrk[0]->GetYaxis()->GetBinLowEdge(r[nrange].minEtaBin2);
  r[nrange].maxEta2 = qxtrk[0]->GetYaxis()->GetBinLowEdge(r[nrange].maxEtaBin2)+qxtrk[0]->GetYaxis()->GetBinWidth(r[nrange].maxEtaBin2);
  r[nrange].minPt = qxtrk[0]->GetXaxis()->GetBinLowEdge(r[nrange].minPtBin);
  r[nrange].maxPt = qxtrk[0]->GetXaxis()->GetBinLowEdge(r[nrange].maxPtBin)+qxtrk[0]->GetXaxis()->GetBinWidth(r[nrange].maxPtBin);
  //
  r[nrange].vn2d_sub1 = new TH2D(Form("vn2d_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("vn2d_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),100,-1.4,1.4,100,-1.4,1.4);
  r[nrange].vn2d_sub1->SetOption("colz");
  r[nrange].vn2d_sub1->SetDirectory(0);
  r[nrange].vn2d_sub1->Sumw2();
  r[nrange].vn2d_sub1->SetXTitle(Form("v_{n,x}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta1,r[nrange].maxEta1));
  r[nrange].vn2d_sub1->SetYTitle("v_{n,y}^{obs}");

  r[nrange].vn2d_sub2 = new TH2D(Form("vn2d_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("vn2d_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),100,-1.4,1.4,100,-1.4,1.4);
  r[nrange].vn2d_sub2->SetOption("colz");
  r[nrange].vn2d_sub2->SetDirectory(0);
  r[nrange].vn2d_sub2->Sumw2();
  r[nrange].vn2d_sub2->SetXTitle(Form("v_{n,x}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta2,r[nrange].maxEta2));
  r[nrange].vn2d_sub2->SetYTitle("v_{n,y}^{obs}");


  //
  r[nrange].vn1d_sub1 = new TH1D(Form("vn1d_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("vn1d_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),nhistbins_,0,maxvn_);
  r[nrange].vn1d_sub1->SetDirectory(0);
  r[nrange].vn1d_sub1->Sumw2();
  r[nrange].vn1d_sub1->SetXTitle(Form("v_{n}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta1,r[nrange].maxEta1));
  r[nrange].vn1d_sub1->SetYTitle("Counts");

  r[nrange].vn1d_sub2 = new TH1D(Form("vn1d_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("vn1d_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),nhistbins_,0,maxvn_);
  r[nrange].vn1d_sub2->SetDirectory(0);
  r[nrange].vn1d_sub2->Sumw2();
  r[nrange].vn1d_sub2->SetXTitle(Form("v_{n}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta2,r[nrange].maxEta2));
  r[nrange].vn1d_sub2->SetYTitle("Counts");

  //
  r[nrange].vn1dMult_sub1 = new TH1D(Form("vn1dMult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  				     Form("vn1dMult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),nhistbins_,0,maxvn_);
  r[nrange].vn1dMult_sub1->SetDirectory(0);
  r[nrange].vn1dMult_sub1->Sumw2();
  r[nrange].vn1dMult_sub1->SetXTitle(Form("v_{n}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta1,r[nrange].maxEta1));
  r[nrange].vn1dMult_sub1->SetYTitle("AvMult");

  r[nrange].vn1dMult_sub2 = new TH1D(Form("vn1dMult_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),
  				     Form("vn1dMult_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),nhistbins_,0,maxvn_);
  r[nrange].vn1dMult_sub2->SetDirectory(0);
  r[nrange].vn1dMult_sub2->Sumw2();
  r[nrange].vn1dMult_sub2->SetXTitle(Form("v_{n}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta2,r[nrange].maxEta2));
  r[nrange].vn1dMult_sub2->SetYTitle("AvMult");



  //
  r[nrange].mult_sub1 = new TH1D(Form("mult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("mult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),100,0,100);
  r[nrange].mult_sub1->SetDirectory(0);
  r[nrange].mult_sub1->Sumw2();

  r[nrange].mult_sub2 = new TH1D(Form("mult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("mult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),100,0,1000);
  r[nrange].mult_sub2->SetDirectory(0);
  r[nrange].mult_sub2->Sumw2();

  ++nrange;
  return nrange-1;
} 

void Framework::SetROIEP(int roi, int EPA1, int EPB1, int EPC1, int EPA2, int EPB2, int EPC2){
  if(roi>nrange) {
    cout<<"request roi index = "<<roi<< " > nrange = "<<nrange<<endl;
    return;
  }
  r[roi].A1 = EPA1;
  r[roi].B1 = EPB1;
  r[roi].C1 = EPC1;
  r[roi].A2 = EPA2;
  r[roi].B2 = EPB2;
  r[roi].C2 = EPC2;
}

bool Framework::AddFile(){
  char buf[120];
  if(fgets(buf,120,flist)==NULL) return false;
  buf[strlen(buf)-1]=0;
  string infile = buf;
  tf->Close();
  tf = new TFile(infile.data(),"read");
  if(tf->IsZombie())                 {
    cout<<"ZOMBIE:    " <<infile.data()<<endl; 
    string remove = "rm "+infile;
    system(remove.data());
    return true;
  }
  for(int i = 0; i<nrange; i++) {
    TH2F * ptspec;
    TH2F * qA[11];
    TH2F * qB[11];
    TH2F * wnA[11];
    TH2F * wnB[11];
    TH1D * qBA[11];
    TH1D * qCA[11];
    TH1D * qCB[11];
    TH1D * qBAcnt[11];
    TH1D * qCAcnt[11];
    TH1D * qCBcnt[11];
    ptspec = (TH2F *) tf->Get(Form("vnanalyzer/Spectra/%d_%d/ptspec",r[i].minNtrk,r[i].maxNtrk));
    qA[0] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qA",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    qB[0] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qB",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    wnA[0] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/wnA",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    wnB[0] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/wnB",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    qBA[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qBA",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    qCA[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qCA",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    qCB[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qCB",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    qBAcnt[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qBAcnt",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    qCAcnt[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qCAcnt",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    qCBcnt[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qCBcnt",r[i].minNtrk,r[i].maxNtrk,r[i].order));
    for(int isub = 1; isub<=10; isub++) {
      qA[isub] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qA_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      qB[isub] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qB_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      wnA[isub] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/wnA_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      wnB[isub] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/wnB_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      qBA[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qBA_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      qCA[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qCA_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      qCB[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qCB_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      qBAcnt[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qBAcnt_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      qCAcnt[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qCAcnt_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
      qCBcnt[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qCBcnt_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    }
  
    for(int j = r[i].minEtaBin1; j<= r[i].maxEtaBin1; j++) {
      for(int k = r[i].minPtBin; k<=r[i].maxPtBin; k++) {
	r[i].qn_sub1+=qA[0]->GetBinContent(k,j);
	r[i].qn_sub2+=qB[0]->GetBinContent(k,j);
	r[i].qne_sub1+=pow(qA[0]->GetBinError(k,j),2);
	r[i].qne_sub2+=pow(qB[0]->GetBinError(k,j),2);
	r[i].wnA_sub1 += wnA[0]->GetBinContent(k,j);
	r[i].wnA_sub2 += wnB[0]->GetBinContent(k,j);
	r[i].qAB_sub1 += qBA[0]->GetBinContent(1);
	r[i].qAC_sub1 += qCA[0]->GetBinContent(1);
	r[i].qBC_sub1 += qCB[0]->GetBinContent(1);
	r[i].qAB_sub2 += qBA[0]->GetBinContent(1);
	r[i].qAC_sub2 += qCB[0]->GetBinContent(1);
	r[i].qBC_sub2 += qCA[0]->GetBinContent(1);
	r[i].wAB_sub1 += qBAcnt[0]->GetBinContent(1);
	r[i].wAC_sub1 += qCAcnt[0]->GetBinContent(1);
	r[i].wBC_sub1 += qCBcnt[0]->GetBinContent(1);
	r[i].wAB_sub2 += qBAcnt[0]->GetBinContent(1);
	r[i].wAC_sub2 += qCBcnt[0]->GetBinContent(1);
	r[i].wBC_sub2 += qCAcnt[0]->GetBinContent(1);

	r[i].qAB_sub1 += qBA[0]->GetBinContent(1);
	r[i].qAC_sub1 += qCA[0]->GetBinContent(1);
	r[i].qBC_sub1 += qCB[0]->GetBinContent(1);
	r[i].qAB_sub2 += qBA[0]->GetBinContent(1);
	r[i].qAC_sub2 += qCB[0]->GetBinContent(1);
	r[i].qBC_sub2 += qCA[0]->GetBinContent(1);

	r[i].pt += ptspec->GetXaxis()->GetBinCenter(k)*ptspec->GetBinContent(k,j);
	r[i].ptcnt += ptspec->GetBinContent(k,j);
	
	for(int m = 1; m<11; m++) {  
	  r[i].qnSub_sub1[m-1]+=qA[m]->GetBinContent(k,j);
	  r[i].qnSub_sub2[m-1]+=qB[m]->GetBinContent(k,j);
	  r[i].wnASub_sub1[m-1] += wnA[m]->GetBinContent(k,j);
	  r[i].wnASub_sub2[m-1] += wnB[m]->GetBinContent(k,j);
	}
	
	//double bineta = qxtrk[r[i].orderIndx]->GetYaxis()->GetBinCenter(j);
      }
    }
  }
  return true;
}


/* bool Framework::LoadOffsets(string offname){ */
/*   foff = new TFile(offname.data(),"read");  */
/*   if(foff->IsZombie()) return false; */

/*   return true; */
/* } */
/* void Framework::SetRuns(int nr, double * runl){ */
/*   runs = new TH1D("FrameworkRuns","FrameworkRuns",nr,runl); */
/*   runs->SetDirectory(0); */
/*   nruns = nr; */
/*   for(int i = 0; i<=nr; i++) runlist[i]=runl[i]; */
/* } */

/* void Framework::SaveFrameworkRuns(int roi, TDirectory * dir){ */
/*   TDirectory * savedir = gDirectory; */
/*   TDirectory * newdir=NULL; */
/*   TDirectory * chk = (TDirectory *) dir->Get("RunAverages");  */
/*   if(chk==NULL)  { */
/*     newdir = (TDirectory *) dir->mkdir("RunAverages"); */
/*   } else { */
/*     newdir = chk; */
/*   } */
/*   newdir->cd(); */
/*   savedir->cd(); */
/* } */




/* void Framework::ShowAllROIRanges(){ */
/*   cout<<setw(12)<<right<<"indx"<<setw(12)<<right<<"minNtrk"<<setw(12)<<right<<"maxNtrk"<<setw(12)<<right<<"minEta1"<<setw(12)<<right<<"maxEta1"<<setw(12)<<right<<"minEta2"<<setw(12)<<right<<"maxEta2"<<setw(12)<<right<<"minPt"<<setw(12)<<right<<"maxPt"<<setw(12)<<right<<"minEtaBin1"<<setw(12)<<right<<"maxEtaBin1"<<setw(12)<<right<<"minEtaBin2"<<setw(12)<<right<<"maxEtaBin2"<<setw(12)<<right<<"minPtBin"<<setw(12)<<right<<"maxPtBin"<<std::endl; */
/*   for(int i = 0; i<nrange; i++) { */
/*     cout<<setprecision(2)<<setw(12)<<right<<i<<setprecision(2)<<setw(12)<<right<<r[i].minNtrk<<setprecision(2)<<setw(12)<<right<<r[i].maxNtrk<<setprecision(2)<<setw(12)<<right<<r[i].minEta1<<setprecision(2)<<setw(12)<<right<<r[i].maxEta1<<setw(12)<<right<<r[i].minEta2<<setprecision(2)<<setw(12)<<right<<r[i].maxEta2<<setprecision(2)<<setw(12)<<right<<r[i].minPt<<setprecision(2)<<setw(12)<<right<<r[i].maxPt<<setprecision(2)<<setw(12)<<right<<r[i].minEtaBin1<<setprecision(2)<<setw(12)<<right<<r[i].maxEtaBin1<<setw(12)<<right<<r[i].minEtaBin2<<setprecision(2)<<setw(12)<<right<<r[i].maxEtaBin2<<setprecision(2)<<setw(12)<<right<<r[i].minPtBin<<setprecision(2)<<setw(12)<<right<<r[i].maxPtBin<<std::endl; */
/*   } */
/* } */



/* double Framework::GetAB_sub1(int roi) { */
/*   return r[roi].rAB_sub1; */
/* } */
/* double Framework::GetAB_sub2(int roi) { */
/*   return r[roi].rAB_sub2; */
/* } */
/* double Framework::GetAC_sub1(int roi) { */
/*   return r[roi].rAC_sub1; */
/* } */
/* double Framework::GetAC_sub2(int roi) { */
/*   return r[roi].rAC_sub2; */
/* } */
/* double Framework::GetBC_sub1(int roi) { */
/*   return r[roi].rBC_sub1; */
/* } */
/* double Framework::GetBC_sub2(int roi) { */
/*   return r[roi].rBC_sub2; */
/* } */

/* TH1D * Framework::GetSpectra(int roi) { */
/*   debug = false; */
/*   TDirectory * dirsave = gDirectory; */
/*   TH2D * spec; */
/*   int minNtrk = r[roi].minNtrk; */
/*   int maxNtrk = r[roi].maxNtrk; */
/*   string crnge = Form("%d_%d",minNtrk,maxNtrk); */
/*   string spname = "vnanalyzer/Spectra/"+crnge+"/ptspec"; */
/*   TH2D * ptcnt = (TH2D *) tf->Get(spname.data()); */
/*   spec = (TH2D *) ptcnt->Clone(Form("spec_%s",crnge.data())); */
/*   spec->SetDirectory(0); */
/*   double etamin1 = r[roi].minEta1; */
/*   double etamax1 = r[roi].maxEta1; */
/*   int ietamin1 = spec->GetYaxis()->FindBin(etamin1+0.01); */
/*   int ietamax1 = spec->GetYaxis()->FindBin(etamax1-0.01); */
/*   double etamin2 = r[roi].minEta2; */
/*   double etamax2 = r[roi].maxEta2; */
/*   int ietamin2 = spec->GetYaxis()->FindBin(etamin2+0.01); */
/*   int ietamax2 = spec->GetYaxis()->FindBin(etamax2-0.01); */
/*   r[roi].spec_NegEta = (TH1D *) spec->ProjectionX(Form("spec1d_%d_%d_NegEta",minNtrk,maxNtrk),ietamin1,ietamax1); */
/*   r[roi].spec_PosEta = (TH1D *) spec->ProjectionX(Form("spec1d_%d_%d_PosEta",minNtrk,maxNtrk),ietamin2,ietamax2); */
/*   TH1D * spec1d = (TH1D *) r[roi].spec_NegEta->Clone(Form("spec1d_%d_%d",minNtrk,maxNtrk)); */
/*   spec1d->SetDirectory(0); */
/*   spec1d->Add(r[roi].spec_PosEta); */
/*   double bineta = 0.199; */
/*   for(int i = 0; i<spec1d->GetNbinsX(); i++) { */
/*     double deta = etamax1-etamin1+etamax2-etamin2; */
/*     double dpt = spec1d->GetBinWidth(i+1); */
/*     double binpt = spec1d->GetXaxis()->GetBinCenter(i+1); */
/*     double eff = 1; */
/*     spec1d->SetBinContent(i+1,spec1d->GetBinContent(i+1)/deta/dpt); */
/*     spec1d->SetBinError(i+1,spec1d->GetBinError(i+1)/deta/dpt); */

/*   } */
/*   spec1d->SetXTitle("p_{T} (GeV/c)"); */
/*   spec1d->SetYTitle("dN/d#eta/dp_{T}"); */
/*   spec1d->SetMarkerStyle(20); */
/*   spec1d->SetMarkerColor(kBlue); */
/*   spec1d->SetLineColor(kBlue); */
/*   spec->Delete(); */
/*   debug = false; */
/*   dirsave->cd(); */
/*   return spec1d; */
/* } */

/* double Framework::GetVnErrSubEvt_sub1(int roi){ */
/*   double vnav=0; */
/*   for(int i = 0; i<10; i++) vnav+=GetVnSub_sub1(roi,i); */
/*   vnav/=10.; */
/*   double sig = 0; */
/*   for(int i = 0; i<10; i++) sig+=pow(GetVnSub_sub1(roi,i)-vnav,2); */
/*   sig = sqrt(sig)/9.; */
/*   return sig; */
/* } */
/* double Framework::GetVnErrSubEvt_sub2(int roi){ */
/*   double vnav=0; */
/*   for(int i = 0; i<10; i++) vnav+=GetVnSub_sub2(roi,i); */
/*   vnav/=10.; */
/*   double sig = 0; */
/*   for(int i = 0; i<10; i++) sig+=pow(GetVnSub_sub2(roi,i)-vnav,2); */
/*   sig = sqrt(sig)/9.; */
/*   return sig; */
/* } */

/* double Framework::GetVnSubEvt_sub1(int roi){ */
/*   double vnav=0; */
/*   for(int i = 0; i<10; i++) { */
/*     vnav+=GetVnSub_sub1(roi,i); */
/*   } */

/*   vnav/=10.; */
/*   return vnav; */
/* } */
/* double Framework::GetVnSubEvt_sub2(int roi){ */
/*   double vnav=0; */
/*   for(int i = 0; i<10; i++) { */
/*     vnav+=GetVnSub_sub2(roi,i); */
/*   } */
/*   vnav/=10.; */
/*   return vnav; */
/* } */
#endif
