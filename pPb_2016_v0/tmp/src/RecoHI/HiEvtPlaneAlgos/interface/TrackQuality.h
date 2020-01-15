#ifndef RecoHI_HiEvtPlaneAlgos_TrackQuality_h
#define RecoHI_HiEvtPlaneAlgos_TrackQuality_h
// system include files
#include <memory>
#include <iostream>
#include <string>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include <vector>
using namespace std;
using namespace hi;
using namespace edm;


namespace hi{
enum    TrackCut {trackUndefine = 0, ppReco = 1, HIReco, MergedPixel, PixelOnly,  GenMC};
 class TrackQuality {
 public:
    TrackQuality(edm::InputTag trackTag_, double dz = 3, double d0 = 3, double pt = 0.1, double dzpix = 10, double chi2 = 40 ){
     string trackType = trackTag_.label();
     if ( trackType == "hiGeneralTracks" ) {
       sTrackQuality = HIReco;
       //std::cout<<"hiGeneralTracks"<<std::endl;
     } else if ( trackType == "generalTracks" ) {
       sTrackQuality = ppReco;
       //std::cout<<"generalTracks"<<std::endl;
     } else if ( trackType == "hiGeneralAndPixelTracks"  ) {
       sTrackQuality = MergedPixel;
       //std::cout<<"merged pixel"<<std::endl;
     } else if ( trackType == "hiConformalPixelTracks" ) {
       sTrackQuality = PixelOnly;
       //std::cout<<"pixel only"<<std::endl;
     } else if (trackType == "mcEvtPlane") {
       sTrackQuality = GenMC;
       //std::cout<<"mcEvtPlane"<<std::endl;
     } else {
       sTrackQuality = trackUndefine;
       //std::cout<<"UNDEFINED: "<<trackTag_.label()<<std::endl;
     }
     dzdzerror_ = dz;
     d0d0error_ = d0;
     pterror_ = pt;
     dzdzerror_pix_ = dzpix;
     chi2_ = chi2;
   }
   bool isGood(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices);
   bool is_ppReco(){
     if(sTrackQuality == ppReco) return true;
     else return false;
   }
   bool is_GenMC(){
     if(sTrackQuality == GenMC) return true;
     else return false;
   }
   bool TrackQuality_ppReco(const reco::TrackCollection::const_iterator&, const reco::VertexCollection&);
   bool TrackQuality_HIReco(const reco::TrackCollection::const_iterator&, const reco::VertexCollection&);
   bool TrackQuality_MergedPixel(const reco::TrackCollection::const_iterator&, const reco::VertexCollection&);
   bool TrackQuality_PixelOnly(const reco::TrackCollection::const_iterator&, const reco::VertexCollection&);
   bool TrackQuality_GenMC(const reco::TrackCollection::const_iterator&, const reco::VertexCollection&);
 private:
   TrackCut sTrackQuality;
   double dzdzerror_ ;
   double d0d0error_ ;
   double pterror_ ;
   double dzdzerror_pix_ ;
   double chi2_ ;
 };
}

bool 
TrackQuality::isGood( const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices) {
  bool isGood = true;
  if ( sTrackQuality == HIReco and not TrackQuality_HIReco(itTrack, recoVertices) ) isGood = false;
  else if ( sTrackQuality == ppReco and not TrackQuality_ppReco(itTrack, recoVertices) ) isGood = false;
  else if ( sTrackQuality == MergedPixel  and not TrackQuality_MergedPixel (itTrack, recoVertices) ) isGood = false;
  else if ( sTrackQuality == PixelOnly  and not TrackQuality_PixelOnly (itTrack, recoVertices) ) isGood = false;
  return isGood;
}
///
bool
TrackQuality::TrackQuality_ppReco(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices)
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
TrackQuality::TrackQuality_HIReco(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices)
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
TrackQuality::TrackQuality_MergedPixel(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices)
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
///
bool
TrackQuality::TrackQuality_PixelOnly(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices)
{
  if ( itTrack->charge() == 0 ) return false;
  //if ( !itTrack->quality(reco::TrackBase::highPurity) ) return false;
  
  int primaryvtx = 0;
  math::XYZPoint v1( recoVertices[primaryvtx].position().x(), recoVertices[primaryvtx].position().y(), recoVertices[primaryvtx].position().z() );
  double vzError = recoVertices[primaryvtx].zError();
  
  double dz=itTrack->dz(v1);
  double dzerror=sqrt(itTrack->dzError()*itTrack->dzError()+vzError*vzError);
  if ( itTrack->normalizedChi2() / itTrack->hitPattern().trackerLayersWithMeasurement() > chi2_ ) return false;
  if ( fabs( dz/dzerror ) > dzdzerror_pix_ ) {
    return false;
  }
  return true;
}
///
bool
TrackQuality::TrackQuality_GenMC(const reco::TrackCollection::const_iterator& itTrack, const reco::VertexCollection& recoVertices)
{
	if ( itTrack->charge() == 0 ) return false;
	if( fabs(itTrack->eta())>2.4  )return false;
	return true;
}


#endif
