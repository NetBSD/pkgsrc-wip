$NetBSD$

Portability fixes:

- Define non-standard compiler attribute extension.
- Do not hard-code xlock path.
- Disable pledge.

--- xidle.c.orig	2022-07-18 06:17:31.000000000 +0000
+++ xidle.c
@@ -45,9 +45,12 @@
 #endif
 
 #ifndef PATH_PROG
-#define PATH_PROG	"/usr/X11R6/bin/xlock"
+#define PATH_PROG	"@PREFIX@/bin/xlock"
 #endif
 
+#ifndef	__dead 
+#define __dead      __attribute__((__noreturn__))
+#endif
 
 enum {
 	north = 0x01,
@@ -354,9 +357,6 @@ main(int argc, char **argv)
 	if (fd > 2)
 		close(fd);
 
-	if (pledge("stdio proc exec", NULL) == -1)
-		err(1, "pledge");
-
 	for (;;) {
 		XEvent ev;
 		u_long mask;
