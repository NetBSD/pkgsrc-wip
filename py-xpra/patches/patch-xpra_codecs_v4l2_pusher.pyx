$NetBSD$

--- xpra/codecs/v4l2/pusher.pyx.orig	2016-07-29 03:08:34.000000000 +0000
+++ xpra/codecs/v4l2/pusher.pyx
@@ -41,7 +41,7 @@ cdef extern from *:
 cdef extern from "sys/ioctl.h":
     int ioctl(int fd, unsigned long request, ...)
 
-cdef extern from "linux/videodev2.h":
+cdef extern from "./video.h":
     #define v4l2_fourcc(a,b,c,d)\
     #    (((__u32)(a)<<0)|((__u32)(b)<<8)|((__u32)(c)<<16)|((__u32)(d)<<24))
     int v4l2_fourcc(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
