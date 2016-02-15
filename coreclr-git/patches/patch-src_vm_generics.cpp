$NetBSD$

--- src/vm/generics.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/generics.cpp
@@ -151,7 +151,7 @@ TypeHandle ClassLoader::LoadCanonicalGen
         DO_INTERIOR_STACK_PROBE_FOR_NOTHROW_CHECK_THREAD((10+dwAllocSize/PAGE_SIZE+1), NO_FORBIDGC_LOADER_USE_ThrowSO(););
     }
 #endif // DACCESS_COMPILE
-    TypeHandle *repInst = (TypeHandle*) _alloca(dwAllocSize);
+    TypeHandle *repInst = (TypeHandle*) Alloca(dwAllocSize);
 
     for (DWORD i = 0; i < ntypars; i++)
     {
