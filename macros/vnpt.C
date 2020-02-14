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
TGraphErrors * vnptCalc(string chan, string flist, int mintrk, int maxtrk, float * sub1, float * sub2, int *Markers, int *Colors);

void vnpt(){
  int Markers[2];
  int Colors[2];

  fout = new TFile("v0.root","recreate");
  Markers[0] = 20;
  Markers[1] = 21;
  Colors[0] = kRed;
  Colors[1] = kBlue;
  float sub1[2] = {-1.0,0.0};
  float sub2[2] = { 0.0,1.0};
  float sub1a[2] =  {-1.0,1.0};
  float sub2a[2] =  {-1.0,1.0};
  vnptCalc("Ks","filelists/pPb_HM120_Ks.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Ks","filelists/pPb_HM150_Ks.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Ks","filelists/pPb_HM185_Ks.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("Ks","filelists/pPb_HM250_Ks.dat", 250, 500, sub1, sub2, Markers, Colors);
  vnptCalc("Ks","filelists/pPb_HM120_Ks.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks","filelists/pPb_HM150_Ks.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Ks","filelists/pPb_HM185_Ks.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks","filelists/pPb_HM250_Ks.dat", 250, 500, sub1a, sub2a, Markers, Colors);

  vnptCalc("Ks_SBPos","filelists/pPb_HM120_Ks_SBPos.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/pPb_HM150_Ks_SBPos.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/pPb_HM185_Ks_SBPos.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/pPb_HM250_Ks_SBPos.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/pPb_HM120_Ks_SBPos.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/pPb_HM150_Ks_SBPos.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/pPb_HM185_Ks_SBPos.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/pPb_HM250_Ks_SBPos.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  vnptCalc("Ks_SBNeg","filelists/pPb_HM120_Ks_SBNeg.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/pPb_HM150_Ks_SBNeg.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/pPb_HM185_Ks_SBNeg.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/pPb_HM250_Ks_SBNeg.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/pPb_HM120_Ks_SBNeg.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/pPb_HM150_Ks_SBNeg.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/pPb_HM185_Ks_SBNeg.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/pPb_HM250_Ks_SBNeg.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  vnptCalc("Lambda","filelists/pPb_HM120_Lambda.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda","filelists/pPb_HM150_Lambda.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Lambda","filelists/pPb_HM185_Lambda.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda","filelists/pPb_HM250_Lambda.dat", 250, 500, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda","filelists/pPb_HM120_Lambda.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda","filelists/pPb_HM150_Lambda.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Lambda","filelists/pPb_HM185_Lambda.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda","filelists/pPb_HM250_Lambda.dat", 250, 500, sub1a, sub2a, Markers, Colors);

  vnptCalc("Lambda_SBPos","filelists/pPb_HM120_Lambda_SBPos.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/pPb_HM150_Lambda_SBPos.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/pPb_HM185_Lambda_SBPos.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/pPb_HM250_Lambda_SBPos.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/pPb_HM120_Lambda_SBPos.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/pPb_HM150_Lambda_SBPos.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/pPb_HM185_Lambda_SBPos.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/pPb_HM250_Lambda_SBPos.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  vnptCalc("Lambda_SBNeg","filelists/pPb_HM120_Lambda_SBNeg.dat", 120, 150, sub1, sub2, Markers, Colors);
  //vnptCalc("Lambda_SBNeg","filelists/pPb_HM150_Lambda_SBNeg.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Lambda_SBNeg","filelists/pPb_HM185_Lambda_SBNeg.dat", 185, 250, sub1, sub2, Markers, Colors);
  //vnptCalc("Lambda_SBNeg","filelists/pPb_HM250_Lambda_SBNeg.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda_SBNeg","filelists/pPb_HM120_Lambda_SBNeg.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  //vnptCalc("Lambda_SBNeg","filelists/pPb_HM150_Lambda_SBNeg.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Lambda_SBNeg","filelists/pPb_HM185_Lambda_SBNeg.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  //vnptCalc("Lambda_SBNeg","filelists/pPb_HM250_Lambda_SBNeg.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  vnptCalc("ch","filelists/pPb_HM120_ch.dat", 120, 150, sub1, sub2,  Markers, Colors);
  vnptCalc("ch","filelists/pPb_HM150_ch.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("ch","filelists/pPb_HM185_ch.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("ch","filelists/pPb_HM250_ch.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("ch","filelists/pPb_HM120_ch.dat", 120, 150, sub1a, sub2a,  Markers, Colors);
  vnptCalc("ch","filelists/pPb_HM150_ch.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("ch","filelists/pPb_HM185_ch.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("ch","filelists/pPb_HM250_ch.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  Markers[0] = 25;
  Markers[1] = 24;
  Colors[0] = kBlue;
  Colors[1] = kRed;
  vnptCalc("Ks","filelists/Pbp_HM120_Ks.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Ks","filelists/Pbp_HM120_Ks.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks","filelists/Pbp_HM150_Ks.dat", 150, 185, sub1, sub2, Markers, Colors);
  vnptCalc("Ks","filelists/Pbp_HM185_Ks.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("Ks","filelists/Pbp_HM250_Ks.dat", 250, 500, sub1, sub2, Markers, Colors);
  vnptCalc("Ks","filelists/Pbp_HM150_Ks.dat", 150, 185, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks","filelists/Pbp_HM185_Ks.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks","filelists/Pbp_HM250_Ks.dat", 250, 500, sub1a, sub2a, Markers, Colors);

  vnptCalc("Ks_SBPos","filelists/Pbp_HM120_Ks_SBPos.dat", 120, 150, sub1, sub2, Markers, Colors);
  //vnptCalc("Ks_SBPos","filelists/Pbp_HM150_Ks_SBPos.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/Pbp_HM185_Ks_SBPos.dat", 185, 250, sub1, sub2, Markers, Colors);
  //vnptCalc("Ks_SBPos","filelists/Pbp_HM250_Ks_SBPos.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/Pbp_HM120_Ks_SBPos.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  //vnptCalc("Ks_SBPos","filelists/Pbp_HM150_Ks_SBPos.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Ks_SBPos","filelists/Pbp_HM185_Ks_SBPos.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  //vnptCalc("Ks_SBPos","filelists/Pbp_HM250_Ks_SBPos.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  vnptCalc("Ks_SBNeg","filelists/Pbp_HM120_Ks_SBNeg.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/Pbp_HM150_Ks_SBNeg.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/Pbp_HM185_Ks_SBNeg.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/Pbp_HM250_Ks_SBNeg.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/Pbp_HM120_Ks_SBNeg.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/Pbp_HM150_Ks_SBNeg.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/Pbp_HM185_Ks_SBNeg.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("Ks_SBNeg","filelists/Pbp_HM250_Ks_SBNeg.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  vnptCalc("Lambda","filelists/Pbp_HM120_Lambda.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda","filelists/Pbp_HM150_Lambda.dat", 150, 185, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda","filelists/Pbp_HM185_Lambda.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda","filelists/Pbp_HM250_Lambda.dat", 250, 500, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda","filelists/Pbp_HM120_Lambda.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda","filelists/Pbp_HM150_Lambda.dat", 150, 185, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda","filelists/Pbp_HM185_Lambda.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda","filelists/Pbp_HM250_Lambda.dat", 250, 500, sub1a, sub2a, Markers, Colors);


  vnptCalc("Lambda_SBPos","filelists/Pbp_HM120_Lambda_SBPos.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/Pbp_HM150_Lambda_SBPos.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/Pbp_HM185_Lambda_SBPos.dat", 185, 250, sub1, sub2, Markers, Colors);
  //vnptCalc("Lambda_SBPos","filelists/Pbp_HM250_Lambda_SBPos.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/Pbp_HM120_Lambda_SBPos.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/Pbp_HM150_Lambda_SBPos.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Lambda_SBPos","filelists/Pbp_HM185_Lambda_SBPos.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  //vnptCalc("Lambda_SBPos","filelists/Pbp_HM250_Lambda_SBPos.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  //vnptCalc("Lambda_SBNeg","filelists/Pbp_HM120_Lambda_SBNeg.dat", 120, 150, sub1, sub2, Markers, Colors);
  vnptCalc("Lambda_SBNeg","filelists/Pbp_HM150_Lambda_SBNeg.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("Lambda_SBNeg","filelists/Pbp_HM185_Lambda_SBNeg.dat", 185, 250, sub1, sub2, Markers, Colors);
  //vnptCalc("Lambda_SBNeg","filelists/Pbp_HM250_Lambda_SBNeg.dat", 250, 600, sub1, sub2, Markers, Colors);
  //vnptCalc("Lambda_SBNeg","filelists/Pbp_HM120_Lambda_SBNeg.dat", 120, 150, sub1a, sub2a, Markers, Colors);
  vnptCalc("Lambda_SBNeg","filelists/Pbp_HM150_Lambda_SBNeg.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("Lambda_SBNeg","filelists/Pbp_HM185_Lambda_SBNeg.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  //vnptCalc("Lambda_SBNeg","filelists/Pbp_HM250_Lambda_SBNeg.dat", 250, 600, sub1a, sub2a, Markers, Colors);

  vnptCalc("ch","filelists/Pbp_HM120_ch.dat", 120, 150, sub1, sub2,  Markers, Colors);
  vnptCalc("ch","filelists/Pbp_HM150_ch.dat", 150, 185, sub1, sub2,  Markers, Colors);
  vnptCalc("ch","filelists/Pbp_HM185_ch.dat", 185, 250, sub1, sub2, Markers, Colors);
  vnptCalc("ch","filelists/Pbp_HM250_ch.dat", 250, 600, sub1, sub2, Markers, Colors);
  vnptCalc("ch","filelists/Pbp_HM120_ch.dat", 120, 150, sub1a, sub2a,  Markers, Colors);
  vnptCalc("ch","filelists/Pbp_HM150_ch.dat", 150, 185, sub1a, sub2a,  Markers, Colors);
  vnptCalc("ch","filelists/Pbp_HM185_ch.dat", 185, 250, sub1a, sub2a, Markers, Colors);
  vnptCalc("ch","filelists/Pbp_HM250_ch.dat", 250, 600, sub1a, sub2a, Markers, Colors);

}

TGraphErrors * vnptCalc(string chan, string flist, int mintrk, int maxtrk, float * sub1, float * sub2, int *Markers, int *Colors){
  std::clock_t start = clock();
  int order = 2;
  FILE * ftest;
  ftest = fopen(flist.data(),"r");
  if(ftest==NULL) {
    cout<<"file not found: "<<flist.data()<<endl;
  } else {
    fclose(ftest);
  }
  std::cout<<"Channel: "<<chan<<"\t"<<mintrk<<"\t"<<maxtrk<<"\t"<<sub1[0]<<"\t"<<sub1[1]<<std::endl;
  //Framework * frame = new Framework(flist);
  std::unique_ptr<Framework> frame(new Framework(flist));
  int iloc = 0;
  
 
  for(int j = 0; j<nptbins; j++) {
    ROI[j] = frame->SetROIRange(order, mintrk,maxtrk, sub1,sub2,  ptbins[j],ptbins[j+1]);
    frame->SetROIEP(ROI[j],HFp2,HFm2,trackmid2,HFm2,HFp2,trackmid2);
    if(ROI[j]<0) {cout<<"ROI ERROR"<<endl; return NULL;}
    ptloc[iloc++] = j;
  }
  int nfiles = 0;
  while(frame->AddFile() ) {++nfiles;}
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
  
  fout->cd();
  TDirectory * subdir=0;
  string subdirName;
  if(flist.find("pPb")!=std::string::npos) {
    subdirName = Form("%s_pPb_%d_%d",chan.data(),mintrk,maxtrk);
  } else {
    subdirName = Form("%s_Pbp_%d_%d",chan.data(),mintrk,maxtrk);
  }
  if((subdir = (TDirectory *) fout->Get(subdirName.data()))==NULL) subdir = fout->mkdir(subdirName.data());
  subdir->cd();
  
  if(fabs(sub1[0])!=fabs(sub1[1])) {
    g[0]->Write("vn_NegEta_PosEtaEP");
    gSub[0]->Write("vn_NegEta_PosEtaEP_SubEvt");
    frame->GetSpectraNegEta()->Write("specNegEta");
    frame->GetSpectraPosEta()->Write("specPosEta");
  } else {
    g[0]->Write("vn_Full_PosEtaEP");
    gSub[0]->Write("vn_Full_PosEtaEP_SubEvt");
  }  

  if(fabs(sub1[0])!=fabs(sub1[1])) {
    g[1]->Write("vn_PosEta_NegEtaEP");
    gSub[1]->Write("vn_PosEta_NegEtaEP_SubEvt");
  } else {  
    g[1]->Write("vn_Full_NegEtaEP");
    gSub[1]->Write("vn_Full_NegEtaEP_SubEvt");
  }
  g[0]->Delete();
  g[1]->Delete();
  gSub[0]->Delete();
  gSub[1]->Delete();
  //delete frame;
  clock_t end = clock();
  double elapsed_secs = double(end-start)/CLOCKS_PER_SEC;
  cout<<"elapsed time (s) = "<<elapsed_secs<<endl;
  return 0;
}

#endif
