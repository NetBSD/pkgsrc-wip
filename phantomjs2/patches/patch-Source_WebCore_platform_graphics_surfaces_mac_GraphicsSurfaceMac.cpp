$NetBSD: patch-Source_WebCore_platform_graphics_surfaces_mac_GraphicsSurfaceMac.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

Correct includes.

--- src/qt/qtwebkit/Source/WebCore/platform/graphics/surfaces/mac/GraphicsSurfaceMac.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebCore/platform/graphics/surfaces/mac/GraphicsSurfaceMac.cpp
@@ -23,9 +23,9 @@
 #if USE(GRAPHICS_SURFACE) && OS(DARWIN)
 #include "TextureMapperGL.h"
 #include <CoreFoundation/CFNumber.h>
-#include <CGLContext.h>
-#include <CGLCurrent.h>
-#include <CGLIOSurface.h>
+#include <OpenGL/CGLContext.h>
+#include <OpenGL/CGLCurrent.h>
+#include <OpenGL/CGLIOSurface.h>
 #include <IOSurface/IOSurface.h>
 #include <OpenGL/OpenGL.h>
 #include <OpenGL/gl.h>
