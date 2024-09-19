$NetBSD: patch-ZipArchive_ZipFile__stl.cpp,v 1.1.1.1 2011/05/12 12:13:39 ryo-on Exp $

* Support NetBSD

--- ZipArchive/ZipFile_stl.cpp.orig	2010-11-03 02:11:54.000000000 +0000
+++ ZipArchive/ZipFile_stl.cpp
@@ -16,7 +16,7 @@
 
 #if (defined _ZIP_IMPL_STL && (!defined _ZIP_FILE_IMPLEMENTATION || _ZIP_FILE_IMPLEMENTATION == ZIP_ZFI_DEFAULT)) || _ZIP_FILE_IMPLEMENTATION == ZIP_ZFI_STL
 
-#if defined __APPLE__ || defined __CYGWIN__
+#if defined __APPLE__ || defined __CYGWIN__ || defined __NetBSD__
 	#define FILE_FUNCTIONS_64B_BY_DEFAULT
 #else
 	#undef FILE_FUNCTIONS_64B_BY_DEFAULT	
