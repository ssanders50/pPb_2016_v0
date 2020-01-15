ALL_PACKAGES += src_bak/HeavyIonsAnalysis
subdirs_src_src_bak_HeavyIonsAnalysis := src_src_bak_HeavyIonsAnalysis_Configuration src_src_bak_HeavyIonsAnalysis_VertexAnalysis src_src_bak_HeavyIonsAnalysis_HiEvtPlaneCalib
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
ALL_SUBSYSTEMS+=RecoHI
subdirs_src_RecoHI = src_RecoHI_HiEvtPlaneAlgos
ALL_PACKAGES += HeavyIonsAnalysis/TrackAnalysis
subdirs_src_HeavyIonsAnalysis_TrackAnalysis := src_HeavyIonsAnalysis_TrackAnalysis_python src_HeavyIonsAnalysis_TrackAnalysis_interface src_HeavyIonsAnalysis_TrackAnalysis_src
ALL_PACKAGES += HeavyIonsAnalysis/EventAnalysis
subdirs_src_HeavyIonsAnalysis_EventAnalysis := src_HeavyIonsAnalysis_EventAnalysis_python src_HeavyIonsAnalysis_EventAnalysis_test src_HeavyIonsAnalysis_EventAnalysis_interface src_HeavyIonsAnalysis_EventAnalysis_src
ALL_PACKAGES += HeavyIonsAnalysis/CentralityAnalysis
subdirs_src_HeavyIonsAnalysis_CentralityAnalysis := src_HeavyIonsAnalysis_CentralityAnalysis_tools
ALL_COMMONRULES += src_HeavyIonsAnalysis_JetAnalysis_test
src_HeavyIonsAnalysis_JetAnalysis_test_parent := HeavyIonsAnalysis/JetAnalysis
src_HeavyIonsAnalysis_JetAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_JetAnalysis_test,src/HeavyIonsAnalysis/JetAnalysis/test,TEST))
ALL_COMMONRULES += src_HeavyIonsAnalysis_Configuration_test
src_HeavyIonsAnalysis_Configuration_test_parent := HeavyIonsAnalysis/Configuration
src_HeavyIonsAnalysis_Configuration_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_Configuration_test,src/HeavyIonsAnalysis/Configuration/test,TEST))
ALL_PACKAGES += src_bak/RecoHI
subdirs_src_src_bak_RecoHI := src_src_bak_RecoHI_HiEvtPlaneAlgos
ALL_PACKAGES += src_bak/CondFormats
subdirs_src_src_bak_CondFormats := 
ALL_PACKAGES += HeavyIonsAnalysis/VertexAnalysis
subdirs_src_HeavyIonsAnalysis_VertexAnalysis := src_HeavyIonsAnalysis_VertexAnalysis_plugins src_HeavyIonsAnalysis_VertexAnalysis_python src_HeavyIonsAnalysis_VertexAnalysis_src
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
ALL_PACKAGES += HeavyIonsAnalysis/JetAnalysis
subdirs_src_HeavyIonsAnalysis_JetAnalysis := src_HeavyIonsAnalysis_JetAnalysis_python src_HeavyIonsAnalysis_JetAnalysis_test src_HeavyIonsAnalysis_JetAnalysis_interface src_HeavyIonsAnalysis_JetAnalysis_src
ALL_PACKAGES += HeavyIonsAnalysis/HiEvtPlaneCalib
subdirs_src_HeavyIonsAnalysis_HiEvtPlaneCalib := src_HeavyIonsAnalysis_HiEvtPlaneCalib_python src_HeavyIonsAnalysis_HiEvtPlaneCalib_test src_HeavyIonsAnalysis_HiEvtPlaneCalib_src
ALL_PACKAGES += HeavyIonsAnalysis/MuonAnalysis
subdirs_src_HeavyIonsAnalysis_MuonAnalysis := src_HeavyIonsAnalysis_MuonAnalysis_python src_HeavyIonsAnalysis_MuonAnalysis_src
ALL_PACKAGES += RecoHI/HiEvtPlaneAlgos
subdirs_src_RecoHI_HiEvtPlaneAlgos := src_RecoHI_HiEvtPlaneAlgos_python src_RecoHI_HiEvtPlaneAlgos_test src_RecoHI_HiEvtPlaneAlgos_interface src_RecoHI_HiEvtPlaneAlgos_src
ifeq ($(strip $(PyRecoHIHiEvtPlaneAlgos)),)
PyRecoHIHiEvtPlaneAlgos := self/src/RecoHI/HiEvtPlaneAlgos/python
src_RecoHI_HiEvtPlaneAlgos_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoHI/HiEvtPlaneAlgos/python)
PyRecoHIHiEvtPlaneAlgos_files := $(patsubst src/RecoHI/HiEvtPlaneAlgos/python/%,%,$(wildcard $(foreach dir,src/RecoHI/HiEvtPlaneAlgos/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoHIHiEvtPlaneAlgos_LOC_USE := self  
PyRecoHIHiEvtPlaneAlgos_PACKAGE := self/src/RecoHI/HiEvtPlaneAlgos/python
ALL_PRODS += PyRecoHIHiEvtPlaneAlgos
PyRecoHIHiEvtPlaneAlgos_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoHIHiEvtPlaneAlgos,src/RecoHI/HiEvtPlaneAlgos/python,src_RecoHI_HiEvtPlaneAlgos_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoHIHiEvtPlaneAlgos,src/RecoHI/HiEvtPlaneAlgos/python))
endif
ALL_COMMONRULES += src_RecoHI_HiEvtPlaneAlgos_python
src_RecoHI_HiEvtPlaneAlgos_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoHI_HiEvtPlaneAlgos_python,src/RecoHI/HiEvtPlaneAlgos/python,PYTHON))
ifeq ($(strip $(testSerializationHIObjects)),)
testSerializationHIObjects_files := $(patsubst src/CondFormats/HIObjects/test/%,%,$(foreach file,testSerializationHIObjects.cpp,$(eval xfile:=$(wildcard src/CondFormats/HIObjects/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/CondFormats/HIObjects/test/$(file). Please fix src/CondFormats/HIObjects/test/BuildFile.))))
testSerializationHIObjects := self/src/CondFormats/HIObjects/test
testSerializationHIObjects_TEST_RUNNER_CMD :=  testSerializationHIObjects 
testSerializationHIObjects_BuildFile    := $(WORKINGDIR)/cache/bf/src/CondFormats/HIObjects/test/BuildFile
testSerializationHIObjects_LOC_USE := self  CondFormats/HIObjects
testSerializationHIObjects_PACKAGE := self/src/CondFormats/HIObjects/test
ALL_PRODS += testSerializationHIObjects
testSerializationHIObjects_INIT_FUNC        += $$(eval $$(call Binary,testSerializationHIObjects,src/CondFormats/HIObjects/test,src_CondFormats_HIObjects_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testSerializationHIObjects_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,testSerializationHIObjects,src/CondFormats/HIObjects/test))
endif
ALL_COMMONRULES += src_CondFormats_HIObjects_test
src_CondFormats_HIObjects_test_parent := CondFormats/HIObjects
src_CondFormats_HIObjects_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_CondFormats_HIObjects_test,src/CondFormats/HIObjects/test,TEST))
ALL_SUBSYSTEMS+=src_bak
subdirs_src_src_bak = src_src_bak_QWAna src_src_bak_RecoHI src_src_bak_TrackingCode src_src_bak_HeavyIonsAnalysis src_src_bak_CondFormats
ALL_PACKAGES += src_bak/QWAna
subdirs_src_src_bak_QWAna := 
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
ifeq ($(strip $(PyHeavyIonsAnalysisEventAnalysis)),)
PyHeavyIonsAnalysisEventAnalysis := self/src/HeavyIonsAnalysis/EventAnalysis/python
src_HeavyIonsAnalysis_EventAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/EventAnalysis/python)
PyHeavyIonsAnalysisEventAnalysis_files := $(patsubst src/HeavyIonsAnalysis/EventAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/EventAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisEventAnalysis_LOC_USE := self  
PyHeavyIonsAnalysisEventAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/EventAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisEventAnalysis
PyHeavyIonsAnalysisEventAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisEventAnalysis,src/HeavyIonsAnalysis/EventAnalysis/python,src_HeavyIonsAnalysis_EventAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisEventAnalysis,src/HeavyIonsAnalysis/EventAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_EventAnalysis_python
src_HeavyIonsAnalysis_EventAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_EventAnalysis_python,src/HeavyIonsAnalysis/EventAnalysis/python,PYTHON))
ALL_SUBSYSTEMS+=CondFormats
subdirs_src_CondFormats = src_CondFormats_HIObjects
ifeq ($(strip $(PyHeavyIonsAnalysisConfiguration)),)
PyHeavyIonsAnalysisConfiguration := self/src/HeavyIonsAnalysis/Configuration/python
src_HeavyIonsAnalysis_Configuration_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/Configuration/python)
PyHeavyIonsAnalysisConfiguration_files := $(patsubst src/HeavyIonsAnalysis/Configuration/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/Configuration/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisConfiguration_LOC_USE := self  
PyHeavyIonsAnalysisConfiguration_PACKAGE := self/src/HeavyIonsAnalysis/Configuration/python
ALL_PRODS += PyHeavyIonsAnalysisConfiguration
PyHeavyIonsAnalysisConfiguration_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisConfiguration,src/HeavyIonsAnalysis/Configuration/python,src_HeavyIonsAnalysis_Configuration_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisConfiguration,src/HeavyIonsAnalysis/Configuration/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_Configuration_python
src_HeavyIonsAnalysis_Configuration_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_Configuration_python,src/HeavyIonsAnalysis/Configuration/python,PYTHON))
ALL_SUBSYSTEMS+=QWAna
subdirs_src_QWAna = src_QWAna_QWNtrkOfflineProducer
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
ALL_PACKAGES += HeavyIonsAnalysis/PhotonAnalysis
subdirs_src_HeavyIonsAnalysis_PhotonAnalysis := src_HeavyIonsAnalysis_PhotonAnalysis_plugins src_HeavyIonsAnalysis_PhotonAnalysis_python src_HeavyIonsAnalysis_PhotonAnalysis_src
ALL_COMMONRULES += src_RecoHI_HiEvtPlaneAlgos_test
src_RecoHI_HiEvtPlaneAlgos_test_parent := RecoHI/HiEvtPlaneAlgos
src_RecoHI_HiEvtPlaneAlgos_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoHI_HiEvtPlaneAlgos_test,src/RecoHI/HiEvtPlaneAlgos/test,TEST))
ALL_PACKAGES += QWAna/QWNtrkOfflineProducer
subdirs_src_QWAna_QWNtrkOfflineProducer := src_QWAna_QWNtrkOfflineProducer_python src_QWAna_QWNtrkOfflineProducer_test src_QWAna_QWNtrkOfflineProducer_src
ALL_PACKAGES += HeavyIonsAnalysis/Configuration
subdirs_src_HeavyIonsAnalysis_Configuration := src_HeavyIonsAnalysis_Configuration_python src_HeavyIonsAnalysis_Configuration_test src_HeavyIonsAnalysis_Configuration_macros
ALL_PACKAGES += src_bak/TrackingCode
subdirs_src_src_bak_TrackingCode := src_src_bak_TrackingCode_pileUpFilter
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
ALL_PACKAGES += CondFormats/HIObjects
subdirs_src_CondFormats_HIObjects := src_CondFormats_HIObjects_test src_CondFormats_HIObjects_src
ALL_COMMONRULES += src_HeavyIonsAnalysis_HiEvtPlaneCalib_test
src_HeavyIonsAnalysis_HiEvtPlaneCalib_test_parent := HeavyIonsAnalysis/HiEvtPlaneCalib
src_HeavyIonsAnalysis_HiEvtPlaneCalib_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_HiEvtPlaneCalib_test,src/HeavyIonsAnalysis/HiEvtPlaneCalib/test,TEST))
ALL_SUBSYSTEMS+=HeavyIonsAnalysis
subdirs_src_HeavyIonsAnalysis = src_HeavyIonsAnalysis_HiEvtPlaneCalib src_HeavyIonsAnalysis_EventAnalysis src_HeavyIonsAnalysis_VertexAnalysis src_HeavyIonsAnalysis_PhotonAnalysis src_HeavyIonsAnalysis_VNAnalysis src_HeavyIonsAnalysis_CentralityAnalysis src_HeavyIonsAnalysis_MuonAnalysis src_HeavyIonsAnalysis_TrackAnalysis src_HeavyIonsAnalysis_Configuration src_HeavyIonsAnalysis_JetAnalysis
ALL_PACKAGES += HeavyIonsAnalysis/VNAnalysis
subdirs_src_HeavyIonsAnalysis_VNAnalysis := src_HeavyIonsAnalysis_VNAnalysis_doc src_HeavyIonsAnalysis_VNAnalysis_python src_HeavyIonsAnalysis_VNAnalysis_test src_HeavyIonsAnalysis_VNAnalysis_interface src_HeavyIonsAnalysis_VNAnalysis_src
ALL_COMMONRULES += src_QWAna_QWNtrkOfflineProducer_test
src_QWAna_QWNtrkOfflineProducer_test_parent := QWAna/QWNtrkOfflineProducer
src_QWAna_QWNtrkOfflineProducer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_QWAna_QWNtrkOfflineProducer_test,src/QWAna/QWNtrkOfflineProducer/test,TEST))
ALL_COMMONRULES += src_HeavyIonsAnalysis_EventAnalysis_test
src_HeavyIonsAnalysis_EventAnalysis_test_parent := HeavyIonsAnalysis/EventAnalysis
src_HeavyIonsAnalysis_EventAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_EventAnalysis_test,src/HeavyIonsAnalysis/EventAnalysis/test,TEST))
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
ifeq ($(strip $(PyQWAnaQWNtrkOfflineProducer)),)
PyQWAnaQWNtrkOfflineProducer := self/src/QWAna/QWNtrkOfflineProducer/python
src_QWAna_QWNtrkOfflineProducer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/QWAna/QWNtrkOfflineProducer/python)
PyQWAnaQWNtrkOfflineProducer_files := $(patsubst src/QWAna/QWNtrkOfflineProducer/python/%,%,$(wildcard $(foreach dir,src/QWAna/QWNtrkOfflineProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyQWAnaQWNtrkOfflineProducer_LOC_USE := self  
PyQWAnaQWNtrkOfflineProducer_PACKAGE := self/src/QWAna/QWNtrkOfflineProducer/python
ALL_PRODS += PyQWAnaQWNtrkOfflineProducer
PyQWAnaQWNtrkOfflineProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyQWAnaQWNtrkOfflineProducer,src/QWAna/QWNtrkOfflineProducer/python,src_QWAna_QWNtrkOfflineProducer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyQWAnaQWNtrkOfflineProducer,src/QWAna/QWNtrkOfflineProducer/python))
endif
ALL_COMMONRULES += src_QWAna_QWNtrkOfflineProducer_python
src_QWAna_QWNtrkOfflineProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_QWAna_QWNtrkOfflineProducer_python,src/QWAna/QWNtrkOfflineProducer/python,PYTHON))
ALL_COMMONRULES += src_HeavyIonsAnalysis_VNAnalysis_test
src_HeavyIonsAnalysis_VNAnalysis_test_parent := HeavyIonsAnalysis/VNAnalysis
src_HeavyIonsAnalysis_VNAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VNAnalysis_test,src/HeavyIonsAnalysis/VNAnalysis/test,TEST))
