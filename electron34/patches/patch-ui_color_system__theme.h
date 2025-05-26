$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/color/system_theme.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/color/system_theme.h
@@ -15,7 +15,7 @@ namespace ui {
 enum class SystemTheme {
   // Classic theme, used in the default or users' chosen theme.
   kDefault = 0,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   kGtk = 1,
   kQt = 2,
   kMaxValue = kQt,
