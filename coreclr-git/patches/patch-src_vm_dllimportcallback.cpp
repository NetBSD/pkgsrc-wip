$NetBSD$

--- src/vm/dllimportcallback.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/dllimportcallback.cpp
@@ -872,7 +872,7 @@ Stub *UMThunkMarshInfo::CompileNExportTh
     // parameters with copy constructors where we perform value-to-reference transformation
     UINT nStackBytesIncoming = nStackBytes;
 
-    UINT *psrcofs = (UINT *)_alloca((nStackBytes / STACK_ELEM_SIZE) * sizeof(UINT));
+    UINT *psrcofs = (UINT *)Alloca((nStackBytes / STACK_ELEM_SIZE) * sizeof(UINT));
     UINT psrcofsregs[NUM_ARGUMENT_REGISTERS];
     UINT retbufofs = UNUSED_STACK_OFFSET;
 
