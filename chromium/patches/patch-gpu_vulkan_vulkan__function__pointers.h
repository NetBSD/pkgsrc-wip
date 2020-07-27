$NetBSD$

--- gpu/vulkan/vulkan_function_pointers.h.orig	2020-07-08 21:40:44.000000000 +0000
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -234,7 +234,7 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFu
       vkGetAndroidHardwareBufferPropertiesANDROID;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetSemaphoreFdKHR> vkGetSemaphoreFdKHR;
   VulkanFunction<PFN_vkImportSemaphoreFdKHR> vkImportSemaphoreFdKHR;
 #endif  // defined(OS_LINUX) || defined(OS_ANDROID)
@@ -245,7 +245,7 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFu
       vkImportSemaphoreWin32HandleKHR;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetMemoryFdKHR> vkGetMemoryFdKHR;
   VulkanFunction<PFN_vkGetMemoryFdPropertiesKHR> vkGetMemoryFdPropertiesKHR;
 #endif  // defined(OS_LINUX) || defined(OS_ANDROID)
@@ -953,7 +953,7 @@ ALWAYS_INLINE VkResult vkGetAndroidHardw
 }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 ALWAYS_INLINE VkResult
 vkGetSemaphoreFdKHR(VkDevice device,
                     const VkSemaphoreGetFdInfoKHR* pGetFdInfo,
@@ -986,7 +986,7 @@ vkImportSemaphoreWin32HandleKHR(VkDevice
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 ALWAYS_INLINE VkResult vkGetMemoryFdKHR(VkDevice device,
                                         const VkMemoryGetFdInfoKHR* pGetFdInfo,
                                         int* pFd) {
@@ -1081,4 +1081,4 @@ ALWAYS_INLINE VkResult vkQueuePresentKHR
                                                              pPresentInfo);
 }
 
-#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
\ No newline at end of file
+#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
