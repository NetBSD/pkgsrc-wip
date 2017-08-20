$NetBSD$

--- lib/tsan/tests/rtl/tsan_test_util_posix.cc.orig	2017-07-04 05:53:21.000000000 +0000
+++ lib/tsan/tests/rtl/tsan_test_util_posix.cc
@@ -9,7 +9,7 @@
 //
 // This file is a part of ThreadSanitizer (TSan), a race detector.
 //
-// Test utils, Linux, FreeBSD and Darwin implementation.
+// Test utils, Linux, FreeBSD, NetBSD and Darwin implementation.
 //===----------------------------------------------------------------------===//
 
 #include "sanitizer_common/sanitizer_atomic.h"
@@ -270,7 +270,7 @@ void ScopedThread::Impl::HandleEvent(Eve
       }
     }
     CHECK_NE(tsan_mop, 0);
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
     const int ErrCode = ESOCKTNOSUPPORT;
 #else
     const int ErrCode = ECHRNG;
