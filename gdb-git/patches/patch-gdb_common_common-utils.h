$NetBSD$

--- gdb/common/common-utils.h.orig	2017-09-11 23:07:52.000000000 +0000
+++ gdb/common/common-utils.h
@@ -52,8 +52,7 @@ void xfree (void *);
 /* Like asprintf and vasprintf, but return the string, throw an error
    if no memory.  */
 char *xstrprintf (const char *format, ...) ATTRIBUTE_PRINTF (1, 2);
-char *xstrvprintf (const char *format, va_list ap)
-     ATTRIBUTE_PRINTF (1, 0);
+char *xstrvprintf (const char *format, va_list ap);
 
 /* Like snprintf, but throw an error if the output buffer is too small.  */
 int xsnprintf (char *str, size_t size, const char *format, ...)
