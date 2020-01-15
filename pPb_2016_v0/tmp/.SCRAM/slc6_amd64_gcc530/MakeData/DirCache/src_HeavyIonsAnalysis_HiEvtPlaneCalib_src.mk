ifeq ($(strip $(HeavyIonsAnalysis/HiEvtPlaneCalib)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_HiEvtPlaneCalib_src
src_HeavyIonsAnalysis_HiEvtPlaneCalib_src_parent := HeavyIonsAnalysis/HiEvtPlaneCalib
src_HeavyIonsAnalysis_HiEvtPlaneCalib_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_HiEvtPlaneCalib_src,src/HeavyIonsAnalysis/HiEvtPlaneCalib/src,LIBRARY))
HeavyIonsAnalysisHiEvtPlaneCalib := self/HeavyIonsAnalysis/HiEvtPlaneCalib
HeavyIonsAnalysis/HiEvtPlaneCalib := HeavyIonsAnalysisHiEvtPlaneCalib
HeavyIonsAnalysisHiEvtPlaneCalib_files := $(patsubst src/HeavyIonsAnalysis/HiEvtPlaneCalib/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/HiEvtPlaneCalib/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisHiEvtPlaneCalib_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/HiEvtPlaneCalib/BuildFile
HeavyIonsAnalysisHiEvtPlaneCalib_LOC_USE := self  root rootrflx FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Utilities PhysicsTools/UtilAlgos DataFormats/Candidate DataFormats/HcalRecHit DataFormats/WrappedStdDictionaries Geometry/Records DataFormats/HepMCCandidate DataFormats/TrackReco DataFormats/VertexReco DataFormats/Common DataFormats/HeavyIonEvent DataFormats/CaloTowers DataFormats/Provenance CondCore/DBOutputService CondFormats/DataRecord RecoHI/HiCentralityAlgos clhep
HeavyIonsAnalysisHiEvtPlaneCalib_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisHiEvtPlaneCalib,HeavyIonsAnalysisHiEvtPlaneCalib,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/HiEvtPlaneCalib/src))
HeavyIonsAnalysisHiEvtPlaneCalib_PACKAGE := self/src/HeavyIonsAnalysis/HiEvtPlaneCalib/src
ALL_PRODS += HeavyIonsAnalysisHiEvtPlaneCalib
HeavyIonsAnalysisHiEvtPlaneCalib_CLASS := LIBRARY
HeavyIonsAnalysis/HiEvtPlaneCalib_forbigobj+=HeavyIonsAnalysisHiEvtPlaneCalib
HeavyIonsAnalysisHiEvtPlaneCalib_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisHiEvtPlaneCalib,src/HeavyIonsAnalysis/HiEvtPlaneCalib/src,src_HeavyIonsAnalysis_HiEvtPlaneCalib_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
