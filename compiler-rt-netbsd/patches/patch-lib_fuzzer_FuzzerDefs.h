$NetBSD$

--- lib/fuzzer/FuzzerDefs.h.orig	2017-08-28 21:09:44.000000000 +0000
+++ lib/fuzzer/FuzzerDefs.h
@@ -25,14 +25,22 @@
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
@@ -42,7 +50,7 @@
 #  define __has_attribute(x) 0
 #endif
 
-#define LIBFUZZER_POSIX LIBFUZZER_APPLE || LIBFUZZER_LINUX
+#define LIBFUZZER_POSIX (LIBFUZZER_APPLE || LIBFUZZER_LINUX || LIBFUZZER_NETBSD)
 
 #ifdef __x86_64
 #  if __has_attribute(target)
