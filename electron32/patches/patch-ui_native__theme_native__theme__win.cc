$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/native_theme/native_theme_win.cc.orig	2024-10-18 12:35:12.736265700 +0000
+++ ui/native_theme/native_theme_win.cc
@@ -677,6 +677,8 @@ bool NativeThemeWin::ShouldUseDarkColors
   // ...unless --force-dark-mode was specified in which case caveat emptor.
   if (InForcedColorsMode() && !IsForcedDarkMode())
     return false;
+  if (theme_source() == ThemeSource::kForcedLight) return false;
+  if (theme_source() == ThemeSource::kForcedDark) return true;
   return NativeTheme::ShouldUseDarkColors();
 }
 
