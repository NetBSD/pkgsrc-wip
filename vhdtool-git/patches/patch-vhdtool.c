$NetBSD$

This is a quick hack to get other platforms besides Linux to work, via:

  1) on Darwin/macOS, off64_t is undefined, but off_t is guaranteed to
     always be 64-bit, so define it as that.

  2) For the same reason above, use lseek instead of lseek64 on macOS.

  3) Deal with endian.h being found in different places on Linux & BSD.

--- vhdtool.c.orig	2018-03-02 03:47:49.000000000 +0000
+++ vhdtool.c
@@ -21,9 +21,19 @@
 #define _GNU_SOURCE
 #define _FILE_OFFSET_BITS 64
 
+#if defined(__APPLE__) || ! defined(off64_t)
+	#define off64_t off_t // on macOS, off64_t isn't defined, and off_t is always 64-bit
+#endif
+
 #include <errno.h>
 #include <stdio.h>
-#include <endian.h>
+
+#ifdef __linux__
+	#include <endian.h>
+#else
+	#include <machine/endian.h>
+#endif
+
 #include <inttypes.h>
 #include <string.h>
 #include <getopt.h>
@@ -34,6 +44,13 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
+#if defined(__APPLE__) && ! defined(lseek64)
+	#define LSEEK lseek // lseek is guaranteed to handle big files on macOS
+#else
+	#define LSEEK lseek64
+#endif
+
+
 #define COOKIE(x)           (*(uint64_t *) x)
 #define COOKIE32(x)         (*(uint32_t *) x)
 #define FOOTER_FEAT_RSVD    (2)
@@ -152,7 +169,7 @@ int vhd_read(struct vhd *vhd,
 	     void *buf,
 	     size_t size)
 {
-	if (lseek64(vhd->fd, vhd->offset, SEEK_SET) != vhd->offset) {
+	if (LSEEK(vhd->fd, vhd->offset, SEEK_SET) != vhd->offset) {
 		fprintf(stderr, "Error: couldn't seek '%s': %s\n",
 			vhd->name, strerror(errno));
 		return -1;
@@ -172,7 +189,7 @@ int vhd_write(struct vhd *vhd,
 	      void *buf,
 	      size_t size)
 {
-	if (lseek64(vhd->fd, vhd->offset, SEEK_SET) != vhd->offset) {
+	if (LSEEK(vhd->fd, vhd->offset, SEEK_SET) != vhd->offset) {
 		fprintf(stderr, "Error: couldn't seek '%s': %s\n",
 			vhd->name, strerror(errno));
 		return -1;
