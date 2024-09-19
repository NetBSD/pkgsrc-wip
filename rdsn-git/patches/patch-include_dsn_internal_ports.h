$NetBSD$

--- include/dsn/internal/ports.h.orig	2016-02-27 19:59:48.000000000 +0000
+++ include/dsn/internal/ports.h
@@ -44,7 +44,7 @@ __pragma(warning(disable:4127))
 # define __thread __declspec(thread)
 # define __selectany __declspec(selectany) extern 
 
-# elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+# elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 # include <unistd.h>
 
@@ -120,4 +120,3 @@ namespace dsn 
 # define snprintf_p std::snprintf
 # endif
 # endif
-
