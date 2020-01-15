ifeq ($(strip $(QWAna/QWNtrkOfflineProducer)),)
ALL_COMMONRULES += src_QWAna_QWNtrkOfflineProducer_src
src_QWAna_QWNtrkOfflineProducer_src_parent := QWAna/QWNtrkOfflineProducer
src_QWAna_QWNtrkOfflineProducer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_QWAna_QWNtrkOfflineProducer_src,src/QWAna/QWNtrkOfflineProducer/src,LIBRARY))
QWAnaQWNtrkOfflineProducer := self/QWAna/QWNtrkOfflineProducer
QWAna/QWNtrkOfflineProducer := QWAnaQWNtrkOfflineProducer
QWAnaQWNtrkOfflineProducer_files := $(patsubst src/QWAna/QWNtrkOfflineProducer/src/%,%,$(wildcard $(foreach dir,src/QWAna/QWNtrkOfflineProducer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
QWAnaQWNtrkOfflineProducer_BuildFile    := $(WORKINGDIR)/cache/bf/src/QWAna/QWNtrkOfflineProducer/BuildFile
QWAnaQWNtrkOfflineProducer_LOC_USE := self  root hepmc FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/Common DataFormats/Candidate DataFormats/VertexReco DataFormats/TrackReco DataFormats/ParticleFlowCandidate DataFormats/HepMCCandidate DataFormats/CaloTowers DataFormats/HcalDigi DataFormats/HeavyIonEvent CommonTools/UtilAlgos PhysicsTools/CandUtils TrackingTools/TransientTrack MagneticField/Records SimDataFormats/GeneratorProducts TrackingTools/IPTools CalibFormats/HcalObjects
QWAnaQWNtrkOfflineProducer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,QWAnaQWNtrkOfflineProducer,QWAnaQWNtrkOfflineProducer,$(SCRAMSTORENAME_LIB),src/QWAna/QWNtrkOfflineProducer/src))
QWAnaQWNtrkOfflineProducer_PACKAGE := self/src/QWAna/QWNtrkOfflineProducer/src
ALL_PRODS += QWAnaQWNtrkOfflineProducer
QWAnaQWNtrkOfflineProducer_CLASS := LIBRARY
QWAna/QWNtrkOfflineProducer_forbigobj+=QWAnaQWNtrkOfflineProducer
QWAnaQWNtrkOfflineProducer_INIT_FUNC        += $$(eval $$(call Library,QWAnaQWNtrkOfflineProducer,src/QWAna/QWNtrkOfflineProducer/src,src_QWAna_QWNtrkOfflineProducer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
