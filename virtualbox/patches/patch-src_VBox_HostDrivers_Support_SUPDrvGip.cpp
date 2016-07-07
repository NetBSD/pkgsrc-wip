$NetBSD$

--- src/VBox/HostDrivers/Support/SUPDrvGip.cpp.orig	2016-03-04 19:29:24.000000000 +0000
+++ src/VBox/HostDrivers/Support/SUPDrvGip.cpp
@@ -51,7 +51,7 @@
 #include <iprt/crc.h>
 #include <iprt/string.h>
 #include <iprt/timer.h>
-#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <iprt/rand.h>
 # include <iprt/path.h>
 #endif
@@ -4894,4 +4894,3 @@ int VBOXCALL supdrvIOCtl_GipSetFlags(PSU
 #endif
     return rc;
 }
-
