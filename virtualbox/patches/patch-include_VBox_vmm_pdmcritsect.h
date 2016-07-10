$NetBSD$

--- include/VBox/vmm/pdmcritsect.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/pdmcritsect.h
@@ -51,14 +51,14 @@ typedef union PDMCRITSECT
 #endif
 } PDMCRITSECT;
 
-VMMR3_INT_DECL(int)     PDMR3CritSectBothTerm(PVM pVM);
-VMMR3_INT_DECL(void)    PDMR3CritSectLeaveAll(PVM pVM);
+VMMR3_INT_DECL(int)     PDMR3CritSectBothTerm(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    PDMR3CritSectLeaveAll(vbox_PVM pVM);
 VMM_INT_DECL(void)      PDMCritSectBothFF(PVMCPU pVCpu);
 
 
-VMMR3DECL(uint32_t) PDMR3CritSectCountOwned(PVM pVM, char *pszNames, size_t cbNames);
+VMMR3DECL(uint32_t) PDMR3CritSectCountOwned(vbox_PVM pVM, char *pszNames, size_t cbNames);
 
-VMMR3DECL(int)      PDMR3CritSectInit(PVM pVM, PPDMCRITSECT pCritSect, RT_SRC_POS_DECL,
+VMMR3DECL(int)      PDMR3CritSectInit(vbox_PVM pVM, PPDMCRITSECT pCritSect, RT_SRC_POS_DECL,
                                       const char *pszNameFmt, ...) RT_IPRT_FORMAT_ATTR(6, 7);
 VMMR3DECL(int)      PDMR3CritSectEnterEx(PPDMCRITSECT pCritSect, bool fCallRing3);
 VMMR3DECL(bool)     PDMR3CritSectYield(PPDMCRITSECT pCritSect);
@@ -80,9 +80,9 @@ VMMDECL(bool)       PDMCritSectIsInitial
 VMMDECL(bool)       PDMCritSectHasWaiters(PCPDMCRITSECT pCritSect);
 VMMDECL(uint32_t)   PDMCritSectGetRecursion(PCPDMCRITSECT pCritSect);
 
-VMMR3DECL(PPDMCRITSECT)             PDMR3CritSectGetNop(PVM pVM);
-VMMR3DECL(R0PTRTYPE(PPDMCRITSECT))  PDMR3CritSectGetNopR0(PVM pVM);
-VMMR3DECL(RCPTRTYPE(PPDMCRITSECT))  PDMR3CritSectGetNopRC(PVM pVM);
+VMMR3DECL(PPDMCRITSECT)             PDMR3CritSectGetNop(vbox_PVM pVM);
+VMMR3DECL(R0PTRTYPE(PPDMCRITSECT))  PDMR3CritSectGetNopR0(vbox_PVM pVM);
+VMMR3DECL(RCPTRTYPE(PPDMCRITSECT))  PDMR3CritSectGetNopRC(vbox_PVM pVM);
 
 /* Strict build: Remap the two enter calls to the debug versions. */
 #ifdef VBOX_STRICT
@@ -100,4 +100,3 @@ VMMR3DECL(RCPTRTYPE(PPDMCRITSECT))  PDMR
 RT_C_DECLS_END
 
 #endif
-
