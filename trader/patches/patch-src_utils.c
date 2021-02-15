$NetBSD$

Do not use err_exit() to generate error messages when locale initialization
fails as in this case curs_set() is called before initscr(), which causes
trader to crash when built with NetBSD curses.

--- src/utils.c.orig	2021-01-19 05:42:38.000000000 +0000
+++ src/utils.c
@@ -591,8 +591,9 @@ extern void init_locale (void)
 
     // Initialise the current locale
     if (setlocale(LC_ALL, "") == NULL) {
-	err_exit("could not set locale "
-		 "(check LANG, LC_ALL and LANGUAGE in environment)");
+	fprintf(stderr, "%s: %s\n", program_name, "could not set locale "
+		"(check LANG, LC_ALL and LANGUAGE in environment)");
+	exit(EXIT_FAILURE);
     }
 
     // Use correct message catalogs for the locale
