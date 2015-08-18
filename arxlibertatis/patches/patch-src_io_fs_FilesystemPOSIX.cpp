$NetBSD: patch-src_io_fs_FilesystemPOSIX.cpp,v 1.1 2015/08/18 20:14:58 yhardy Exp $

Wrong errno.h include

--- src/io/fs/FilesystemPOSIX.cpp.orig	2013-07-15 20:56:44.000000000 +0200
+++ src/io/fs/FilesystemPOSIX.cpp	2013-07-15 20:57:15.000000000 +0200
@@ -27,7 +27,7 @@
 #include <cstdlib>
 
 #include <sys/stat.h>
-#include <sys/errno.h>
+#include <errno.h>
 #include <dirent.h>
 #include <unistd.h>
 
