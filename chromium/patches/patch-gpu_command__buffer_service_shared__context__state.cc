$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_context_state.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ gpu/command_buffer/service/shared_context_state.cc
@@ -65,7 +65,7 @@
 #include "gpu/vulkan/vulkan_implementation.h"
 #include "gpu/vulkan/vulkan_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/external_semaphore_pool.h"
 #endif
 
@@ -304,7 +304,7 @@ SharedContextState::SharedContextState(
   if (gr_context_type_ == GrContextType::kVulkan) {
     if (vk_context_provider_) {
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
       external_semaphore_pool_ = std::make_unique<ExternalSemaphorePool>(this);
 #endif
       use_virtualized_gl_contexts_ = false;
@@ -341,7 +341,7 @@ SharedContextState::~SharedContextState(
   }
 
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   external_semaphore_pool_.reset();
 #endif
 
