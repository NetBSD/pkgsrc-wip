$NetBSD$

--- src/VBox/Debugger/DBGConsole.cpp.orig	2016-03-04 19:25:46.000000000 +0000
+++ src/VBox/Debugger/DBGConsole.cpp
@@ -1004,7 +1004,7 @@ DBGDECL(int) DBGCCreate(PUVM pUVM, PDBGC
      * Validate input.
      */
     AssertPtrNullReturn(pUVM, VERR_INVALID_VM_HANDLE);
-    PVM pVM = NULL;
+    vbox_PVM pVM = NULL;
     if (pUVM)
     {
         pVM = VMR3GetVM(pUVM);
@@ -1100,4 +1100,3 @@ DBGDECL(int) DBGCCreate(PUVM pUVM, PDBGC
     dbgcDestroy(pDbgc);
     return rc == VERR_DBGC_QUIT ? VINF_SUCCESS : rc;
 }
-
