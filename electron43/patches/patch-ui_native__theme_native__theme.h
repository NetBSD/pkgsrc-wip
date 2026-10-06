$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/native_theme/native_theme.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/native_theme/native_theme.h
@@ -61,7 +61,7 @@ class NATIVE_THEME_EXPORT NativeTheme {
   // The part to be painted / sized.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
@@ -443,6 +443,23 @@ class NATIVE_THEME_EXPORT NativeTheme {
       scoped_refptr<ColorProviderKey::ThemeInitializerSupplier> custom_theme,
       bool use_custom_frame = true) const;
 
+
+  enum ThemeSource {
+    kSystem,
+    kForcedDark,
+    kForcedLight,
+  };
+
+  ThemeSource theme_source() const {
+    return theme_source_;
+  }
+
+  void set_theme_source(ThemeSource theme_source) {
+    bool original = ShouldUseDarkColors();
+    theme_source_ = theme_source;
+    if (ShouldUseDarkColors() != original) NotifyOnNativeThemeUpdated();
+  }
+
   // Returns a shared instance of the native theme that should be used for web
   // rendering. Do not use it in a normal application context (i.e. browser).
   // The returned object should not be deleted by the caller. This function is
@@ -680,6 +697,7 @@ class NATIVE_THEME_EXPORT NativeTheme {
   PreferredContrast preferred_contrast_ = PreferredContrast::kNoPreference;
   std::optional<base::TimeDelta> caret_blink_interval_;
   bool use_overlay_scrollbars_ = false;
+  ThemeSource theme_source_ = ThemeSource::kSystem;
 
   SEQUENCE_CHECKER(sequence_checker_);
 };
