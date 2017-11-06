$NetBSD$

--- test/tsan/atexit3.cc.orig	2017-11-06 18:32:33.221125749 +0000
+++ test/tsan/atexit3.cc
@@ -0,0 +1,41 @@
+// RUN: %clang_tsan -O1 %s -o %t && %run %t 2>&1 | FileCheck %s
+
+#include <stdio.h>
+#include <stdlib.h>
+
+static void atexit5() {
+  fprintf(stderr, "5");
+}
+
+static void atexit4() {
+  fprintf(stderr, "4");
+}
+
+static void atexit3() {
+  fprintf(stderr, "3");
+}
+
+static void atexit2() {
+  fprintf(stderr, "2");
+}
+
+static void atexit1() {
+  fprintf(stderr, "1");
+}
+
+static void atexit0() {
+  fprintf(stderr, "\n");
+}
+
+int main() {
+  atexit(atexit0);
+  atexit(atexit1);
+  atexit(atexit2);
+  atexit(atexit3);
+  atexit(atexit4);
+  atexit(atexit5);
+}
+
+// CHECK-NOT: FATAL: ThreadSanitizer
+// CHECK-NOT: WARNING: ThreadSanitizer
+// CHECK: 54321
