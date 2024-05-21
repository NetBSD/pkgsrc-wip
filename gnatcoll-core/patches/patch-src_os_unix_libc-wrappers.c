$NetBSD: patch-src_os_unix_libc-wrappers.c,v 1.0 2024/05/10 23:00:00 dkazankov Exp $

Add NetBSD support

--- src/os/unix/libc-wrappers.c.orig	2023-09-21 18:57:14.000000000 +0300
+++ src/os/unix/libc-wrappers.c	2024-05-10 23:03:56.375549812 +0300
@@ -348,7 +348,7 @@
   if (result != NULL)
   {
      buf->inode = (uint_64) result->d_ino;
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
      buf->offset = 0;
 #else
      buf->offset = (uint_64) result->d_off;
