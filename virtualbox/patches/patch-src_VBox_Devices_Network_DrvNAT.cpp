$NetBSD$

--- src/VBox/Devices/Network/DrvNAT.cpp.orig	2016-03-04 19:27:54.000000000 +0000
+++ src/VBox/Devices/Network/DrvNAT.cpp
@@ -51,7 +51,7 @@ extern "C" {
 # include <poll.h>
 # include <errno.h>
 #endif
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <netinet/in.h>
 #endif
 #include <iprt/semaphore.h>
@@ -1752,4 +1752,3 @@ const PDMDRVREG g_DrvNAT =
     /* u32EndVersion */
     PDM_DRVREG_VERSION
 };
-
