$NetBSD$

--- src/VBox/HostDrivers/Support/SUPDrv.cpp.orig	2016-03-04 19:29:24.000000000 +0000
+++ src/VBox/HostDrivers/Support/SUPDrv.cpp
@@ -54,7 +54,7 @@
 #include <iprt/crc.h>
 #include <iprt/string.h>
 #include <iprt/timer.h>
-#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <iprt/rand.h>
 # include <iprt/path.h>
 #endif
@@ -456,7 +456,7 @@ static SUPFUNC g_aFunctions[] =
 /* SED: END */
 };
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 /**
  * Drag in the rest of IRPT since we share it with the
  * rest of the kernel modules on darwin.
@@ -469,7 +469,7 @@ PFNRT g_apfnVBoxDrvIPRTDeps[] =
     (PFNRT)RTPathStripFilename,
     NULL
 };
-#endif  /* RT_OS_DARWIN || RT_OS_SOLARIS || RT_OS_SOLARIS */
+#endif  /* RT_OS_DARWIN || RT_OS_SOLARIS || RT_OS_SOLARIS || RT_OS_NETBSD */
 
 
 /**
@@ -5719,4 +5719,3 @@ static int supdrvIOCtl_ResumeSuspendedKb
     return VERR_NOT_IMPLEMENTED;
 #endif
 }
-
