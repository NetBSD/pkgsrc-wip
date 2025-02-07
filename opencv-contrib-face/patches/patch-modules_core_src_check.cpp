$NetBSD: patch-modules_core_src_check.cpp,v 1.1 2020/04/18 22:01:33 joerg Exp $

--- modules/core/src/check.cpp.orig	2025-01-08 12:47:46.000000000 +0000
+++ modules/core/src/check.cpp
@@ -3,6 +3,7 @@
 // of this distribution and at http://opencv.org/license.html.
 
 #include "precomp.hpp"
+#include <sstream>
 
 #include <sstream>
 
