$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/native_theme/native_theme.h.orig	2024-10-18 12:35:12.736265700 +0000
+++ ui/native_theme/native_theme.h
@@ -63,7 +63,7 @@ class NATIVE_THEME_EXPORT NativeTheme {
     kCheckbox,
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
@@ -436,6 +436,23 @@ class NATIVE_THEME_EXPORT NativeTheme {
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
@@ -664,6 +681,7 @@ class NATIVE_THEME_EXPORT NativeTheme {
   PreferredColorScheme preferred_color_scheme_ = PreferredColorScheme::kLight;
   PreferredContrast preferred_contrast_ = PreferredContrast::kNoPreference;
   std::optional<base::TimeDelta> caret_blink_interval_;
+  ThemeSource theme_source_ = ThemeSource::kSystem;
 
   SEQUENCE_CHECKER(sequence_checker_);
 };
