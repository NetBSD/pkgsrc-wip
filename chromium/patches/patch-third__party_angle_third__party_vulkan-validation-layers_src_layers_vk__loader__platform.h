$NetBSD$

--- third_party/angle/third_party/vulkan-validation-layers/src/layers/vk_loader_platform.h.orig	2020-07-15 19:01:42.000000000 +0000
+++ third_party/angle/third_party/vulkan-validation-layers/src/layers/vk_loader_platform.h
@@ -33,7 +33,7 @@
 #undef NOMINMAX
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 /* Linux-specific common code: */
 
 // Headers:
