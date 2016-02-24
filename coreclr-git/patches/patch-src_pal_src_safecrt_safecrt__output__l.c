$NetBSD$

Try to fix va_list insanity. It is unsafe to pass pointers to va_list across
function calls, on some platforms. clang does not like it.

--- src/pal/src/safecrt/safecrt_output_l.c.orig	2016-02-24 01:48:40.000000000 +0000
+++ src/pal/src/safecrt/safecrt_output_l.c
@@ -111,7 +111,7 @@ Buffer size required to be passed to _gc
     CASSERT(sizeof(long) == sizeof(int));
 #endif
 
-#ifdef __GNUC_VA_LIST
+#if defined(__GNUC_VA_LIST)
     // GCC: short is not int, but GCC promotes va_arg to int
     #define SHORT_IS_INT     1
 #else
@@ -143,7 +143,7 @@ Buffer size required to be passed to _gc
     CASSERT(sizeof(void *) != sizeof(int64_t));
 #endif  /* defined (_WIN64) */
 
-#ifndef __GNUC_VA_LIST
+#if !defined(__GNUC_VA_LIST) && !defined(__clang__)
 
 #if LONGLONG_IS_INT64
     #define get_long_long_arg(x) (long long)get_int64_arg(x)
@@ -401,7 +401,7 @@ LOCAL(void) write_string(const _TCHAR *s
 
 #endif  /* CPRFLAG */
 
-#ifdef __GNUC_VA_LIST
+#if defined(__GNUC_VA_LIST) || defined(__clang__)
 
     #define get_short_arg(list)         va_arg(*list, int)  // GCC promotes va_arg shorts into int values
     #define get_int_arg(list)           va_arg(*list, int)
@@ -1527,7 +1527,7 @@ LOCAL(void) write_string (
 
 
 // For GCC 64 bit, we can't cast to va_list *, so we need to make these functions defines.
-#ifndef __GNUC_VA_LIST
+#if !defined(__GNUC_VA_LIST) && !defined(__clang__)
 
 /***
 *int get_int_arg(va_list *pargptr)
