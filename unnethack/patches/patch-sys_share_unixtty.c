$NetBSD$

--- sys/share/unixtty.c.orig	2022-05-11 18:37:13.878580520 +0000
+++ sys/share/unixtty.c
@@ -462,7 +462,8 @@ check_utf8_console()
     }
 
     /* set minimal raw mode */
-    struct termios raw = { 0 };
+    struct termios raw = original;
+    cfmakeraw(&raw);
     raw.c_cc[VMIN] = 0;
     raw.c_cc[VTIME] = 3; /* timeout of 0.3 seconds */
     if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
