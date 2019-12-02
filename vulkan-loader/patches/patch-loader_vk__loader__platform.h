$NetBSD$
* add netbsd support
--- loader/vk_loader_platform.h.orig	2019-09-18 15:49:42.194132122 +0000
+++ loader/vk_loader_platform.h
@@ -31,7 +31,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
 /* Linux-specific common code: */
 
 // Headers:
