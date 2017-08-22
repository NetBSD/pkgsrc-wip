$NetBSD$

--- lib/fuzzer/FuzzerDefs.h.orig	2017-08-21 23:23:37.000000000 +0000
+++ lib/fuzzer/FuzzerDefs.h
@@ -23,14 +23,22 @@
 #ifdef __linux__
 #define LIBFUZZER_APPLE 0
 #define LIBFUZZER_LINUX 1
+#define LIBFUZZER_NETBSD 0
 #define LIBFUZZER_WINDOWS 0
 #elif __APPLE__
 #define LIBFUZZER_APPLE 1
 #define LIBFUZZER_LINUX 0
+#define LIBFUZZER_NETBSD 0
+#define LIBFUZZER_WINDOWS 0
+#elif __NetBSD__
+#define LIBFUZZER_APPLE 0
+#define LIBFUZZER_LINUX 0
+#define LIBFUZZER_NETBSD 1
 #define LIBFUZZER_WINDOWS 0
 #elif _WIN32
 #define LIBFUZZER_APPLE 0
 #define LIBFUZZER_LINUX 0
+#define LIBFUZZER_NETBSD 0
 #define LIBFUZZER_WINDOWS 1
 #else
 #error "Support for your platform has not been implemented"
