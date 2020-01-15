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
  double GetAvPt(int roi, int sub){return r[roi].pt[sub]/r[roi].ptcnt[sub];}
  double GetqnA(int roi,int sub){return r[roi].qn[sub]/r[roi].wnA[sub];}
  double GetVn(int roi, int sub) {return GetqnA(roi,sub)/GetqABC(roi,sub);}
  double GetqnAError(int roi, int sub){return sqrt(r[roi].qne[sub])/r[roi].wnA[sub];}
  double GetVnErr(int roi, int sub) {return GetqnAError(roi,sub)/GetqABC(roi,sub);}
  double GetAng(int roi,int sub) {return r[roi].ang[0];}

  double GetVnSubEvt(int roi, int sub);
  double GetVnErrSubEvt(int roi, int sub);

  double GetqABC(int roi, int sub);
  double GetRescor_sub(int sub, int roi) {return (foff)? r[roi].rescor[sub]:1 ;}
  TH2F * qxtrk[3];
  double GetAngHFp(int roi) {return r[roi].angHFp;}
  double GetAvEta_sub1(int roi) {return (r[roi].minEta[0]+r[roi].maxEta[0])/2.;}
  double GetAvEta_sub2(int roi) {return (r[roi].minEta[1]+r[roi].maxEta[1])/2.;}
  double GetNtrk(int roi) {return r[roi].ntrk;}
  double GetVtx(int roi) {return r[roi].vtx;}
  TH1D * GetSpectra();
  TH2D * Get2d_sub1(int roi){return r[roi].vn2d[0];}
  TH2D * Get2d_sub2(int roi){return r[roi].vn2d[1];}
  TH1D * Get1d_sub1(int roi){return r[roi].vn1d[0];}
  TH1D * Get1d_sub2(int roi){return r[roi].vn1d[1];}
  TH1D * Get1dMult_sub1(int roi){return r[roi].vn1dMult[0];}
  TH1D * Get1dMult_sub2(int roi){return r[roi].vn1dMult[1];}
  int GetMinNtrk(int roi){return r[roi].minNtrk;}
  int GetMaxNtrk(int roi){return r[roi].maxNtrk;}
  int GetMinMult(){return minMult;}
  int GetMaxMult(){return maxMult;}
  int GetMinRun(){return minRun;}
  int GetMaxRun(){return maxRun;}
  TH1D * GetRuns(){return runs;}
  TH1D * GetMult_sub1(int roi){return r[roi].mult[0];}
  TH1D * GetMult_sub2(int roi){return r[roi].mult[1];}
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
  double GetVnSub(int roi,int i,int sub) {return r[roi].qnSub[sub][i]/r[roi].wnASub[sub][i]/GetqABC(roi,sub);}
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
  TH1D * hntrk;
  struct range {
    int order;
    int orderIndx;
    int minNtrk;
    int maxNtrk;
    double minEta[2];
    double maxEta[2];
    double minPt;
    double maxPt;
    int minEtaBin[2];
    int maxEtaBin[2];
    int minPtBin;
    int maxPtBin;
    int A[2]={-1};
    int B[2]={-1};
    int C[2]={-1};
    double qn[2]={0};
    double qne[2]={0};
    double pt[2] = {0};
    double ptcnt[2] = {0};
    double wn[2] ={0};
    double wne[2]={0};
    double wnA[2] = {0};
    double qAB[2] = {0};
    double rAB[2] = {0};
    double wAB[2] = {0};
    double qAC[2] = {0};
    double rAC[2] = {0};
    double wAC[2] = {0};
    double qBC[2] = {0};
    double rBC[2] = {0};
    double wBC[2] = {0};
    double rescor[2] = {0};
    double qnSub[2][10]={{0}};
    double qnSube[2][10]={{0}};
    double wnASub[2][10]={{0}};
    TH2D * vn2d[2];
    TH2D * ptspec=NULL;
    TH1D * hAB[2];
    TH1D * hAC[2];
    TH1D * hBC[2];
    TH1D * vn1d[2];
    TH1D * vn1dMult[2];
    TH1D * mult[2];
    TH1D * spec_NegEta;
    TH1D * spec_PosEta;
    double ang[2];
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
  qxtrk[0]->Reset();
  cout<<"qxtrk[0] "<<qxtrk[0]<<endl;
  hntrk = (TH1D *) tf->Get("vnanalyzer/Ntrk");
  cout<<"Ntrk: "<<hntrk<<endl;
  hntrk->SetDirectory(0);
  hntrk->Reset();
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
  r[nrange].minEtaBin[0] = qxtrk[0]->GetYaxis()->FindBin(sub1[0]+0.01);
  r[nrange].maxEtaBin[0] = qxtrk[0]->GetYaxis()->FindBin(sub1[1]-0.01);
  r[nrange].minEtaBin[1] = qxtrk[0]->GetYaxis()->FindBin(sub2[0]+0.01);
  r[nrange].maxEtaBin[1] = qxtrk[0]->GetYaxis()->FindBin(sub2[1]-0.01);
  r[nrange].minPtBin = qxtrk[0]->GetXaxis()->FindBin(minPt+0.01);
  r[nrange].maxPtBin = qxtrk[0]->GetXaxis()->FindBin(maxPt-0.01);
  r[nrange].minEta[0] = qxtrk[0]->GetYaxis()->GetBinLowEdge(r[nrange].minEtaBin[0]);
  r[nrange].maxEta[0] = qxtrk[0]->GetYaxis()->GetBinLowEdge(r[nrange].maxEtaBin[0])+qxtrk[0]->GetYaxis()->GetBinWidth(r[nrange].maxEtaBin[0]);
  r[nrange].minEta[1] = qxtrk[0]->GetYaxis()->GetBinLowEdge(r[nrange].minEtaBin[1]);
  r[nrange].maxEta[1] = qxtrk[0]->GetYaxis()->GetBinLowEdge(r[nrange].maxEtaBin[1])+qxtrk[0]->GetYaxis()->GetBinWidth(r[nrange].maxEtaBin[1]);
  r[nrange].minPt = qxtrk[0]->GetXaxis()->GetBinLowEdge(r[nrange].minPtBin);
  r[nrange].maxPt = qxtrk[0]->GetXaxis()->GetBinLowEdge(r[nrange].maxPtBin)+qxtrk[0]->GetXaxis()->GetBinWidth(r[nrange].maxPtBin);
  //
  r[nrange].vn2d[0] = new TH2D(Form("vn2d_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("vn2d_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),100,-1.4,1.4,100,-1.4,1.4);
  r[nrange].vn2d[0]->SetOption("colz");
  r[nrange].vn2d[0]->SetDirectory(0);
  r[nrange].vn2d[0]->Sumw2();
  r[nrange].vn2d[0]->SetXTitle(Form("v_{n,x}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta[0],r[nrange].maxEta[0]));
  r[nrange].vn2d[0]->SetYTitle("v_{n,y}^{obs}");

  r[nrange].vn2d[1] = new TH2D(Form("vn2d_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("vn2d_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),100,-1.4,1.4,100,-1.4,1.4);
  r[nrange].vn2d[1]->SetOption("colz");
  r[nrange].vn2d[1]->SetDirectory(0);
  r[nrange].vn2d[1]->Sumw2();
  r[nrange].vn2d[1]->SetXTitle(Form("v_{n,x}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta[1],r[nrange].maxEta[1]));
  r[nrange].vn2d[1]->SetYTitle("v_{n,y}^{obs}");


  //
  r[nrange].vn1d[0] = new TH1D(Form("vn1d_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("vn1d_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),nhistbins_,0,maxvn_);
  r[nrange].vn1d[0]->SetDirectory(0);
  r[nrange].vn1d[0]->Sumw2();
  r[nrange].vn1d[0]->SetXTitle(Form("v_{n}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta[0],r[nrange].maxEta[0]));
  r[nrange].vn1d[0]->SetYTitle("Counts");

  r[nrange].vn1d[1] = new TH1D(Form("vn1d_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("vn1d_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),nhistbins_,0,maxvn_);
  r[nrange].vn1d[1]->SetDirectory(0);
  r[nrange].vn1d[1]->Sumw2();
  r[nrange].vn1d[1]->SetXTitle(Form("v_{n}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta[1],r[nrange].maxEta[1]));
  r[nrange].vn1d[1]->SetYTitle("Counts");

  //
  r[nrange].vn1dMult[0] = new TH1D(Form("vn1dMult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  				     Form("vn1dMult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),nhistbins_,0,maxvn_);
  r[nrange].vn1dMult[0]->SetDirectory(0);
  r[nrange].vn1dMult[0]->Sumw2();
  r[nrange].vn1dMult[0]->SetXTitle(Form("v_{n}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta[0],r[nrange].maxEta[0]));
  r[nrange].vn1dMult[0]->SetYTitle("AvMult");

  r[nrange].vn1dMult[1] = new TH1D(Form("vn1dMult_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),
  				     Form("vn1dMult_%d_%d_%d_%04.2f_%04.2f_sub2",order,minNtrk,maxNtrk,minPt,maxPt),nhistbins_,0,maxvn_);
  r[nrange].vn1dMult[1]->SetDirectory(0);
  r[nrange].vn1dMult[1]->Sumw2();
  r[nrange].vn1dMult[1]->SetXTitle(Form("v_{n}^{obs} (%3.1f < #eta <  %3.1f)",r[nrange].minEta[1],r[nrange].maxEta[1]));
  r[nrange].vn1dMult[1]->SetYTitle("AvMult");



  //
  r[nrange].mult[0] = new TH1D(Form("mult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("mult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),100,0,100);
  r[nrange].mult[0]->SetDirectory(0);
  r[nrange].mult[0]->Sumw2();

  r[nrange].mult[1] = new TH1D(Form("mult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),
  			         Form("mult_%d_%d_%d_%04.2f_%04.2f_sub1",order,minNtrk,maxNtrk,minPt,maxPt),100,0,1000);
  r[nrange].mult[1]->SetDirectory(0);
  r[nrange].mult[1]->Sumw2();

  ++nrange;
  return nrange-1;
} 
#include "FrameworkSrc/AddFile.C"

void Framework::SetROIEP(int roi, int EPA1, int EPB1, int EPC1, int EPA2, int EPB2, int EPC2){
  if(roi>nrange) {
    cout<<"request roi index = "<<roi<< " > nrange = "<<nrange<<endl;
    return;
  }
  r[roi].A[0] = EPA1;
  r[roi].B[0] = EPB1;
  r[roi].C[0] = EPC1;
  r[roi].A[1] = EPA2;
  r[roi].B[1] = EPB2;
  r[roi].C[1] = EPC2;
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



#include "FrameworkSrc/GetSpectra.C"
#include "FrameworkSrc/GetVnSubEvt.C"
#include "FrameworkSrc/GetVnErrSubEvt.C"
#endif
