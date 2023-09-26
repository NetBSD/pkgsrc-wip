$NetBSD$

Our libc has that.

--- Library/Implementation/HTString.h.orig	1994-09-25 14:15:24.000000000 +0000
+++ Library/Implementation/HTString.h
@@ -30,8 +30,10 @@ Case-insensitive string inside another s
    
  */
 
+/*
 PUBLIC char * strcasestr PARAMS((char * s1,
                                  char * s2));
+*/
 
 /*
 
