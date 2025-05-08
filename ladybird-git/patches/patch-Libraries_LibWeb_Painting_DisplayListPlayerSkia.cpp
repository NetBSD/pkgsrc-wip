$NetBSD$

--- Libraries/LibWeb/Painting/DisplayListPlayerSkia.cpp.orig	2025-05-07 20:56:31.113857417 +0000
+++ Libraries/LibWeb/Painting/DisplayListPlayerSkia.cpp
@@ -18,7 +18,7 @@
 #include <effects/SkGradientShader.h>
 #include <effects/SkImageFilters.h>
 #include <effects/SkRuntimeEffect.h>
-#include <gpu/GrDirectContext.h>
+#include <gpu/ganesh/GrDirectContext.h>
 #include <gpu/ganesh/SkSurfaceGanesh.h>
 #include <pathops/SkPathOps.h>
 
