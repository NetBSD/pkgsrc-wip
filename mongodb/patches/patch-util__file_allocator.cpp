$NetBSD: patch-util__file_allocator.cpp,v 1.1 2012/02/22 11:36:27 bartoszkuzma Exp $

--- util/file_allocator.cpp.orig	2011-12-14 17:18:48.000000000 +0000
+++ util/file_allocator.cpp
@@ -19,7 +19,7 @@
 #include <fcntl.h>
 #include <errno.h>
 
-#if defined(__freebsd__) || defined(__openbsd__)
+#if defined(__freebsd__) || defined(__netbsd__) || defined(__openbsd__)
 #include <sys/stat.h>
 #endif
 
