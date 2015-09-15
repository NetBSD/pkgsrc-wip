$NetBSD: patch-src_VBox_Additions_x11_vboxvideo_pointer.c,v 1.1 2015/09/15 20:56:04 tnn2 Exp $

--- src/VBox/Additions/x11/vboxvideo/pointer.c.orig	2015-09-08 07:03:17.000000000 +0000
+++ src/VBox/Additions/x11/vboxvideo/pointer.c
@@ -17,6 +17,8 @@
 
 #include <VBox/VBoxGuestLib.h>
 
+#include "xorg-server.h"
+
 #ifndef PCIACCESS
 # include <xf86Pci.h>
 # include <Pci.h>
