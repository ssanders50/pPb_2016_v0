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
