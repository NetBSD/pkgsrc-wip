$NetBSD$

--- tools/gn/variables.cc.orig	2016-08-05 17:36:04.000000000 +0000
+++ tools/gn/variables.cc
@@ -191,7 +191,8 @@ const char kTargetOs_Help[] =
     "  - \"linux\"\n"
     "  - \"nacl\"\n"
     "  - \"mac\"\n"
-    "  - \"win\"\n";
+    "  - \"win\"\n"
+    "  - \"netbsd\"\n";
 
 const char kCurrentCpu[] = "current_cpu";
 const char kCurrentCpu_HelpShort[] =
