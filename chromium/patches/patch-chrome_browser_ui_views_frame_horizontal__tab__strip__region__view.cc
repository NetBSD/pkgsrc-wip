$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/horizontal_tab_strip_region_view.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/views/frame/horizontal_tab_strip_region_view.cc
@@ -326,7 +326,7 @@ HorizontalTabStripRegionView::Horizontal
     new_tab_button_->GetViewAccessibility().SetName(
         l10n_util::GetStringUTF16(IDS_ACCNAME_NEWTAB));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On Linux, middle-clicking the New Tab Button triggers
     // paste and navigate, either to URLs or to search queries.
     new_tab_button_->SetTriggerableEventFlags(
