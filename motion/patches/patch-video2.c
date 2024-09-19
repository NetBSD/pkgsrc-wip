$NetBSD$

Portability: Fix defination to match ioctl 

--- video2.c.orig	2016-10-25 02:39:24.000000000 +0100
+++ video2.c	2017-06-10 15:28:04.000000000 +0100
@@ -184,7 +184,7 @@
 /**
  * xioctl
  */
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 static int xioctl(src_v4l2_t *vid_source, unsigned long request, void *arg)
 #else
 static int xioctl(src_v4l2_t *vid_source, int request, void *arg)
