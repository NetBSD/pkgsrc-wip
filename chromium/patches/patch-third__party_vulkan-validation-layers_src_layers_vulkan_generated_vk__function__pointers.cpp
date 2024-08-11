$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/vulkan-validation-layers/src/layers/vulkan/generated/vk_function_pointers.cpp.orig	2024-07-24 02:45:48.887779700 +0000
+++ third_party/vulkan-validation-layers/src/layers/vulkan/generated/vk_function_pointers.cpp
@@ -53,7 +53,8 @@ static void *get_proc_address(dl_handle 
     assert(name);
     return (void *)GetProcAddress(library, name);
 }
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || \
+         defined(__NetBSD__)
 
 #include <dlfcn.h>
 
