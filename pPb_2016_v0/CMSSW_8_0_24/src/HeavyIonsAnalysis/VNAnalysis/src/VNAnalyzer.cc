// -*- C++ -*-
//
// Package:    VNAnalyzer
// Class:      VNAnalyzer
// 

// system include files
#include <memory>
#include <algorithm>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "Math/Vector3D.h"

#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "DataFormats/HeavyIonEvent/interface/Centrality.h"
#include "DataFormats/HeavyIonEvent/interface/EvtPlane.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include <DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h>
#include <DataFormats/ParticleFlowCandidate/interface/PFCandidate.h>

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "CondFormats/DataRecord/interface/HeavyIonRPRcd.h"
#include "CondFormats/DataRecord/interface/HeavyIonRcd.h"
#include "CondFormats/HIObjects/interface/CentralityTable.h"
#include "CondFormats/HIObjects/interface/RPFlatParams.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidateFwd.h"
#include "HeavyIonsAnalysis/VNAnalysis/interface/TrackEfficiency.h"
#include "TROOT.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TTree.h"
#include "TH1I.h"
#include "TF1.h"
#include "TMath.h"
#include "TRandom.h"
#include <time.h>
#include <cstdlib>
	
#include <vector>
using std::vector;
using std::rand;
using namespace std;
#include "RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneFlatten.h"
#include "RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneList.h"
#include "RecoHI/HiEvtPlaneAlgos/interface/LoadEPDB.h"
using namespace hi;
using namespace edm;

static const int ntrkbins = 5;
static const  double trkBins[]={0, 120, 150, 185, 250, 500};

static const int ncentbins = 13;
static const  double centbins[]={0, 5, 10, 15, 20, 25, 30, 35, 40,  50, 60, 70, 80, 100};

static const int nptbins = 13;
static const float ptbins[]={0.2, 0.4, 0.6,  0.8,  1.0,  1.40,  1.8,
			      2.2,  2.8,  3.6,  4.6,  6.0,  7.0, 8.5};

static const int netabinsDefault = 4;
static const float etabinsDefault[]={-2.0, -1.0, 0.,   1.0, 2.0};

static const int nanals = 1;
enum AnalType {
    N2,      N3,      N4
};
string AnalNames[]={
 "N2",    "N3",      "N4"
};


//
// class declaration
//

class VNAnalyzer : public edm::EDAnalyzer {
public:
  explicit VNAnalyzer(const edm::ParameterSet&);
  ~VNAnalyzer();
      
private:
  int NtrkToBin(int ntrk){
    for(int i = 0; i<=ntrkbins; i++) {
      if(ntrk < trkBins[i]) return i;
    }
    return ntrkbins;
  }
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
#include "HeavyIonsAnalysis/VNAnalysis/interface/rescor.h"
  bool CaloMatch(const reco::Track & track, const edm::Event & iEvent, unsigned int idx);
  // ----------member data ---------------------------
  int eporder_;

  std::string centralityVariable_;
  std::string centralityLabel_;
  std::string centralityMC_;
  edm::InputTag qwTagPhi_;
  edm::EDGetTokenT<std::vector<double>> qwtokenPhi;
  edm::InputTag qwTagEta_;
  edm::EDGetTokenT<std::vector<double>> qwtokenEta;
  edm::InputTag qwTagRapidity_;
  edm::EDGetTokenT<std::vector<double>> qwtokenRapidity;
  edm::InputTag qwTagPt_;
  edm::EDGetTokenT<std::vector<double>> qwtokenPt;
  edm::InputTag qwTagMass_;
  edm::EDGetTokenT<std::vector<double>> qwtokenMass;
  edm::InputTag qwTagWeight_;
  edm::EDGetTokenT<std::vector<double>> qwtokenWeight;

  std::string reaction_;
  edm::InputTag centralityBinTag_;
  edm::EDGetTokenT<int> centralityBinToken;
  edm::Handle<int> cbin_;
  edm::EDGetTokenT<int> tag_;
  edm::InputTag centralityTag_;
  edm::EDGetTokenT<reco::Centrality> centralityToken;
  edm::Handle<reco::Centrality> centrality_;

  edm::InputTag pfTag_;
  edm::EDGetTokenT<reco::PFCandidateCollection> pfToken_;

  edm::InputTag vertexTag_;
  edm::EDGetTokenT<std::vector<reco::Vertex>> vertexToken;
  edm::Handle<std::vector<reco::Vertex>> vertex_;

  edm::InputTag trackTag_;
  edm::EDGetTokenT<reco::TrackCollection> trackToken;
  edm::Handle<reco::TrackCollection> trackCollection_;

  edm::InputTag inputPlanesTag_;
  edm::EDGetTokenT<reco::EvtPlaneCollection> inputPlanesToken;
  edm::Handle<reco::EvtPlaneCollection> inputPlanes_;

  edm::Service<TFileService> fs;

  double caloCentRef_;
  double caloCentRefWidth_;
  int caloCentRefMinBin_;
  int caloCentRefMaxBin_;

  bool useNtrk_;

  int vs_sell;   // vertex collection size
  float vzr_sell;
  float vzErr_sell;
  TH1D * hcent;

  TH1D * hcentbins;
  TH1D * hcentres;
  TH1D * hptNtrk;
  TH1D * hptNtrkGood;
  TH1I * hNtrkRet;

  TH1D * hqwPhi;
  TH1D * hqwEta;
  TH1D * hqwRapidity;
  TH1D * hqwPt;
  TH1D * hqwMass;
  TH1D * hqwWeight;

  //  TH2D * hEff[ntrkbins];
  double centval;
  double vtx;
  Double_t epang[NumEPNames];
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
  TH1D * hsumw[NumEPNames];
  unsigned int runno_;
  Int_t ntrkval;
  Int_t Noff;

  double reso_;
  bool bCaloMatching_;
  int nvtx_;
  double minvz_;
  double maxvz_;
  double dzdzerror_pix_;
  double chi2_;

  double dzdzerror_;
  double d0d0error_;
  double pterror_;

  Double_t epsin[NumEPNames];
  Double_t epcos[NumEPNames];

  TH1D * hPsi[NumEPNames];
  TH1D * hPsiOffset[NumEPNames];
  TH1D * hPsiFlat[NumEPNames];

  TH1D * hEP_BA[NumEPNames];
  TH1D * hEP_CA[NumEPNames];
  TH1D * hEP_CB[NumEPNames];
  TH1D * hEP_BAcnt[NumEPNames];
  TH1D * hEP_CAcnt[NumEPNames];
  TH1D * hEP_CBcnt[NumEPNames];
  TH1D * hMult[NumEPNames];

  TH1D * hNtrk;
  TH1D * hNoff;
  int nEtaBins;
  TH1I * hrun;
  string rpnames[NumEPNames];
  string effTable_;
  TTree * tree;
  TrackEfficiency *teff;
  int FlatOrder_;
  int NumFlatBins_;
  int CentBinCompression_;
  int Noffmin_;
  int Noffmax_;
  TH2F * qxtrk[3];
  TH2F * qytrk[3];
  TH2F * qcnt;
  TH2F * avpt;
  TH2D * res[3][ntrkbins];
  TH2D * resw[3][ntrkbins];
  TH2D * resep[3][ntrkbins];
  TH2D * rescnt[3][ntrkbins];
  TH2D * ptspec[ntrkbins];
  TH2D * ptspecCnt[ntrkbins];
  HiEvtPlaneFlatten * flat[NumEPNames];
  bool loadDB_;
  bool useNtrkBins_; 
  bool bypassCentrality_;
  bool FirstEvent_;
  bool makeTree_;
  bool Recenter_;
  int minrun_;
  int maxrun_;

  int nCentBins_ = 1;
  int ntrack;


  //==============  Harmonics ============
  TH2D * ptav[ntrkbins];
  TH2D * ptcnt[ntrkbins];
  TH2D * badcnt[ntrkbins];
  //TH2D * qA[ntrkbins][11];
  //TH2D * qB[ntrkbins][11];
  TH1D * qres;
  //TH1D * qBA[ntrkbins][11];
  //TH1D * qCA[ntrkbins][11];
  //TH1D * qCB[ntrkbins][11];
  //TH1D * qBAcnt[ntrkbins][11];
  //TH1D * qCAcnt[ntrkbins][11];
  //TH1D * qCBcnt[ntrkbins][11];
  TH2D * qxav[3][ntrkbins];
  TH2D * qyav[3][ntrkbins];
  TH2D * qxycnt[ntrkbins];
  //TH2D * wnA[ntrkbins][11];
  //TH2D * wnB[ntrkbins][11];
  //TH1D * rBA[ntrkbins][11];
  //TH1D * rCA[ntrkbins][11];
  //TH1D * rCB[ntrkbins][11];
  //TH1D * rBAcnt[ntrkbins][11];
  //TH1D * rCAcnt[ntrkbins][11];
  //TH1D * rCBcnt[ntrkbins][11];
  TH2D * hTemplate;
  TH2D * qxt = 0;
  TH2D * qyt = 0;
  TH2D * qct = 0;
  TH2D * qxy = 0;
  TH2D * qxxy = 0;
  TH2D * qxyy = 0;
  TH2D * qx2y3 = 0;
  TH2D * qy2x3 = 0;
  TH2D * qx2x2x3;
  TH2D * qx2x3y2;
  TH2D * qx3y2y2;
  TH2D * qx2x2y3;
  TH2D * qx2y2y3;
  TH2D * qy2y2y3;
  TH2D * qcnt3;

  struct qvec {
    TH2D * qA[ntrkbins][11];
    TH2D * qB[ntrkbins][11];
    TH2D * wnA[ntrkbins][11];
    TH2D * wnB[ntrkbins][11];
    TH2D * rA[ntrkbins][11];
    TH2D * rB[ntrkbins][11];
    TH2D * rAcnt[ntrkbins][11];
    TH2D * rBcnt[ntrkbins][11];
    TH1D * qBA[ntrkbins][11];
    TH1D * qCA[ntrkbins][11];
    TH1D * qCB[ntrkbins][11];
    TH1D * qBAcnt[ntrkbins][11];
    TH1D * qCAcnt[ntrkbins][11];
    TH1D * qCBcnt[ntrkbins][11];
    TH1D * rBA[ntrkbins][11];
    TH1D * rCA[ntrkbins][11];
    TH1D * rCB[ntrkbins][11];
    TH1D * rBAcnt[ntrkbins][11];
    TH1D * rCAcnt[ntrkbins][11];
    TH1D * rCBcnt[ntrkbins][11];
    TH1D * wA[ntrkbins][11];
    TH1D * wB[ntrkbins][11];
    TH1D * wC[ntrkbins][11];
  } qanal[nanals];

  //===================================

  
  TH2D * Eff_0_5;
  TH2D * Eff_5_10;
  TH2D * Eff_10_30;
  TH2D * Eff_30_50;
  TH2D * Eff_50_100;
  enum    TrackCut {trackUndefine = 0, ppReco = 1, HIReco, Pixel};
  TrackCut sTrackQuality;
  bool TrackQuality_ppReco(const reco::TrackCollection::const_iterator&, const reco::VertexCollection&);
  bool TrackQuality_HIReco(const reco::TrackCollection::const_iterator&, const reco::VertexCollection&);
  bool TrackQuality_Pixel(const reco::TrackCollection::const_iterator&, const reco::VertexCollection&);


  TRandom * ran;
  bool Fill_N(int anal,int n, int bin, TH2F *qxtrk_, TH2F * qytrk_, TH2F * qcnt_, double Ax, double Ay, double Bx, double By, double Cx, double Cy, double wA, double wB, double wC, double thA, double thB, double thC){
    bool stat = false;
    if(pow(Ax,2)+pow(Ay,2) < 1e-6) return stat;
    if(pow(Bx,2)+pow(By,2) < 1e-6) return stat;
    if(pow(Cx,2)+pow(Cy,2) < 1e-6) return stat;
    for(int i = 1; i<=qxtrk_->GetNbinsX(); i++) {
      for(int j = 1; j<=qxtrk_->GetNbinsY(); j++) {
	if(qxtrk_->GetBinContent(i,j)!=0) {
	  double th = TMath::ATan2(qytrk_->GetBinContent(i,j),qxtrk_->GetBinContent(i,j));
	  qanal[anal].rA[bin][0]->SetBinContent(i,j,qanal[anal].rA[bin][0]->GetBinContent(i,j)+TMath::Cos(n*(th-thA)));
	  qanal[anal].rB[bin][0]->SetBinContent(i,j,qanal[anal].rB[bin][0]->GetBinContent(i,j)+TMath::Cos(n*(th-thB)));
	  qanal[anal].rAcnt[bin][0]->SetBinContent(i,j,qanal[anal].rAcnt[bin][0]->GetBinContent(i,j)+1);
	  qanal[anal].rBcnt[bin][0]->SetBinContent(i,j,qanal[anal].rBcnt[bin][0]->GetBinContent(i,j)+1);
	}
      }
    }
    qanal[anal].qA[bin][0]->Add(qxtrk_,Ax);
    qanal[anal].qA[bin][0]->Add(qytrk_,Ay);
    qanal[anal].qB[bin][0]->Add(qxtrk_,Bx);
    qanal[anal].qB[bin][0]->Add(qytrk_,By);
    qanal[anal].wnA[bin][0]->Add(qcnt_,wA);
    qanal[anal].wnB[bin][0]->Add(qcnt_,wB);
    qanal[anal].qBA[bin][0]->Fill(0.,Bx*Ax + By*Ay);
    qanal[anal].qCA[bin][0]->Fill(0.,Cx*Ax + Cy*Ay);
    qanal[anal].qCB[bin][0]->Fill(0.,Cx*Bx + Cy*By);
    qanal[anal].qBAcnt[bin][0]->Fill(0.,wB*wA);
    qanal[anal].qCAcnt[bin][0]->Fill(0.,wC*wA);
    qanal[anal].qCBcnt[bin][0]->Fill(0.,wC*wB);
    qanal[anal].wA[bin][0]->Fill(wA);
    qanal[anal].wB[bin][0]->Fill(wB);
    qanal[anal].wC[bin][0]->Fill(wC);
    qanal[anal].rBA[bin][0]->Fill(0.,TMath::Cos(n*(thB-thA)));
    qanal[anal].rCA[bin][0]->Fill(0.,TMath::Cos(n*(thC-thA)));
    qanal[anal].rCB[bin][0]->Fill(0.,TMath::Cos(n*(thC-thB)));
    qanal[anal].rBAcnt[bin][0]->Fill(0.);
    qanal[anal].rCAcnt[bin][0]->Fill(0.);
    qanal[anal].rCBcnt[bin][0]->Fill(0.);
    
    int j=(int)(ran->Uniform(0,9.999))+1;
    qanal[anal].qA[bin][j]->Add(qxtrk_,Ax);
    qanal[anal].qA[bin][j]->Add(qytrk_,Ay);
    qanal[anal].qB[bin][j]->Add(qxtrk_,Bx);
    qanal[anal].qB[bin][j]->Add(qytrk_,By);
    qanal[anal].wnA[bin][j]->Add(qcnt_,wA);
    qanal[anal].wnB[bin][j]->Add(qcnt_,wB);
    qanal[anal].qBA[bin][j]->Fill(0.,Bx*Ax + By*Ay);
    qanal[anal].qCA[bin][j]->Fill(0.,Cx*Ax + Cy*Ay);
    qanal[anal].qCB[bin][j]->Fill(0.,Cx*Bx + Cy*By);
    qanal[anal].qBAcnt[bin][j]->Fill(0.,wB*wA);
    qanal[anal].qCAcnt[bin][j]->Fill(0.,wC*wA);
    qanal[anal].qCBcnt[bin][j]->Fill(0.,wC*wB);
    qanal[anal].wA[bin][j]->Fill(wA);
    qanal[anal].wB[bin][j]->Fill(wB);
    qanal[anal].wC[bin][j]->Fill(wC);
    qanal[anal].rBA[bin][j]->Fill(0.,TMath::Cos(n*(thB-thA)));
    qanal[anal].rCA[bin][j]->Fill(0.,TMath::Cos(n*(thC-thA)));
    qanal[anal].rCB[bin][j]->Fill(0.,TMath::Cos(n*(thC-thB)));
    qanal[anal].rBAcnt[bin][j]->Fill(0.);
    qanal[anal].rCAcnt[bin][j]->Fill(0.);
    qanal[anal].rCBcnt[bin][j]->Fill(0.);
    stat = true;
    for(int i = 1; i<=qxtrk_->GetNbinsX(); i++) {
      for(int k = 1; k<=qxtrk_->GetNbinsY(); k++) {
	if(qxtrk_->GetBinContent(i,k)!=0) {
	  double th = TMath::ATan2(qytrk_->GetBinContent(i,k),qxtrk_->GetBinContent(i,k));
	  qanal[anal].rA[bin][j]->SetBinContent(i,k,qanal[anal].rA[bin][j]->GetBinContent(i,k)+TMath::Cos(n*(th-thA)));
	  qanal[anal].rB[bin][j]->SetBinContent(i,k,qanal[anal].rB[bin][j]->GetBinContent(i,k)+TMath::Cos(n*(th-thB)));
	  qanal[anal].rAcnt[bin][j]->SetBinContent(i,k,qanal[anal].rAcnt[bin][0]->GetBinContent(i,k)+1);
	  qanal[anal].rBcnt[bin][j]->SetBinContent(i,k,qanal[anal].rBcnt[bin][0]->GetBinContent(i,k)+1);
	}
      }
    }
    return stat;
  }
  
  //===================================
  
 Int_t getNoff(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
    int N = 0;
    using namespace edm;
    using namespace reco;
    iEvent.getByToken(vertexToken,vertex_);
    VertexCollection recoVertices = *vertex_;
    int primaryvtx = 0;
    double hold_d0d0error_ = d0d0error_;
    double hold_dzdzerror_ = dzdzerror_;
    double hold_pterror_ = pterror_;
    double hold_dzdzerror_pix_ = dzdzerror_pix_;
    double hold_chi2_ = chi2_;
    d0d0error_ = 3.;
    dzdzerror_ = 3.;
    pterror_ = 0.1;
    if(sTrackQuality == ppReco) {
      if ( recoVertices.size() > 100 ) return -1;
      sort(recoVertices.begin(), recoVertices.end(), [](const reco::Vertex &a, const reco::Vertex &b){
	  if ( a.tracksSize() == b.tracksSize() ) return a.chi2() < b.chi2();
	  return a.tracksSize() > b.tracksSize();
	});
    } else {
      sort(recoVertices.begin(), recoVertices.end(), [](const reco::Vertex &a, const reco::Vertex &b){
	  return a.tracksSize() > b.tracksSize();
	});    
    }
    
    vtx = recoVertices[primaryvtx].z();
    if (fabs(vtx) < minvz_ || fabs(vtx) > maxvz_) {
      return -1;
    }        
    
    iEvent.getByLabel(trackTag_,trackCollection_);
    
    for(TrackCollection::const_iterator itTrack = trackCollection_->begin(); itTrack != trackCollection_->end(); ++itTrack) { 
      if ( sTrackQuality == HIReco and not TrackQuality_HIReco(itTrack, recoVertices) ) continue;
      else if ( sTrackQuality == ppReco and not TrackQuality_ppReco(itTrack, recoVertices) ) continue;
      else if ( sTrackQuality == Pixel  and not TrackQuality_Pixel (itTrack, recoVertices) ) continue;
      
      if( itTrack->pt() < 0.4 ) continue;
      ++N;
    }
    d0d0error_ = hold_d0d0error_;
    dzdzerror_ = hold_dzdzerror_;
    pterror_ = hold_pterror_;
    dzdzerror_pix_ = hold_dzdzerror_pix_;
    chi2_ = hold_chi2_;
    return N;
  }
  
  
  Int_t fillTracks(const edm::Event& iEvent, const edm::EventSetup& iSetup, int bin)
  {
    int Ntrk = 0;
    using namespace edm;
    using namespace reco;
    for(int i = 2; i<=4; i++) {
      qxtrk[i-2]->Reset();
      qytrk[i-2]->Reset();
    }
    
    qcnt->Reset();
    avpt->Reset();
    
    //
    //Access qw vector
    //
    Handle<std::vector<double>> tPhi;
    iEvent.getByLabel(qwTagPhi_, tPhi);
    Handle<std::vector<double>> tEta;
    iEvent.getByLabel(qwTagEta_, tEta);
    Handle<std::vector<double>> tRapidity;
    iEvent.getByLabel(qwTagRapidity_, tRapidity);
    Handle<std::vector<double>> tPt;
    iEvent.getByLabel(qwTagPt_, tPt);
    Handle<std::vector<double>> tMass;
    iEvent.getByLabel(qwTagMass_, tMass);
    Handle<std::vector<double>> tWeight;
    iEvent.getByLabel(qwTagWeight_, tWeight);
        
    iEvent.getByToken(vertexToken,vertex_);
    VertexCollection recoVertices = *vertex_;
    int primaryvtx = 0;
    if(sTrackQuality == ppReco) {
      if ( recoVertices.size() > 100 ) return -1;
      sort(recoVertices.begin(), recoVertices.end(), [](const reco::Vertex &a, const reco::Vertex &b){
	  if ( a.tracksSize() == b.tracksSize() ) return a.chi2() < b.chi2();
	  return a.tracksSize() > b.tracksSize();
	});
    } else {
      sort(recoVertices.begin(), recoVertices.end(), [](const reco::Vertex &a, const reco::Vertex &b){
	  return a.tracksSize() > b.tracksSize();
	});    
    }
    
    vtx = recoVertices[primaryvtx].z();
    if (fabs(vtx) < minvz_ || fabs(vtx) > maxvz_) {
      return -1;
    }        
    
    iEvent.getByLabel(trackTag_,trackCollection_);
    
    for(TrackCollection::const_iterator itTrack = trackCollection_->begin(); itTrack != trackCollection_->end(); ++itTrack) { 
      if ( sTrackQuality == HIReco and not TrackQuality_HIReco(itTrack, recoVertices) ) continue;
      else if ( sTrackQuality == ppReco and not TrackQuality_ppReco(itTrack, recoVertices) ) continue;
      else if ( sTrackQuality == Pixel  and not TrackQuality_Pixel (itTrack, recoVertices) ) continue; 
      
      if( itTrack->pt() < 0.4 ) continue;
      ++Ntrk;
    }
    
    for(int i = 0; i<(int)tPhi->size(); i++) {
      double phi = (*tPhi)[i];
      hqwPhi->Fill(phi);
      double eta = (*tEta)[i];
      hqwEta->Fill(eta);
      double Rapidity = (*tRapidity)[i];
      hqwRapidity->Fill(Rapidity);
      double pt = (*tPt)[i];
      hqwPt->Fill(pt);
      double mass = (*tMass)[i];
      hqwMass->Fill(mass);
      double weight = (*tWeight)[i];
      hqwWeight->Fill(weight);
      double eff = 1.;
      for(int iorder = 2; iorder <=4; iorder++) {
	qxtrk[iorder-2]->Fill(pt, eta, eff*(TMath::Cos(iorder*phi)));
	qytrk[iorder-2]->Fill(pt, eta, eff*(TMath::Sin(iorder*phi)));
      }
      qcnt->Fill(pt, eta, eff);
      avpt->Fill(pt, eta, eff*pt);
      ptspec[bin]->Fill(pt,eta,pt);
      ptspecCnt[bin]->Fill(pt,eta);
    
    }

    return Ntrk;
  }
};


//
// constructors and destructor
//
VNAnalyzer::VNAnalyzer(const edm::ParameterSet& iConfig):runno_(0)
  
{
  ran = new TRandom();
  ran->SetSeed(0);
  runno_ = 0;
  loadDB_ = kTRUE;
  FirstEvent_ = kTRUE;
  for(int i = 0; i<NumEPNames; i++) {
    epang[i] = -10;
    eporig[i] = -10;
    epsin[i] = 0;
    epcos[i] = 0;
    qx[i] = 0;
    qy[i] = 0;
    q[i] = 0;
    epmult[i] = 0;
    rescor[i] = 0;
    rescorErr[i] = 0;
  }
  qwTagPhi_ = iConfig.getParameter<edm::InputTag>("qwTagPhi_");
  qwtokenPhi = consumes<std::vector<double>>(qwTagPhi_);

  qwTagEta_ = iConfig.getParameter<edm::InputTag>("qwTagEta_");
  qwtokenEta = consumes<std::vector<double>>(qwTagEta_);

  qwTagRapidity_ = iConfig.getParameter<edm::InputTag>("qwTagRapidity_");
  qwtokenRapidity = consumes<std::vector<double>>(qwTagRapidity_);

  qwTagPt_ = iConfig.getParameter<edm::InputTag>("qwTagPt_");
  qwtokenPt = consumes<std::vector<double>>(qwTagPt_);

  qwTagMass_ = iConfig.getParameter<edm::InputTag>("qwTagMass_");
  qwtokenMass = consumes<std::vector<double>>(qwTagMass_);

  qwTagWeight_ = iConfig.getParameter<edm::InputTag>("qwTagWeight_");
  qwtokenWeight = consumes<std::vector<double>>(qwTagWeight_);

  centralityVariable_ = iConfig.getParameter<std::string>("centralityVariable");
  if(iConfig.exists("nonDefaultGlauberModel")){
    centralityMC_ = iConfig.getParameter<std::string>("nonDefaultGlauberModel");
  }
  centralityLabel_ = centralityVariable_+centralityMC_;


  centralityBinTag_ = iConfig.getParameter<edm::InputTag>("centralityBinTag_");
  centralityBinToken = consumes<int>(centralityBinTag_);

  centralityTag_ = iConfig.getParameter<edm::InputTag>("centralityTag_");
  centralityToken = consumes<reco::Centrality>(centralityTag_);
  if(centralityToken.isUninitialized()) {
    std::cout<<"centralityToken is uninitialized."<<std::endl;
  }
  reaction_ = iConfig.getParameter<std::string>("reaction_");

  vertexTag_  = iConfig.getParameter<edm::InputTag>("vertexTag_");
  vertexToken = consumes<std::vector<reco::Vertex>>(vertexTag_);
  if(vertexToken.isUninitialized()) {
    std::cout<<"vertexToken is uninitialized."<<std::endl;
  }

  trackTag_ = iConfig.getParameter<edm::InputTag>("trackTag_");
  trackToken = consumes<reco::TrackCollection>(trackTag_);
  if(trackToken.isUninitialized()) {
    std::cout<<"trackToken is uninitialized."<<std::endl;
  }
  if ( trackTag_.label() == "hiGeneralTracks" ) {
    sTrackQuality = HIReco;
    cout<<"hiGeneralTracks"<<endl;
  } else if ( trackTag_.label() == "generalTracks" ) {
    sTrackQuality = ppReco;
    cout<<"generalTracks"<<endl;
  } else if ( trackTag_.label() == "hiGeneralAndPixelTracks" ) {
    sTrackQuality = Pixel;
    cout<<"hiGeneralAndPixelTracks"<<endl;
  } else {
    sTrackQuality = trackUndefine;
  }
  useNtrk_ = iConfig.getUntrackedParameter<bool>("useNtrk",false);
  if(useNtrk_) {
    NumFlatBins_ = ntrkbins;
    CentBinCompression_ = 1;
  }

  inputPlanesTag_ = iConfig.getParameter<edm::InputTag>("inputPlanesTag_");
  inputPlanesToken = consumes<reco::EvtPlaneCollection>(inputPlanesTag_);
  if(inputPlanesToken.isUninitialized()) {
    std::cout<<"inputPlanesToken is uninitialized."<<std::endl;
  }
  tag_ = consumes<int>(iConfig.getParameter<edm::InputTag>("BinLabel"));

  FlatOrder_ = iConfig.getUntrackedParameter<int>("FlatOrder_", 9);
  NumFlatBins_ = iConfig.getUntrackedParameter<int>("NumFlatBins_",20);
  caloCentRef_ = iConfig.getUntrackedParameter<double>("caloCentRef_",80.);
  caloCentRefWidth_ = iConfig.getUntrackedParameter<double>("caloCentRefWidth_",5.);
  CentBinCompression_ = iConfig.getUntrackedParameter<int>("CentBinCompression_",5);
  Noffmin_ = iConfig.getUntrackedParameter<int>("Noffmin_", 0);
  Noffmax_ = iConfig.getUntrackedParameter<int>("Noffmax_", 50000);	
  minrun_ = iConfig.getUntrackedParameter<int>("minrun_", 0);
  maxrun_ = iConfig.getUntrackedParameter<int>("maxrun_", 50000);	
  effTable_ = iConfig.getParameter<std::string>("effTable_");
  bCaloMatching_ = iConfig.getUntrackedParameter<bool>("bCaloMaching", false);
  Recenter_ = iConfig.getUntrackedParameter<bool>("Recenter",true);
  makeTree_ = iConfig.getUntrackedParameter<bool>("makeTree_",false);

  nvtx_ = iConfig.getUntrackedParameter<int>("nvtx_", 100);
  reso_ = iConfig.getUntrackedParameter<double>("reso", 0.2);
  if(reso_<0.01) bCaloMatching_ = false;
  if(bCaloMatching_) {
    pfTag_ = iConfig.getUntrackedParameter<edm::InputTag>("pfTag");
    pfToken_ = consumes<reco::PFCandidateCollection>(pfTag_);
  }
  dzdzerror_ = iConfig.getUntrackedParameter<double>("dzdzerror_", 3.);
  d0d0error_ = iConfig.getUntrackedParameter<double>("d0d0error_", 3.);
  pterror_ = iConfig.getUntrackedParameter<double>("pterror_",0.1);
  dzdzerror_pix_ = iConfig.getUntrackedParameter<double>("dzdzerror_pix_") ;
  chi2_  = iConfig.getUntrackedParameter<double>("chi2_") ;
  teff = 0;
  if(effTable_!="NULL") teff = new TrackEfficiency(effTable_.data());
  minvz_ = iConfig.getUntrackedParameter<double>("minvz_", -15.);
  maxvz_ = iConfig.getUntrackedParameter<double>("maxvz_", 15.);

  std::cout<<"==============================================="<<std::endl;
  std::cout<<"reaction_                   "<<reaction_<<std::endl;
  std::cout<<"centralityBinTag_           "<<centralityBinTag_.encode()<<std::endl;
  std::cout<<"centralityTag_              "<<centralityTag_.encode()<<std::endl;
  std::cout<<"vertexTag_                  "<<vertexTag_.encode()<<std::endl;
  std::cout<<"trackTag_                   "<<trackTag_.encode()<<std::endl;
  std::cout<<"inputPlanesTag_             "<<inputPlanesTag_.encode()<<std::endl;
  std::cout<<"FlatOrder_                  "<<FlatOrder_<<std::endl;
  std::cout<<"NumFlatBins_                "<<NumFlatBins_<<std::endl;
  std::cout<<"caloCentRef_                "<<caloCentRef_<<std::endl;
  std::cout<<"caloCentRefWidth_           "<<caloCentRefWidth_<<std::endl;
  std::cout<<"CentBinCompression_         "<<CentBinCompression_<<std::endl;
  std::cout<<"Noffmin_                    "<<Noffmin_<<std::endl;
  std::cout<<"Noffmax_                    "<<Noffmax_<<std::endl;
  std::cout<<"minrun_                     "<<minrun_<<std::endl;
  std::cout<<"maxrun_                     "<<maxrun_<<std::endl;
  std::cout<<"effTable_                   "<<effTable_<<std::endl;
  std::cout<<"dzerror_                    "<<dzdzerror_<<endl;
  std::cout<<"d0error_                    "<<d0d0error_<<endl;
  std::cout<<"pterror_                    "<<pterror_<<endl;
  std::cout<<"nvtx_                       "<<nvtx_<<endl;
  if(bCaloMatching_) { 
    std::cout<<"bCaloMatching_              true"<<std::endl;
    std::cout<<"reso_                     "<<reso_<<std::endl;   
  }
  std::cout<<"dzdzerror_pix_               "<<dzdzerror_pix_<<std::endl;
  std::cout<<"chi2_                        "<<chi2_<<std::endl;
  if(Recenter_) { 
    std::cout<<"Recenter_                  true"<<std::endl;
  } else {
    std::cout<<"Recenter_                  false"<<std::endl;
  }
  if(useNtrk_) { 
    std::cout<<"Ntrk binning                  "<<std::endl;
  } else {
    std::cout<<"Centrality binning            "<<std::endl;
  }

  //====================================================
  //========= Spectra =================================
  TFileDirectory specdir = fs->mkdir("Spectra");
  for(int i = 0; i<ntrkbins; i++) {
    TFileDirectory specsubdir;
    if(useNtrk_) {
      specsubdir = specdir.mkdir(Form("%d_%d",(int)trkBins[i],(int)trkBins[i+1]));
    } else {
      specsubdir = specdir.mkdir(Form("%d_%d",(int)centbins[i],(int)centbins[i+1]));
    }
    ptspec[i] =  specsubdir.make<TH2D>("ptspec","ptspec",nptbins,ptbins, netabinsDefault, etabinsDefault);
    ptspec[i]->Sumw2();
    ptspec[i]->SetXTitle("p_{T} (GeV/c)");
    ptspec[i]->SetYTitle("Yield");
    ptspec[i]->SetOption("colz");

    ptspecCnt[i] =  specsubdir.make<TH2D>("ptspecCnt","ptspecCnt",nptbins,ptbins, netabinsDefault, etabinsDefault);
    ptspecCnt[i]->Sumw2();
    ptspecCnt[i]->SetXTitle("p_{T} (GeV/c)");
    ptspecCnt[i]->SetYTitle("Yield");
    ptspecCnt[i]->SetOption("colz");
  }
 
  if(makeTree_) std::cout<<"Make tree"<<std::endl;
  std::cout<<"==============================================="<<std::endl;
  TDirectory * save = gDirectory;
  TFileDirectory conddir = fs->mkdir("Conditions");
  conddir.make<TH1I>(centralityBinTag_.label().data(),centralityBinTag_.label().data(),1,0,1);
  conddir.make<TH1I>(centralityTag_.label().data(), centralityTag_.label().data(),1,0,1);
  conddir.make<TH1I>(vertexTag_.label().data(), vertexTag_.label().data(),1,0,1);
  conddir.make<TH1I>(trackTag_.label().data(), trackTag_.label().data(),1,0,1);
  conddir.make<TH1I>(inputPlanesTag_.label().data(), inputPlanesTag_.label().data(),1,0,1);
  string note_reaction = Form("Reaction_%s",reaction_.data());
  conddir.make<TH1I>(note_reaction.data(),note_reaction.data(),1,0,1); 
  string etable = Form("EffTable_%s",effTable_.data());
  conddir.make<TH1I>(etable.data(), etable.data(),1,0,1);
  string note_FlatOrder = Form("FlatOrder_%d",FlatOrder_);
  conddir.make<TH1I>(note_FlatOrder.data(), note_FlatOrder.data(),1,0,1);
  string note_NumFlatBins = Form("NumFlatBins_%d",NumFlatBins_);
  conddir.make<TH1I>(note_NumFlatBins.data(), note_NumFlatBins.data(),1,0,1);
  string note_caloCentRef = Form("caloCentRef_%d",(int)caloCentRef_);
  conddir.make<TH1I>(note_caloCentRef.data(), note_caloCentRef.data(),1,0,1);
  string note_caloCentRefWidth = Form("caloCentRefWidth_%d",(int)caloCentRefWidth_);
  conddir.make<TH1I>(note_caloCentRefWidth.data(), note_caloCentRefWidth.data(),1,0,1);
  string note_dzdzerror = Form("dzdzerror_%07.2f",dzdzerror_);
  conddir.make<TH1I>(note_dzdzerror.data(), note_dzdzerror.data(),1,0,1);
  string note_d0d0error = Form("d0d0error_%07.2f",d0d0error_);
  conddir.make<TH1I>(note_d0d0error.data(), note_d0d0error.data(),1,0,1);
  string note_dzdzerror_pix = Form("dzdzerror_pix_%07.2f",dzdzerror_pix_);
  conddir.make<TH1I>(note_dzdzerror_pix.data(), note_dzdzerror_pix.data(),1,0,1);
  string note_chi2 = Form("chi2_%07.2f",chi2_);
  conddir.make<TH1I>(note_chi2.data(), note_chi2.data(),1,0,1);
  string note_vtx_range = Form("vtx_%5.1f_%5.1f",minvz_,maxvz_);
  conddir.make<TH1I>(note_vtx_range.data(), note_vtx_range.data(),1,0,1);
  string note_nvtx = Form("nvtx_%d",nvtx_);
  conddir.make<TH1I>(note_nvtx.data(), note_nvtx.data(),1,0,1);
  if(bCaloMatching_) {
    conddir.make<TH1I>("bCaloMatching_Set_True", "bCaloMatching_Set_True",1,0,1);
    string note_reso = Form("reso_%07.2f",reso_);
    conddir.make<TH1I>(note_reso.data(),note_reso.data(),1,0,1);
  } else {
    conddir.make<TH1I>("bCaloMatching_Set_False", "bCaloMatching_Set_False",1,0,1);
  }
  if(Recenter_) {
    conddir.make<TH1I>("RecenterTracks", "RecenterTracks",1,0,1);
  } else {
    conddir.make<TH1I>("DoNotRecenterTracks", "DoNotRecenterTracks",1,0,1);
  }
  if(useNtrk_) {
    conddir.make<TH1I>("useNtrk_Set_True", "useNtrk_Set_True",1,0,1);
  } else {
    conddir.make<TH1I>("useNtrk_Set_False", "useNtrk_Set_False",1,0,1);
  }
  
  save->cd();
  hNtrk = fs->make<TH1D>("Ntrk","Ntrk",1001,0,3000);
  hNoff = fs->make<TH1D>("Noff","Noff",1001,0,3000);
  int npt = nptbins;
  for(int iorder = 2; iorder<=4; iorder++) {
    qxtrk[iorder-2] = fs->make<TH2F>(Form("qxtrk%d",iorder),Form("qxtrk%d",iorder),npt,ptbins, netabinsDefault, etabinsDefault);
    qytrk[iorder-2] = fs->make<TH2F>(Form("qytrk%d",iorder),Form("qytrk%d",iorder),npt,ptbins, netabinsDefault, etabinsDefault);
    qxtrk[iorder-2]->SetOption("colz");
    qytrk[iorder-2]->SetOption("colz");
    qxtrk[iorder-2]->Sumw2();
    qytrk[iorder-2]->Sumw2();
  }
  qcnt =  fs->make<TH2F>("qcnt", "qcnt",npt,ptbins, netabinsDefault, etabinsDefault);
  avpt =  fs->make<TH2F>("avpt","avpt",npt,ptbins, netabinsDefault, etabinsDefault);
  qcnt->SetOption("colz");
  avpt->SetOption("colz");
  qcnt->Sumw2();
  avpt->Sumw2();
  hTemplate = (TH2D *) qcnt->Clone("hTemplate");
  hTemplate->SetDirectory(0);
  hTemplate->Reset();

  hqwPhi = fs->make<TH1D>("qwPhi","qwPhi",500, -4,4);
  hqwEta = fs->make<TH1D>("qwEta","qwEta",500,-2.5,2.5);
  hqwRapidity = fs->make<TH1D>("qwRapidity","qwRapidity",500,-2,2);
  hqwPt = fs->make<TH1D>("qwPt","qwPt",1000,0,10);
  hqwMass = fs->make<TH1D>("qwMass","qwMass",4000,0,2);
  hqwWeight = fs->make<TH1D>("qwWeight","qwWeight",100,-2,2);

  hcent = fs->make<TH1D>("cent","cent",220,-10,110);
  hcentbins = fs->make<TH1D>("centbins","centbins",201,0,200);
  hcentres = fs->make<TH1D>("centres","centres",ntrkbins,trkBins);
  hrun = fs->make<TH1I>("runs","runs",maxrun_-minrun_+1,minrun_,maxrun_);
  hptNtrk = fs->make<TH1D>("ptNtrk","ptNtrk",npt,ptbins);
  hptNtrk->SetXTitle("p_{T} (GeV/c)");
  hptNtrk->SetYTitle("Ntrks (|#eta|<1; 0-5)");
  hptNtrkGood = fs->make<TH1D>("ptNtrkGood","ptNtrkGood",npt,ptbins);
  hptNtrkGood->SetXTitle("p_{T} (GeV/c)");
  hptNtrkGood->SetYTitle("Ntrks (Good) (|#eta|<1; 0-5)");
  hNtrkRet = fs->make<TH1I>("NtrkRet","NtrkRet", 10,0,10);
  TString epnames = EPNames[0].data();
  epnames = epnames+"/D";
  NumFlatBins_ = ntrkbins;
  for(int i = 0; i<NumEPNames; i++) {
    if(i>0) epnames = epnames + ":" + EPNames[i].data() + "/D";
    TFileDirectory subdir = fs->mkdir(Form("%s",EPNames[i].data()));
    flat[i] = new HiEvtPlaneFlatten();
    flat[i]->init(FlatOrder_,NumFlatBins_,EPNames[i],EPOrder[i]);
    Double_t psirange = 4;
    if(EPOrder[i]==1 ) psirange = 3.5;
    if(EPOrder[i]==2 ) psirange = 2;
    if(EPOrder[i]==3 ) psirange = 1.5;
    if(EPOrder[i]==4 ) psirange = 1;
    if(EPOrder[i]==5) psirange = 0.8;
    if(EPOrder[i]==6) psirange = 0.6;
    if(EPOrder[i]==7) psirange = 0.5;

    hPsi[i] = subdir.make<TH1D>("psi","psi",800,-psirange,psirange);
    hPsi[i]->SetXTitle("#Psi");
    hPsi[i]->SetYTitle(Form("Counts (cent<80%c)",'%'));
    
    hPsiOffset[i] = subdir.make<TH1D>("psiOffset","psiOffset",800,-psirange,psirange);
    hPsiOffset[i]->SetXTitle("#Psi");
    hPsiOffset[i]->SetYTitle(Form("Counts (cent<80%c)",'%'));

    
    hPsiFlat[i] = subdir.make<TH1D>("psiFlat","psiFlat",800,-psirange,psirange);
    hPsiFlat[i]->SetXTitle("#Psi");
    hPsiFlat[i]->SetYTitle(Form("Counts (cent<80%c)",'%'));

    hEP_BA[i] = subdir.make<TH1D>("BA","BA",1,0,1);
    hEP_CA[i] = subdir.make<TH1D>("CA","CA",1,0,1);
    hEP_CB[i] = subdir.make<TH1D>("CB","CB",1,0,1);
    hEP_BAcnt[i] = subdir.make<TH1D>("BAcnt","BAcnt",1,0,1);
    hEP_CAcnt[i] = subdir.make<TH1D>("CAcnt","CAcnt",1,0,1);
    hEP_CBcnt[i] = subdir.make<TH1D>("CBcnt","CBcnt",1,0,1);
    hMult[i] = subdir.make<TH1D>("mult","mult",601,0,600);
    hsumw[i] = subdir.make<TH1D>("sumw","sumw",200,0,400);


  }
  //=====================
  TFileDirectory hardir = fs->mkdir("Harmonics");
  qxt = (TH2D *) hTemplate->Clone("qxt");
  qyt = (TH2D *) hTemplate->Clone("qyt");
  qct = (TH2D *) hTemplate->Clone("qct");
  
  qxy = (TH2D *) hTemplate->Clone("qxy");
  qxxy = (TH2D *) hTemplate->Clone("qxxy");
  qxyy = (TH2D *) hTemplate->Clone("qxyy");
  qx2y3 = (TH2D *) hTemplate->Clone("qx2y3");
  qy2x3 = (TH2D *) hTemplate->Clone("qy2x3");
  qx2x2x3= (TH2D *) hTemplate->Clone("qx2x2x3");
  qx2x3y2= (TH2D *) hTemplate->Clone("qx2x3y2");
  qx3y2y2= (TH2D *) hTemplate->Clone("qx3y2y2");
  qx2x2y3= (TH2D *) hTemplate->Clone("qx2x2y3");
  qx2y2y3= (TH2D *) hTemplate->Clone("qx2y2y3");
  qy2y2y3= (TH2D *) hTemplate->Clone("qy2y2y3");    
  qcnt3  = (TH2D *) hTemplate->Clone("qcnt3");
  qxy->SetDirectory(0);
  qxxy->SetDirectory(0);
  qxyy->SetDirectory(0);
  qx2y3->SetDirectory(0);
  qy2x3->SetDirectory(0);
  qx2x2x3->SetDirectory(0);
  qx2x3y2->SetDirectory(0);
  qx3y2y2->SetDirectory(0);
  qx2x2y3->SetDirectory(0);
  qx2y2y3->SetDirectory(0);
  qy2y2y3->SetDirectory(0);
  qcnt3->SetDirectory(0);
  int nanalbins = ntrkbins;

  //==============   Resolution terms  ========
  TFileDirectory resdir = fs->mkdir("Resolutions");
  for(int i = 0; i<nanalbins; i++) {
    TFileDirectory ressubdir;
    for(int iorder = 2; iorder<=4; iorder++) {
      if(useNtrk_) {
	ressubdir = resdir.mkdir(Form("%d_%d",(int)trkBins[i],(int)trkBins[i+1]));
      } else {
	ressubdir = resdir.mkdir(Form("%d_%d",(int)centbins[i],(int)centbins[i+1]));
      }
      res[iorder-2][i] = ressubdir.make<TH2D>(Form("res%d",iorder),Form("res%d",iorder),46,0,46,46,0,46);
      resw[iorder-2][i] = ressubdir.make<TH2D>(Form("resw%d",iorder),Form("resw%d",iorder),46,0,46,46,0,46);
      resep[iorder-2][i] = ressubdir.make<TH2D>(Form("resep%d",iorder),Form("resep%d",iorder),46,0,46,46,0,46);
      rescnt[iorder-2][i] = ressubdir.make<TH2D>(Form("rescnt%d",iorder),Form("rescnt%d",iorder),46,0,46,46,0,46);
      res[iorder-2][i]->Reset();
      res[iorder-2][i]->Sumw2();
      res[iorder-2][i]->SetOption("colz");
      resw[iorder-2][i]->Reset();
      resw[iorder-2][i]->Sumw2();
      resw[iorder-2][i]->SetOption("colz");
      resep[iorder-2][i]->Reset();
      resep[iorder-2][i]->Sumw2();
      resep[iorder-2][i]->SetOption("colz");
      rescnt[iorder-2][i]->Reset();
      rescnt[iorder-2][i]->Sumw2();
      rescnt[iorder-2][i]->SetOption("colz");
    }
  }


  for(int i = 0; i<nanalbins; i++) {

    TFileDirectory subdir;
    if(useNtrk_) {
      subdir= hardir.mkdir(Form("%d_%d",(int)trkBins[i],(int)trkBins[i+1]));
    } else {
      subdir = hardir.mkdir(Form("%d_%d",(int)centbins[i],(int)centbins[i+1]));
    }
    ptav[i] = subdir.make<TH2D>("ptav","ptav",npt,ptbins, netabinsDefault, etabinsDefault);
    ptcnt[i] = subdir.make<TH2D>("ptcnt","ptcnt",npt,ptbins, netabinsDefault, etabinsDefault);
    badcnt[i] = subdir.make<TH2D>("badcnt","badcnt",npt,ptbins, netabinsDefault, etabinsDefault);
    for(int iorder = 2; iorder<=4; iorder++) {
      qxav[iorder-2][i] = subdir.make<TH2D>(Form("qxav%d",iorder),Form("qxav%d",iorder),npt,ptbins, netabinsDefault, etabinsDefault);
      qyav[iorder-2][i] = subdir.make<TH2D>(Form("qyav%d",iorder),Form("qyav%d",iorder),npt,ptbins, netabinsDefault, etabinsDefault);
      qxav[iorder-2][i]->Sumw2();
      qyav[iorder-2][i]->Sumw2();
      qxav[iorder-2][i]->SetOption("colz");
      qyav[iorder-2][i]->SetOption("colz");
    }
    qxycnt[i] = subdir.make<TH2D>("qxcnt","qxcnt",npt,ptbins, netabinsDefault, etabinsDefault);

    ptav[i]->Sumw2();
    ptcnt[i]->Sumw2();
    badcnt[i]->Sumw2();
    qxycnt[i]->Sumw2();

    ptav[i]->SetOption("colz");
    ptcnt[i]->SetOption("colz");
    badcnt[i]->SetOption("colz");
    qxycnt[i]->SetOption("colz");

    for(int ian = 0; ian<nanals; ian++) {
      TFileDirectory andir = subdir.mkdir(AnalNames[ian].data());
      
      qanal[ian].qA[i][0] = andir.make<TH2D>("qA","qA",npt,ptbins, netabinsDefault, etabinsDefault);
      qanal[ian].qB[i][0] = andir.make<TH2D>("qB","qB",npt,ptbins, netabinsDefault, etabinsDefault);
      qanal[ian].wnA[i][0] = andir.make<TH2D>("wnA","wnA",npt,ptbins, netabinsDefault, etabinsDefault);
      qanal[ian].wnB[i][0] = andir.make<TH2D>("wnB","wnB",npt,ptbins, netabinsDefault, etabinsDefault);
      qanal[ian].qA[i][0]->Sumw2();
      qanal[ian].qB[i][0]->Sumw2();
      qanal[ian].wnA[i][0]->Sumw2();
      qanal[ian].wnB[i][0]->Sumw2();
      qanal[ian].qA[i][0]->SetOption("colz");
      qanal[ian].qB[i][0]->SetOption("colz");
      qanal[ian].wnA[i][0]->SetOption("colz");
      qanal[ian].wnB[i][0]->SetOption("colz");

      qanal[ian].rA[i][0] = andir.make<TH2D>("rA","rA",npt,ptbins, netabinsDefault, etabinsDefault);
      qanal[ian].rB[i][0] = andir.make<TH2D>("rB","rB",npt,ptbins, netabinsDefault, etabinsDefault);
      qanal[ian].rAcnt[i][0] = andir.make<TH2D>("rAcnt","rAcnt",npt,ptbins, netabinsDefault, etabinsDefault);
      qanal[ian].rBcnt[i][0] = andir.make<TH2D>("rBcnt","rBcnt",npt,ptbins, netabinsDefault, etabinsDefault);
      
      qanal[ian].qBA[i][0] = andir.make<TH1D>("qBA","qBA",1,0,1);
      qanal[ian].qCA[i][0] = andir.make<TH1D>("qCA","qCA",1,0,1);
      qanal[ian].qCB[i][0] = andir.make<TH1D>("qCB","qCB",1,0,1);
      qanal[ian].qBAcnt[i][0] = andir.make<TH1D>("qBAcnt","qBAcnt",1,0,1);
      qanal[ian].qCAcnt[i][0] = andir.make<TH1D>("qCAcnt","qCAcnt",1,0,1);
      qanal[ian].qCBcnt[i][0] = andir.make<TH1D>("qCBcnt","qCBcnt",1,0,1);
      qanal[ian].wA[i][0] = andir.make<TH1D>("wA","wA",200,0,400);
      qanal[ian].wB[i][0] = andir.make<TH1D>("wB","wB",200,0,400);
      qanal[ian].wC[i][0] = andir.make<TH1D>("wC","wC",200,0,400);
      qanal[ian].rBA[i][0] = andir.make<TH1D>("rBA","rBA",1,0,1);
      qanal[ian].rCA[i][0] = andir.make<TH1D>("rCA","rCA",1,0,1);
      qanal[ian].rCB[i][0] = andir.make<TH1D>("rCB","rCB",1,0,1);
      qanal[ian].rBAcnt[i][0] = andir.make<TH1D>("rBAcnt","rBAcnt",1,0,1);
      qanal[ian].rCAcnt[i][0] = andir.make<TH1D>("rCAcnt","rCAcnt",1,0,1);
      qanal[ian].rCBcnt[i][0] = andir.make<TH1D>("rCBcnt","rCBcnt",1,0,1);
      
      TFileDirectory subev = andir.mkdir("SubEvents");
      for(int j = 1; j<=10; j++) {	  
	qanal[ian].qA[i][j] = subev.make<TH2D>(Form("qA_%d",j),Form("qA_%d",j),npt,ptbins, netabinsDefault, etabinsDefault); 
	qanal[ian].qB[i][j] = subev.make<TH2D>(Form("qB_%d",j),Form("qB_%d",j),npt,ptbins, netabinsDefault, etabinsDefault);
	qanal[ian].wnA[i][j] = subev.make<TH2D>(Form("wnA_%d",j),Form("wnA_%d",j),npt,ptbins, netabinsDefault, etabinsDefault);
	qanal[ian].wnB[i][j] = subev.make<TH2D>(Form("wnB_%d",j),Form("wnB_%d",j),npt,ptbins, netabinsDefault, etabinsDefault);
	qanal[ian].qA[i][j]->Sumw2();
	qanal[ian].qB[i][j]->Sumw2();
	qanal[ian].wnA[i][j]->Sumw2();
	qanal[ian].wnB[i][j]->Sumw2();
	qanal[ian].qA[i][j]->SetOption("colz");
	qanal[ian].qB[i][j]->SetOption("colz");
	qanal[ian].wnA[i][j]->SetOption("colz");
	qanal[ian].wnB[i][j]->SetOption("colz");
	
	qanal[ian].rA[i][j] = andir.make<TH2D>(Form("rA_%d",j),Form("rA_%d",j),npt,ptbins, netabinsDefault, etabinsDefault);
	qanal[ian].rB[i][j] = andir.make<TH2D>(Form("rB_%d",j),Form("rB_%d",j),npt,ptbins, netabinsDefault, etabinsDefault);
	qanal[ian].rAcnt[i][j] = andir.make<TH2D>(Form("rAcnt_%d",j),Form("rAcnt_%d",j),npt,ptbins, netabinsDefault, etabinsDefault);
	qanal[ian].rBcnt[i][j] = andir.make<TH2D>(Form("rBcnt_%d",j),Form("rBcnt_%d",j),npt,ptbins, netabinsDefault, etabinsDefault);

	qanal[ian].qBA[i][j] = subev.make<TH1D>(Form("qBA_%d",j),Form("qBA_%d",j),1,0,1);
	qanal[ian].qCA[i][j] = subev.make<TH1D>(Form("qCA_%d",j),Form("qCA_%d",j),1,0,1);      
	qanal[ian].qCB[i][j] = subev.make<TH1D>(Form("qCB_%d",j),Form("qCB_%d",j),1,0,1);
	
	qanal[ian].qBAcnt[i][j] = subev.make<TH1D>(Form("qBAcnt_%d",j),Form("qBAcnt_%d",j),1,0,1);
	qanal[ian].qCAcnt[i][j] = subev.make<TH1D>(Form("qCAcnt_%d",j),Form("qCAcnt_%d",j),1,0,1);      
	qanal[ian].qCBcnt[i][j] = subev.make<TH1D>(Form("qCBcnt_%d",j),Form("qCBcnt_%d",j),1,0,1);
	
	qanal[ian].wA[i][j] = andir.make<TH1D>(Form("wA_%d",j),Form("wA_%d",j),100,0,2000);
	qanal[ian].wB[i][j] = andir.make<TH1D>(Form("wB_%d",j),Form("wB_%d",j),100,0,2000);
	qanal[ian].wC[i][j] = andir.make<TH1D>(Form("wC_%d",j),Form("wC_%d",j),100,0,2000);

	
	qanal[ian].rBA[i][j] = subev.make<TH1D>(Form("rBA_%d",j),Form("rBA_%d",j),1,0,1);
	qanal[ian].rCA[i][j] = subev.make<TH1D>(Form("rCA_%d",j),Form("rCA_%d",j),1,0,1);      
	qanal[ian].rCB[i][j] = subev.make<TH1D>(Form("rCB_%d",j),Form("rCB_%d",j),1,0,1);
	
	qanal[ian].rBAcnt[i][j] = subev.make<TH1D>(Form("rBAcnt_%d",j),Form("rBAcnt_%d",j),1,0,1);
	qanal[ian].rCAcnt[i][j] = subev.make<TH1D>(Form("rCAcnt_%d",j),Form("rCAcnt_%d",j),1,0,1);      
	qanal[ian].rCBcnt[i][j] = subev.make<TH1D>(Form("rCBcnt_%d",j),Form("rCBcnt_%d",j),1,0,1);
      }
      
    }
  }
  //==============================
  
  
  if(makeTree_) {
    tree = fs->make<TTree>("tree","EP tree");
    tree->Branch("Cent",&centval,"Cent/D");
    tree->Branch("Vtx",&vtx,"Vtx/D");
    tree->Branch("epang",&epang, epnames.Data());
    tree->Branch("eporig",&eporig, epnames.Data());
    tree->Branch("qx",      &qx,       epnames.Data());
    tree->Branch("qy",      &qy,       epnames.Data());
    tree->Branch("q",       &q,       epnames.Data());
    tree->Branch("vn", &vn, epnames.Data());
    tree->Branch("mult",    &epmult,  epnames.Data());
    tree->Branch("sumw",    &sumw,  epnames.Data());
    tree->Branch("sumw2",    &sumw2,  epnames.Data());
    tree->Branch("Rescor",  &rescor,   epnames.Data());
    tree->Branch("RescorErr",  &rescorErr,   epnames.Data());
    tree->Branch("qxtrk2",  "TH2F",  &qxtrk[0], 128000, 0);
    tree->Branch("qytrk2",  "TH2F",  &qytrk[0], 128000, 0);
    tree->Branch("qxtrk3",  "TH2F",  &qxtrk[1], 128000, 0);
    tree->Branch("qytrk3",  "TH2F",  &qytrk[1], 128000, 0);
    tree->Branch("qxtrk4",  "TH2F",  &qxtrk[2], 128000, 0);
    tree->Branch("qytrk4",  "TH2F",  &qytrk[2], 128000, 0);
    tree->Branch("qcnt",    "TH2F",  &qcnt, 128000, 0);
    tree->Branch("avpt",    "TH2F",  &avpt, 128000, 0);
    tree->Branch("Run",     &runno_,   "runno_/i");
    tree->Branch("NtrkOff",&Noff,"Noff/I");
    tree->Branch("ntrkval",&ntrkval,"ntrkval/I");
  }
}


VNAnalyzer::~VNAnalyzer()
{
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
}


//
// member functions
//

// ------------ method called to for each event  ------------
void
VNAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;
  Bool_t newrun = kFALSE;
  if(runno_ != iEvent.id().run()) newrun = kTRUE;
  runno_ = iEvent.id().run();
  hrun->Fill(runno_);
  if(FirstEvent_ || newrun) {
    FirstEvent_ = kFALSE;
    newrun = kFALSE;
    //
    // Get flattening parameter file.  
    //
    edm::ESHandle<RPFlatParams> flatparmsDB_;
    iSetup.get<HeavyIonRPRcd>().get(flatparmsDB_);
    LoadEPDB * db = new LoadEPDB(flatparmsDB_,flat);
    if(!db->IsSuccess()) {
      std::cout<<"Flattening db inconsistancy, will continue without: "<<std::endl;
      loadDB_ = kFALSE;
    }        
  } //First event
  
  
  //
  // Get Centrality
  //

  int bin = 0;
  int cbin = 0;
    
  iEvent.getByToken(centralityToken, centrality_);
  Noff = getNoff(iEvent, iSetup);
  hNoff->Fill(Noff);
  bin = NtrkToBin(Noff)-1;
  cbin = bin;
  centval = Noff;
  hcentres->Fill(Noff);
  
  int ibin = hcentres->FindBin(centval)-1;
  if(ibin<0) return;
  hcent->Fill(centval);
  hcentbins->Fill(cbin);
  
  
  if (fabs(vtx) < minvz_ || fabs(vtx) > maxvz_) return;
  ntrkval=fillTracks(iEvent, iSetup, ibin);
  hNtrk->Fill(ntrkval);
  //
  // Get Event Planes
  //
  iEvent.getByToken(inputPlanesToken,inputPlanes_);
  
  if(!inputPlanes_.isValid()){
    cout << "Error! Can't get hiEvtPlaneFlat product!" << endl;
    return ;
  }
  
  Int_t indx = 0;
  for(int i = 0; i<NumEPNames; i++) {
    epang[i] = -10;
    epsin[i] = 0;
    epcos[i] = 0;
    qx[i] = 0;
    qy[i] = 0;
    q[i] = 0;
    vn[i] = 0;
    epmult[i] = 0;
    sumw[i] = 0;
    sumw2[i] = 0;
  }
  for (EvtPlaneCollection::const_iterator rp = inputPlanes_->begin();rp !=inputPlanes_->end(); rp++) {
    if(indx != rp->indx() ) {
      cout<<"EP inconsistency found. Abort."<<endl;
      return;
    }
    if(rp->sumSin()!=0 || rp->sumCos()!=0) {
      if(rp->mult()>3 && fabs(vtx)<15 ) {
		epang[indx]=rp->angle();
		eporig[indx]=rp->angle(0);
		epsin[indx] = rp->sumSin();
		epcos[indx] = rp->sumCos();
		hPsi[indx]->Fill(rp->angle(0));
		hPsiOffset[indx]->Fill(rp->angle(1));
		hPsiFlat[indx]->Fill(rp->angle(2));
		qx[indx]  = rp->qx(); 
		qy[indx]  = rp->qy();
		q[indx]   = rp->q();
		vn[indx] = rp->vn(0);
		epmult[indx] = (double) rp->mult();
		sumw[indx] = rp->sumw();
		hsumw[indx]->Fill(sumw[indx]);
		sumw2[indx] = rp->sumw2();
		hMult[indx]->Fill((double) rp->mult());
		int trkbin = hcentres->FindBin(Noff);
		if(reaction_.find("pPb")!=std::string::npos) {
		  rescor[indx] = rescor_pPb[indx][trkbin];
		  rescorErr[indx] = rescor_pPb[indx][trkbin+25];
		} else {
		  rescor[indx] = rescor_Pbp[indx][trkbin];
		  rescorErr[indx] = rescor_Pbp[indx][trkbin+25];	
	}
		//cout<<"rescor: "<<indx<<"\t"<<Noff<<"\t"<<rescor[indx]<<"\t"<<rescorErr[indx]<<endl;
      } 
    }
    ++indx; 
  }
  bool epstat = false;
  for(int i = 0; i<NumEPNames; i++) {
    if(epang[i]>-10 && epang[RCMate1[i]]>-10&&epang[RCMate2[i]]>-10) {
      hEP_BA[i]->Fill(0.,TMath::Cos(EPOrder[i]*(epang[i]-epang[RCMate1[i]])));
      hEP_CA[i]->Fill(0.,TMath::Cos(EPOrder[i]*(epang[i]-epang[RCMate2[i]])));
      hEP_CB[i]->Fill(0.,TMath::Cos(EPOrder[i]*(epang[RCMate1[i]]-epang[RCMate2[i]])));
      hEP_BAcnt[i]->Fill(0.);
      hEP_CAcnt[i]->Fill(0.);
      hEP_CBcnt[i]->Fill(0.);
      if(i==HFp2) epstat = true;
    }
  }
  ptav[ibin]->Add(avpt);
  ptcnt[ibin]->Add(qcnt);
  for(int iorder = 2; iorder<=4; iorder++) {
    qxav[iorder-2][ibin]->Add(qxtrk[iorder-2]);
    qyav[iorder-2][ibin]->Add(qytrk[iorder-2]);
  }
  qxycnt[ibin]->Add(qcnt);
  bool stat = false;
  for(int ian = 0; ian<nanals; ian++) {
    if(ian==N2) stat = Fill_N( N2, 2,  ibin, qxtrk[0], qytrk[0], qcnt, qx[HFp2], qy[HFp2], qx[HFm2], qy[HFm2], qx[trackmid2], qy[trackmid2], sumw[HFp2], sumw[HFm2], sumw[trackmid2], epang[HFp2], epang[HFm2], epang[trackmid2]);
    if(ian==N3) stat = Fill_N( N3, 3,  ibin, qxtrk[1], qytrk[1], qcnt, qx[HFp3], qy[HFp3], qx[HFm3], qy[HFm3], qx[trackmid3], qy[trackmid3], sumw[HFp3], sumw[HFm3], sumw[trackmid3], epang[HFp3], epang[HFm3], epang[trackmid3]);
    if(ian==N4) stat = Fill_N( N4, 4,  ibin, qxtrk[2], qytrk[2], qcnt, qx[HFp4], qy[HFp4], qx[HFm4], qy[HFm4], qx[trackmid4], qy[trackmid4], sumw[HFp4], sumw[HFm4], sumw[trackmid4], epang[HFp4], epang[HFm4], epang[trackmid4]);
  }
  
  if(epstat==false || stat == false) {
    cout<<"Inconsistency "<<epstat<<"\t"<<stat<<"\t"<<qx[HFp2]<<"\t"<<qy[HFp2]<<"\t"<<qx[HFm2]<<"\t"<<qy[HFp2]<<"\t"<<qx[trackmid2]<<"\t"<<qy[trackmid2]<<"\t"<<sumw[HFp2]<<"\t"<<sumw[HFm2]<<"\t"<<sumw[trackmid2]<<"\t"<<epang[HFp2]<<"\t"<<epang[HFm2]<<"\t"<<epang[trackmid2]<<endl;
  }
  for(int iorder = 2; iorder <=4; iorder++) {
    int epmin = 0;
    int epmax = 0;
    if (iorder == 2) {
      epmin = HFm2;
      epmax = HFp2f;
    }else if (iorder == 3) {
      epmin = HFm3;
      epmax = HFp3f;
    }else if (iorder == 4) {
      epmin = HFm4;
      epmax = HFp4f;
    }
    for(int i = epmin; i<= epmax; i++) {
      for(int j = i; j<=epmax; j++) {
  	int ii = i-epmin+1;
  	int jj = j-epmin+1;
  	double w =(pow(qx[i],2)+pow(qy[i],2))*(pow(qx[j],2)+pow(qy[j],2));
  	if(w>0) {
  	  res[iorder-2][ibin]->SetBinContent(ii,jj,    res[iorder-2][ibin]->GetBinContent(ii,jj)+(qx[i]*qx[j]+qy[i]*qy[j]));
  	  resw[iorder-2][ibin]->SetBinContent(ii,jj,   resw[iorder-2][ibin]->GetBinContent(ii,jj)+sumw[i]*sumw[j]);
  	  resep[iorder-2][ibin]->SetBinContent(ii,jj,  resep[iorder-2][ibin]->GetBinContent(ii,jj)+(qx[i]*qx[j]+qy[i]*qy[j])/sqrt(w));
  	  rescnt[iorder-2][ibin]->SetBinContent(ii,jj, rescnt[iorder-2][ibin]->GetBinContent(ii,jj)+1.);
  	}
      }
    }
  }
  if(makeTree_) {
    //cout<<Noff<<"\t"<<ntrkval<<endl;
    tree->Fill(); 
  }
}



// ------------ method called once each job just before starting event loop  ------------
void 
VNAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
VNAnalyzer::endJob() {
  
}
bool
VNAnalyzer::CaloMatch(const reco::Track & track, const edm::Event & iEvent, unsigned int idx)
{
  if ( !bCaloMatching_ ) return true;
  edm::Handle<reco::PFCandidateCollection> pfCand;
  iEvent.getByToken( pfToken_, pfCand );
  double energy = 0;
  for ( reco::PFCandidateCollection::const_iterator it = pfCand->begin(); it != pfCand->end(); ++it ) {
    reco::TrackRef trackRef = it->trackRef();
    if ( !((it->particleId() != reco::PFCandidate::h) ||
	   (it->particleId() != reco::PFCandidate::e) ||
	   (it->particleId() != reco::PFCandidate::mu) )) continue;
    if ( idx == trackRef.key() ) {
      energy = it->ecalEnergy() + it->hcalEnergy();
      break;
    }
  }
  
  if( track.pt() < 20 || ( energy/( track.pt()*TMath::CosH(track.eta() ) ) > reso_ && (energy)/(TMath::CosH(track.eta())) > (track.pt() - 80.0) )  ) return true;
  else {
    return false;
  }
}
///
bool
VNAnalyzer::TrackQuality_ppReco(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices)
{
  if ( itTrack->charge() == 0 ) return false;
  if ( !itTrack->quality(reco::TrackBase::highPurity) ) return false;
  if ( itTrack->ptError()/itTrack->pt() > pterror_ ) return false;
  int primaryvtx = 0;
  math::XYZPoint v1( recoVertices[primaryvtx].position().x(), recoVertices[primaryvtx].position().y(), recoVertices[primaryvtx].position().z() );
  double vxError = recoVertices[primaryvtx].xError();
  double vyError = recoVertices[primaryvtx].yError();
  double vzError = recoVertices[primaryvtx].zError();
  double d0 = -1.* itTrack->dxy(v1);
  double derror=sqrt(itTrack->dxyError()*itTrack->dxyError()+vxError*vyError);
  if ( fabs( d0/derror ) > d0d0error_ ) {
    return false;
  }
  double dz=itTrack->dz(v1);
  double dzerror=sqrt(itTrack->dzError()*itTrack->dzError()+vzError*vzError);
  if ( fabs( dz/dzerror ) > dzdzerror_ ) {
    return false;
  }
  return true;
}

///
bool
VNAnalyzer::TrackQuality_HIReco(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices)
{
  if ( itTrack->charge() == 0 ) return false;
  if ( !itTrack->quality(reco::TrackBase::highPurity) ) return false;
  if ( itTrack->numberOfValidHits() < 11 ) return false;
  if ( itTrack->normalizedChi2() / itTrack->hitPattern().trackerLayersWithMeasurement() > 0.15 ) {
    return false;
  }
  if ( itTrack->ptError()/itTrack->pt() > pterror_ ) {
    return false;
  }
  if (
      itTrack->originalAlgo() != 4 and
      itTrack->originalAlgo() != 5 and
      itTrack->originalAlgo() != 6 and
      itTrack->originalAlgo() != 7
      ) {
    return false;
  }
  
  int primaryvtx = 0;
  math::XYZPoint v1( recoVertices[primaryvtx].position().x(), recoVertices[primaryvtx].position().y(), recoVertices[primaryvtx].position().z() );
  double vxError = recoVertices[primaryvtx].xError();
  double vyError = recoVertices[primaryvtx].yError();
  double vzError = recoVertices[primaryvtx].zError();
  double d0 = -1.* itTrack->dxy(v1);
  double derror=sqrt(itTrack->dxyError()*itTrack->dxyError()+vxError*vyError);
  if ( fabs( d0/derror ) > d0d0error_ ) {
    return false;
  }
  
  double dz=itTrack->dz(v1);
  double dzerror=sqrt(itTrack->dzError()*itTrack->dzError()+vzError*vzError);
  if ( fabs( dz/dzerror ) > dzdzerror_ ) {
    return false;
  }
  return true;
}

///
bool
VNAnalyzer::TrackQuality_Pixel(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices)
{
  if ( itTrack->charge() == 0 ) return false;
  if ( !itTrack->quality(reco::TrackBase::highPurity) ) return false;
  bool bPix = false;
  int nHits = itTrack->numberOfValidHits();
  
  int primaryvtx = 0;
  math::XYZPoint v1( recoVertices[primaryvtx].position().x(), recoVertices[primaryvtx].position().y(), recoVertices[primaryvtx].position().z() );
  double vxError = recoVertices[primaryvtx].xError();
  double vyError = recoVertices[primaryvtx].yError();
  double vzError = recoVertices[primaryvtx].zError();
  double d0 = -1.* itTrack->dxy(v1);
  
  double dz=itTrack->dz(v1);
  double dzerror=sqrt(itTrack->dzError()*itTrack->dzError()+vzError*vzError);
  if ( itTrack->pt() < 2.4 and (nHits==3 or nHits==4 or nHits==5 or nHits==6) ) bPix = true;
  if ( not bPix ) {
    if ( nHits < 11 ) return false;
    if ( itTrack->normalizedChi2() / itTrack->hitPattern().trackerLayersWithMeasurement() > 0.15 ) {
      return false;
    }
    if ( itTrack->ptError()/itTrack->pt() > pterror_ ) {
      return false;
    }
    if (
	itTrack->pt() > 2.4 and
	itTrack->originalAlgo() != 4 and
	itTrack->originalAlgo() != 5 and
	itTrack->originalAlgo() != 6 and
	itTrack->originalAlgo() != 7
	) {
      return false;
    }
    
    double derror=sqrt(itTrack->dxyError()*itTrack->dxyError()+vxError*vyError);
    if ( fabs( d0/derror ) > d0d0error_ ) {
      return false;
    }
    
    if ( fabs( dz/dzerror ) > dzdzerror_ ) {
      return false;
    }
  } else {
    if ( itTrack->normalizedChi2() / itTrack->hitPattern().trackerLayersWithMeasurement() > chi2_ ) return false;
    if ( fabs( dz/dzerror ) > dzdzerror_pix_ ) {
      return false;
    }
  }
  return true;
}

//define this as a plug-in
DEFINE_FWK_MODULE(VNAnalyzer);

