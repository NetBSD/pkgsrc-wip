$NetBSD$

--- lib/fuzzer/FuzzerExtraCounters.cpp.orig	2017-08-21 23:23:37.000000000 +0000
+++ lib/fuzzer/FuzzerExtraCounters.cpp
@@ -11,7 +11,7 @@
 
 #include "FuzzerDefs.h"
 
-#if LIBFUZZER_LINUX
+#if LIBFUZZER_LINUX || LIBFUZZER_NETBSD
 __attribute__((weak)) extern uint8_t __start___libfuzzer_extra_counters;
 __attribute__((weak)) extern uint8_t __stop___libfuzzer_extra_counters;
 
