$NetBSD$

Tolerate more warnings and errors, because there are a lot
of nonsense warnings which are a pain to clean up (GCC
visibility garbage).

--- lib.c.orig	2014-02-16 22:44:57.000000000 +0000
+++ lib.c
@@ -112,7 +112,7 @@ static void do_warn(const char *type, st
 		name, pos.line, pos.pos, type, buffer);
 }
 
-static int max_warnings = 100;
+static int max_warnings = 5000;
 static int show_info = 1;
 
 void info(struct position pos, const char * fmt, ...)
@@ -148,11 +148,11 @@ void warning(struct position pos, const 
 static void do_error(struct position pos, const char * fmt, va_list args)
 {
 	static int errors = 0;
-        die_if_error = 1;
+        die_if_error = 0;
 	show_info = 1;
 	/* Shut up warnings after an error */
 	max_warnings = 0;
-	if (errors > 100) {
+	if (errors > 5000) {
 		static int once = 0;
 		show_info = 0;
 		if (once)
