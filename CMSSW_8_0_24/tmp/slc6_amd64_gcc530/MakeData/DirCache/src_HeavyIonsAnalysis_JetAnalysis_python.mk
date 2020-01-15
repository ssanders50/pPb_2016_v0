ifeq ($(strip $(PyHeavyIonsAnalysisJetAnalysis)),)
PyHeavyIonsAnalysisJetAnalysis := self/src/HeavyIonsAnalysis/JetAnalysis/python
src_HeavyIonsAnalysis_JetAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/JetAnalysis/python)
PyHeavyIonsAnalysisJetAnalysis_files := $(patsubst src/HeavyIonsAnalysis/JetAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/JetAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisJetAnalysis_LOC_USE := self  
PyHeavyIonsAnalysisJetAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/JetAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisJetAnalysis
PyHeavyIonsAnalysisJetAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisJetAnalysis,src/HeavyIonsAnalysis/JetAnalysis/python,src_HeavyIonsAnalysis_JetAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisJetAnalysis,src/HeavyIonsAnalysis/JetAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_JetAnalysis_python
src_HeavyIonsAnalysis_JetAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_JetAnalysis_python,src/HeavyIonsAnalysis/JetAnalysis/python,PYTHON))
