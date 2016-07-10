$NetBSD$

--- include/VBox/vmm/vmm.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/vmm.h
@@ -148,7 +148,7 @@ typedef FNVMMR0CALLRING3NOTIFICATION *PF
  * @param   pVCpu   The cross context virtual CPU structure of the calling EMT.
  * @param   pvUser  The user argument.
  */
-typedef DECLCALLBACK(VBOXSTRICTRC) FNVMMEMTRENDEZVOUS(PVM pVM, PVMCPU pVCpu, void *pvUser);
+typedef DECLCALLBACK(VBOXSTRICTRC) FNVMMEMTRENDEZVOUS(vbox_PVM pVM, PVMCPU pVCpu, void *pvUser);
 /** Pointer to a rendezvous callback function. */
 typedef FNVMMEMTRENDEZVOUS *PFNVMMEMTRENDEZVOUS;
 
@@ -262,16 +262,16 @@ typedef struct VMM2USERMETHODS
 
 
 VMM_INT_DECL(RTRCPTR)       VMMGetStackRC(PVMCPU pVCpu);
-VMMDECL(VMCPUID)            VMMGetCpuId(PVM pVM);
-VMMDECL(PVMCPU)             VMMGetCpu(PVM pVM);
-VMMDECL(PVMCPU)             VMMGetCpu0(PVM pVM);
-VMMDECL(PVMCPU)             VMMGetCpuById(PVM pVM, VMCPUID idCpu);
+VMMDECL(VMCPUID)            VMMGetCpuId(vbox_PVM pVM);
+VMMDECL(PVMCPU)             VMMGetCpu(vbox_PVM pVM);
+VMMDECL(PVMCPU)             VMMGetCpu0(vbox_PVM pVM);
+VMMDECL(PVMCPU)             VMMGetCpuById(vbox_PVM pVM, VMCPUID idCpu);
 VMMR3DECL(PVMCPU)           VMMR3GetCpuByIdU(PUVM pVM, VMCPUID idCpu);
 VMM_INT_DECL(uint32_t)      VMMGetSvnRev(void);
-VMM_INT_DECL(VMMSWITCHER)   VMMGetSwitcher(PVM pVM);
+VMM_INT_DECL(VMMSWITCHER)   VMMGetSwitcher(vbox_PVM pVM);
 VMM_INT_DECL(bool)          VMMIsInRing3Call(PVMCPU pVCpu);
 VMM_INT_DECL(void)          VMMTrashVolatileXMMRegs(void);
-VMM_INT_DECL(int)           VMMPatchHypercall(PVM pVM, void *pvBuf, size_t cbBuf, size_t *pcbWritten);
+VMM_INT_DECL(int)           VMMPatchHypercall(vbox_PVM pVM, void *pvBuf, size_t cbBuf, size_t *pcbWritten);
 VMM_INT_DECL(void)          VMMHypercallsEnable(PVMCPU pVCpu);
 VMM_INT_DECL(void)          VMMHypercallsDisable(PVMCPU pVCpu);
 
@@ -280,37 +280,37 @@ VMM_INT_DECL(void)          VMMHypercall
 /** @defgroup grp_vmm_api_r3    The VMM Host Context Ring 3 API
  * @{
  */
-VMMR3_INT_DECL(int)     VMMR3Init(PVM pVM);
-VMMR3_INT_DECL(int)     VMMR3InitR0(PVM pVM);
+VMMR3_INT_DECL(int)     VMMR3Init(vbox_PVM pVM);
+VMMR3_INT_DECL(int)     VMMR3InitR0(vbox_PVM pVM);
 # ifdef VBOX_WITH_RAW_MODE
-VMMR3_INT_DECL(int)     VMMR3InitRC(PVM pVM);
+VMMR3_INT_DECL(int)     VMMR3InitRC(vbox_PVM pVM);
 # endif
-VMMR3_INT_DECL(int)     VMMR3InitCompleted(PVM pVM, VMINITCOMPLETED enmWhat);
-VMMR3_INT_DECL(int)     VMMR3Term(PVM pVM);
-VMMR3_INT_DECL(void)    VMMR3Relocate(PVM pVM, RTGCINTPTR offDelta);
-VMMR3_INT_DECL(int)     VMMR3UpdateLoggers(PVM pVM);
-VMMR3DECL(const char *) VMMR3GetRZAssertMsg1(PVM pVM);
-VMMR3DECL(const char *) VMMR3GetRZAssertMsg2(PVM pVM);
-VMMR3_INT_DECL(int)     VMMR3SelectSwitcher(PVM pVM, VMMSWITCHER enmSwitcher);
-VMMR3_INT_DECL(RTR0PTR) VMMR3GetHostToGuestSwitcher(PVM pVM, VMMSWITCHER enmSwitcher);
-VMMR3_INT_DECL(int)     VMMR3HmRunGC(PVM pVM, PVMCPU pVCpu);
+VMMR3_INT_DECL(int)     VMMR3InitCompleted(vbox_PVM pVM, VMINITCOMPLETED enmWhat);
+VMMR3_INT_DECL(int)     VMMR3Term(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    VMMR3Relocate(vbox_PVM pVM, RTGCINTPTR offDelta);
+VMMR3_INT_DECL(int)     VMMR3UpdateLoggers(vbox_PVM pVM);
+VMMR3DECL(const char *) VMMR3GetRZAssertMsg1(vbox_PVM pVM);
+VMMR3DECL(const char *) VMMR3GetRZAssertMsg2(vbox_PVM pVM);
+VMMR3_INT_DECL(int)     VMMR3SelectSwitcher(vbox_PVM pVM, VMMSWITCHER enmSwitcher);
+VMMR3_INT_DECL(RTR0PTR) VMMR3GetHostToGuestSwitcher(vbox_PVM pVM, VMMSWITCHER enmSwitcher);
+VMMR3_INT_DECL(int)     VMMR3HmRunGC(vbox_PVM pVM, PVMCPU pVCpu);
 # ifdef VBOX_WITH_RAW_MODE
-VMMR3_INT_DECL(int)     VMMR3RawRunGC(PVM pVM, PVMCPU pVCpu);
-VMMR3DECL(int)          VMMR3ResumeHyper(PVM pVM, PVMCPU pVCpu);
-VMMR3_INT_DECL(int)     VMMR3GetImportRC(PVM pVM, const char *pszSymbol, PRTRCPTR pRCPtrValue);
-VMMR3DECL(int)          VMMR3CallRC(PVM pVM, RTRCPTR RCPtrEntry, unsigned cArgs, ...);
-VMMR3DECL(int)          VMMR3CallRCV(PVM pVM, RTRCPTR RCPtrEntry, unsigned cArgs, va_list args);
+VMMR3_INT_DECL(int)     VMMR3RawRunGC(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR3DECL(int)          VMMR3ResumeHyper(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR3_INT_DECL(int)     VMMR3GetImportRC(vbox_PVM pVM, const char *pszSymbol, PRTRCPTR pRCPtrValue);
+VMMR3DECL(int)          VMMR3CallRC(vbox_PVM pVM, RTRCPTR RCPtrEntry, unsigned cArgs, ...);
+VMMR3DECL(int)          VMMR3CallRCV(vbox_PVM pVM, RTRCPTR RCPtrEntry, unsigned cArgs, va_list args);
 # endif
-VMMR3DECL(int)          VMMR3CallR0(PVM pVM, uint32_t uOperation, uint64_t u64Arg, PSUPVMMR0REQHDR pReqHdr);
-VMMR3DECL(void)         VMMR3FatalDump(PVM pVM, PVMCPU pVCpu, int rcErr);
-VMMR3_INT_DECL(void)    VMMR3YieldSuspend(PVM pVM);
-VMMR3_INT_DECL(void)    VMMR3YieldStop(PVM pVM);
-VMMR3_INT_DECL(void)    VMMR3YieldResume(PVM pVM);
-VMMR3_INT_DECL(void)    VMMR3SendSipi(PVM pVM, VMCPUID idCpu, uint32_t uVector);
-VMMR3_INT_DECL(void)    VMMR3SendInitIpi(PVM pVM, VMCPUID idCpu);
-VMMR3DECL(int)          VMMR3RegisterPatchMemory(PVM pVM, RTGCPTR pPatchMem, unsigned cbPatchMem);
-VMMR3DECL(int)          VMMR3DeregisterPatchMemory(PVM pVM, RTGCPTR pPatchMem, unsigned cbPatchMem);
-VMMR3DECL(int)          VMMR3EmtRendezvous(PVM pVM, uint32_t fFlags, PFNVMMEMTRENDEZVOUS pfnRendezvous, void *pvUser);
+VMMR3DECL(int)          VMMR3CallR0(vbox_PVM pVM, uint32_t uOperation, uint64_t u64Arg, PSUPVMMR0REQHDR pReqHdr);
+VMMR3DECL(void)         VMMR3FatalDump(vbox_PVM pVM, PVMCPU pVCpu, int rcErr);
+VMMR3_INT_DECL(void)    VMMR3YieldSuspend(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    VMMR3YieldStop(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    VMMR3YieldResume(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    VMMR3SendSipi(vbox_PVM pVM, VMCPUID idCpu, uint32_t uVector);
+VMMR3_INT_DECL(void)    VMMR3SendInitIpi(vbox_PVM pVM, VMCPUID idCpu);
+VMMR3DECL(int)          VMMR3RegisterPatchMemory(vbox_PVM pVM, RTGCPTR pPatchMem, unsigned cbPatchMem);
+VMMR3DECL(int)          VMMR3DeregisterPatchMemory(vbox_PVM pVM, RTGCPTR pPatchMem, unsigned cbPatchMem);
+VMMR3DECL(int)          VMMR3EmtRendezvous(vbox_PVM pVM, uint32_t fFlags, PFNVMMEMTRENDEZVOUS pfnRendezvous, void *pvUser);
 VMMR3_INT_DECL(bool)    VMMR3EmtRendezvousSetDisabled(PVMCPU pVCpu, bool fDisabled);
 /** @defgroup grp_VMMR3EmtRendezvous_fFlags     VMMR3EmtRendezvous flags
  *  @{ */
@@ -335,8 +335,8 @@ VMMR3_INT_DECL(bool)    VMMR3EmtRendezvo
 /** The valid flags. */
 #define VMMEMTRENDEZVOUS_FLAGS_VALID_MASK           UINT32_C(0x0000000f)
 /** @} */
-VMMR3_INT_DECL(int)     VMMR3EmtRendezvousFF(PVM pVM, PVMCPU pVCpu);
-VMMR3_INT_DECL(int)     VMMR3ReadR0Stack(PVM pVM, VMCPUID idCpu, RTHCUINTPTR R0Addr, void *pvBuf, size_t cbRead);
+VMMR3_INT_DECL(int)     VMMR3EmtRendezvousFF(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR3_INT_DECL(int)     VMMR3ReadR0Stack(vbox_PVM pVM, VMCPUID idCpu, RTHCUINTPTR R0Addr, void *pvBuf, size_t cbRead);
 /** @} */
 #endif /* IN_RING3 */
 
@@ -509,10 +509,10 @@ typedef struct GCFGMVALUEREQ
 typedef GCFGMVALUEREQ *PGCFGMVALUEREQ;
 
 #if defined(IN_RING0) || defined(DOXYGEN_RUNNING)
-VMMR0DECL(int)       VMMR0EntryInt(PVM pVM, VMMR0OPERATION enmOperation, void *pvArg);
-VMMR0DECL(void)      VMMR0EntryFast(PVM pVM, VMCPUID idCpu, VMMR0OPERATION enmOperation);
-VMMR0DECL(int)       VMMR0EntryEx(PVM pVM, VMCPUID idCpu, VMMR0OPERATION enmOperation, PSUPVMMR0REQHDR pReq, uint64_t u64Arg, PSUPDRVSESSION);
-VMMR0_INT_DECL(int)  VMMR0TermVM(PVM pVM, PGVM pGVM);
+VMMR0DECL(int)       VMMR0EntryInt(vbox_PVM pVM, VMMR0OPERATION enmOperation, void *pvArg);
+VMMR0DECL(void)      VMMR0EntryFast(vbox_PVM pVM, VMCPUID idCpu, VMMR0OPERATION enmOperation);
+VMMR0DECL(int)       VMMR0EntryEx(vbox_PVM pVM, VMCPUID idCpu, VMMR0OPERATION enmOperation, PSUPVMMR0REQHDR pReq, uint64_t u64Arg, PSUPDRVSESSION);
+VMMR0_INT_DECL(int)  VMMR0TermVM(vbox_PVM pVM, PGVM pGVM);
 VMMR0_INT_DECL(bool) VMMR0IsLongJumpArmed(PVMCPU pVCpu);
 VMMR0_INT_DECL(bool) VMMR0IsInRing3LongJump(PVMCPU pVCpu);
 VMMR0_INT_DECL(int)  VMMR0ThreadCtxHookCreateForEmt(PVMCPU pVCpu);
@@ -538,9 +538,9 @@ VMMR0_INT_DECL(bool) VMMR0IsLogFlushDisa
 /** @defgroup grp_vmm_api_rc    The VMM Raw-Mode Context API
  * @{
  */
-VMMRCDECL(int)      VMMRCEntry(PVM pVM, unsigned uOperation, unsigned uArg, ...);
-VMMRCDECL(void)     VMMRCGuestToHost(PVM pVM, int rc);
-VMMRCDECL(void)     VMMRCLogFlushIfFull(PVM pVM);
+VMMRCDECL(int)      VMMRCEntry(vbox_PVM pVM, unsigned uOperation, unsigned uArg, ...);
+VMMRCDECL(void)     VMMRCGuestToHost(vbox_PVM pVM, int rc);
+VMMRCDECL(void)     VMMRCLogFlushIfFull(vbox_PVM pVM);
 /** @} */
 #endif /* IN_RC */
 
@@ -548,8 +548,8 @@ VMMRCDECL(void)     VMMRCLogFlushIfFull(
 /** @defgroup grp_vmm_api_rz    The VMM Raw-Mode and Ring-0 Context API
  * @{
  */
-VMMRZDECL(int)      VMMRZCallRing3(PVM pVM, PVMCPU pVCpu, VMMCALLRING3 enmOperation, uint64_t uArg);
-VMMRZDECL(int)      VMMRZCallRing3NoCpu(PVM pVM, VMMCALLRING3 enmOperation, uint64_t uArg);
+VMMRZDECL(int)      VMMRZCallRing3(vbox_PVM pVM, PVMCPU pVCpu, VMMCALLRING3 enmOperation, uint64_t uArg);
+VMMRZDECL(int)      VMMRZCallRing3NoCpu(vbox_PVM pVM, VMMCALLRING3 enmOperation, uint64_t uArg);
 VMMRZDECL(void)     VMMRZCallRing3Disable(PVMCPU pVCpu);
 VMMRZDECL(void)     VMMRZCallRing3Enable(PVMCPU pVCpu);
 VMMRZDECL(bool)     VMMRZCallRing3IsEnabled(PVMCPU pVCpu);
