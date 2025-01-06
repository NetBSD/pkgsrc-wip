$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/widget/desktop_aura/desktop_window_tree_host_win.cc.orig	2024-10-18 12:35:12.872211500 +0000
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_win.cc
@@ -581,7 +581,7 @@ void DesktopWindowTreeHostWin::SetOpacit
 void DesktopWindowTreeHostWin::SetAspectRatio(
     const gfx::SizeF& aspect_ratio,
     const gfx::Size& excluded_margin) {
-  DCHECK(!aspect_ratio.IsEmpty());
+  DCHECK_NE(aspect_ratio.height(), 0);
   message_handler_->SetAspectRatio(aspect_ratio.width() / aspect_ratio.height(),
                                    excluded_margin);
 }
@@ -1228,6 +1228,10 @@ void DesktopWindowTreeHostWin::HandleHea
   window()->SetProperty(aura::client::kHeadlessBoundsKey, bounds);
 }
 
+bool DesktopWindowTreeHostWin::HandleMouseEventForCaption(UINT message) const {
+  return false;
+}
+
 DesktopNativeCursorManager*
 DesktopWindowTreeHostWin::GetSingletonDesktopNativeCursorManager() {
   return new DesktopNativeCursorManagerWin();
