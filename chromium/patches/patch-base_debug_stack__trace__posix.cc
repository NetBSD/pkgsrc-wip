$NetBSD: patch-base_debug_stack__trace__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/debug/stack_trace_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/debug/stack_trace_posix.cc
@@ -5,11 +5,16 @@
 #include "base/debug/stack_trace.h"
 
 #include <errno.h>
+#if !defined(OS_NETBSD)
 #include <execinfo.h>
+#endif
 #include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/stat.h>
+#if defined(OS_BSD)
+#include <sys/param.h>
+#endif
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -158,7 +163,12 @@ StackTrace::StackTrace() {
 #endif
   // Though the backtrace API man page does not list any possible negative
   // return values, we take no chance.
+#if !defined(OS_NETBSD)
   count_ = std::max(backtrace(trace_, arraysize(trace_)), 0);
+#else
+  count_ = 0;
+  return;
+#endif
 }
 
 void StackTrace::PrintBacktrace() {
