$NetBSD$

--- lib/cpp/antlr/CharScanner.hpp.orig	2006-11-01 21:37:17.000000000 +0000
+++ lib/cpp/antlr/CharScanner.hpp
@@ -24,6 +24,9 @@
 # include <stdio.h>
 #endif
 
+#include <cstdio>
+#include <cstring>
+
 #include <antlr/TokenStream.hpp>
 #include <antlr/RecognitionException.hpp>
 #include <antlr/SemanticException.hpp>
