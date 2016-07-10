$NetBSD$

--- include/VBox/vmm/ssm.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/ssm.h
@@ -818,7 +818,7 @@ typedef FNSSMDRVLOADDONE *PFNSSMDRVLOADD
  * @param   pSSM            SSM operation handle.
  * @thread  Any.
  */
-typedef DECLCALLBACK(int) FNSSMINTLIVEPREP(PVM pVM, PSSMHANDLE pSSM);
+typedef DECLCALLBACK(int) FNSSMINTLIVEPREP(vbox_PVM pVM, PSSMHANDLE pSSM);
 /** Pointer to a FNSSMINTLIVEPREP() function. */
 typedef FNSSMINTLIVEPREP *PFNSSMINTLIVEPREP;
 
@@ -834,7 +834,7 @@ typedef FNSSMINTLIVEPREP *PFNSSMINTLIVEP
  * @param   uPass           The data pass.
  * @thread  Any.
  */
-typedef DECLCALLBACK(int) FNSSMINTLIVEEXEC(PVM pVM, PSSMHANDLE pSSM, uint32_t uPass);
+typedef DECLCALLBACK(int) FNSSMINTLIVEEXEC(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uPass);
 /** Pointer to a FNSSMINTLIVEEXEC() function. */
 typedef FNSSMINTLIVEEXEC *PFNSSMINTLIVEEXEC;
 
@@ -856,7 +856,7 @@ typedef FNSSMINTLIVEEXEC *PFNSSMINTLIVEE
  * @param   uPass           The data pass.
  * @thread  Any.
  */
-typedef DECLCALLBACK(int) FNSSMINTLIVEVOTE(PVM pVM, PSSMHANDLE pSSM, uint32_t uPass);
+typedef DECLCALLBACK(int) FNSSMINTLIVEVOTE(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uPass);
 /** Pointer to a FNSSMINTLIVEVOTE() function. */
 typedef FNSSMINTLIVEVOTE *PFNSSMINTLIVEVOTE;
 
@@ -867,7 +867,7 @@ typedef FNSSMINTLIVEVOTE *PFNSSMINTLIVEV
  * @param   pVM             The cross context VM structure.
  * @param   pSSM            SSM operation handle.
  */
-typedef DECLCALLBACK(int) FNSSMINTSAVEPREP(PVM pVM, PSSMHANDLE pSSM);
+typedef DECLCALLBACK(int) FNSSMINTSAVEPREP(vbox_PVM pVM, PSSMHANDLE pSSM);
 /** Pointer to a FNSSMINTSAVEPREP() function. */
 typedef FNSSMINTSAVEPREP *PFNSSMINTSAVEPREP;
 
@@ -878,7 +878,7 @@ typedef FNSSMINTSAVEPREP *PFNSSMINTSAVEP
  * @param   pVM             The cross context VM structure.
  * @param   pSSM            SSM operation handle.
  */
-typedef DECLCALLBACK(int) FNSSMINTSAVEEXEC(PVM pVM, PSSMHANDLE pSSM);
+typedef DECLCALLBACK(int) FNSSMINTSAVEEXEC(vbox_PVM pVM, PSSMHANDLE pSSM);
 /** Pointer to a FNSSMINTSAVEEXEC() function. */
 typedef FNSSMINTSAVEEXEC *PFNSSMINTSAVEEXEC;
 
@@ -889,7 +889,7 @@ typedef FNSSMINTSAVEEXEC *PFNSSMINTSAVEE
  * @param   pVM             The cross context VM structure.
  * @param   pSSM            SSM operation handle.
  */
-typedef DECLCALLBACK(int) FNSSMINTSAVEDONE(PVM pVM, PSSMHANDLE pSSM);
+typedef DECLCALLBACK(int) FNSSMINTSAVEDONE(vbox_PVM pVM, PSSMHANDLE pSSM);
 /** Pointer to a FNSSMINTSAVEDONE() function. */
 typedef FNSSMINTSAVEDONE *PFNSSMINTSAVEDONE;
 
@@ -900,7 +900,7 @@ typedef FNSSMINTSAVEDONE *PFNSSMINTSAVED
  * @param   pVM             The cross context VM structure.
  * @param   pSSM            SSM operation handle.
  */
-typedef DECLCALLBACK(int) FNSSMINTLOADPREP(PVM pVM, PSSMHANDLE pSSM);
+typedef DECLCALLBACK(int) FNSSMINTLOADPREP(vbox_PVM pVM, PSSMHANDLE pSSM);
 /** Pointer to a FNSSMINTLOADPREP() function. */
 typedef FNSSMINTLOADPREP *PFNSSMINTLOADPREP;
 
@@ -914,7 +914,7 @@ typedef FNSSMINTLOADPREP *PFNSSMINTLOADP
  * @param   uPass           The pass. This is always SSM_PASS_FINAL for units
  *                          that doesn't specify a pfnSaveLive callback.
  */
-typedef DECLCALLBACK(int) FNSSMINTLOADEXEC(PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass);
+typedef DECLCALLBACK(int) FNSSMINTLOADEXEC(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass);
 /** Pointer to a FNSSMINTLOADEXEC() function. */
 typedef FNSSMINTLOADEXEC *PFNSSMINTLOADEXEC;
 
@@ -925,7 +925,7 @@ typedef FNSSMINTLOADEXEC *PFNSSMINTLOADE
  * @param   pVM             The cross context VM structure.
  * @param   pSSM            SSM operation handle.
  */
-typedef DECLCALLBACK(int) FNSSMINTLOADDONE(PVM pVM, PSSMHANDLE pSSM);
+typedef DECLCALLBACK(int) FNSSMINTLOADDONE(vbox_PVM pVM, PSSMHANDLE pSSM);
 /** Pointer to a FNSSMINTLOADDONE() function. */
 typedef FNSSMINTLOADDONE *PFNSSMINTLOADDONE;
 
@@ -1155,25 +1155,25 @@ typedef struct SSMSTRMOPS
 #define SSMSTRMOPS_VERSION      UINT32_C(0x55aa0001)
 
 
-VMMR3_INT_DECL(void)    SSMR3Term(PVM pVM);
+VMMR3_INT_DECL(void)    SSMR3Term(vbox_PVM pVM);
 VMMR3_INT_DECL(int)
-SSMR3RegisterDevice(PVM pVM, PPDMDEVINS pDevIns, const char *pszName, uint32_t uInstance, uint32_t uVersion,
+SSMR3RegisterDevice(vbox_PVM pVM, PPDMDEVINS pDevIns, const char *pszName, uint32_t uInstance, uint32_t uVersion,
                     size_t cbGuess, const char *pszBefore,
                     PFNSSMDEVLIVEPREP pfnLivePrep, PFNSSMDEVLIVEEXEC pfnLiveExec, PFNSSMDEVLIVEVOTE pfnLiveVote,
                     PFNSSMDEVSAVEPREP pfnSavePrep, PFNSSMDEVSAVEEXEC pfnSaveExec, PFNSSMDEVSAVEDONE pfnSaveDone,
                     PFNSSMDEVLOADPREP pfnLoadPrep, PFNSSMDEVLOADEXEC pfnLoadExec, PFNSSMDEVLOADDONE pfnLoadDone);
 VMMR3_INT_DECL(int)
-SSMR3RegisterDriver(PVM pVM, PPDMDRVINS pDrvIns, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
+SSMR3RegisterDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
                     PFNSSMDRVLIVEPREP pfnLivePrep, PFNSSMDRVLIVEEXEC pfnLiveExec, PFNSSMDRVLIVEVOTE pfnLiveVote,
                     PFNSSMDRVSAVEPREP pfnSavePrep, PFNSSMDRVSAVEEXEC pfnSaveExec, PFNSSMDRVSAVEDONE pfnSaveDone,
                     PFNSSMDRVLOADPREP pfnLoadPrep, PFNSSMDRVLOADEXEC pfnLoadExec, PFNSSMDRVLOADDONE pfnLoadDone);
 VMMR3_INT_DECL(int)
-SSMR3RegisterUsb(PVM pVM, PPDMUSBINS pUsbIns, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
+SSMR3RegisterUsb(vbox_PVM pVM, PPDMUSBINS pUsbIns, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
                  PFNSSMUSBLIVEPREP pfnLivePrep, PFNSSMUSBLIVEEXEC pfnLiveExec, PFNSSMUSBLIVEVOTE pfnLiveVote,
                  PFNSSMUSBSAVEPREP pfnSavePrep, PFNSSMUSBSAVEEXEC pfnSaveExec, PFNSSMUSBSAVEDONE pfnSaveDone,
                  PFNSSMUSBLOADPREP pfnLoadPrep, PFNSSMUSBLOADEXEC pfnLoadExec, PFNSSMUSBLOADDONE pfnLoadDone);
 VMMR3DECL(int)
-SSMR3RegisterInternal(PVM pVM, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
+SSMR3RegisterInternal(vbox_PVM pVM, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
                       PFNSSMINTLIVEPREP pfnLivePrep, PFNSSMINTLIVEEXEC pfnLiveExec, PFNSSMINTLIVEVOTE pfnLiveVote,
                       PFNSSMINTSAVEPREP pfnSavePrep, PFNSSMINTSAVEEXEC pfnSaveExec, PFNSSMINTSAVEDONE pfnSaveDone,
                       PFNSSMINTLOADPREP pfnLoadPrep, PFNSSMINTLOADEXEC pfnLoadExec, PFNSSMINTLOADDONE pfnLoadDone);
@@ -1182,21 +1182,21 @@ SSMR3RegisterExternal(PUVM pUVM, const c
                       PFNSSMEXTLIVEPREP pfnLivePrep, PFNSSMEXTLIVEEXEC pfnLiveExec, PFNSSMEXTLIVEVOTE pfnLiveVote,
                       PFNSSMEXTSAVEPREP pfnSavePrep, PFNSSMEXTSAVEEXEC pfnSaveExec, PFNSSMEXTSAVEDONE pfnSaveDone,
                       PFNSSMEXTLOADPREP pfnLoadPrep, PFNSSMEXTLOADEXEC pfnLoadExec, PFNSSMEXTLOADDONE pfnLoadDone, void *pvUser);
-VMMR3DECL(int)          SSMR3RegisterStub(PVM pVM, const char *pszName, uint32_t uInstance);
-VMMR3_INT_DECL(int)     SSMR3DeregisterDevice(PVM pVM, PPDMDEVINS pDevIns, const char *pszName, uint32_t uInstance);
-VMMR3_INT_DECL(int)     SSMR3DeregisterDriver(PVM pVM, PPDMDRVINS pDrvIns, const char *pszName, uint32_t uInstance);
-VMMR3_INT_DECL(int)     SSMR3DeregisterUsb(PVM pVM, PPDMUSBINS pUsbIns, const char *pszName, uint32_t uInstance);
-VMMR3DECL(int)          SSMR3DeregisterInternal(PVM pVM, const char *pszName);
-VMMR3DECL(int)          SSMR3DeregisterExternal(PVM pVM, const char *pszName);
-VMMR3DECL(int)          SSMR3Save(PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser, SSMAFTER enmAfter, PFNVMPROGRESS pfnProgress, void *pvUser);
-VMMR3_INT_DECL(int)     SSMR3LiveSave(PVM pVM, uint32_t cMsMaxDowntime,
+VMMR3DECL(int)          SSMR3RegisterStub(vbox_PVM pVM, const char *pszName, uint32_t uInstance);
+VMMR3_INT_DECL(int)     SSMR3DeregisterDevice(vbox_PVM pVM, PPDMDEVINS pDevIns, const char *pszName, uint32_t uInstance);
+VMMR3_INT_DECL(int)     SSMR3DeregisterDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns, const char *pszName, uint32_t uInstance);
+VMMR3_INT_DECL(int)     SSMR3DeregisterUsb(vbox_PVM pVM, PPDMUSBINS pUsbIns, const char *pszName, uint32_t uInstance);
+VMMR3DECL(int)          SSMR3DeregisterInternal(vbox_PVM pVM, const char *pszName);
+VMMR3DECL(int)          SSMR3DeregisterExternal(vbox_PVM pVM, const char *pszName);
+VMMR3DECL(int)          SSMR3Save(vbox_PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser, SSMAFTER enmAfter, PFNVMPROGRESS pfnProgress, void *pvUser);
+VMMR3_INT_DECL(int)     SSMR3LiveSave(vbox_PVM pVM, uint32_t cMsMaxDowntime,
                                       const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOps,
                                       SSMAFTER enmAfter, PFNVMPROGRESS pfnProgress, void *pvProgressUser,
                                       PSSMHANDLE *ppSSM);
 VMMR3_INT_DECL(int)     SSMR3LiveDoStep1(PSSMHANDLE pSSM);
 VMMR3_INT_DECL(int)     SSMR3LiveDoStep2(PSSMHANDLE pSSM);
 VMMR3_INT_DECL(int)     SSMR3LiveDone(PSSMHANDLE pSSM);
-VMMR3DECL(int)          SSMR3Load(PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
+VMMR3DECL(int)          SSMR3Load(vbox_PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
                                   SSMAFTER enmAfter, PFNVMPROGRESS pfnProgress, void *pvProgressUser);
 VMMR3DECL(int)          SSMR3ValidateFile(const char *pszFilename, bool fChecksumIt);
 VMMR3DECL(int)          SSMR3Open(const char *pszFilename, unsigned fFlags, PSSMHANDLE *ppSSM);
@@ -1299,4 +1299,3 @@ VMMR3DECL(int) SSMR3SetCfgError(PSSMHAND
 RT_C_DECLS_END
 
 #endif
-
