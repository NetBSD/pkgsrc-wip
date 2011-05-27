$NetBSD: patch-ui_gfx_native__widget__types.h,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/gfx/native_widget_types.h.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/gfx/native_widget_types.h
@@ -97,7 +97,7 @@ typedef GdkRegion* NativeRegion;
 
 #if defined(OS_MACOSX)
 typedef NSImage NativeImageType;
-#elif defined(OS_LINUX) && !defined(TOOLKIT_VIEWS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(TOOLKIT_VIEWS)
 typedef GdkPixbuf NativeImageType;
 #else
 typedef SkBitmap NativeImageType;
