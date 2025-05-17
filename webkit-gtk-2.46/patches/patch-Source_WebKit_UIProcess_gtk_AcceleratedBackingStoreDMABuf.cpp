$NetBSD$

Disable dma buf renderer by default.

--- Source/WebKit/UIProcess/gtk/AcceleratedBackingStoreDMABuf.cpp.orig	2025-02-25 08:25:42.127409200 +0000
+++ Source/WebKit/UIProcess/gtk/AcceleratedBackingStoreDMABuf.cpp
@@ -82,7 +82,11 @@ OptionSet<RendererBufferTransportMode> A
     static OptionSet<RendererBufferTransportMode> mode;
     static std::once_flag onceFlag;
     std::call_once(onceFlag, [] {
+#if defined(__NetBSD__)
+        const char* disableDMABuf = "1";
+#else
         const char* disableDMABuf = getenv("WEBKIT_DISABLE_DMABUF_RENDERER");
+#endif
         if (disableDMABuf && strcmp(disableDMABuf, "0"))
             return;
 
