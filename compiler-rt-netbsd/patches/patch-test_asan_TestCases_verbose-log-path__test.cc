$NetBSD$

--- test/asan/TestCases/verbose-log-path_test.cc.orig	2017-06-03 23:53:56.000000000 +0000
+++ test/asan/TestCases/verbose-log-path_test.cc
@@ -8,7 +8,7 @@
 // RUN: %env_asan_opts=log_path=%T/asan.log:log_exe_name=1 not %run %T/verbose-log-path_test-binary 2> %t.out
 // RUN: FileCheck %s --check-prefix=CHECK-ERROR < %T/asan.log.verbose-log-path_test-binary.*
 
-// FIXME: only FreeBSD and Linux have verbose log paths now.
+// FIXME: only FreeBSD, NetBSD and Linux have verbose log paths now.
 // XFAIL: win32,android
 // UNSUPPORTED: ios
 
