$NetBSD$

--- gdb/common/common-utils.c.orig	2017-09-11 23:07:52.000000000 +0000
+++ gdb/common/common-utils.c
@@ -126,8 +126,10 @@ char *
 xstrvprintf (const char *format, va_list ap)
 {
   char *ret = NULL;
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
   int status = vasprintf (&ret, format, ap);
-
+#pragma GCC diagnostic pop
   /* NULL is returned when there was a memory allocation problem, or
      any other error (for instance, a bad format string).  A negative
      status (the printed length) with a non-NULL buffer should never
