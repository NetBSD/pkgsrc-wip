$NetBSD$

--- content/browser/web_contents/web_contents_impl.cc.orig	2016-06-24 01:02:20.000000000 +0000
+++ content/browser/web_contents/web_contents_impl.cc
@@ -1685,7 +1685,7 @@ bool WebContentsImpl::HandleWheelEvent(
     // Count only integer cumulative scrolls as zoom events; this handles
     // smooth scroll and regular scroll device behavior.
     zoom_scroll_remainder_ += event.wheelTicksY;
-    int whole_zoom_scroll_remainder_ = std::lround(zoom_scroll_remainder_);
+    int whole_zoom_scroll_remainder_ = lround(zoom_scroll_remainder_);
     zoom_scroll_remainder_ -= whole_zoom_scroll_remainder_;
     if (whole_zoom_scroll_remainder_ != 0) {
       delegate_->ContentsZoomChange(whole_zoom_scroll_remainder_ > 0);
