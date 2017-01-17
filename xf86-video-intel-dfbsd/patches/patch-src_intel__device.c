$NetBSD$

From past DragonFly dports x11-drivers/xf86-video-intel29 and FreeBSD ports

--- src/intel_device.c.orig	2014-11-18 21:50:39.000000000 +0000
+++ src/intel_device.c
@@ -398,8 +398,16 @@ static int __intel_open_device__legacy(c
 		 pci->domain, pci->bus, pci->dev, pci->func);
 
 	ret = drmCheckModesettingSupported(id);
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+	if (ret || 1) {
+		if (xf86LoadKernelModule("i915kms"))
+#elif defined(__DragonFly__)
+	if (ret || 1) {
+		if (xf86LoadKernelModule("i915"))
+#else
 	if (ret) {
 		if (xf86LoadKernelModule("i915"))
+#endif
 			ret = drmCheckModesettingSupported(id);
 		if (ret)
 			return -1;
