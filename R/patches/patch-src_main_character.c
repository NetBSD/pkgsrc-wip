--- src/main/character.c.orig	2023-07-05 07:15:01.000000000 +0900
+++ src/main/character.c	2024-01-05 10:23:29.080790235 +0900
@@ -74,7 +74,7 @@ abbreviate chartr make.names strtrim tol
 /* Used to indicate that we can safely convert marked UTF-8 strings
    to wchar_t* -- not currently used.
 */
-#if defined(Win32) || defined(__STDC_ISO_10646__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun)
+#if defined(Win32) || defined(__STDC_ISO_10646__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun) || defined(__NetBSD__)
 # define TO_WCS_OK 1
 #else
 /*
@@ -1748,7 +1748,7 @@ attribute_hidden SEXP do_strtrim(SEXP ca
     UNPROTECT(1);
     return s;
 }
-
+#undef _NETBSD_SOURCE
 static int strtoi(SEXP s, int base)
 {
     if(s == NA_STRING || CHAR(s)[0] == '\0') return(NA_INTEGER);
