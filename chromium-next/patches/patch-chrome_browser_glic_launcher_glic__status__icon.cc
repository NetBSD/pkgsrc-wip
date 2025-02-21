$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/launcher/glic_status_icon.cc.orig	2025-02-17 21:09:38.000000000 +0000
+++ chrome/browser/glic/launcher/glic_status_icon.cc
@@ -30,7 +30,7 @@ GlicStatusIcon::GlicStatusIcon(GlicContr
   // TODO(crbug.com/382287104): Use correct icon.
   // TODO(crbug.com/386839488): Chose color based on system theme.
   gfx::ImageSkia status_tray_icon = gfx::CreateVectorIcon(kGlicButtonIcon,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                                                           SK_ColorWHITE
 #else
                                                           SK_ColorBLACK
