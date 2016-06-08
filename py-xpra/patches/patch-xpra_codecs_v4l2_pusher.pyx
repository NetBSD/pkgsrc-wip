$NetBSD$

--- xpra/codecs/v4l2/pusher.pyx.orig	2016-06-03 05:35:44.000000000 +0000
+++ xpra/codecs/v4l2/pusher.pyx
@@ -41,7 +41,7 @@ cdef extern from *:
 cdef extern from "sys/ioctl.h":
     int ioctl(int fd, unsigned long request, ...)
 
-cdef extern from "linux/videodev2.h":
+cdef extern from "./video.h":
     #define v4l2_fourcc(a,b,c,d)\
     #    (((__u32)(a)<<0)|((__u32)(b)<<8)|((__u32)(c)<<16)|((__u32)(d)<<24))
     int v4l2_fourcc(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
@@ -55,10 +55,10 @@ cdef extern from "linux/videodev2.h":
     int V4L2_FIELD_BOTTOM
     int V4L2_FIELD_INTERLACED
     int V4L2_FIELD_SEQ_TB
-    int V4L2_FIELD_SEQ_BT
-    int V4L2_FIELD_ALTERNATE
-    int V4L2_FIELD_INTERLACED_TB
-    int V4L2_FIELD_INTERLACED_BT
+    #int V4L2_FIELD_SEQ_BT
+    #int V4L2_FIELD_ALTERNATE
+    #int V4L2_FIELD_INTERLACED_TB
+    #int V4L2_FIELD_INTERLACED_BT
     #formats:
     int V4L2_PIX_FMT_GREY
     int V4L2_PIX_FMT_YUV422P
@@ -159,10 +159,10 @@ FIELD_STR = {
     V4L2_FIELD_BOTTOM               : "Bottom",
     V4L2_FIELD_INTERLACED           : "Interlaced",
     V4L2_FIELD_SEQ_TB               : "SEQ TB",
-    V4L2_FIELD_SEQ_BT               : "SEQ BT",
-    V4L2_FIELD_ALTERNATE            : "ALTERNATE",
-    V4L2_FIELD_INTERLACED_TB        : "INTERLACED TB",
-    V4L2_FIELD_INTERLACED_BT        : "INTERLACED BT",
+    #V4L2_FIELD_SEQ_BT               : "SEQ BT",
+    #V4L2_FIELD_ALTERNATE            : "ALTERNATE",
+    #V4L2_FIELD_INTERLACED_TB        : "INTERLACED TB",
+    #V4L2_FIELD_INTERLACED_BT        : "INTERLACED BT",
 }
 COLORSPACE_STR = {
     V4L2_COLORSPACE_SRGB            : "SRGB",
