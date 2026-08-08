$NetBSD$

Add NetBSD.

--- src/vde_switch/tuntap.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_switch/tuntap.c
@@ -34,7 +34,7 @@
 #include <linux/if_tun.h>
 #endif
 
-#if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
+#if defined(VDE_DARWIN) || defined(VDE_FREEBSD) || defined(VDE_NETBSD)
 #define TAP_PREFIX "/dev/"
 #endif
 
@@ -202,7 +202,7 @@ int open_tap(char *dev)
 }
 #endif
 
-#if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
+#if defined(VDE_DARWIN) || defined(VDE_FREEBSD) || defined(VDE_NETBSD)
 int open_tap(char *dev)
 {
 	int fd;
