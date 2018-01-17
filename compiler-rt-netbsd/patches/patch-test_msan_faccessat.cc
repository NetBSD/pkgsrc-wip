$NetBSD$

--- test/msan/faccessat.cc.orig	2018-01-17 19:17:09.381739846 +0000
+++ test/msan/faccessat.cc
@@ -0,0 +1,7 @@
+// RUN: %clangxx_msan -O0 %s -o %t && %run %t
+// UNSUPPORTED: linux
+
+#include <fcntl.h>
+#include <unistd.h>
+
+int main(void) { return faccessat(AT_FDCWD, "/root", F_OK, 0); }
