$NetBSD$

--- test/asan/TestCases/heavy_uar_test.cc.orig	2018-08-21 21:25:29.000000000 +0000
+++ test/asan/TestCases/heavy_uar_test.cc
@@ -53,8 +53,8 @@ int main(int argc, char **argv) {
     RecursiveFunctionWithStackFrame<1024>(depth);
     RecursiveFunctionWithStackFrame<2000>(depth);
     // The stack size is tight for the main thread in multithread
-    // environment on FreeBSD.
-#if !defined(__FreeBSD__)
+    // environment on FreeBSD and NetBSD.
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
     RecursiveFunctionWithStackFrame<5000>(depth);
     RecursiveFunctionWithStackFrame<10000>(depth);
 #endif
