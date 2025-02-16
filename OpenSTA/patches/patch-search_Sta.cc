$NetBSD$

https://github.com/parallaxsw/OpenSTA/issues/217

--- search/Sta.cc.orig	2025-02-16 14:45:45.204666451 +0000
+++ search/Sta.cc
@@ -364,7 +364,11 @@ Sta::updateComponentsState()
 void
 Sta::makeReport()
 {
+#ifdef NOTCLREPORT
+  report_ = new Report();
+#else
   report_ = new ReportTcl();
+#endif
 }
 
 void
