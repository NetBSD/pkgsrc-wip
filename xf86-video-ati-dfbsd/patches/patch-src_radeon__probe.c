$NetBSD$

From DragonFly dports

Needed due to removed patches from graphics/libdrm.
Sometimes fails to probe for given PCI:0:0:60 and leaves everything in funny
state: no /dev/dri/card0 (devq-lsdri also) thou kms console works.
It looks like reprobing should be done like this.

--- src/radeon_probe.c.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon_probe.c
@@ -55,7 +55,7 @@
 #include "dri.h"
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #include <xf86_OSproc.h>
 #endif
 
@@ -101,7 +101,7 @@ static Bool radeon_kernel_mode_enabled(S
 
     busIdString = DRICreatePCIBusID(pci_dev);
     ret = drmCheckModesettingSupported(busIdString);
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     if (ret) {
       if (xf86LoadKernelModule("radeonkms"))
         ret = drmCheckModesettingSupported(busIdString);
