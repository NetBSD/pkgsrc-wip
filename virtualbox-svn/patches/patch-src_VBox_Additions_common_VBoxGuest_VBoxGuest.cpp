$NetBSD$

--- src/VBox/Additions/common/VBoxGuest/VBoxGuest.cpp.orig	2016-03-04 19:23:09.000000000 +0000
+++ src/VBox/Additions/common/VBoxGuest/VBoxGuest.cpp
@@ -68,7 +68,7 @@
 # include <iprt/thread.h>
 #endif
 #include "version-generated.h"
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include "revision-generated.h"
 #endif
 #ifdef RT_OS_WINDOWS
@@ -3745,4 +3745,3 @@ bool VGDrvCommonISR(PVBOXGUESTDEVEXT pDe
     NOREF(rc);
     return fOurIrq;
 }
-
