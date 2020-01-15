ifeq ($(strip $(PyHeavyIonsAnalysisTrackAnalysis)),)
PyHeavyIonsAnalysisTrackAnalysis := self/src/HeavyIonsAnalysis/TrackAnalysis/python
src_HeavyIonsAnalysis_TrackAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/TrackAnalysis/python)
PyHeavyIonsAnalysisTrackAnalysis_files := $(patsubst src/HeavyIonsAnalysis/TrackAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/TrackAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisTrackAnalysis_LOC_USE := self  
PyHeavyIonsAnalysisTrackAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/TrackAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisTrackAnalysis
PyHeavyIonsAnalysisTrackAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisTrackAnalysis,src/HeavyIonsAnalysis/TrackAnalysis/python,src_HeavyIonsAnalysis_TrackAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisTrackAnalysis,src/HeavyIonsAnalysis/TrackAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_TrackAnalysis_python
src_HeavyIonsAnalysis_TrackAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_TrackAnalysis_python,src/HeavyIonsAnalysis/TrackAnalysis/python,PYTHON))
