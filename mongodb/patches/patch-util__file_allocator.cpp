$NetBSD: patch-util__file_allocator.cpp,v 1.2 2012/10/02 08:48:46 fhajny Exp $

Add support for NetBSD.
--- src/mongo/util/file_allocator.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/util/file_allocator.cpp
@@ -22,7 +22,7 @@
 #include <fcntl.h>
 #include <errno.h>
 
-#if defined(__freebsd__) || defined(__openbsd__)
+#if defined(__freebsd__) || defined(__netbsd__) || defined(__openbsd__)
 #   include <sys/stat.h>
 #endif
 
