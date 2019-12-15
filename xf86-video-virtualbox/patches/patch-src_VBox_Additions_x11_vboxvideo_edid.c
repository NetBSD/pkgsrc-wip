$NetBSD$

--- src/VBox/Additions/x11/vboxvideo/edid.c.orig	2019-11-29 19:39:42.639615817 +0000
+++ src/VBox/Additions/x11/vboxvideo/edid.c
@@ -35,6 +35,7 @@
  *    Michael Thayer <michael.thayer@oracle.com>
  */
 
+#include "xorg-server.h"
 #include "misc.h"
 #include "xf86DDC.h"
 #include "xf86Crtc.h"
