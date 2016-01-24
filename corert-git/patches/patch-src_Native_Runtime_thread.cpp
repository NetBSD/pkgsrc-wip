$NetBSD$

--- src/Native/Runtime/thread.cpp.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Runtime/thread.cpp
@@ -540,9 +540,9 @@ EXTERN_C void FASTCALL RhpGcProbeHijackB
 
 static void* NormalHijackTargets[3]     = 
 {
-    RhpGcProbeHijackScalar, // GCRK_Scalar = 0,
-    RhpGcProbeHijackObject, // GCRK_Object  = 1,
-    RhpGcProbeHijackByref   // GCRK_Byref  = 2,
+    reinterpret_cast<void*>(RhpGcProbeHijackScalar), // GCRK_Scalar = 0,
+    reinterpret_cast<void*>(RhpGcProbeHijackObject), // GCRK_Object  = 1,
+    reinterpret_cast<void*>(RhpGcProbeHijackByref)   // GCRK_Byref  = 2,
 };
 
 #ifdef FEATURE_GC_STRESS
@@ -552,9 +552,9 @@ EXTERN_C void FASTCALL RhpGcStressHijack
 
 static void* GcStressHijackTargets[3]   = 
 { 
-    RhpGcStressHijackScalar, // GCRK_Scalar = 0,
-    RhpGcStressHijackObject, // GCRK_Object  = 1,
-    RhpGcStressHijackByref   // GCRK_Byref  = 2,
+    reinterpret_cast<void*>(RhpGcStressHijackScalar), // GCRK_Scalar = 0,
+    reinterpret_cast<void*>(RhpGcStressHijackObject), // GCRK_Object  = 1,
+    reinterpret_cast<void*>(RhpGcStressHijackByref)   // GCRK_Byref  = 2,
 };
 #endif // FEATURE_GC_STRESS
 
