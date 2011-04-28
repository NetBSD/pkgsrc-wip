$NetBSD: patch-gfx_native__widget__types.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- gfx/native_widget_types.h.orig	2011-04-13 08:01:07.000000000 +0000
+++ gfx/native_widget_types.h
@@ -97,7 +97,7 @@ typedef GdkRegion* NativeRegion;
 
 #if defined(OS_MACOSX)
 typedef NSImage NativeImageType;
-#elif defined(OS_LINUX) && !defined(TOOLKIT_VIEWS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(TOOLKIT_VIEWS)
 typedef GdkPixbuf NativeImageType;
 #else
 typedef SkBitmap NativeImageType;
