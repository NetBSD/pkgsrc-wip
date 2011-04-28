$NetBSD: patch-gfx_scoped__image.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- gfx/scoped_image.h.orig	2011-04-13 08:01:07.000000000 +0000
+++ gfx/scoped_image.h
@@ -11,7 +11,7 @@
 #include "gfx/native_widget_types.h"
 #include "third_party/skia/include/core/SkBitmap.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <glib-object.h>
 #elif defined(OS_MACOSX)
 #include "base/mac/mac_util.h"
@@ -116,7 +116,7 @@ class ScopedImage<NSImage> : public gfx:
 #endif  // defined(OS_MACOSX)
 
 // Specialization for the GdkPixbuf type on Linux.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 template <>
 class ScopedImage<GdkPixbuf> : public gfx::internal::ScopedImage<GdkPixbuf> {
  public:
