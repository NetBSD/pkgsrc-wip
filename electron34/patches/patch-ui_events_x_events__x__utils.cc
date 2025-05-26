$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/events/x/events_x_utils.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/events/x/events_x_utils.cc
@@ -591,6 +591,9 @@ gfx::Point EventLocationFromXEvent(const
 gfx::Point EventSystemLocationFromXEvent(const x11::Event& xev) {
   if (auto* crossing = xev.As<x11::CrossingEvent>())
     return gfx::Point(crossing->root_x, crossing->root_y);
+  if (auto* crossing = xev.As<x11::Input::CrossingEvent>())
+    return gfx::Point(Fp1616ToDouble(crossing->root_x),
+                      Fp1616ToDouble(crossing->root_y));
   if (auto* button = xev.As<x11::ButtonEvent>())
     return gfx::Point(button->root_x, button->root_y);
   if (auto* motion = xev.As<x11::MotionNotifyEvent>())
