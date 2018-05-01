$NetBSD$

libdrm 2.4.88 does not have certain symbols defined in i915_drm.h.

--- src/mesa/drivers/dri/i965/intel_screen.h.orig	2017-11-20 14:25:47.000000000 +0000
+++ src/mesa/drivers/dri/i965/intel_screen.h
@@ -35,7 +35,7 @@
 #include "dri_util.h"
 #include "brw_bufmgr.h"
 #include "common/gen_device_info.h"
-#include "i915_drm.h"
+#include "drm-uapi/i915_drm.h"
 #include "util/xmlconfig.h"
 
 #include "isl/isl.h"
