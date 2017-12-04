$NetBSD$

--- lib/msan/msan_interceptors.cc.orig	2017-12-04 13:03:32.091928090 +0000
+++ lib/msan/msan_interceptors.cc
@@ -152,9 +152,14 @@ INTERCEPTOR(SSIZE_T, readlink, const cha
   return res;
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(void *, mempcpy, void *dest, const void *src, SIZE_T n) {
   return (char *)__msan_memcpy(dest, src, n) + n;
 }
+#define MSAN_MAYBE_INTERCEPT_MEMPCPY INTERCEPT_FUNCTION(mempcpy)
+#else
+#define MSAN_MAYBE_INTERCEPT_MEMPCPY
+#endif
 
 INTERCEPTOR(void *, memccpy, void *dest, const void *src, int c, SIZE_T n) {
   ENSURE_MSAN_INITED();
@@ -194,6 +199,7 @@ INTERCEPTOR(void *, aligned_alloc, SIZE_
   return msan_aligned_alloc(alignment, size, &stack);
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(void *, __libc_memalign, SIZE_T alignment, SIZE_T size) {
   GET_MALLOC_STACK_TRACE;
   void *ptr = msan_memalign(alignment, size, &stack);
@@ -201,6 +207,10 @@ INTERCEPTOR(void *, __libc_memalign, SIZ
     DTLS_on_libc_memalign(ptr, size);
   return ptr;
 }
+#define MSAN_MAYBE_INTERCEPT___LIBC_MEMALIGN INTERCEPT_FUNCTION(__libc_memalign)
+#else
+#define MSAN_MAYBE_INTERCEPT___LIBC_MEMALIGN
+#endif
 
 INTERCEPTOR(void *, valloc, SIZE_T size) {
   GET_MALLOC_STACK_TRACE;
@@ -234,9 +244,15 @@ INTERCEPTOR(void, cfree, void *ptr) {
 #define MSAN_MAYBE_INTERCEPT_CFREE
 #endif
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(uptr, malloc_usable_size, void *ptr) {
   return __sanitizer_get_allocated_size(ptr);
 }
+#define MSAN_MAYBE_INTERCEPT_MALLOC_USABLE_SIZE \
+  INTERCEPT_FUNCTION(malloc_usable_size)
+#else
+#define MSAN_MAYBE_INTERCEPT_MALLOC_USABLE_SIZE
+#endif
 
 #if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 // This function actually returns a struct by value, but we can't unpoison a
@@ -297,6 +313,7 @@ INTERCEPTOR(char *, strncpy, char *dest,
   return res;
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(char *, stpcpy, char *dest, const char *src) {  // NOLINT
   ENSURE_MSAN_INITED();
   GET_STORE_STACK_TRACE;
@@ -306,6 +323,10 @@ INTERCEPTOR(char *, stpcpy, char *dest, 
   CopyShadowAndOrigin(dest, src, n + 1, &stack);
   return res;
 }
+#define MSAN_MAYBE_INTERCEPT_STPCPY INTERCEPT_FUNCTION(stpcpy)
+#else
+#define MSAN_MAYBE_INTERCEPT_STPCPY
+#endif
 
 INTERCEPTOR(char *, strdup, char *src) {
   ENSURE_MSAN_INITED();
@@ -334,6 +355,7 @@ INTERCEPTOR(char *, __strdup, char *src)
 #define MSAN_MAYBE_INTERCEPT___STRDUP
 #endif
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(char *, gcvt, double number, SIZE_T ndigit, char *buf) {
   ENSURE_MSAN_INITED();
   char *res = REAL(gcvt)(number, ndigit, buf);
@@ -341,6 +363,10 @@ INTERCEPTOR(char *, gcvt, double number,
   __msan_unpoison(buf, n + 1);
   return res;
 }
+#define MSAN_MAYBE_INTERCEPT_GCVT INTERCEPT_FUNCTION(gcvr)
+#else
+#define MSAN_MAYBE_INTERCEPT_GCVT
+#endif
 
 INTERCEPTOR(char *, strcat, char *dest, const char *src) {  // NOLINT
   ENSURE_MSAN_INITED();
@@ -554,6 +580,7 @@ INTERCEPTOR(wchar_t *, wmemcpy, wchar_t 
   return res;
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(wchar_t *, wmempcpy, wchar_t *dest, const wchar_t *src, SIZE_T n) {
   ENSURE_MSAN_INITED();
   GET_STORE_STACK_TRACE;
@@ -561,6 +588,10 @@ INTERCEPTOR(wchar_t *, wmempcpy, wchar_t
   CopyShadowAndOrigin(dest, src, n * sizeof(wchar_t), &stack);
   return res;
 }
+#define MSAN_MAYBE_INTERCEPT_WMEMPCPY INTERCEPT_FUNCTION(wmempcpy)
+#else
+#define MSAN_MAYBE_INTERCEPT_WMEMPCPY
+#endif
 
 INTERCEPTOR(wchar_t *, wmemset, wchar_t *s, wchar_t c, SIZE_T n) {
   CHECK(MEM_IS_APP(s));
@@ -594,6 +625,7 @@ INTERCEPTOR(int, gettimeofday, void *tv,
   return res;
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(char *, fcvt, double x, int a, int *b, int *c) {
   ENSURE_MSAN_INITED();
   char *res = REAL(fcvt)(x, a, b, c);
@@ -602,6 +634,10 @@ INTERCEPTOR(char *, fcvt, double x, int 
   if (res) __msan_unpoison(res, REAL(strlen)(res) + 1);
   return res;
 }
+#define MSAN_MAYBE_INTERCEPT_FCVT INTERCEPT_FUNCTION(fcvr)
+#else
+#define MSAN_MAYBE_INTERCEPT_FCVT
+#endif
 
 INTERCEPTOR(char *, getenv, char *name) {
   if (msan_init_is_running)
@@ -1512,7 +1548,7 @@ void InitializeInterceptors() {
   MSAN_MAYBE_INTERCEPT_MMAP64;
   INTERCEPT_FUNCTION(posix_memalign);
   MSAN_MAYBE_INTERCEPT_MEMALIGN;
-  INTERCEPT_FUNCTION(__libc_memalign);
+  MSAN_MAYBE_INTERCEPT___LIBC_MEMALIGN;
   INTERCEPT_FUNCTION(valloc);
   MSAN_MAYBE_INTERCEPT_PVALLOC;
   INTERCEPT_FUNCTION(malloc);
@@ -1520,7 +1556,7 @@ void InitializeInterceptors() {
   INTERCEPT_FUNCTION(realloc);
   INTERCEPT_FUNCTION(free);
   MSAN_MAYBE_INTERCEPT_CFREE;
-  INTERCEPT_FUNCTION(malloc_usable_size);
+  MSAN_MAYBE_INTERCEPT_MALLOC_USABLE_SIZE;
   MSAN_MAYBE_INTERCEPT_MALLINFO;
   MSAN_MAYBE_INTERCEPT_MALLOPT;
   MSAN_MAYBE_INTERCEPT_MALLOC_STATS;
@@ -1528,18 +1564,18 @@ void InitializeInterceptors() {
   MSAN_MAYBE_INTERCEPT_FREAD_UNLOCKED;
   INTERCEPT_FUNCTION(readlink);
   INTERCEPT_FUNCTION(memccpy);
-  INTERCEPT_FUNCTION(mempcpy);
+  MSAN_MAYBE_INTERCEPT_MEMPCPY;
   INTERCEPT_FUNCTION(bcopy);
   INTERCEPT_FUNCTION(wmemset);
   INTERCEPT_FUNCTION(wmemcpy);
-  INTERCEPT_FUNCTION(wmempcpy);
+  MSAN_MAYBE_INTERCEPT_WMEMPCPY;
   INTERCEPT_FUNCTION(wmemmove);
   INTERCEPT_FUNCTION(strcpy);  // NOLINT
-  INTERCEPT_FUNCTION(stpcpy);  // NOLINT
+  MSAN_MAYBE_INTERCEPT_STPCPY;  // NOLINT
   INTERCEPT_FUNCTION(strdup);
   MSAN_MAYBE_INTERCEPT___STRDUP;
   INTERCEPT_FUNCTION(strncpy);  // NOLINT
-  INTERCEPT_FUNCTION(gcvt);
+  MSAN_MAYBE_INTERCEPT_GCVT;
   INTERCEPT_FUNCTION(strcat);  // NOLINT
   INTERCEPT_FUNCTION(strncat);  // NOLINT
   INTERCEPT_STRTO(strtod);
@@ -1584,7 +1620,7 @@ void InitializeInterceptors() {
   INTERCEPT_FUNCTION(setenv);
   INTERCEPT_FUNCTION(putenv);
   INTERCEPT_FUNCTION(gettimeofday);
-  INTERCEPT_FUNCTION(fcvt);
+  MSAN_MAYBE_INTERCEPT_FCVT;
   MSAN_MAYBE_INTERCEPT___FXSTAT;
   MSAN_INTERCEPT_FSTATAT;
   MSAN_MAYBE_INTERCEPT___FXSTAT64;
