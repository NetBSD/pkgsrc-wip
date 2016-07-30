$NetBSD$

--- engine/source/platform/platformAL.h.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/platform/platformAL.h
@@ -35,7 +35,7 @@
 //Android uses openal soft from https://github.com/AerialX/openal-soft-android
 #include <AL/al.h>
 #include <AL/alc.h>
-#elif defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD)
+#elif defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_NETBSD)
 #include <AL/al.h>
 #include <AL/alc.h>
 #include "platform/eaxtypes.h"
