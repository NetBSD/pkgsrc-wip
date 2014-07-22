$NetBSD: patch-grammar_lexer.l,v 1.2 2014/07/22 07:44:55 fhajny Exp $

Fix build on other BSDs.
--- grammar/lexer.l.orig	2014-02-12 13:17:50.000000000 +0000
+++ grammar/lexer.l
@@ -88,7 +88,7 @@ extern int yydebug;
 /* somehow, I need these prototype even though the headers are 
  * included. I guess that's some autotools magic I don't understand...
  */
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonflyBSD__)
 int fileno(FILE *stream);
 #endif
 
