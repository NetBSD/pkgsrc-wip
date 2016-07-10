$NetBSD$

--- include/VBox/vmm/gvm.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/gvm.h
@@ -80,7 +80,7 @@ typedef struct GVM
     /** The global VM handle for this VM. */
     uint32_t        hSelf;
     /** The ring-0 mapping of the VM structure. */
-    PVM             pVM;
+    vbox_PVM             pVM;
     /** Number of Virtual CPUs, i.e. how many entries there are in aCpus.
      * Same same as VM::cCpus. */
     uint32_t        cCpus;
@@ -124,4 +124,3 @@ typedef struct GVM
 /** @} */
 
 #endif
-
