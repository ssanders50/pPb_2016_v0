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
ifeq ($(strip $(HeavyIonsAnalysis/JetAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_JetAnalysis_src
src_HeavyIonsAnalysis_JetAnalysis_src_parent := HeavyIonsAnalysis/JetAnalysis
src_HeavyIonsAnalysis_JetAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_JetAnalysis_src,src/HeavyIonsAnalysis/JetAnalysis/src,LIBRARY))
HeavyIonsAnalysisJetAnalysis := self/HeavyIonsAnalysis/JetAnalysis
HeavyIonsAnalysis/JetAnalysis := HeavyIonsAnalysisJetAnalysis
HeavyIonsAnalysisJetAnalysis_files := $(patsubst src/HeavyIonsAnalysis/JetAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/JetAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisJetAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/JetAnalysis/BuildFile
HeavyIonsAnalysisJetAnalysis_LOC_USE := self  root hepmc boost fastjet fastjet-contrib FWCore/PluginManager FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Framework PhysicsTools/UtilAlgos CommonTools/UtilAlgos Geometry/CaloGeometry Geometry/Records SimGeneral/HepPDTRecord SimDataFormats/GeneratorProducts SimDataFormats/HiGenData SimTracker/TrackAssociation SimTracker/Records DataFormats/HepMCCandidate DataFormats/EcalRecHit DataFormats/HcalRecHit DataFormats/HcalDigi DataFormats/HcalDetId DataFormats/DetId DataFormats/GeometryVector DataFormats/JetReco DataFormats/METReco DataFormats/PatCandidates RecoJets/JetProducers RecoHI/HiJetAlgos DataFormats/HeavyIonEvent CondFormats/JetMETObjects CalibFormats/HcalObjects RecoLocalCalo/HcalRecAlgos RecoBTag/SecondaryVertex
HeavyIonsAnalysisJetAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisJetAnalysis,HeavyIonsAnalysisJetAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/JetAnalysis/src))
HeavyIonsAnalysisJetAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/JetAnalysis/src
ALL_PRODS += HeavyIonsAnalysisJetAnalysis
HeavyIonsAnalysisJetAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/JetAnalysis_forbigobj+=HeavyIonsAnalysisJetAnalysis
HeavyIonsAnalysisJetAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisJetAnalysis,src/HeavyIonsAnalysis/JetAnalysis/src,src_HeavyIonsAnalysis_JetAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/HiEvtPlaneCalib)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_HiEvtPlaneCalib_src
src_HeavyIonsAnalysis_HiEvtPlaneCalib_src_parent := HeavyIonsAnalysis/HiEvtPlaneCalib
src_HeavyIonsAnalysis_HiEvtPlaneCalib_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_HiEvtPlaneCalib_src,src/HeavyIonsAnalysis/HiEvtPlaneCalib/src,LIBRARY))
HeavyIonsAnalysisHiEvtPlaneCalib := self/HeavyIonsAnalysis/HiEvtPlaneCalib
HeavyIonsAnalysis/HiEvtPlaneCalib := HeavyIonsAnalysisHiEvtPlaneCalib
HeavyIonsAnalysisHiEvtPlaneCalib_files := $(patsubst src/HeavyIonsAnalysis/HiEvtPlaneCalib/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/HiEvtPlaneCalib/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisHiEvtPlaneCalib_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/HiEvtPlaneCalib/BuildFile
HeavyIonsAnalysisHiEvtPlaneCalib_LOC_USE := self  root rootrflx FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Utilities PhysicsTools/UtilAlgos DataFormats/Candidate DataFormats/HcalRecHit DataFormats/WrappedStdDictionaries Geometry/Records DataFormats/HepMCCandidate DataFormats/TrackReco DataFormats/VertexReco DataFormats/Common DataFormats/HeavyIonEvent DataFormats/CaloTowers DataFormats/Provenance CondCore/DBOutputService CondFormats/DataRecord RecoHI/HiCentralityAlgos clhep
HeavyIonsAnalysisHiEvtPlaneCalib_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisHiEvtPlaneCalib,HeavyIonsAnalysisHiEvtPlaneCalib,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/HiEvtPlaneCalib/src))
HeavyIonsAnalysisHiEvtPlaneCalib_PACKAGE := self/src/HeavyIonsAnalysis/HiEvtPlaneCalib/src
ALL_PRODS += HeavyIonsAnalysisHiEvtPlaneCalib
HeavyIonsAnalysisHiEvtPlaneCalib_CLASS := LIBRARY
HeavyIonsAnalysis/HiEvtPlaneCalib_forbigobj+=HeavyIonsAnalysisHiEvtPlaneCalib
HeavyIonsAnalysisHiEvtPlaneCalib_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisHiEvtPlaneCalib,src/HeavyIonsAnalysis/HiEvtPlaneCalib/src,src_HeavyIonsAnalysis_HiEvtPlaneCalib_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/TrackAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_TrackAnalysis_src
src_HeavyIonsAnalysis_TrackAnalysis_src_parent := HeavyIonsAnalysis/TrackAnalysis
src_HeavyIonsAnalysis_TrackAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_TrackAnalysis_src,src/HeavyIonsAnalysis/TrackAnalysis/src,LIBRARY))
HeavyIonsAnalysisTrackAnalysis := self/HeavyIonsAnalysis/TrackAnalysis
HeavyIonsAnalysis/TrackAnalysis := HeavyIonsAnalysisTrackAnalysis
HeavyIonsAnalysisTrackAnalysis_files := $(patsubst src/HeavyIonsAnalysis/TrackAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/TrackAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisTrackAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/TrackAnalysis/BuildFile
HeavyIonsAnalysisTrackAnalysis_LOC_USE := self  hepmc root heppdt DataFormats/Common DataFormats/DetId DataFormats/EcalRecHit DataFormats/GeometryVector DataFormats/HeavyIonEvent DataFormats/SiPixelDigi DataFormats/TrackingRecHit DataFormats/VertexReco DataFormats/HepMCCandidate RecoBTag/SecondaryVertex FWCore/Framework FWCore/ServiceRegistry FWCore/PluginManager FWCore/ParameterSet PhysicsTools/UtilAlgos SimDataFormats/Vertex SimDataFormats/GeneratorProducts SimDataFormats/TrackingAnalysis SimGeneral/HepPDTRecord SimTracker/TrackerHitAssociation SimTracker/TrackAssociation SimTracker/Records Geometry/CaloGeometry Geometry/CommonDetUnit Geometry/TrackerGeometryBuilder Geometry/Records RecoTracker/Record HLTrigger/HLTcore
HeavyIonsAnalysisTrackAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisTrackAnalysis,HeavyIonsAnalysisTrackAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/TrackAnalysis/src))
HeavyIonsAnalysisTrackAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/TrackAnalysis/src
ALL_PRODS += HeavyIonsAnalysisTrackAnalysis
HeavyIonsAnalysisTrackAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/TrackAnalysis_forbigobj+=HeavyIonsAnalysisTrackAnalysis
HeavyIonsAnalysisTrackAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisTrackAnalysis,src/HeavyIonsAnalysis/TrackAnalysis/src,src_HeavyIonsAnalysis_TrackAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/VNAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_VNAnalysis_src
src_HeavyIonsAnalysis_VNAnalysis_src_parent := HeavyIonsAnalysis/VNAnalysis
src_HeavyIonsAnalysis_VNAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VNAnalysis_src,src/HeavyIonsAnalysis/VNAnalysis/src,LIBRARY))
HeavyIonsAnalysisVNAnalysis := self/HeavyIonsAnalysis/VNAnalysis
HeavyIonsAnalysis/VNAnalysis := HeavyIonsAnalysisVNAnalysis
HeavyIonsAnalysisVNAnalysis_files := $(patsubst src/HeavyIonsAnalysis/VNAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VNAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisVNAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/VNAnalysis/BuildFile
HeavyIonsAnalysisVNAnalysis_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Utilities PhysicsTools/UtilAlgos PhysicsTools/JetMCUtils SimGeneral/HepPDTRecord SimDataFormats/CaloHit SimDataFormats/Track SimDataFormats/TrackingHit SimDataFormats/Vertex SimDataFormats/GeneratorProducts SimDataFormats/CrossingFrame SimDataFormats/HiGenData DataFormats/HepMCCandidate DataFormats/JetReco DataFormats/HeavyIonEvent CondFormats/HIObjects CondFormats/DataRecord DataFormats/WrappedStdDictionaries DataFormats/Common DataFormats/Provenance DataFormats/EgammaReco Geometry/Records RecoHI/HiCentralityAlgos root clhep
HeavyIonsAnalysisVNAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisVNAnalysis,HeavyIonsAnalysisVNAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/VNAnalysis/src))
HeavyIonsAnalysisVNAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/VNAnalysis/src
ALL_PRODS += HeavyIonsAnalysisVNAnalysis
HeavyIonsAnalysisVNAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/VNAnalysis_forbigobj+=HeavyIonsAnalysisVNAnalysis
HeavyIonsAnalysisVNAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisVNAnalysis,src/HeavyIonsAnalysis/VNAnalysis/src,src_HeavyIonsAnalysis_VNAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(RecoHI/HiEvtPlaneAlgos)),)
ALL_COMMONRULES += src_RecoHI_HiEvtPlaneAlgos_src
src_RecoHI_HiEvtPlaneAlgos_src_parent := RecoHI/HiEvtPlaneAlgos
src_RecoHI_HiEvtPlaneAlgos_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoHI_HiEvtPlaneAlgos_src,src/RecoHI/HiEvtPlaneAlgos/src,LIBRARY))
RecoHIHiEvtPlaneAlgos := self/RecoHI/HiEvtPlaneAlgos
RecoHI/HiEvtPlaneAlgos := RecoHIHiEvtPlaneAlgos
RecoHIHiEvtPlaneAlgos_files := $(patsubst src/RecoHI/HiEvtPlaneAlgos/src/%,%,$(wildcard $(foreach dir,src/RecoHI/HiEvtPlaneAlgos/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoHIHiEvtPlaneAlgos_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoHI/HiEvtPlaneAlgos/BuildFile
RecoHIHiEvtPlaneAlgos_LOC_USE := self  root FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Utilities PhysicsTools/UtilAlgos DataFormats/Candidate DataFormats/HcalRecHit DataFormats/WrappedStdDictionaries Geometry/Records DataFormats/HepMCCandidate DataFormats/TrackReco DataFormats/VertexReco DataFormats/Common DataFormats/HeavyIonEvent DataFormats/CaloTowers DataFormats/Provenance CondCore/DBOutputService CondFormats/DataRecord RecoHI/HiCentralityAlgos clhep
RecoHIHiEvtPlaneAlgos_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoHIHiEvtPlaneAlgos,RecoHIHiEvtPlaneAlgos,$(SCRAMSTORENAME_LIB),src/RecoHI/HiEvtPlaneAlgos/src))
RecoHIHiEvtPlaneAlgos_PACKAGE := self/src/RecoHI/HiEvtPlaneAlgos/src
ALL_PRODS += RecoHIHiEvtPlaneAlgos
RecoHIHiEvtPlaneAlgos_CLASS := LIBRARY
RecoHI/HiEvtPlaneAlgos_forbigobj+=RecoHIHiEvtPlaneAlgos
RecoHIHiEvtPlaneAlgos_INIT_FUNC        += $$(eval $$(call Library,RecoHIHiEvtPlaneAlgos,src/RecoHI/HiEvtPlaneAlgos/src,src_RecoHI_HiEvtPlaneAlgos_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/MuonAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_MuonAnalysis_src
src_HeavyIonsAnalysis_MuonAnalysis_src_parent := HeavyIonsAnalysis/MuonAnalysis
src_HeavyIonsAnalysis_MuonAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_MuonAnalysis_src,src/HeavyIonsAnalysis/MuonAnalysis/src,LIBRARY))
HeavyIonsAnalysisMuonAnalysis := self/HeavyIonsAnalysis/MuonAnalysis
HeavyIonsAnalysis/MuonAnalysis := HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/MuonAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/MuonAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisMuonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/MuonAnalysis/BuildFile
HeavyIonsAnalysisMuonAnalysis_LOC_USE := self  clhep root FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/ServiceRegistry DataFormats/HepMCCandidate DataFormats/MuonReco DataFormats/HeavyIonEvent SimDataFormats/TrackingAnalysis CommonTools/UtilAlgos CondFormats/HIObjects CondFormats/DataRecord TrackingTools/TransientTrack RecoVertex/KalmanVertexFit DataFormats/TrackReco DataFormats/TrackerRecHit2D DataFormats/TrackingRecHit RecoTracker/TkTrackingRegions
HeavyIonsAnalysisMuonAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisMuonAnalysis,HeavyIonsAnalysisMuonAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/MuonAnalysis/src))
HeavyIonsAnalysisMuonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/MuonAnalysis/src
ALL_PRODS += HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/MuonAnalysis_forbigobj+=HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisMuonAnalysis,src/HeavyIonsAnalysis/MuonAnalysis/src,src_HeavyIonsAnalysis_MuonAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysisVertexAnalysisAuto)),)
HeavyIonsAnalysisVertexAnalysisAuto := self/src/HeavyIonsAnalysis/VertexAnalysis/plugins
PLUGINS:=yes
HeavyIonsAnalysisVertexAnalysisAuto_files := $(patsubst src/HeavyIonsAnalysis/VertexAnalysis/plugins/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VertexAnalysis/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisVertexAnalysisAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/VertexAnalysis/plugins/BuildFile
HeavyIonsAnalysisVertexAnalysisAuto_LOC_USE := self  FWCore/Utilities DataFormats/VertexReco FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger CommonTools/UtilAlgos root
HeavyIonsAnalysisVertexAnalysisAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisVertexAnalysisAuto,HeavyIonsAnalysisVertexAnalysisAuto,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/VertexAnalysis/plugins))
HeavyIonsAnalysisVertexAnalysisAuto_PACKAGE := self/src/HeavyIonsAnalysis/VertexAnalysis/plugins
ALL_PRODS += HeavyIonsAnalysisVertexAnalysisAuto
HeavyIonsAnalysis/VertexAnalysis_forbigobj+=HeavyIonsAnalysisVertexAnalysisAuto
HeavyIonsAnalysisVertexAnalysisAuto_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisVertexAnalysisAuto,src/HeavyIonsAnalysis/VertexAnalysis/plugins,src_HeavyIonsAnalysis_VertexAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
HeavyIonsAnalysisVertexAnalysisAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,HeavyIonsAnalysisVertexAnalysisAuto,src/HeavyIonsAnalysis/VertexAnalysis/plugins))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_VertexAnalysis_plugins
src_HeavyIonsAnalysis_VertexAnalysis_plugins_parent := HeavyIonsAnalysis/VertexAnalysis
src_HeavyIonsAnalysis_VertexAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VertexAnalysis_plugins,src/HeavyIonsAnalysis/VertexAnalysis/plugins,PLUGINS))
ifeq ($(strip $(HeavyIonsAnalysis/EventAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_EventAnalysis_src
src_HeavyIonsAnalysis_EventAnalysis_src_parent := HeavyIonsAnalysis/EventAnalysis
src_HeavyIonsAnalysis_EventAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_EventAnalysis_src,src/HeavyIonsAnalysis/EventAnalysis/src,LIBRARY))
HeavyIonsAnalysisEventAnalysis := self/HeavyIonsAnalysis/EventAnalysis
HeavyIonsAnalysis/EventAnalysis := HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_files := $(patsubst src/HeavyIonsAnalysis/EventAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/EventAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisEventAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/EventAnalysis/BuildFile
HeavyIonsAnalysisEventAnalysis_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet CommonTools/UtilAlgos FWCore/ServiceRegistry DataFormats/HeavyIonEvent DataFormats/VertexReco RecoHI/HiCentralityAlgos DataFormats/HepMCCandidate DataFormats/JetReco DataFormats/Common SimDataFormats/HiGenData SimDataFormats/GeneratorProducts FWCore/Common DataFormats/HLTReco HLTrigger/HLTcore CondFormats/HLTObjects CondFormats/DataRecord
HeavyIonsAnalysisEventAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisEventAnalysis,HeavyIonsAnalysisEventAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/EventAnalysis/src))
HeavyIonsAnalysisEventAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/EventAnalysis/src
ALL_PRODS += HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/EventAnalysis_forbigobj+=HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisEventAnalysis,src/HeavyIonsAnalysis/EventAnalysis/src,src_HeavyIonsAnalysis_EventAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/PhotonAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_PhotonAnalysis_src
src_HeavyIonsAnalysis_PhotonAnalysis_src_parent := HeavyIonsAnalysis/PhotonAnalysis
src_HeavyIonsAnalysis_PhotonAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_PhotonAnalysis_src,src/HeavyIonsAnalysis/PhotonAnalysis/src,LIBRARY))
HeavyIonsAnalysisPhotonAnalysis := self/HeavyIonsAnalysis/PhotonAnalysis
HeavyIonsAnalysis/PhotonAnalysis := HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/PhotonAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/PhotonAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisPhotonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/PhotonAnalysis/BuildFile
HeavyIonsAnalysisPhotonAnalysis_LOC_USE := self  CondFormats/DataRecord CondFormats/EcalObjects FWCore/Framework FWCore/ParameterSet DataFormats/HcalRecHit DataFormats/EgammaReco DataFormats/Candidate DataFormats/PatCandidates Geometry/CaloGeometry DataFormats/HepMCCandidate clhep root
HeavyIonsAnalysisPhotonAnalysis_EX_LIB   := HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_EX_USE   := $(foreach d,$(HeavyIonsAnalysisPhotonAnalysis_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
HeavyIonsAnalysisPhotonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/PhotonAnalysis/src
ALL_PRODS += HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/PhotonAnalysis_forbigobj+=HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisPhotonAnalysis,src/HeavyIonsAnalysis/PhotonAnalysis/src,src_HeavyIonsAnalysis_PhotonAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/VertexAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_VertexAnalysis_src
src_HeavyIonsAnalysis_VertexAnalysis_src_parent := HeavyIonsAnalysis/VertexAnalysis
src_HeavyIonsAnalysis_VertexAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VertexAnalysis_src,src/HeavyIonsAnalysis/VertexAnalysis/src,LIBRARY))
HeavyIonsAnalysisVertexAnalysis := self/HeavyIonsAnalysis/VertexAnalysis
HeavyIonsAnalysis/VertexAnalysis := HeavyIonsAnalysisVertexAnalysis
HeavyIonsAnalysisVertexAnalysis_files := $(patsubst src/HeavyIonsAnalysis/VertexAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VertexAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisVertexAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/VertexAnalysis/BuildFile
HeavyIonsAnalysisVertexAnalysis_LOC_USE := self  hepmc FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/MessageLogger FWCore/Utilities DataFormats/Common DataFormats/FEDRawData DataFormats/SiStripDetId DataFormats/TrackerRecHit2D DataFormats/SiPixelDetId DataFormats/DetId CondFormats/DataRecord CondFormats/SiStripObjects CalibFormats/SiStripObjects CalibTracker/Records FWCore/ServiceRegistry CommonTools/UtilAlgos DataFormats/SiStripCluster DataFormats/SiPixelCluster DataFormats/HeavyIonEvent DataFormats/TrackReco DataFormats/VertexReco DataFormats/HepMCCandidate DataFormats/Math DataFormats/Scalers Geometry/TrackerGeometryBuilder SimTracker/Records SimTracker/TrackAssociation SimTracker/TrackHistory SimDataFormats/GeneratorProducts SimDataFormats/PileupSummaryInfo SimGeneral/HepPDTRecord
HeavyIonsAnalysisVertexAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisVertexAnalysis,HeavyIonsAnalysisVertexAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/VertexAnalysis/src))
HeavyIonsAnalysisVertexAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/VertexAnalysis/src
ALL_PRODS += HeavyIonsAnalysisVertexAnalysis
HeavyIonsAnalysisVertexAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/VertexAnalysis_forbigobj+=HeavyIonsAnalysisVertexAnalysis
HeavyIonsAnalysisVertexAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisVertexAnalysis,src/HeavyIonsAnalysis/VertexAnalysis/src,src_HeavyIonsAnalysis_VertexAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
