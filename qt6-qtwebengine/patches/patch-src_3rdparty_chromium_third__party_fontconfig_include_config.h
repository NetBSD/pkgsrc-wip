$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/fontconfig/include/config.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/fontconfig/include/config.h
@@ -24,7 +24,7 @@
 /* #undef FC_ARCHITECTURE */
 
 /* System font directory */
-#define FC_DEFAULT_FONTS "<dir>/usr/share/fonts</dir>"
+#define FC_DEFAULT_FONTS "<dir>/usr/X11R6/lib/X11/fonts</dir>"
 
 /* The type of len parameter of the gperf hash/lookup function */
 #define FC_GPERF_SIZE_T size_t
@@ -141,7 +141,7 @@
 /* #undef HAVE_NDIR_H */
 
 /* Define to 1 if you have the 'posix_fadvise' function. */
-#define HAVE_POSIX_FADVISE 1
+#define HAVE_POSIX_FADVISE 0
 
 /* Have POSIX threads */
 #define HAVE_PTHREAD 1
@@ -156,11 +156,14 @@
 #define HAVE_RANDOM 1
 
 /* Define to 1 if you have the `random_r' function. */
-#define HAVE_RANDOM_R 1
+/* #undef HAVE_RANDOM_R */
 
 /* Define to 1 if you have the `rand_r' function. */
 #define HAVE_RAND_R 1
 
+/* Define to 1 if you have the `arc4_random' function. */
+#define HAVE_ARC4RANDOM 1
+
 /* Define to 1 if you have the `readlink' function. */
 #define HAVE_READLINK 1
 
@@ -230,7 +233,7 @@
 #define HAVE_SYS_PARAM_H 1
 
 /* Define to 1 if you have the <sys/statfs.h> header file. */
-#define HAVE_SYS_STATFS_H 1
+/* #undef HAVE_SYS_STATFS_H */
 
 /* Define to 1 if you have the <sys/statvfs.h> header file. */
 #define HAVE_SYS_STATVFS_H 1
@@ -245,7 +248,7 @@
 #define HAVE_SYS_VFS_H 1
 
 /* Define to 1 if you have the <unistd.h> header file. */
-#define HAVE_UNISTD_H 1
+/* #undef HAVE_UNISTD_H */
 
 /* Define to 1 if you have the `vprintf' function. */
 #define HAVE_VPRINTF 1
