ifeq ($(strip $(HeavyIonsAnalysis/EventAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_EventAnalysis_src
src_HeavyIonsAnalysis_EventAnalysis_src_parent := HeavyIonsAnalysis/EventAnalysis
src_HeavyIonsAnalysis_EventAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_EventAnalysis_src,src/HeavyIonsAnalysis/EventAnalysis/src,LIBRARY))
HeavyIonsAnalysisEventAnalysis := self/HeavyIonsAnalysis/EventAnalysis
HeavyIonsAnalysis/EventAnalysis := HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_files := $(patsubst src/HeavyIonsAnalysis/EventAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/EventAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisEventAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/EventAnalysis/BuildFile
HeavyIonsAnalysisEventAnalysis_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet CommonTools/UtilAlgos FWCore/ServiceRegistry DataFormats/HeavyIonEvent DataFormats/VertexReco RecoHI/HiCentralityAlgos DataFormats/HepMCCandidate DataFormats/JetReco DataFormats/Common SimDataFormats/HiGenData SimDataFormats/GeneratorProducts FWCore/Common DataFormats/HLTReco HLTrigger/HLTcore CondFormats/HLTObjects CondFormats/DataRecord
HeavyIonsAnalysisEventAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisEventAnalysis,HeavyIonsAnalysisEventAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/EventAnalysis/src))
HeavyIonsAnalysisEventAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/EventAnalysis/src
ALL_PRODS += HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/EventAnalysis_forbigobj+=HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisEventAnalysis,src/HeavyIonsAnalysis/EventAnalysis/src,src_HeavyIonsAnalysis_EventAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
