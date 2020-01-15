ifeq ($(strip $(PyHeavyIonsAnalysisHiEvtPlaneCalib)),)
PyHeavyIonsAnalysisHiEvtPlaneCalib := self/src/HeavyIonsAnalysis/HiEvtPlaneCalib/python
src_HeavyIonsAnalysis_HiEvtPlaneCalib_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/HiEvtPlaneCalib/python)
PyHeavyIonsAnalysisHiEvtPlaneCalib_files := $(patsubst src/HeavyIonsAnalysis/HiEvtPlaneCalib/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/HiEvtPlaneCalib/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisHiEvtPlaneCalib_LOC_USE := self  
PyHeavyIonsAnalysisHiEvtPlaneCalib_PACKAGE := self/src/HeavyIonsAnalysis/HiEvtPlaneCalib/python
ALL_PRODS += PyHeavyIonsAnalysisHiEvtPlaneCalib
PyHeavyIonsAnalysisHiEvtPlaneCalib_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisHiEvtPlaneCalib,src/HeavyIonsAnalysis/HiEvtPlaneCalib/python,src_HeavyIonsAnalysis_HiEvtPlaneCalib_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisHiEvtPlaneCalib,src/HeavyIonsAnalysis/HiEvtPlaneCalib/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_HiEvtPlaneCalib_python
src_HeavyIonsAnalysis_HiEvtPlaneCalib_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_HiEvtPlaneCalib_python,src/HeavyIonsAnalysis/HiEvtPlaneCalib/python,PYTHON))
