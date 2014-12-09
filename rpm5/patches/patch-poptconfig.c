$NetBSD: patch-poptconfig.c,v 1.1 2014/12/09 22:47:32 krytarowski Exp $

--- popt/poptconfig.c.orig	2013-08-04 20:58:20.000000000 +0000
+++ popt/poptconfig.c
@@ -42,7 +42,7 @@ extern int glob_pattern_p (const char *_
 /*@=declundef =exportheader =incondefs =protoparammatch =redecl =type @*/
 #endif	/* __LCLINT__ */
 
-#if !defined(__GLIBC__)
+#if !defined(__GLIBC__) && !defined(_NETBSD_SOURCE)
 /* Return nonzero if PATTERN contains any metacharacters.
    Metacharacters can be quoted with backslashes if QUOTE is nonzero.  */
 static int
