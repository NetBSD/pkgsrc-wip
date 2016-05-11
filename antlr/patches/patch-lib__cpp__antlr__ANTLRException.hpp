$NetBSD$

--- lib/cpp/antlr/ANTLRException.hpp.orig	2006-11-01 21:37:17.000000000 +0000
+++ lib/cpp/antlr/ANTLRException.hpp
@@ -9,6 +9,7 @@
  */
 
 #include <antlr/config.hpp>
+#include <exception>
 #include <string>
 
 #ifdef ANTLR_CXX_SUPPORTS_NAMESPACE
