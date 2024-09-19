$NetBSD: patch-src_ch7xxx_ch7xxx.c,v 1.3 2013/05/29 13:59:38 makoto Exp $

--- src/ch7xxx/ch7xxx.c.orig	2009-04-08 23:59:47.000000000 +0000
+++ src/ch7xxx/ch7xxx.c
@@ -34,7 +34,6 @@ SOFTWARE OR THE USE OR OTHER DEALINGS IN
 #include <string.h>
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "miscstruct.h"
 #include "xf86i2c.h"
