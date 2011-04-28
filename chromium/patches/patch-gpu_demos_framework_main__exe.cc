$NetBSD: patch-gpu_demos_framework_main__exe.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- gpu/demos/framework/main_exe.cc.orig	2011-04-13 08:01:09.000000000 +0000
+++ gpu/demos/framework/main_exe.cc
@@ -8,9 +8,9 @@
 #include "base/logging.h"
 #include "gpu/demos/framework/window.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include <gtk/gtk.h>
-#endif  // OS_LINUX
+#endif  // TOOLKIT_USES_GTK
 
 namespace {
 static const int kWindowWidth = 512;
@@ -18,9 +18,9 @@ static const int kWindowHeight = 512;
 }  // namespace.
 
 int main(int argc, char** argv) {
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   gtk_init(&argc, &argv);
-#endif  // OS_LINUX
+#endif  // TOOLKIT_USES_GTK
 
   // AtExitManager is used by singleton classes to delete themselves when
   // the program terminates.
