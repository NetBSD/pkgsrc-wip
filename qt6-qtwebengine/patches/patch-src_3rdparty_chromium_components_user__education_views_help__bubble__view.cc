$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/user_education/views/help_bubble_view.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/components/user_education/views/help_bubble_view.cc
@@ -1009,7 +1009,7 @@ gfx::Rect HelpBubbleView::GetAnchorRect(
 void HelpBubbleView::OnBeforeBubbleWidgetInit(views::Widget::InitParams* params,
                                               views::Widget* widget) const {
   BubbleDialogDelegateView::OnBeforeBubbleWidgetInit(params, widget);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Help bubbles anchored to menus may be clipped to their anchors' bounds,
   // resulting in visual errors, unless they use accelerated rendering. See
   // crbug.com/1445770 for details.
