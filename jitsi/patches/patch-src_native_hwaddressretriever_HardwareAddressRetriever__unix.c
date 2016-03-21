$NetBSD$

--- src/native/hwaddressretriever/HardwareAddressRetriever_unix.c.orig	2013-07-09 08:31:30.000000000 +0000
+++ src/native/hwaddressretriever/HardwareAddressRetriever_unix.c
@@ -26,7 +26,7 @@
 
 #include <net/if.h>
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__APPLE__)
 #include <ifaddrs.h>
 #include <net/if_dl.h>
 #include <net/route.h>
