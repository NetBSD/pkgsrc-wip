$NetBSD$

- Address compiler warning about already defined value

diff --git plugins/experimental/memcache/tsmemcache.cc plugins/experimental/memcache/tsmemcache.cc
index 5f742a4f11..4c531c0e39 100644
--- plugins/experimental/memcache/tsmemcache.cc
+++ plugins/experimental/memcache/tsmemcache.cc
@@ -44,7 +44,9 @@ static time_t base_day_time;
 
 // These should be persistent.
 int32_t    MC::verbosity  = 0;
+#if !defined(__NetBSD__)
 ink_hrtime MC::last_flush = 0;
+#endif
 
 namespace
 {
