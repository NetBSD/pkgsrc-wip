$NetBSD$

--- test/msan/signal_stress_test.cc.orig	2018-08-21 21:25:23.000000000 +0000
+++ test/msan/signal_stress_test.cc
@@ -2,6 +2,9 @@
 //
 // Test that va_arg shadow from a signal handler does not leak outside.
 
+// Reported deadly signal due to stack-overflow
+// XFAIL: netbsd
+
 #include <signal.h>
 #include <stdarg.h>
 #include <sanitizer/msan_interface.h>
