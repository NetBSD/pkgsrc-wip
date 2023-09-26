$NetBSD$

Our libc has that.

--- Library/Implementation/HTString.c.orig	1994-09-25 13:53:36.000000000 +0000
+++ Library/Implementation/HTString.c
@@ -61,6 +61,7 @@ PUBLIC int strncasecomp ARGS3(CONST char
 /*
  * strcasestr(s1,s2) -- like strstr(s1,s2) but case-insensitive.
  */
+/*
 PUBLIC char * strcasestr ARGS2(char *,	s1,
 			       char *,	s2)
 {
@@ -90,6 +91,7 @@ PUBLIC char * strcasestr ARGS2(char *,	s
 	   s1,s2);
     return NULL;
 }
+*/
 
 
 
