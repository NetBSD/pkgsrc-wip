$NetBSD$

--- src/ImageReader.cpp.orig	2024-12-24 11:07:39.461867765 +0000
+++ src/ImageReader.cpp
@@ -10,6 +10,8 @@
 //
 // SPDX-License-Identifier: LGPL-3.0-or-later
 
+#include <cmath>
+
 // Require ImageMagick support
 #ifdef USE_IMAGEMAGICK
 
