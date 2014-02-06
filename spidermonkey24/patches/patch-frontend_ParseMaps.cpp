$NetBSD: patch-frontend_ParseMaps.cpp,v 1.1 2014/02/06 15:12:18 fhajny Exp $

--- frontend/ParseMaps.cpp.orig	2013-09-10 03:43:34.000000000 +0000
+++ frontend/ParseMaps.cpp
@@ -132,5 +132,5 @@ frontend::InitAtomMap(JSContext *cx, fro
     }
 }
 
-template class js::frontend::AtomDecls<FullParseHandler>;
-template class js::frontend::AtomDecls<SyntaxParseHandler>;
+template class frontend::AtomDecls<FullParseHandler>;
+template class frontend::AtomDecls<SyntaxParseHandler>;
