$NetBSD$

NetBSD-1.6.2 does not know about ENOTSUP.

--- include/ntfs-3g/compat.h.orig	2016-09-11 13:20:39.912972713 +0000
+++ include/ntfs-3g/compat.h	2016-09-11 13:22:14.634709911 +0000
@@ -71,5 +71,9 @@
 
 #endif /* defined WINDOWS */
 
+#ifndef ENOTSUP
+#define ENOTSUP EINVAL
+#endif
+
 #endif /* defined _NTFS_COMPAT_H */
 
