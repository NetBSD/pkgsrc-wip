$NetBSD$

Fix build on non-linux platforms and disable btime support for now.

--- libnemo-private/nemo-statx.c.orig	2018-11-27 17:20:59.000000000 +0000
+++ libnemo-private/nemo-statx.c
@@ -21,10 +21,17 @@
 #define _ATFILE_SOURCE
 #include <config.h>
 #include <time.h>
+#ifdef __linux__
 #include <linux/fcntl.h>        // for AT_FDCWD, AT_NO_AUTOMOUNT
 #include <linux/stat.h>         // for statx, STATX_BTIME, statx_timestamp
+#else
+#include <sys/stat.h>
+#include <fcntl.h>
+#endif
 #include <string.h>             // for memset
+#ifndef __NetBSD__
 #include <syscall.h>            // for __NR_statx
+#endif
 #include <unistd.h>             // for syscall, ssize_t
 #include <stdio.h>
 #include <errno.h>
@@ -50,6 +57,16 @@ ssize_t statx (int dfd, const char *file
 
 #define STATX_BTIME             0x00000800U     /* Want/got stx_btime */
 
+#ifndef __linux__
+typedef uint8_t __u8;
+typedef uint16_t __u16;
+typedef uint32_t __u32;
+typedef uint64_t __u64;
+
+typedef int32_t __s32;
+typedef int64_t __s64;
+#endif
+
 struct statx_timestamp {
     __s64   tv_sec;
     __u32   tv_nsec;
@@ -97,7 +114,11 @@ get_file_btime (const char *path)
 {
     static int not_implemented = 0;
 
+#ifdef __linux__
     int flags = AT_NO_AUTOMOUNT;
+#else
+    int flags = 0;
+#endif
     unsigned int mask = STATX_BTIME;
     struct statx stxbuf;
     long ret = 0;
@@ -113,7 +134,11 @@ get_file_btime (const char *path)
     memset (&stxbuf, 0xbf, sizeof(stxbuf));
     errno = 0;
 
+#ifdef __NetBSD__
+    ret = -1;
+#else
     ret = statx (AT_FDCWD, path, flags, mask, &stxbuf);
+#endif
 
     if (ret < 0)
     {
@@ -129,4 +154,4 @@ get_file_btime (const char *path)
     btime = (&stxbuf)->stx_btime.tv_sec;
 
     return btime;
-}
\ No newline at end of file
+}
