$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/vulkan/vulkan_function_pointers.h.orig	2024-10-18 12:34:18.936087000 +0000
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -322,7 +322,7 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFu
   VulkanFunction<PFN_vkGetSwapchainImagesKHR> vkGetSwapchainImagesKHR;
   VulkanFunction<PFN_vkQueuePresentKHR> vkQueuePresentKHR;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   VulkanFunction<PFN_vkGetImageDrmFormatModifierPropertiesEXT>
       vkGetImageDrmFormatModifierPropertiesEXT;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -1336,7 +1336,7 @@ ALWAYS_INLINE VkResult vkQueuePresentKHR
                                                              pPresentInfo);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 ALWAYS_INLINE VkResult vkGetImageDrmFormatModifierPropertiesEXT(
     VkDevice device,
     VkImage image,
@@ -1346,4 +1346,4 @@ ALWAYS_INLINE VkResult vkGetImageDrmForm
 }
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
\ No newline at end of file
+#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
