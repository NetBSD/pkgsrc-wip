$NetBSD$

--- engine/source/platform/platformFileIO.h.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/platform/platformFileIO.h
@@ -26,7 +26,7 @@
 #include "platform/platform.h"
 #endif
 
-#if defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD)
+#if defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_NETBSD)
 // Need to remove this once Xlib stops leaking
 #undef Status
 #endif
