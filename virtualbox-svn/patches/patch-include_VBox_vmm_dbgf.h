$NetBSD$

--- include/VBox/vmm/dbgf.h.orig	2016-07-10 19:42:15.000000000 +0000
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
 
@@ -923,7 +923,7 @@ typedef FNDBGFHANDLERDRV  *PFNDBGFHANDLE
  * @param   pHlp        Callback functions for doing output.
  * @param   pszArgs     Argument string. Optional and specific to the handler.
  */
-typedef DECLCALLBACK(void) FNDBGFHANDLERINT(PVM pVM, PCDBGFINFOHLP pHlp, const char *pszArgs);
+typedef DECLCALLBACK(void) FNDBGFHANDLERINT(vbox_PVM pVM, PCDBGFINFOHLP pHlp, const char *pszArgs);
 /** Pointer to a FNDBGFHANDLERINT function. */
 typedef FNDBGFHANDLERINT  *PFNDBGFHANDLERINT;
 
@@ -1940,8 +1940,8 @@ VMMR3DECL(int) DBGFR3RegCpuSetBatch( PUV
 
 VMMR3DECL(const char *) DBGFR3RegCpuName(PUVM pUVM, DBGFREG enmReg, DBGFREGVALTYPE enmType);
 
-VMMR3_INT_DECL(int) DBGFR3RegRegisterCpu(PVM pVM, PVMCPU pVCpu, PCDBGFREGDESC paRegisters, bool fGuestRegs);
-VMMR3_INT_DECL(int) DBGFR3RegRegisterDevice(PVM pVM, PCDBGFREGDESC paRegisters, PPDMDEVINS pDevIns,
+VMMR3_INT_DECL(int) DBGFR3RegRegisterCpu(vbox_PVM pVM, PVMCPU pVCpu, PCDBGFREGDESC paRegisters, bool fGuestRegs);
+VMMR3_INT_DECL(int) DBGFR3RegRegisterDevice(vbox_PVM pVM, PCDBGFREGDESC paRegisters, PPDMDEVINS pDevIns,
                                             const char *pszPrefix, uint32_t iInstance);
 
 /**
@@ -2494,4 +2494,3 @@ VMMR3DECL(int)  DBGFR3TypeValDumpEx(PUVM
 RT_C_DECLS_END
 
 #endif
-
