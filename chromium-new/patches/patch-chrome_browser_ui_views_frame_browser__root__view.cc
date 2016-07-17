$NetBSD$

--- chrome/browser/ui/views/frame/browser_root_view.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_root_view.cc
@@ -139,10 +139,10 @@ bool BrowserRootView::OnMouseWheel(const
 
       // Number of integer scroll events that have passed in each direction.
       int whole_scroll_amount_x =
-          std::lround(static_cast<double>(scroll_remainder_x_) /
+          lround(static_cast<double>(scroll_remainder_x_) /
                       ui::MouseWheelEvent::kWheelDelta);
       int whole_scroll_amount_y =
-          std::lround(static_cast<double>(scroll_remainder_y_) /
+          lround(static_cast<double>(scroll_remainder_y_) /
                       ui::MouseWheelEvent::kWheelDelta);
 
       // Adjust the remainder such that any whole scrolls we have taken action
