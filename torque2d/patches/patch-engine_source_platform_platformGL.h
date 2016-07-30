$NetBSD$

--- engine/source/platform/platformGL.h.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/platform/platformGL.h
@@ -26,7 +26,7 @@
 #include "platformOSX/platformGL.h"
 #elif defined(TORQUE_OS_WIN32)
 #include "platformWin32/platformGL.h"
-#elif defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_FREEBSD)
+#elif defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_FREEBSD) || defined(TORQUE_OS_NETBSD)
 #include "platformX86UNIX/platformGL.h"
 #elif defined(TORQUE_OS_IOS)
 #include "platformiOS/platformGL.h"
