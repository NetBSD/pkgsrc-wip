$NetBSD: patch-util__file_allocator.cpp,v 1.3 2013/08/28 16:52:43 fhajny Exp $

Add support for NetBSD.
--- src/mongo/util/file_allocator.cpp.orig	2013-08-18 18:24:57.000000000 +0000
+++ src/mongo/util/file_allocator.cpp
@@ -24,7 +24,7 @@
 #include <errno.h>
 #include <fcntl.h>
 
-#if defined(__freebsd__) || defined(__openbsd__)
+#if defined(__freebsd__) || defined(__netbsd__) || defined(__openbsd__)
 #   include <sys/stat.h>
 #endif
 
