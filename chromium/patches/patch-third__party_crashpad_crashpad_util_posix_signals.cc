$NetBSD$

--- third_party/crashpad/crashpad/util/posix/signals.cc.orig	2020-07-15 18:56:30.000000000 +0000
+++ third_party/crashpad/crashpad/util/posix/signals.cc
@@ -46,7 +46,7 @@ constexpr int kCrashSignals[] = {
 #if defined(SIGEMT)
     SIGEMT,
 #endif  // defined(SIGEMT)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     SIGXCPU,
     SIGXFSZ,
 #endif  // defined(OS_LINUX)
@@ -86,7 +86,7 @@ constexpr int kTerminateSignals[] = {
     SIGXCPU,
     SIGXFSZ,
 #endif  // defined(OS_MACOSX)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     SIGIO,
 #endif  // defined(OS_LINUX)
 };
