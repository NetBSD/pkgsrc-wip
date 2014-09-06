$NetBSD: patch-common_SC__DirUtils.cpp,v 1.1 2014/09/06 22:22:36 thomasklausner Exp $

Add NetBSD support.

--- common/SC_DirUtils.cpp.orig	2013-11-27 12:54:02.000000000 +0000
+++ common/SC_DirUtils.cpp
@@ -148,7 +148,7 @@ bool sc_IsNonHostPlatformDir(const char 
 	const char a[] = "linux", b[] = "windows", c[]="iphone";
 #elif defined(__linux__)
 	const char a[] = "osx", b[] = "windows", c[]="iphone";
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 	const char a[] = "osx", b[] = "windows", c[]="iphone";
 #elif defined(_WIN32)
 	const char a[] = "osx", b[] = "linux", c[]="iphone";
