$NetBSD$

--- src/VBox/Additions/x11/vboxvideo/vboxvideo.c.orig	2019-10-10 18:28:12.000000000 +0000
+++ src/VBox/Additions/x11/vboxvideo/vboxvideo.c
@@ -44,6 +44,7 @@
 #include "vboxvideo.h"
 #include <VBoxVideoVBE.h>
 
+#include "xorg-server.h"
 /* Basic definitions and functions needed by all drivers. */
 #include "xf86.h"
 /* For video memory mapping. */
