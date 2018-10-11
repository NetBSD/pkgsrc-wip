$NetBSD$

--- test/asan/TestCases/intercept-rethrow-exception.cc.orig	2018-08-21 21:25:30.000000000 +0000
+++ test/asan/TestCases/intercept-rethrow-exception.cc
@@ -4,6 +4,9 @@
 // RUN: %clangxx_asan -fexceptions -O0 %s -o %t
 // RUN: %run %t
 
+// Not ported to NetBSD
+// XFAIL: netbsd
+
 #include <assert.h>
 #include <exception>
 #include <sanitizer/asan_interface.h>
