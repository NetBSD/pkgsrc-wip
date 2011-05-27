$NetBSD: patch-testing_gtest_src_gtest.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- testing/gtest/src/gtest.cc.orig	2011-05-24 08:20:42.000000000 +0000
+++ testing/gtest/src/gtest.cc
@@ -59,6 +59,7 @@
 // Declares vsnprintf().  This header is not available on Windows.
 #include <strings.h>  // NOLINT
 #include <sys/mman.h>  // NOLINT
+#include <sys/socket.h>  // NOLINT
 #include <sys/time.h>  // NOLINT
 #include <unistd.h>  // NOLINT
 #include <string>
@@ -1612,7 +1613,7 @@ bool String::CaseInsensitiveWideCStringE
 
 #if GTEST_OS_WINDOWS
   return _wcsicmp(lhs, rhs) == 0;
-#elif GTEST_OS_LINUX
+#elif GTEST_OS_LINUX && !defined(__DragonFly__)
   return wcscasecmp(lhs, rhs) == 0;
 #else
   // Mac OS X and Cygwin don't define wcscasecmp.  Other unknown OSes
