$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/gpu/chromeos/gl_image_processor_backend.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/gpu/chromeos/gl_image_processor_backend.cc
@@ -28,6 +28,10 @@
 #include "ui/ozone/public/ozone_platform.h"
 #include "ui/ozone/public/surface_factory_ozone.h"
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
 namespace media {
 
 namespace {
