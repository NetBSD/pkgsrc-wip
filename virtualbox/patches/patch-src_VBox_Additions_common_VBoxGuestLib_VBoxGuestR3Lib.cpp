$NetBSD$

--- src/VBox/Additions/common/VBoxGuestLib/VBoxGuestR3Lib.cpp.orig	2016-03-04 19:23:10.000000000 +0000
+++ src/VBox/Additions/common/VBoxGuestLib/VBoxGuestR3Lib.cpp
@@ -38,6 +38,7 @@
 
 #elif defined(RT_OS_DARWIN) \
    || defined(RT_OS_FREEBSD) \
+   || defined(RT_OS_NETBSD) \
    || defined(RT_OS_HAIKU) \
    || defined(RT_OS_LINUX) \
    || defined(RT_OS_SOLARIS)
@@ -252,7 +253,7 @@ static int vbglR3Init(const char *pszDev
 
 #else
 
-    /* The default implementation. (linux, solaris, freebsd, haiku) */
+    /* The default implementation. (linux, solaris, freebsd, netbsd, haiku) */
     RTFILE File;
     int rc = RTFileOpen(&File, pszDeviceName, RTFILE_O_READWRITE | RTFILE_O_OPEN | RTFILE_O_DENY_NONE);
     if (RT_FAILURE(rc))
@@ -394,7 +395,7 @@ int vbglR3DoIOCtl(unsigned iFunction, vo
     return RTErrConvertFromOS2(rc);
 
 #else
-# if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+# if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     VBGLBIGREQ Hdr;
     Hdr.u32Magic = VBGLBIGREQ_MAGIC;
     Hdr.cbData = cbData;
@@ -413,7 +414,7 @@ int vbglR3DoIOCtl(unsigned iFunction, vo
     NOREF(cbData);
 # endif
 
-# if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_DARWIN) || defined(RT_OS_LINUX)
+# if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined(RT_OS_NETBSD)
 #  ifdef VBOX_VBGLR3_XSERVER
     int rc = xf86ioctl((int)g_File, iFunction, pvData);
 #  else
@@ -444,4 +445,3 @@ int vbglR3DoIOCtl(unsigned iFunction, vo
 
 #endif
 }
-
