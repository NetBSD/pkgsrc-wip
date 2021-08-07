$NetBSD$

Include <sys/file.h> for LOCK_* (needed for musl-libc).

--- lib/device/dev-cache.c.orig	2021-05-07 21:14:09.000000000 +0000
+++ lib/device/dev-cache.c
@@ -29,6 +29,7 @@
 #include <unistd.h>
 #include <dirent.h>
 #include <locale.h>
+#include <sys/file.h>
 
 struct dev_iter {
 	struct btree_iter *current;
