$NetBSD$

--- ui/events/event_switches.h.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/events/event_switches.h
@@ -18,7 +18,7 @@ EVENTS_BASE_EXPORT extern const char kTo
 EVENTS_BASE_EXPORT extern const char kTouchEventsDisabled[];
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
