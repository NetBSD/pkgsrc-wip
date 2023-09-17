$NetBSD$

Add NetBSD support.

--- hw/9pfs/9p-util-bsd.c.orig	2023-09-17 11:07:36.901331752 +0000
+++ hw/9pfs/9p-util-bsd.c
@@ -0,0 +1,41 @@
+/*
+ * 9p utilities (BSD stub)
+ *
+ * This work is licensed under the terms of the GNU GPL, version 2 or later.
+ * See the COPYING file in the top-level directory.
+ */
+
+#include "qemu/osdep.h"
+#include "qemu/xattr.h"
+#include "qapi/error.h"
+#include "qemu/error-report.h"
+#include "9p-util.h"
+
+ssize_t fgetxattrat_nofollow(int dirfd, const char *filename, const char *name,
+                             void *value, size_t size)
+{
+    return ENOTSUP;
+}
+
+ssize_t flistxattrat_nofollow(int dirfd, const char *filename,
+                              char *list, size_t size)
+{
+    return ENOTSUP;
+}
+
+ssize_t fremovexattrat_nofollow(int dirfd, const char *filename,
+                                const char *name)
+{
+    return ENOTSUP;
+}
+
+int fsetxattrat_nofollow(int dirfd, const char *filename, const char *name,
+                         void *value, size_t size, int flags)
+{
+    return ENOTSUP;
+}
+
+int qemu_mknodat(int dirfd, const char *filename, mode_t mode, dev_t dev)
+{
+    return mknodat(dirfd, filename, mode, dev);
+}
