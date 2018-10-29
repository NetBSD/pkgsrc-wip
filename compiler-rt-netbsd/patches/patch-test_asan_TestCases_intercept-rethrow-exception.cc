$NetBSD$

--- test/asan/TestCases/intercept-rethrow-exception.cc.orig	2018-10-26 19:39:54.839975610 +0000
+++ test/asan/TestCases/intercept-rethrow-exception.cc
@@ -8,6 +8,9 @@
 // combination of libraries that are not used by default on NetBSD
 // XFAIL: netbsd
 
+// Not ported to NetBSD
+// XFAIL: netbsd
+
 #include <assert.h>
 #include <exception>
 #include <sanitizer/asan_interface.h>
