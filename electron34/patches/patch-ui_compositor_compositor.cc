$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/compositor/compositor.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/compositor/compositor.cc
@@ -343,7 +343,8 @@ void Compositor::SetLayerTreeFrameSink(
   if (display_private_) {
     disabled_swap_until_resize_ = false;
     display_private_->Resize(size());
-    display_private_->SetDisplayVisible(host_->IsVisible());
+    // Invisible display is throttling itself.
+    display_private_->SetDisplayVisible(background_throttling_ ? host_->IsVisible() : true);
     display_private_->SetDisplayColorSpaces(display_color_spaces_);
     display_private_->SetDisplayColorMatrix(
         gfx::SkM44ToTransform(display_color_matrix_));
@@ -554,7 +555,9 @@ void Compositor::SetVisible(bool visible
   // updated then. We need to call this even if the visibility hasn't changed,
   // for the same reason.
   if (display_private_)
-    display_private_->SetDisplayVisible(visible);
+    // Invisible display is throttling itself.
+    display_private_->SetDisplayVisible(
+        background_throttling_ ? visible : true);
 
   if (changed) {
     observer_list_.Notify(&CompositorObserver::OnCompositorVisibilityChanged,
@@ -912,7 +915,7 @@ void Compositor::OnResume() {
     obs.ResetIfActive();
 }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   observer_list_.Notify(
       &CompositorObserver::OnCompositingCompleteSwapWithNewSize, this, size);
@@ -1005,6 +1008,15 @@ void Compositor::MaybeUpdateObserveBegin
       host_begin_frame_observer_->GetBoundRemote());
 }
 
+void Compositor::SetBackgroundThrottling(bool background_throttling_enabled) {
+  background_throttling_ = background_throttling_enabled;
+  if (display_private_) {
+    // Invisible display is throttling itself.
+    display_private_->SetDisplayVisible(
+        background_throttling_ ? host_->IsVisible() : true);
+  }
+}
+
 #if BUILDFLAG(IS_CHROMEOS)
 void Compositor::SetSeamlessRefreshRates(
     const std::vector<float>& seamless_refresh_rates) {
