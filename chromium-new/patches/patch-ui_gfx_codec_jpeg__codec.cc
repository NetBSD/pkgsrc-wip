$NetBSD$

--- ui/gfx/codec/jpeg_codec.cc.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/gfx/codec/jpeg_codec.cc
@@ -13,6 +13,7 @@
 
 extern "C" {
 #if defined(USE_SYSTEM_LIBJPEG)
+#include <stdio.h>
 #include <jpeglib.h>
 #elif defined(USE_LIBJPEG_TURBO)
 #include "third_party/libjpeg_turbo/jpeglib.h"
