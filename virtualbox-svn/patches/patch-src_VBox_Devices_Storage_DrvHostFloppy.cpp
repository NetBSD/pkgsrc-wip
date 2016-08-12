$NetBSD$

--- src/VBox/Devices/Storage/DrvHostFloppy.cpp.orig	2016-08-05 16:42:58.000000000 +0000
+++ src/VBox/Devices/Storage/DrvHostFloppy.cpp
@@ -35,7 +35,7 @@
 #elif defined(RT_OS_L4)
 
 #else /* !RT_OS_WINDOWS nor RT_OS_LINUX nor RT_OS_L4 */
-# error "Unsupported Platform."
+//# error "Unsupported Platform."
 #endif /* !RT_OS_WINDOWS nor RT_OS_LINUX nor RT_OS_L4 */
 
 #include <VBox/vmm/pdmdrv.h>
@@ -287,4 +287,3 @@ const PDMDRVREG g_DrvHostFloppy =
     /* u32EndVersion */
     PDM_DRVREG_VERSION
 };
-
