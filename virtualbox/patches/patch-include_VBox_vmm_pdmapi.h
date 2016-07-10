$NetBSD$

--- include/VBox/vmm/pdmapi.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/pdmapi.h
@@ -42,21 +42,21 @@ RT_C_DECLS_BEGIN
  */
 
 VMMDECL(int)            PDMGetInterrupt(PVMCPU pVCpu, uint8_t *pu8Interrupt);
-VMMDECL(int)            PDMIsaSetIrq(PVM pVM, uint8_t u8Irq, uint8_t u8Level, uint32_t uTagSrc);
-VMM_INT_DECL(bool)      PDMHasIoApic(PVM pVM);
-VMM_INT_DECL(int)       PDMIoApicSetIrq(PVM pVM, uint8_t u8Irq, uint8_t u8Level, uint32_t uTagSrc);
-VMM_INT_DECL(int)       PDMIoApicSendMsi(PVM pVM, RTGCPHYS GCAddr, uint32_t uValue, uint32_t uTagSrc);
-VMM_INT_DECL(bool)      PDMHasApic(PVM pVM);
-VMM_INT_DECL(int)       PDMApicHasPendingIrq(PVM pVM, bool *pfPending);
+VMMDECL(int)            PDMIsaSetIrq(vbox_PVM pVM, uint8_t u8Irq, uint8_t u8Level, uint32_t uTagSrc);
+VMM_INT_DECL(bool)      PDMHasIoApic(vbox_PVM pVM);
+VMM_INT_DECL(int)       PDMIoApicSetIrq(vbox_PVM pVM, uint8_t u8Irq, uint8_t u8Level, uint32_t uTagSrc);
+VMM_INT_DECL(int)       PDMIoApicSendMsi(vbox_PVM pVM, RTGCPHYS GCAddr, uint32_t uValue, uint32_t uTagSrc);
+VMM_INT_DECL(bool)      PDMHasApic(vbox_PVM pVM);
+VMM_INT_DECL(int)       PDMApicHasPendingIrq(vbox_PVM pVM, bool *pfPending);
 VMMDECL(int)            PDMApicSetBase(PVMCPU pVCpu, uint64_t u64Base);
 VMMDECL(int)            PDMApicGetBase(PVMCPU pVCpu, uint64_t *pu64Base);
 VMMDECL(int)            PDMApicSetTPR(PVMCPU pVCpu, uint8_t u8TPR);
 VMMDECL(int)            PDMApicGetTPR(PVMCPU pVCpu, uint8_t *pu8TPR, bool *pfPending, uint8_t *pu8PendingIrq);
-VMM_INT_DECL(int)       PDMApicWriteMSR(PVM pVM, VMCPUID iCpu, uint32_t u32Reg, uint64_t u64Value);
-VMM_INT_DECL(int)       PDMApicReadMSR(PVM pVM, VMCPUID iCpu, uint32_t u32Reg, uint64_t *pu64Value);
-VMM_INT_DECL(int)       PDMApicGetTimerFreq(PVM pVM, uint64_t *pu64Value);
-VMM_INT_DECL(int)       PDMVmmDevHeapR3ToGCPhys(PVM pVM, RTR3PTR pv, RTGCPHYS *pGCPhys);
-VMM_INT_DECL(bool)      PDMVmmDevHeapIsEnabled(PVM pVM);
+VMM_INT_DECL(int)       PDMApicWriteMSR(vbox_PVM pVM, VMCPUID iCpu, uint32_t u32Reg, uint64_t u64Value);
+VMM_INT_DECL(int)       PDMApicReadMSR(vbox_PVM pVM, VMCPUID iCpu, uint32_t u32Reg, uint64_t *pu64Value);
+VMM_INT_DECL(int)       PDMApicGetTimerFreq(vbox_PVM pVM, uint64_t *pu64Value);
+VMM_INT_DECL(int)       PDMVmmDevHeapR3ToGCPhys(vbox_PVM pVM, RTR3PTR pv, RTGCPHYS *pGCPhys);
+VMM_INT_DECL(bool)      PDMVmmDevHeapIsEnabled(vbox_PVM pVM);
 
 
 /** @defgroup grp_pdm_r3    The PDM Host Context Ring-3 API
@@ -65,16 +65,16 @@ VMM_INT_DECL(bool)      PDMVmmDevHeapIsE
 
 VMMR3_INT_DECL(int)     PDMR3InitUVM(PUVM pUVM);
 VMMR3_INT_DECL(int)     PDMR3LdrLoadVMMR0U(PUVM pUVM);
-VMMR3_INT_DECL(int)     PDMR3Init(PVM pVM);
-VMMR3DECL(void)         PDMR3PowerOn(PVM pVM);
+VMMR3_INT_DECL(int)     PDMR3Init(vbox_PVM pVM);
+VMMR3DECL(void)         PDMR3PowerOn(vbox_PVM pVM);
 VMMR3_INT_DECL(void)    PDMR3ResetCpu(PVMCPU pVCpu);
-VMMR3_INT_DECL(void)    PDMR3Reset(PVM pVM);
-VMMR3_INT_DECL(void)    PDMR3MemSetup(PVM pVM, bool fAtReset);
-VMMR3_INT_DECL(void)    PDMR3Suspend(PVM pVM);
-VMMR3_INT_DECL(void)    PDMR3Resume(PVM pVM);
-VMMR3DECL(void)         PDMR3PowerOff(PVM pVM);
-VMMR3_INT_DECL(void)    PDMR3Relocate(PVM pVM, RTGCINTPTR offDelta);
-VMMR3_INT_DECL(int)     PDMR3Term(PVM pVM);
+VMMR3_INT_DECL(void)    PDMR3Reset(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    PDMR3MemSetup(vbox_PVM pVM, bool fAtReset);
+VMMR3_INT_DECL(void)    PDMR3Suspend(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    PDMR3Resume(vbox_PVM pVM);
+VMMR3DECL(void)         PDMR3PowerOff(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    PDMR3Relocate(vbox_PVM pVM, RTGCINTPTR offDelta);
+VMMR3_INT_DECL(int)     PDMR3Term(vbox_PVM pVM);
 VMMR3_INT_DECL(void)    PDMR3TermUVM(PUVM pUVM);
 
 /** PDM loader context indicator.  */
@@ -108,28 +108,28 @@ typedef enum  PDMLDRCTX
  * @param   enmCtx          The context the module is loaded into.
  * @param   pvArg           User argument.
  */
-typedef DECLCALLBACK(int) FNPDMR3ENUM(PVM pVM, const char *pszFilename, const char *pszName,
+typedef DECLCALLBACK(int) FNPDMR3ENUM(vbox_PVM pVM, const char *pszFilename, const char *pszName,
                                       RTUINTPTR ImageBase, size_t cbImage, PDMLDRCTX enmCtx, void *pvArg);
 /** Pointer to a FNPDMR3ENUM() function. */
 typedef FNPDMR3ENUM *PFNPDMR3ENUM;
-VMMR3DECL(int)          PDMR3LdrEnumModules(PVM pVM, PFNPDMR3ENUM pfnCallback, void *pvArg);
+VMMR3DECL(int)          PDMR3LdrEnumModules(vbox_PVM pVM, PFNPDMR3ENUM pfnCallback, void *pvArg);
 VMMR3_INT_DECL(void)    PDMR3LdrRelocateU(PUVM pUVM, RTGCINTPTR offDelta);
-VMMR3_INT_DECL(int)     PDMR3LdrGetSymbolR3(PVM pVM, const char *pszModule, const char *pszSymbol, void **ppvValue);
-VMMR3DECL(int)          PDMR3LdrGetSymbolR0(PVM pVM, const char *pszModule, const char *pszSymbol, PRTR0PTR ppvValue);
-VMMR3DECL(int)          PDMR3LdrGetSymbolR0Lazy(PVM pVM, const char *pszModule, const char *pszSearchPath, const char *pszSymbol, PRTR0PTR ppvValue);
-VMMR3DECL(int)          PDMR3LdrLoadRC(PVM pVM, const char *pszFilename, const char *pszName);
-VMMR3DECL(int)          PDMR3LdrGetSymbolRC(PVM pVM, const char *pszModule, const char *pszSymbol, PRTRCPTR pRCPtrValue);
-VMMR3DECL(int)          PDMR3LdrGetSymbolRCLazy(PVM pVM, const char *pszModule, const char *pszSearchPath, const char *pszSymbol,
+VMMR3_INT_DECL(int)     PDMR3LdrGetSymbolR3(vbox_PVM pVM, const char *pszModule, const char *pszSymbol, void **ppvValue);
+VMMR3DECL(int)          PDMR3LdrGetSymbolR0(vbox_PVM pVM, const char *pszModule, const char *pszSymbol, PRTR0PTR ppvValue);
+VMMR3DECL(int)          PDMR3LdrGetSymbolR0Lazy(vbox_PVM pVM, const char *pszModule, const char *pszSearchPath, const char *pszSymbol, PRTR0PTR ppvValue);
+VMMR3DECL(int)          PDMR3LdrLoadRC(vbox_PVM pVM, const char *pszFilename, const char *pszName);
+VMMR3DECL(int)          PDMR3LdrGetSymbolRC(vbox_PVM pVM, const char *pszModule, const char *pszSymbol, PRTRCPTR pRCPtrValue);
+VMMR3DECL(int)          PDMR3LdrGetSymbolRCLazy(vbox_PVM pVM, const char *pszModule, const char *pszSearchPath, const char *pszSymbol,
                                                 PRTRCPTR pRCPtrValue);
-VMMR3_INT_DECL(int)     PDMR3LdrQueryRCModFromPC(PVM pVM, RTRCPTR uPC,
+VMMR3_INT_DECL(int)     PDMR3LdrQueryRCModFromPC(vbox_PVM pVM, RTRCPTR uPC,
                                                  char *pszModName,  size_t cchModName,  PRTRCPTR pMod,
                                                  char *pszNearSym1, size_t cchNearSym1, PRTRCPTR pNearSym1,
                                                  char *pszNearSym2, size_t cchNearSym2, PRTRCPTR pNearSym2);
-VMMR3_INT_DECL(int)     PDMR3LdrQueryR0ModFromPC(PVM pVM, RTR0PTR uPC,
+VMMR3_INT_DECL(int)     PDMR3LdrQueryR0ModFromPC(vbox_PVM pVM, RTR0PTR uPC,
                                                  char *pszModName,  size_t cchModName,  PRTR0PTR pMod,
                                                  char *pszNearSym1, size_t cchNearSym1, PRTR0PTR pNearSym1,
                                                  char *pszNearSym2, size_t cchNearSym2, PRTR0PTR pNearSym2);
-VMMR3_INT_DECL(int)     PDMR3LdrGetInterfaceSymbols(PVM pVM, void *pvInterface, size_t cbInterface,
+VMMR3_INT_DECL(int)     PDMR3LdrGetInterfaceSymbols(vbox_PVM pVM, void *pvInterface, size_t cbInterface,
                                                     const char *pszModule, const char *pszSearchPath,
                                                     const char *pszSymPrefix, const char *pszSymList,
                                                     bool fRing0OrRC);
@@ -142,7 +142,7 @@ VMMR3DECL(int)          PDMR3QueryDriver
 VMMR3DECL(int)          PDMR3DeviceAttach(PUVM pUVM, const char *pszDevice, unsigned iInstance, unsigned iLun, uint32_t fFlags,
                                           PPDMIBASE *ppBase);
 VMMR3DECL(int)          PDMR3DeviceDetach(PUVM pUVM, const char *pszDevice, unsigned iInstance, unsigned iLun, uint32_t fFlags);
-VMMR3_INT_DECL(PPDMCRITSECT) PDMR3DevGetCritSect(PVM pVM, PPDMDEVINS pDevIns);
+VMMR3_INT_DECL(PPDMCRITSECT) PDMR3DevGetCritSect(vbox_PVM pVM, PPDMDEVINS pDevIns);
 VMMR3DECL(int)          PDMR3DriverAttach(PUVM pUVM, const char *pszDevice, unsigned iDevIns, unsigned iLun, uint32_t fFlags,
                                           PPPDMIBASE ppBase);
 VMMR3DECL(int)          PDMR3DriverDetach(PUVM pUVM, const char *pszDevice, unsigned iDevIns, unsigned iLun,
@@ -150,15 +150,15 @@ VMMR3DECL(int)          PDMR3DriverDetac
 VMMR3DECL(int)          PDMR3DriverReattach(PUVM pVM, const char *pszDevice, unsigned iDevIns, unsigned iLun,
                                             const char *pszDriver, unsigned iOccurance, uint32_t fFlags, PCFGMNODE pCfg,
                                             PPPDMIBASE ppBase);
-VMMR3DECL(void)         PDMR3DmaRun(PVM pVM);
-VMMR3_INT_DECL(int)     PDMR3LockCall(PVM pVM);
-VMMR3_INT_DECL(int)     PDMR3VmmDevHeapRegister(PVM pVM, RTGCPHYS GCPhys, RTR3PTR pvHeap, unsigned cbSize);
-VMMR3_INT_DECL(int)     PDMR3VmmDevHeapUnregister(PVM pVM, RTGCPHYS GCPhys);
-VMMR3_INT_DECL(int)     PDMR3VmmDevHeapAlloc(PVM pVM, size_t cbSize, RTR3PTR *ppv);
-VMMR3_INT_DECL(int)     PDMR3VmmDevHeapFree(PVM pVM, RTR3PTR pv);
-VMMR3_INT_DECL(int)     PDMR3TracingConfig(PVM pVM, const char *pszName, size_t cchName, bool fEnable, bool fApply);
-VMMR3_INT_DECL(bool)    PDMR3TracingAreAll(PVM pVM, bool fEnabled);
-VMMR3_INT_DECL(int)     PDMR3TracingQueryConfig(PVM pVM, char *pszConfig, size_t cbConfig);
+VMMR3DECL(void)         PDMR3DmaRun(vbox_PVM pVM);
+VMMR3_INT_DECL(int)     PDMR3LockCall(vbox_PVM pVM);
+VMMR3_INT_DECL(int)     PDMR3VmmDevHeapRegister(vbox_PVM pVM, RTGCPHYS GCPhys, RTR3PTR pvHeap, unsigned cbSize);
+VMMR3_INT_DECL(int)     PDMR3VmmDevHeapUnregister(vbox_PVM pVM, RTGCPHYS GCPhys);
+VMMR3_INT_DECL(int)     PDMR3VmmDevHeapAlloc(vbox_PVM pVM, size_t cbSize, RTR3PTR *ppv);
+VMMR3_INT_DECL(int)     PDMR3VmmDevHeapFree(vbox_PVM pVM, RTR3PTR pv);
+VMMR3_INT_DECL(int)     PDMR3TracingConfig(vbox_PVM pVM, const char *pszName, size_t cchName, bool fEnable, bool fApply);
+VMMR3_INT_DECL(bool)    PDMR3TracingAreAll(vbox_PVM pVM, bool fEnabled);
+VMMR3_INT_DECL(int)     PDMR3TracingQueryConfig(vbox_PVM pVM, char *pszConfig, size_t cbConfig);
 /** @} */
 
 
@@ -195,7 +195,7 @@ typedef struct PDMDRIVERCALLREQHANDLERRE
  * request buffer. */
 typedef PDMDRIVERCALLREQHANDLERREQ *PPDMDRIVERCALLREQHANDLERREQ;
 
-VMMR0_INT_DECL(int) PDMR0DriverCallReqHandler(PVM pVM, PPDMDRIVERCALLREQHANDLERREQ pReq);
+VMMR0_INT_DECL(int) PDMR0DriverCallReqHandler(vbox_PVM pVM, PPDMDRIVERCALLREQHANDLERREQ pReq);
 
 /**
  * Request buffer for PDMR0DeviceCallReqHandler / VMMR0_DO_PDM_DEVICE_CALL_REQ_HANDLER.
@@ -220,7 +220,7 @@ typedef struct PDMDEVICECALLREQHANDLERRE
  * VMMR0_DO_PDM_DEVICE_CALL_REQ_HANDLER request buffer. */
 typedef PDMDEVICECALLREQHANDLERREQ *PPDMDEVICECALLREQHANDLERREQ;
 
-VMMR0_INT_DECL(int) PDMR0DeviceCallReqHandler(PVM pVM, PPDMDEVICECALLREQHANDLERREQ pReq);
+VMMR0_INT_DECL(int) PDMR0DeviceCallReqHandler(vbox_PVM pVM, PPDMDEVICECALLREQHANDLERREQ pReq);
 
 /** @} */
 
