$NetBSD$

Treat NetBSD like Linux.

--- libnative/libnativegs.c.orig	2026-03-08 01:49:42.164113292 +0000
+++ libnative/libnativegs.c
@@ -84,7 +84,7 @@ error_code _native_gs_fd(native_path_id 
     error_code	ec = 0;
 		
 
-#if defined(__APPLE__) || defined(WIN32) || defined(sun)
+#if defined(__APPLE__) || defined(WIN32) || defined(sun) || defined(__NetBSD__)
 	if (fstat(path->fd->_file, statbuf) < 0)
 #else
 	if (fstat(path->fd->_fileno, statbuf) < 0)
@@ -135,7 +135,7 @@ error_code _native_gs_size(native_path_i
 	struct stat statbuf;
 
         
-#if defined(__APPLE__) || defined(WIN32) || defined(sun)
+#if defined(__APPLE__) || defined(WIN32) || defined(sun) || defined(__NetBSD__)
 	if (fstat(path->fd->_file, &statbuf) < 0)
 #else
 	if (fstat(path->fd->_fileno, &statbuf) < 0)
