$NetBSD$

--- third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h.orig	2020-07-15 19:01:32.000000000 +0000
+++ third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h
@@ -19,7 +19,7 @@ bool IsVulkanWin32DisplayAvailable();
 DisplayImpl *CreateVulkanWin32Display(const egl::DisplayState &state);
 #endif  // defined(ANGLE_PLATFORM_WINDOWS)
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool IsVulkanXcbDisplayAvailable();
 DisplayImpl *CreateVulkanXcbDisplay(const egl::DisplayState &state);
 #endif  // defined(ANGLE_PLATFORM_LINUX)
