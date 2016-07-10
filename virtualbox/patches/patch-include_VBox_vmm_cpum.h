$NetBSD$

--- include/VBox/vmm/cpum.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/cpum.h
@@ -1053,8 +1053,8 @@ VMMDECL(void)       CPUMGetGuestCpuId(PV
 VMMDECL(uint64_t)   CPUMGetGuestEFER(PVMCPU pVCpu);
 VMMDECL(VBOXSTRICTRC)   CPUMQueryGuestMsr(PVMCPU pVCpu, uint32_t idMsr, uint64_t *puValue);
 VMMDECL(VBOXSTRICTRC)   CPUMSetGuestMsr(PVMCPU pVCpu, uint32_t idMsr, uint64_t uValue);
-VMMDECL(CPUMCPUVENDOR)  CPUMGetGuestCpuVendor(PVM pVM);
-VMMDECL(CPUMCPUVENDOR)  CPUMGetHostCpuVendor(PVM pVM);
+VMMDECL(CPUMCPUVENDOR)  CPUMGetGuestCpuVendor(vbox_PVM pVM);
+VMMDECL(CPUMCPUVENDOR)  CPUMGetHostCpuVendor(vbox_PVM pVM);
 /** @} */
 
 /** @name Guest Register Setters.
@@ -1092,9 +1092,9 @@ VMMDECL(int)        CPUMSetGuestFS(PVMCP
 VMMDECL(int)        CPUMSetGuestGS(PVMCPU pVCpu, uint16_t gs);
 VMMDECL(int)        CPUMSetGuestSS(PVMCPU pVCpu, uint16_t ss);
 VMMDECL(void)       CPUMSetGuestEFER(PVMCPU pVCpu, uint64_t val);
-VMMDECL(void)       CPUMSetGuestCpuIdFeature(PVM pVM, CPUMCPUIDFEATURE enmFeature);
-VMMDECL(void)       CPUMClearGuestCpuIdFeature(PVM pVM, CPUMCPUIDFEATURE enmFeature);
-VMMDECL(bool)       CPUMGetGuestCpuIdFeature(PVM pVM, CPUMCPUIDFEATURE enmFeature);
+VMMDECL(void)       CPUMSetGuestCpuIdFeature(vbox_PVM pVM, CPUMCPUIDFEATURE enmFeature);
+VMMDECL(void)       CPUMClearGuestCpuIdFeature(vbox_PVM pVM, CPUMCPUIDFEATURE enmFeature);
+VMMDECL(bool)       CPUMGetGuestCpuIdFeature(vbox_PVM pVM, CPUMCPUIDFEATURE enmFeature);
 VMMDECL(void)       CPUMSetGuestCtx(PVMCPU pVCpu, const PCPUMCTX pCtx);
 VMM_INT_DECL(void)  CPUMGuestLazyLoadHiddenCsAndSs(PVMCPU pVCpu);
 VMM_INT_DECL(void)  CPUMGuestLazyLoadHiddenSelectorReg(PVMCPU pVCpu, PCPUMSELREG pSReg);
@@ -1341,9 +1341,9 @@ VMMDECL(void)           CPUMRawSetEFlags
 VMMDECL(void)           CPUMSetChangedFlags(PVMCPU pVCpu, uint32_t fChangedAdd);
 VMMR3DECL(uint32_t)     CPUMR3RemEnter(PVMCPU pVCpu, uint32_t *puCpl);
 VMMR3DECL(void)         CPUMR3RemLeave(PVMCPU pVCpu, bool fNoOutOfSyncSels);
-VMMDECL(bool)           CPUMSupportsXSave(PVM pVM);
-VMMDECL(bool)           CPUMIsHostUsingSysEnter(PVM pVM);
-VMMDECL(bool)           CPUMIsHostUsingSysCall(PVM pVM);
+VMMDECL(bool)           CPUMSupportsXSave(vbox_PVM pVM);
+VMMDECL(bool)           CPUMIsHostUsingSysEnter(vbox_PVM pVM);
+VMMDECL(bool)           CPUMIsHostUsingSysCall(vbox_PVM pVM);
 VMMDECL(bool)           CPUMIsGuestFPUStateActive(PVMCPU pVCpu);
 VMMDECL(bool)           CPUMIsGuestDebugStateActive(PVMCPU pVCpu);
 VMMDECL(bool)           CPUMIsGuestDebugStateActivePending(PVMCPU pVCpu);
@@ -1354,7 +1354,7 @@ VMMDECL(uint32_t)       CPUMGetGuestCPL(
 VMMDECL(CPUMMODE)       CPUMGetGuestMode(PVMCPU pVCpu);
 VMMDECL(uint32_t)       CPUMGetGuestCodeBits(PVMCPU pVCpu);
 VMMDECL(DISCPUMODE)     CPUMGetGuestDisMode(PVMCPU pVCpu);
-VMMDECL(uint64_t)       CPUMGetGuestScalableBusFrequency(PVM pVM);
+VMMDECL(uint64_t)       CPUMGetGuestScalableBusFrequency(vbox_PVM pVM);
 
 /** @name Typical scalable bus frequency values.
  * @{ */
@@ -1376,19 +1376,19 @@ VMMDECL(uint64_t)       CPUMGetGuestScal
  * @{
  */
 
-VMMR3DECL(int)          CPUMR3Init(PVM pVM);
-VMMR3DECL(int)          CPUMR3InitCompleted(PVM pVM);
-VMMR3DECL(void)         CPUMR3LogCpuIds(PVM pVM);
-VMMR3DECL(void)         CPUMR3Relocate(PVM pVM);
-VMMR3DECL(int)          CPUMR3Term(PVM pVM);
-VMMR3DECL(void)         CPUMR3Reset(PVM pVM);
-VMMR3DECL(void)         CPUMR3ResetCpu(PVM pVM, PVMCPU pVCpu);
-VMMDECL(bool)           CPUMR3IsStateRestorePending(PVM pVM);
-VMMR3DECL(void)         CPUMR3SetHWVirtEx(PVM pVM, bool fHWVirtExEnabled);
-VMMR3DECL(int)          CPUMR3SetCR4Feature(PVM pVM, RTHCUINTREG fOr, RTHCUINTREG fAnd);
+VMMR3DECL(int)          CPUMR3Init(vbox_PVM pVM);
+VMMR3DECL(int)          CPUMR3InitCompleted(vbox_PVM pVM);
+VMMR3DECL(void)         CPUMR3LogCpuIds(vbox_PVM pVM);
+VMMR3DECL(void)         CPUMR3Relocate(vbox_PVM pVM);
+VMMR3DECL(int)          CPUMR3Term(vbox_PVM pVM);
+VMMR3DECL(void)         CPUMR3Reset(vbox_PVM pVM);
+VMMR3DECL(void)         CPUMR3ResetCpu(vbox_PVM pVM, PVMCPU pVCpu);
+VMMDECL(bool)           CPUMR3IsStateRestorePending(vbox_PVM pVM);
+VMMR3DECL(void)         CPUMR3SetHWVirtEx(vbox_PVM pVM, bool fHWVirtExEnabled);
+VMMR3DECL(int)          CPUMR3SetCR4Feature(vbox_PVM pVM, RTHCUINTREG fOr, RTHCUINTREG fAnd);
 
-VMMR3DECL(int)              CPUMR3CpuIdInsert(PVM pVM, PCPUMCPUIDLEAF pNewLeaf);
-VMMR3DECL(int)              CPUMR3CpuIdGetLeaf(PVM pVM, PCPUMCPUIDLEAF pLeaf, uint32_t uLeaf, uint32_t uSubLeaf);
+VMMR3DECL(int)              CPUMR3CpuIdInsert(vbox_PVM pVM, PCPUMCPUIDLEAF pNewLeaf);
+VMMR3DECL(int)              CPUMR3CpuIdGetLeaf(vbox_PVM pVM, PCPUMCPUIDLEAF pLeaf, uint32_t uLeaf, uint32_t uSubLeaf);
 VMMR3DECL(CPUMMICROARCH)    CPUMR3CpuIdDetermineMicroarchEx(CPUMCPUVENDOR enmVendor, uint8_t bFamily,
                                                             uint8_t bModel, uint8_t bStepping);
 VMMR3DECL(const char *)     CPUMR3MicroarchName(CPUMMICROARCH enmMicroarch);
@@ -1398,18 +1398,18 @@ VMMR3DECL(const char *)     CPUMR3CpuIdU
 VMMR3DECL(CPUMCPUVENDOR)    CPUMR3CpuIdDetectVendorEx(uint32_t uEAX, uint32_t uEBX, uint32_t uECX, uint32_t uEDX);
 VMMR3DECL(const char *)     CPUMR3CpuVendorName(CPUMCPUVENDOR enmVendor);
 
-VMMR3DECL(int)              CPUMR3MsrRangesInsert(PVM pVM, PCCPUMMSRRANGE pNewRange);
+VMMR3DECL(int)              CPUMR3MsrRangesInsert(vbox_PVM pVM, PCCPUMMSRRANGE pNewRange);
 
 # if defined(VBOX_WITH_RAW_MODE) || defined(DOXYGEN_RUNNING)
 /** @name APIs for the CPUID raw-mode patch (legacy).
  * @{ */
-VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmDefRCPtr(PVM pVM);
-VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmStdMax(PVM pVM);
-VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmExtMax(PVM pVM);
-VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmCentaurMax(PVM pVM);
-VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmStdRCPtr(PVM pVM);
-VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmExtRCPtr(PVM pVM);
-VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmCentaurRCPtr(PVM pVM);
+VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmDefRCPtr(vbox_PVM pVM);
+VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmStdMax(vbox_PVM pVM);
+VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmExtMax(vbox_PVM pVM);
+VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmCentaurMax(vbox_PVM pVM);
+VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmStdRCPtr(vbox_PVM pVM);
+VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmExtRCPtr(vbox_PVM pVM);
+VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmCentaurRCPtr(vbox_PVM pVM);
 /** @} */
 # endif
 
@@ -1461,11 +1461,11 @@ VMMDECL(void)           CPUMRCRecheckRaw
  */
 VMMR0_INT_DECL(int)     CPUMR0ModuleInit(void);
 VMMR0_INT_DECL(int)     CPUMR0ModuleTerm(void);
-VMMR0_INT_DECL(int)     CPUMR0InitVM(PVM pVM);
-VMMR0_INT_DECL(int)     CPUMR0Trap07Handler(PVM pVM, PVMCPU pVCpu, PCPUMCTX pCtx);
-VMMR0_INT_DECL(int)     CPUMR0LoadGuestFPU(PVM pVM, PVMCPU pVCpu, PCPUMCTX pCtx);
-VMMR0_INT_DECL(int)     CPUMR0SaveGuestFPU(PVM pVM, PVMCPU pVCpu, PCPUMCTX pCtx);
-VMMR0_INT_DECL(int)     CPUMR0SaveHostDebugState(PVM pVM, PVMCPU pVCpu);
+VMMR0_INT_DECL(int)     CPUMR0InitVM(vbox_PVM pVM);
+VMMR0_INT_DECL(int)     CPUMR0Trap07Handler(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTX pCtx);
+VMMR0_INT_DECL(int)     CPUMR0LoadGuestFPU(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTX pCtx);
+VMMR0_INT_DECL(int)     CPUMR0SaveGuestFPU(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTX pCtx);
+VMMR0_INT_DECL(int)     CPUMR0SaveHostDebugState(vbox_PVM pVM, PVMCPU pVCpu);
 VMMR0_INT_DECL(bool)    CPUMR0DebugStateMaybeSaveGuestAndRestoreHost(PVMCPU pVCpu, bool fDr6);
 VMMR0_INT_DECL(bool)    CPUMR0DebugStateMaybeSaveGuest(PVMCPU pVCpu, bool fDr6);
 
@@ -1483,4 +1483,3 @@ RT_C_DECLS_END
 
 
 #endif
-
