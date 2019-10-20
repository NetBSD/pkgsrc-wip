$NetBSD$

We use "uselocale" too, so check for that in the macro as well.

--- src/util/virstring.c.orig	2019-03-26 13:50:10.521394891 +0000
+++ src/util/virstring.c
@@ -590,7 +590,7 @@ virStrToLong_ullp(char const *s, char **
 }
 
 /* In case thread-safe locales are available */
-#if HAVE_NEWLOCALE
+#if HAVE_NEWLOCALE && HAVE_USELOCALE
 
 typedef locale_t virLocale;
 static virLocale virLocaleRaw;
