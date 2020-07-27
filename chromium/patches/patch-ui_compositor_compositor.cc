$NetBSD$

--- ui/compositor/compositor.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ ui/compositor/compositor.cc
@@ -731,7 +731,7 @@ void Compositor::CancelThroughtputTracke
   throughput_tracker_map_.erase(tracker_id);
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   for (auto& observer : observer_list_)
     observer.OnCompositingCompleteSwapWithNewSize(this, size);
