$NetBSD$

Disable dma buf renderer by default.

--- Source/WebKit/UIProcess/gtk/AcceleratedBackingStoreDMABuf.cpp.orig	2024-08-28 09:05:36.303747400 +0000
+++ Source/WebKit/UIProcess/gtk/AcceleratedBackingStoreDMABuf.cpp
@@ -71,7 +71,11 @@ OptionSet<DMABufRendererBufferMode> Acce
     static OptionSet<DMABufRendererBufferMode> mode;
     static std::once_flag onceFlag;
     std::call_once(onceFlag, [] {
+#if defined(__NetBSD__)
+        const char* disableDMABuf = "1";
+#else
         const char* disableDMABuf = getenv("WEBKIT_DISABLE_DMABUF_RENDERER");
+#endif
         if (disableDMABuf && strcmp(disableDMABuf, "0"))
             return;
 
