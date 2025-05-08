$NetBSD$

--- Libraries/LibGfx/PaintingSurface.cpp.orig	2025-05-07 20:19:18.293923340 +0000
+++ Libraries/LibGfx/PaintingSurface.cpp
@@ -10,8 +10,8 @@
 
 #include <core/SkColorSpace.h>
 #include <core/SkSurface.h>
-#include <gpu/GrBackendSurface.h>
-#include <gpu/GrDirectContext.h>
+#include <gpu/ganesh/GrBackendSurface.h>
+#include <gpu/ganesh/GrDirectContext.h>
 #include <gpu/ganesh/SkSurfaceGanesh.h>
 
 #ifdef AK_OS_MACOS
