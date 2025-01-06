$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/native_theme/native_theme.cc.orig	2024-10-18 12:35:12.736265700 +0000
+++ ui/native_theme/native_theme.cc
@@ -209,6 +209,8 @@ NativeTheme::NativeTheme(bool should_use
 NativeTheme::~NativeTheme() = default;
 
 bool NativeTheme::ShouldUseDarkColors() const {
+  if (theme_source() == ThemeSource::kForcedLight) return false;
+  if (theme_source() == ThemeSource::kForcedDark) return true;
   return should_use_dark_colors_;
 }
 
