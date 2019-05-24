$NetBSD$

From graphics/mesa-dri: update to 18.3.1

https://reviews.freebsd.org/D17872

--- src/amd/vulkan/radv_device.c.orig	2019-04-23 23:49:39.000000000 +0000
+++ src/amd/vulkan/radv_device.c
@@ -51,6 +51,14 @@
 #include "compiler/glsl_types.h"
 #include "util/xmlpool.h"
 
+#ifndef CLOCK_MONOTONIC_RAW
+# ifdef CLOCK_MONOTONIC_FAST
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+# else
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+# endif
+#endif
+
 static int
 radv_device_get_cache_uuid(enum radeon_family family, void *uuid)
 {
