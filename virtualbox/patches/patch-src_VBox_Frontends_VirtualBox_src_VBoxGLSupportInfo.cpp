$NetBSD$

--- src/VBox/Frontends/VirtualBox/src/VBoxGLSupportInfo.cpp.orig	2016-03-04 19:29:07.000000000 +0000
+++ src/VBox/Frontends/VirtualBox/src/VBoxGLSupportInfo.cpp
@@ -605,7 +605,7 @@ bool VBoxVHWAInfo::isVHWASupported() con
 /* static */
 bool VBoxVHWAInfo::checkVHWASupport()
 {
-#if defined(RT_OS_WINDOWS) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_WINDOWS) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     static char pszVBoxPath[RTPATH_MAX];
     const char *papszArgs[] = { NULL, "-test", "2D", NULL};
     int rc;
@@ -702,4 +702,3 @@ const class QGLContext * VBoxGLTmpContex
     }
     return NULL;
 }
-
