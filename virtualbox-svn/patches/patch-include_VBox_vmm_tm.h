$NetBSD$

--- include/VBox/vmm/tm.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/tm.h
@@ -86,14 +86,14 @@ VMMDECL(void)           TMNotifyEndOfExe
 VMM_INT_DECL(void)      TMNotifyStartOfHalt(PVMCPU pVCpu);
 VMM_INT_DECL(void)      TMNotifyEndOfHalt(PVMCPU pVCpu);
 #ifdef IN_RING3
-VMMR3DECL(int)          TMR3NotifySuspend(PVM pVM, PVMCPU pVCpu);
-VMMR3DECL(int)          TMR3NotifyResume(PVM pVM, PVMCPU pVCpu);
+VMMR3DECL(int)          TMR3NotifySuspend(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR3DECL(int)          TMR3NotifyResume(vbox_PVM pVM, PVMCPU pVCpu);
 VMMR3DECL(int)          TMR3SetWarpDrive(PUVM pUVM, uint32_t u32Percent);
 VMMR3DECL(uint32_t)     TMR3GetWarpDrive(PUVM pUVM);
 #endif
-VMM_INT_DECL(uint32_t)  TMCalcHostTimerFrequency(PVM pVM, PVMCPU pVCpu);
+VMM_INT_DECL(uint32_t)  TMCalcHostTimerFrequency(vbox_PVM pVM, PVMCPU pVCpu);
 #ifdef IN_RING3
-VMMR3DECL(int)          TMR3GetCpuLoadTimes(PVM pVM, VMCPUID idCpu, uint64_t *pcNsTotal, uint64_t *pcNsExecuting,
+VMMR3DECL(int)          TMR3GetCpuLoadTimes(vbox_PVM pVM, VMCPUID idCpu, uint64_t *pcNsTotal, uint64_t *pcNsExecuting,
                                             uint64_t *pcNsHalted, uint64_t *pcNsOther);
 #endif
 
@@ -101,31 +101,31 @@ VMMR3DECL(int)          TMR3GetCpuLoadTi
 /** @name Real Clock Methods
  * @{
  */
-VMM_INT_DECL(uint64_t)  TMRealGet(PVM pVM);
-VMM_INT_DECL(uint64_t)  TMRealGetFreq(PVM pVM);
+VMM_INT_DECL(uint64_t)  TMRealGet(vbox_PVM pVM);
+VMM_INT_DECL(uint64_t)  TMRealGetFreq(vbox_PVM pVM);
 /** @} */
 
 
 /** @name Virtual Clock Methods
  * @{
  */
-VMM_INT_DECL(uint64_t)  TMVirtualGet(PVM pVM);
-VMM_INT_DECL(uint64_t)  TMVirtualGetNoCheck(PVM pVM);
-VMM_INT_DECL(uint64_t)  TMVirtualSyncGetLag(PVM pVM);
-VMM_INT_DECL(uint32_t)  TMVirtualSyncGetCatchUpPct(PVM pVM);
-VMM_INT_DECL(uint64_t)  TMVirtualGetFreq(PVM pVM);
-VMM_INT_DECL(uint64_t)  TMVirtualSyncGet(PVM pVM);
-VMM_INT_DECL(uint64_t)  TMVirtualSyncGetNoCheck(PVM pVM);
-VMM_INT_DECL(uint64_t)  TMVirtualSyncGetEx(PVM pVM, bool fCheckTimers);
-VMM_INT_DECL(uint64_t)  TMVirtualSyncGetWithDeadlineNoCheck(PVM pVM, uint64_t *pcNsToDeadline);
-VMMDECL(uint64_t)       TMVirtualSyncGetNsToDeadline(PVM pVM);
-VMM_INT_DECL(uint64_t)  TMVirtualToNano(PVM pVM, uint64_t u64VirtualTicks);
-VMM_INT_DECL(uint64_t)  TMVirtualToMicro(PVM pVM, uint64_t u64VirtualTicks);
-VMM_INT_DECL(uint64_t)  TMVirtualToMilli(PVM pVM, uint64_t u64VirtualTicks);
-VMM_INT_DECL(uint64_t)  TMVirtualFromNano(PVM pVM, uint64_t u64NanoTS);
-VMM_INT_DECL(uint64_t)  TMVirtualFromMicro(PVM pVM, uint64_t u64MicroTS);
-VMM_INT_DECL(uint64_t)  TMVirtualFromMilli(PVM pVM, uint64_t u64MilliTS);
-VMM_INT_DECL(bool)      TMVirtualIsTicking(PVM pVM);
+VMM_INT_DECL(uint64_t)  TMVirtualGet(vbox_PVM pVM);
+VMM_INT_DECL(uint64_t)  TMVirtualGetNoCheck(vbox_PVM pVM);
+VMM_INT_DECL(uint64_t)  TMVirtualSyncGetLag(vbox_PVM pVM);
+VMM_INT_DECL(uint32_t)  TMVirtualSyncGetCatchUpPct(vbox_PVM pVM);
+VMM_INT_DECL(uint64_t)  TMVirtualGetFreq(vbox_PVM pVM);
+VMM_INT_DECL(uint64_t)  TMVirtualSyncGet(vbox_PVM pVM);
+VMM_INT_DECL(uint64_t)  TMVirtualSyncGetNoCheck(vbox_PVM pVM);
+VMM_INT_DECL(uint64_t)  TMVirtualSyncGetEx(vbox_PVM pVM, bool fCheckTimers);
+VMM_INT_DECL(uint64_t)  TMVirtualSyncGetWithDeadlineNoCheck(vbox_PVM pVM, uint64_t *pcNsToDeadline);
+VMMDECL(uint64_t)       TMVirtualSyncGetNsToDeadline(vbox_PVM pVM);
+VMM_INT_DECL(uint64_t)  TMVirtualToNano(vbox_PVM pVM, uint64_t u64VirtualTicks);
+VMM_INT_DECL(uint64_t)  TMVirtualToMicro(vbox_PVM pVM, uint64_t u64VirtualTicks);
+VMM_INT_DECL(uint64_t)  TMVirtualToMilli(vbox_PVM pVM, uint64_t u64VirtualTicks);
+VMM_INT_DECL(uint64_t)  TMVirtualFromNano(vbox_PVM pVM, uint64_t u64NanoTS);
+VMM_INT_DECL(uint64_t)  TMVirtualFromMicro(vbox_PVM pVM, uint64_t u64MicroTS);
+VMM_INT_DECL(uint64_t)  TMVirtualFromMilli(vbox_PVM pVM, uint64_t u64MilliTS);
+VMM_INT_DECL(bool)      TMVirtualIsTicking(vbox_PVM pVM);
 /** @} */
 
 
@@ -134,12 +134,12 @@ VMM_INT_DECL(bool)      TMVirtualIsTicki
  */
 VMMDECL(uint64_t)       TMCpuTickGet(PVMCPU pVCpu);
 VMM_INT_DECL(uint64_t)  TMCpuTickGetNoCheck(PVMCPU pVCpu);
-VMM_INT_DECL(bool)      TMCpuTickCanUseRealTSC(PVM pVM, PVMCPU pVCpu, uint64_t *poffRealTSC, bool *pfParavirtTsc);
-VMM_INT_DECL(uint64_t)  TMCpuTickGetDeadlineAndTscOffset(PVM pVM, PVMCPU pVCpu, uint64_t *poffRealTSC, bool *pfOffsettedTsc, bool *pfParavirtTsc);
-VMM_INT_DECL(int)       TMCpuTickSet(PVM pVM, PVMCPU pVCpu, uint64_t u64Tick);
+VMM_INT_DECL(bool)      TMCpuTickCanUseRealTSC(vbox_PVM pVM, PVMCPU pVCpu, uint64_t *poffRealTSC, bool *pfParavirtTsc);
+VMM_INT_DECL(uint64_t)  TMCpuTickGetDeadlineAndTscOffset(vbox_PVM pVM, PVMCPU pVCpu, uint64_t *poffRealTSC, bool *pfOffsettedTsc, bool *pfParavirtTsc);
+VMM_INT_DECL(int)       TMCpuTickSet(vbox_PVM pVM, PVMCPU pVCpu, uint64_t u64Tick);
 VMM_INT_DECL(int)       TMCpuTickSetLastSeen(PVMCPU pVCpu, uint64_t u64LastSeenTick);
 VMM_INT_DECL(uint64_t)  TMCpuTickGetLastSeen(PVMCPU pVCpu);
-VMMDECL(uint64_t)       TMCpuTicksPerSecond(PVM pVM);
+VMMDECL(uint64_t)       TMCpuTicksPerSecond(vbox_PVM pVM);
 VMM_INT_DECL(bool)      TMCpuTickIsTicking(PVMCPU pVCpu);
 /** @} */
 
@@ -198,7 +198,7 @@ typedef FNTMTIMERSRV *PFNTMTIMERSRV;
  * @param   pTimer          The timer handle.
  * @param   pvUser          User argument specified upon timer creation.
  */
-typedef DECLCALLBACK(void) FNTMTIMERINT(PVM pVM, PTMTIMER pTimer, void *pvUser);
+typedef DECLCALLBACK(void) FNTMTIMERINT(vbox_PVM pVM, PTMTIMER pTimer, void *pvUser);
 /** Pointer to internal timer callback function. */
 typedef FNTMTIMERINT *PFNTMTIMERINT;
 
@@ -239,9 +239,9 @@ VMMDECL(uint64_t)       TMTimerFromNano(
 VMMDECL(uint64_t)       TMTimerFromMicro(PTMTIMER pTimer, uint64_t cMicroSecs);
 VMMDECL(uint64_t)       TMTimerFromMilli(PTMTIMER pTimer, uint64_t cMilliSecs);
 
-VMMDECL(bool)           TMTimerPollBool(PVM pVM, PVMCPU pVCpu);
-VMM_INT_DECL(void)      TMTimerPollVoid(PVM pVM, PVMCPU pVCpu);
-VMM_INT_DECL(uint64_t)  TMTimerPollGIP(PVM pVM, PVMCPU pVCpu, uint64_t *pu64Delta);
+VMMDECL(bool)           TMTimerPollBool(vbox_PVM pVM, PVMCPU pVCpu);
+VMM_INT_DECL(void)      TMTimerPollVoid(vbox_PVM pVM, PVMCPU pVCpu);
+VMM_INT_DECL(uint64_t)  TMTimerPollGIP(vbox_PVM pVM, PVMCPU pVCpu, uint64_t *pu64Delta);
 /** @} */
 
 
@@ -249,31 +249,31 @@ VMM_INT_DECL(uint64_t)  TMTimerPollGIP(P
 /** @defgroup grp_tm_r3     The TM Host Context Ring-3 API
  * @{
  */
-VMM_INT_DECL(int)       TMR3Init(PVM pVM);
-VMM_INT_DECL(int)       TMR3InitFinalize(PVM pVM);
-VMM_INT_DECL(void)      TMR3Relocate(PVM pVM, RTGCINTPTR offDelta);
-VMM_INT_DECL(int)       TMR3Term(PVM pVM);
-VMM_INT_DECL(void)      TMR3Reset(PVM pVM);
-VMM_INT_DECL(int)       TMR3GetImportRC(PVM pVM, const char *pszSymbol, PRTRCPTR pRCPtrValue);
-VMM_INT_DECL(int)       TMR3TimerCreateDevice(PVM pVM, PPDMDEVINS pDevIns, TMCLOCK enmClock, PFNTMTIMERDEV pfnCallback, void *pvUser, uint32_t fFlags, const char *pszDesc, PPTMTIMERR3 ppTimer);
-VMM_INT_DECL(int)       TMR3TimerCreateUsb(PVM pVM, PPDMUSBINS pUsbIns, TMCLOCK enmClock, PFNTMTIMERUSB pfnCallback, void *pvUser, uint32_t fFlags, const char *pszDesc, PPTMTIMERR3 ppTimer);
-VMM_INT_DECL(int)       TMR3TimerCreateDriver(PVM pVM, PPDMDRVINS pDrvIns, TMCLOCK enmClock, PFNTMTIMERDRV pfnCallback, void *pvUser, uint32_t fFlags, const char *pszDesc, PPTMTIMERR3 ppTimer);
-VMMR3DECL(int)          TMR3TimerCreateInternal(PVM pVM, TMCLOCK enmClock, PFNTMTIMERINT pfnCallback, void *pvUser, const char *pszDesc, PPTMTIMERR3 ppTimer);
-VMMR3DECL(PTMTIMERR3)   TMR3TimerCreateExternal(PVM pVM, TMCLOCK enmClock, PFNTMTIMEREXT pfnCallback, void *pvUser, const char *pszDesc);
+VMM_INT_DECL(int)       TMR3Init(vbox_PVM pVM);
+VMM_INT_DECL(int)       TMR3InitFinalize(vbox_PVM pVM);
+VMM_INT_DECL(void)      TMR3Relocate(vbox_PVM pVM, RTGCINTPTR offDelta);
+VMM_INT_DECL(int)       TMR3Term(vbox_PVM pVM);
+VMM_INT_DECL(void)      TMR3Reset(vbox_PVM pVM);
+VMM_INT_DECL(int)       TMR3GetImportRC(vbox_PVM pVM, const char *pszSymbol, PRTRCPTR pRCPtrValue);
+VMM_INT_DECL(int)       TMR3TimerCreateDevice(vbox_PVM pVM, PPDMDEVINS pDevIns, TMCLOCK enmClock, PFNTMTIMERDEV pfnCallback, void *pvUser, uint32_t fFlags, const char *pszDesc, PPTMTIMERR3 ppTimer);
+VMM_INT_DECL(int)       TMR3TimerCreateUsb(vbox_PVM pVM, PPDMUSBINS pUsbIns, TMCLOCK enmClock, PFNTMTIMERUSB pfnCallback, void *pvUser, uint32_t fFlags, const char *pszDesc, PPTMTIMERR3 ppTimer);
+VMM_INT_DECL(int)       TMR3TimerCreateDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns, TMCLOCK enmClock, PFNTMTIMERDRV pfnCallback, void *pvUser, uint32_t fFlags, const char *pszDesc, PPTMTIMERR3 ppTimer);
+VMMR3DECL(int)          TMR3TimerCreateInternal(vbox_PVM pVM, TMCLOCK enmClock, PFNTMTIMERINT pfnCallback, void *pvUser, const char *pszDesc, PPTMTIMERR3 ppTimer);
+VMMR3DECL(PTMTIMERR3)   TMR3TimerCreateExternal(vbox_PVM pVM, TMCLOCK enmClock, PFNTMTIMEREXT pfnCallback, void *pvUser, const char *pszDesc);
 VMMR3DECL(int)          TMR3TimerDestroy(PTMTIMER pTimer);
-VMM_INT_DECL(int)       TMR3TimerDestroyDevice(PVM pVM, PPDMDEVINS pDevIns);
-VMM_INT_DECL(int)       TMR3TimerDestroyUsb(PVM pVM, PPDMUSBINS pUsbIns);
-VMM_INT_DECL(int)       TMR3TimerDestroyDriver(PVM pVM, PPDMDRVINS pDrvIns);
+VMM_INT_DECL(int)       TMR3TimerDestroyDevice(vbox_PVM pVM, PPDMDEVINS pDevIns);
+VMM_INT_DECL(int)       TMR3TimerDestroyUsb(vbox_PVM pVM, PPDMUSBINS pUsbIns);
+VMM_INT_DECL(int)       TMR3TimerDestroyDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns);
 VMMR3DECL(int)          TMR3TimerSave(PTMTIMERR3 pTimer, PSSMHANDLE pSSM);
 VMMR3DECL(int)          TMR3TimerLoad(PTMTIMERR3 pTimer, PSSMHANDLE pSSM);
 VMMR3DECL(int)          TMR3TimerSetCritSect(PTMTIMERR3 pTimer, PPDMCRITSECT pCritSect);
-VMMR3DECL(void)         TMR3TimerQueuesDo(PVM pVM);
-VMMR3_INT_DECL(void)    TMR3VirtualSyncFF(PVM pVM, PVMCPU pVCpu);
-VMMR3_INT_DECL(PRTTIMESPEC) TMR3UtcNow(PVM pVM, PRTTIMESPEC pTime);
-
-VMMR3_INT_DECL(int)     TMR3CpuTickParavirtEnable(PVM pVM);
-VMMR3_INT_DECL(int)     TMR3CpuTickParavirtDisable(PVM pVM);
-VMMR3_INT_DECL(bool)    TMR3CpuTickIsFixedRateMonotonic(PVM pVM, bool fWithParavirtEnabled);
+VMMR3DECL(void)         TMR3TimerQueuesDo(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    TMR3VirtualSyncFF(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR3_INT_DECL(PRTTIMESPEC) TMR3UtcNow(vbox_PVM pVM, PRTTIMESPEC pTime);
+
+VMMR3_INT_DECL(int)     TMR3CpuTickParavirtEnable(vbox_PVM pVM);
+VMMR3_INT_DECL(int)     TMR3CpuTickParavirtDisable(vbox_PVM pVM);
+VMMR3_INT_DECL(bool)    TMR3CpuTickIsFixedRateMonotonic(vbox_PVM pVM, bool fWithParavirtEnabled);
 /** @} */
 #endif /* IN_RING3 */
 
@@ -283,4 +283,3 @@ VMMR3_INT_DECL(bool)    TMR3CpuTickIsFix
 RT_C_DECLS_END
 
 #endif
-
