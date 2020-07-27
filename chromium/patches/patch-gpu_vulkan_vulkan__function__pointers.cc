$NetBSD$

--- gpu/vulkan/vulkan_function_pointers.cc.orig	2020-07-08 21:40:44.000000000 +0000
+++ gpu/vulkan/vulkan_function_pointers.cc
@@ -862,7 +862,7 @@ bool VulkanFunctionPointers::BindDeviceF
   }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME)) {
     vkGetSemaphoreFdKHR = reinterpret_cast<PFN_vkGetSemaphoreFdKHR>(
@@ -906,7 +906,7 @@ bool VulkanFunctionPointers::BindDeviceF
   }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME)) {
     vkGetMemoryFdKHR = reinterpret_cast<PFN_vkGetMemoryFdKHR>(
