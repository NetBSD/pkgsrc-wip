$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2519,7 +2519,7 @@ void BrowserView::ToolbarSizeChanged(boo
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   GetContentsWebView()->SetFastResize(is_dragging);
   if (multi_contents_view_) {
     multi_contents_view_->GetInactiveContentsView()->SetFastResize(is_dragging);
@@ -5559,7 +5559,7 @@ void BrowserView::MaybeShowProfileSwitch
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
