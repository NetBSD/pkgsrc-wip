$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/native_theme/native_theme.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ ui/native_theme/native_theme.h
@@ -62,7 +62,7 @@ class COMPONENT_EXPORT(NATIVE_THEME) Nat
   // The part to be painted / sized.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
