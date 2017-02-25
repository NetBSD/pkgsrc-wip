$NetBSD$
Add missing BSD detection
--- common/obj-backend-fs.c.orig	2017-01-31 22:19:02.911085207 +0000
+++ common/obj-backend-fs.c	2017-01-31 22:21:23.335671083 +0000
@@ -101,7 +101,7 @@
 static int
 fsync_obj_contents (int fd)
 {
-#ifdef __linux__
+#if defined( __linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD)
     /* Some file systems may not support fsync().
      * In this case, just skip the error.
      */
@@ -153,7 +153,7 @@
 static int
 rename_and_sync (const char *tmp_path, const char *obj_path)
 {
-#ifdef __linux__
+#if defined(__linux_) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     char *parent_dir;
     int ret = 0;
 
