$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/src/node.cc.orig	2026-11-23 18:17:13.476616793 +0000
+++ third_party/electron_node/src/node.cc
@@ -87,7 +87,7 @@
 
 #include "large_pages/node_large_page.h"
 
-#if defined(__APPLE__) || defined(__linux__) || defined(_WIN32)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(_WIN32)
 #define NODE_USE_V8_WASM_TRAP_HANDLER 1
 #else
 #define NODE_USE_V8_WASM_TRAP_HANDLER 0
