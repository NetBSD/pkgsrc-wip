$NetBSD: patch-src_SFML_Network_SelectorBase.cpp,v 1.1 2012/10/03 15:06:00 othyro Exp $

Needs sys/time.h for timeval and select.

--- src/SFML/Network/SelectorBase.cpp.orig	2010-01-27 14:00:37.000000000 +0000
+++ src/SFML/Network/SelectorBase.cpp
@@ -29,6 +29,7 @@
 ////////////////////////////////////////////////////////////
 // Headers
 ////////////////////////////////////////////////////////////
+#include <sys/time.h>
 #include <SFML/Network/SelectorBase.hpp>
 
 
