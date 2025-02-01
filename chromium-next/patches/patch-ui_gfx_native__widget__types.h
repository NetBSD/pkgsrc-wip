$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/native_widget_types.h.orig	2025-01-27 17:37:37.000000000 +0000
+++ ui/gfx/native_widget_types.h
@@ -101,7 +101,7 @@ class ViewAndroid;
 #endif
 class SkBitmap;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 using AtkObject = struct _AtkObject;
@@ -214,7 +214,7 @@ using NativeViewAccessible = id;
 #else
 using NativeViewAccessible = struct objc_object*;
 #endif
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native font type.
 using NativeViewAccessible = AtkObject*;
 #else
