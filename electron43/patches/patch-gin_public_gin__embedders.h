$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/public/gin_embedders.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/public/gin_embedders.h
@@ -20,6 +20,8 @@ enum GinEmbedder : uint16_t {
   kEmbedderBlink,
   kEmbedderPDFium,
   kEmbedderFuchsia,
+  kEmbedderElectron,
+  kEmbedderBlinkTag,
 };
 
 }  // namespace gin
