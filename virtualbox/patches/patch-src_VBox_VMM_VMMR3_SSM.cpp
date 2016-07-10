$NetBSD$

--- src/VBox/VMM/VMMR3/SSM.cpp.orig	2016-03-04 19:30:12.000000000 +0000
+++ src/VBox/VMM/VMMR3/SSM.cpp
@@ -456,7 +456,7 @@ typedef struct SSMHANDLE
     SSMSTRM                 Strm;
 
     /** Pointer to the VM. */
-    PVM                     pVM;
+    vbox_PVM                     pVM;
     /** The current operation. */
     SSMSTATE                enmOp;
     /** What to do after save completes. (move the enum) */
@@ -877,12 +877,12 @@ static uint8_t const    g_abZero[_1K] = 
 *   Internal Functions                                                                                                           *
 *********************************************************************************************************************************/
 #ifndef SSM_STANDALONE
-static int                  ssmR3LazyInit(PVM pVM);
-static DECLCALLBACK(int)    ssmR3SelfLiveExec(PVM pVM, PSSMHANDLE pSSM, uint32_t uPass);
-static DECLCALLBACK(int)    ssmR3SelfSaveExec(PVM pVM, PSSMHANDLE pSSM);
-static DECLCALLBACK(int)    ssmR3SelfLoadExec(PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass);
-static DECLCALLBACK(int)    ssmR3LiveControlLoadExec(PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass);
-static int                  ssmR3Register(PVM pVM, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess, const char *pszBefore, PSSMUNIT *ppUnit);
+static int                  ssmR3LazyInit(vbox_PVM pVM);
+static DECLCALLBACK(int)    ssmR3SelfLiveExec(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uPass);
+static DECLCALLBACK(int)    ssmR3SelfSaveExec(vbox_PVM pVM, PSSMHANDLE pSSM);
+static DECLCALLBACK(int)    ssmR3SelfLoadExec(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass);
+static DECLCALLBACK(int)    ssmR3LiveControlLoadExec(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass);
+static int                  ssmR3Register(vbox_PVM pVM, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess, const char *pszBefore, PSSMUNIT *ppUnit);
 static int                  ssmR3LiveControlEmit(PSSMHANDLE pSSM, long double lrdPct, uint32_t uPass);
 #endif
 
@@ -902,7 +902,7 @@ static int                  ssmR3DataRea
  *
  * @param   pVM                 The cross context VM structure.
  */
-VMMR3_INT_DECL(void) SSMR3Term(PVM pVM)
+VMMR3_INT_DECL(void) SSMR3Term(vbox_PVM pVM)
 {
     if (pVM->ssm.s.fInitialized)
     {
@@ -918,7 +918,7 @@ VMMR3_INT_DECL(void) SSMR3Term(PVM pVM)
  * @returns VBox status code.
  * @param   pVM         The cross context VM structure.
  */
-static int ssmR3LazyInit(PVM pVM)
+static int ssmR3LazyInit(vbox_PVM pVM)
 {
     /*
      * Register a saved state unit which we use to put the VirtualBox version,
@@ -958,7 +958,7 @@ static int ssmR3LazyInit(PVM pVM)
  * @param   pSSM            The SSM handle.
  * @param   uPass           The data pass number.
  */
-static DECLCALLBACK(int) ssmR3SelfLiveExec(PVM pVM, PSSMHANDLE pSSM, uint32_t uPass)
+static DECLCALLBACK(int) ssmR3SelfLiveExec(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uPass)
 {
     if (uPass == 0)
     {
@@ -980,7 +980,7 @@ static DECLCALLBACK(int) ssmR3SelfLiveEx
  * @param   pVM             The cross context VM structure.
  * @param   pSSM            The SSM handle.
  */
-static DECLCALLBACK(int) ssmR3SelfSaveExec(PVM pVM, PSSMHANDLE pSSM)
+static DECLCALLBACK(int) ssmR3SelfSaveExec(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     NOREF(pVM);
 
@@ -1012,7 +1012,7 @@ static DECLCALLBACK(int) ssmR3SelfSaveEx
  * @param   uVersion        The version (1).
  * @param   uPass           The pass.
  */
-static DECLCALLBACK(int) ssmR3SelfLoadExec(PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass)
+static DECLCALLBACK(int) ssmR3SelfLoadExec(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass)
 {
     AssertLogRelMsgReturn(uVersion == 1, ("%d\n", uVersion), VERR_SSM_UNSUPPORTED_DATA_UNIT_VERSION);
     NOREF(pVM); NOREF(uPass);
@@ -1076,7 +1076,7 @@ static DECLCALLBACK(int) ssmR3SelfLoadEx
  * @param   uVersion        The version (1).
  * @param   uPass           The pass.
  */
-static DECLCALLBACK(int) ssmR3LiveControlLoadExec(PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass)
+static DECLCALLBACK(int) ssmR3LiveControlLoadExec(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass)
 {
     AssertLogRelMsgReturn(uVersion == 1, ("%d\n", uVersion), VERR_SSM_UNSUPPORTED_DATA_UNIT_VERSION);
     NOREF(uPass);
@@ -1115,7 +1115,7 @@ static DECLCALLBACK(int) ssmR3LiveContro
  * @param   ppUnit          Where to store the inserted unit node.
  *                          Caller must fill in the missing details.
  */
-static int ssmR3Register(PVM pVM, const char *pszName, uint32_t uInstance,
+static int ssmR3Register(vbox_PVM pVM, const char *pszName, uint32_t uInstance,
                          uint32_t uVersion, size_t cbGuess, const char *pszBefore, PSSMUNIT *ppUnit)
 {
     /*
@@ -1235,7 +1235,7 @@ static int ssmR3Register(PVM pVM, const 
  * @param   pfnLoadDone     Done load callback, optional.
  */
 VMMR3_INT_DECL(int)
-SSMR3RegisterDevice(PVM pVM, PPDMDEVINS pDevIns, const char *pszName,
+SSMR3RegisterDevice(vbox_PVM pVM, PPDMDEVINS pDevIns, const char *pszName,
                     uint32_t uInstance, uint32_t uVersion, size_t cbGuess, const char *pszBefore,
                     PFNSSMDEVLIVEPREP pfnLivePrep, PFNSSMDEVLIVEEXEC pfnLiveExec, PFNSSMDEVLIVEVOTE pfnLiveVote,
                     PFNSSMDEVSAVEPREP pfnSavePrep, PFNSSMDEVSAVEEXEC pfnSaveExec, PFNSSMDEVSAVEDONE pfnSaveDone,
@@ -1289,7 +1289,7 @@ SSMR3RegisterDevice(PVM pVM, PPDMDEVINS 
  * @param   pfnLoadDone     Done load callback, optional.
  */
 VMMR3_INT_DECL(int)
-SSMR3RegisterDriver(PVM pVM, PPDMDRVINS pDrvIns, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
+SSMR3RegisterDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
                     PFNSSMDRVLIVEPREP pfnLivePrep, PFNSSMDRVLIVEEXEC pfnLiveExec, PFNSSMDRVLIVEVOTE pfnLiveVote,
                     PFNSSMDRVSAVEPREP pfnSavePrep, PFNSSMDRVSAVEEXEC pfnSaveExec, PFNSSMDRVSAVEDONE pfnSaveDone,
                     PFNSSMDRVLOADPREP pfnLoadPrep, PFNSSMDRVLOADEXEC pfnLoadExec, PFNSSMDRVLOADDONE pfnLoadDone)
@@ -1341,7 +1341,7 @@ SSMR3RegisterDriver(PVM pVM, PPDMDRVINS 
  * @param   pfnLoadDone     Done load callback, optional.
  */
 VMMR3_INT_DECL(int)
-SSMR3RegisterUsb(PVM pVM, PPDMUSBINS pUsbIns, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
+SSMR3RegisterUsb(vbox_PVM pVM, PPDMUSBINS pUsbIns, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
                  PFNSSMUSBLIVEPREP pfnLivePrep, PFNSSMUSBLIVEEXEC pfnLiveExec, PFNSSMUSBLIVEVOTE pfnLiveVote,
                  PFNSSMUSBSAVEPREP pfnSavePrep, PFNSSMUSBSAVEEXEC pfnSaveExec, PFNSSMUSBSAVEDONE pfnSaveDone,
                  PFNSSMUSBLOADPREP pfnLoadPrep, PFNSSMUSBLOADEXEC pfnLoadExec, PFNSSMUSBLOADDONE pfnLoadDone)
@@ -1391,7 +1391,7 @@ SSMR3RegisterUsb(PVM pVM, PPDMUSBINS pUs
  * @param   pfnLoadExec     Execute load callback, optional.
  * @param   pfnLoadDone     Done load callback, optional.
  */
-VMMR3DECL(int) SSMR3RegisterInternal(PVM pVM, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
+VMMR3DECL(int) SSMR3RegisterInternal(vbox_PVM pVM, const char *pszName, uint32_t uInstance, uint32_t uVersion, size_t cbGuess,
     PFNSSMINTLIVEPREP pfnLivePrep, PFNSSMINTLIVEEXEC pfnLiveExec, PFNSSMINTLIVEVOTE pfnLiveVote,
     PFNSSMINTSAVEPREP pfnSavePrep, PFNSSMINTSAVEEXEC pfnSaveExec, PFNSSMINTSAVEDONE pfnSaveDone,
     PFNSSMINTLOADPREP pfnLoadPrep, PFNSSMINTLOADEXEC pfnLoadExec, PFNSSMINTLOADDONE pfnLoadDone)
@@ -1447,7 +1447,7 @@ VMMR3DECL(int) SSMR3RegisterExternal(PUV
     PFNSSMEXTLOADPREP pfnLoadPrep, PFNSSMEXTLOADEXEC pfnLoadExec, PFNSSMEXTLOADDONE pfnLoadDone, void *pvUser)
 {
     UVM_ASSERT_VALID_EXT_RETURN(pUVM, VERR_INVALID_VM_HANDLE);
-    PVM pVM = pUVM->pVM;
+    vbox_PVM pVM = pUVM->pVM;
     VM_ASSERT_VALID_EXT_RETURN(pVM, VERR_INVALID_VM_HANDLE);
 
     PSSMUNIT pUnit;
@@ -1474,7 +1474,7 @@ VMMR3DECL(int) SSMR3RegisterExternal(PUV
  * @callback_method_impl{FNSSMINTLOADEXEC,
  * Stub that skips the whole unit (see SSMR3RegisterStub).}
  */
-static DECLCALLBACK(int) ssmR3LoadExecStub(PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass)
+static DECLCALLBACK(int) ssmR3LoadExecStub(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion, uint32_t uPass)
 {
     NOREF(pVM); NOREF(uVersion); NOREF(uPass);
     return SSMR3SkipToEndOfUnit(pSSM);
@@ -1492,7 +1492,7 @@ static DECLCALLBACK(int) ssmR3LoadExecSt
  * @param   pszName             Data unit name.
  * @param   uInstance           Instance number.
  */
-VMMR3DECL(int) SSMR3RegisterStub(PVM pVM, const char *pszName, uint32_t uInstance)
+VMMR3DECL(int) SSMR3RegisterStub(vbox_PVM pVM, const char *pszName, uint32_t uInstance)
 {
     return SSMR3RegisterInternal(pVM, pszName, uInstance, UINT32_MAX, 0,
                                  NULL, NULL, NULL,
@@ -1514,7 +1514,7 @@ VMMR3DECL(int) SSMR3RegisterStub(PVM pVM
  *                          This must together with the name be unique.
  * @remark  Only for dynamic data units and dynamic unloaded modules.
  */
-VMMR3_INT_DECL(int) SSMR3DeregisterDevice(PVM pVM, PPDMDEVINS pDevIns, const char *pszName, uint32_t uInstance)
+VMMR3_INT_DECL(int) SSMR3DeregisterDevice(vbox_PVM pVM, PPDMDEVINS pDevIns, const char *pszName, uint32_t uInstance)
 {
     /*
      * Validate input.
@@ -1590,7 +1590,7 @@ VMMR3_INT_DECL(int) SSMR3DeregisterDevic
  *                          This must together with the name be unique. Ignored if pszName is NULL.
  * @remark  Only for dynamic data units and dynamic unloaded modules.
  */
-VMMR3_INT_DECL(int) SSMR3DeregisterDriver(PVM pVM, PPDMDRVINS pDrvIns, const char *pszName, uint32_t uInstance)
+VMMR3_INT_DECL(int) SSMR3DeregisterDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns, const char *pszName, uint32_t uInstance)
 {
     /*
      * Validate input.
@@ -1664,7 +1664,7 @@ VMMR3_INT_DECL(int) SSMR3DeregisterDrive
  *                          This must together with the name be unique. Ignored if pszName is NULL.
  * @remark  Only for dynamic data units and dynamic unloaded modules.
  */
-VMMR3_INT_DECL(int) SSMR3DeregisterUsb(PVM pVM, PPDMUSBINS pUsbIns, const char *pszName, uint32_t uInstance)
+VMMR3_INT_DECL(int) SSMR3DeregisterUsb(vbox_PVM pVM, PPDMUSBINS pUsbIns, const char *pszName, uint32_t uInstance)
 {
     /*
      * Validate input.
@@ -1731,7 +1731,7 @@ VMMR3_INT_DECL(int) SSMR3DeregisterUsb(P
  * @param   pszName         Data unit name.
  * @remark  Only for dynamic data units.
  */
-static int ssmR3DeregisterByNameAndType(PVM pVM, const char *pszName, SSMUNITTYPE enmType)
+static int ssmR3DeregisterByNameAndType(vbox_PVM pVM, const char *pszName, SSMUNITTYPE enmType)
 {
     /*
      * Validate input.
@@ -1787,7 +1787,7 @@ static int ssmR3DeregisterByNameAndType(
  * @param   pszName         Data unit name.
  * @remark  Only for dynamic data units.
  */
-VMMR3DECL(int) SSMR3DeregisterInternal(PVM pVM, const char *pszName)
+VMMR3DECL(int) SSMR3DeregisterInternal(vbox_PVM pVM, const char *pszName)
 {
     return ssmR3DeregisterByNameAndType(pVM, pszName, SSMUNITTYPE_INTERNAL);
 }
@@ -1804,7 +1804,7 @@ VMMR3DECL(int) SSMR3DeregisterInternal(P
 VMMR3DECL(int) SSMR3DeregisterExternal(PUVM pUVM, const char *pszName)
 {
     UVM_ASSERT_VALID_EXT_RETURN(pUVM, VERR_INVALID_VM_HANDLE);
-    PVM pVM = pUVM->pVM;
+    vbox_PVM pVM = pUVM->pVM;
     VM_ASSERT_VALID_EXT_RETURN(pVM, VERR_INVALID_VM_HANDLE);
 
     return ssmR3DeregisterByNameAndType(pVM, pszName, SSMUNITTYPE_EXTERNAL);
@@ -3206,7 +3206,7 @@ static void ssmR3ProgressByByte(PSSMHAND
  * @param   pSSM            The saved state handle. (SSMHANDLE::rc may be set.)
  * @param   fCancellable    The new state.
  */
-static void ssmR3SetCancellable(PVM pVM, PSSMHANDLE pSSM, bool fCancellable)
+static void ssmR3SetCancellable(vbox_PVM pVM, PSSMHANDLE pSSM, bool fCancellable)
 {
     RTCritSectEnter(&pVM->ssm.s.CancelCritSect);
     if (fCancellable)
@@ -4508,7 +4508,7 @@ DECLINLINE(void) ssmR3UnitCritSectLeave(
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3SaveDoDoneRun(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3SaveDoDoneRun(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     VM_ASSERT_EMT0(pVM);
 
@@ -4569,7 +4569,7 @@ static int ssmR3SaveDoDoneRun(PVM pVM, P
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3SaveDoClose(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3SaveDoClose(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     VM_ASSERT_EMT0(pVM);
     pVM->ssm.s.uPass = 0;
@@ -4642,7 +4642,7 @@ VMMR3_INT_DECL(int) SSMR3LiveDone(PSSMHA
      * Validate input.
      */
     AssertPtrReturn(pSSM, VERR_INVALID_POINTER);
-    PVM pVM = pSSM->pVM;
+    vbox_PVM pVM = pSSM->pVM;
     VM_ASSERT_VALID_EXT_RETURN(pVM, VERR_INVALID_VM_HANDLE);
     VM_ASSERT_EMT0(pVM);
     AssertMsgReturn(   pSSM->enmAfter == SSMAFTER_DESTROY
@@ -4669,7 +4669,7 @@ VMMR3_INT_DECL(int) SSMR3LiveDone(PSSMHA
  * @param   pSSM                The SSM handle.
  * @param   pcEntries           Where to return the number of directory entries.
  */
-static int ssmR3WriteDirectory(PVM pVM, PSSMHANDLE pSSM, uint32_t *pcEntries)
+static int ssmR3WriteDirectory(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t *pcEntries)
 {
     VM_ASSERT_EMT0(pVM);
 
@@ -4723,7 +4723,7 @@ static int ssmR3WriteDirectory(PVM pVM, 
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3SaveDoFinalization(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3SaveDoFinalization(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     VM_ASSERT_EMT0(pVM);
     Assert(RT_SUCCESS(pSSM->rc));
@@ -4814,7 +4814,7 @@ static void ssmR3ProgressByUnit(PSSMHAND
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3SaveDoExecRun(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3SaveDoExecRun(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     VM_ASSERT_EMT0(pVM);
     AssertRC(pSSM->rc);
@@ -4959,7 +4959,7 @@ static int ssmR3SaveDoExecRun(PVM pVM, P
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3SaveDoPrepRun(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3SaveDoPrepRun(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     VM_ASSERT_EMT0(pVM);
     Assert(RT_SUCCESS(pSSM->rc));
@@ -5027,7 +5027,7 @@ static int ssmR3SaveDoPrepRun(PVM pVM, P
  *
  * @thread  EMT(0)
  */
-static int ssmR3SaveDoCommon(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3SaveDoCommon(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     VM_ASSERT_EMT0(pVM);
 
@@ -5067,7 +5067,7 @@ VMMR3_INT_DECL(int) SSMR3LiveDoStep2(PSS
      * Validate input.
      */
     AssertPtrReturn(pSSM, VERR_INVALID_POINTER);
-    PVM pVM = pSSM->pVM;
+    vbox_PVM pVM = pSSM->pVM;
     VM_ASSERT_VALID_EXT_RETURN(pVM, VERR_INVALID_VM_HANDLE);
     VM_ASSERT_EMT0(pVM);
     AssertMsgReturn(   pSSM->enmAfter == SSMAFTER_DESTROY
@@ -5092,7 +5092,7 @@ VMMR3_INT_DECL(int) SSMR3LiveDoStep2(PSS
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The SSM handle.
  */
-static int ssmR3WriteHeaderAndClearPerUnitData(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3WriteHeaderAndClearPerUnitData(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     /*
      * Write the header.
@@ -5148,7 +5148,7 @@ static int ssmR3WriteHeaderAndClearPerUn
  *                              handle upon successful return.  Free it using
  *                              RTMemFree after closing the stream.
  */
-static int ssmR3SaveDoCreateFile(PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
+static int ssmR3SaveDoCreateFile(vbox_PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
                                  SSMAFTER enmAfter, PFNVMPROGRESS pfnProgress, void *pvProgressUser, PSSMHANDLE *ppSSM)
 {
     PSSMHANDLE pSSM = (PSSMHANDLE)RTMemAllocZ(sizeof(*pSSM));
@@ -5212,7 +5212,7 @@ static int ssmR3SaveDoCreateFile(PVM pVM
  *
  * @thread  EMT
  */
-VMMR3DECL(int) SSMR3Save(PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
+VMMR3DECL(int) SSMR3Save(vbox_PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
                          SSMAFTER enmAfter, PFNVMPROGRESS pfnProgress, void *pvUser)
 {
     LogFlow(("SSMR3Save: pszFilename=%p:{%s} enmAfter=%d pfnProgress=%p pvUser=%p\n", pszFilename, pszFilename, enmAfter, pfnProgress, pvUser));
@@ -5299,7 +5299,7 @@ VMMR3DECL(void) SSMR3HandleReportLivePer
  * @param   pSSM                The saved state handle.
  * @param   uPass               The current pass.
  */
-static int ssmR3LiveDoVoteRun(PVM pVM, PSSMHANDLE pSSM, uint32_t uPass)
+static int ssmR3LiveDoVoteRun(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uPass)
 {
     int rcRet = VINF_SUCCESS;
     AssertRC(pSSM->rc);
@@ -5405,7 +5405,7 @@ static int ssmR3LiveDoVoteRun(PVM pVM, P
  * @param   pSSM                The saved state handle.
  * @param   uPass               The current pass.
  */
-static int ssmR3LiveDoExecRun(PVM pVM, PSSMHANDLE pSSM, uint32_t uPass)
+static int ssmR3LiveDoExecRun(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uPass)
 {
     AssertRC(pSSM->rc);
     pSSM->rc = VINF_SUCCESS;
@@ -5536,7 +5536,7 @@ static int ssmR3LiveDoExecRun(PVM pVM, P
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3DoLiveExecVoteLoop(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3DoLiveExecVoteLoop(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     /*
      * Calc the max saved state size before we should give up because of insane
@@ -5608,7 +5608,7 @@ static int ssmR3DoLiveExecVoteLoop(PVM p
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3DoLivePrepRun(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3DoLivePrepRun(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     /*
      * Do the prepare run.
@@ -5686,7 +5686,7 @@ VMMR3_INT_DECL(int) SSMR3LiveDoStep1(PSS
      * Validate input.
      */
     AssertPtrReturn(pSSM, VERR_INVALID_POINTER);
-    PVM pVM = pSSM->pVM;
+    vbox_PVM pVM = pSSM->pVM;
     VM_ASSERT_VALID_EXT_RETURN(pVM, VERR_INVALID_VM_HANDLE);
     VM_ASSERT_OTHER_THREAD(pVM);
     AssertMsgReturn(   pSSM->enmAfter == SSMAFTER_DESTROY
@@ -5731,7 +5731,7 @@ VMMR3_INT_DECL(int) SSMR3LiveDoStep1(PSS
  *
  * @thread  EMT0
  */
-VMMR3_INT_DECL(int) SSMR3LiveSave(PVM pVM, uint32_t cMsMaxDowntime,
+VMMR3_INT_DECL(int) SSMR3LiveSave(vbox_PVM pVM, uint32_t cMsMaxDowntime,
                                   const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
                                   SSMAFTER enmAfter, PFNVMPROGRESS pfnProgress, void *pvProgressUser,
                                   PSSMHANDLE *ppSSM)
@@ -8011,7 +8011,7 @@ static int ssmR3HeaderAndValidate(PSSMHA
  *                              completely initialized on success.
  * @param   cBuffers            The number of stream buffers.
  */
-static int ssmR3OpenFile(PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvUser,
+static int ssmR3OpenFile(vbox_PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvUser,
                          bool fChecksumIt, bool fChecksumOnRead, uint32_t cBuffers, PSSMHANDLE pSSM)
 {
     /*
@@ -8283,7 +8283,7 @@ static void ssmR3StrmLogUnitContent(PSSM
  * @param   pszName         Data unit name.
  * @param   uInstance       The data unit instance id.
  */
-static PSSMUNIT ssmR3Find(PVM pVM, const char *pszName, uint32_t uInstance)
+static PSSMUNIT ssmR3Find(vbox_PVM pVM, const char *pszName, uint32_t uInstance)
 {
     size_t   cchName = strlen(pszName);
     PSSMUNIT pUnit = pVM->ssm.s.pHead;
@@ -8303,7 +8303,7 @@ static PSSMUNIT ssmR3Find(PVM pVM, const
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3LoadExecV1(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3LoadExecV1(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     int     rc;
     char   *pszName = NULL;
@@ -8566,7 +8566,7 @@ static int ssmR3LoadDirectoryAndFooter(P
  * @param   pVM                 The cross context VM structure.
  * @param   pSSM                The saved state handle.
  */
-static int ssmR3LoadExecV2(PVM pVM, PSSMHANDLE pSSM)
+static int ssmR3LoadExecV2(vbox_PVM pVM, PSSMHANDLE pSSM)
 {
     pSSM->enmOp = SSMSTATE_LOAD_EXEC;
     for (;;)
@@ -8757,7 +8757,7 @@ static int ssmR3LoadExecV2(PVM pVM, PSSM
  *
  * @thread  EMT
  */
-VMMR3DECL(int) SSMR3Load(PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
+VMMR3DECL(int) SSMR3Load(vbox_PVM pVM, const char *pszFilename, PCSSMSTRMOPS pStreamOps, void *pvStreamOpsUser,
                          SSMAFTER enmAfter, PFNVMPROGRESS pfnProgress, void *pvProgressUser)
 {
     LogFlow(("SSMR3Load: pszFilename=%p:{%s} pStreamOps=%p pvStreamOpsUser=%p enmAfter=%d pfnProgress=%p pvProgressUser=%p\n",
@@ -9641,7 +9641,7 @@ VMMR3DECL(const char *) SSMR3HandleHostO
 VMMR3DECL(int) SSMR3Cancel(PUVM pUVM)
 {
     UVM_ASSERT_VALID_EXT_RETURN(pUVM, VERR_INVALID_VM_HANDLE);
-    PVM pVM = pUVM->pVM;
+    vbox_PVM pVM = pUVM->pVM;
     VM_ASSERT_VALID_EXT_RETURN(pVM, VERR_INVALID_VM_HANDLE);
 
     int rc = RTCritSectEnter(&pVM->ssm.s.CancelCritSect);
@@ -9671,4 +9671,3 @@ VMMR3DECL(int) SSMR3Cancel(PUVM pUVM)
     return rc;
 }
 #endif /* !SSM_STANDALONE */
-
