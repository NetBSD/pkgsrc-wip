$NetBSD$

--- ui/events/event_switches.h.orig	2016-06-24 01:02:52.000000000 +0000
+++ ui/events/event_switches.h
@@ -18,7 +18,7 @@ EVENTS_BASE_EXPORT extern const char kTo
 EVENTS_BASE_EXPORT extern const char kTouchEventsDisabled[];
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
