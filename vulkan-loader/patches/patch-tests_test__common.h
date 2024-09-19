$NetBSD$
* add netbsd support
--- tests/test_common.h.orig	2019-09-18 21:32:16.041186928 +0000
+++ tests/test_common.h
@@ -105,7 +105,7 @@ static inline void test_error_callback(c
     ADD_FAILURE_AT(file, line) << "Assertion: `" << expr << "'";
 }
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
     /* Linux-specific common code: */
 
 #include <pthread.h>
