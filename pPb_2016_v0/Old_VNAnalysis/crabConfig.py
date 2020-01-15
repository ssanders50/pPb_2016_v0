from WMCore.Configuration import Configuration
config = Configuration()
from CRABClient.UserUtilities import getUsernameFromSiteDB
config.section_('General')
config.General.transferOutputs = True
config.General.transferLogs = True
config.section_('JobType')
config.JobType.outputFiles = ['vnanal.root']
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/home/sanders/pPb_2016_v0/VNAnalysis/vnanalysis_cfg.py'
config.JobType.maxJobRuntimeMin = 1315
config.section_('Data')
config.Data.unitsPerJob = 80
config.Data.publication = False
config.Data.splitting = 'LumiBased'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_US_Vanderbilt'

config.General.requestName = 'pPb2016_pPb_MB1'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_MB1'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_pPb_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_MB.root']
config.Data.inputDataset = '/PAMinimumBias1/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from httplib import HTTPException

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
    config.General.workArea = 'crab_projects'

    def submit(config):
        try:
            crabCommand('submit', config = config)
        except HTTPException, hte:
            print hte.headers

    #############################################################################################
    ## From now on that's what users should modify: this is the a-la-CRAB2 configuration part. ##
    #############################################################################################
#submit(config)

config.General.requestName = 'pPb2016_pPb_MB2'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_MB2'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_pPb_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_MB.root']
config.Data.inputDataset = '/PAMinimumBias2/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_MB3'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_MB3'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_pPb_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_MB.root']
config.Data.inputDataset = '/PAMinimumBias3/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_MB4'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_MB4'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_pPb_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_MB.root']
config.Data.inputDataset = '/PAMinimumBias4/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_MB5'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_MB5'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_pPb_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_MB.root']
config.Data.inputDataset = '/PAMinimumBias5/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_MB6'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_MB6'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_pPb_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_MB.root']
config.Data.inputDataset = '/PAMinimumBias6/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_MB7'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_MB7'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_pPb_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_MB.root']
config.Data.inputDataset = '/PAMinimumBias7/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_MB1'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_MB1'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_Pbp_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_MB.root']
config.Data.inputDataset = '/PAMinimumBias1/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_MB2'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_MB2'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_Pbp_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_MB.root']
config.Data.inputDataset = '/PAMinimumBias2/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_MB3'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_MB3'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_Pbp_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_MB.root']
config.Data.inputDataset = '/PAMinimumBias3/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_MB4'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_MB4'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_Pbp_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_MB.root']
config.Data.inputDataset = '/PAMinimumBias4/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_MB5'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_MB5'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_Pbp_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_MB.root']
config.Data.inputDataset = '/PAMinimumBias5/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_MB6'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_MB6'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_Pbp_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_MB.root']
config.Data.inputDataset = '/PAMinimumBias6/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_MB7'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_MB7'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_Pbp_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_MB.root']
config.Data.inputDataset = '/PAMinimumBias7/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_pPb_HM120_0'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM120_0'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM120_offline.db','offset_pPb2016_pPb_HM120.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=120','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM120.root']
config.Data.inputDataset = '/PAHighMultiplicity0/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
submit(config)


config.General.requestName = 'pPb2016_Pbp_HM120_0'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM120_0'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM120_offline.db','offset_pPb2016_Pbp_HM120.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=120','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM120.root']
config.Data.inputDataset = '/PAHighMultiplicity0/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)


config.General.requestName = 'pPb2016_pPb_HM150_0'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM150_0'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM150_offline.db','offset_pPb2016_pPb_HM150.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=150','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM150.root']
config.Data.inputDataset = '/PAHighMultiplicity0/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM150_0'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM150_0'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM150_offline.db','offset_pPb2016_Pbp_HM150.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=150','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM150.root']
config.Data.inputDataset = '/PAHighMultiplicity0/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)


config.General.requestName = 'pPb2016_pPb_HM185_1'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_1'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_pPb_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity1/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_HM185_2'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_2'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_pPb_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity2/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_HM185_3'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_3'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_pPb_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity3/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_HM185_4'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_4'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_pPb_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity4/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_HM185_5'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_5'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_pPb_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity5/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_pPb_HM185_6'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_6'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_pPb_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity6/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_HM185_1'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_1'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_Pbp_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity1/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_HM185_2'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_2'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_Pbp_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity2/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_HM185_3'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_3'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_Pbp_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity3/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_HM185_4'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_4'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_Pbp_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity4/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_HM185_5'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_5'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_Pbp_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity5/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_HM185_6'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_6'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db','offset_pPb2016_Pbp_HM185.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM185.root']
config.Data.inputDataset = '/PAHighMultiplicity6/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)



config.General.requestName = 'pPb2016_pPb_HM250_7'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM250_7'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM250_offline.db','offset_pPb2016_pPb_HM250.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=250','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_HM250.root']
config.Data.inputDataset = '/PAHighMultiplicity7/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_HM250_7'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM250_7'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM250_offline.db','offset_pPb2016_Pbp_HM250.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=250','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_Pbp_HM250.root']
config.Data.inputDataset = '/PAHighMultiplicity7/PARun2016C-PromptReco-v1/AOD'
config.Data.runRange = '285952-286496'
#submit(config)
