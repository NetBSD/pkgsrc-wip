$NetBSD$

--- src/Native/Runtime/gcrhenv.cpp.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Runtime/gcrhenv.cpp
@@ -717,7 +717,7 @@ void RedhawkGCInterface::ScanStackRoots(
     sContext.m_pfnCallback = pfnScanCallback;
     sContext.m_pContext = pContext;
 
-    pThread->GcScanRoots(ScanRootsCallbackWrapper, &sContext);
+    pThread->GcScanRoots(reinterpret_cast<void*>(ScanRootsCallbackWrapper), &sContext);
 #else
     UNREFERENCED_PARAMETER(pThread);
     UNREFERENCED_PARAMETER(pfnScanCallback);
@@ -735,7 +735,7 @@ void RedhawkGCInterface::ScanStaticRoots
     sContext.m_pfnCallback = pfnScanCallback;
     sContext.m_pContext = pContext;
 
-    GetRuntimeInstance()->EnumAllStaticGCRefs(ScanRootsCallbackWrapper, &sContext);
+    GetRuntimeInstance()->EnumAllStaticGCRefs(reinterpret_cast<void*>(ScanRootsCallbackWrapper), &sContext);
 #else
     UNREFERENCED_PARAMETER(pfnScanCallback);
     UNREFERENCED_PARAMETER(pContext);
