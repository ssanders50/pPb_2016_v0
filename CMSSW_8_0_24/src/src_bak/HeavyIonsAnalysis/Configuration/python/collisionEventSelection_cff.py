import FWCore.ParameterSet.Config as cms

# Coincidence of HF towers above threshold
from HeavyIonsAnalysis.Configuration.hfCoincFilter_cff import *

# Selection of at least a two-track fitted vertex
primaryVertexFilter = cms.EDFilter("VertexSelector",
    src = cms.InputTag("hiSelectedVertex"),
    cut = cms.string("!isFake && abs(z) <= 25 && position.Rho <= 2 && tracksSize >= 2"), 
    filter = cms.bool(True),   # otherwise it won't filter the events
)

primaryVertexFilterPA = cms.EDFilter("VertexSelector",
    src = cms.InputTag("offlinePrimaryVertices"),
    cut = cms.string("!isFake && abs(z) <= 25 && position.Rho <= 2 && tracksSize >= 2"),
    filter = cms.bool(True), # otherwise it won't filter the events
)


# Cluster-shape filter re-run offline from ClusterCompatibility object for PbPb
from HeavyIonsAnalysis.Configuration.HIClusterCompatibilityFilter_cfi import *

#Reject beam scraping events standard pp and pA configuration
NoScraping = cms.EDFilter("FilterOutScraping",
 applyfilter = cms.untracked.bool(True),
 debugOn = cms.untracked.bool(False),
 numtrack = cms.untracked.uint32(10),
 thresh = cms.untracked.double(0.25)
)


#Reject events with pile-up, optionally
from HeavyIonsAnalysis.VertexAnalysis.PAPileUpVertexFilter_cff import *


collisionEventSelection = cms.Sequence(hfCoincFilter3 *
                                       primaryVertexFilter *
                                       clusterCompatibilityFilter)

collisionEventSelectionPA = cms.Sequence(hfCoincFilter *
                                         primaryVertexFilterPA *
                                         NoScraping
                                         )

collisionEventSelectionPA_rejectPU = cms.Sequence(collisionEventSelectionPA *
                                                  pileupVertexFilterCutGplus)

