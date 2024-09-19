$NetBSD$

--- src/kml/base/contrib/minizip/unzip.c.orig	2015-12-21 17:23:05.000000000 +0000
+++ src/kml/base/contrib/minizip/unzip.c
@@ -42,7 +42,10 @@ woven in by Terry Thorsen 1/2003.
 #include <zlib.h> //RR
 #include "unzip.h"
 #include "iomem_simple.h"
-#undef NOUNCRYPT
+
+#ifndef NOUNCRYPT
+#define NOUNCRYPT
+#endif
 
 #ifdef STDC
 #  include <stddef.h>
