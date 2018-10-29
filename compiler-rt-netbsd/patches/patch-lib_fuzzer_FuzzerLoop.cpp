$NetBSD$

--- lib/fuzzer/FuzzerLoop.cpp.orig	2018-10-26 19:38:37.382745571 +0000
+++ lib/fuzzer/FuzzerLoop.cpp
@@ -275,7 +275,7 @@ NO_SANITIZE_MEMORY
 void Fuzzer::AlarmCallback() {
   assert(Options.UnitTimeoutSec > 0);
   // In Windows Alarm callback is executed by a different thread.
-#if !LIBFUZZER_WINDOWS
+#if !LIBFUZZER_WINDOWS && !LIBFUZZER_NETBSD // XXX: why?
   if (!InFuzzingThread())
     return;
 #endif
