$NetBSD$

Match archivers/minizip.

--- include/ext_lzma.h.orig	2020-06-16 15:30:11.000000000 +0000
+++ include/ext_lzma.h
@@ -8,8 +8,8 @@
 #include <LzmaDec.h>
 #include <Lzma2Dec.h>
 
-#include "contrib/minizip/ioapi.h"
-#include "contrib/minizip/unzip.h"
+#include <minizip/ioapi.h>
+#include <minizip/unzip.h>
 
 int hc_lzma1_decompress (const unsigned char *in, SizeT *in_len, unsigned char *out, SizeT *out_len, const char *props);
 int hc_lzma2_decompress (const unsigned char *in, SizeT *in_len, unsigned char *out, SizeT *out_len, const char *props);
