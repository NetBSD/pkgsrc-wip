$NetBSD$

--- lib/xray/xray_profiling.cc.orig	2018-08-21 21:25:41.000000000 +0000
+++ lib/xray/xray_profiling.cc
@@ -345,8 +345,12 @@ bool profilingDynamicInitializer() XRAY_
     return false;
   }
 
-  if (!internal_strcmp(flags()->xray_mode, "xray-profiling"))
-    __xray_log_select_mode("xray_profiling");
+  Printf("flags()=%p\n", flags());
+  Printf("flags()->xray_mode=%s\n", flags()->xray_mode);
+  Printf("flags()->xray_logfile_base=%s\n", flags()->xray_logfile_base);
+
+//  if (!internal_strcmp(flags()->xray_mode, "xray-profiling"))
+//    __xray_log_select_mode("xray_profiling");
   return true;
 }
 
