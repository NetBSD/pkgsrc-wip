$NetBSD: patch-xml-parser_xml__definition.y,v 1.1 2013/09/02 19:08:25 thomasklausner Exp $

Fix build with flex.

--- xml-parser/xml_definition.y.orig	2010-10-27 12:30:16.000000000 +0000
+++ xml-parser/xml_definition.y
@@ -30,16 +30,15 @@
 
   C_XmlParser      *XmlParserClass ;
 
+extern "C" {
   // Generic parser data
   extern char  yytext[] ;
   extern FILE *yyin    ;
   extern int  yylineno ;
-
-#if defined(__linux__) || defined(__CYGWIN__)
   extern int  yyparse ();
-  extern int  yylex () ;
   extern void yyerror (const char*) ;
-#endif 
+}
+  extern int  yylex () ;
 
 %}
 
