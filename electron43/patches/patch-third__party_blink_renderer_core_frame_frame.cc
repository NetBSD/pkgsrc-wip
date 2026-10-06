$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/frame.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/frame/frame.cc
@@ -135,14 +135,6 @@ bool Frame::Detach(FrameDetachType type)
 
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
@@ -166,6 +158,14 @@ bool Frame::Detach(FrameDetachType type)
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
