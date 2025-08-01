$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/omnibox/omnibox_view_views.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/ui/views/omnibox/omnibox_view_views.cc
@@ -2175,7 +2175,7 @@ void OmniboxViewViews::MaybeAddSendTabTo
 }
 
 void OmniboxViewViews::OnPopupOpened() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // It's not great for promos to overlap the omnibox if the user opens the
   // drop-down after showing the promo. This especially causes issues on Mac and
   // Linux due to z-order/rendering issues, see crbug.com/1225046 and
