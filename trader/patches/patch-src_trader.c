$NetBSD$

Do not use err_exit() to generate error messages when locale initialization
fails as in this case curs_set() is called before initscr(), which causes
trader to crash when built with NetBSD curses.

--- src/trader.c.orig	2021-01-12 23:39:07.351997639 +0000
+++ src/trader.c
@@ -151,8 +151,9 @@ int main (int argc, char *argv[])
 
     // Initialise the locale
     if (setlocale(LC_ALL, "") == NULL) {
-	err_exit("could not set locale "
-		 "(check LANG, LC_ALL and LANGUAGE in environment)");
+	fprintf(stderr, "%s: %s\n", program_name, "could not set locale "
+		"(check LANG, LC_ALL and LANGUAGE in environment)");
+	exit(EXIT_FAILURE);
     }
 
     // Use correct message catalogs for the locale
