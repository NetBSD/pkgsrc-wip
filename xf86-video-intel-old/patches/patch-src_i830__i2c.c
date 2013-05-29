$NetBSD: patch-src_i830__i2c.c,v 1.3 2013/05/29 13:59:38 makoto Exp $

--- src/i830_i2c.c.orig	2009-04-08 23:59:48.000000000 +0000
+++ src/i830_i2c.c
@@ -31,7 +31,6 @@ USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "xf86RAC.h"
 #include "xf86cmap.h"
 #include "compiler.h"
