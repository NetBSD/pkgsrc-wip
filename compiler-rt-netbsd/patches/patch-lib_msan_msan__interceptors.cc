$NetBSD$

--- lib/msan/msan_interceptors.cc.orig	2017-10-20 10:50:46.737765048 +0000
+++ lib/msan/msan_interceptors.cc
@@ -118,7 +118,7 @@ static void *AllocateFromLocalPool(uptr 
 #define CHECK_UNPOISONED_STRING(x, n)                           \
     CHECK_UNPOISONED_STRING_OF_LEN((x), internal_strlen(x), (n))
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(SIZE_T, fread_unlocked, void *ptr, SIZE_T size, SIZE_T nmemb,
             void *file) {
   ENSURE_MSAN_INITED();
@@ -168,7 +168,7 @@ INTERCEPTOR(int, posix_memalign, void **
   return res;
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(void *, memalign, SIZE_T alignment, SIZE_T size) {
   GET_MALLOC_STACK_TRACE;
   return msan_memalign(alignment, size, &stack);
@@ -196,7 +196,7 @@ INTERCEPTOR(void *, valloc, SIZE_T size)
   return msan_valloc(size, &stack);
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(void *, pvalloc, SIZE_T size) {
   GET_MALLOC_STACK_TRACE;
   return msan_pvalloc(size, &stack);
@@ -212,7 +212,7 @@ INTERCEPTOR(void, free, void *ptr) {
   MsanDeallocate(&stack, ptr);
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(void, cfree, void *ptr) {
   GET_MALLOC_STACK_TRACE;
   if (!ptr || UNLIKELY(IsInDlsymAllocPool(ptr))) return;
@@ -227,7 +227,7 @@ INTERCEPTOR(uptr, malloc_usable_size, vo
   return __sanitizer_get_allocated_size(ptr);
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 // This function actually returns a struct by value, but we can't unpoison a
 // temporary! The following is equivalent on all supported platforms but
 // aarch64 (which uses a different register for sret value).  We have a test
@@ -246,7 +246,7 @@ INTERCEPTOR(void, mallinfo, __sanitizer_
 #define MSAN_MAYBE_INTERCEPT_MALLINFO
 #endif
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(int, mallopt, int cmd, int value) {
   return -1;
 }
@@ -255,7 +255,7 @@ INTERCEPTOR(int, mallopt, int cmd, int v
 #define MSAN_MAYBE_INTERCEPT_MALLOPT
 #endif
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(void, malloc_stats, void) {
   // FIXME: implement, but don't call REAL(malloc_stats)!
 }
@@ -308,7 +308,7 @@ INTERCEPTOR(char *, strdup, char *src) {
   return res;
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(char *, __strdup, char *src) {
   ENSURE_MSAN_INITED();
   GET_STORE_STACK_TRACE;
@@ -473,7 +473,7 @@ INTERCEPTOR(SIZE_T, strftime_l, char *s,
   INTERCEPTOR_STRFTIME_BODY(char, SIZE_T, strftime_l, s, max, format, tm, loc);
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(SIZE_T, __strftime_l, char *s, SIZE_T max, const char *format,
             __sanitizer_tm *tm, void *loc) {
   INTERCEPTOR_STRFTIME_BODY(char, SIZE_T, __strftime_l, s, max, format, tm,
@@ -495,7 +495,7 @@ INTERCEPTOR(SIZE_T, wcsftime_l, wchar_t 
                             loc);
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(SIZE_T, __wcsftime_l, wchar_t *s, SIZE_T max, const wchar_t *format,
             __sanitizer_tm *tm, void *loc) {
   INTERCEPTOR_STRFTIME_BODY(wchar_t, SIZE_T, __wcsftime_l, s, max, format, tm,
@@ -614,7 +614,7 @@ INTERCEPTOR(int, putenv, char *string) {
   return res;
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(int, __fxstat, int magic, int fd, void *buf) {
   ENSURE_MSAN_INITED();
   int res = REAL(__fxstat)(magic, fd, buf);
@@ -627,7 +627,7 @@ INTERCEPTOR(int, __fxstat, int magic, in
 #define MSAN_MAYBE_INTERCEPT___FXSTAT
 #endif
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(int, __fxstat64, int magic, int fd, void *buf) {
   ENSURE_MSAN_INITED();
   int res = REAL(__fxstat64)(magic, fd, buf);
@@ -640,7 +640,7 @@ INTERCEPTOR(int, __fxstat64, int magic, 
 #define MSAN_MAYBE_INTERCEPT___FXSTAT64
 #endif
 
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(int, fstatat, int fd, char *pathname, void *buf, int flags) {
   ENSURE_MSAN_INITED();
   int res = REAL(fstatat)(fd, pathname, buf, flags);
@@ -659,7 +659,7 @@ INTERCEPTOR(int, __fxstatat, int magic, 
 # define MSAN_INTERCEPT_FSTATAT INTERCEPT_FUNCTION(__fxstatat)
 #endif
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(int, __fxstatat64, int magic, int fd, char *pathname, void *buf,
             int flags) {
   ENSURE_MSAN_INITED();
@@ -706,7 +706,7 @@ INTERCEPTOR(char *, fgets, char *s, int 
   return res;
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(char *, fgets_unlocked, char *s, int size, void *stream) {
   ENSURE_MSAN_INITED();
   char *res = REAL(fgets_unlocked)(s, size, stream);
@@ -729,7 +729,7 @@ INTERCEPTOR(int, getrlimit, int resource
   return res;
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(int, getrlimit64, int resource, void *rlim) {
   if (msan_init_is_running) return REAL(getrlimit64)(resource, rlim);
   ENSURE_MSAN_INITED();
@@ -805,7 +805,7 @@ INTERCEPTOR(int, gethostname, char *name
   return res;
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(int, epoll_wait, int epfd, void *events, int maxevents,
     int timeout) {
   ENSURE_MSAN_INITED();
@@ -820,7 +820,7 @@ INTERCEPTOR(int, epoll_wait, int epfd, v
 #define MSAN_MAYBE_INTERCEPT_EPOLL_WAIT
 #endif
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(int, epoll_pwait, int epfd, void *events, int maxevents,
     int timeout, void *sigmask) {
   ENSURE_MSAN_INITED();
@@ -909,7 +909,7 @@ INTERCEPTOR(void *, mmap, void *addr, SI
   return res;
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 INTERCEPTOR(void *, mmap64, void *addr, SIZE_T length, int prot, int flags,
             int fd, OFF64_T offset) {
   ENSURE_MSAN_INITED();
