$NetBSD$

--- src/3rdparty/chromium/ui/base/ui_base_features.h.orig	2020-07-15 18:56:33.000000000 +0000
+++ src/3rdparty/chromium/ui/base/ui_base_features.h
@@ -60,7 +60,7 @@ COMPONENT_EXPORT(UI_BASE_FEATURES) exter
 COMPONENT_EXPORT(UI_BASE_FEATURES) bool IsUsingWMPointerForTouch();
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 extern const base::Feature kDirectManipulationStylus;
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
