$NetBSD$

Have a case for netbsd.

--- src/vbox/vbox_XPCOMCGlue.c.orig	2018-09-26 11:26:50.994409695 +0000
+++ src/vbox/vbox_XPCOMCGlue.c
@@ -45,7 +45,7 @@
 VIR_LOG_INIT("vbox.vbox_XPCOMCGlue");
 
 #if defined(__linux__) || defined(__linux_gnu__) || defined(__sun__) || \
-    defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || \
     defined(__FreeBSD_kernel__)
 # define DYNLIB_NAME "VBoxXPCOMC.so"
 #elif defined(__APPLE__)
