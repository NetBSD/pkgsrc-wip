$NetBSD$

Fix build with GCC 14: entry[-1] accesses the d_type byte stored before the
path string (by design per dir.h). Suppress false-positive array-bounds
warning with a GCC diagnostic pragma.

--- gitstatus/src/index.cc.orig	2026-05-16 17:06:03.393586436 +0100
+++ gitstatus/src/index.cc	2026-05-16 17:06:36.603689498 +0100
@@ -292,7 +292,10 @@
 
       if (!matched) {
         StringView basename(entry);
-        if (entry[-1] == DT_DIR) entry[basename.len++] = '/';
+  #pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Warray-bounds"
+      if (entry[-1] == DT_DIR) entry[basename.len++] = '/';
+#pragma GCC diagnostic pop
         AddUnmached(basename);
       }
     }
