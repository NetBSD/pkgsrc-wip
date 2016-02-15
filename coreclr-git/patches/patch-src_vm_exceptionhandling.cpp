$NetBSD$

--- src/vm/exceptionhandling.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/exceptionhandling.cpp
@@ -4298,7 +4298,7 @@ void DumpClauses(IJitManager* pJitMan, c
 }
 
 #define STACK_ALLOC_ARRAY(numElements, type) \
-    ((type *)_alloca((numElements)*(sizeof(type))))
+    ((type *)Alloca((numElements)*(sizeof(type))))
 
 static void DoEHLog(
     DWORD lvl,
