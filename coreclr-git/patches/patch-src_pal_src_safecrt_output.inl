$NetBSD$

Try to fix va_list insanity. It is unsafe to pass pointers to va_list across
function calls, on some platforms. clang does not like it.

--- src/pal/src/safecrt/output.inl.orig	2016-02-24 01:48:40.000000000 +0000
+++ src/pal/src/safecrt/output.inl
@@ -205,7 +205,7 @@ int __cdecl _swoutput_s(wchar_t *_Dst, s
     CASSERT(sizeof(void *) != sizeof(int64_t));
 #endif  /* defined (_WIN64) */
 
-#ifndef __GNUC_VA_LIST
+#if !defined(__GNUC_VA_LIST) && !defined(__clang__)
 #if LONGLONG_IS_INT64
     #define get_long_long_arg(x) (long long)get_int64_arg(x)
 #endif  /* LONGLONG_IS_INT64 */
@@ -546,7 +546,7 @@ LOCAL(void) write_string(const _TCHAR *s
 
 #endif  /* CPRFLAG */
 
-#ifdef __GNUC_VA_LIST
+#if defined(__GNUC_VA_LIST) || defined(__clang__)
 
     #define get_int_arg(list)           va_arg(*list, int)
     #define get_long_arg(list)          va_arg(*list, long)
@@ -1665,7 +1665,7 @@ LOCAL(void) write_string (
 #endif  /* CPRFLAG */
 
 // For GCC 64 bit, we can't cast to va_list *, so we need to make these functions defines.
-#ifndef __GNUC_VA_LIST
+#if !defined(__GNUC_VA_LIST) && !defined(__clang__)
 
 /***
 *int get_int_arg(va_list *pargptr)
