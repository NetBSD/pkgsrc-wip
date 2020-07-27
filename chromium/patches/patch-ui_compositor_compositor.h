$NetBSD$

--- ui/compositor/compositor.h.orig	2020-07-15 18:56:34.000000000 +0000
+++ ui/compositor/compositor.h
@@ -370,7 +370,7 @@ class COMPOSITOR_EXPORT Compositor : pub
   void StopThroughtputTracker(TrackerId tracker_id) override;
   void CancelThroughtputTracker(TrackerId tracker_id) override;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif
 
