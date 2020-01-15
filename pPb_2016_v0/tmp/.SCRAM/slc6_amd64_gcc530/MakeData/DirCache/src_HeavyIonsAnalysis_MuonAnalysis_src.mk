ifeq ($(strip $(HeavyIonsAnalysis/MuonAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_MuonAnalysis_src
src_HeavyIonsAnalysis_MuonAnalysis_src_parent := HeavyIonsAnalysis/MuonAnalysis
src_HeavyIonsAnalysis_MuonAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_MuonAnalysis_src,src/HeavyIonsAnalysis/MuonAnalysis/src,LIBRARY))
HeavyIonsAnalysisMuonAnalysis := self/HeavyIonsAnalysis/MuonAnalysis
HeavyIonsAnalysis/MuonAnalysis := HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/MuonAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/MuonAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisMuonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/MuonAnalysis/BuildFile
HeavyIonsAnalysisMuonAnalysis_LOC_USE := self  clhep root FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/ServiceRegistry DataFormats/HepMCCandidate DataFormats/MuonReco DataFormats/HeavyIonEvent SimDataFormats/TrackingAnalysis CommonTools/UtilAlgos CondFormats/HIObjects CondFormats/DataRecord TrackingTools/TransientTrack RecoVertex/KalmanVertexFit DataFormats/TrackReco DataFormats/TrackerRecHit2D DataFormats/TrackingRecHit RecoTracker/TkTrackingRegions
HeavyIonsAnalysisMuonAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisMuonAnalysis,HeavyIonsAnalysisMuonAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/MuonAnalysis/src))
HeavyIonsAnalysisMuonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/MuonAnalysis/src
ALL_PRODS += HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/MuonAnalysis_forbigobj+=HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisMuonAnalysis,src/HeavyIonsAnalysis/MuonAnalysis/src,src_HeavyIonsAnalysis_MuonAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
