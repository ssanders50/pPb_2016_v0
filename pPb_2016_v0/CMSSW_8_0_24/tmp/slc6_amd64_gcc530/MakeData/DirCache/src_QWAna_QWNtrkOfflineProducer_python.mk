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
