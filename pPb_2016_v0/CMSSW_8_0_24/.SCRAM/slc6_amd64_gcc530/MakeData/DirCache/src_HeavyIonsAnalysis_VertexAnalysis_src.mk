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
