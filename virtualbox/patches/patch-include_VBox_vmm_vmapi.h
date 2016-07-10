$NetBSD$

--- include/VBox/vmm/vmapi.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/vmapi.h
@@ -104,8 +104,8 @@ typedef DECLCALLBACK(void) FNVMATERROR(P
 /** Pointer to a VM error callback. */
 typedef FNVMATERROR *PFNVMATERROR;
 
-VMMDECL(int)    VMSetError(PVM pVM, int rc, RT_SRC_POS_DECL, const char *pszFormat, ...) RT_IPRT_FORMAT_ATTR(6, 7);
-VMMDECL(int)    VMSetErrorV(PVM pVM, int rc, RT_SRC_POS_DECL, const char *pszFormat, va_list args) RT_IPRT_FORMAT_ATTR(6, 7);
+VMMDECL(int)    VMSetError(vbox_PVM pVM, int rc, RT_SRC_POS_DECL, const char *pszFormat, ...) RT_IPRT_FORMAT_ATTR(6, 7);
+VMMDECL(int)    VMSetErrorV(vbox_PVM pVM, int rc, RT_SRC_POS_DECL, const char *pszFormat, va_list args) RT_IPRT_FORMAT_ATTR(6, 7);
 
 /** @def VM_SET_ERROR
  * Macro for setting a simple VM error message.
@@ -155,9 +155,9 @@ typedef DECLCALLBACK(void) FNVMATRUNTIME
 /** Pointer to a VM runtime error callback. */
 typedef FNVMATRUNTIMEERROR *PFNVMATRUNTIMEERROR;
 
-VMMDECL(int) VMSetRuntimeError(PVM pVM, uint32_t fFlags, const char *pszErrorId,
+VMMDECL(int) VMSetRuntimeError(vbox_PVM pVM, uint32_t fFlags, const char *pszErrorId,
                                const char *pszFormat, ...) RT_IPRT_FORMAT_ATTR(4, 5);
-VMMDECL(int) VMSetRuntimeErrorV(PVM pVM, uint32_t fFlags, const char *pszErrorId,
+VMMDECL(int) VMSetRuntimeErrorV(vbox_PVM pVM, uint32_t fFlags, const char *pszErrorId,
                                 const char *pszFormat, va_list args) RT_IPRT_FORMAT_ATTR(4, 0);
 
 /** @name VMSetRuntimeError fFlags
@@ -404,7 +404,7 @@ typedef FNVMPROGRESS *PFNVMPROGRESS;
 VMMR3DECL(int)          VMR3Create(uint32_t cCpus, PCVMM2USERMETHODS pVm2UserCbs,
                                    PFNVMATERROR pfnVMAtError, void *pvUserVM,
                                    PFNCFGMCONSTRUCTOR pfnCFGMConstructor, void *pvUserCFGM,
-                                   PVM *ppVM, PUVM *ppUVM);
+                                   vbox_PVM *ppVM, PUVM *ppUVM);
 VMMR3DECL(int)          VMR3PowerOn(PUVM pUVM);
 VMMR3DECL(int)          VMR3Suspend(PUVM pUVM, VMSUSPENDREASON enmReason);
 VMMR3DECL(VMSUSPENDREASON) VMR3GetSuspendReason(PUVM);
@@ -421,41 +421,41 @@ VMMR3_INT_DECL(int)     VMR3LoadFromStre
 
 VMMR3DECL(int)          VMR3PowerOff(PUVM pUVM);
 VMMR3DECL(int)          VMR3Destroy(PUVM pUVM);
-VMMR3_INT_DECL(void)    VMR3Relocate(PVM pVM, RTGCINTPTR offDelta);
+VMMR3_INT_DECL(void)    VMR3Relocate(vbox_PVM pVM, RTGCINTPTR offDelta);
 
-VMMR3DECL(PVM)          VMR3GetVM(PUVM pUVM);
-VMMR3DECL(PUVM)         VMR3GetUVM(PVM pVM);
+VMMR3DECL(vbox_PVM)          VMR3GetVM(PUVM pUVM);
+VMMR3DECL(PUVM)         VMR3GetUVM(vbox_PVM pVM);
 VMMR3DECL(uint32_t)     VMR3RetainUVM(PUVM pUVM);
 VMMR3DECL(uint32_t)     VMR3ReleaseUVM(PUVM pUVM);
 VMMR3DECL(const char *) VMR3GetName(PUVM pUVM);
 VMMR3DECL(PRTUUID)      VMR3GetUuid(PUVM pUVM, PRTUUID pUuid);
-VMMR3DECL(VMSTATE)      VMR3GetState(PVM pVM);
+VMMR3DECL(VMSTATE)      VMR3GetState(vbox_PVM pVM);
 VMMR3DECL(VMSTATE)      VMR3GetStateU(PUVM pUVM);
 VMMR3DECL(const char *) VMR3GetStateName(VMSTATE enmState);
 VMMR3DECL(int)          VMR3AtStateRegister(PUVM pUVM, PFNVMATSTATE pfnAtState, void *pvUser);
 VMMR3DECL(int)          VMR3AtStateDeregister(PUVM pUVM, PFNVMATSTATE pfnAtState, void *pvUser);
-VMMR3_INT_DECL(bool)    VMR3TeleportedAndNotFullyResumedYet(PVM pVM);
+VMMR3_INT_DECL(bool)    VMR3TeleportedAndNotFullyResumedYet(vbox_PVM pVM);
 VMMR3DECL(int)          VMR3AtErrorRegister(PUVM pUVM, PFNVMATERROR pfnAtError, void *pvUser);
 VMMR3DECL(int)          VMR3AtErrorDeregister(PUVM pUVM, PFNVMATERROR pfnAtError, void *pvUser);
 VMMR3DECL(int)          VMR3SetError(PUVM pUVM, int rc, RT_SRC_POS_DECL, const char *pszFormat, ...) RT_IPRT_FORMAT_ATTR(6, 7);
 VMMR3DECL(int)          VMR3SetErrorV(PUVM pUVM, int rc, RT_SRC_POS_DECL, const char *pszFormat, va_list va) RT_IPRT_FORMAT_ATTR(6, 0);
-VMMR3_INT_DECL(void)    VMR3SetErrorWorker(PVM pVM);
+VMMR3_INT_DECL(void)    VMR3SetErrorWorker(vbox_PVM pVM);
 VMMR3_INT_DECL(uint32_t) VMR3GetErrorCount(PUVM pUVM);
 VMMR3DECL(int)          VMR3AtRuntimeErrorRegister(PUVM pUVM, PFNVMATRUNTIMEERROR pfnAtRuntimeError, void *pvUser);
 VMMR3DECL(int)          VMR3AtRuntimeErrorDeregister(PUVM pUVM, PFNVMATRUNTIMEERROR pfnAtRuntimeError, void *pvUser);
-VMMR3_INT_DECL(int)     VMR3SetRuntimeErrorWorker(PVM pVM);
+VMMR3_INT_DECL(int)     VMR3SetRuntimeErrorWorker(vbox_PVM pVM);
 VMMR3_INT_DECL(uint32_t) VMR3GetRuntimeErrorCount(PUVM pUVM);
 
 VMMR3DECL(int)          VMR3ReqCallU(PUVM pUVM, VMCPUID idDstCpu, PVMREQ *ppReq, RTMSINTERVAL cMillies, uint32_t fFlags, PFNRT pfnFunction, unsigned cArgs, ...);
 VMMR3DECL(int)          VMR3ReqCallVU(PUVM pUVM, VMCPUID idDstCpu, PVMREQ *ppReq, RTMSINTERVAL cMillies, uint32_t fFlags, PFNRT pfnFunction, unsigned cArgs, va_list Args);
-VMMR3_INT_DECL(int)     VMR3ReqCallWait(PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
+VMMR3_INT_DECL(int)     VMR3ReqCallWait(vbox_PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
 VMMR3DECL(int)          VMR3ReqCallWaitU(PUVM pUVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
-VMMR3DECL(int)          VMR3ReqCallNoWait(PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
+VMMR3DECL(int)          VMR3ReqCallNoWait(vbox_PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
 VMMR3DECL(int)          VMR3ReqCallNoWaitU(PUVM pUVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
-VMMR3_INT_DECL(int)     VMR3ReqCallVoidWait(PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
+VMMR3_INT_DECL(int)     VMR3ReqCallVoidWait(vbox_PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
 VMMR3DECL(int)          VMR3ReqCallVoidWaitU(PUVM pUVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
-VMMR3DECL(int)          VMR3ReqCallVoidNoWait(PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
-VMMR3DECL(int)          VMR3ReqPriorityCallWait(PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
+VMMR3DECL(int)          VMR3ReqCallVoidNoWait(vbox_PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
+VMMR3DECL(int)          VMR3ReqPriorityCallWait(vbox_PVM pVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
 VMMR3DECL(int)          VMR3ReqPriorityCallWaitU(PUVM pUVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
 VMMR3DECL(int)          VMR3ReqPriorityCallVoidWaitU(PUVM pUVM, VMCPUID idDstCpu, PFNRT pfnFunction, unsigned cArgs, ...);
 VMMR3DECL(int)          VMR3ReqAlloc(PUVM pUVM, PVMREQ *ppReq, VMREQTYPE enmType, VMCPUID idDstCpu);
@@ -473,16 +473,16 @@ VMMR3_INT_DECL(int)     VMR3ReqProcessU(
 /** @} */
 VMMR3_INT_DECL(void)        VMR3NotifyGlobalFFU(PUVM pUVM, uint32_t fFlags);
 VMMR3_INT_DECL(void)        VMR3NotifyCpuFFU(PUVMCPU pUVMCpu, uint32_t fFlags);
-VMMR3DECL(int)              VMR3NotifyCpuDeviceReady(PVM pVM, VMCPUID idCpu);
-VMMR3_INT_DECL(int)         VMR3WaitHalted(PVM pVM, PVMCPU pVCpu, bool fIgnoreInterrupts);
+VMMR3DECL(int)              VMR3NotifyCpuDeviceReady(vbox_PVM pVM, VMCPUID idCpu);
+VMMR3_INT_DECL(int)         VMR3WaitHalted(vbox_PVM pVM, PVMCPU pVCpu, bool fIgnoreInterrupts);
 VMMR3_INT_DECL(int)         VMR3WaitU(PUVMCPU pUVMCpu);
-VMMR3DECL(int)              VMR3WaitForDeviceReady(PVM pVM, VMCPUID idCpu);
+VMMR3DECL(int)              VMR3WaitForDeviceReady(vbox_PVM pVM, VMCPUID idCpu);
 VMMR3_INT_DECL(int)         VMR3AsyncPdmNotificationWaitU(PUVMCPU pUVCpu);
 VMMR3_INT_DECL(void)        VMR3AsyncPdmNotificationWakeupU(PUVM pUVM);
-VMMR3_INT_DECL(RTCPUID)     VMR3GetVMCPUId(PVM pVM);
-VMMR3_INT_DECL(bool)        VMR3IsLongModeAllowed(PVM pVM);
+VMMR3_INT_DECL(RTCPUID)     VMR3GetVMCPUId(vbox_PVM pVM);
+VMMR3_INT_DECL(bool)        VMR3IsLongModeAllowed(vbox_PVM pVM);
 VMMR3DECL(RTTHREAD)         VMR3GetVMCPUThread(PUVM pUVM);
-VMMR3DECL(RTNATIVETHREAD)   VMR3GetVMCPUNativeThread(PVM pVM);
+VMMR3DECL(RTNATIVETHREAD)   VMR3GetVMCPUNativeThread(vbox_PVM pVM);
 VMMR3DECL(RTNATIVETHREAD)   VMR3GetVMCPUNativeThreadU(PUVM pUVM);
 VMMR3DECL(int)              VMR3GetCpuCoreAndPackageIdFromCpuId(PUVM pUVM, VMCPUID idCpu, uint32_t *pidCpuCore, uint32_t *pidCpuPackage);
 VMMR3DECL(int)              VMR3HotUnplugCpu(PUVM pUVM, VMCPUID idCpu);
@@ -506,4 +506,3 @@ RT_C_DECLS_END
 /** @} */
 
 #endif
-
