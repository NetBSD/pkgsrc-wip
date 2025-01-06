$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/host/layered_window_updater_impl.cc.orig	2024-10-18 12:34:11.531880000 +0000
+++ components/viz/host/layered_window_updater_impl.cc
@@ -46,7 +46,9 @@ void LayeredWindowUpdaterImpl::OnAllocat
   // |region|'s handle will close when it goes out of scope.
 }
 
-void LayeredWindowUpdaterImpl::Draw(DrawCallback draw_callback) {
+void LayeredWindowUpdaterImpl::Draw(
+    const gfx::Rect& damage_rect,
+    DrawCallback draw_callback) {
   TRACE_EVENT0("viz", "LayeredWindowUpdaterImpl::Draw");
 
   if (!canvas_) {
