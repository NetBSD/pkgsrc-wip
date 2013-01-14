$NetBSD: patch-base_logging.cc,v 1.1 2013/01/14 06:21:30 ryo-on Exp $

* I am not sure.

--- base/logging.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/logging.cc
@@ -59,6 +59,10 @@
 #include "base/singleton.h"
 #include "base/util.h"
 
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
+
 DEFINE_bool(colored_log, true, "Enables colored log messages on tty devices");
 DEFINE_bool(logtostderr,
             false,
@@ -124,6 +128,9 @@ string Logging::GetLogMessageHeader() {
 #elif defined(OS_MACOSX)
            ::getpid(),
            reinterpret_cast<uint32>(pthread_self())
+#elif defined(__NetBSD__)
+	   ::getpid(),
+	   (long unsigned int) _lwp_self()
 #else  // = OS_LINUX
            ::getpid(),
            // In NaCl it returns uint32, otherwise it returns unsigned long.
