$NetBSD$

--- test/msan/group_from_gid.cc.orig	2018-01-17 19:17:09.382044436 +0000
+++ test/msan/group_from_gid.cc
@@ -0,0 +1,18 @@
+// RUN: %clangxx_msan -O0 %s -o %t && %run %t
+// UNSUPPORTED: linux
+
+#include <grp.h>
+#include <stdlib.h>
+#include <string.h>
+
+int main(void) {
+  const char *nobody;
+
+  if (!(nobody = group_from_gid(0, 0)))
+    exit(1);
+
+  if (strlen(nobody))
+    exit(0);
+
+  return 0;
+}
