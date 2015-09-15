$NetBSD: patch-src_VBox_Additions_x11_vboxvideo_vboxvideo.c,v 1.1 2015/09/15 20:56:04 tnn2 Exp $

--- src/VBox/Additions/x11/vboxvideo/vboxvideo.c.orig	2015-09-08 07:03:17.000000000 +0000
+++ src/VBox/Additions/x11/vboxvideo/vboxvideo.c
@@ -62,6 +62,7 @@
 #include "product-generated.h"
 #include "revision-generated.h"
 
+#include "xorg-server.h"
 /* Basic definitions and functions needed by all drivers. */
 #include "xf86.h"
 /* For video memory mapping. */
