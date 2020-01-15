ALL_COMMONRULES += src_HeavyIonsAnalysis_JetAnalysis_test
src_HeavyIonsAnalysis_JetAnalysis_test_parent := HeavyIonsAnalysis/JetAnalysis
src_HeavyIonsAnalysis_JetAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_JetAnalysis_test,src/HeavyIonsAnalysis/JetAnalysis/test,TEST))
