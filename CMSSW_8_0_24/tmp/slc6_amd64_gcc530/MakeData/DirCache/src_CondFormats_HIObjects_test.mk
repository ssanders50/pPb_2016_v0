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
