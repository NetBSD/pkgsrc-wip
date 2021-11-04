$NetBSD$

--- platforms/Cross/plugins/SqueakFFIPrims/sqFFIPlugin.c.orig	2018-10-19 04:12:21.000000000 +0000
+++ platforms/Cross/plugins/SqueakFFIPrims/sqFFIPlugin.c
@@ -7,11 +7,10 @@
 *
 *****************************************************************************/
 
+#include "sq.h"
+
 #include <stdio.h>
 #include <stdlib.h> /* proto for alloca in MINGW */
-#if !_WIN32 && !__FreeBSD__ && !__OpenBSD__
-# include <alloca.h>
-#endif
 #include <string.h>
 
 #ifdef _MSC_VER
