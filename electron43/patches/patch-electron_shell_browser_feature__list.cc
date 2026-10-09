$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/feature_list.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/feature_list.cc
@@ -30,7 +30,7 @@
 #include "pdf/pdf_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_features.h"
 #include "ui/base/ui_base_features.h"
 #endif
@@ -84,7 +84,7 @@ void InitializeFeatureList() {
       std::string(",") + chrome_pdf::features::kPdfUseShowSaveFilePicker.name;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Without this, globalShortcut is a silent no-op on GNOME Wayland (the
   // ozone factory returns no listener there). Chromium keeps it off due to
   // https://gitlab.gnome.org/GNOME/xdg-desktop-portal-gnome/-/issues/185,
