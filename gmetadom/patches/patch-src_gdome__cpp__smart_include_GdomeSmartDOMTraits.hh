$NetBSD: patch-src_gdome__cpp__smart_include_GdomeSmartDOMTraits.hh,v 1.1 2014/12/26 15:39:45 nros Exp $
* mem* needs string.h
--- src/gdome_cpp_smart/include/GdomeSmartDOMTraits.hh.orig	2014-12-25 18:58:42.000000000 +0000
+++ src/gdome_cpp_smart/include/GdomeSmartDOMTraits.hh
@@ -26,6 +26,7 @@
  */
 
 #include <string>
+#include <string.h>
 
 #include "GdomeSmartDOMChar.hh"
 
