$NetBSD$

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libphobos/libdruntime/core/internal/gc/impl/conservative/gc.d
+++ libphobos/libdruntime/core/internal/gc/impl/conservative/gc.d
@@ -30,8 +30,13 @@ module core.internal.gc.impl.conservative.gc;

 /***************************************************/
 version = COLLECT_PARALLEL;  // parallel scanning
-version (Posix)
-    version = COLLECT_FORK;
+version (GNU)
+{
+  version (linux)
+    version = COLLECT_FORK;  // uses clone(), battle tested and reliable
+}
+else version (Posix)
+  version = COLLECT_FORK;

 import core.internal.gc.bits;
 import core.internal.gc.os;
