$NetBSD$

# libsysinfo not available in dreckly yet

--- src/vsearch.h.orig	2025-03-02 14:06:13.019197000 +0000
+++ src/vsearch.h
@@ -163,7 +163,8 @@
 #elif __FreeBSD__
 
 #define PROG_OS "freebsd"
-#include <sys/sysinfo.h>
+// Only available via FreeBSD ports at this time
+// #include <sys/sysinfo.h>
 #include <sys/resource.h>
 #include <sys/endian.h>
 #define bswap_16(x) bswap16(x)
