$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/ipc/service/image_transport_surface_overlay_mac.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ gpu/ipc/service/image_transport_surface_overlay_mac.h
@@ -8,6 +8,7 @@
 #include <vector>
 
 #include "base/memory/weak_ptr.h"
+#include "electron/mas.h"
 #include "gpu/ipc/service/command_buffer_stub.h"
 #include "gpu/ipc/service/image_transport_surface.h"
 #include "ui/gfx/ca_layer_result.h"
@@ -23,7 +24,9 @@
 #include "ui/display/types/display_constants.h"
 #endif
 
+#if !IS_MAS_BUILD()
 @class CAContext;
+#endif
 @class CALayer;
 
 namespace ui {
