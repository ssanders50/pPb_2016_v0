ALL_COMMONRULES += src_RecoHI_HiEvtPlaneAlgos_test
src_RecoHI_HiEvtPlaneAlgos_test_parent := RecoHI/HiEvtPlaneAlgos
src_RecoHI_HiEvtPlaneAlgos_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoHI_HiEvtPlaneAlgos_test,src/RecoHI/HiEvtPlaneAlgos/test,TEST))
