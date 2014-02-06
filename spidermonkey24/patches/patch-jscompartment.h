$NetBSD: patch-jscompartment.h,v 1.1 2014/02/06 15:12:18 fhajny Exp $

--- jscompartment.h.orig	2013-06-17 22:13:11.000000000 +0000
+++ jscompartment.h
@@ -396,9 +396,9 @@ class js::AutoDebugModeGC
             GC(rt, GC_NORMAL, JS::gcreason::DEBUG_MODE_GC);
     }
 
-    void scheduleGC(Zone *zone) {
+    void scheduleGC(JS::Zone *zone) {
         JS_ASSERT(!rt->isHeapBusy());
-        PrepareZoneForGC(zone);
+        JS::PrepareZoneForGC(zone);
         needGC = true;
     }
 };
