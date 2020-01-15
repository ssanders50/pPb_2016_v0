#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TMath.h"
#include "TDirectory.h"
#include <iostream>
#include <unistd.h>
#include <complex>
#include <cmath>
#include "HiEvtPlaneList.h"
using namespace hi;
typedef complex<double> comp;
static const int nptbinsDefault = 16;
static const double ptbinsDefault[]={
  0.2,  0.3,  0.4,  0.5,  0.6,  0.8,  1.0,  1.2,  1.6,  2.0,
  2.5,  3.0,  3.5,  4.0,  5.0,  6.0,  8.0};
static const int netabinsDefault = 12;
static const double etabinsDefault[]={-2.4, -2.0, -1.6, -1.2, -0.8, -0.4, 0.0,  0.4,  0.8,
				      1.2,  1.6,  2.0,  2.4};
static const int ncentbins = 4;
static const double centBins[]={0,10,30,50,80};
static const int ntrkbins = 14;
static const double trkBins[]={0,20,30,40,50,60,80,100,120,150,185,220,260,300,350};
static const double epord_ = 2.;
string rpnames[NumEPNames];
TTree * tree;

double centval;
int noff;
double vtx;
double epang[NumEPNames];
Double_t qx[NumEPNames];
Double_t qy[NumEPNames];
Double_t q[NumEPNames];
Double_t epmult[NumEPNames];
unsigned int  runno_;
Double_t rescor[NumEPNames];
Double_t rescorErr[NumEPNames];
TH2D * qxtrk_;
TH2D * qytrk_;
TH2D * qcnt_;
TH2D * avpt_;

TH2D * vn[20];
TH2D * vnInt[20];
TH2D * vncnt[20];
TH2D * vncntInt[20];
TH2D * vncntIntEffCorr[20];
TH2D * eff[20];
TH2D * effcnt[20];
TH2D * valideff[20];
TH2D * avpt[20];
TH1D * hrescor;
TH1D * vicnt[20];
TH1D * vi[20];

TH2D * vnReSP[20];
TH2D * vnImSP[20];
TH2D * vnSP[20];
TH2D * vnIntSP[20];
TH2D * vncntSP[20];
TH2D * hReQAB[20];
TH2D * hImQAB[20];
TH2D * hReQAC[20];
TH2D * hImQAC[20];
TH2D * hReQBC[20];
TH2D * hImQBC[20];
TH2D * hQcnt[20];
TH2D * hcrescor[20];
TH1D * vicntSP[20];
TH1D * viSP[20];


TFile * tfin;
TFile * tfout;
TH1D * centbin;
TH1D * ntrkbin;
Int_t NumEvnts; 
TString fname;
Bool_t HM;
void ReadTree(int EP,TString file);
TFile * fres;
TFile * feff;
TH2D * heff; 
static const double  minpt = 0.3;
static const double maxpt = 3.0;
static const Bool_t noEff = kTRUE;
TString stag="";

void GenerateVN(){
  if(noEff) {
    stag = "_NoEff";
  } else {
    feff = new TFile("data/TrackCorrections_HIJING_538_OFFICIAL_Mar24.root");
    heff = (TH2D *) feff->Get("rTotalEff3D");
  }

  ReadTree(HFm2,"rpflat_combined.root");



}
void ReadTree(int EP, TString file){ 
  NumEvnts = -1;
  fname = file;
  //TString inFile = Form("/rfs/sanders/pPb/%s.root",file.Data());
  TString inFile = file;
  tfin    = new TFile(inFile.Data(),"read");
  cout<<EPNames[EP].data()<<"  "<<tfin->GetName()<<endl;
  centbin = new TH1D("centbin","centbin",ncentbins,centBins);
  ntrkbin = new TH1D("ntrkbin","ntrkbin",ntrkbins,trkBins);
  qxtrk_  = new TH2D("qxtrk","qxtrk",nptbinsDefault,ptbinsDefault, netabinsDefault, etabinsDefault);
  qytrk_  = new TH2D("qytrk","qytrk",nptbinsDefault,ptbinsDefault, netabinsDefault, etabinsDefault);
  qcnt_   = new TH2D("qcnt","qcnt",nptbinsDefault,ptbinsDefault, netabinsDefault, etabinsDefault);
  avpt_   = new TH2D("avpt_","avpt_",nptbinsDefault,ptbinsDefault, netabinsDefault, etabinsDefault);
  avpt_->Sumw2();
  centbin->Sumw2();
  ntrkbin->Sumw2();
  qxtrk_->Sumw2();
  qytrk_->Sumw2();
  qcnt_->Sumw2();
  qxtrk_->SetOption("colz");
  qytrk_->SetOption("colz");
  qcnt_->SetOption("colz");
  avpt_->SetOption("colz");
  centbin->Reset();
  ntrkbin->Reset();
  qxtrk_->Reset();
  qytrk_->Reset();
  qcnt_->Reset();
  avpt_->Reset();
  
  //  hrescor = new TH1D("rescor","rescor",ntrkbins,trkBins);
  hrescor = new TH1D("rescor","rescor",ncentbins,centBins);
  hrescor->Reset();
  hrescor->Sumw2();
  hrescor->SetMaximum(1.);
 
  for(int i = 0; i<ncentbins; i++) {
    vn[i] =    (TH2D *) qxtrk_->Clone(Form("vn%d",i));
    vncnt[i] =  (TH2D *) qcnt_->Clone(Form("vncnt%d",i));
    eff[i] =    (TH2D *) qcnt_->Clone(Form("eff%d",i));
    effcnt[i] = (TH2D *) qcnt_->Clone(Form("effcnt%d",i));
    avpt[i] =   (TH2D *) avpt_->Clone(Form("avpt%d",i));
    
    vnReSP[i] = (TH2D *) qxtrk_->Clone(Form("vnReSP%d",i));
    vnImSP[i] = (TH2D *) qxtrk_->Clone(Form("vnImSP%d",i));
    vnSP[i] = (TH2D *) qxtrk_->Clone(Form("vnSP%d",i));
    vncntSP[i] =  (TH2D *) qcnt_->Clone(Form("vncntSP%d",i));
    
    vn[i]->Reset();
    vncnt[i]->Reset();
    avpt[i]->Reset();
    eff[i]->Reset();
    effcnt[i]->Reset();
    
    vnReSP[i]->Reset();
    vnImSP[i]->Reset();
    vnSP[i]->Reset();
    vncntSP[i]->Reset();
    
    vn[i]->SetOption("colz");
    vncnt[i]->SetOption("colz");
    eff[i]->SetOption("colz");
    effcnt[i]->SetOption("colz");
    avpt[i]->SetOption("colz");
    
    vnReSP[i]->SetOption("colz");
    vnImSP[i]->SetOption("colz");
    vnSP[i]->SetOption("colz");
    vncntSP[i]->SetOption("colz");
    
    hReQAB[i] = (TH2D *) vn[i]->Clone(Form("ReQAB%d",i));
    hImQAB[i] = (TH2D *) vn[i]->Clone(Form("ImQAB%d",i));
    hReQAC[i] = (TH2D *) vn[i]->Clone(Form("ReQAC%d",i));
    hImQAC[i] = (TH2D *) vn[i]->Clone(Form("ImQAC%d",i));
    hReQBC[i] = (TH2D *) vn[i]->Clone(Form("ReQBC%d",i));
    hImQBC[i] = (TH2D *) vn[i]->Clone(Form("ImQBC%d",i));
    hQcnt[i] = (TH2D *) vn[i]->Clone(Form("ReQcnt%d",i));
    hReQAB[i]->Reset();
    hReQAC[i]->Reset();
    hReQBC[i]->Reset();
    hImQAB[i]->Reset();
    hImQAC[i]->Reset();
    hImQBC[i]->Reset();
    hQcnt[i]->Reset();
    
  }
  tree = (TTree *) tfin->Get("vnanalyzer/tree");
  tree->SetBranchAddress("Cent",       &centval);
  tree->SetBranchAddress("NtrkOff",    &noff);
  tree->SetBranchAddress("Vtx",        &vtx);
  tree->SetBranchAddress("epang",      &epang);
  tree->SetBranchAddress("qx",         &qx);
  tree->SetBranchAddress("qy",         &qy);
  tree->SetBranchAddress("q",          &q);
  tree->SetBranchAddress("mult",       &epmult);
  tree->SetBranchAddress("Run",        &runno_);
  tree->SetBranchAddress("Rescor",     &rescor);
  tree->SetBranchAddress("RescorErr",  &rescorErr);
  tree->SetBranchAddress("qxtrk_v2",      &qxtrk_);
  tree->SetBranchAddress("qytrk_v2",      &qytrk_);
  tree->SetBranchAddress("qcnt_v2",       &qcnt_);
  tree->SetBranchAddress("avpt",        &avpt_);
  
  Double_t rescorAv[20];
  Double_t rescorAvErr[20];
  Double_t rescorCnt[20];
  for(int i = 0; i<20; i++) {
    rescorAv[i]=0;
    rescorAvErr[i]=0;
    rescorCnt[i]=0;
  }
  NumEvnts = NumEvnts<tree->GetEntries() && NumEvnts>0? NumEvnts: tree->GetEntries();
  
  int nextStatus = NumEvnts/20;
  cout<<"Number of Events: "<<NumEvnts<<endl;
  ntrkbin->Reset();
  centbin->Reset();
  for(int ievent = 0; ievent<NumEvnts; ievent++) {
    if(ievent>nextStatus) {
      cout<<(int)(100*nextStatus/NumEvnts)<<"% done"<<endl;
      nextStatus+=NumEvnts/20;
    }
    tree->GetEntry(ievent);
    if(fabs(vtx)>15.) continue;
    if(noff>500) continue;
    
    int bin = -1;
    
    bin = centbin->FindBin(centval)-1;
    if(bin>=ncentbins) continue;
    if(bin<0) continue;
    comp QA (qx[EP],qy[EP]);
    comp QB (qx[RCMate1[EP]], qy[RCMate1[EP]]);
    comp QC (qx[RCMate2[EP]], qy[RCMate2[EP]]);
    comp QAB(0,0);
    comp QAC(0,0);
    comp QBC(0,0);
    QAB=  QA*std::conj(QB);
    QAC=  QA*std::conj(QC);
    QBC=  QB*std::conj(QC);
    
    for(int i = 1; i<= qxtrk_->GetNbinsX(); i++) {
      for(int j = 1; j<= qxtrk_->GetNbinsY(); j++) {
	if(qcnt_->GetBinContent(i,j)>0) {
	  comp ctmp (qxtrk_->GetBinContent(i,j)/qcnt_->GetBinContent(i,j),qytrk_->GetBinContent(i,j)/qcnt_->GetBinContent(i,j)) ;
	  ctmp = ctmp*std::conj(QA);
	  vnReSP[bin]->SetBinContent(i,j,ctmp.real() + vnReSP[bin]->GetBinContent(i,j));
	  vnImSP[bin]->SetBinContent(i,j,ctmp.imag() + vnImSP[bin]->GetBinContent(i,j));
	  vncntSP[bin]->SetBinContent(i,j, vncntSP[bin]->GetBinContent(i,j) + 1.);
	  hReQAB[bin]->SetBinContent(i,j,QAB.real() + hReQAB[bin]->GetBinContent(i,j));
	  hImQAB[bin]->SetBinContent(i,j,QAB.imag() + hImQAB[bin]->GetBinContent(i,j));
	  hReQAC[bin]->SetBinContent(i,j,QAC.real() + hReQAC[bin]->GetBinContent(i,j));
	  hImQAC[bin]->SetBinContent(i,j,QAC.imag() + hImQAC[bin]->GetBinContent(i,j));
	  hReQBC[bin]->SetBinContent(i,j,QBC.real() + hReQBC[bin]->GetBinContent(i,j));
	  hImQBC[bin]->SetBinContent(i,j,QBC.imag() + hImQBC[bin]->GetBinContent(i,j));
	  hQcnt[bin]->SetBinContent(i,j, 1.+ hQcnt[bin]->GetBinContent(i,j));
	  
	}
      }
    }

    ntrkbin->Fill(noff);
    centbin->Fill(centval);
    qxtrk_->Scale(TMath::Cos(epord_*epang[EP]));
    qytrk_->Scale(TMath::Sin(epord_*epang[EP]));
    vn[bin]->Add(qxtrk_);
    vn[bin]->Add(qytrk_);
    vncnt[bin]->Add(qcnt_);
    for(int ipt = 1;     ipt<= qcnt_->GetNbinsX(); ipt++) {
      for(int jeta = 1; jeta<= qcnt_->GetNbinsY(); jeta++) {
	double pt = qcnt_->GetXaxis()->GetBinCenter(ipt);
	double eta = qcnt_->GetYaxis()->GetBinCenter(jeta);
	double veff=1;
	if(heff) {
	  int ieff = heff->GetXaxis()->FindBin(eta);
	  int jeff = heff->GetYaxis()->FindBin(pt);
	  veff = heff->GetBinContent(ieff,jeff);
	} 
	eff[bin]->Fill(pt,eta,veff*qcnt_->GetBinContent(ipt,jeta));
	effcnt[bin]->Fill(pt,eta,qcnt_->GetBinContent(ipt,jeta));
      }
    }
    avpt[bin]->Add(avpt_);
    rescorAv[bin]+=rescor[EP];
    rescorAvErr[bin]+=rescorErr[EP];
    rescorCnt[bin]+=1;
  }
  for(int bin = 0; bin<ncentbins; bin++) {
    if(rescorCnt[bin]<=0) continue;
    TString ctag;
    ctag = Form("%d_%d",(int) centBins[bin],(int) centBins[bin+1]);
    
    vn[bin]->Divide(vncnt[bin]);
    avpt[bin]->Divide(vncnt[bin]);
    eff[bin]->Divide(effcnt[bin]);
    
    rescorAv[bin]/=rescorCnt[bin];
    rescorAvErr[bin]/=rescorCnt[bin];
    hrescor->SetBinContent(bin+1,rescorAv[bin]);
    hrescor->SetBinError(bin+1, rescorAvErr[bin]);
    
    if(rescorAv[bin]>0.005) {      
      vn[bin]->Scale(1./rescorAv[bin]);
      
      vncntInt[bin] = (TH2D *) vncnt[bin]->Clone(Form("vncntInt%d",bin));
      vncntIntEffCorr[bin] = (TH2D *) vncnt[bin]->Clone(Form("vncntIntEffCorr%d",bin));
      if(!noEff) vncntIntEffCorr[bin]->Divide(eff[bin]);
      vnInt[bin] = (TH2D *) vn[bin]->Clone(Form("vnInt%d",bin));
      vnInt[bin]->Multiply(vncntIntEffCorr[bin]);

      valideff[bin] = (TH2D *) effcnt[bin]->Clone("valideff");
      valideff[bin]->Divide(vncnt[bin]);
      valideff[bin]->SetOption("colz");

      Int_t minptb = vnInt[bin]->GetXaxis()->FindBin(minpt);
      Int_t maxptb = vnInt[bin]->GetXaxis()->FindBin(maxpt-0.01);
      vi[bin] = (TH1D *) vnInt[bin]->ProjectionY(Form("vi_%s",ctag.Data()),minptb,maxptb);
      vicnt[bin] = (TH1D *) vncntIntEffCorr[bin]->ProjectionY(Form("vicnt_%s",ctag.Data()),minptb,maxptb);
      vi[bin]->Divide(vicnt[bin]);
    } else { 
      vn[bin]=0;
      vnInt[bin]=0;
      vi[bin] = 0;
      vicnt[bin]=0;
    }
  }
  if(!fopen(Form("results%s_%03.1f_%03.1f",stag.Data(),minpt,maxpt),"r")) system(Form("mkdir results%s_%03.1f_%03.1f",stag.Data(),minpt,maxpt));
  tfout = new TFile(Form("results%s_%03.1f_%03.1f/%s_v%d_%s.root",stag.Data(),minpt,maxpt,fname.Data(),EPOrder[EP],EPNames[EP].data()),"recreate");
  cout<<tfout->GetName()<<endl;
  TDirectory * td[10];
  tfout->cd();

  for(int bin = 0; bin<ncentbins; bin++) {
    if(!vi[bin]) continue;
    TString ctag = Form("%d_%d",(int) centBins[bin],(int) centBins[bin+1]);
    td[bin] = (TDirectory *) tfout->mkdir(Form("%d-%d",(int) centBins[bin],(int) centBins[bin+1]));
    td[bin]->cd();

    hReQAB[bin]->Divide(hQcnt[bin]);
    hImQAB[bin]->Divide(hQcnt[bin]);
    hReQAC[bin]->Divide(hQcnt[bin]);
    hImQAC[bin]->Divide(hQcnt[bin]);
    hReQBC[bin]->Divide(hQcnt[bin]);
    hImQBC[bin]->Divide(hQcnt[bin]);
    
    hcrescor[bin] = (TH2D *) hReQAB[bin]->Clone("crescor");
    hcrescor[bin]->Multiply(hReQAC[bin]);
    hcrescor[bin]->Divide(hReQBC[bin]);
    for(int i = 1; i<=hcrescor[bin]->GetNbinsX(); i++) {
      for(int j = 1; j<=hcrescor[bin]->GetNbinsY(); j++) {
	hcrescor[bin]->SetBinContent(i,j, TMath::Sqrt(hcrescor[bin]->GetBinContent(i,j)));
	hcrescor[bin]->SetBinError(i, 0.5*hcrescor[bin]->GetBinError(i,j)/hcrescor[bin]->GetBinContent(i,j));
      }
    }
    ((TH2D *)vn[bin])->Clone(Form("vn_%s",ctag.Data()))->Write();
    ((TH2D *)vncnt[bin])->Clone(Form("vncnt_%s",ctag.Data()))->Write();
    ((TH2D *)valideff[bin])->Clone(Form("valideff_%s",ctag.Data()))->Write();
    ((TH2D *)eff[bin])->Clone(Form("eff_%s",ctag.Data()))->Write();
    ((TH2D *)effcnt[bin])->Clone(Form("effcnt_%s",ctag.Data()))->Write();
    ((TH2D *)vnInt[bin])->Clone(Form("vnInt_%s",ctag.Data()))->Write();
    ((TH2D *)vncntInt[bin])->Clone(Form("vncntInt_%s",ctag.Data()))->Write();
    ((TH2D *)vncntIntEffCorr[bin])->Clone(Form("vncntIntEffCorr_%s",ctag.Data()))->Write();
    ((TH2D *)avpt[bin])->Clone(Form("avpt_%s",ctag.Data()))->Write();
    vi[bin]->Write();
    vicnt[bin]->Write();
    vncnt[bin]->Write(); 

    for(int i = 1; i<= qxtrk_->GetNbinsX(); i++) {
      for(int j = 1; j<= qxtrk_->GetNbinsY(); j++) {
  	comp ctmp (vnReSP[bin]->GetBinContent(i,j), vnImSP[bin]->GetBinContent(i,j)) ;
  	vnSP[bin]->SetBinContent(i,j,ctmp.real());
      }
    }
    ((TH2D *) vncntSP[bin])->Clone(Form("vncntSP_%s",ctag.Data()))->Write();
    vnSP[bin]->Divide(hQcnt[bin]);
    vnSP[bin]->Divide(hcrescor[bin]);

    vnIntSP[bin] = (TH2D *) vnSP[bin]->Clone(Form("vnIntSP%d",bin));
    vnIntSP[bin]->Multiply(vncntIntEffCorr[bin]);

    Int_t minptb = vnIntSP[bin]->GetXaxis()->FindBin(minpt);
    Int_t maxptb = vnIntSP[bin]->GetXaxis()->FindBin(maxpt-0.01);
    viSP[bin] = (TH1D *) vnIntSP[bin]->ProjectionY(Form("viSP_%s",ctag.Data()),minptb,maxptb);
    vicntSP[bin] = (TH1D *) vncntIntEffCorr[bin]->ProjectionY(Form("vicntSP_%s",ctag.Data()),minptb,maxptb);
    viSP[bin]->Divide(vicntSP[bin]);
    viSP[bin]->SetMarkerColor(kRed);
    ((TH2D *) hcrescor[bin])->Clone(Form("rescorSP_%s",ctag.Data()))->Write();
    ((TH2D *) vnSP[bin])->Clone(Form("vnSP_%s",ctag.Data()))->Write();
    ((TH2D *) vnReSP[bin])->Clone(Form("vnReSP_%s",ctag.Data()))->Write();
    ((TH2D *) vnImSP[bin])->Clone(Form("vnImSP_%s",ctag.Data()))->Write();
    ((TH2D *) hQcnt[bin])->Clone(Form("hQcnt_%s",ctag.Data()))->Write();
    ((TH1D *) viSP[bin])->Clone(Form("viSP_%s",ctag.Data()))->Write();
    ((TH1D *) vicntSP[bin])->Clone(Form("vicntSP_%s",ctag.Data()))->Write();

  }
  hrescor->Write();
  centbin->Write();
  ntrkbin->Write();
  for(int i = 0; i<ncentbins ; i++) {
    if(vn[i]) vn[i]->Delete();
    if(valideff[i]) valideff[i]->Delete();
    if(vncnt[i]) vncnt[i]->Delete();
    if(eff[i]) eff[i]->Delete();
    if(effcnt[i]) effcnt[i]->Delete();
    if(avpt[i]) avpt[i]->Delete();
    if(vi[i]) vi[i]->Delete();
    if(vicnt[i]) vicnt[i]->Delete();
    if(vnInt[i]) vnInt[i]->Delete();
    if(vncntInt[i]) vncntInt[i]->Delete();
    if(vnIntSP[i]) vnIntSP[i]->Delete();
    if(vnSP[i]) vnSP[i]->Delete();
    if(vncntSP[i]) vncntSP[i]->Delete();
    if(vnReSP[i]) vnReSP[i]->Delete();
    if(vnImSP[i]) vnImSP[i]->Delete();
    if(viSP[i]) viSP[i]->Delete();
    if(vicntSP[i]) vicntSP[i]->Delete();
    if(vncntIntEffCorr[i]) vncntIntEffCorr[i]->Delete();    
    if(hReQAB[i]) hReQAB[i]->Delete(); 
    if(hImQAB[i]) hImQAB[i]->Delete();
    if(hReQAC[i]) hReQAC[i]->Delete();
    if(hImQAC[i]) hImQAC[i]->Delete();
    if(hReQBC[i]) hReQBC[i]->Delete();
    if(hImQBC[i]) hImQBC[i]->Delete();
    if(hQcnt[i]) hQcnt[i]->Delete();
    if(hcrescor[i]) hcrescor[i]->Delete();
   
    vn[i] = 0;
    valideff[i] = 0;
    vncnt[i] = 0;
    eff[i] = 0;
    effcnt[i] = 0;
    avpt[i] = 0;
    vi[i] = 0;
    vicnt[i] = 0;
    vnInt[i] = 0;
    vncntInt[i] = 0;

    vnSP[i] = 0;
    vncntSP[i] = 0;
    vnIntSP[i] = 0;
    vnReSP[i] = 0;
    vnImSP[i] = 0;
    viSP[i] = 0;
    vicntSP[i] = 0;
    vncntIntEffCorr[i] = 0;
    hReQAB[i] = 0;
    hImQAB[i] = 0;
    hReQAC[i] = 0;
    hImQAC[i] = 0;
    hReQBC[i] = 0;
    hImQBC[i] = 0;
    hQcnt[i] = 0;
    hcrescor[i] = 0;
  }
  tfout->Close();
  avpt_->Delete();
  centbin->Delete();
  ntrkbin->Delete();
  qxtrk_->Delete();
  qytrk_->Delete();
  qcnt_->Delete();
  hrescor->Delete();
  tfin->Close();
}
