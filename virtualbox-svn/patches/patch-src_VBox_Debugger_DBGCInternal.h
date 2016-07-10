$NetBSD$

--- src/VBox/Debugger/DBGCInternal.h.orig	2016-03-04 19:25:46.000000000 +0000
+++ src/VBox/Debugger/DBGCInternal.h
@@ -89,7 +89,7 @@ typedef struct DBGC
     PDBGCBACK           pBack;
 
     /** Pointer to the current VM. */
-    PVM                 pVM;
+    vbox_PVM                 pVM;
     /** The user mode handle of the current VM. */
     PUVM                pUVM;
     /** The ID of current virtual CPU. */
@@ -410,4 +410,3 @@ extern const uint32_t   g_cDbgcOps;
 
 
 #endif
-
