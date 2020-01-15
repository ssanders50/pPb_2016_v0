// system include files
#include <memory>

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
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/CastorReco/interface/CastorTower.h"

#include "DataFormats/HeavyIonEvent/interface/Centrality.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/HeavyIonEvent/interface/EvtPlane.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "CondFormats/DataRecord/interface/HeavyIonRPRcd.h"
#include "CondFormats/DataRecord/interface/HeavyIonRcd.h"
#include "CondFormats/HIObjects/interface/CentralityTable.h"
#include "CondFormats/HIObjects/interface/RPFlatParams.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidateFwd.h"
#include "DataFormats/Math/interface/Point3D.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefVector.h"


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
using namespace reco;
using namespace edm;
static const int ntrkbins = 25;
static const  double trkBins[]={0, 10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 135, 150, 160, 185, 210, 230, 250, 270, 300, 330, 350, 370, 390, 420, 500};

static const int nptbins = 28;
static const float ptbins[]={0.3, 0.4, 0.5,  0.6,  0.8,  1.0,  1.25,  1.50,  2.0,
			      2.5,  3.0,  3.5,  4.0,  5.0,  6.0,  7.0, 8.0, 10., 12.0, 14.0, 16.0,  20.0, 26.0, 35.0, 45.0, 60.0, 80.0, 100., 200.};

static const int netabins = 12;
static const float etabins[]={-2.4, -2.0, -1.6, -1.2, -0.8, -0.4, 0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4};
//
// class declaration
//

class CheckFlattening : public edm::EDAnalyzer {
public:
  explicit CheckFlattening(const edm::ParameterSet&);
  ~CheckFlattening();
      
private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  // ----------member data ---------------------------
  int eporder_;


  std::string centralityVariable_;
  std::string centralityLabel_;
  std::string centralityMC_;

  edm::InputTag centralityBinTag_;
  edm::EDGetTokenT<int> centralityBinToken;

  edm::InputTag centralityTag_;
  edm::EDGetTokenT<reco::Centrality> centralityToken;
  edm::Handle<reco::Centrality> centrality_;

  edm::Handle<int> cbin_;
  edm::EDGetTokenT<int> tag_;

  edm::InputTag vertexTag_;
  edm::EDGetTokenT<std::vector<reco::Vertex>> vertexToken;
  edm::Handle<VertexCollection> vertexCollection_;
  edm::Handle<std::vector<reco::Vertex>> vertex_;

  edm::InputTag trackTag_;
  edm::EDGetTokenT<reco::TrackCollection> trackToken;
  edm::Handle<reco::TrackCollection> trackCollection_;

  edm::InputTag inputPlanesTag_;
  edm::EDGetTokenT<reco::EvtPlaneCollection> inputPlanesToken;
  edm::Handle<reco::EvtPlaneCollection> inputPlanes_;

  edm::Service<TFileService> fs;
  TFile *  frecenter;
  int vs_sell;   // vertex collection size
  float vzr_sell;
  float vzErr_sell;
  TH1D * hcent;
  TH1D * hcentbins;
  double centval;
  double vtx;
  int noff;
  double caloCentRef_;
  double caloCentRefWidth_;
  int caloCentRefMinBin_;
  int caloCentRefMaxBin_;
  bool useNtrk_;
  double nCentBins_;
  Double_t epang[NumEPNames];
  Double_t epsin[NumEPNames];
  Double_t epcos[NumEPNames];

  Double_t epang_orig[NumEPNames];
  Double_t epsin_orig[NumEPNames];
  Double_t epcos_orig[NumEPNames];

  Double_t epang_RecenterOnly[NumEPNames];
  Double_t epsin_RecenterOnly[NumEPNames];
  Double_t epcos_RecenterOnly[NumEPNames];


  Double_t epang_NoWgt[NumEPNames];
  Double_t epsin_NoWgt[NumEPNames];
  Double_t epcos_NoWgt[NumEPNames];

  Double_t sumw[NumEPNames];
  Double_t sumw2[NumEPNames];

  Double_t sumPtOrEt[NumEPNames];
  Double_t sumPtOrEt2[NumEPNames];

  Double_t qx[NumEPNames];
  Double_t qy[NumEPNames];
  Double_t q[NumEPNames];
  Double_t vn[NumEPNames];
  Double_t epmult[NumEPNames];

  Double_t rescor[NumEPNames];
  Double_t rescorErr[NumEPNames];
  unsigned int runno_;

  TH1D * hNtrkoff;
  int nEtaBins;
  string rpnames[NumEPNames];
  TH1D * PsiRaw[NumEPNames];
  TH1D * Psi[NumEPNames];
  TTree * tree;
  string offsetFileName;

  TH2D * wqxtrk[7][40];
  TH2D * wqytrk[7][40];
  TH2D * wqxtrkRef[7][40];
  TH2D * wqytrkRef[7][40];
  TH2D * wqxtrkRecenter[7][40];
  TH2D * wqytrkRecenter[7][40];
  TH2D * wqcntRecenter[40];

  int FlatOrder_;
  int NumFlatBins_;
  int CentBinCompression_;
  int Noffmin_;
  int Noffmax_;

  HiEvtPlaneFlatten * flat[NumEPNames];
  bool loadDB_;
  bool FirstEvent_;

  bool Branch_Cent;
  bool Branch_NtrkOff;
  bool Branch_Vtx;
  bool Branch_epang;
  bool Branch_epang_orig;
  bool Branch_epang_RecenterOnly;
  bool Branch_NoWgt;
  bool Branch_epsin;
  bool Branch_epcos;
  bool Branch_epsin_orig;
  bool Branch_epcos_orig;
  bool Branch_epsin_RecenterOnly;
  bool Branch_epcos_RecenterOnly;
  bool Branch_epsin_NoWgt;
  bool Branch_epcos_NoWgt;
  bool Branch_sumw;
  bool Branch_sumw2;
  bool Branch_sumPtOrEt;
  bool Branch_sumPtOrEt2;
  bool Branch_qx;
  bool Branch_qy;
  bool Branch_q;
  bool Branch_mult;
  bool Branch_Run;
  bool Branch_Rescor;
  bool Branch_RescorErr;
  bool Branch_vn;

  int ntrkval;

  int getNoff(const edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    int Noff = 0;
    using namespace edm;
    using namespace reco;
    iEvent.getByToken(vertexToken,vertex_);
    VertexCollection recoVertices = *vertex_;
    if ( recoVertices.size() > 100 ) return -1;
    sort(recoVertices.begin(), recoVertices.end(), [](const reco::Vertex &a, const reco::Vertex &b){
	if ( a.tracksSize() == b.tracksSize() ) return a.chi2() < b.chi2();
	return a.tracksSize() > b.tracksSize();
      });
   
    int primaryvtx = 0;
   
    double vz = recoVertices[primaryvtx].z();
    if (fabs(vz) < -15 || fabs(vz) > 15) {
      return -1;
    }
 
    math::XYZPoint v1( recoVertices[primaryvtx].position().x(), recoVertices[primaryvtx].position().y(), recoVertices[primaryvtx].position().z() );
    double vxError = recoVertices[primaryvtx].xError();
    double vyError = recoVertices[primaryvtx].yError();
    double vzError = recoVertices[primaryvtx].zError();
    

    iEvent.getByLabel(trackTag_,trackCollection_);
    for(TrackCollection::const_iterator itTrack = trackCollection_->begin(); itTrack != trackCollection_->end(); ++itTrack) {    
      if ( !itTrack->quality(reco::TrackBase::highPurity) ) continue;
      if ( itTrack->charge() == 0 ) continue;
      if ( fabs(itTrack->eta()) > 2.4 ) continue;
      bool bPix = false;
      int nHits = itTrack->numberOfValidHits();
      if ( itTrack->pt() < 2.4 and (nHits==3 or nHits==4 or nHits==5 or nHits==6) ) bPix = true;
      if ( not bPix ) {
	if ( nHits < 11 ) continue;
	if ( itTrack->normalizedChi2() / itTrack->hitPattern().trackerLayersWithMeasurement() > 0.15 ) {
	  continue;
	}
	if ( itTrack->ptError()/itTrack->pt() > 0.1 ) {
	  continue;
	}
	double d0 = -1.* itTrack->dxy(v1);
	double derror=sqrt(itTrack->dxyError()*itTrack->dxyError()+vxError*vyError);
	if ( fabs( d0/derror ) > 3.0 ) {
	  continue;
	}
	double dz=itTrack->dz(v1);
	double dzerror=sqrt(itTrack->dzError()*itTrack->dzError()+vzError*vzError);
	if ( fabs( dz/dzerror ) > 3.0 ) {
	  continue;
	}
      }
      Noff++;
    }
    if(Noff < Noffmin_ || Noff > Noffmax_) return -2;


    for(TrackCollection::const_iterator itTrack = trackCollection_->begin(); itTrack != trackCollection_->end(); ++itTrack) {    
      if ( !itTrack->quality(reco::TrackBase::highPurity) ) continue;
      if ( itTrack->charge() == 0 ) continue;
      if ( fabs(itTrack->eta()) > 2.4 ) continue;
      bool bPix = false;
      int nHits = itTrack->numberOfValidHits();
      if ( itTrack->pt() < 2.4 and (nHits==3 or nHits==4 or nHits==5 or nHits==6) ) bPix = true;
      if ( not bPix ) {
	if ( nHits < 11 ) continue;
	if ( itTrack->normalizedChi2() / itTrack->hitPattern().trackerLayersWithMeasurement() > 0.15 ) {
	  continue;
	}
	if ( itTrack->ptError()/itTrack->pt() > 0.1 ) {
	  continue;
	}
	
	double d0 = -1.* itTrack->dxy(v1);
	double derror=sqrt(itTrack->dxyError()*itTrack->dxyError()+vxError*vyError);
	if ( fabs( d0/derror ) > 3.0 ) {
	  continue;
	}
	
	double dz=itTrack->dz(v1);
	double dzerror=sqrt(itTrack->dzError()*itTrack->dzError()+vzError*vzError);
	if ( fabs( dz/dzerror ) > 3.0 ) {
	  continue;
	}
      }

      int bin = NtrkToBin(Noff)-1;
      for(int j = 1; j<=7; j++) {
	wqxtrkRecenter[j-1][bin]->Fill(itTrack->pt(), itTrack->eta(), TMath::Cos(j*itTrack->phi()));
	wqytrkRecenter[j-1][bin]->Fill(itTrack->pt(), itTrack->eta(), TMath::Sin(j*itTrack->phi()));
      }
      wqcntRecenter[bin]->Fill(itTrack->pt(), itTrack->eta());
    }
    return Noff;
  }


  int NtrkToBin(int ntrk){
    for(int i = 0; i<ntrkbins; i++) {
      if(ntrk < trkBins[i]) return i;
    }
    return ntrkbins;
  }



};


//
// constructors and destructor
//
CheckFlattening::CheckFlattening(const edm::ParameterSet& iConfig):runno_(0)
  
{

  offsetFileName = iConfig.getUntrackedParameter<std::string>("offsetFile");
  frecenter = new TFile(offsetFileName.data(),"read");
  nCentBins_ = 200;
  runno_ = 0;
  loadDB_ = kTRUE;
  FirstEvent_ = kTRUE;

  centralityVariable_ = iConfig.getParameter<std::string>("centralityVariable");
  if(iConfig.exists("nonDefaultGlauberModel")){
    centralityMC_ = iConfig.getParameter<std::string>("nonDefaultGlauberModel");
  }
  centralityLabel_ = centralityVariable_+centralityMC_;

  centralityBinTag_ = iConfig.getParameter<edm::InputTag>("centralityBinTag_");
  centralityBinToken = consumes<int>(centralityBinTag_);

  centralityTag_ = iConfig.getParameter<edm::InputTag>("centralityTag_");
  centralityToken = consumes<reco::Centrality>(centralityTag_);

  vertexTag_  = iConfig.getParameter<edm::InputTag>("vertexTag_");
  vertexToken = consumes<std::vector<reco::Vertex>>(vertexTag_);

  trackTag_ = iConfig.getParameter<edm::InputTag>("trackTag_");
  trackToken = consumes<reco::TrackCollection>(trackTag_);

  inputPlanesTag_ = iConfig.getParameter<edm::InputTag>("inputPlanesTag_");
  inputPlanesToken = consumes<reco::EvtPlaneCollection>(inputPlanesTag_);

  FlatOrder_ = iConfig.getParameter<int>("FlatOrder_");
  NumFlatBins_ = iConfig.getParameter<int>("NumFlatBins_");
  CentBinCompression_ = iConfig.getParameter<int>("CentBinCompression_");
  caloCentRef_ = iConfig.getParameter<double>("caloCentRef_");
  caloCentRefWidth_ = iConfig.getParameter<double>("caloCentRefWidth_");
  useNtrk_ = iConfig.getUntrackedParameter<bool>("useNtrk",false);
  if(useNtrk_) {
    NumFlatBins_ = ntrkbins;
    CentBinCompression_ = 1;
  }

  // std::cout<<"centralityBinTag_           "<<centralityBinTag_.encode()<<std::endl;
  // std::cout<<"centralityTag_              "<<centralityTag_.encode()<<std::endl;
  // std::cout<<"vertexTag_                  "<<vertexTag_.encode()<<std::endl;
  // std::cout<<"trackTag_                   "<<trackTag_.encode()<<std::endl;
  // std::cout<<"inputPlanesTag_             "<<inputPlanesTag_.encode()<<std::endl;

  // std::cout<<"FlatOrder: "<<FlatOrder_<<std::endl;
  // std::cout<<"CentBinCompression: "<<CentBinCompression_<<std::endl;
  // std::cout<<"caloCentRef_: "<<caloCentRef_<<std::endl;
  Noffmin_ = iConfig.getParameter<int>("Noffmin_");
  Noffmax_ = iConfig.getParameter<int>("Noffmax_");	
  hNtrkoff = fs->make<TH1D>("Ntrkoff","Ntrkoff",1001,0,3000);

  Branch_Cent = iConfig.getUntrackedParameter<bool>("Branch_Cent",true);
  Branch_NtrkOff = iConfig.getUntrackedParameter<bool>("Branch_NtrkOff",true);
  Branch_Vtx = iConfig.getUntrackedParameter<bool>("Branch_Vtx",true);
  Branch_epang = iConfig.getUntrackedParameter<bool>("Branch_epang",true);
  Branch_epang_orig = iConfig.getUntrackedParameter<bool>("Branch_epang_orig",true);
  Branch_epang_RecenterOnly = iConfig.getUntrackedParameter<bool>("Branch_epang_RecenterOnly",true);
  Branch_NoWgt = iConfig.getUntrackedParameter<bool>("Branch_NoWgt",true);
  Branch_epsin = iConfig.getUntrackedParameter<bool>("Branch_epsin",true);
  Branch_epcos = iConfig.getUntrackedParameter<bool>("Branch_epcos",true);
  Branch_epsin_orig = iConfig.getUntrackedParameter<bool>("Branch_epsin_orig",true);
  Branch_epcos_orig = iConfig.getUntrackedParameter<bool>("Branch_epcos_orig",true);
  Branch_epsin_RecenterOnly = iConfig.getUntrackedParameter<bool>("Branch_epsin_RecenterOnly",true);
  Branch_epcos_RecenterOnly = iConfig.getUntrackedParameter<bool>("Branch_epcos_RecenterOnly",true);
  Branch_epsin_NoWgt = iConfig.getUntrackedParameter<bool>("Branch_epsin_NoWgt",true);
  Branch_epcos_NoWgt = iConfig.getUntrackedParameter<bool>("Branch_epcos_NoWgt",true);
  Branch_sumw = iConfig.getUntrackedParameter<bool>("Branch_sumw",true);
  Branch_sumw2 = iConfig.getUntrackedParameter<bool>("Branch_sumw2",true);
  Branch_sumPtOrEt = iConfig.getUntrackedParameter<bool>("Branch_sumPtOrEt",true);
  Branch_sumPtOrEt2 = iConfig.getUntrackedParameter<bool>("Branch_sumPtOrEt2",true);
  Branch_qx = iConfig.getUntrackedParameter<bool>("Branch_qx",true);
  Branch_qy = iConfig.getUntrackedParameter<bool>("Branch_qy",true);
  Branch_q = iConfig.getUntrackedParameter<bool>("Branch_q",true);
  Branch_mult = iConfig.getUntrackedParameter<bool>("Branch_mult",true);
  Branch_Run = iConfig.getUntrackedParameter<bool>("Branch_Run",true);
  Branch_Rescor = iConfig.getUntrackedParameter<bool>("Branch_Rescor",true);
  Branch_RescorErr = iConfig.getUntrackedParameter<bool>("Branch_RescorErr",true);
  Branch_vn = iConfig.getUntrackedParameter<bool>("Branch_vn",true);

  hcent = fs->make<TH1D>("cent","cent",220,-10,110);
  hcentbins = fs->make<TH1D>("centbins","centbins",201,0,200);
  tag_ = consumes<int>(iConfig.getParameter<edm::InputTag>("BinLabel"));

  TString epnames = EPNames[0].data();
  epnames = epnames+"/D";
  for(int i = 0; i<NumEPNames; i++) {
    if(i>0) epnames = epnames + ":" + EPNames[i].data() + "/D";
    TFileDirectory subdir = fs->mkdir(Form("%s",EPNames[i].data()));
    Double_t psirange = 4;
    if(EPOrder[i]==2 ) psirange = 2;
    if(EPOrder[i]==3 ) psirange = 1.5;
    if(EPOrder[i]==4 ) psirange = 1;
    if(EPOrder[i]==5) psirange = 0.8;
    if(EPOrder[i]==6) psirange = 0.6;
    if(EPOrder[i]==7) psirange = 0.5;

    PsiRaw[i] = subdir.make<TH1D>(Form("PsiRaw_%s",EPNames[i].data()),Form("PsiRaw_%s",EPNames[i].data()),800,-psirange,psirange);
    Psi[i] = subdir.make<TH1D>(Form("Psi_%s",EPNames[i].data()),Form("Psi_%s",EPNames[i].data()),800,-psirange,psirange);

    NumFlatBins_ = ntrkbins;
    flat[i] = new HiEvtPlaneFlatten();
    flat[i]->init(FlatOrder_,NumFlatBins_,EPNames[i],EPOrder[i]);

  }
  std::cout<<"Hbins: "<<flat[0]->getHBins()<<std::endl;
  std::cout<<"OBins: "<<flat[0]->getOBins()<<std::endl;

  tree = fs->make<TTree>("tree","EP tree");

  if(Branch_Cent)              tree->Branch("Cent",&centval,"cent/D");
  if(Branch_NtrkOff)           tree->Branch("NtrkOff",&noff,"noff/D");
  if(Branch_Vtx)               tree->Branch("Vtx",&vtx,"vtx/D");
  if(Branch_epang)             tree->Branch("epang",&epang, epnames.Data());
  if(Branch_epang_orig)        tree->Branch("epang_orig",&epang_orig, epnames.Data());
  if(Branch_epang_RecenterOnly)  tree->Branch("epang_RecenterOnly", &epang_RecenterOnly, epnames.Data());
  if(Branch_NoWgt)             tree->Branch("epang_NoWgt", &epang_NoWgt, epnames.Data());

  if(Branch_epsin)             tree->Branch("epsin",     &epsin,      epnames.Data());
  if(Branch_epcos)             tree->Branch("epcos",     &epcos,      epnames.Data());
  if(Branch_epsin_orig)        tree->Branch("epsin_orig",     &epsin_orig,      epnames.Data());
  if(Branch_epcos_orig)        tree->Branch("epcos_orig",     &epcos_orig,      epnames.Data());
  if(Branch_epsin_RecenterOnly)tree->Branch("epsin_RecenterOnly",     &epsin_RecenterOnly,      epnames.Data());
  if(Branch_epcos_RecenterOnly)tree->Branch("epcos_RecenterOnly",     &epcos_RecenterOnly,      epnames.Data());
  if(Branch_epsin_NoWgt)       tree->Branch("epsin_NoWgt",     &epsin_NoWgt,      epnames.Data());
  if(Branch_epcos_NoWgt)       tree->Branch("epcos_NoWgt",     &epcos_NoWgt,      epnames.Data());
  if(Branch_sumw)              tree->Branch("sumw",  &sumw,        epnames.Data());
  if(Branch_sumw2)             tree->Branch("sumw2",  &sumw2,        epnames.Data());
  if(Branch_sumPtOrEt)         tree->Branch("sumPtOrEt",  &sumPtOrEt,        epnames.Data());
  if(Branch_sumPtOrEt2)        tree->Branch("sumPtOrEt2",  &sumPtOrEt2,        epnames.Data());
  if(Branch_qx)                tree->Branch("qx",      &qx,       epnames.Data());
  if(Branch_qy)                tree->Branch("qy",      &qy,       epnames.Data());
  if(Branch_q)                 tree->Branch("q",       &q,       epnames.Data());
  if(Branch_mult)              tree->Branch("mult",    &epmult,  epnames.Data());
  if(Branch_Run)               tree->Branch("Run",     &runno_,   "run/i");
  if(Branch_Rescor)            tree->Branch("Rescor",  &rescor,   epnames.Data());
  if(Branch_RescorErr)         tree->Branch("RescorErr",  &rescorErr,   epnames.Data());
  if(Branch_vn)                tree->Branch("vn", &vn, epnames.Data());
  int mx = ntrkbins;
  if(!useNtrk_) {
    mx = 0;
    cout<<"need to set this up"<<endl;
    //	mx = nCentBins_;
  }
  for(int i = 0; i<mx; i++) {
    for(int j = 1; j<=7; j++){
      wqxtrk[j-1][i] = (TH2D *) frecenter->Get(Form("wqxtrk_%d_%d",j,i));
      wqytrk[j-1][i] = (TH2D *) frecenter->Get(Form("wqytrk_%d_%d",j,i));
    }
  }
  for(int i = 0; i<ntrkbins; i++) {
    TFileDirectory subdir = fs->mkdir(Form("%d_%d",(int)trkBins[i],(int)trkBins[i+1]));
    wqcntRecenter[i]   = subdir.make<TH2D>("wqcntRecenter","wqcntRecenter", nptbins,ptbins, netabins, etabins);
    wqcntRecenter[i]->SetOption("colz");
    wqcntRecenter[i]->SetXTitle("p_{T} (GeV/c)");
    wqcntRecenter[i]->SetYTitle("#eta");
    for(int j = 0; j<7; j++) {
      wqxtrkRecenter[j][i] = subdir.make<TH2D>(Form("wqxtrkRecenter%d",j+1),Form("wqxtrkRecenter%d",j+1),nptbins,ptbins, netabins, etabins);
      wqytrkRecenter[j][i] = subdir.make<TH2D>(Form("wqytrkRecenter%d",j+1),Form("wqytrkRecenter%d",j+1),nptbins,ptbins, netabins, etabins);
      wqxtrkRecenter[j][i]->SetOption("colz");
      wqytrkRecenter[j][i]->SetOption("colz");
      wqxtrkRecenter[j][i]->SetXTitle("p_{T} (GeV/c)");
      wqxtrkRecenter[j][i]->SetYTitle("#eta");
      wqytrkRecenter[j][i]->SetXTitle("p_{T} (GeV/c)");
      wqytrkRecenter[j][i]->SetYTitle("#eta");

      wqxtrkRef[j][i] = subdir.make<TH2D>(Form("wqxtrkRef%d",j+1),Form("wqxtrkRef%d",j+1),nptbins,ptbins, netabins, etabins);
      wqytrkRef[j][i] = subdir.make<TH2D>(Form("wqytrkRef%d",j+1),Form("wqytrkRef%d",j+1),nptbins,ptbins, netabins, etabins);
      wqxtrkRef[j][i]->SetOption("colz");
      wqytrkRef[j][i]->SetOption("colz");
      wqxtrkRef[j][i]->SetXTitle("p_{T} (GeV/c)");
      wqxtrkRef[j][i]->SetYTitle("#eta");
      wqytrkRef[j][i]->SetXTitle("p_{T} (GeV/c)");
      wqytrkRef[j][i]->SetYTitle("#eta");

      for(int ii = 1; ii<= wqxtrkRef[j][i]->GetNbinsX(); ii++) {
      	for(int jj = 1; jj<= wqxtrkRef[j][i]->GetNbinsY(); jj++) {
	  wqxtrkRef[j][i]->SetBinContent(ii,jj,wqxtrk[j][i]->GetBinContent(ii,jj));
      	  wqytrkRef[j][i]->SetBinContent(ii,jj,wqytrk[j][i]->GetBinContent(ii,jj));
      	}
      }
    }
  }



}



CheckFlattening::~CheckFlattening()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

  frecenter->Close();
}


//
// member functions
//

// ------------ method called to for each event  ------------
void
CheckFlattening::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;
  Bool_t newrun = kFALSE;
  if(runno_ != iEvent.id().run()) newrun = kTRUE;
  runno_ = iEvent.id().run();

  if(FirstEvent_ || newrun) {
    FirstEvent_ = kFALSE;
    newrun = kFALSE;
    //
    //Get Size of Centrality Table
    //
    if(!useNtrk_) {
      edm::ESHandle<CentralityTable> centDB_;
      iSetup.get<HeavyIonRcd>().get(centralityLabel_,centDB_);
      nCentBins_ = (int) centDB_->m_table.size();
      for(int i = 0; i<NumEPNames; i++) {
	flat[i]->setCaloCentRefBins(-1,-1);
	if(caloCentRef_>0) {
	  int minbin = (caloCentRef_-caloCentRefWidth_/2.)*nCentBins_/100.;
	  int maxbin = (caloCentRef_+caloCentRefWidth_/2.)*nCentBins_/100.;
	  minbin/=CentBinCompression_;
	  maxbin/=CentBinCompression_;
	  if(minbin>0 && maxbin>=minbin) {
	    if(EPDet[i]==HF || EPDet[i]==Castor) flat[i]->setCaloCentRefBins(minbin,maxbin);
	  }
	}
      }
    }
    //
    //Get flattening parameter file.  
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
  //Get Centrality
  //
  int bin = 0;
  if(!useNtrk_) {
    int ntrkval=0;
    if(Noffmin_>=0) {
      iEvent.getByToken(centralityToken, centrality_);
      ntrkval = centrality_->Ntracks();
      if ( (ntrkval < Noffmin_) || (ntrkval >= Noffmax_) ) {
	return;
      }
    }

   iEvent.getByToken(centralityBinToken, cbin_);
   int cbin = *cbin_;
   bin = cbin/CentBinCompression_; 
   double cscale = 100./nCentBins_;
   centval = cscale*cbin;
   
   
  } else {
    iEvent.getByToken(tag_,cbin_);
    ntrkval = *cbin_;
    hNtrkoff->Fill(ntrkval);
    bin = NtrkToBin(ntrkval)-1;
    centval = bin;
    hcentbins->Fill(bin);
  }
  hcent->Fill(centval);
  //Get Vertex
  //
  //  int vs_sell;   // vertex collection size
  // float vzr_sell;
  // iEvent.getByToken(vertexToken,vertex_);
  // const reco::VertexCollection * vertices3 = vertex_.product();
  // vs_sell = vertices3->size();
  // if(vs_sell>0) {
  //   vzr_sell = vertices3->begin()->z();
  // } else
  //   vzr_sell = -999.9;
  
  // vtx = vzr_sell;
  //


  iEvent.getByToken(vertexToken, vertexCollection_);
  VertexCollection recoVertices = *vertexCollection_;
  if ( recoVertices.size() > 100 ) return;
  sort(recoVertices.begin(), recoVertices.end(), [](const reco::Vertex &a, const reco::Vertex &b){
      if ( a.tracksSize() == b.tracksSize() ) return a.chi2() < b.chi2();
      return a.tracksSize() > b.tracksSize();
    });

  int primaryvtx = 0;
   
  double vz = recoVertices[primaryvtx].z();
  vtx = vz;

  //Get Event Planes
  //
  iEvent.getByToken(inputPlanesToken,inputPlanes_);
  
  if(!inputPlanes_.isValid()){
    cout << "Error! Can't get hiEvtPlaneFlat product!" << endl;
    return ;
  }
  Int_t indx = 0;
  //std::cout<<" =============================================== "<<std::endl;
  for (EvtPlaneCollection::const_iterator rp = inputPlanes_->begin();rp !=inputPlanes_->end(); rp++) {
    if(indx != rp->indx() ) {
      cout<<"EP inconsistency found. Abort."<<endl;
      return;
    }
    epang[indx]=rp->angle(2);
    epsin[indx] = rp->sumSin(2);
    epcos[indx] = rp->sumCos(2);

    epang_orig[indx]=rp->angle(0);
    epsin_orig[indx] = rp->sumSin(0);
    epcos_orig[indx] = rp->sumCos(0);

    epang_RecenterOnly[indx]=rp->angle(1);
    epsin_RecenterOnly[indx] = rp->sumSin(1);
    epcos_RecenterOnly[indx] = rp->sumCos(1);

    epang_NoWgt[indx]=rp->angle(3);
    epsin_NoWgt[indx] = rp->sumSin(3);
    epcos_NoWgt[indx] = rp->sumCos(3);

    qx[indx]  = rp->qx(); 
    qy[indx]  = rp->qy();
    q[indx]   = rp->q();
    vn[indx] = rp->vn(0);
    sumw[indx]   = rp->sumw();
    sumw2[indx] = rp->sumw2();
    sumPtOrEt[indx] = rp->sumPtOrEt();
    sumPtOrEt2[indx] = rp->sumPtOrEt2();
    //std::cout<<"CheckFlattening: "<<EPNames[indx]<<"\t"<<rp->angle(0)<<"\t"<<rp->angle(1)<<"\t"<<rp->angle(2)<<std::endl;
    epmult[indx] = (double) rp->mult();

    if(Branch_Rescor || Branch_RescorErr) {
      rescor[indx] = flat[indx]->getCentRes1((int) centval);
      rescorErr[indx] = flat[indx]->getCentResErr1((int) centval);
    }
    if(centval<=80&&rp->angle(0)>-5) {
      Psi[indx]->Fill( rp->angle() );
      PsiRaw[indx]->Fill( rp->angle(0) );
    }
    ++indx; 
  }

  tree->Fill(); 
  getNoff(iEvent, iSetup);
}



// ------------ method called once each job just before starting event loop  ------------
void 
CheckFlattening::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
CheckFlattening::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(CheckFlattening);

