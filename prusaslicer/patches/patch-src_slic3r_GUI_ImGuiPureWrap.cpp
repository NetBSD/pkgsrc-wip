$NetBSD$

Add missing include.

--- src/slic3r/GUI/ImGuiPureWrap.cpp.orig	2024-06-19 23:08:49.135122434 +0000
+++ src/slic3r/GUI/ImGuiPureWrap.cpp
@@ -5,6 +5,8 @@
 ///|/
 #include "ImGuiPureWrap.hpp"
 
+#include <cmath>
+
 #include <boost/algorithm/string/predicate.hpp>
 #include <boost/nowide/convert.hpp>
 
