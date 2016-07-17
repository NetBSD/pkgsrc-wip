$NetBSD$

--- third_party/WebKit/Source/modules/battery/battery_status.h.orig	2016-06-24 01:02:46.000000000 +0000
+++ third_party/WebKit/Source/modules/battery/battery_status.h
@@ -46,7 +46,7 @@ class MODULES_EXPORT BatteryStatus final
     // of reducing the possibility of fingerprinting and triggers less level
     // change events on platforms where the granularity is high.
     ASSERT(level >= 0 && level <= 1);
-    return std::round(level * 100) / 100.f;
+    return round(level * 100) / 100.f;
   }
 
   bool charging_;
