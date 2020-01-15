ifeq ($(strip $(PyHeavyIonsAnalysisPhotonAnalysis)),)
PyHeavyIonsAnalysisPhotonAnalysis := self/src/HeavyIonsAnalysis/PhotonAnalysis/python
src_HeavyIonsAnalysis_PhotonAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/PhotonAnalysis/python)
PyHeavyIonsAnalysisPhotonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/PhotonAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/PhotonAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisPhotonAnalysis_LOC_USE := self  
PyHeavyIonsAnalysisPhotonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/PhotonAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisPhotonAnalysis
PyHeavyIonsAnalysisPhotonAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisPhotonAnalysis,src/HeavyIonsAnalysis/PhotonAnalysis/python,src_HeavyIonsAnalysis_PhotonAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisPhotonAnalysis,src/HeavyIonsAnalysis/PhotonAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_PhotonAnalysis_python
src_HeavyIonsAnalysis_PhotonAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_PhotonAnalysis_python,src/HeavyIonsAnalysis/PhotonAnalysis/python,PYTHON))
