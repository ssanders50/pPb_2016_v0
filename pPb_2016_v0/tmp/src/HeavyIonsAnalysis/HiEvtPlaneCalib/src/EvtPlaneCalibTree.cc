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

#include "DataFormats/HeavyIonEvent/interface/EvtPlane.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "CondFormats/DataRecord/interface/HeavyIonRPRcd.h"
#include "CondFormats/DataRecord/interface/HeavyIonRcd.h"
#include "CondFormats/HIObjects/interface/CentralityTable.h"
#include "CondCore/DBOutputService/interface/PoolDBOutputService.h"
#include "CondFormats/HIObjects/interface/RPFlatParams.h"
#include "DataFormats/Math/interface/Point3D.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefVector.h"

#include "RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneFlatten.h"
#include "TFile.h"
#include "TH1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TTree.h"
#include "TH1I.h"
#include "TF1.h"
#include "TList.h"
#include "TString.h"
#include "TMath.h"
#include <time.h>
#include <cstdlib>
#include <vector>

#include "RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneList.h"
#include "RecoHI/HiEvtPlaneAlgos/interface/LoadEPDB.h"
#include "CondFormats/HIObjects/interface/CentralityTable.h"

using namespace std;
using namespace hi;
using namespace reco;

static const int ntrkbins = 25;
static const  double trkbins[]={0, 10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 135, 150, 160, 185, 210, 230, 250, 270, 300, 330, 350, 370, 390, 420, 500};

static const int nptbins = 28;
static const double ptbins[]={0.3, 0.4, 0.5,  0.6,  0.8,  1.0,  1.25,  1.50,  2.0,
			      2.5,  3.0,  3.5,  4.0,  5.0,  6.0,  7.0, 8.0, 10., 12.0, 14.0, 16.0,  20.0, 26.0, 35.0, 45.0, 60.0, 80.0, 100., 200.};
static const int MaxNumFlatBins = 200;

static const int netabins = 12;
static const double etabins[]={-2.4, -2.0, -1.6, -1.2, -0.8, -0.4, 0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4};

class EvtPlaneCalibTree : public edm::EDAnalyzer {
public:
  explicit EvtPlaneCalibTree(const edm::ParameterSet&);
  ~EvtPlaneCalibTree();
  
private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  edm::Service<TFileService> fs;
  
  std::string centralityVariable_;
  std::string centralityLabel_;
  std::string centralityMC_;
  
  edm::InputTag centralityBinTag_;
  edm::EDGetTokenT<int> centralityBinToken;
  edm::Handle<int> cbin_;
  
  edm::InputTag centralityTag_;
  edm::EDGetTokenT<reco::Centrality> centralityToken;
  edm::Handle<reco::Centrality> centrality_;
  
  edm::InputTag vertexTag_;
  edm::EDGetTokenT<std::vector<reco::Vertex>> vertexToken;
  edm::Handle<VertexCollection> vertexCollection_;
  edm::Handle<std::vector<reco::Vertex>> vertex_;
  
  //edm::InputTag caloTag_;
  //edm::EDGetTokenT<CaloTowerCollection> caloToken;
  //edm::Handle<CaloTowerCollection> caloCollection_;
  
  //edm::InputTag castorTag_;
  //edm::EDGetTokenT<std::vector<reco::CastorTower>> castorToken;
  //edm::Handle<std::vector<reco::CastorTower>> castorCollection_;
  
  edm::InputTag trackTag_;
  edm::EDGetTokenT<reco::TrackCollection> trackToken;
  edm::Handle<reco::TrackCollection> trackCollection_;
  
  edm::InputTag inputPlanesTag_;
  edm::EDGetTokenT<reco::EvtPlaneCollection> inputPlanesToken;
  edm::Handle<reco::EvtPlaneCollection> inputPlanes_;
  
  bool foundCentTag;
  bool useECAL_;
  bool useHCAL_;
  bool useNtrk_;
  bool loadDB_;
  double minet_;
  double maxet_;
  double effm_;
  double minpt_;
  double maxpt_;
  double minvtx_;
  double maxvtx_;
  double delvtx_;
  double dzerr_;
  double chi2_;
  bool FirstEvent;
  int FlatOrder_;
  uint runno_; 
  float centval;
  int bin;
  int cbin;
  uint ntrkval;
  float vtx;
  double caloCentRef_;
  double caloCentRefWidth_;
  int caloCentRefMinBin_;
  int caloCentRefMaxBin_;
  int NumFlatBins_;
  int CentBinCompression_;
  
  int HFEtScale_;
  bool bypassCentrality_;
  int obins;
  TTree * tree;
  TH1D * fparams;
  TH1I * iparams;
  TH1D * hNtrkoff;
  TH1D * htrkbins;
  TH1D * hcent;
  TH1D * hcentbins;
  TH2F * hpt;
  TH2F * hpt2;
  TH2F * hptcnt;
  TH2D * wqxtrk[7][ntrkbins];
  TH2D * wqytrk[7][ntrkbins];
  TH2D * wqcnt[ntrkbins];
  
  //TH2D * hcastor;
  float ws[NumEPNames];
  float wc[NumEPNames];
  float ws_no_w[NumEPNames];
  float wc_no_w[NumEPNames];
  float s[NumEPNames];
  float c[NumEPNames];
  float pt[NumEPNames];
  float pt2[NumEPNames];
  int cnt[NumEPNames];
  double nCentBins_;
  bool genFlatPsi_;
  bool useOffsetPsi_;
  bool storeNames_;
  
  int getNoff(const edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    int Noff = 0;
    using namespace edm;
    using namespace reco;
    
    iEvent.getByToken(trackToken,trackCollection_);
    for(reco::TrackCollection::const_iterator itTrack = trackCollection_->begin();
	itTrack != trackCollection_->end();                      
	++itTrack) {    
      if ( !itTrack->quality(reco::TrackBase::highPurity) ) continue;
      if ( itTrack->charge() == 0 ) continue;
      if ( itTrack->pt() < 0.4 ) continue;
      
      iEvent.getByToken(vertexToken, vertex_);
      math::XYZPoint vtxPoint(0.0,0.0,0.0);
      double vzErr =0.0, vxErr=0.0, vyErr=0.0;
      if(vertex_->size()>0) {
	vtxPoint=vertex_->begin()->position();
	vzErr=vertex_->begin()->zError();
	vxErr=vertex_->begin()->xError();
	vyErr=vertex_->begin()->yError();
      }
      
      double d0=0.0, dz=0.0, d0sigma=0.0, dzsigma=0.0;
      d0 = -1.*itTrack->dxy(vtxPoint);
      dz = itTrack->dz(vtxPoint);
      d0sigma = sqrt(itTrack->d0Error()*itTrack->d0Error()+vxErr*vyErr);
      dzsigma = sqrt(itTrack->dzError()*itTrack->dzError()+vzErr*vzErr);
      
      if ( fabs(itTrack->eta()) > 2.4 ) continue;
      if ( fabs( dz/dzsigma ) > 3. ) continue;
      if ( fabs( d0/d0sigma ) > 3. ) continue;
      if ( itTrack->ptError()/itTrack->pt() > 0.1 ) continue;
      Noff++;
    }
    
    return Noff;
  }
  
private:
  
};
EvtPlaneCalibTree::EvtPlaneCalibTree(const edm::ParameterSet& iConfig) {
  foundCentTag = kTRUE;
  nCentBins_ = 200.;
  
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
  
  genFlatPsi_ = iConfig.getUntrackedParameter<bool>("genFlatPsi_",true);
  useNtrk_ = iConfig.getUntrackedParameter<bool>("useNtrk",false);
  FlatOrder_ = iConfig.getUntrackedParameter<int>("FlatOrder_", 9);
  NumFlatBins_ = iConfig.getUntrackedParameter<int>("NumFlatBins_",40);
  CentBinCompression_ = iConfig.getUntrackedParameter<int>("CentBinCompression_",5);

  useNtrk_ = iConfig.getUntrackedParameter<bool>("useNtrk",false);
  if(useNtrk_) {
    NumFlatBins_ = ntrkbins;
    CentBinCompression_ = 1;
  }
  caloCentRef_ = iConfig.getUntrackedParameter<double>("caloCentRef_",80.);
  caloCentRefWidth_ = iConfig.getUntrackedParameter<double>("caloCentRefWidth_",5.);
  if(NumFlatBins_ > MaxNumFlatBins) {
    cout<<"NumFlatBins set to max of "<<MaxNumFlatBins<<endl;
  }
  useOffsetPsi_ = iConfig.getUntrackedParameter<bool>("useOffsetPsi_",true);
  minet_ = iConfig.getUntrackedParameter<double>("minet_",-1.);
  maxet_ = iConfig.getUntrackedParameter<double>("maxet_",-1.);
  effm_ = iConfig.getUntrackedParameter<double>("effm_",0.0);
  minpt_ = iConfig.getUntrackedParameter<double>("minpt_",0.3);
  maxpt_ = iConfig.getUntrackedParameter<double>("maxpt_",3.0);
  minvtx_ = iConfig.getUntrackedParameter<double>("minvtx_",-25.);
  maxvtx_ = iConfig.getUntrackedParameter<double>("maxvtx_",25.);
  delvtx_ = iConfig.getUntrackedParameter<double>("delvtx_",5.);
  dzerr_ = iConfig.getUntrackedParameter<double>("dzerr_",10.);
  chi2_  = iConfig.getUntrackedParameter<double>("chi2_",40.);
  
  storeNames_ = 1;
  
  FirstEvent = kTRUE;
  hcent = fs->make<TH1D>("cent","cent",101,0,100);
  hcentbins = fs->make<TH1D>("centbins","centbins",201,0,200);
  htrkbins = fs->make<TH1D>("trkbins","trkbins",ntrkbins,trkbins);
  TString epnamesF = EPNames[0].data();
  epnamesF = epnamesF+"/F";
  for(int i = 0; i<NumEPNames; i++) if(i>0) epnamesF = epnamesF + ":" + EPNames[i].data() + "/F";  
  
  TString epnamesI = EPNames[0].data();
  epnamesI = epnamesI+"/I";
  for(int i = 0; i<NumEPNames; i++) if(i>0) epnamesI = epnamesI + ":" + EPNames[i].data() + "/I";  
  
  
  cout<<"=========================="<<endl;
  cout<<"EvtPlaneProducer:         "<<endl;
  cout<<"  NumFlatBins_:           "<<NumFlatBins_<<endl;
  cout<<"  CentBinCompression_:    "<<CentBinCompression_<<endl;
  cout<<"  minet_:                 "<<minet_<<endl;
  cout<<"  maxet_:                 "<<maxet_<<endl;
  cout<<"  minpt_:                 "<<minpt_<<endl;
  cout<<"  maxpt_:                 "<<maxpt_<<endl; 
  cout<<"  minvtx_:                "<<minvtx_<<endl;
  cout<<"  maxvtx_:                "<<maxvtx_<<endl;
  cout<<"  delvtx_:                "<<delvtx_<<endl;
  cout<<"  dzerr_                  "<<dzerr_<<endl;
  cout<<"  chi2_                   "<<chi2_<<endl;
  cout<<"  NumEPNames:             "<<NumEPNames<<endl;
  cout<<"=========================="<<endl;
  
  
  fparams = fs->make<TH1D>("fparams","fparams",10,0,10);
  iparams = fs->make<TH1I>("iparams","iparams",10,0,10);
  hNtrkoff = fs->make<TH1D>("Ntrkoff","Ntrkoff",1001,0,3000);
  int nvtxbins = (maxvtx_ - minvtx_)/delvtx_ + 0.1;
  
  
  hpt    = fs->make<TH2F>("hpt",   "hpt",   NumFlatBins_,0,NumFlatBins_,nvtxbins,minvtx_,maxvtx_);
  hpt2   = fs->make<TH2F>("hpt2",  "hpt2",  NumFlatBins_,0,NumFlatBins_,nvtxbins,minvtx_,maxvtx_);
  hptcnt = fs->make<TH2F>("hptcnt","hptcnt",NumFlatBins_,0,NumFlatBins_,nvtxbins,minvtx_,maxvtx_);
  for(int i = 0; i<ntrkbins; i++) {
    TFileDirectory subdir = fs->mkdir(Form("%d_%d",(int)trkbins[i],(int)trkbins[i+1]));
    wqcnt[i]   = subdir.make<TH2D>(Form("wqcnt_%d"  ,i),Form("wqcnt_%d"  ,i),nptbins,ptbins, netabins, etabins);
    wqcnt[i]->SetOption("colz");
    wqcnt[i]->SetXTitle("p_{T} (GeV/c)");
    wqcnt[i]->SetYTitle("#eta");
    for(int j = 0; j<7; j++) {
      wqxtrk[j][i] = subdir.make<TH2D>(Form("wqxtrk%d_%d",j+1,i),Form("wqxtrk%d_%d",j+1,i),nptbins,ptbins, netabins, etabins);
      wqytrk[j][i] = subdir.make<TH2D>(Form("wqytrk%d_%d",j+1,i),Form("wqytrk%d_%d",j+1,i),nptbins,ptbins, netabins, etabins);
      wqxtrk[j][i]->SetOption("colz");
      wqytrk[j][i]->SetOption("colz");
      wqxtrk[j][i]->SetXTitle("p_{T} (GeV/c)");
      wqxtrk[j][i]->SetYTitle("#eta");
      wqytrk[j][i]->SetXTitle("p_{T} (GeV/c)");
      wqytrk[j][i]->SetYTitle("#eta");
    }
  }
  fparams->SetBinContent(1,minet_);
  fparams->SetBinContent(2,maxet_);
  fparams->SetBinContent(3,minpt_);
  fparams->SetBinContent(4,maxpt_);
  fparams->SetBinContent(5,minvtx_);
  fparams->SetBinContent(6,maxvtx_);
  fparams->SetBinContent(7,caloCentRef_);
  fparams->SetBinContent(8,caloCentRefWidth_);
  iparams->SetBinContent(1,FlatOrder_);
  iparams->SetBinContent(2,NumFlatBins_);
  iparams->SetBinContent(3,CentBinCompression_);
  tree = fs->make<TTree>("tree","EP tree");
  tree->Branch("Cent",    &centval,    "cent/F");
  tree->Branch("Vtx",     &vtx,        "vtx/F");
  tree->Branch("Run",     &runno_,     "run/i");
  tree->Branch("bin",     &bin,        "bin/I");
  tree->Branch("cbin",     &cbin,        "cbin/I");
  tree->Branch("NtrkOff",&ntrkval,     "ntrkoff/i");
  tree->Branch("ws", &ws, epnamesF.Data());
  tree->Branch("wc", &wc, epnamesF.Data());
  tree->Branch("ws_no_w", &ws_no_w, epnamesF.Data());
  tree->Branch("wc_no_w", &wc_no_w, epnamesF.Data());
  tree->Branch("pt", &pt, epnamesF.Data());
  tree->Branch("pt2", &pt2, epnamesF.Data());
  tree->Branch("cnt",&cnt,epnamesI.Data());
  runno_ = 0;
}


EvtPlaneCalibTree::~EvtPlaneCalibTree()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
EvtPlaneCalibTree::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  centval = -1;
  vtx = -100;
  ntrkval = getNoff(iEvent,iSetup);
  if(ntrkval==0) return;
  hNtrkoff->Fill(ntrkval);

  using namespace edm;
  using namespace std;
  using namespace reco;
  
  Bool_t newrun = kFALSE;
  if((int) runno_ != (int) iEvent.id().run()) newrun = kTRUE;
  runno_ = iEvent.id().run();
  //////////////////
  if(FirstEvent || newrun) {
    FirstEvent = kFALSE;
    newrun = kFALSE;
    //
    //Get Size of Centrality Table
    if(!useNtrk_) {
      edm::ESHandle<CentralityTable> centDB_;
      iSetup.get<HeavyIonRcd>().get(centralityLabel_,centDB_);
      nCentBins_ = (int) centDB_->m_table.size();
    }
  } //First event
  
  //
  //Get Centrality
  //
  if(!useNtrk_) {
    iEvent.getByToken(centralityBinToken, cbin_);
    cbin = *cbin_;
    bin = cbin/CentBinCompression_; 
    
    double cscale = 100./nCentBins_;
    centval = cscale*cbin;
    
    hcent->Fill(centval);
    hcentbins->Fill(cbin);
    bin = cbin/CentBinCompression_; 
  } else {
    bin = htrkbins->FindBin(ntrkval)-1;
    htrkbins->Fill(ntrkval);
    if(bin<0 || bin>=ntrkbins) return;
  }
  //
  //Get Vertex
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

  if(vtx>minvtx_ && vtx<maxvtx_) {    
    //
    //Get Event Planes
    //
    iEvent.getByToken(inputPlanesToken,inputPlanes_);
    
    if(!inputPlanes_.isValid()){
      cout << "Error! Can't get hiEvtPlane product!" << endl;
      return ;
    }
    
    int i = 0;
    for (EvtPlaneCollection::const_iterator ep = inputPlanes_->begin();ep !=inputPlanes_->end(); ep++) {
      if(i>=NumEPNames || i!= ep->indx()) {
	cout<<"DATA INCONSISTENCY.  Too many or wrong EPs found in collection. Expect a crash!"<<endl;
      }

      ws[i]=0;
      wc[i]=0;
      ws_no_w[i] = 0;
      wc_no_w[i] = 0;
      cnt[i]=0;
      pt[i]=0;
      pt2[i]=0;


      double c = ep->sumCos(0);
      double s = ep->sumSin(0);
      double c_no_w = ep->sumCos(3);
      double s_no_w = ep->sumSin(3);
      uint m = ep->mult();
      float fpt = ep->sumPtOrEt();
      float fpt2 = ep->sumPtOrEt2();
      //std::cout<<"EvtPlaneCalibTree: "<<s<<"\t"<<c<<"\t"<<m<<"\tang: "<<ep->angle(0)<<std::endl;
      if(ep->angle(0)>-5) {      
	ws[i]=s;
	wc[i]=c;
	ws_no_w[i] = s_no_w;
	wc_no_w[i] = c_no_w;
	cnt[i]=m;
	pt[i]=fpt;
	pt2[i]=fpt2;
      }
      ++i;
    }    
    tree->Fill();   
    
    //    Fill offset hists
    iEvent.getByToken(trackToken,trackCollection_);
    for(reco::TrackCollection::const_iterator itTrack = trackCollection_->begin();
    	itTrack != trackCollection_->end();                      
    	++itTrack) {    
      if ( !itTrack->quality(reco::TrackBase::highPurity) ) continue;
      if ( itTrack->charge() == 0 ) continue;
      if ( itTrack->pt() < 0.4 ) continue;
      double phi = itTrack->phi();
      double eta = itTrack->eta();
      iEvent.getByToken(vertexToken, vertex_);
      math::XYZPoint vtxPoint(0.0,0.0,0.0);
      double vzErr =0.0, vxErr=0.0, vyErr=0.0;
      if(vertex_->size()>0) {
    	vtxPoint=vertex_->begin()->position();
    	vzErr=vertex_->begin()->zError();
    	vxErr=vertex_->begin()->xError();
    	vyErr=vertex_->begin()->yError();
      }
      
      double d0=0.0, dz=0.0, d0sigma=0.0, dzsigma=0.0;
      d0 = -1.*itTrack->dxy(vtxPoint);
      dz = itTrack->dz(vtxPoint);
      d0sigma = sqrt(itTrack->d0Error()*itTrack->d0Error()+vxErr*vyErr);
      dzsigma = sqrt(itTrack->dzError()*itTrack->dzError()+vzErr*vzErr);
      
      if ( fabs(itTrack->eta()) > 2.4 ) continue;
      if ( fabs( dz/dzsigma ) > 3. ) continue;
      if ( fabs( d0/d0sigma ) > 3. ) continue;
      if ( itTrack->ptError()/itTrack->pt() > 0.1 ) continue;
      double pt = itTrack->pt();
      for(int j = 0; j<7; j++) {
    	wqxtrk[j][bin]->Fill(pt, eta, cos( (1.+j) * phi ));
    	wqytrk[j][bin]->Fill(pt, eta, sin( (1.+j) * phi ));
      }
      wqcnt[bin]->Fill(pt,eta);
    }


  }
}

// ------------ method called once each job just before starting event loop  ------------
void 
EvtPlaneCalibTree::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
EvtPlaneCalibTree::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(EvtPlaneCalibTree);
