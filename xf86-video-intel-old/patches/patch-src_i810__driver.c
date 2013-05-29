$NetBSD: patch-src_i810__driver.c,v 1.3 2013/05/29 13:59:38 makoto Exp $

--- src/i810_driver.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i810_driver.c
@@ -69,8 +69,6 @@ SOFTWARE OR THE USE OR OTHER DEALINGS IN
  */
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
-#include "xf86RAC.h"
 #include "xf86cmap.h"
 #include "compiler.h"
 #include "mibstore.h"
