$NetBSD$

--- include/VBox/vmm/gmm.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/gmm.h
@@ -399,26 +399,26 @@ GMMR0DECL(int)  GMMR0Init(void);
 GMMR0DECL(void) GMMR0Term(void);
 GMMR0DECL(void) GMMR0InitPerVMData(PGVM pGVM);
 GMMR0DECL(void) GMMR0CleanupVM(PGVM pGVM);
-GMMR0DECL(int)  GMMR0InitialReservation(PVM pVM, VMCPUID idCpu, uint64_t cBasePages, uint32_t cShadowPages, uint32_t cFixedPages,
+GMMR0DECL(int)  GMMR0InitialReservation(vbox_PVM pVM, VMCPUID idCpu, uint64_t cBasePages, uint32_t cShadowPages, uint32_t cFixedPages,
                                         GMMOCPOLICY enmPolicy, GMMPRIORITY enmPriority);
-GMMR0DECL(int)  GMMR0UpdateReservation(PVM pVM, VMCPUID idCpu, uint64_t cBasePages, uint32_t cShadowPages, uint32_t cFixedPages);
-GMMR0DECL(int)  GMMR0AllocateHandyPages(PVM pVM, VMCPUID idCpu, uint32_t cPagesToUpdate, uint32_t cPagesToAlloc, PGMMPAGEDESC paPages);
-GMMR0DECL(int)  GMMR0AllocatePages(PVM pVM, VMCPUID idCpu, uint32_t cPages, PGMMPAGEDESC paPages, GMMACCOUNT enmAccount);
-GMMR0DECL(int)  GMMR0AllocateLargePage(PVM pVM, VMCPUID idCpu, uint32_t cbPage, uint32_t *pIdPage, RTHCPHYS *pHCPhys);
-GMMR0DECL(int)  GMMR0FreePages(PVM pVM, VMCPUID idCpu, uint32_t cPages, PGMMFREEPAGEDESC paPages, GMMACCOUNT enmAccount);
-GMMR0DECL(int)  GMMR0FreeLargePage(PVM pVM, VMCPUID idCpu, uint32_t idPage);
-GMMR0DECL(int)  GMMR0BalloonedPages(PVM pVM, VMCPUID idCpu, GMMBALLOONACTION enmAction, uint32_t cBalloonedPages);
-GMMR0DECL(int)  GMMR0MapUnmapChunk(PVM pVM, uint32_t idChunkMap, uint32_t idChunkUnmap, PRTR3PTR ppvR3);
-GMMR0DECL(int)  GMMR0SeedChunk(PVM pVM, VMCPUID idCpu, RTR3PTR pvR3);
-GMMR0DECL(int)  GMMR0RegisterSharedModule(PVM pVM, VMCPUID idCpu, VBOXOSFAMILY enmGuestOS, char *pszModuleName, char *pszVersion,
+GMMR0DECL(int)  GMMR0UpdateReservation(vbox_PVM pVM, VMCPUID idCpu, uint64_t cBasePages, uint32_t cShadowPages, uint32_t cFixedPages);
+GMMR0DECL(int)  GMMR0AllocateHandyPages(vbox_PVM pVM, VMCPUID idCpu, uint32_t cPagesToUpdate, uint32_t cPagesToAlloc, PGMMPAGEDESC paPages);
+GMMR0DECL(int)  GMMR0AllocatePages(vbox_PVM pVM, VMCPUID idCpu, uint32_t cPages, PGMMPAGEDESC paPages, GMMACCOUNT enmAccount);
+GMMR0DECL(int)  GMMR0AllocateLargePage(vbox_PVM pVM, VMCPUID idCpu, uint32_t cbPage, uint32_t *pIdPage, RTHCPHYS *pHCPhys);
+GMMR0DECL(int)  GMMR0FreePages(vbox_PVM pVM, VMCPUID idCpu, uint32_t cPages, PGMMFREEPAGEDESC paPages, GMMACCOUNT enmAccount);
+GMMR0DECL(int)  GMMR0FreeLargePage(vbox_PVM pVM, VMCPUID idCpu, uint32_t idPage);
+GMMR0DECL(int)  GMMR0BalloonedPages(vbox_PVM pVM, VMCPUID idCpu, GMMBALLOONACTION enmAction, uint32_t cBalloonedPages);
+GMMR0DECL(int)  GMMR0MapUnmapChunk(vbox_PVM pVM, uint32_t idChunkMap, uint32_t idChunkUnmap, PRTR3PTR ppvR3);
+GMMR0DECL(int)  GMMR0SeedChunk(vbox_PVM pVM, VMCPUID idCpu, RTR3PTR pvR3);
+GMMR0DECL(int)  GMMR0RegisterSharedModule(vbox_PVM pVM, VMCPUID idCpu, VBOXOSFAMILY enmGuestOS, char *pszModuleName, char *pszVersion,
                                           RTGCPTR GCBaseAddr,  uint32_t cbModule, uint32_t cRegions,
                                           struct VMMDEVSHAREDREGIONDESC const *paRegions);
-GMMR0DECL(int)  GMMR0UnregisterSharedModule(PVM pVM, VMCPUID idCpu, char *pszModuleName, char *pszVersion, RTGCPTR GCBaseAddr, uint32_t cbModule);
-GMMR0DECL(int)  GMMR0UnregisterAllSharedModules(PVM pVM, VMCPUID idCpu);
-GMMR0DECL(int)  GMMR0CheckSharedModules(PVM pVM, PVMCPU pVCpu);
-GMMR0DECL(int)  GMMR0ResetSharedModules(PVM pVM, VMCPUID idCpu);
-GMMR0DECL(int)  GMMR0CheckSharedModulesStart(PVM pVM);
-GMMR0DECL(int)  GMMR0CheckSharedModulesEnd(PVM pVM);
+GMMR0DECL(int)  GMMR0UnregisterSharedModule(vbox_PVM pVM, VMCPUID idCpu, char *pszModuleName, char *pszVersion, RTGCPTR GCBaseAddr, uint32_t cbModule);
+GMMR0DECL(int)  GMMR0UnregisterAllSharedModules(vbox_PVM pVM, VMCPUID idCpu);
+GMMR0DECL(int)  GMMR0CheckSharedModules(vbox_PVM pVM, PVMCPU pVCpu);
+GMMR0DECL(int)  GMMR0ResetSharedModules(vbox_PVM pVM, VMCPUID idCpu);
+GMMR0DECL(int)  GMMR0CheckSharedModulesStart(vbox_PVM pVM);
+GMMR0DECL(int)  GMMR0CheckSharedModulesEnd(vbox_PVM pVM);
 GMMR0DECL(int)  GMMR0QueryStatistics(PGMMSTATS pStats, PSUPDRVSESSION pSession);
 GMMR0DECL(int)  GMMR0ResetStatistics(PCGMMSTATS pStats, PSUPDRVSESSION pSession);
 
@@ -439,7 +439,7 @@ typedef struct GMMINITIALRESERVATIONREQ
 /** Pointer to a GMMR0InitialReservationReq / VMMR0_DO_GMM_INITIAL_RESERVATION request buffer. */
 typedef GMMINITIALRESERVATIONREQ *PGMMINITIALRESERVATIONREQ;
 
-GMMR0DECL(int)  GMMR0InitialReservationReq(PVM pVM, VMCPUID idCpu, PGMMINITIALRESERVATIONREQ pReq);
+GMMR0DECL(int)  GMMR0InitialReservationReq(vbox_PVM pVM, VMCPUID idCpu, PGMMINITIALRESERVATIONREQ pReq);
 
 
 /**
@@ -457,7 +457,7 @@ typedef struct GMMUPDATERESERVATIONREQ
 /** Pointer to a GMMR0InitialReservationReq / VMMR0_DO_GMM_INITIAL_RESERVATION request buffer. */
 typedef GMMUPDATERESERVATIONREQ *PGMMUPDATERESERVATIONREQ;
 
-GMMR0DECL(int)  GMMR0UpdateReservationReq(PVM pVM, VMCPUID idCpu, PGMMUPDATERESERVATIONREQ pReq);
+GMMR0DECL(int)  GMMR0UpdateReservationReq(vbox_PVM pVM, VMCPUID idCpu, PGMMUPDATERESERVATIONREQ pReq);
 
 
 /**
@@ -478,7 +478,7 @@ typedef struct GMMALLOCATEPAGESREQ
 /** Pointer to a GMMR0AllocatePagesReq / VMMR0_DO_GMM_ALLOCATE_PAGES request buffer. */
 typedef GMMALLOCATEPAGESREQ *PGMMALLOCATEPAGESREQ;
 
-GMMR0DECL(int)  GMMR0AllocatePagesReq(PVM pVM, VMCPUID idCpu, PGMMALLOCATEPAGESREQ pReq);
+GMMR0DECL(int)  GMMR0AllocatePagesReq(vbox_PVM pVM, VMCPUID idCpu, PGMMALLOCATEPAGESREQ pReq);
 
 
 /**
@@ -499,7 +499,7 @@ typedef struct GMMFREEPAGESREQ
 /** Pointer to a GMMR0FreePagesReq / VMMR0_DO_GMM_FREE_PAGES request buffer. */
 typedef GMMFREEPAGESREQ *PGMMFREEPAGESREQ;
 
-GMMR0DECL(int)  GMMR0FreePagesReq(PVM pVM, VMCPUID idCpu, PGMMFREEPAGESREQ pReq);
+GMMR0DECL(int)  GMMR0FreePagesReq(vbox_PVM pVM, VMCPUID idCpu, PGMMFREEPAGESREQ pReq);
 
 /**
  * Request buffer for GMMR0BalloonedPagesReq / VMMR0_DO_GMM_BALLOONED_PAGES.
@@ -517,7 +517,7 @@ typedef struct GMMBALLOONEDPAGESREQ
 /** Pointer to a GMMR0BalloonedPagesReq / VMMR0_DO_GMM_BALLOONED_PAGES request buffer. */
 typedef GMMBALLOONEDPAGESREQ *PGMMBALLOONEDPAGESREQ;
 
-GMMR0DECL(int)  GMMR0BalloonedPagesReq(PVM pVM, VMCPUID idCpu, PGMMBALLOONEDPAGESREQ pReq);
+GMMR0DECL(int)  GMMR0BalloonedPagesReq(vbox_PVM pVM, VMCPUID idCpu, PGMMBALLOONEDPAGESREQ pReq);
 
 
 /**
@@ -542,8 +542,8 @@ typedef struct GMMMEMSTATSREQ
 /** Pointer to a GMMR0QueryHypervisorMemoryStatsReq / VMMR0_DO_GMM_QUERY_HYPERVISOR_MEM_STATS request buffer. */
 typedef GMMMEMSTATSREQ *PGMMMEMSTATSREQ;
 
-GMMR0DECL(int)  GMMR0QueryHypervisorMemoryStatsReq(PVM pVM, PGMMMEMSTATSREQ pReq);
-GMMR0DECL(int)  GMMR0QueryMemoryStatsReq(PVM pVM, VMCPUID idCpu, PGMMMEMSTATSREQ pReq);
+GMMR0DECL(int)  GMMR0QueryHypervisorMemoryStatsReq(vbox_PVM pVM, PGMMMEMSTATSREQ pReq);
+GMMR0DECL(int)  GMMR0QueryMemoryStatsReq(vbox_PVM pVM, VMCPUID idCpu, PGMMMEMSTATSREQ pReq);
 
 /**
  * Request buffer for GMMR0MapUnmapChunkReq / VMMR0_DO_GMM_MAP_UNMAP_CHUNK.
@@ -563,7 +563,7 @@ typedef struct GMMMAPUNMAPCHUNKREQ
 /** Pointer to a GMMR0MapUnmapChunkReq / VMMR0_DO_GMM_MAP_UNMAP_CHUNK request buffer. */
 typedef GMMMAPUNMAPCHUNKREQ *PGMMMAPUNMAPCHUNKREQ;
 
-GMMR0DECL(int)  GMMR0MapUnmapChunkReq(PVM pVM, PGMMMAPUNMAPCHUNKREQ pReq);
+GMMR0DECL(int)  GMMR0MapUnmapChunkReq(vbox_PVM pVM, PGMMMAPUNMAPCHUNKREQ pReq);
 
 
 /**
@@ -580,7 +580,7 @@ typedef struct GMMFREELARGEPAGEREQ
 /** Pointer to a GMMR0FreePagesReq / VMMR0_DO_GMM_FREE_PAGES request buffer. */
 typedef GMMFREELARGEPAGEREQ *PGMMFREELARGEPAGEREQ;
 
-GMMR0DECL(int) GMMR0FreeLargePageReq(PVM pVM, VMCPUID idCpu, PGMMFREELARGEPAGEREQ pReq);
+GMMR0DECL(int) GMMR0FreeLargePageReq(vbox_PVM pVM, VMCPUID idCpu, PGMMFREELARGEPAGEREQ pReq);
 
 /** Maximum length of the shared module name string, terminator included. */
 #define GMM_SHARED_MODULE_MAX_NAME_STRING       128
@@ -615,7 +615,7 @@ typedef struct GMMREGISTERSHAREDMODULERE
 /** Pointer to a GMMR0RegisterSharedModuleReq / VMMR0_DO_GMM_REGISTER_SHARED_MODULE request buffer. */
 typedef GMMREGISTERSHAREDMODULEREQ *PGMMREGISTERSHAREDMODULEREQ;
 
-GMMR0DECL(int) GMMR0RegisterSharedModuleReq(PVM pVM, VMCPUID idCpu, PGMMREGISTERSHAREDMODULEREQ pReq);
+GMMR0DECL(int) GMMR0RegisterSharedModuleReq(vbox_PVM pVM, VMCPUID idCpu, PGMMREGISTERSHAREDMODULEREQ pReq);
 
 /**
  * Shared region descriptor
@@ -702,7 +702,7 @@ typedef struct GMMUNREGISTERSHAREDMODULE
 /** Pointer to a GMMR0UnregisterSharedModuleReq / VMMR0_DO_GMM_UNREGISTER_SHARED_MODULE request buffer. */
 typedef GMMUNREGISTERSHAREDMODULEREQ *PGMMUNREGISTERSHAREDMODULEREQ;
 
-GMMR0DECL(int) GMMR0UnregisterSharedModuleReq(PVM pVM, VMCPUID idCpu, PGMMUNREGISTERSHAREDMODULEREQ pReq);
+GMMR0DECL(int) GMMR0UnregisterSharedModuleReq(vbox_PVM pVM, VMCPUID idCpu, PGMMUNREGISTERSHAREDMODULEREQ pReq);
 
 #if defined(VBOX_STRICT) && HC_ARCH_BITS == 64
 /**
@@ -721,7 +721,7 @@ typedef struct GMMFINDDUPLICATEPAGEREQ
 /** Pointer to a GMMR0FindDuplicatePageReq / VMMR0_DO_GMM_FIND_DUPLICATE_PAGE request buffer. */
 typedef GMMFINDDUPLICATEPAGEREQ *PGMMFINDDUPLICATEPAGEREQ;
 
-GMMR0DECL(int) GMMR0FindDuplicatePageReq(PVM pVM, PGMMFINDDUPLICATEPAGEREQ pReq);
+GMMR0DECL(int) GMMR0FindDuplicatePageReq(vbox_PVM pVM, PGMMFINDDUPLICATEPAGEREQ pReq);
 #endif /* VBOX_STRICT && HC_ARCH_BITS == 64 */
 
 
@@ -742,7 +742,7 @@ typedef struct GMMQUERYSTATISTICSSREQ
  *  request buffer. */
 typedef GMMQUERYSTATISTICSSREQ *PGMMQUERYSTATISTICSSREQ;
 
-GMMR0DECL(int)      GMMR0QueryStatisticsReq(PVM pVM, PGMMQUERYSTATISTICSSREQ pReq);
+GMMR0DECL(int)      GMMR0QueryStatisticsReq(vbox_PVM pVM, PGMMQUERYSTATISTICSSREQ pReq);
 
 
 /**
@@ -763,7 +763,7 @@ typedef struct GMMRESETSTATISTICSSREQ
  *  request buffer. */
 typedef GMMRESETSTATISTICSSREQ *PGMMRESETSTATISTICSSREQ;
 
-GMMR0DECL(int)      GMMR0ResetStatisticsReq(PVM pVM, PGMMRESETSTATISTICSSREQ pReq);
+GMMR0DECL(int)      GMMR0ResetStatisticsReq(vbox_PVM pVM, PGMMRESETSTATISTICSSREQ pReq);
 
 
 
@@ -771,31 +771,31 @@ GMMR0DECL(int)      GMMR0ResetStatistics
 /** @defgroup grp_gmm_r3    The Global Memory Manager Ring-3 API Wrappers
  * @{
  */
-GMMR3DECL(int)  GMMR3InitialReservation(PVM pVM, uint64_t cBasePages, uint32_t cShadowPages, uint32_t cFixedPages,
+GMMR3DECL(int)  GMMR3InitialReservation(vbox_PVM pVM, uint64_t cBasePages, uint32_t cShadowPages, uint32_t cFixedPages,
                                         GMMOCPOLICY enmPolicy, GMMPRIORITY enmPriority);
-GMMR3DECL(int)  GMMR3UpdateReservation(PVM pVM, uint64_t cBasePages, uint32_t cShadowPages, uint32_t cFixedPages);
-GMMR3DECL(int)  GMMR3AllocatePagesPrepare(PVM pVM, PGMMALLOCATEPAGESREQ *ppReq, uint32_t cPages, GMMACCOUNT enmAccount);
-GMMR3DECL(int)  GMMR3AllocatePagesPerform(PVM pVM, PGMMALLOCATEPAGESREQ pReq);
+GMMR3DECL(int)  GMMR3UpdateReservation(vbox_PVM pVM, uint64_t cBasePages, uint32_t cShadowPages, uint32_t cFixedPages);
+GMMR3DECL(int)  GMMR3AllocatePagesPrepare(vbox_PVM pVM, PGMMALLOCATEPAGESREQ *ppReq, uint32_t cPages, GMMACCOUNT enmAccount);
+GMMR3DECL(int)  GMMR3AllocatePagesPerform(vbox_PVM pVM, PGMMALLOCATEPAGESREQ pReq);
 GMMR3DECL(void) GMMR3AllocatePagesCleanup(PGMMALLOCATEPAGESREQ pReq);
-GMMR3DECL(int)  GMMR3FreePagesPrepare(PVM pVM, PGMMFREEPAGESREQ *ppReq, uint32_t cPages, GMMACCOUNT enmAccount);
-GMMR3DECL(void) GMMR3FreePagesRePrep(PVM pVM, PGMMFREEPAGESREQ pReq, uint32_t cPages, GMMACCOUNT enmAccount);
-GMMR3DECL(int)  GMMR3FreePagesPerform(PVM pVM, PGMMFREEPAGESREQ pReq, uint32_t cActualPages);
+GMMR3DECL(int)  GMMR3FreePagesPrepare(vbox_PVM pVM, PGMMFREEPAGESREQ *ppReq, uint32_t cPages, GMMACCOUNT enmAccount);
+GMMR3DECL(void) GMMR3FreePagesRePrep(vbox_PVM pVM, PGMMFREEPAGESREQ pReq, uint32_t cPages, GMMACCOUNT enmAccount);
+GMMR3DECL(int)  GMMR3FreePagesPerform(vbox_PVM pVM, PGMMFREEPAGESREQ pReq, uint32_t cActualPages);
 GMMR3DECL(void) GMMR3FreePagesCleanup(PGMMFREEPAGESREQ pReq);
-GMMR3DECL(void) GMMR3FreeAllocatedPages(PVM pVM, GMMALLOCATEPAGESREQ const *pAllocReq);
-GMMR3DECL(int)  GMMR3AllocateLargePage(PVM pVM,  uint32_t cbPage);
-GMMR3DECL(int)  GMMR3FreeLargePage(PVM pVM,  uint32_t idPage);
-GMMR3DECL(int)  GMMR3MapUnmapChunk(PVM pVM, uint32_t idChunkMap, uint32_t idChunkUnmap, PRTR3PTR ppvR3);
-GMMR3DECL(int)  GMMR3SeedChunk(PVM pVM, RTR3PTR pvR3);
-GMMR3DECL(int)  GMMR3QueryHypervisorMemoryStats(PVM pVM, uint64_t *pcTotalAllocPages, uint64_t *pcTotalFreePages, uint64_t *pcTotalBalloonPages, uint64_t *puTotalBalloonSize);
-GMMR3DECL(int)  GMMR3QueryMemoryStats(PVM pVM, uint64_t *pcAllocPages, uint64_t *pcMaxPages, uint64_t *pcBalloonPages);
-GMMR3DECL(int)  GMMR3BalloonedPages(PVM pVM, GMMBALLOONACTION enmAction, uint32_t cBalloonedPages);
-GMMR3DECL(int)  GMMR3RegisterSharedModule(PVM pVM, PGMMREGISTERSHAREDMODULEREQ pReq);
-GMMR3DECL(int)  GMMR3UnregisterSharedModule(PVM pVM, PGMMUNREGISTERSHAREDMODULEREQ pReq);
-GMMR3DECL(int)  GMMR3CheckSharedModules(PVM pVM);
-GMMR3DECL(int)  GMMR3ResetSharedModules(PVM pVM);
+GMMR3DECL(void) GMMR3FreeAllocatedPages(vbox_PVM pVM, GMMALLOCATEPAGESREQ const *pAllocReq);
+GMMR3DECL(int)  GMMR3AllocateLargePage(vbox_PVM pVM,  uint32_t cbPage);
+GMMR3DECL(int)  GMMR3FreeLargePage(vbox_PVM pVM,  uint32_t idPage);
+GMMR3DECL(int)  GMMR3MapUnmapChunk(vbox_PVM pVM, uint32_t idChunkMap, uint32_t idChunkUnmap, PRTR3PTR ppvR3);
+GMMR3DECL(int)  GMMR3SeedChunk(vbox_PVM pVM, RTR3PTR pvR3);
+GMMR3DECL(int)  GMMR3QueryHypervisorMemoryStats(vbox_PVM pVM, uint64_t *pcTotalAllocPages, uint64_t *pcTotalFreePages, uint64_t *pcTotalBalloonPages, uint64_t *puTotalBalloonSize);
+GMMR3DECL(int)  GMMR3QueryMemoryStats(vbox_PVM pVM, uint64_t *pcAllocPages, uint64_t *pcMaxPages, uint64_t *pcBalloonPages);
+GMMR3DECL(int)  GMMR3BalloonedPages(vbox_PVM pVM, GMMBALLOONACTION enmAction, uint32_t cBalloonedPages);
+GMMR3DECL(int)  GMMR3RegisterSharedModule(vbox_PVM pVM, PGMMREGISTERSHAREDMODULEREQ pReq);
+GMMR3DECL(int)  GMMR3UnregisterSharedModule(vbox_PVM pVM, PGMMUNREGISTERSHAREDMODULEREQ pReq);
+GMMR3DECL(int)  GMMR3CheckSharedModules(vbox_PVM pVM);
+GMMR3DECL(int)  GMMR3ResetSharedModules(vbox_PVM pVM);
 
 # if defined(VBOX_STRICT) && HC_ARCH_BITS == 64
-GMMR3DECL(bool) GMMR3IsDuplicatePage(PVM pVM, uint32_t idPage);
+GMMR3DECL(bool) GMMR3IsDuplicatePage(vbox_PVM pVM, uint32_t idPage);
 # endif
 
 /** @} */
@@ -806,4 +806,3 @@ GMMR3DECL(bool) GMMR3IsDuplicatePage(PVM
 RT_C_DECLS_END
 
 #endif
-
