$NetBSD: patch-grammar_lexer.l,v 1.1 2013/10/15 14:54:32 fhajny Exp $

Fix build on other BSDs.
--- grammar/lexer.l.orig	2013-09-03 10:31:42.000000000 +0000
+++ grammar/lexer.l
@@ -88,7 +88,7 @@ extern int yydebug;
 /* somehow, I need these prototype even though the headers are 
  * included. I guess that's some autotools magic I don't understand...
  */
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonflyBSD__)
 int fileno(FILE *stream);
 #endif
 
