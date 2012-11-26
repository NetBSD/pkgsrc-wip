$NetBSD: patch-src_libs_glsl_glsllexer.cpp,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Fix naming conflict of T_RESERVED with a system header define.

--- src/libs/glsl/glsllexer.cpp.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/libs/glsl/glsllexer.cpp
@@ -406,7 +406,7 @@ int Lexer::findKeyword(const char *word,
         // in the current language variant so that the syntax highlighter
         // can warn the user about the word.
         if (!_scanKeywords)
-            return Parser::T_RESERVED;
+            return Parser::TOKEN_RESERVED;
     }
     return t & ~Variant_Mask;
 }
