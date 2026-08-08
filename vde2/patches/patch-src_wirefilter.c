$NetBSD$

Add NetBSD.

--- src/wirefilter.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/wirefilter.c
@@ -39,7 +39,7 @@
 #include <vdecommon.h>
 #include <libvdeplug.h>
 
-#if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
+#if defined(VDE_DARWIN) || defined(VDE_FREEBSD) || defined(VDE_NETBSD)
 #	if defined HAVE_SYSLIMITS_H
 #		include <syslimits.h>
 #	elif defined HAVE_SYS_SYSLIMITS_H
