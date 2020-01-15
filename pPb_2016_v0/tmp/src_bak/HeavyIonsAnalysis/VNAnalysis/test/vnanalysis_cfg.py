import FWCore.ParameterSet.Config as cms
import FWCore.ParameterSet.VarParsing as VarParsing
import sys

ivars = VarParsing.VarParsing('standard')

ivars.register ('dbfile',
                'HeavyIonRPRcd_PbPb2011_75x_v02_offline',
                mult=ivars.multiplicity.singleton,
                mytype=ivars.varType.string,
                info="db file")

ivars.parseArguments()
process = cms.Process("vn")


process = cms.Process("VNAnalyzer")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration/StandardSequences/Reconstruction_cff')
process.load('Configuration.EventContent.EventContentHeavyIons_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("RecoHI.HiEvtPlaneAlgos.HiEvtPlane_cfi")
process.load("RecoHI.HiEvtPlaneAlgos.hiEvtPlaneFlat_cfi")
process.load("RecoHI.HiCentralityAlgos.HiCentrality_cfi")
process.load("HeavyIonsAnalysis.VNAnalysis.vnanalyzer_cfi")
process.load("RecoHI.HiCentralityAlgos.CentralityBin_cfi")
process.load("CondCore.DBCommon.CondDBCommon_cfi")

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '75X_mcRun2_HeavyIon_v5', '')
process.GlobalTag.snapshotTime = cms.string("9999-12-31 23:59:59.000")


process.MessageLogger.cerr.FwkReport.reportEvery=1000


process.GlobalTag.toGet.extend([
   cms.PSet(record = cms.string("HeavyIonRcd"),
      tag = cms.string("CentralityTable_HFtowers200_HydjetDrum5_v750x02_mc"),
      connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS"),
      label = cms.untracked.string("HFtowers")
   )
])


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_1.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_10.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_100.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_101.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_102.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_103.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_104.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_105.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_106.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_107.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_108.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_109.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_11.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_110.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_111.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_112.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_113.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_114.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_115.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_116.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_117.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_118.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_119.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_12.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_120.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_121.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_122.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_123.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_124.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_125.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_126.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_127.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_128.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_129.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_13.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_130.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_131.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_132.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_133.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_134.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_135.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_136.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_137.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_138.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_139.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_14.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_140.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_141.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_142.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_143.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_144.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_145.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_146.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_147.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_148.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_149.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_15.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_150.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_151.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_152.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_153.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_154.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_155.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_156.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_157.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_158.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_159.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_16.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_160.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_161.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_162.root',
       'root://cmsxrootd.fnal.gov//store/user/tuos/HIAOD2015/round3/June01/HydjetMB/Hydjet_Quenched_MinBias_5020GeV/HydjetMB_AOD_750pre5_round3v01/150601_223002/0000/step2_RAW2DIGI_L1Reco_MB_AODSIM_163.root'
        ),
                            duplicateCheckMode = cms.untracked.string("noDuplicateCheck"),
                            inputCommands=cms.untracked.vstring(
        'keep *',
        )

)

process.CondDBCommon.connect = "sqlite_file:HeavyIonRPRcd_75x_v02_offline.db"
process.PoolDBESSource = cms.ESSource("PoolDBESSource",
                                       process.CondDBCommon,
                                       toGet = cms.VPSet(cms.PSet(record = cms.string('HeavyIonRPRcd'),
                                                                  tag = cms.string('HeavyIonRPRcd_75x_v02_offline')
                                                                  )
                                                         )
                                      )


process.TFileService = cms.Service("TFileService",
    fileName = cms.string("rpflat.root")
)

# Minimum bias trigger selection (later runs)
process.hiEvtPlane.loadDB = cms.bool(True)
process.p = cms.Path(process.centralityBin*process.hiEvtPlane*process.hiEvtPlaneFlat*process.vnanalyzer)

