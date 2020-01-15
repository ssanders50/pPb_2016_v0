ifeq ($(strip $(HeavyIonsAnalysis/PhotonAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_PhotonAnalysis_src
src_HeavyIonsAnalysis_PhotonAnalysis_src_parent := HeavyIonsAnalysis/PhotonAnalysis
src_HeavyIonsAnalysis_PhotonAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_PhotonAnalysis_src,src/HeavyIonsAnalysis/PhotonAnalysis/src,LIBRARY))
HeavyIonsAnalysisPhotonAnalysis := self/HeavyIonsAnalysis/PhotonAnalysis
HeavyIonsAnalysis/PhotonAnalysis := HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/PhotonAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/PhotonAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisPhotonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/PhotonAnalysis/BuildFile
HeavyIonsAnalysisPhotonAnalysis_LOC_USE := self  CondFormats/DataRecord CondFormats/EcalObjects FWCore/Framework FWCore/ParameterSet DataFormats/HcalRecHit DataFormats/EgammaReco DataFormats/Candidate DataFormats/PatCandidates Geometry/CaloGeometry DataFormats/HepMCCandidate clhep root
HeavyIonsAnalysisPhotonAnalysis_EX_LIB   := HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_EX_USE   := $(foreach d,$(HeavyIonsAnalysisPhotonAnalysis_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
HeavyIonsAnalysisPhotonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/PhotonAnalysis/src
ALL_PRODS += HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/PhotonAnalysis_forbigobj+=HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisPhotonAnalysis,src/HeavyIonsAnalysis/PhotonAnalysis/src,src_HeavyIonsAnalysis_PhotonAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
