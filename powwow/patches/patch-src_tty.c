$NetBSD$

Adapt patch from FreeBSD ports patch-src_tty.c

--- src/tty.c.orig	2019-11-06 06:25:17.000000000 +0100
+++ src/tty.c	2022-05-19 18:00:08.513525079 +0200
@@ -9,7 +9,6 @@
  *  (at your option) any later version.
  *
  */
-#include <alloca.h>
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -61,6 +60,7 @@
 
 #ifdef BSD_LIKE
 #  include <sys/ioctl_compat.h>
+#  include <sys/termios.h>
 #  define O_RAW RAW
 #  define O_ECHO ECHO
 #  define O_CBREAK CBREAK
@@ -847,31 +847,29 @@
 
 int tty_printf(const char *format, ...)
 {
-    char buf[1024], *bufp = buf;
+    char *bufp;
+    char *old_locale;
     va_list va;
     int res;
 
-    char *old_locale = strdup(setlocale(LC_ALL, NULL));
+    if ((old_locale = strdup(setlocale(LC_ALL, NULL))) == NULL)
+           return -1;
 
     setlocale(LC_ALL, "C");
 
     va_start(va, format);
-    res = vsnprintf(buf, sizeof buf, format, va);
+    res = vasprintf(&bufp, format, va);
     va_end(va);
 
-    if (res >= sizeof buf) {
-	bufp = alloca(res + 1);
-	va_start(va, format);
-	vsprintf(bufp, format, va);
-        assert(strlen(bufp) == res);
-	va_end(va);
-    }
+    if (res < 0)
+           goto out;
 
     setlocale(LC_ALL, old_locale);
-    free(old_locale);
 
     tty_puts(bufp);
-
+    free(bufp);
+out:
+    free(old_locale);
     return res;
 }
 
@@ -968,16 +966,23 @@
 
 void tty_gets(char *s, int size)
 {
-    wchar_t *ws = alloca(size * sizeof *ws);
+    wchar_t *ws = NULL;
+
+    if ((ws = malloc(size * sizeof *ws)) == NULL)
+           goto out;
 
     if (!fgetws(ws, size, stdin))
-	return;
+	   goto out;
 
     while (*ws) {
 	if (!(*ws & ~0xff))
 	    *s++ = (unsigned char)*ws;
 	++ws;
     }
+out:
+    if (ws != NULL)
+           free(ws);
+    return;
 }
 
 void tty_flush(void)
