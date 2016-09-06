$NetBSD$

V4L2_FMT_FLAG_EMULATED is undefined on NetBSD-7. This define
effectively says that no device is emulated (if the underlying
v4l2 does not know about emulated devices).

--- modules/v4l2/v4l2.c.orig	2016-07-22 19:17:45.000000000 +0000
+++ modules/v4l2/v4l2.c
@@ -36,6 +36,9 @@
 #define v4l2_close close
 #endif
 
+#ifndef V4L2_FMT_FLAG_EMULATED
+#define V4L2_FMT_FLAG_EMULATED 0
+#endif
 
 /**
  * @defgroup v4l2 v4l2
