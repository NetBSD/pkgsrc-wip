$NetBSD$

Include cstring for memcpy and memset (exposed by turning pre-compiled headers off).

--- source/common/textures/bitmap.h.orig	2023-11-12 13:35:34.000000000 +0000
+++ source/common/textures/bitmap.h
@@ -36,6 +36,7 @@
 #ifndef __BITMAP_H__
 #define __BITMAP_H__
 
+#include <cstring>
 #include "palentry.h"
 
 struct FCopyInfo;
