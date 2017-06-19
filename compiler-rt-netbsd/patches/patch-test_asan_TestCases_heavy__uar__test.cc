$NetBSD$

--- test/asan/TestCases/heavy_uar_test.cc.orig	2017-06-03 23:53:55.000000000 +0000
+++ test/asan/TestCases/heavy_uar_test.cc
@@ -49,7 +49,7 @@ int main(int argc, char **argv) {
     RecursiveFunctionWithStackFrame<2000>(depth);
     // The stack size is tight for the main thread in multithread
     // environment on FreeBSD.
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) // XXX: NetBSD?
     RecursiveFunctionWithStackFrame<5000>(depth);
     RecursiveFunctionWithStackFrame<10000>(depth);
 #endif
