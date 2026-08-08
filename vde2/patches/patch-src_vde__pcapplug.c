$NetBSD$

from https://github.com/virtualsquare/vde-2/issues/70

--- src/vde_pcapplug.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_pcapplug.c
@@ -32,7 +32,6 @@
 #include <libgen.h>
 #define _GNU_SOURCE
 #include <getopt.h>
-#include <pcap.h>
 #include <limits.h>
 
 #include <config.h>
@@ -40,11 +39,14 @@
 #include <vdecommon.h>
 #include <libvdeplug.h>
 
-#ifdef VDE_FREEBSD
+#if defined(VDE_FREEBSD) || defined(VDE_NETBSD)
+#include <net/bpf.h>
 #include <sys/socket.h>
 #endif
 
-#if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
+#include <pcap.h>
+
+#if defined(VDE_DARWIN) || defined(VDE_FREEBSD) || defined(VDE_NETBSD)
 #	if defined HAVE_SYSLIMITS_H
 #		include <syslimits.h>
 #	elif defined HAVE_SYS_SYSLIMITS_H
