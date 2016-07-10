$NetBSD$

--- include/VBox/vmm/hm.h.orig	2016-07-10 19:42:15.000000000 +0000
+++ include/VBox/vmm/hm.h
@@ -149,14 +149,14 @@ VMM_INT_DECL(void)              HMHyperc
 
 #ifndef IN_RC
 VMM_INT_DECL(int)               HMFlushTLB(PVMCPU pVCpu);
-VMM_INT_DECL(int)               HMFlushTLBOnAllVCpus(PVM pVM);
-VMM_INT_DECL(int)               HMInvalidatePageOnAllVCpus(PVM pVM, RTGCPTR GCVirt);
-VMM_INT_DECL(int)               HMInvalidatePhysPage(PVM pVM, RTGCPHYS GCPhys);
-VMM_INT_DECL(bool)              HMIsNestedPagingActive(PVM pVM);
-VMM_INT_DECL(bool)              HMAreNestedPagingAndFullGuestExecEnabled(PVM pVM);
-VMM_INT_DECL(bool)              HMIsLongModeAllowed(PVM pVM);
-VMM_INT_DECL(bool)              HMAreMsrBitmapsAvailable(PVM pVM);
-VMM_INT_DECL(PGMMODE)           HMGetShwPagingMode(PVM pVM);
+VMM_INT_DECL(int)               HMFlushTLBOnAllVCpus(vbox_PVM pVM);
+VMM_INT_DECL(int)               HMInvalidatePageOnAllVCpus(vbox_PVM pVM, RTGCPTR GCVirt);
+VMM_INT_DECL(int)               HMInvalidatePhysPage(vbox_PVM pVM, RTGCPHYS GCPhys);
+VMM_INT_DECL(bool)              HMIsNestedPagingActive(vbox_PVM pVM);
+VMM_INT_DECL(bool)              HMAreNestedPagingAndFullGuestExecEnabled(vbox_PVM pVM);
+VMM_INT_DECL(bool)              HMIsLongModeAllowed(vbox_PVM pVM);
+VMM_INT_DECL(bool)              HMAreMsrBitmapsAvailable(vbox_PVM pVM);
+VMM_INT_DECL(PGMMODE)           HMGetShwPagingMode(vbox_PVM pVM);
 #else /* Nops in RC: */
 # define HMFlushTLB(pVCpu)                              do { } while (0)
 # define HMIsNestedPagingActive(pVM)                    false
@@ -248,4 +248,3 @@ RT_C_DECLS_END
 
 
 #endif
-
