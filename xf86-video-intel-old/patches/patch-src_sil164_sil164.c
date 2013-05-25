$NetBSD: patch-src_sil164_sil164.c,v 1.1 2013/05/25 13:09:48 thomasklausner Exp $

--- src/sil164/sil164.c.orig	2009-04-08 23:59:48.000000000 +0000
+++ src/sil164/sil164.c
@@ -35,7 +35,6 @@ SOFTWARE OR THE USE OR OTHER DEALINGS IN
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "miscstruct.h"
 #include "xf86i2c.h"
