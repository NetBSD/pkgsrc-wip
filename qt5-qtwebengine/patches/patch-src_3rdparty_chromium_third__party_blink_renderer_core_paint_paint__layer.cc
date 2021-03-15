$NetBSD$

--- src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_layer.cc.orig	2020-07-15 18:56:48.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_layer.cc
@@ -108,7 +108,7 @@ namespace {
 static CompositingQueryMode g_compositing_query_mode =
     kCompositingQueriesAreOnlyAllowedInCertainDocumentLifecyclePhases;
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
 struct SameSizeAsPaintLayer : DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
