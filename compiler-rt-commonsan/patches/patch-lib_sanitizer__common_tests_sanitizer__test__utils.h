$NetBSD$

--- lib/sanitizer_common/tests/sanitizer_test_utils.h.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/sanitizer_common/tests/sanitizer_test_utils.h
@@ -101,7 +101,7 @@ static inline uint32_t my_rand() {
 # define SANITIZER_TEST_HAS_POSIX_MEMALIGN 0
 #endif
 
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && \
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
     !defined(__ANDROID__) && !defined(_WIN32)
 # define SANITIZER_TEST_HAS_MEMALIGN 1
 # define SANITIZER_TEST_HAS_PVALLOC 1
@@ -118,7 +118,7 @@ static inline uint32_t my_rand() {
 # define SANITIZER_TEST_HAS_STRNLEN 0
 #endif
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 # define SANITIZER_TEST_HAS_PRINTF_L 1
 #else
 # define SANITIZER_TEST_HAS_PRINTF_L 0
