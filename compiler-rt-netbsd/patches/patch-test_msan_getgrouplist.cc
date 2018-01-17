$NetBSD$

--- test/msan/getgrouplist.cc.orig	2018-01-17 19:17:09.381817951 +0000
+++ test/msan/getgrouplist.cc
@@ -0,0 +1,30 @@
+// RUN: %clangxx_msan -O0 %s -o %t && %run %t
+// UNSUPPORTED: linux
+
+#include <stdlib.h>
+#include <unistd.h>
+#include <grp.h>
+
+int main(void) {
+  gid_t *groups;
+  gid_t nobody;
+  int ngroups;
+
+  ngroups = sysconf(_SC_NGROUPS_MAX);
+  groups = (gid_t *)malloc(ngroups * sizeof(gid_t));
+  if (!groups)
+    exit(1);
+
+  if (gid_from_group("nobody", &nobody) == -1)
+    exit(1);
+
+  if (getgrouplist("nobody", nobody, groups, &ngroups))
+    exit(1);
+
+  if (groups && ngroups) {
+    free(groups);
+    exit(0);
+  }
+
+  return -1;
+}
