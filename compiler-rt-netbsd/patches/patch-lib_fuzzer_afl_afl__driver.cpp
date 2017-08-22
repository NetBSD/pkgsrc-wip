$NetBSD$

--- lib/fuzzer/afl/afl_driver.cpp.orig	2017-08-21 23:23:37.000000000 +0000
+++ lib/fuzzer/afl/afl_driver.cpp
@@ -68,9 +68,15 @@ statistics from the file. If that fails 
 #ifdef __linux__
 #define LIBFUZZER_LINUX 1
 #define LIBFUZZER_APPLE 0
+#define LIBFUZZER_NETBSD 0
 #elif __APPLE__
 #define LIBFUZZER_LINUX 0
 #define LIBFUZZER_APPLE 1
+#define LIBFUZZER_NETBSD 0
+#elif __NetBSD__
+#define LIBFUZZER_LINUX 0
+#define LIBFUZZER_APPLE 0
+#define LIBFUZZER_NETBSD 1
 #else
 #error "Support for your platform has not been implemented"
 #endif
@@ -119,7 +125,7 @@ size_t GetPeakRSSMb() {
   struct rusage usage;
   if (getrusage(RUSAGE_SELF, &usage))
     return 0;
-  if (LIBFUZZER_LINUX) {
+  if (LIBFUZZER_LINUX || LIBFUZZER_NETBSD) {
     // ru_maxrss is in KiB
     return usage.ru_maxrss >> 10;
   } else if (LIBFUZZER_APPLE) {
