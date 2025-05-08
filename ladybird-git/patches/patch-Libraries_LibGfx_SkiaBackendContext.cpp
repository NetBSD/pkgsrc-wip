$NetBSD$

--- Libraries/LibGfx/SkiaBackendContext.cpp.orig	2025-05-07 20:18:55.439582715 +0000
+++ Libraries/LibGfx/SkiaBackendContext.cpp
@@ -10,7 +10,7 @@
 #include <LibGfx/SkiaBackendContext.h>
 
 #include <core/SkSurface.h>
-#include <gpu/GrDirectContext.h>
+#include <gpu/ganesh/GrDirectContext.h>
 
 #ifdef USE_VULKAN
 #    include <gpu/ganesh/vk/GrVkDirectContext.h>
