ifeq ($(strip $(RecoHI/HiEvtPlaneAlgos)),)
ALL_COMMONRULES += src_RecoHI_HiEvtPlaneAlgos_src
src_RecoHI_HiEvtPlaneAlgos_src_parent := RecoHI/HiEvtPlaneAlgos
src_RecoHI_HiEvtPlaneAlgos_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoHI_HiEvtPlaneAlgos_src,src/RecoHI/HiEvtPlaneAlgos/src,LIBRARY))
RecoHIHiEvtPlaneAlgos := self/RecoHI/HiEvtPlaneAlgos
RecoHI/HiEvtPlaneAlgos := RecoHIHiEvtPlaneAlgos
RecoHIHiEvtPlaneAlgos_files := $(patsubst src/RecoHI/HiEvtPlaneAlgos/src/%,%,$(wildcard $(foreach dir,src/RecoHI/HiEvtPlaneAlgos/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoHIHiEvtPlaneAlgos_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoHI/HiEvtPlaneAlgos/BuildFile
RecoHIHiEvtPlaneAlgos_LOC_USE := self  root FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Utilities PhysicsTools/UtilAlgos DataFormats/Candidate DataFormats/HcalRecHit DataFormats/WrappedStdDictionaries Geometry/Records DataFormats/HepMCCandidate DataFormats/TrackReco DataFormats/VertexReco DataFormats/Common DataFormats/HeavyIonEvent DataFormats/CaloTowers DataFormats/Provenance CondCore/DBOutputService CondFormats/DataRecord RecoHI/HiCentralityAlgos clhep
RecoHIHiEvtPlaneAlgos_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoHIHiEvtPlaneAlgos,RecoHIHiEvtPlaneAlgos,$(SCRAMSTORENAME_LIB),src/RecoHI/HiEvtPlaneAlgos/src))
RecoHIHiEvtPlaneAlgos_PACKAGE := self/src/RecoHI/HiEvtPlaneAlgos/src
ALL_PRODS += RecoHIHiEvtPlaneAlgos
RecoHIHiEvtPlaneAlgos_CLASS := LIBRARY
RecoHI/HiEvtPlaneAlgos_forbigobj+=RecoHIHiEvtPlaneAlgos
RecoHIHiEvtPlaneAlgos_INIT_FUNC        += $$(eval $$(call Library,RecoHIHiEvtPlaneAlgos,src/RecoHI/HiEvtPlaneAlgos/src,src_RecoHI_HiEvtPlaneAlgos_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
