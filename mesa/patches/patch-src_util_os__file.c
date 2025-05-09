$NetBSD$

--- src/util/os_file.c.orig	2025-01-22 18:12:23.000000000 +0000
+++ src/util/os_file.c
@@ -224,6 +224,10 @@ typedef void *kvaddr_t;
 
 #endif /* DETECT_OS_DRAGONFLY || DETECT_OS_FREEBSD */
 
+#if DETECT_OS_NETBSD
+#include <sys/stat.h>
+#endif
+
 int
 os_same_file_description(int fd1, int fd2)
 {
@@ -263,6 +267,19 @@ os_same_file_description(int fd1, int fd
       return -1;
 
    return (fd1_kfile < fd2_kfile) | ((fd1_kfile > fd2_kfile) << 1);
+#elif DETECT_OS_NETBSD
+   struct stat st1, st2;
+
+   if (fstat(fd1, &st1) != 0)
+      return -1;
+
+   if (fstat(fd2, &st2) != 0)
+      return -1;
+
+   if ((st1.st_dev == st2.st_dev) && (st1.st_ino == st2.st_ino))
+      return 0;
+   else
+      return 3;
 #else
    /* Otherwise we can't tell */
    return -1;
