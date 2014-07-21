$NetBSD: patch-grammar_lexer.l,v 1.1 2014/07/21 10:33:53 fhajny Exp $

Fix build on other BSDs.
--- grammar/lexer.l.orig	2014-06-02 10:18:03.000000000 +0000
+++ grammar/lexer.l
@@ -90,7 +90,7 @@ extern int yydebug;
 /* somehow, I need these prototype even though the headers are 
  * included. I guess that's some autotools magic I don't understand...
  */
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonflyBSD__)
 int fileno(FILE *stream);
 #endif
 
