$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/frame.cc.orig	2024-10-18 12:34:35.412180400 +0000
+++ third_party/blink/renderer/core/frame/frame.cc
@@ -130,14 +130,6 @@ bool Frame::Detach(FrameDetachType type)
 
   DCHECK(!IsDetached());
 
-  // TODO(dcheng): FocusController::FrameDetached() *should* fire JS events,
-  // hence the above check for `client_` being null. However, when this was
-  // previously placed before the `FrameDetached()` call, nothing crashes, which
-  // is suspicious. Investigate if we really don't need to fire JS events--and
-  // if we don't, move `forbid_scripts` up to be instantiated sooner and
-  // simplify this code.
-  ScriptForbiddenScope forbid_scripts;
-
   if (type == FrameDetachType::kRemove) {
     if (provisional_frame_) {
       provisional_frame_->Detach(FrameDetachType::kRemove);
@@ -161,6 +153,14 @@ bool Frame::Detach(FrameDetachType type)
     GetWindowProxyManager()->ClearForSwap();
   }
 
+  // TODO(dcheng): FocusController::FrameDetached() *should* fire JS events,
+  // hence the above check for `client_` being null. However, when this was
+  // previously placed before the `FrameDetached()` call, nothing crashes, which
+  // is suspicious. Investigate if we really don't need to fire JS events--and
+  // if we don't, move `forbid_scripts` up to be instantiated sooner and
+  // simplify this code.
+  ScriptForbiddenScope forbid_scripts;
+
   // After this, we must no longer talk to the client since this clears
   // its owning reference back to our owning LocalFrame.
   client_->Detached(type);
