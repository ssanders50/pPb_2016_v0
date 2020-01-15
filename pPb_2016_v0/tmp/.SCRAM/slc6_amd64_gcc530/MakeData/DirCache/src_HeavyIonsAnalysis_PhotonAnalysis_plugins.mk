ifeq ($(strip $(UserCodeDataAnalyzers_plugins)),)
UserCodeDataAnalyzers_plugins := self/src/HeavyIonsAnalysis/PhotonAnalysis/plugins
PLUGINS:=yes
UserCodeDataAnalyzers_plugins_files := $(patsubst src/HeavyIonsAnalysis/PhotonAnalysis/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/HeavyIonsAnalysis/PhotonAnalysis/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/HeavyIonsAnalysis/PhotonAnalysis/plugins/$(file). Please fix src/HeavyIonsAnalysis/PhotonAnalysis/plugins/BuildFile.))))
UserCodeDataAnalyzers_plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/PhotonAnalysis/plugins/BuildFile
UserCodeDataAnalyzers_plugins_LOC_USE := self  CondFormats/DataRecord CondFormats/EcalObjects DataFormats/Candidate DataFormats/Common DataFormats/PatCandidates DataFormats/EcalRecHit DataFormats/Math PhysicsTools/UtilAlgos PhysicsTools/CandUtils FWCore/ServiceRegistry FWCore/Framework FWCore/ParameterSet DataFormats/Provenance DataFormats/BeamSpot DataFormats/L1GlobalTrigger RecoEcal/EgammaCoreTools RecoEgamma/EgammaTools RecoEgamma/EgammaMCTools RecoJets/JetAlgorithms CommonTools/Statistics Geometry/Records Geometry/CaloGeometry Geometry/EcalAlgo RecoHI/HiEgammaAlgos DataFormats/HeavyIonEvent HeavyIonsAnalysis/PhotonAnalysis clhep root
UserCodeDataAnalyzers_plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,UserCodeDataAnalyzers_plugins,UserCodeDataAnalyzers_plugins,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/PhotonAnalysis/plugins))
UserCodeDataAnalyzers_plugins_PACKAGE := self/src/HeavyIonsAnalysis/PhotonAnalysis/plugins
ALL_PRODS += UserCodeDataAnalyzers_plugins
HeavyIonsAnalysis/PhotonAnalysis_forbigobj+=UserCodeDataAnalyzers_plugins
UserCodeDataAnalyzers_plugins_INIT_FUNC        += $$(eval $$(call Library,UserCodeDataAnalyzers_plugins,src/HeavyIonsAnalysis/PhotonAnalysis/plugins,src_HeavyIonsAnalysis_PhotonAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
UserCodeDataAnalyzers_plugins_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,UserCodeDataAnalyzers_plugins,src/HeavyIonsAnalysis/PhotonAnalysis/plugins))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_PhotonAnalysis_plugins
src_HeavyIonsAnalysis_PhotonAnalysis_plugins_parent := HeavyIonsAnalysis/PhotonAnalysis
src_HeavyIonsAnalysis_PhotonAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_PhotonAnalysis_plugins,src/HeavyIonsAnalysis/PhotonAnalysis/plugins,PLUGINS))
