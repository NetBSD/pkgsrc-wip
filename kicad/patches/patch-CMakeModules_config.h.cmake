$NetBSD: patch-CMakeModules_config.h.cmake,v 1.1.1.1 2011/06/11 12:56:32 jathis Exp $

$ fixes compile problem due to iso646
--- ./CMakeModules/config.h.cmake.orig	2011-05-29 05:59:41.000000000 +0000
+++ ./CMakeModules/config.h.cmake
@@ -32,7 +32,7 @@
 #cmakedefine HAVE_ISO646_H
 
 #if defined( HAVE_ISO646_H )
-#include <iso646.h>
+#include <ciso646>
 #endif
 
 #cmakedefine HAVE_STRINGS_H
