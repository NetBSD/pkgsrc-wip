$NetBSD: patch-src_webserver.c,v 1.1 2013/08/28 20:03:17 thomasklausner Exp $

<error.h> isn't portable, provide replacement for error().

--- src/webserver.c.orig	2013-08-28 11:35:19.000000000 +0000
+++ src/webserver.c
@@ -31,7 +31,6 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <errno.h>
-#include <error.h>
 #include <string.h>
 #include <limits.h>
 #include <assert.h>
@@ -59,6 +58,22 @@ static struct virtual_file {
 	struct virtual_file *next;
 } *virtual_files = NULL;
 
+static void error(int unknown, int myerrno, const char *fmt, ...)
+{
+    va_list va;
+
+    va_start(va, fmt);
+    vfprintf(stderr, fmt, va);
+    va_end(va);
+
+    if (errno != 0)
+        fprintf(stderr, ": %s", strerror(errno));
+
+    putc('\n', stderr);
+
+    return;
+}
+
 int webserver_register_buf(const char *path, const char *contents,
 			   const char *content_type)
 {
