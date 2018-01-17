$NetBSD$

--- test/msan/access.cc.orig	2018-01-17 19:17:09.381651021 +0000
+++ test/msan/access.cc
@@ -0,0 +1,6 @@
+// RUN: %clangxx_msan -O0 %s -o %t && %run %t
+// UNSUPPORTED: linux
+
+#include <unistd.h>
+
+int main(void) { return access("/root", F_OK); }
