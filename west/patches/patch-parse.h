$NetBSD: patch-parse.h,v 1.1 2012/12/09 16:56:45 othyro Exp $

string.h already defines strcasestr.

--- parse.h.orig	2001-02-07 08:23:20.000000000 +0000
+++ parse.h
@@ -7,7 +7,6 @@ frame_t **page_getframes( char **pg );
 link_t **page_getlinks( char **page );
 void newurl( char *url, char **page );
 char *leastcp( char *a, char *b );
-char *strcasestr( char *haystack, char *needle );
 char *url_fixrelative( char *new, char *ref );
 int isredirect( char **page );
 
