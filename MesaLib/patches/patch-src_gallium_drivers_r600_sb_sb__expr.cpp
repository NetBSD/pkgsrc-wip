$NetBSD: patch-src_gallium_drivers_r600_sb_sb__expr.cpp,v 1.2 2015/04/05 16:43:19 tnn2 Exp $

--- src/gallium/drivers/r600/sb/sb_expr.cpp.orig	2015-03-21 00:51:18.000000000 +0000
+++ src/gallium/drivers/r600/sb/sb_expr.cpp
@@ -25,6 +25,17 @@
  */
 
 #include <cmath>
+#include <sys/param.h>
+#if defined(__NetBSD__) && __NetBSD_Version__ < 600000000
+#if defined(exp2f)
+#undef exp2f
+#endif
+#define exp2f(x) powf(2.0f,x)
+#if defined(exp2)
+#undef exp2
+#endif
+#define exp2(x) pow(2.0d,x)
+#endif
 
 #include "sb_shader.h"
 
