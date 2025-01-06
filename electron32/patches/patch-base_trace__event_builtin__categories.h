$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/trace_event/builtin_categories.h.orig	2024-10-18 12:33:59.858222500 +0000
+++ base/trace_event/builtin_categories.h
@@ -88,6 +88,7 @@
   X("drm")                                                               \
   X("drmcursor")                                                         \
   X("dwrite")                                                            \
+  X("electron")                                                          \
   X("evdev")                                                             \
   X("event")                                                             \
   X("exo")                                                               \
