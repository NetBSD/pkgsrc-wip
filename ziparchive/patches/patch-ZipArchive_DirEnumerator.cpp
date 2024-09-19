$NetBSD: patch-ZipArchive_DirEnumerator.cpp,v 1.1.1.1 2011/05/12 12:13:39 ryo-on Exp $

* Support NetBSD

--- ZipArchive/DirEnumerator.cpp.orig	2010-11-03 02:11:54.000000000 +0000
+++ ZipArchive/DirEnumerator.cpp
@@ -73,7 +73,7 @@ bool CDirEnumerator::Start(CFileFilter& 
 				if (!entry)
 					break;								
 				CZipString path(m_szCurrentDirectory + entry->d_name);
-	#if !defined __APPLE__ && !defined __CYGWIN__
+	#if !defined __APPLE__ && !defined __CYGWIN__ && !defined __NetBSD__
 				struct stat64 sStats;
 				if (stat64(path, &sStats) == -1)
 	#else
