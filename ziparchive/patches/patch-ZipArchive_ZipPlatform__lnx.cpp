$NetBSD: patch-ZipArchive_ZipPlatform__lnx.cpp,v 1.1.1.1 2011/05/12 12:13:39 ryo-on Exp $

*Support NetBSD

--- ZipArchive/ZipPlatform_lnx.cpp.orig	2010-11-03 02:11:54.000000000 +0000
+++ ZipArchive/ZipPlatform_lnx.cpp
@@ -16,7 +16,7 @@
 
 #ifdef _ZIP_SYSTEM_LINUX
 
-#if defined __APPLE__ || defined __CYGWIN__
+#if defined __APPLE__ || defined __CYGWIN__ || defined __NetBSD__
 	#define FILE_FUNCTIONS_64B_BY_DEFAULT
 #else
 	#undef FILE_FUNCTIONS_64B_BY_DEFAULT	
@@ -34,7 +34,7 @@
 
 #include <sys/types.h>
 
-#if defined (__FreeBSD__) || defined (__APPLE__)
+#if defined (__FreeBSD__) || defined (__APPLE__) || defined (__NetBSD__)
 	#include <sys/param.h>
 	#include <sys/mount.h>
 #else
@@ -47,6 +47,11 @@
 
 #include <fcntl.h>
 
+#if defined (__NetBSD__)
+	#include <sys/types.h>
+	#include <sys/statvfs.h>
+#endif
+
 const TCHAR CZipPathComponent::m_cSeparator = _T('/');
 
 #ifndef _UTIMBUF_DEFINED
@@ -60,9 +65,13 @@ const TCHAR CZipPathComponent::m_cSepara
 //////////////////////////////////////////////////////////////////////
 ULONGLONG ZipPlatform::GetDeviceFreeSpace(LPCTSTR lpszPath)
 {
+	#if !defined (__NetBSD__)
 	struct statfs sStats;
+	#else
+	struct statvfs sStats;
+	#endif
 
-	#if defined (__SVR4) && defined (__sun)
+	#if (defined (__SVR4) && defined (__sun)) || defined (__NetBSD__)
 		if (statvfs(lpszPath, &sStats) == -1) // Solaris
 	#else
 		if (statfs(lpszPath, &sStats) == -1)
