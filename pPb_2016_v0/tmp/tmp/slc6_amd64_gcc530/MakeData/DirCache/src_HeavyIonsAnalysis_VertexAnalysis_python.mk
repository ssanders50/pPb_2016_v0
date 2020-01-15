ifeq ($(strip $(PyHeavyIonsAnalysisVertexAnalysis)),)
PyHeavyIonsAnalysisVertexAnalysis := self/src/HeavyIonsAnalysis/VertexAnalysis/python
src_HeavyIonsAnalysis_VertexAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/VertexAnalysis/python)
PyHeavyIonsAnalysisVertexAnalysis_files := $(patsubst src/HeavyIonsAnalysis/VertexAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VertexAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisVertexAnalysis_LOC_USE := self  
PyHeavyIonsAnalysisVertexAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/VertexAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisVertexAnalysis
PyHeavyIonsAnalysisVertexAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisVertexAnalysis,src/HeavyIonsAnalysis/VertexAnalysis/python,src_HeavyIonsAnalysis_VertexAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisVertexAnalysis,src/HeavyIonsAnalysis/VertexAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_VertexAnalysis_python
src_HeavyIonsAnalysis_VertexAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VertexAnalysis_python,src/HeavyIonsAnalysis/VertexAnalysis/python,PYTHON))
