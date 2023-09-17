$NetBSD$

Emulate statfs(2) on NetBSD via statvfs(2).

--- hw/9pfs/9p.h.orig	2023-08-22 15:34:01.000000000 +0000
+++ hw/9pfs/9p.h
@@ -4,6 +4,9 @@
 #include <dirent.h>
 #include <utime.h>
 #include <sys/resource.h>
+#if defined(__NetBSD__)
+#include "netbsd-statfs-compat.h"
+#endif
 #include "fsdev/file-op-9p.h"
 #include "fsdev/9p-iov-marshal.h"
 #include "qemu/thread.h"
