$NetBSD$

--- src/VBox/HostDrivers/Support/SUPDrvInternal.h.orig	2016-03-04 19:29:24.000000000 +0000
+++ src/VBox/HostDrivers/Support/SUPDrvInternal.h
@@ -115,7 +115,7 @@
 
 #elif defined(RT_OS_OS2)
 
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #   define memset  libkern_memset /** @todo these are just hacks to get it compiling, check out later. */
 #   define memcmp  libkern_memcmp
 #   define strchr  libkern_strchr
@@ -995,4 +995,3 @@ const SUPDRVTRACERREG * VBOXCALL supdrvD
 RT_C_DECLS_END
 
 #endif
-
