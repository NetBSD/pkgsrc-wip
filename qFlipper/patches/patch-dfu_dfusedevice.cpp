$NetBSD$

Work around NetBSD <math.h> namespace bugs.

--- dfu/dfusedevice.cpp.orig	2023-11-10 09:40:31.000000000 +0000
+++ dfu/dfusedevice.cpp
@@ -1,3 +1,7 @@
+#ifdef __NetBSD__
+#define	_NETBSD_SOURCE		// PR lib/57960, https://gnats.NetBSD.org/57960
+#endif
+
 #include "dfusedevice.h"
 
 #include <cmath>
