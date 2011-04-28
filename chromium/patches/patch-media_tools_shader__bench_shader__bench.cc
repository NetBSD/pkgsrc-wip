$NetBSD: patch-media_tools_shader__bench_shader__bench.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- media/tools/shader_bench/shader_bench.cc.orig	2011-04-13 08:01:06.000000000 +0000
+++ media/tools/shader_bench/shader_bench.cc
@@ -24,7 +24,7 @@
 #include "media/tools/shader_bench/painter.h"
 #include "media/tools/shader_bench/window.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include <gtk/gtk.h>
 #endif
 
@@ -97,7 +97,7 @@ int main(int argc, char** argv) {
   }
 
   // Read command line.
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   gtk_init(&argc, &argv);
 #endif
   CommandLine::Init(argc, argv);
