$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/ipc/service/image_transport_surface_overlay_mac.h.orig	2024-10-18 12:34:18.928091000 +0000
+++ gpu/ipc/service/image_transport_surface_overlay_mac.h
@@ -23,7 +23,9 @@
 #include "ui/display/types/display_constants.h"
 #endif
 
+#if !IS_MAS_BUILD()
 @class CAContext;
+#endif
 @class CALayer;
 
 namespace ui {
