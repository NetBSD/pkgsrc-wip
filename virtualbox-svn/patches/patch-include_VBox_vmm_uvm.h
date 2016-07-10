$NetBSD$

--- include/VBox/vmm/uvm.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/uvm.h
@@ -42,7 +42,7 @@ typedef struct UVMCPU
     /** Pointer to the UVM structure.  */
     PUVM                            pUVM;
     /** Pointer to the VM structure.  */
-    PVM                             pVM;
+    vbox_PVM                             pVM;
     /** Pointer to the VMCPU structure.  */
     PVMCPU                          pVCpu;
     /** The virtual CPU ID.  */
@@ -87,7 +87,7 @@ typedef struct UVM
     /** The number of virtual CPUs. */
     uint32_t            cCpus;
     /** The ring-3 mapping of the shared VM structure. */
-    PVM                 pVM;
+    vbox_PVM                 pVM;
     /** Pointer to the next VM.
      * We keep a per process list of VM for the event that a process could
      * contain more than one VM.
@@ -180,4 +180,3 @@ AssertCompileMemberAlignment(UVM, aCpus,
 
 /** @} */
 #endif
-
