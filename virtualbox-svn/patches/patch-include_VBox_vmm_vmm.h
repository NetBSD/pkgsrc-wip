$NetBSD$

--- include/VBox/vmm/vmm.h.orig	2016-07-10 19:42:15.000000000 +0000
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
 
@@ -515,10 +515,10 @@ typedef struct GCFGMVALUEREQ
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
@@ -544,9 +544,9 @@ VMMR0_INT_DECL(bool) VMMR0IsLogFlushDisa
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
 
@@ -554,8 +554,8 @@ VMMRCDECL(void)     VMMRCLogFlushIfFull(
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
