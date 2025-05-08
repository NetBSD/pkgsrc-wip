$NetBSD$

--- third_party/externals/piex/src/image_type_recognition/image_type_recognition_lite.cc.orig	2025-05-07 14:50:21.000000000 +0000
+++ third_party/externals/piex/src/image_type_recognition/image_type_recognition_lite.cc
@@ -27,6 +27,7 @@
 #include <algorithm>
 #include <cassert>
 #include <string>
+#include <cstring>
 #include <vector>
 
 #include "src/binary_parse/range_checked_byte_ptr.h"
