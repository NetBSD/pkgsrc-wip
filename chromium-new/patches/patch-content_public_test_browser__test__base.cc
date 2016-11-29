$NetBSD$

--- content/public/test/browser_test_base.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/public/test/browser_test_base.cc
@@ -6,6 +6,10 @@
 
 #include <stddef.h>
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #include "base/bind.h"
 #include "base/command_line.h"
 #include "base/debug/stack_trace.h"
