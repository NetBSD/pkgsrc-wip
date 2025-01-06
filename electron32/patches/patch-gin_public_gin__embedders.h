$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/public/gin_embedders.h.orig	2024-10-18 12:34:18.336388300 +0000
+++ gin/public/gin_embedders.h
@@ -18,6 +18,8 @@ namespace gin {
 enum GinEmbedder : uint16_t {
   kEmbedderNativeGin,
   kEmbedderBlink,
+  kEmbedderElectron,
+  kEmbedderBlinkTag,
   kEmbedderPDFium,
   kEmbedderFuchsia,
 };
