$NetBSD$

Workaround for upstream commit 8ce6b211ce7b9ebad3e30fa909effebf59955a93 .
At least with NetBSD stdio fileno() does not accept (void *) type for parameter.

--- lib/gvpr/compile.c.orig	2023-09-11 18:30:04.000000000 +0000
+++ lib/gvpr/compile.c
@@ -56,7 +56,9 @@ static Sflong_t ptr2int(const void *p) {
 
 static int iofread(void *chan, char *buf, int bufsize)
 {
-  return (int)read(fileno(chan), buf, bufsize);
+  FILE *fp = chan;
+
+  return (int)read(fileno(fp), buf, bufsize);
 }
 
 static int ioputstr(void *chan, const char *str)
