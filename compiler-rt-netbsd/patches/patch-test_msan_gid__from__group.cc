$NetBSD$

--- test/msan/gid_from_group.cc.orig	2018-01-17 19:17:09.381969377 +0000
+++ test/msan/gid_from_group.cc
@@ -0,0 +1,17 @@
+// RUN: %clangxx_msan -O0 %s -o %t && %run %t
+// UNSUPPORTED: linux
+
+#include <grp.h>
+#include <stdlib.h>
+
+int main(void) {
+  gid_t nobody;
+
+  if (gid_from_group("nobody", &nobody) == -1)
+    exit(1);
+
+  if (nobody)
+    exit(0);
+
+  return 0;
+}
