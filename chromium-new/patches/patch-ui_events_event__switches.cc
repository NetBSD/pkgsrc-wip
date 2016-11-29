$NetBSD$

--- ui/events/event_switches.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/events/event_switches.cc
@@ -28,7 +28,7 @@ const char kTouchEventsDisabled[] = "dis
 const char kCompensateForUnstablePinchZoom[] =
     "compensate-for-unstable-pinch-zoom";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
