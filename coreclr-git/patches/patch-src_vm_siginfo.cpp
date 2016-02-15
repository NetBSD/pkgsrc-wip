$NetBSD$

--- src/vm/siginfo.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/siginfo.cpp
@@ -1349,7 +1349,7 @@ TypeHandle SigPointer::GetTypeHandleThro
             {
                 DO_INTERIOR_STACK_PROBE_FOR_NOTHROW_CHECK_THREAD((10+dwAllocaSize/PAGE_SIZE+1), NO_FORBIDGC_LOADER_USE_ThrowSO(););
             }
-            TypeHandle *thisinst = (TypeHandle*) _alloca(dwAllocaSize);
+            TypeHandle *thisinst = (TypeHandle*) Alloca(dwAllocaSize);
 
             // Finally we gather up the type arguments themselves, loading at the level specified for generic arguments
             for (unsigned i = 0; i < ntypars; i++)
@@ -1636,7 +1636,7 @@ TypeHandle SigPointer::GetTypeHandleThro
                     DO_INTERIOR_STACK_PROBE_FOR_NOTHROW_CHECK_THREAD((10+cAllocaSize/PAGE_SIZE+1), NO_FORBIDGC_LOADER_USE_ThrowSO(););
                 }
 
-                TypeHandle *retAndArgTypes = (TypeHandle*) _alloca(cAllocaSize);
+                TypeHandle *retAndArgTypes = (TypeHandle*) Alloca(cAllocaSize);
                 bool fReturnTypeOrParameterNotLoaded = false;
 
                 for (unsigned i = 0; i <= cArgs; i++)
