ifeq ($(strip $(HeavyIonsAnalysisVertexAnalysisAuto)),)
HeavyIonsAnalysisVertexAnalysisAuto := self/src/HeavyIonsAnalysis/VertexAnalysis/plugins
PLUGINS:=yes
HeavyIonsAnalysisVertexAnalysisAuto_files := $(patsubst src/HeavyIonsAnalysis/VertexAnalysis/plugins/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VertexAnalysis/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisVertexAnalysisAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/VertexAnalysis/plugins/BuildFile
HeavyIonsAnalysisVertexAnalysisAuto_LOC_USE := self  FWCore/Utilities DataFormats/VertexReco FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger CommonTools/UtilAlgos root
HeavyIonsAnalysisVertexAnalysisAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisVertexAnalysisAuto,HeavyIonsAnalysisVertexAnalysisAuto,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/VertexAnalysis/plugins))
HeavyIonsAnalysisVertexAnalysisAuto_PACKAGE := self/src/HeavyIonsAnalysis/VertexAnalysis/plugins
ALL_PRODS += HeavyIonsAnalysisVertexAnalysisAuto
HeavyIonsAnalysis/VertexAnalysis_forbigobj+=HeavyIonsAnalysisVertexAnalysisAuto
HeavyIonsAnalysisVertexAnalysisAuto_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisVertexAnalysisAuto,src/HeavyIonsAnalysis/VertexAnalysis/plugins,src_HeavyIonsAnalysis_VertexAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
HeavyIonsAnalysisVertexAnalysisAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,HeavyIonsAnalysisVertexAnalysisAuto,src/HeavyIonsAnalysis/VertexAnalysis/plugins))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_VertexAnalysis_plugins
src_HeavyIonsAnalysis_VertexAnalysis_plugins_parent := HeavyIonsAnalysis/VertexAnalysis
src_HeavyIonsAnalysis_VertexAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VertexAnalysis_plugins,src/HeavyIonsAnalysis/VertexAnalysis/plugins,PLUGINS))
