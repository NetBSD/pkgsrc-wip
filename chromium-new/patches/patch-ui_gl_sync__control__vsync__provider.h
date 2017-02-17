$NetBSD$

--- ui/gl/sync_control_vsync_provider.h.orig	2017-02-02 02:03:13.000000000 +0000
+++ ui/gl/sync_control_vsync_provider.h
@@ -32,7 +32,7 @@ class GL_EXPORT SyncControlVSyncProvider
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   bool AdjustSyncValues(int64_t* system_time, int64_t* media_stream_counter);
 
   base::TimeTicks last_timebase_;
@@ -48,7 +48,7 @@ class GL_EXPORT SyncControlVSyncProvider
   std::queue<base::TimeDelta> last_computed_intervals_;
 #endif  //  defined(OS_LINUX) || defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool invalid_msc_ = false;
 #endif  // defined(OS_LINUX)
 
