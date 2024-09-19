$NetBSD: patch-Source_WebCore_platform_graphics_surfaces_GraphicsSurfaceToken.h,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Treat *BSD like Linux

--- src/qt/qtwebkit/Source/WebCore/platform/graphics/surfaces/GraphicsSurfaceToken.h.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebCore/platform/graphics/surfaces/GraphicsSurfaceToken.h
@@ -35,7 +35,7 @@ struct GraphicsSurfaceToken {
 
 #if OS(DARWIN)
     typedef mach_port_t BufferHandle;
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
     typedef uint32_t BufferHandle;
 #elif OS(WINDOWS)
     typedef HANDLE BufferHandle;
