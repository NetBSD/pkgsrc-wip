$NetBSD: patch-src_plugins_glsleditor_glslhighlighter.cpp,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Fix naming conflict of T_RESERVED with a system header define.

--- src/plugins/glsleditor/glslhighlighter.cpp.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/plugins/glsleditor/glslhighlighter.cpp
@@ -192,7 +192,7 @@ void Highlighter::highlightBlock(const Q
 
         } else if (tk.is(GLSL::Parser::T_IDENTIFIER)) {
             int kind = lex.findKeyword(data.constData() + tk.position, tk.length);
-            if (kind == GLSL::Parser::T_RESERVED)
+            if (kind == GLSL::Parser::TOKEN_RESERVED)
                 setFormat(tk.position, tk.length, m_formats[GLSLReservedKeyword]);
             else if (kind != GLSL::Parser::T_IDENTIFIER)
                 setFormat(tk.position, tk.length, m_formats[GLSLKeywordFormat]);
@@ -371,7 +371,7 @@ void Highlighter::highlightBlock(const Q
             setFormat(tk.position, tk.length, Qt::darkGreen); // ### FIXME: m_formats[GLSLCommentFormat]);
         else if (tk.is(GLSL::Parser::T_IDENTIFIER)) {
             int kind = lex.findKeyword(data.constData() + tk.position, tk.length);
-            if (kind == GLSL::Parser::T_RESERVED)
+            if (kind == GLSL::Parser::TOKEN_RESERVED)
                 setFormat(tk.position, tk.length, m_formats[GLSLReservedKeyword]);
             else if (kind != GLSL::Parser::T_IDENTIFIER)
                 setFormat(tk.position, tk.length, m_formats[GLSLKeywordFormat]);
