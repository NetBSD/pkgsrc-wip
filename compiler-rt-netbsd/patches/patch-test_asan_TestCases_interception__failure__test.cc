$NetBSD$

--- test/asan/TestCases/interception_failure_test.cc.orig	2018-08-21 21:25:31.000000000 +0000
+++ test/asan/TestCases/interception_failure_test.cc
@@ -5,7 +5,7 @@
 // RUN: %clangxx_asan -O1 %s -o %t && %run %t 2>&1 | FileCheck %s
 // RUN: %clangxx_asan -O2 %s -o %t && %run %t 2>&1 | FileCheck %s
 // RUN: %clangxx_asan -O3 %s -o %t && %run %t 2>&1 | FileCheck %s
-// XFAIL: freebsd
+// XFAIL: freebsd, netbsd
 
 // On Windows, defining strtoll in a static build results in linker errors, but
 // it works with the dynamic runtime.
