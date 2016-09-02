$NetBSD$

Fix conflict with stdio.h.

--- media/libyuv/source/mjpeg_decoder.cc.orig	2016-09-02 05:50:23.394938860 +0000
+++ media/libyuv/source/mjpeg_decoder.cc
@@ -25,7 +25,7 @@
 #endif
 
 #endif
-struct FILE;  // For jpeglib.h.
+#include <stdio.h> # for FILE
 
 // C++ build requires extern C for jpeg internals.
 #ifdef __cplusplus
