$NetBSD$

--- src/vm/comwaithandle.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/comwaithandle.cpp
@@ -273,9 +273,9 @@ FCIMPL4(INT32, WaitHandleNative::CorWait
     arrayHolder.Initialize(numWaiters, (PTRARRAYREF*) &waitObjects);
     
     pWaitObjects = (PTRARRAYREF)waitObjects;  // array of objects on which to wait
-    HANDLE* internalHandles = (HANDLE*) _alloca(numWaiters*sizeof(HANDLE));
+    HANDLE* internalHandles = (HANDLE*) Alloca(numWaiters*sizeof(HANDLE));
 #ifndef FEATURE_CORECLR
-    BOOL *hasThreadAffinity = (BOOL*) _alloca(numWaiters*sizeof(BOOL));
+    BOOL *hasThreadAffinity = (BOOL*) Alloca(numWaiters*sizeof(BOOL));
 
     BOOL mayRequireThreadAffinity = FALSE;
 #endif // !FEATURE_CORECLR
