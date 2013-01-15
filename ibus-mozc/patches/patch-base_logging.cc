$NetBSD: patch-base_logging.cc,v 1.3 2013/01/15 12:31:35 ryo-on Exp $

--- base/logging.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/logging.cc
@@ -106,12 +106,7 @@ string Logging::GetLogMessageHeader() {
   char buf[512];
   snprintf(buf, sizeof(buf),
            "%4.4d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d %u "
-#if !defined(OS_LINUX) || defined(__native_client__)
-// = OS_WINDOWS or OS_MACOSX or __native_client__
-           "%u",
-#else
            "%lu",
-#endif
            1900 + tm_time.tm_year,
            1 + tm_time.tm_mon,
            tm_time.tm_mday,
@@ -124,6 +119,9 @@ string Logging::GetLogMessageHeader() {
 #elif defined(OS_MACOSX)
            ::getpid(),
            reinterpret_cast<uint32>(pthread_self())
+#elif defined*OS_NETBSD)
+           ::getpid()
+           _lwp_self()
 #else  // = OS_LINUX
            ::getpid(),
            // In NaCl it returns uint32, otherwise it returns unsigned long.
