$NetBSD$

--- lib/fuzzer/FuzzerLoop.cpp.orig	2018-05-10 23:16:36.000000000 +0000
+++ lib/fuzzer/FuzzerLoop.cpp
@@ -270,7 +270,7 @@ NO_SANITIZE_MEMORY
 void Fuzzer::AlarmCallback() {
   assert(Options.UnitTimeoutSec > 0);
   // In Windows Alarm callback is executed by a different thread.
-#if !LIBFUZZER_WINDOWS
+#if !LIBFUZZER_WINDOWS && !LIBFUZZER_NETBSD // XXX: why?
   if (!InFuzzingThread())
     return;
 #endif
