$NetBSD$

WITH_GETLINE patch from FreeBSD ports libdrm 2.4.75.

Patch to use "i915kms" as module name from FreeBSD ports libdrm 2.4.75.

From DragonFly dports x11-drivers/xf86-video-intel29 2.99.2017.01.06
patch for drmCheckModesettingSupported() always returning 0.

--- src/intel_device.c.orig	2017-02-28 20:52:19.000000000 +0000
+++ src/intel_device.c
@@ -28,6 +28,11 @@
 #include "config.h"
 #endif
 
+#if defined(__FreeBSD__)
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+#endif
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
@@ -204,6 +209,9 @@ static inline struct intel_device *intel
 }
 
 static const char *kernel_module_names[] ={
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+	"i915kms",
+#endif
 	"i915",
 	NULL,
 };
@@ -425,7 +433,11 @@ static int __intel_open_device__legacy(c
 		 pci->domain, pci->bus, pci->dev, pci->func);
 
 	ret = drmCheckModesettingSupported(id);
+#if defined(__DragonFly__)
+	if (ret || 1) {
+#else
 	if (ret) {
+#endif
 		if (load_i915_kernel_module() == 0)
 			ret = drmCheckModesettingSupported(id);
 		if (ret)
