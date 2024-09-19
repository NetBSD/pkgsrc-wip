$NetBSD: patch-parse.c,v 1.1 2012/12/09 16:56:45 othyro Exp $

string.h defines strcasestr.

--- parse.c.orig	2001-02-07 08:23:20.000000000 +0000
+++ parse.c
@@ -1246,32 +1246,6 @@ char *less_nozero( char *a, char *b ){
 		else return b;
 }
 
-char *strcasestr( char *haystack, char *needle ){
-	/*
-	 * crack and code don't mix, Michael
-	 */
-	char fchar;
-	char Fchar;
-	
-	if ( (needle[0] >= 'A' && needle[0] <= 'Z') ||
-		(needle[0] >= 'a' && needle[0] <= 'z') ){
-		fchar = ( needle[0] | 32 );
-		Fchar = ( needle[0] & (255-32) );
-	} else {
-		fchar = needle[0];
-		Fchar = needle[0];
-	}
-	while ( (haystack = 
-		leastcp( strchr( haystack, fchar ), 
-		strchr( haystack, Fchar ) ) ) ){
-		if ( (!strncasecmp( haystack, needle, strlen( needle ) ) ) ){
-			return haystack;
-		}
-		haystack++;
-	}
-	return NULL;
-}
-
 int isredirect( char **page ){
 	int i = 0;
 	while( page[i][0] != '\n' ){
