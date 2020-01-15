ifeq ($(strip $(PyHeavyIonsAnalysisMuonAnalysis)),)
PyHeavyIonsAnalysisMuonAnalysis := self/src/HeavyIonsAnalysis/MuonAnalysis/python
src_HeavyIonsAnalysis_MuonAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/MuonAnalysis/python)
PyHeavyIonsAnalysisMuonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/MuonAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/MuonAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisMuonAnalysis_LOC_USE := self  
PyHeavyIonsAnalysisMuonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/MuonAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisMuonAnalysis
PyHeavyIonsAnalysisMuonAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisMuonAnalysis,src/HeavyIonsAnalysis/MuonAnalysis/python,src_HeavyIonsAnalysis_MuonAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisMuonAnalysis,src/HeavyIonsAnalysis/MuonAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_MuonAnalysis_python
src_HeavyIonsAnalysis_MuonAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_MuonAnalysis_python,src/HeavyIonsAnalysis/MuonAnalysis/python,PYTHON))
