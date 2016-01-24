$NetBSD$

--- src/Native/Runtime/gcrhscan.cpp.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Runtime/gcrhscan.cpp
@@ -30,7 +30,7 @@
 
 void EnumAllStaticGCRefs(EnumGcRefCallbackFunc * fn, EnumGcRefScanContext * sc)
 {
-    GetRuntimeInstance()->EnumAllStaticGCRefs(fn, sc);
+    GetRuntimeInstance()->EnumAllStaticGCRefs(reinterpret_cast<void*>(fn), sc);
 }
 
 /*
@@ -65,7 +65,7 @@ VOID GCToEEInterface::GcScanRoots(EnumGc
 #if defined(FEATURE_EVENT_TRACE) && !defined(DACCESS_COMPILE)
             sc->dwEtwRootKind = kEtwGCRootKindStack;
 #endif
-            pThread->GcScanRoots(fn, sc);
+            pThread->GcScanRoots(reinterpret_cast<void*>(fn), sc);
 
 #if defined(FEATURE_EVENT_TRACE) && !defined(DACCESS_COMPILE)
             sc->dwEtwRootKind = kEtwGCRootKindOther;
