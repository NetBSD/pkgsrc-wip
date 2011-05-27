$NetBSD: patch-ui_gfx_image.h,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/gfx/image.h.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/gfx/image.h
@@ -43,7 +43,7 @@ class Image {
   // Creates a new image with the default representation. The object will take
   // ownership of the image.
   explicit Image(const SkBitmap* bitmap);
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   // Does not increase |pixbuf|'s reference count; expects to take ownership.
   explicit Image(GdkPixbuf* pixbuf);
 #elif defined(OS_MACOSX)
@@ -57,7 +57,7 @@ class Image {
   // Conversion handlers.
   operator const SkBitmap*();
   operator const SkBitmap&();
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   operator GdkPixbuf*();
 #elif defined(OS_MACOSX)
   operator NSImage*();
