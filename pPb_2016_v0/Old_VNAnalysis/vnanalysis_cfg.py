import FWCore.ParameterSet.Config as cms
import FWCore.ParameterSet.VarParsing as VarParsing
import os
import sys
ivars = VarParsing.VarParsing('standard')

ivars.register ('lumifile',
                'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt',
                mult=ivars.multiplicity.singleton,
                mytype=ivars.varType.string,
                info="lumi file")

ivars.register ('offset',
                'offset_pPb2016_pPb_MB.root',
                mult=ivars.multiplicity.singleton,
                mytype=ivars.varType.string,
                info="offset file")

ivars.register ('ntrkMin',
                0,
                mult=ivars.multiplicity.singleton,
                mytype=ivars.varType.int,
                info="min nTrk")

ivars.parseArguments()

process = cms.Process("FlatCheck")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('Configuration.EventContent.EventContentHeavyIons_cff')
process.load("RecoHI.HiEvtPlaneAlgos.HiEvtPlane_cfi")
process.load("RecoHI.HiEvtPlaneAlgos.hiEvtPlaneFlat_cfi")
process.load("HeavyIonsAnalysis.VNAnalysis/vnanalyzer_cfi")
process.load("RecoHI.HiCentralityAlgos.CentralityBin_cfi")
process.load("CondCore.CondDB.CondDB_cfi")
process.load('GeneratorInterface.HiGenCommon.HeavyIon_cff')
process.load("HeavyIonsAnalysis.Configuration.hfCoincFilter_cff")
process.load("HeavyIonsAnalysis.Configuration.analysisFilters_cff")
process.load("HeavyIonsAnalysis.Configuration.collisionEventSelection_cff")
process.load("TrackingCode.pileUpFilter.pileUpFilter_cff")
process.load("HeavyIonsAnalysis.QWNtrkOfflineProducer.QWNoff_cfi")

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_Prompt_v15', '')
process.GlobalTag.snapshotTime = cms.string("9999-12-31 23:59:59.000")


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
process.MessageLogger.cerr.FwkReport.reportEvery=10



import FWCore.PythonUtilities.LumiList as LumiList
goodLumiSecs = LumiList.LumiList(filename = ivars.lumifile ).getCMSSWString().split(',')

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 

#process.source = cms.Source ("PoolSource",fileNames = cms.untracked.vstring(),
#                             inputCommands=cms.untracked.vstring(
#        'keep *',
#        'drop *_hiEvtPlane_*_*'
#)
# )

process.source = cms.Source ("PoolSource",fileNames = cms.untracked.vstring(
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/065400BB-5AB1-E611-A4F6-FA163E7F116F.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/0A4989E3-5AB1-E611-A792-02163E012A64.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/2649FC1A-53B1-E611-A563-FA163E8D77E4.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/2C089730-51B1-E611-9E7F-FA163ECE0FC7.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/30C43750-4EB1-E611-99EB-02163E01246E.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/3E424DD4-5AB1-E611-8A1F-02163E013451.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/40AC8EC7-5AB1-E611-AE5B-02163E0145D8.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/46A6A5C9-5AB1-E611-95E4-FA163ED7F38A.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/4A9B46EB-4EB1-E611-9727-02163E01475A.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/4C764BAE-4FB1-E611-ADEF-FA163E921868.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/521FDCBE-4FB1-E611-9199-02163E01410C.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/6272E4D6-4EB1-E611-981F-FA163E4CA5AC.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/62D5C1E6-4EB1-E611-8D3D-FA163E044471.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/64F6542E-51B1-E611-8E0C-FA163ED87989.root',
        'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAMinimumBias1/AOD/PromptReco-v1/000/285/538/00000/686CE501-50B1-E611-A169-FA163EDC5F0C.root'
       ),
                             inputCommands=cms.untracked.vstring(
        'keep *',
        'drop *_hiEvtPlane_*_*'
        )
                             )

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("vnanal.root")
)


from HeavyIonsAnalysis.Configuration.collisionEventSelection_cff import *


import HLTrigger.HLTfilters.hltHighLevel_cfi
process.minBias = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.minBias.HLTPaths = [
                "HLT_PAL1MinimumBiasHF_OR_SinglePixelTrack_*_v*"
]

process.hltHM120 = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.hltHM120.HLTPaths = [
	"HLT_PAFullTracks_Multiplicity120_v*",
#	"HLT_PAFullTracks_Multiplicity150_v*",
#	"HLT_PAFullTracks_Multiplicity185_*",
#	"HLT_PAFullTracks_Multiplicity220_v*",
#	"HLT_PAFullTracks_Multiplicity250_v*",
#	"HLT_PAFullTracks_Multiplicity280_v*",
]
process.hltHM120.andOr = cms.bool(True)
process.hltHM120.throw = cms.bool(False)

process.hltHM150 = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.hltHM150.HLTPaths = [
	"HLT_PAFullTracks_Multiplicity120_v*",
	"HLT_PAFullTracks_Multiplicity150_v*",
#	"HLT_PAFullTracks_Multiplicity185_*",
#	"HLT_PAFullTracks_Multiplicity220_v*",
#	"HLT_PAFullTracks_Multiplicity250_v*",
#	"HLT_PAFullTracks_Multiplicity280_v*",
]
process.hltHM150.andOr = cms.bool(True)
process.hltHM150.throw = cms.bool(False)

process.hltHM185 = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.hltHM185.HLTPaths = [
#	"HLT_PAFullTracks_Multiplicity120_v*",
#	"HLT_PAFullTracks_Multiplicity150_v*",
	"HLT_PAFullTracks_Multiplicity185_*",
#	"HLT_PAFullTracks_Multiplicity220_v*",
#	"HLT_PAFullTracks_Multiplicity250_v*",
#	"HLT_PAFullTracks_Multiplicity280_v*",
]
process.hltHM185.andOr = cms.bool(True)
process.hltHM185.throw = cms.bool(False)

process.hltHM250 = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.hltHM250.HLTPaths = [
#	"HLT_PAFullTracks_Multiplicity120_v*",
#	"HLT_PAFullTracks_Multiplicity150_v*",
#	"HLT_PAFullTracks_Multiplicity185_*",
#	"HLT_PAFullTracks_Multiplicity220_v*",
	"HLT_PAFullTracks_Multiplicity250_v*",
#	"HLT_PAFullTracks_Multiplicity280_v*",
]
process.hltHM250.andOr = cms.bool(True)
process.hltHM250.throw = cms.bool(False)

process.load('RecoHI.HiCentralityAlgos.CentralityFilter_cfi')
process.ppNoffFilterMB = process.centralityFilter.clone(
		selectedBins = cms.vint32(
			*range(0, 600)
			),
		BinLabel = cms.InputTag("Noff")
		)

process.ppNoffFilter120 = process.centralityFilter.clone(
		selectedBins = cms.vint32(
			*range(120, 150)
			),
		BinLabel = cms.InputTag("Noff")
		)

process.ppNoffFilter150 = process.centralityFilter.clone(
		selectedBins = cms.vint32(
			*range(150, 185)
			),
		BinLabel = cms.InputTag("Noff")
		)

process.ppNoffFilter185 = process.centralityFilter.clone(
		selectedBins = cms.vint32(
			*range(185, 250)
			),
		BinLabel = cms.InputTag("Noff")
		)

process.ppNoffFilter250 = process.centralityFilter.clone(
		selectedBins = cms.vint32(
			*range(250, 600)
			),
		BinLabel = cms.InputTag("Noff")
		)


process.dump = cms.EDAnalyzer("EventContentAnalyzer")

process.hiEvtPlane.trackTag = cms.InputTag("generalTracks")
process.hiEvtPlane.vertexTag = cms.InputTag("offlinePrimaryVertices")
process.hiEvtPlane.loadDB = cms.bool(True)
process.hiEvtPlane.useNtrk = cms.untracked.bool(True)
process.hiEvtPlaneFlat.vertexTag = cms.InputTag("offlinePrimaryVertices")
process.hiEvtPlaneFlat.useNtrk = cms.untracked.bool(True)
process.vnanalyzer.vertexTag = cms.InputTag("offlinePrimaryVertices")
process.vnanalyzer.trackTag_ = cms.InputTag("generalTracks")
process.vnanalyzer.useNtrk = cms.untracked.bool(True)
process.vnanalyzer.offsetFile = cms.untracked.string( ivars.offset )
if ivars.ntrkMin == 0:
    process.CondDB.connect = "sqlite_file:HeavyIonRPRcd_pPb2016_MB_offline.db"
    process.PoolDBESSource = cms.ESSource("PoolDBESSource",
                                       process.CondDB,
                                       toGet = cms.VPSet(cms.PSet(record = cms.string('HeavyIonRPRcd'),
                                                                  tag = cms.string('HeavyIonRPRcd_pPb2016_MB_offline')
                                                                  )
                                                         )
                                      )
    process.es_prefer_flatparms = cms.ESPrefer('PoolDBESSource','')
    process.p = cms.Path(process.collisionEventSelectionPA*process.olvFilter_pPb8TeV_dz1p0*process.minBias*process.hfCoincFilter*process.Noff*process.ppNoffFilterMB*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)

if ivars.ntrkMin == 120:
    process.CondDB.connect = "sqlite_file:HeavyIonRPRcd_pPb2016_HM120_offline.db"
    process.PoolDBESSource = cms.ESSource("PoolDBESSource",
                                       process.CondDB,
                                       toGet = cms.VPSet(cms.PSet(record = cms.string('HeavyIonRPRcd'),
                                                                  tag = cms.string('HeavyIonRPRcd_pPb2016_HM120_offline')
                                                                  )
                                                         )
                                      )
    process.es_prefer_flatparms = cms.ESPrefer('PoolDBESSource','')
    process.p = cms.Path(process.collisionEventSelectionPA*process.olvFilter_pPb8TeV_dz1p0*process.hltHM120*process.hfCoincFilter*process.Noff*process.ppNoffFilter120*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)

if ivars.ntrkMin == 150:
    process.CondDB.connect = "sqlite_file:HeavyIonRPRcd_pPb2016_HM150_offline.db"
    process.PoolDBESSource = cms.ESSource("PoolDBESSource",
                                       process.CondDB,
                                       toGet = cms.VPSet(cms.PSet(record = cms.string('HeavyIonRPRcd'),
                                                                  tag = cms.string('HeavyIonRPRcd_pPb2016_HM150_offline')
                                                                  )
                                                         )
                                      )
    process.es_prefer_flatparms = cms.ESPrefer('PoolDBESSource','')
    process.p = cms.Path(process.collisionEventSelectionPA*process.olvFilter_pPb8TeV_dz1p0*process.hltHM150*process.hfCoincFilter*process.Noff*process.ppNoffFilter150*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)

if ivars.ntrkMin == 185:
    process.CondDB.connect = "sqlite_file:HeavyIonRPRcd_pPb2016_HM185_offline.db"
    process.PoolDBESSource = cms.ESSource("PoolDBESSource",
                                       process.CondDB,
                                       toGet = cms.VPSet(cms.PSet(record = cms.string('HeavyIonRPRcd'),
                                                                  tag = cms.string('HeavyIonRPRcd_pPb2016_HM185_offline')
                                                                  )
                                                         )
                                      )
    process.es_prefer_flatparms = cms.ESPrefer('PoolDBESSource','')
    process.p = cms.Path(process.collisionEventSelectionPA*process.olvFilter_pPb8TeV_dz1p0*process.hltHM185*process.hfCoincFilter*process.Noff*process.ppNoffFilter185*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)

if ivars.ntrkMin == 250:
    process.CondDB.connect = "sqlite_file:HeavyIonRPRcd_pPb2016_HM250_offline.db"
    process.PoolDBESSource = cms.ESSource("PoolDBESSource",
                                       process.CondDB,
                                       toGet = cms.VPSet(cms.PSet(record = cms.string('HeavyIonRPRcd'),
                                                                  tag = cms.string('HeavyIonRPRcd_pPb2016_HM250_offline')
                                                                  )
                                                         )
                                      )
    process.es_prefer_flatparms = cms.ESPrefer('PoolDBESSource','')
    process.p = cms.Path(process.collisionEventSelectionPA*process.olvFilter_pPb8TeV_dz1p0*process.hltHM250*process.hfCoincFilter*process.Noff*process.ppNoffFilter250*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)
