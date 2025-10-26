$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/vulkan-validation-layers/src/layers/vulkan/generated/vk_function_pointers.cpp.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/third_party/vulkan-validation-layers/src/layers/vulkan/generated/vk_function_pointers.cpp
@@ -53,7 +53,7 @@ static void *get_proc_address(dl_handle 
     assert(name);
     return (void *)GetProcAddress(library, name);
 }
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || defined(__NetBSD__)
 
 #include <dlfcn.h>
 
