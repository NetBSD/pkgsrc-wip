$NetBSD$

Add missing includes.

--- src/slic3r/GUI/RulerForDoubleSlider.cpp.orig	2024-06-23 23:32:52.865797908 +0000
+++ src/slic3r/GUI/RulerForDoubleSlider.cpp
@@ -4,6 +4,10 @@
 ///|/
 #include "RulerForDoubleSlider.hpp"
 #include "libslic3r/CustomGCode.hpp"
+#include "libslic3r/Point.hpp"
+
+#include <algorithm>
+#include <cmath>
 
 using namespace Slic3r;
 using namespace CustomGCode;
