$NetBSD$

Add support for NetBSD.

--- 8cc.h.orig	2016-10-01 19:32:15.000000000 +0000
+++ 8cc.h
@@ -7,7 +7,10 @@
 #include <inttypes.h>
 #include <stdbool.h>
 #include <stdio.h>
+#include <stdarg.h>
+#if !defined(__NetBSD__)
 #include <stdnoreturn.h>
+#endif
 #include <time.h>
 
 enum {
@@ -348,7 +351,12 @@ extern bool warning_is_error;
 #define warn(...)        warnf(__FILE__ ":" STR(__LINE__), NULL, __VA_ARGS__)
 #define warnt(tok, ...)  warnf(__FILE__ ":" STR(__LINE__), token_pos(tok), __VA_ARGS__)
 
-noreturn void errorf(char *line, char *pos, char *fmt, ...);
+#if defined(__NetBSD__)
+__dead
+#else
+noreturn 
+#endif
+void errorf(char *line, char *pos, char *fmt, ...);
 void warnf(char *line, char *pos, char *fmt, ...);
 char *token_pos(Token *tok);
 
