$NetBSD$

--- include/VBox/vmm/pdmapi.h.orig	2016-07-10 19:42:15.000000000 +0000
+++ include/VBox/vmm/pdmapi.h
@@ -127,28 +127,28 @@ typedef enum  PDMLDRCTX
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
@@ -161,7 +161,7 @@ VMMR3DECL(int)          PDMR3QueryDriver
 VMMR3DECL(int)          PDMR3DeviceAttach(PUVM pUVM, const char *pszDevice, unsigned iInstance, unsigned iLun, uint32_t fFlags,
                                           PPDMIBASE *ppBase);
 VMMR3DECL(int)          PDMR3DeviceDetach(PUVM pUVM, const char *pszDevice, unsigned iInstance, unsigned iLun, uint32_t fFlags);
-VMMR3_INT_DECL(PPDMCRITSECT) PDMR3DevGetCritSect(PVM pVM, PPDMDEVINS pDevIns);
+VMMR3_INT_DECL(PPDMCRITSECT) PDMR3DevGetCritSect(vbox_PVM pVM, PPDMDEVINS pDevIns);
 VMMR3DECL(int)          PDMR3DriverAttach(PUVM pUVM, const char *pszDevice, unsigned iDevIns, unsigned iLun, uint32_t fFlags,
                                           PPPDMIBASE ppBase);
 VMMR3DECL(int)          PDMR3DriverDetach(PUVM pUVM, const char *pszDevice, unsigned iDevIns, unsigned iLun,
@@ -214,7 +214,7 @@ typedef struct PDMDRIVERCALLREQHANDLERRE
  * request buffer. */
 typedef PDMDRIVERCALLREQHANDLERREQ *PPDMDRIVERCALLREQHANDLERREQ;
 
-VMMR0_INT_DECL(int) PDMR0DriverCallReqHandler(PVM pVM, PPDMDRIVERCALLREQHANDLERREQ pReq);
+VMMR0_INT_DECL(int) PDMR0DriverCallReqHandler(vbox_PVM pVM, PPDMDRIVERCALLREQHANDLERREQ pReq);
 
 /**
  * Request buffer for PDMR0DeviceCallReqHandler / VMMR0_DO_PDM_DEVICE_CALL_REQ_HANDLER.
@@ -239,7 +239,7 @@ typedef struct PDMDEVICECALLREQHANDLERRE
  * VMMR0_DO_PDM_DEVICE_CALL_REQ_HANDLER request buffer. */
 typedef PDMDEVICECALLREQHANDLERREQ *PPDMDEVICECALLREQHANDLERREQ;
 
-VMMR0_INT_DECL(int) PDMR0DeviceCallReqHandler(PVM pVM, PPDMDEVICECALLREQHANDLERREQ pReq);
+VMMR0_INT_DECL(int) PDMR0DeviceCallReqHandler(vbox_PVM pVM, PPDMDEVICECALLREQHANDLERREQ pReq);
 
 /** @} */
 
