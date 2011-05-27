$NetBSD: patch-ui_gfx_image.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/gfx/image.cc.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/gfx/image.cc
@@ -9,7 +9,7 @@
 #include "base/logging.h"
 #include "third_party/skia/include/core/SkBitmap.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include <gdk-pixbuf/gdk-pixbuf.h>
 #include <glib-object.h>
 #include "ui/gfx/canvas_skia.h"
@@ -29,7 +29,7 @@ namespace internal {
 const SkBitmap* NSImageToSkBitmap(NSImage* image);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 const SkBitmap* GdkPixbufToSkBitmap(GdkPixbuf* pixbuf) {
   gfx::CanvasSkia canvas(gdk_pixbuf_get_width(pixbuf),
                          gdk_pixbuf_get_height(pixbuf),
@@ -61,7 +61,7 @@ class ImageRep {
     return reinterpret_cast<SkBitmapRep*>(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   GdkPixbufRep* AsGdkPixbufRep() {
     CHECK_EQ(type_, Image::kGdkPixbufRep);
     return reinterpret_cast<GdkPixbufRep*>(this);
@@ -102,7 +102,7 @@ class SkBitmapRep : public ImageRep {
   DISALLOW_COPY_AND_ASSIGN(SkBitmapRep);
 };
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 class GdkPixbufRep : public ImageRep {
  public:
   explicit GdkPixbufRep(GdkPixbuf* pixbuf)
@@ -158,7 +158,7 @@ Image::Image(const SkBitmap* bitmap)
   AddRepresentation(rep);
 }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 Image::Image(GdkPixbuf* pixbuf)
     : default_representation_(Image::kGdkPixbufRep) {
   internal::GdkPixbufRep* rep = new internal::GdkPixbufRep(pixbuf);
@@ -190,7 +190,7 @@ Image::operator const SkBitmap&() {
   return *(this->operator const SkBitmap*());
 }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 Image::operator GdkPixbuf*() {
   internal::ImageRep* rep = GetRepresentation(Image::kGdkPixbufRep);
   return rep->AsGdkPixbufRep()->pixbuf();
@@ -237,7 +237,7 @@ internal::ImageRep* Image::GetRepresenta
   // Handle native-to-Skia conversion.
   if (rep_type == Image::kSkBitmapRep) {
     internal::SkBitmapRep* rep = NULL;
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
     if (default_representation_ == Image::kGdkPixbufRep) {
       internal::GdkPixbufRep* pixbuf_rep = default_rep->AsGdkPixbufRep();
       rep = new internal::SkBitmapRep(
@@ -261,7 +261,7 @@ internal::ImageRep* Image::GetRepresenta
   if (default_rep->type() == Image::kSkBitmapRep) {
     internal::SkBitmapRep* skia_rep = default_rep->AsSkBitmapRep();
     internal::ImageRep* native_rep = NULL;
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
     if (rep_type == Image::kGdkPixbufRep) {
       GdkPixbuf* pixbuf = gfx::GdkPixbufFromSkBitmap(skia_rep->bitmap());
       native_rep = new internal::GdkPixbufRep(pixbuf);
