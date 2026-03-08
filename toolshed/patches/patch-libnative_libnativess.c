$NetBSD$

Treat NetBSD like Linux.

--- libnative/libnativess.c.orig	2026-03-08 01:52:05.480487254 +0000
+++ libnative/libnativess.c
@@ -74,7 +74,7 @@ error_code _native_ss_size(native_path_i
 {
     error_code	ec = 0;
 
-#if defined(__APPLE__) || defined(WIN32) || defined(sun)
+#if defined(__APPLE__) || defined(WIN32) || defined(sun) || defined(__NetBSD__)
    ftruncate(path->fd->_file, size);
 #else
    ftruncate(path->fd->_fileno, size);
