$NetBSD$

--- include/VBox/vmm/gvmm.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/gvmm.h
@@ -158,27 +158,27 @@ GVMMR0DECL(void)    GVMMR0Term(void);
 GVMMR0DECL(int)     GVMMR0SetConfig(PSUPDRVSESSION pSession, const char *pszName, uint64_t u64Value);
 GVMMR0DECL(int)     GVMMR0QueryConfig(PSUPDRVSESSION pSession, const char *pszName, uint64_t *pu64Value);
 
-GVMMR0DECL(int)     GVMMR0CreateVM(PSUPDRVSESSION pSession, uint32_t cCpus, PVM *ppVM);
-GVMMR0DECL(int)     GVMMR0InitVM(PVM pVM);
-GVMMR0DECL(void)    GVMMR0DoneInitVM(PVM pVM);
-GVMMR0DECL(bool)    GVMMR0DoingTermVM(PVM pVM, PGVM pGVM);
-GVMMR0DECL(int)     GVMMR0DestroyVM(PVM pVM);
-GVMMR0DECL(int)     GVMMR0RegisterVCpu(PVM pVM, VMCPUID idCpu);
+GVMMR0DECL(int)     GVMMR0CreateVM(PSUPDRVSESSION pSession, uint32_t cCpus, vbox_PVM *ppVM);
+GVMMR0DECL(int)     GVMMR0InitVM(vbox_PVM pVM);
+GVMMR0DECL(void)    GVMMR0DoneInitVM(vbox_PVM pVM);
+GVMMR0DECL(bool)    GVMMR0DoingTermVM(vbox_PVM pVM, PGVM pGVM);
+GVMMR0DECL(int)     GVMMR0DestroyVM(vbox_PVM pVM);
+GVMMR0DECL(int)     GVMMR0RegisterVCpu(vbox_PVM pVM, VMCPUID idCpu);
 GVMMR0DECL(PGVM)    GVMMR0ByHandle(uint32_t hGVM);
-GVMMR0DECL(int)     GVMMR0ByVM(PVM pVM, PGVM *ppGVM);
-GVMMR0DECL(int)     GVMMR0ByVMAndEMT(PVM pVM, VMCPUID idCpu, PGVM *ppGVM);
-GVMMR0DECL(PVM)     GVMMR0GetVMByHandle(uint32_t hGVM);
-GVMMR0DECL(PVM)     GVMMR0GetVMByEMT(RTNATIVETHREAD hEMT);
-GVMMR0DECL(int)     GVMMR0SchedHalt(PVM pVM, VMCPUID idCpu, uint64_t u64ExpireGipTime);
-GVMMR0DECL(int)     GVMMR0SchedWakeUp(PVM pVM, VMCPUID idCpu);
-GVMMR0DECL(int)     GVMMR0SchedWakeUpEx(PVM pVM, VMCPUID idCpu, bool fTakeUsedLock);
-GVMMR0DECL(int)     GVMMR0SchedPoke(PVM pVM, VMCPUID idCpu);
-GVMMR0DECL(int)     GVMMR0SchedPokeEx(PVM pVM, VMCPUID idCpu, bool fTakeUsedLock);
-GVMMR0DECL(int)     GVMMR0SchedWakeUpAndPokeCpus(PVM pVM, PCVMCPUSET pSleepSet, PCVMCPUSET pPokeSet);
-GVMMR0DECL(int)     GVMMR0SchedPoll(PVM pVM, VMCPUID idCpu, bool fYield);
-GVMMR0DECL(void)    GVMMR0SchedUpdatePeriodicPreemptionTimer(PVM pVM, RTCPUID idHostCpu, uint32_t uHz);
-GVMMR0DECL(int)     GVMMR0QueryStatistics(PGVMMSTATS pStats, PSUPDRVSESSION pSession, PVM pVM);
-GVMMR0DECL(int)     GVMMR0ResetStatistics(PCGVMMSTATS pStats, PSUPDRVSESSION pSession, PVM pVM);
+GVMMR0DECL(int)     GVMMR0ByVM(vbox_PVM pVM, PGVM *ppGVM);
+GVMMR0DECL(int)     GVMMR0ByVMAndEMT(vbox_PVM pVM, VMCPUID idCpu, PGVM *ppGVM);
+GVMMR0DECL(vbox_PVM)     GVMMR0GetVMByHandle(uint32_t hGVM);
+GVMMR0DECL(vbox_PVM)     GVMMR0GetVMByEMT(RTNATIVETHREAD hEMT);
+GVMMR0DECL(int)     GVMMR0SchedHalt(vbox_PVM pVM, VMCPUID idCpu, uint64_t u64ExpireGipTime);
+GVMMR0DECL(int)     GVMMR0SchedWakeUp(vbox_PVM pVM, VMCPUID idCpu);
+GVMMR0DECL(int)     GVMMR0SchedWakeUpEx(vbox_PVM pVM, VMCPUID idCpu, bool fTakeUsedLock);
+GVMMR0DECL(int)     GVMMR0SchedPoke(vbox_PVM pVM, VMCPUID idCpu);
+GVMMR0DECL(int)     GVMMR0SchedPokeEx(vbox_PVM pVM, VMCPUID idCpu, bool fTakeUsedLock);
+GVMMR0DECL(int)     GVMMR0SchedWakeUpAndPokeCpus(vbox_PVM pVM, PCVMCPUSET pSleepSet, PCVMCPUSET pPokeSet);
+GVMMR0DECL(int)     GVMMR0SchedPoll(vbox_PVM pVM, VMCPUID idCpu, bool fYield);
+GVMMR0DECL(void)    GVMMR0SchedUpdatePeriodicPreemptionTimer(vbox_PVM pVM, RTCPUID idHostCpu, uint32_t uHz);
+GVMMR0DECL(int)     GVMMR0QueryStatistics(PGVMMSTATS pStats, PSUPDRVSESSION pSession, vbox_PVM pVM);
+GVMMR0DECL(int)     GVMMR0ResetStatistics(PCGVMMSTATS pStats, PSUPDRVSESSION pSession, vbox_PVM pVM);
 
 
 /**
@@ -219,7 +219,7 @@ typedef struct GVMMSCHEDWAKEUPANDPOKECPU
 /** Pointer to a GVMMR0QueryStatisticsReq / VMMR0_DO_GVMM_QUERY_STATISTICS request buffer. */
 typedef GVMMSCHEDWAKEUPANDPOKECPUSREQ *PGVMMSCHEDWAKEUPANDPOKECPUSREQ;
 
-GVMMR0DECL(int)     GVMMR0SchedWakeUpAndPokeCpusReq(PVM pVM, PGVMMSCHEDWAKEUPANDPOKECPUSREQ pReq);
+GVMMR0DECL(int)     GVMMR0SchedWakeUpAndPokeCpusReq(vbox_PVM pVM, PGVMMSCHEDWAKEUPANDPOKECPUSREQ pReq);
 
 
 /**
@@ -238,7 +238,7 @@ typedef struct GVMMQUERYSTATISTICSSREQ
 /** Pointer to a GVMMR0QueryStatisticsReq / VMMR0_DO_GVMM_QUERY_STATISTICS request buffer. */
 typedef GVMMQUERYSTATISTICSSREQ *PGVMMQUERYSTATISTICSSREQ;
 
-GVMMR0DECL(int)     GVMMR0QueryStatisticsReq(PVM pVM, PGVMMQUERYSTATISTICSSREQ pReq);
+GVMMR0DECL(int)     GVMMR0QueryStatisticsReq(vbox_PVM pVM, PGVMMQUERYSTATISTICSSREQ pReq);
 
 
 /**
@@ -258,7 +258,7 @@ typedef struct GVMMRESETSTATISTICSSREQ
 /** Pointer to a GVMMR0ResetStatisticsReq / VMMR0_DO_GVMM_RESET_STATISTICS request buffer. */
 typedef GVMMRESETSTATISTICSSREQ *PGVMMRESETSTATISTICSSREQ;
 
-GVMMR0DECL(int)     GVMMR0ResetStatisticsReq(PVM pVM, PGVMMRESETSTATISTICSSREQ pReq);
+GVMMR0DECL(int)     GVMMR0ResetStatisticsReq(vbox_PVM pVM, PGVMMRESETSTATISTICSSREQ pReq);
 
 
 /** @} */
@@ -266,4 +266,3 @@ GVMMR0DECL(int)     GVMMR0ResetStatistic
 RT_C_DECLS_END
 
 #endif
-
