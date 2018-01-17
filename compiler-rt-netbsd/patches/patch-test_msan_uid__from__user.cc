$NetBSD$

--- test/msan/uid_from_user.cc.orig	2018-01-17 19:17:09.382120353 +0000
+++ test/msan/uid_from_user.cc
@@ -0,0 +1,17 @@
+// RUN: %clangxx_msan -O0 %s -o %t && %run %t
+// UNSUPPORTED: linux
+
+#include <pwd.h>
+#include <stdlib.h>
+
+int main(void) {
+  uid_t nobody;
+
+  if (uid_from_user("nobody", &nobody) == -1)
+    exit(1);
+
+  if (nobody)
+    exit(0);
+
+  return 0;
+}
