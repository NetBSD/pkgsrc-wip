$NetBSD$

--- src/VBox/Additions/x11/vboxvideo/pointer.c.orig	2019-10-10 18:28:12.000000000 +0000
+++ src/VBox/Additions/x11/vboxvideo/pointer.c
@@ -28,6 +28,8 @@
  * OTHER DEALINGS IN THE SOFTWARE.
  */
 
+#include "xorg-server.h"
+
 #ifndef PCIACCESS
 # include "xf86Pci.h"
 # include <Pci.h>
