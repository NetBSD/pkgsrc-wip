$NetBSD$

--- src/VBox/Devices/build/VBoxDD.cpp.orig	2016-03-04 19:28:26.000000000 +0000
+++ src/VBox/Devices/build/VBoxDD.cpp
@@ -222,7 +222,7 @@ extern "C" DECLEXPORT(int) VBoxDriversRe
     rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvVD);
     if (RT_FAILURE(rc))
         return rc;
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_WINDOWS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_WINDOWS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvHostDVD);
     if (RT_FAILURE(rc))
         return rc;
@@ -241,7 +241,7 @@ extern "C" DECLEXPORT(int) VBoxDriversRe
     rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvNAT);
     if (RT_FAILURE(rc))
         return rc;
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvHostInterface);
     if (RT_FAILURE(rc))
         return rc;
@@ -296,7 +296,7 @@ extern "C" DECLEXPORT(int) VBoxDriversRe
     if (RT_FAILURE(rc))
         return rc;
 #endif /* RT_OS_LINUX */
-#if defined(RT_OS_FREEBSD)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvHostOSSAudio);
     if (RT_FAILURE(rc))
         return rc;
@@ -344,7 +344,7 @@ extern "C" DECLEXPORT(int) VBoxDriversRe
     if (RT_FAILURE(rc))
         return rc;
 #endif
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_WINDOWS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_WINDOWS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvHostSerial);
     if (RT_FAILURE(rc))
         return rc;
