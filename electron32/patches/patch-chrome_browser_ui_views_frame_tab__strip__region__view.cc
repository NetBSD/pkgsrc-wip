$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/frame/tab_strip_region_view.cc.orig	2024-10-18 12:34:03.360269300 +0000
+++ chrome/browser/ui/views/frame/tab_strip_region_view.cc
@@ -201,7 +201,7 @@ TabStripRegionView::TabStripRegionView(s
 
     // TODO(crbug.com/40118868): Revisit the macro expression once build flag
     // switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     // The New Tab Button can be middle-clicked on Linux.
     new_tab_button_->SetTriggerableEventFlags(
         new_tab_button_->GetTriggerableEventFlags() |
