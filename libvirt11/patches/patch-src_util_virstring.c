$NetBSD$

We use "uselocale" too, so check for that in the macro as well.

--- src/util/virstring.c.orig	2025-10-01 19:46:01.000000000 +0900
+++ src/util/virstring.c	2025-11-02 22:24:49.343985400 +0900
@@ -234,7 +234,7 @@ virStrToLong_ullp(char const *s, char **
 }
 
 /* In case thread-safe locales are available */
-#if WITH_NEWLOCALE
+#if WITH_NEWLOCALE && HAVE_USELOCALE
 
 typedef locale_t virLocale;
 static virLocale virLocaleRaw;
