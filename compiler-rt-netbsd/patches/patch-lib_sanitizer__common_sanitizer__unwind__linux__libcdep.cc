$NetBSD$

--- lib/sanitizer_common/sanitizer_unwind_linux_libcdep.cc.orig	2017-06-03 23:53:57.000000000 +0000
+++ lib/sanitizer_common/sanitizer_unwind_linux_libcdep.cc
@@ -8,11 +8,11 @@
 //===----------------------------------------------------------------------===//
 //
 // This file contains the unwind.h-based (aka "slow") stack unwinding routines
-// available to the tools on Linux, Android, and FreeBSD.
+// available to the tools on Linux, Android, NetBSD and FreeBSD.
 //===----------------------------------------------------------------------===//
 
 #include "sanitizer_platform.h"
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 #include "sanitizer_common.h"
 #include "sanitizer_stacktrace.h"
 
@@ -78,7 +78,8 @@ void SanitizerInitializeUnwinder() {
 }
 #endif
 
-#ifdef __arm__
+#if defined(__arm__) && !SANITIZER_NETBSD
+// NetBSD uses dwarf EH
 #define UNWIND_STOP _URC_END_OF_STACK
 #define UNWIND_CONTINUE _URC_NO_REASON
 #else
@@ -165,4 +166,4 @@ void BufferedStackTrace::SlowUnwindStack
 
 }  // namespace __sanitizer
 
-#endif  // SANITIZER_FREEBSD || SANITIZER_LINUX
+#endif  // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
