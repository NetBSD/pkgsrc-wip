$NetBSD$

--- test/sanitizer_common/TestCases/NetBSD/strlcat.cc.orig	2018-01-25 11:26:34.539381178 +0000
+++ test/sanitizer_common/TestCases/NetBSD/strlcat.cc
@@ -0,0 +1,56 @@
+// RUN: %clangxx -O0 -g %s -o %t && %run %t
+
+#include <string.h>
+#include <stdlib.h>
+#include <stdio.h>
+
+void
+test1() {
+  const char src[] = "abc";
+  char dst[7] = {'x', 'y', 'z', 0};
+  size_t len;
+
+  len = strlcat(dst, src, sizeof(dst));
+  printf("%s %zu ", dst, len);
+}
+
+void
+test2() {
+  const char src[] = "abc";
+  char dst[7] = {0};
+  size_t len;
+
+  len = strlcat(dst, src, sizeof(dst));
+  printf("%s %zu ", dst, len);
+}
+
+void
+test3() {
+  const char src[] = "abc";
+  char dst[4] = {'x', 'y', 'z', 0};
+  size_t len;
+
+  len = strlcat(dst, src, sizeof(dst));
+  printf("%s %zu ", dst, len);
+}
+
+void
+test4() {
+  const char src[] = "";
+  char dst[4] = {'x', 'y', 'z', 0};
+  size_t len;
+
+  len = strlcat(dst, src, sizeof(dst));
+  printf("%s %zu\n", dst, len);
+}
+
+int main(void) {
+  test1();
+  test2();
+  test3();
+  test4();
+
+  // CHECK: xyzabc 6 abc 3 xyz 3 xyz 3
+
+  return 0;
+}
