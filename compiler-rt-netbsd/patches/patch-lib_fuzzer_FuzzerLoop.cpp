$NetBSD$

--- lib/fuzzer/FuzzerLoop.cpp.orig	2018-06-01 09:39:33.000000000 +0000
+++ lib/fuzzer/FuzzerLoop.cpp
@@ -271,7 +271,7 @@ NO_SANITIZE_MEMORY
 void Fuzzer::AlarmCallback() {
   assert(Options.UnitTimeoutSec > 0);
   // In Windows Alarm callback is executed by a different thread.
-#if !LIBFUZZER_WINDOWS
+#if !LIBFUZZER_WINDOWS && !LIBFUZZER_NETBSD // XXX: why?
   if (!InFuzzingThread())
     return;
 #endif
