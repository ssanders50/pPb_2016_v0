#ifndef VNPT
#define VNPT
#include <signal.h>
#include "Framework.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TPaveText.h"
#include "TH1I.h"
#include <ctime>
#include "../CMSSW_8_0_24/src/RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneList.h"
using namespace hi;
using namespace std;
static const int nptbins = 13;
static const float ptbins[]={0.2, 0.4, 0.6,  0.8,  1.0,  1.40,  1.8,
			      2.2,  2.8,  3.6,  4.6,  6.0,  7.0, 8.5};

int ROI[nptbins];
int ptloc[100];
TFile * fout = NULL;
TGraphErrors * vnptCalc(string flist, int mintrk, int maxtrk, float * sub1, float * sub2, int *Markers, int *Colors);

void vnpt_Ks(){
  int Markers[2];
  int Colors[2];

  fout = new TFile("Ks.root","recreate");
  Markers[0] = 20;
  Markers[1] = 21;
  Colors[0] = kRed;
  Colors[1] = kBlue;
  //vnptCalc("filelists/pPb_MB_Ks.dat", 0, 10, Markers, Colors);
  //vnptCalc("filelists/pPb_MB_Ks.dat", 10, 30, Markers, Colors);
  //vnptCalc("filelists/pPb_MB_Ks.dat", 30, 50, Markers, Colors);
  //vnptCalc("filelists/pPb_MB_Ks.dat", 50, 70, Markers, Colors);
  //vnptCalc("filelists/pPb_MB_Ks.dat", 70, 90, Markers, Colors);
  //vnptCalc("filelists/pPb_MB_Ks.dat", 90, 120, Markers, Colors);
  float sub1[2] = {-1.,1.0};
  float sub2[2] = {-1.0,1.0};
  float sub1a[2] = {-1.,0.0};
  float sub2a[2] = {0.0,1.0};
  vnptCalc("filelists/pPb_HM120_Ks.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("filelists/pPb_HM150_Ks.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("filelists/pPb_HM185_Ks.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("filelists/pPb_HM250_Ks.dat", 250, 500, sub1, sub2, Markers, Colors);
  vnptCalc("filelists/pPb_HM120_Ks.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("filelists/pPb_HM150_Ks.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("filelists/pPb_HM185_Ks.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("filelists/pPb_HM250_Ks.dat", 250, 500, sub1a, sub2a, Markers, Colors);
  Markers[0] = 25;
  Markers[1] = 24;
  Colors[0] = kBlue;
  Colors[1] = kRed;
  //vnptCalc("filelists/Pbp_MB_Ks.dat", 0, 10, Markers, Colors);
  //vnptCalc("filelists/Pbp_MB_Ks.dat", 10, 30, Markers, Colors);
  //vnptCalc("filelists/Pbp_MB_Ks.dat", 30, 50, Markers, Colors);
  //vnptCalc("filelists/Pbp_MB_Ks.dat", 50, 70, Markers, Colors);
  //vnptCalc("filelists/Pbp_MB_Ks.dat", 70, 90, Markers, Colors);
  //vnptCalc("filelists/Pbp_MB_Ks.dat", 90, 120, Markers, Colors);
  vnptCalc("filelists/Pbp_HM120_Ks.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("filelists/Pbp_HM150_Ks.dat", 150, 185, sub1, sub2, Markers, Colors);
  vnptCalc("filelists/Pbp_HM185_Ks.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("filelists/Pbp_HM250_Ks.dat", 250, 500, sub1, sub2, Markers, Colors);
  vnptCalc("filelists/Pbp_HM120_Ks.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("filelists/Pbp_HM150_Ks.dat", 150, 185, sub1a, sub2a, Markers, Colors);
  vnptCalc("filelists/Pbp_HM185_Ks.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("filelists/Pbp_HM250_Ks.dat", 250, 500, sub1a, sub2a, Markers, Colors);
}

TGraphErrors * vnptCalc(string flist, int mintrk, int maxtrk, float * sub1, float * sub2, int *Markers, int *Colors){
  std::clock_t start = 0;
  std::clock_t last = 0;
  int order = 2;
  Framework * frame = new Framework(flist);
  int iloc = 0;
  
 
  for(int j = 0; j<nptbins; j++) {
    ROI[j] = frame->SetROIRange(order, mintrk,maxtrk, sub1,sub2,  ptbins[j],ptbins[j+1]);
    frame->SetROIEP(ROI[j],HFp2,HFm2,trackmid2,HFm2,HFp2,trackmid2);
    if(ROI[j]<0) {cout<<"ROI ERROR"<<endl; return NULL;}
    ptloc[iloc++] = j;
  }
  cout<<"iloc: "<<iloc<<endl;
  int nfiles = 0;
  while(frame->AddFile()) {++nfiles;}
  cout<<"processed "<<nfiles<< " files"<<endl;
  double x[2][17];
  double xSub[2][17];
  double y[2][17];
  double ySub[2][17];
  double ey[2][17];
  double eySub[2][17];
  TGraphErrors * g[2];
  TGraphErrors * gSub[2];
  for(int isub = 0; isub<=1; isub++) {
    for(int i = 0; i<nptbins; i++) {
      x[isub][i] = frame->GetAvPt(i,0);
      xSub[isub][i] = x[isub][i];
      y[isub][i] = frame->GetVn(i,isub);
      ey[isub][i] = frame->GetVnErr(i,isub);
      ySub[isub][i] = frame->GetVnSubEvt(i,isub);
      eySub[isub][i] = frame->GetVnErrSubEvt(i,isub);
    }
    g[isub] = new TGraphErrors(nptbins,x[isub],y[isub],0,ey[isub]);
    gSub[isub] = new TGraphErrors(nptbins,xSub[isub],ySub[isub],0,eySub[isub]);
    g[isub]->SetName(Form("g_sub%d",isub+1));
    g[isub]->SetTitle(Form("g_sub%d",isub+1));
    g[isub]->SetMarkerStyle(Markers[isub]);
    g[isub]->SetMarkerColor(Colors[isub]);
    gSub[isub]->SetName(Form("gSub_sub%d",isub+1));
    gSub[isub]->SetTitle(Form("gSub_sub%d",isub+1));
    gSub[isub]->SetMarkerStyle(Markers[isub]);
    gSub[isub]->SetMarkerColor(Colors[isub]);
  }
  
  TH1D * spec = frame->GetSpectra();
  // cout<<"================================"<<endl;
  // TCanvas * c = new TCanvas("c","c",1000,800);
  // c->Divide(2);
  // c->cd(1);
  // TH1D * h = new TH1D("h","h",100,0,12);
  // h->SetMinimum(0);
  // h->SetMaximum(0.4);
  // h->Draw();
  // g_sub1->SetMarkerStyle(20);
  // g_sub1->SetMarkerColor(kBlue);
  // g_sub1->SetLineColor(kBlue);
  // g_sub1->Draw("p");
  // gSub_sub1->SetMarkerStyle(21);
  // gSub_sub1->SetMarkerColor(kRed);
  // gSub_sub1->SetLineColor(kRed);
  // gSub_sub1->Draw("p");
 
  fout->cd();
  TDirectory * subdir;
  if(flist.find("pPb")!=std::string::npos) {
    subdir = fout->mkdir(Form("pPb_%d_%d_%d_%d",mintrk,maxtrk,(int)sub1[0],(int)sub1[1]));
  } else {
    subdir = fout->mkdir(Form("Pbp_%d_%d_%d_%d",mintrk,maxtrk,(int)sub2[0],(int)sub2[1]));
  }
  subdir->cd();
  g[0]->Write("vn_NegEta");
  gSub[0]->Write("vn_NegEta_SubEvt");
  
  g[1]->Write("vn_PosEta");
  gSub[1]->Write("vn_PosEta_SubEvt");

  spec->Write();
  
  return 0;
}

#endif
