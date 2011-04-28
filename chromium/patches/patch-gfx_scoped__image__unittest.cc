$NetBSD: patch-gfx_scoped__image__unittest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- gfx/scoped_image_unittest.cc.orig	2011-04-13 08:01:07.000000000 +0000
+++ gfx/scoped_image_unittest.cc
@@ -7,7 +7,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 #include "third_party/skia/include/core/SkBitmap.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include "gfx/gtk_util.h"
 #elif defined(OS_MACOSX)
 #include "base/mac/mac_util.h"
@@ -32,7 +32,7 @@ class ScopedImageTest : public testing::
     NSImage* image = gfx::SkBitmapToNSImage(*(bitmap.get()));
     base::mac::NSObjectRetain(image);
     return image;
-#elif defined(OS_LINUX) && !defined(TOOLKIT_VIEWS)
+#elif defined(TOOLKIT_USES_GTK)
     return gfx::GdkPixbufFromSkBitmap(bitmap.get());
 #else
     return bitmap.release();
