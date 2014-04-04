$NetBSD: patch-tuntap__freebsd.c,v 1.1 2014/04/04 13:48:34 phonohawk Exp $

Hunk #2: FILE* fd will never be < 0.

Hunk #1, #2: tuntap_open() is calling a wrong function, leading to a
         linkage failure. This bug goes unnoticed if you are using GCC
         because the call of tun_close() is optimized out as the
         condition "fd < 0" never holds.

TODO: This patch should be sent to the upstream.

--- tuntap_freebsd.c.orig	2014-04-04 13:13:24.000000000 +0000
+++ tuntap_freebsd.c
@@ -19,8 +19,6 @@
 
 #ifdef __FreeBSD__
 
-void tun_close(tuntap_dev *device);
-
 /* ********************************** */
 
 #define N2N_FREEBSD_TAPDEVICE_SIZE 32
@@ -76,8 +74,8 @@ int tuntap_open(tuntap_dev *device /* ig
     /* traceEvent(TRACE_INFO, "%s", buf); */
 
     fd = popen(buf, "r");
-    if(fd < 0) {
-      tun_close(device);
+    if(fd == NULL) {
+      tuntap_close(device);
       return(-1);
     } else {
       int a, b, c, d, e, f;
