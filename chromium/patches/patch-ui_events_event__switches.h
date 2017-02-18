$NetBSD$

--- ui/events/event_switches.h.orig	2017-02-02 02:03:13.000000000 +0000
+++ ui/events/event_switches.h
@@ -18,7 +18,7 @@ EVENTS_BASE_EXPORT extern const char kTo
 EVENTS_BASE_EXPORT extern const char kTouchEventsDisabled[];
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
