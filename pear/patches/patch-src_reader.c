$NetBSD$

--- src/reader.c.orig	2015-01-15 16:23:52.000000000 +0000
+++ src/reader.c
@@ -13,6 +13,11 @@
 #include <zlib.h>
 #endif
 
+// Base zlib on NetBSD 6 lacks gzoffset()
+#ifdef __NetBSD__
+#define	gzoffset(file)	gzseek(file,0,SEEK_CUR)
+#endif
+
 #define READ_SIZE 400
 
 #define PEAR_FILETYPE_FASTQ     1 << 0
