$NetBSD: patch-src_engine_mathml_mathVariantAux.cc,v 1.2 2015/02/11 12:03:53 nros Exp $
* strcmp needs cstring
--- src/engine/mathml/mathVariantAux.cc.orig	2007-08-17 10:02:38.000000000 +0000
+++ src/engine/mathml/mathVariantAux.cc
@@ -20,6 +20,8 @@
 
 #include <cassert>
 
+#include <cstring>
+
 #include "mathVariantAux.hh"
 
 static MathVariantAttributes vattr[] = {
