import FWCore.ParameterSet.Config as cms

evtPlaneCalibTree = cms.EDAnalyzer("EvtPlaneCalibTree",
                            vertexTag_=cms.InputTag("offlinePrimaryVertices"),
                            centralityTag_=cms.InputTag("hiCentrality"),
                            centralityBinTag_ = cms.InputTag("centralityBin","HFtowers"),
                            centralityVariable = cms.string("HFtowers"),
                            inputPlanesTag_ = cms.InputTag("hiEvtPlane",""),
                            FlatOrder_ = cms.untracked.int32(9),
                            NumFlatBins_ = cms.untracked.int32(40),
                            CentBinCompression_ = cms.untracked.int32(5),
                            minet_ = cms.untracked.double(-1.),
                            maxet_ = cms.untracked.double(-1.),
                            minpt_ = cms.untracked.double(0.3),
                            maxpt_ = cms.untracked.double(3.0),
                            minvtx_ = cms.untracked.double(-25.),
                            maxvtx_ = cms.untracked.double(25.),
                            delvtx_ = cms.untracked.double(5.),
                            dzerr_ = cms.untracked.double(10.),
                            chi2_ = cms.untracked.double(40.),
                            useNtrkBins_ = cms.untracked.bool(False),
                            bypassCentrality_ = cms.untracked.bool(False),
                            trackTag_ = cms.InputTag("generalTracks"),
                            )
                            




    
