$NetBSD$

Add NetBSD.

--- src/vde_plug2tap.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_plug2tap.c
@@ -34,13 +34,13 @@
 #include <linux/if_tun.h>
 #endif
 
-#ifdef VDE_FREEBSD
+#if defined(VDE_FREEBSD) || defined(VDE_NETNSD)
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_tun.h>
 #endif
 
-#if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
+#if defined(VDE_DARWIN) || defined(VDE_FREEBSD) || defined(VDE_NETBSD)
 #	define TAP_PREFIX "/dev/"
 #	if defined HAVE_SYSLIMITS_H
 #		include <syslimits.h>
@@ -195,7 +195,7 @@ int open_tap(char *dev)
 }
 #endif
 
-#if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
+#if defined(VDE_DARWIN) || defined(VDE_FREEBSD) || defined(VDE_NETBSD)
 int open_tap(char *dev)
 {
 	int fd;
