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


ivars.register ('reaction',
                'pPb',
                mult=ivars.multiplicity.singleton,
                mytype=ivars.varType.string,
                info="reaction direction")

ivars.register ('ntrkMin',
                120,
                mult=ivars.multiplicity.singleton,
                mytype=ivars.varType.int,
                info="min nTrk")

ivars.parseArguments()

process = cms.Process("vnanal")

process.load("CondCore.CondDB.CondDB_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.EventContent.EventContentHeavyIons_cff')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load("Configuration.Geometry.GeometryDB_cff")
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
#process.load("TrackingCode.pileUpFilter.pileUpFilter_cff")
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("RecoHI.HiEvtPlaneAlgos.HiEvtPlane_cfi")
process.load("RecoHI.HiEvtPlaneAlgos.hiEvtPlaneFlat_cfi")
process.load("RecoHI.HiCentralityAlgos.CentralityBin_cfi")
process.load('GeneratorInterface.HiGenCommon.HeavyIon_cff')
process.load("HeavyIonsAnalysis.Configuration.hfCoincFilter_cff")
process.load("HeavyIonsAnalysis.Configuration.analysisFilters_cff")
process.load("HeavyIonsAnalysis.Configuration.collisionEventSelection_cff")
process.load("QWAna.QWNtrkOfflineProducer.QWNoff_cfi")
process.load("HeavyIonsAnalysis.VNAnalysis/vnanalyzer_cfi")

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_Prompt_v16', '')


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery=500



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

process.source = cms.Source ("PoolSource",
        fileNames = cms.untracked.vstring("root://cmsxrootd.fnal.gov//store/user/davidlw/PAHighMultiplicity0/RecoSkim2016_pPb_V0Cascade_v1/170301_201930/0000/pPb_HM_28.root"),
	secondaryFileNames = cms.untracked.vstring(
#		'file:/eos/cms/store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/479/00000/3AB7179C-DCAE-E611-980E-FA163EC8DDF7.root',
#		'file:/eos/cms/store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/480/00000/0E343491-06AF-E611-AF4F-FA163E0C8993.root',
#		'file:/eos/cms/store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/480/00000/CAAC6AB7-06AF-E611-A23C-FA163EA53949.root',
#		'file:/eos/cms/store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/480/00000/D0F23BC7-06AF-E611-8D86-FA163EA3E531.root',
#		'file:/eos/cms/store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/480/00000/FE0873CE-06AF-E611-92B7-02163E0140FE.root'
		'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/480/00000/AC8FA173-08AF-E611-94F2-02163E014561.root',
		'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/480/00000/A417C575-08AF-E611-9BFC-FA163E05A16C.root',
		'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/480/00000/34DF5A88-08AF-E611-BC70-FA163E5AF33F.root',
		'root://cmsxrootd.fnal.gov//store/hidata/PARun2016C/PAHighMultiplicity0/AOD/PromptReco-v1/000/285/480/00000/1E07EF6E-08AF-E611-A8B7-FA163EFF24E2.root'
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

process.vnanalyzer.qwTagPhi_ = cms.InputTag("QWV0EventLambda","phi")
process.vnanalyzer.qwTagEta_ = cms.InputTag("QWV0EventLambda","eta")
process.vnanalyzer.qwTagRapidity_ = cms.InputTag("QWV0EventLambda","rapidity")
process.vnanalyzer.qwTagPt_ = cms.InputTag("QWV0EventLambda","pt")
process.vnanalyzer.qwTagMass_ = cms.InputTag("QWV0EventLambda","mass")
process.vnanalyzer.qwTagWeight_ = cms.InputTag("QWV0EventLambda","weight")
process.vnanalyzer.reaction_ = cms.string("pPb")


process.load("HeavyIonsAnalysis.VertexAnalysis.PAPileUpVertexFilter_cff")

process.PAprimaryVertexFilter = cms.EDFilter("VertexSelector",
    src = cms.InputTag("offlinePrimaryVertices"),
    cut = cms.string("!isFake && abs(z) <= 25 && position.Rho <= 2 && tracksSize >= 2"),
    filter = cms.bool(True), # otherwise it won't filter the events
)
process.NoScraping = cms.EDFilter("FilterOutScraping",
 applyfilter = cms.untracked.bool(True),
 debugOn = cms.untracked.bool(False),
 numtrack = cms.untracked.uint32(10),
 thresh = cms.untracked.double(0.25)
)

process.QWVertex = cms.EDProducer('QWVertexProducer',
		vertexSrc = cms.untracked.InputTag('offlinePrimaryVertices')
	)
process.QWPrimaryVz = cms.EDProducer('QWVectorSelector',
		vectSrc = cms.untracked.InputTag('QWVertex', 'vz'),
	)
process.QWVzFilter15 = cms.EDFilter('QWDoubleFilter',
		src = cms.untracked.InputTag('QWPrimaryVz'),
		dmin = cms.untracked.double(-15.),
		dmax = cms.untracked.double(15.),
	)
process.QWPrimaryVertexSelection = cms.Sequence( process.QWVertex * process.QWPrimaryVz * process.QWVzFilter15 )
####### Lambda

process.QWV0EventLambda = cms.EDProducer('QWV0VectProducer'
        , vertexSrc = cms.untracked.InputTag('offlinePrimaryVertices')
        , trackSrc = cms.untracked.InputTag('generalTracks')
        , V0Src = cms.untracked.InputTag('generalV0CandidatesNew', 'Lambda')
        , daughter_cuts = cms.untracked.PSet(
            )
        , cuts = cms.untracked.VPSet(
            cms.untracked.PSet(
                Massmin = cms.untracked.double(1.1115)
                , Massmax = cms.untracked.double(1.1200)
                , DecayXYZMin = cms.untracked.double(5.0)
                , ThetaXYZMin = cms.untracked.double(0.999)
                , ptMin = cms.untracked.double(0.2)
                , ptMax = cms.untracked.double(8.5)
                , Rapmin = cms.untracked.double(-1.0)
                , Rapmax = cms.untracked.double(1.0)
                )
            )
        )


process.load('pPb_HM_eff')
process.QWEvent.fweight = cms.untracked.InputTag('NA')
process.QWEvent.ptMin = cms.untracked.double(0.2)
process.QWEvent.ptMax = cms.untracked.double(8.5)

process.QWCumuDiff = cms.EDAnalyzer('QWCumuDiff',
		trackSet = cms.untracked.PSet(
			Eta = cms.untracked.InputTag('QWEvent', 'eta'),
			Phi = cms.untracked.InputTag('QWEvent', 'phi'),
			Ref = cms.untracked.InputTag('QWEvent', 'ref'),
			Pt  = cms.untracked.InputTag('QWEvent', 'pt'),
			Weight = cms.untracked.InputTag('QWEvent', 'weight'),
			),
		sigSet = cms.untracked.PSet(
			Eta = cms.untracked.InputTag('QWV0EventLambda', 'rapidity'),
			Phi = cms.untracked.InputTag('QWV0EventLambda', 'phi'),
			Ref = cms.untracked.InputTag('QWV0EventLambda', 'Refs'),
			Pt = cms.untracked.InputTag('QWV0EventLambda', 'pt'),
			Weight = cms.untracked.InputTag('QWV0EventLambda', 'weight'),
			),
		vertexZ = cms.untracked.InputTag('QWEvent', "vz"),
		ptBin = cms.untracked.vdouble(0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6,6.0, 7.0, 8.5),
		centrality = cms.untracked.InputTag('Noff')
		)

process.vectV0MassLm120 = cms.EDAnalyzer('QWVectorAnalyzer',
		src = cms.untracked.InputTag("QWV0EventLambda", "mass"),
		hNbins = cms.untracked.int32(100),
		hstart = cms.untracked.double(0),
		hend = cms.untracked.double(100),
		cNbins = cms.untracked.int32(160),
		cstart = cms.untracked.double(1.08),
		cend = cms.untracked.double(1.16),
		)

process.vectV0MassLm150 = process.vectV0MassLm120.clone()
process.vectV0MassLm185 = process.vectV0MassLm120.clone()
process.vectV0MassLm250 = process.vectV0MassLm120.clone()

process.vectPhi120Lm = process.vectPhi.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'phi'))
process.vectPhi150Lm = process.vectPhi.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'phi'))
process.vectPhi185Lm = process.vectPhi.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'phi'))
process.vectPhi250Lm = process.vectPhi.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'phi'))

process.vectEta120Lm = process.vectEta.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'rapidity'))
process.vectEta150Lm = process.vectEta.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'rapidity'))
process.vectEta185Lm = process.vectEta.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'rapidity'))
process.vectEta250Lm = process.vectEta.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'rapidity'))

process.vectPt120Lm = process.vectPt.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'pt'), cNbins = cms.untracked.int32(1000), cend = cms.untracked.double(10))
process.vectPt150Lm = process.vectPt.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'pt'), cNbins = cms.untracked.int32(1000), cend = cms.untracked.double(10))
process.vectPt185Lm = process.vectPt.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'pt'), cNbins = cms.untracked.int32(1000), cend = cms.untracked.double(10))
process.vectPt250Lm = process.vectPt.clone(src = cms.untracked.InputTag('QWV0EventLambda', 'pt'), cNbins = cms.untracked.int32(1000), cend = cms.untracked.double(10))


########## Ks
#process.QWV0EventKs = cms.EDProducer('QWV0VectProducer'
#        , vertexSrc = cms.untracked.InputTag('offlinePrimaryVertices')
#        , trackSrc = cms.untracked.InputTag('generalTracks')
#        , V0Src = cms.untracked.InputTag('generalV0CandidatesNew', 'Kshort')
#        , daughter_cuts = cms.untracked.PSet(
#            )
#        , cuts = cms.untracked.VPSet(
#            cms.untracked.PSet(
#                Massmin = cms.untracked.double(0.492)
#                , Massmax = cms.untracked.double(0.503)
#                , DecayXYZMin = cms.untracked.double(5.0)
#                , ThetaXYZMin = cms.untracked.double(0.999)
#                , ptMin = cms.untracked.double(0.2)
#                , ptMax = cms.untracked.double(8.5)
#                , Rapmin = cms.untracked.double(-1.0)
#                , Rapmax = cms.untracked.double(1.0)
#                )
#            )
#        )
#
#process.load('pPb_HM_eff')
#process.QWEvent.fweight = cms.untracked.InputTag('NA')
#process.QWEvent.ptMin = cms.untracked.double(0.2)
#process.QWEvent.ptMax = cms.untracked.double(8.5)


#process.vectV0MassKs120 = cms.EDAnalyzer('QWVectorAnalyzer',
#		src = cms.untracked.InputTag("QWV0EventKs", "mass"),
#		hNbins = cms.untracked.int32(100),
#		hstart = cms.untracked.double(0),
#		hend = cms.untracked.double(100),
#		cNbins = cms.untracked.int32(270),
#		cstart = cms.untracked.double(.43),
#		cend = cms.untracked.double(0.565),
#		)

#process.vectV0MassKs150 = process.vectV0MassKs120.clone()
#process.vectV0MassKs185 = process.vectV0MassKs120.clone()
#process.vectV0MassKs250 = process.vectV0MassKs120.clone()

#process.vectPhi120Ks = process.vectPhi.clone(src = cms.untracked.InputTag('QWV0EventKs', 'phi'))
#process.vectPhi150Ks = process.vectPhi.clone(src = cms.untracked.InputTag('QWV0EventKs', 'phi'))
#process.vectPhi185Ks = process.vectPhi.clone(src = cms.untracked.InputTag('QWV0EventKs', 'phi'))
#process.vectPhi250Ks = process.vectPhi.clone(src = cms.untracked.InputTag('QWV0EventKs', 'phi'))

#process.vectEta120Ks = process.vectEta.clone(src = cms.untracked.InputTag('QWV0EventKs', 'rapidity'))
#process.vectEta150Ks = process.vectEta.clone(src = cms.untracked.InputTag('QWV0EventKs', 'rapidity'))
#process.vectEta185Ks = process.vectEta.clone(src = cms.untracked.InputTag('QWV0EventKs', 'rapidity'))
#process.vectEta250Ks = process.vectEta.clone(src = cms.untracked.InputTag('QWV0EventKs', 'rapidity'))

#process.vectPt120Ks = process.vectPt.clone(src = cms.untracked.InputTag('QWV0EventKs', 'pt'), cNbins = cms.untracked.int32(1000), cend = cms.untracked.double(10))
#process.vectPt150Ks = process.vectPt.clone(src = cms.untracked.InputTag('QWV0EventKs', 'pt'), cNbins = cms.untracked.int32(1000), cend = cms.untracked.double(10))
#process.vectPt185Ks = process.vectPt.clone(src = cms.untracked.InputTag('QWV0EventKs', 'pt'), cNbins = cms.untracked.int32(1000), cend = cms.untracked.double(10))
#process.vectPt250Ks = process.vectPt.clone(src = cms.untracked.InputTag('QWV0EventKs', 'pt'), cNbins = cms.untracked.int32(1000), cend = cms.untracked.double(10))
#######
process.vectPhi120 = process.vectPhi.clone()
process.vectPhi150 = process.vectPhi.clone()
process.vectPhi185 = process.vectPhi.clone()
process.vectPhi250 = process.vectPhi.clone()

process.vectPhiW120 = process.vectPhiW.clone()
process.vectPhiW150 = process.vectPhiW.clone()
process.vectPhiW185 = process.vectPhiW.clone()
process.vectPhiW250 = process.vectPhiW.clone()

process.vectEta120 = process.vectEta.clone()
process.vectEta150 = process.vectEta.clone()
process.vectEta185 = process.vectEta.clone()
process.vectEta250 = process.vectEta.clone()

process.vectEtaW120 = process.vectEtaW.clone()
process.vectEtaW150 = process.vectEtaW.clone()
process.vectEtaW185 = process.vectEtaW.clone()
process.vectEtaW250 = process.vectEtaW.clone()

process.vectPt120 = process.vectPt.clone()
process.vectPt150 = process.vectPt.clone()
process.vectPt185 = process.vectPt.clone()
process.vectPt250 = process.vectPt.clone()

process.vectPtW120 = process.vectPtW.clone()
process.vectPtW150 = process.vectPtW.clone()
process.vectPtW185 = process.vectPtW.clone()
process.vectPtW250 = process.vectPtW.clone()
##### Lambda
process.mon120 = cms.Sequence(process.histNoff + process.vectPhi120 + process.vectPhi120Lm + process.vectPt120 + process.vectPt120Lm + process.vectEta120 + process.vectEta120Lm + process.vectV0MassLm120)
process.mon150 = cms.Sequence(process.histNoff + process.vectPhi150 + process.vectPhi150Lm + process.vectPt150 + process.vectPt150Lm + process.vectEta150 + process.vectEta150Lm + process.vectV0MassLm150)
process.mon185 = cms.Sequence(process.histNoff + process.vectPhi185 + process.vectPhi185Lm + process.vectPt185 + process.vectPt185Lm + process.vectEta185 + process.vectEta185Lm + process.vectV0MassLm185)
process.mon250 = cms.Sequence(process.histNoff + process.vectPhi250 + process.vectPhi250Lm + process.vectPt250 + process.vectPt250Lm + process.vectEta250 + process.vectEta250Lm + process.vectV0MassLm250)

##### Ks
#process.mon120 = cms.Sequence(process.histNoff + process.vectPhi120 + process.vectPhi120Ks + process.vectPt120 + process.vectPt120Ks + process.vectEta120 + process.vectEta120Ks + process.vectV0MassKs120)
#process.mon150 = cms.Sequence(process.histNoff + process.vectPhi150 + process.vectPhi150Ks + process.vectPt150 + process.vectPt150Ks + process.vectEta150 + process.vectEta150Ks + process.vectV0MassKs150)
#process.mon185 = cms.Sequence(process.histNoff + process.vectPhi185 + process.vectPhi185Ks + process.vectPt185 + process.vectPt185Ks + process.vectEta185 + process.vectEta185Ks + process.vectV0MassKs185)
#process.mon250 = cms.Sequence(process.histNoff + process.vectPhi250 + process.vectPhi250Ks + process.vectPt250 + process.vectPt250Ks + process.vectEta250 + process.vectEta250Ks + process.vectV0MassKs250)
######
process.load("HeavyIonsAnalysis.Configuration.hfCoincFilter_cff")
process.load("HeavyIonsAnalysis.VertexAnalysis.pileUpFilter_cff")

process.eventSelection = cms.Sequence(process.hfCoincFilter * process.PAprimaryVertexFilter * process.NoScraping * process.olvFilter_pPb8TeV_dz1p0 * process.QWPrimaryVertexSelection)
#process.RECO = cms.OutputModule("PoolOutputModule",
#		outputCommands = cms.untracked.vstring('keep *'),
#		SelectEvents = cms.untracked.PSet(
#			SelectEvents = cms.vstring('ana120', 'ana150')
#			),
#		fileName = cms.untracked.string('recoV0.root')
#		)

#process.out = cms.EndPath(process.RECO)


process.hiEvtPlane.trackTag = cms.InputTag("generalTracks")
process.hiEvtPlane.vertexTag = cms.InputTag("offlinePrimaryVertices")
process.hiEvtPlane.loadDB = cms.bool(True)
process.hiEvtPlane.useNtrk = cms.untracked.bool(True)
process.hiEvtPlaneFlat.vertexTag = cms.InputTag("offlinePrimaryVertices")
process.hiEvtPlaneFlat.useNtrk = cms.untracked.bool(True)
process.vnanalyzer.vertexTag = cms.InputTag("offlinePrimaryVertices")
process.vnanalyzer.trackTag_ = cms.InputTag("generalTracks")
process.vnanalyzer.useNtrk = cms.untracked.bool(True)
process.vnanalyzer.makeTree_ = cms.untracked.bool(False)
process.vnanalyzer.reaction_ = cms.string(ivars.reaction)

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
    process.p = cms.Path(process.hltHM120*process.eventSelection*process.Noff*process.ppNoffFilter120*process.QWEvent * process.QWV0EventLambda  * process.mon120*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)

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
    process.p = cms.Path(process.hltHM150*process.eventSelection*process.Noff*process.ppNoffFilter150*process.QWEvent * process.QWV0EventLambda * process.mon150*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)

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
    process.p = cms.Path(process.hltHM185*process.eventSelection*process.Noff*process.ppNoffFilter185*process.QWEvent * process.QWV0EventLambda * process.mon185*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)

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
    process.p = cms.Path(process.hltHM250*process.eventSelection*process.Noff*process.ppNoffFilter250*process.QWEvent * process.QWV0EventLambda *  process.mon250*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)
