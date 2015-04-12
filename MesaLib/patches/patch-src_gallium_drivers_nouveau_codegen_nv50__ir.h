$NetBSD: patch-src_gallium_drivers_nouveau_codegen_nv50__ir.h,v 1.1 2015/04/12 19:32:06 tnn2 Exp $

--- src/gallium/drivers/nouveau/codegen/nv50_ir.h.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/gallium/drivers/nouveau/codegen/nv50_ir.h
@@ -30,6 +30,18 @@
 #include <list>
 #include <vector>
 #include <tr1/unordered_set>
+#include <cmath>
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
 
 #include "codegen/nv50_ir_util.h"
 #include "codegen/nv50_ir_graph.h"
