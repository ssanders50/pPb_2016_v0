ifeq ($(strip $(CondFormats/HIObjects)),)
ALL_COMMONRULES += src_CondFormats_HIObjects_src
src_CondFormats_HIObjects_src_parent := CondFormats/HIObjects
src_CondFormats_HIObjects_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_CondFormats_HIObjects_src,src/CondFormats/HIObjects/src,LIBRARY))
CondFormatsHIObjects := self/CondFormats/HIObjects
CondFormats/HIObjects := CondFormatsHIObjects
CondFormatsHIObjects_files := $(patsubst src/CondFormats/HIObjects/src/%,%,$(wildcard $(foreach dir,src/CondFormats/HIObjects/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
CondFormatsHIObjects_BuildFile    := $(WORKINGDIR)/cache/bf/src/CondFormats/HIObjects/BuildFile
CondFormatsHIObjects_LOC_USE := self  CondFormats/Common CondFormats/Serialization FWCore/Framework boost_serialization
CondFormatsHIObjects_LCGDICTS  := x 
CondFormatsHIObjects_PRE_INIT_FUNC += $$(eval $$(call LCGDict,CondFormatsHIObjects,src/CondFormats/HIObjects/src/classes.h,src/CondFormats/HIObjects/src/classes_def.xml,$(SCRAMSTORENAME_LIB), --fail_on_warnings,))
CondFormatsHIObjects_PRE_INIT_FUNC += $$(eval $$(call CondSerialization,CondFormatsHIObjects,src/CondFormats/HIObjects/src,src/CondFormats/HIObjects/src/headers.h))
CondFormatsHIObjects_EX_LIB   := CondFormatsHIObjects
CondFormatsHIObjects_EX_USE   := $(foreach d,$(CondFormatsHIObjects_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
CondFormatsHIObjects_PACKAGE := self/src/CondFormats/HIObjects/src
ALL_PRODS += CondFormatsHIObjects
CondFormatsHIObjects_CLASS := LIBRARY
CondFormats/HIObjects_forbigobj+=CondFormatsHIObjects
CondFormatsHIObjects_INIT_FUNC        += $$(eval $$(call Library,CondFormatsHIObjects,src/CondFormats/HIObjects/src,src_CondFormats_HIObjects_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
