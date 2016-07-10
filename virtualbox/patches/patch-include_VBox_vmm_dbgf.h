$NetBSD$

--- include/VBox/vmm/dbgf.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/dbgf.h
@@ -46,8 +46,8 @@ RT_C_DECLS_BEGIN
 /** @defgroup grp_dbgf_rz  The RZ DBGF API
  * @{
  */
-VMMRZ_INT_DECL(int) DBGFRZTrap01Handler(PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, RTGCUINTREG uDr6, bool fAltStepping);
-VMMRZ_INT_DECL(int) DBGFRZTrap03Handler(PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame);
+VMMRZ_INT_DECL(int) DBGFRZTrap01Handler(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, RTGCUINTREG uDr6, bool fAltStepping);
+VMMRZ_INT_DECL(int) DBGFRZTrap03Handler(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame);
 /** @} */
 #endif
 
@@ -281,18 +281,18 @@ typedef const DBGFEVENT *PCDBGFEVENT;
 #  define DBGFSTOP(pVM)  VINF_SUCCESS
 # endif
 
-VMMR3_INT_DECL(int)     DBGFR3Init(PVM pVM);
-VMMR3_INT_DECL(int)     DBGFR3Term(PVM pVM);
-VMMR3_INT_DECL(void)    DBGFR3PowerOff(PVM pVM);
-VMMR3_INT_DECL(void)    DBGFR3Relocate(PVM pVM, RTGCINTPTR offDelta);
-VMMR3_INT_DECL(int)     DBGFR3VMMForcedAction(PVM pVM);
-VMMR3DECL(int)          DBGFR3Event(PVM pVM, DBGFEVENTTYPE enmEvent);
-VMMR3DECL(int)          DBGFR3EventSrc(PVM pVM, DBGFEVENTTYPE enmEvent, const char *pszFile, unsigned uLine,
+VMMR3_INT_DECL(int)     DBGFR3Init(vbox_PVM pVM);
+VMMR3_INT_DECL(int)     DBGFR3Term(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    DBGFR3PowerOff(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    DBGFR3Relocate(vbox_PVM pVM, RTGCINTPTR offDelta);
+VMMR3_INT_DECL(int)     DBGFR3VMMForcedAction(vbox_PVM pVM);
+VMMR3DECL(int)          DBGFR3Event(vbox_PVM pVM, DBGFEVENTTYPE enmEvent);
+VMMR3DECL(int)          DBGFR3EventSrc(vbox_PVM pVM, DBGFEVENTTYPE enmEvent, const char *pszFile, unsigned uLine,
                                        const char *pszFunction, const char *pszFormat, ...) RT_IPRT_FORMAT_ATTR_MAYBE_NULL(6, 7);
-VMMR3DECL(int)          DBGFR3EventSrcV(PVM pVM, DBGFEVENTTYPE enmEvent, const char *pszFile, unsigned uLine,
+VMMR3DECL(int)          DBGFR3EventSrcV(vbox_PVM pVM, DBGFEVENTTYPE enmEvent, const char *pszFile, unsigned uLine,
                                         const char *pszFunction, const char *pszFormat, va_list args) RT_IPRT_FORMAT_ATTR_MAYBE_NULL(6, 0);
-VMMR3_INT_DECL(int)     DBGFR3EventAssertion(PVM pVM, DBGFEVENTTYPE enmEvent, const char *pszMsg1, const char *pszMsg2);
-VMMR3_INT_DECL(int)     DBGFR3EventBreakpoint(PVM pVM, DBGFEVENTTYPE enmEvent);
+VMMR3_INT_DECL(int)     DBGFR3EventAssertion(vbox_PVM pVM, DBGFEVENTTYPE enmEvent, const char *pszMsg1, const char *pszMsg2);
+VMMR3_INT_DECL(int)     DBGFR3EventBreakpoint(vbox_PVM pVM, DBGFEVENTTYPE enmEvent);
 VMMR3_INT_DECL(int)     DBGFR3PrgStep(PVMCPU pVCpu);
 
 VMMR3DECL(int)          DBGFR3Attach(PUVM pUVM);
@@ -412,15 +412,15 @@ typedef FNDBGFBPENUM *PFNDBGFBPENUM;
 VMMR3DECL(int)              DBGFR3BpEnum(PUVM pUVM, PFNDBGFBPENUM pfnCallback, void *pvUser);
 #endif /* IN_RING3 */
 
-VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR7(PVM pVM);
-VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR0(PVM pVM);
-VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR1(PVM pVM);
-VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR2(PVM pVM);
-VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR3(PVM pVM);
-VMM_INT_DECL(bool)          DBGFBpIsHwArmed(PVM pVM);
-VMM_INT_DECL(bool)          DBGFBpIsHwIoArmed(PVM pVM);
+VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR7(vbox_PVM pVM);
+VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR0(vbox_PVM pVM);
+VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR1(vbox_PVM pVM);
+VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR2(vbox_PVM pVM);
+VMM_INT_DECL(RTGCUINTREG)   DBGFBpGetDR3(vbox_PVM pVM);
+VMM_INT_DECL(bool)          DBGFBpIsHwArmed(vbox_PVM pVM);
+VMM_INT_DECL(bool)          DBGFBpIsHwIoArmed(vbox_PVM pVM);
 VMM_INT_DECL(bool)          DBGFIsStepping(PVMCPU pVCpu);
-VMM_INT_DECL(VBOXSTRICTRC)  DBGFBpCheckIo(PVM pVM, PVMCPU pVCpu, PCPUMCTX pCtx, RTIOPORT uIoPort, uint8_t cbValue);
+VMM_INT_DECL(VBOXSTRICTRC)  DBGFBpCheckIo(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTX pCtx, RTIOPORT uIoPort, uint8_t cbValue);
 
 
 #ifdef IN_RING3 /* The CPU mode API only works in ring-3. */
@@ -498,7 +498,7 @@ typedef FNDBGFHANDLERDRV  *PFNDBGFHANDLE
  * @param   pHlp        Callback functions for doing output.
  * @param   pszArgs     Argument string. Optional and specific to the handler.
  */
-typedef DECLCALLBACK(void) FNDBGFHANDLERINT(PVM pVM, PCDBGFINFOHLP pHlp, const char *pszArgs);
+typedef DECLCALLBACK(void) FNDBGFHANDLERINT(vbox_PVM pVM, PCDBGFINFOHLP pHlp, const char *pszArgs);
 /** Pointer to a FNDBGFHANDLERINT function. */
 typedef FNDBGFHANDLERINT  *PFNDBGFHANDLERINT;
 
@@ -520,20 +520,20 @@ typedef FNDBGFHANDLEREXT  *PFNDBGFHANDLE
 #define DBGFINFO_FLAGS_RUN_ON_EMT       RT_BIT(0)
 /** @} */
 
-VMMR3_INT_DECL(int) DBGFR3InfoRegisterDevice(PVM pVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLERDEV pfnHandler, PPDMDEVINS pDevIns);
-VMMR3_INT_DECL(int) DBGFR3InfoRegisterDriver(PVM pVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLERDRV pfnHandler, PPDMDRVINS pDrvIns);
-VMMR3_INT_DECL(int) DBGFR3InfoRegisterInternal(PVM pVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLERINT pfnHandler);
-VMMR3_INT_DECL(int) DBGFR3InfoRegisterInternalEx(PVM pVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLERINT pfnHandler, uint32_t fFlags);
+VMMR3_INT_DECL(int) DBGFR3InfoRegisterDevice(vbox_PVM pVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLERDEV pfnHandler, PPDMDEVINS pDevIns);
+VMMR3_INT_DECL(int) DBGFR3InfoRegisterDriver(vbox_PVM pVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLERDRV pfnHandler, PPDMDRVINS pDrvIns);
+VMMR3_INT_DECL(int) DBGFR3InfoRegisterInternal(vbox_PVM pVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLERINT pfnHandler);
+VMMR3_INT_DECL(int) DBGFR3InfoRegisterInternalEx(vbox_PVM pVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLERINT pfnHandler, uint32_t fFlags);
 VMMR3DECL(int)      DBGFR3InfoRegisterExternal(PUVM pUVM, const char *pszName, const char *pszDesc, PFNDBGFHANDLEREXT pfnHandler, void *pvUser);
-VMMR3_INT_DECL(int) DBGFR3InfoDeregisterDevice(PVM pVM, PPDMDEVINS pDevIns, const char *pszName);
-VMMR3_INT_DECL(int) DBGFR3InfoDeregisterDriver(PVM pVM, PPDMDRVINS pDrvIns, const char *pszName);
-VMMR3_INT_DECL(int) DBGFR3InfoDeregisterInternal(PVM pVM, const char *pszName);
+VMMR3_INT_DECL(int) DBGFR3InfoDeregisterDevice(vbox_PVM pVM, PPDMDEVINS pDevIns, const char *pszName);
+VMMR3_INT_DECL(int) DBGFR3InfoDeregisterDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns, const char *pszName);
+VMMR3_INT_DECL(int) DBGFR3InfoDeregisterInternal(vbox_PVM pVM, const char *pszName);
 VMMR3DECL(int)      DBGFR3InfoDeregisterExternal(PUVM pUVM, const char *pszName);
 VMMR3DECL(int)      DBGFR3Info(PUVM pUVM, const char *pszName, const char *pszArgs, PCDBGFINFOHLP pHlp);
 VMMR3DECL(int)      DBGFR3InfoEx(PUVM pUVM, VMCPUID idCpu, const char *pszName, const char *pszArgs, PCDBGFINFOHLP pHlp);
 VMMR3DECL(int)      DBGFR3InfoLogRel(PUVM pUVM, const char *pszName, const char *pszArgs);
 VMMR3DECL(int)      DBGFR3InfoStdErr(PUVM pUVM, const char *pszName, const char *pszArgs);
-VMMR3_INT_DECL(int) DBGFR3InfoMulti(PVM pVM, const char *pszIncludePat, const char *pszExcludePat,
+VMMR3_INT_DECL(int) DBGFR3InfoMulti(vbox_PVM pVM, const char *pszIncludePat, const char *pszExcludePat,
                                     const char *pszSepFmt, PCDBGFINFOHLP pHlp);
 
 /** @def DBGFR3_INFO_LOG
@@ -1486,8 +1486,8 @@ VMMR3DECL(int) DBGFR3RegCpuSetBatch( PUV
 
 VMMR3DECL(const char *) DBGFR3RegCpuName(PUVM pUVM, DBGFREG enmReg, DBGFREGVALTYPE enmType);
 
-VMMR3_INT_DECL(int) DBGFR3RegRegisterCpu(PVM pVM, PVMCPU pVCpu, PCDBGFREGDESC paRegisters, bool fGuestRegs);
-VMMR3_INT_DECL(int) DBGFR3RegRegisterDevice(PVM pVM, PCDBGFREGDESC paRegisters, PPDMDEVINS pDevIns,
+VMMR3_INT_DECL(int) DBGFR3RegRegisterCpu(vbox_PVM pVM, PVMCPU pVCpu, PCDBGFREGDESC paRegisters, bool fGuestRegs);
+VMMR3_INT_DECL(int) DBGFR3RegRegisterDevice(vbox_PVM pVM, PCDBGFREGDESC paRegisters, PPDMDEVINS pDevIns,
                                             const char *pszPrefix, uint32_t iInstance);
 
 /**
@@ -1794,4 +1794,3 @@ VMMR3DECL(void) DBGFR3PlugInUnloadAll(PU
 RT_C_DECLS_END
 
 #endif
-
