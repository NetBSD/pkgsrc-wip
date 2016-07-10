$NetBSD$

--- include/VBox/vmm/ftm.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/ftm.h
@@ -48,8 +48,8 @@ typedef enum FTMCHECKPOINTTYPE
     FTMCHECKPOINTTYPE_32BIT_HACK = 0x7fffffff
 } FTMCHECKPOINTTYPE;
 
-VMM_INT_DECL(bool)  FTMIsDeltaLoadSaveActive(PVM pVM);
-VMM_INT_DECL(int)   FTMSetCheckpoint(PVM pVM, FTMCHECKPOINTTYPE enmType);
+VMM_INT_DECL(bool)  FTMIsDeltaLoadSaveActive(vbox_PVM pVM);
+VMM_INT_DECL(int)   FTMSetCheckpoint(vbox_PVM pVM, FTMCHECKPOINTTYPE enmType);
 
 #ifdef IN_RING3
 /** @defgroup grp_ftm_r3     The FTM Host Context Ring-3 API
@@ -58,9 +58,9 @@ VMM_INT_DECL(int)   FTMSetCheckpoint(PVM
 VMMR3DECL(int)      FTMR3PowerOn(PUVM pUVM, bool fMaster, unsigned uInterval, const char *pszAddress, unsigned uPort, const char *pszPassword);
 VMMR3DECL(int)      FTMR3CancelStandby(PUVM pUVM);
 
-VMMR3_INT_DECL(int) FTMR3Init(PVM pVM);
-VMMR3_INT_DECL(int) FTMR3Term(PVM pVM);
-VMMR3_INT_DECL(int) FTMR3SetCheckpoint(PVM pVM, FTMCHECKPOINTTYPE enmType);
+VMMR3_INT_DECL(int) FTMR3Init(vbox_PVM pVM);
+VMMR3_INT_DECL(int) FTMR3Term(vbox_PVM pVM);
+VMMR3_INT_DECL(int) FTMR3SetCheckpoint(vbox_PVM pVM, FTMCHECKPOINTTYPE enmType);
 
 #endif /* IN_RING3 */
 
@@ -71,4 +71,3 @@ VMMR3_INT_DECL(int) FTMR3SetCheckpoint(P
 RT_C_DECLS_END
 
 #endif
-
