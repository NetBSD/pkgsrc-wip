$NetBSD$

--- content/browser/time_zone_monitor.cc.orig	2016-06-24 01:02:20.000000000 +0000
+++ content/browser/time_zone_monitor.cc
@@ -29,7 +29,7 @@ void TimeZoneMonitor::NotifyRenderers() 
   scoped_ptr<icu::TimeZone> new_zone(icu::TimeZone::createDefault());
 #else
   icu::TimeZone* new_zone = icu::TimeZone::detectHostTimeZone();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // We get here multiple times on Linux per a single tz change, but
   // want to update the ICU default zone and notify renderer only once.
   scoped_ptr<icu::TimeZone> current_zone(icu::TimeZone::createDefault());
