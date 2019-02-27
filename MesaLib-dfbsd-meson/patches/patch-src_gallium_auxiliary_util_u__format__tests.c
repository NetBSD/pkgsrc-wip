$NetBSD: patch-src_gallium_auxiliary_util_u__format__tests.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

On old NetBSD, NAN in math.h is __nanf.__val. Which is not constant.

--- src/gallium/auxiliary/util/u_format_tests.c.orig	2019-01-04 23:59:59.000000000 +0000
+++ src/gallium/auxiliary/util/u_format_tests.c
@@ -28,6 +28,10 @@
 
 #include <math.h>
 #include <float.h>
+#if defined(__NetBSD__) && __NetBSD_Version__ < 600000000
+#undef NAN
+#define NAN __builtin_nanf("")
+#endif
 
 #include "pipe/p_config.h"
 #include "util/u_memory.h"
