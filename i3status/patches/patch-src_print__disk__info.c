$NetBSD: patch-src_print__disk__info.c,v 1.1 2015/04/07 21:11:11 nros Exp $
* mntent.h and setmntent stuff is linux only
--- src/print_disk_info.c.orig	2015-03-22 17:03:23.000000000 +0000
+++ src/print_disk_info.c
@@ -3,7 +3,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#if defined(__linux__)
 #include <mntent.h>
+#endif
 #include <stdint.h>
 #include <sys/stat.h>
 #include <sys/statvfs.h>
@@ -126,6 +128,7 @@ void print_disk_info(yajl_gen json_gen, 
     if (statvfs(path, &buf) == -1)
         return;
 
+#if defined(__linux__)
     if (format_not_mounted != NULL) {
         FILE *mntentfile = setmntent("/etc/mtab", "r");
         struct mntent *m;
@@ -144,6 +147,7 @@ void print_disk_info(yajl_gen json_gen, 
         }
     }
 #endif
+#endif
 
     if (low_threshold > 0 && below_threshold(buf, prefix_type, threshold_type, low_threshold)) {
         START_COLOR("color_bad");
