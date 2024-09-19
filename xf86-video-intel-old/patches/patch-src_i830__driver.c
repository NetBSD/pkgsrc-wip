$NetBSD: patch-src_i830__driver.c,v 1.3 2013/05/29 13:59:38 makoto Exp $

--- src/i830_driver.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i830_driver.c
@@ -175,7 +175,6 @@ USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "xf86RAC.h"
 #include "xf86Priv.h"
 #include "xf86cmap.h"
