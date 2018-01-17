$NetBSD$

--- test/msan/user_from_uid.cc.orig	2018-01-17 19:17:09.382195279 +0000
+++ test/msan/user_from_uid.cc
@@ -0,0 +1,18 @@
+// RUN: %clangxx_msan -O0 %s -o %t && %run %t
+// UNSUPPORTED: linux
+
+#include <pwd.h>
+#include <stdlib.h>
+#include <string.h>
+
+int main(void) {
+  const char *nobody;
+
+  if (!(nobody = user_from_uid(0, 0)))
+    exit(1);
+
+  if (strlen(nobody))
+    exit(0);
+
+  return 0;
+}
