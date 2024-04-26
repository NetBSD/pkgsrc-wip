$NetBSD$

Parameter is const.

--- src/avrparse.y.orig	2004-01-20 01:10:07.000000000 +0000
+++ src/avrparse.y
@@ -63,7 +63,7 @@ int yylex();
 
 /// yyerror //////////////////////////////////////////////////////////////////
 
-void yyerror(char *s)
+void yyerror(const char *s)
 {
   s = s; // Used for debugging purposes
 }
