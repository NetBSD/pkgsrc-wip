$NetBSD$

Patches from FreeBSD ports x11-drivers/xf86-video-intel

* WITH_GETLINE patch.

* Patch to use "i915kms" as module name from FreeBSD ports
x11-drivers/xf86-video-intel.

Patch from DragonFly dports x11-drivers/xf86-video-intel29

* i915 does not use hw.dri.0.busid so simplify to basics.

--- src/intel_device.c.orig	2018-05-12 09:01:10.000000000 +0000
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
+#if defined(__FreeBSD__)
+	"i915kms",
+#endif
 	"i915",
 	NULL,
 };
@@ -424,6 +432,10 @@ static int __intel_open_device__legacy(c
 		 "pci:%04x:%02x:%02x.%d",
 		 pci->domain, pci->bus, pci->dev, pci->func);
 
+#if defined(__DragonFly__)
+	/* assume modesetting for i915, allow multiple loads and no fbcon */
+	load_i915_kernel_module();
+#else
 	ret = drmCheckModesettingSupported(id);
 	if (ret) {
 		if (load_i915_kernel_module() == 0)
@@ -433,6 +445,7 @@ static int __intel_open_device__legacy(c
 		/* Be nice to the user and load fbcon too */
 		(void)xf86LoadKernelModule("fbcon");
 	}
+#endif
 
 	return fd_set_nonblock(drmOpen(NULL, id));
 }
