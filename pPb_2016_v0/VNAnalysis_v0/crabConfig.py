from WMCore.Configuration import Configuration
config = Configuration()
from CRABClient.UserUtilities import getUsernameFromSiteDB
config.section_('General')
config.General.transferOutputs = True
config.General.transferLogs = True
config.section_('JobType')
config.JobType.outputFiles = ['vnanal.root']
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/home/sanders/pPb_2016_v0/VNAnalysis_v0/vnanalysis_cfg.py'
#config.JobType.maxJobRuntimeMin = 1315
config.section_('Data')
config.Data.unitsPerJob = 25
config.Data.publication = False
config.Data.useParent = True
config.Data.splitting = 'LumiBased'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_US_Vanderbilt'

config.General.requestName = 'pPb2016_pPb_v0_Ks'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_v0_Ks'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_MB_offline.db','offset_pPb2016_pPb_MB.root']
config.JobType.pyCfgParams = ['noprint','ntrkMin=0','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','offset=offset_pPb2016_pPb_MB.root']
config.Data.inputDataset = '/PAHighMultiplicity0/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.inputDBS = 'phys03'
config.Data.runRange = '285479-285832'
config.Site.ignoreGlobalBlacklist = True
config.Data.ignoreLocality = True
config.Site.whitelist = ['T2_US_Vanderbilt']
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

config.General.requestName = 'pPb2016_pPb_HM120_Ks'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM120_Ks'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM120_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=120','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity0/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM120_Ks'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM120_Ks'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM120_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=120','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity0/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)


config.General.requestName = 'pPb2016_pPb_HM150_Ks'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM150_Ks'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM150_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=150','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity0/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM150_Ks'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM150_Ks'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM150_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=150','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity0/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)


config.General.requestName = 'pPb2016_pPb_HM185_Ks_1'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_Ks_1'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity1/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM185_Ks_1'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_Ks_1'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity1/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)


config.General.requestName = 'pPb2016_pPb_HM185_Ks_2'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_Ks_2'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity2/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM185_Ks_2'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_Ks_2'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity2/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_pPb_HM185_Ks_3'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_Ks_3'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity3/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM185_Ks_3'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_Ks_3'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity3/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)

config.General.requestName = 'pPb2016_pPb_HM185_Ks_4'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_Ks_4'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity4/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM185_Ks_4'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_Ks_4'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity4/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)


config.General.requestName = 'pPb2016_pPb_HM185_Ks_5'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_Ks_5'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity5/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM185_Ks_5'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_Ks_5'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity5/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)


config.General.requestName = 'pPb2016_pPb_HM185_Ks_6'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM185_Ks_6'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity6/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)


config.General.requestName = 'pPb2016_Pbp_HM185_Ks_6'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM185_Ks_6'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM185_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=185','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity6/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)



config.General.requestName = 'pPb2016_pPb_HM250_Ks_7'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_pPb_HM250_Ks_7'
config.Data.lumiMask = 'Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM250_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=250','reaction=pPb','lumifile=Cert_285479-285832_HI8TeV_PromptReco_pPb_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity7/davidlw-RecoSkim2016_pPb_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285479-285832'
#submit(config)

config.General.requestName = 'pPb2016_Pbp_HM250_Ks_7'
config.Data.outLFNDirBase = '/store/user/ssanders/pPb2016_Pbp_HM250_Ks_7'
config.Data.lumiMask = 'Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt'
config.JobType.inputFiles = ['Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt','HeavyIonRPRcd_pPb2016_HM250_offline.db']
config.JobType.pyCfgParams = ['noprint','ntrkMin=250','reaction=Pbp','lumifile=Cert_285952-286496_HI8TeV_PromptReco_Pbp_Collisions16_JSON_NoL1T.txt']
config.Data.inputDataset = '/PAHighMultiplicity7/davidlw-RecoSkim2016_Pbp_V0Cascade_v1-97be9aa52ea60cba5455e64649c12464/USER'
config.Data.runRange = '285952-286496'
#submit(config)
