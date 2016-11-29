$NetBSD$

--- ui/gl/sync_control_vsync_provider.h.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/gl/sync_control_vsync_provider.h
@@ -31,7 +31,7 @@ class SyncControlVSyncProvider : public 
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
