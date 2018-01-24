$NetBSD$

--- test/sanitizer_common/TestCases/NetBSD/kvm_openfiles.cc.orig	2018-01-24 15:01:49.077554804 +0000
+++ test/sanitizer_common/TestCases/NetBSD/kvm_openfiles.cc
@@ -0,0 +1,13 @@
+// RUN: %clangxx -O0 -g %s -o %t && %run %t
+
+#include <fcntl.h>
+#include <kvm.h>
+
+int main(void) {
+  kvm_t K;
+
+  K = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, "kvm_open");
+  kvm_close(&K);
+
+  return 0;
+}
