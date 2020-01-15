ifeq ($(strip $(PyHeavyIonsAnalysisVNAnalysis)),)
PyHeavyIonsAnalysisVNAnalysis := self/src/HeavyIonsAnalysis/VNAnalysis/python
src_HeavyIonsAnalysis_VNAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/VNAnalysis/python)
PyHeavyIonsAnalysisVNAnalysis_files := $(patsubst src/HeavyIonsAnalysis/VNAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VNAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisVNAnalysis_LOC_USE := self  
PyHeavyIonsAnalysisVNAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/VNAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisVNAnalysis
PyHeavyIonsAnalysisVNAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisVNAnalysis,src/HeavyIonsAnalysis/VNAnalysis/python,src_HeavyIonsAnalysis_VNAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisVNAnalysis,src/HeavyIonsAnalysis/VNAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_VNAnalysis_python
src_HeavyIonsAnalysis_VNAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VNAnalysis_python,src/HeavyIonsAnalysis/VNAnalysis/python,PYTHON))
