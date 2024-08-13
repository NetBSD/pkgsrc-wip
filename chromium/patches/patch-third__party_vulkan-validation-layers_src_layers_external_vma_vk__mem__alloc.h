$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/vulkan-validation-layers/src/layers/external/vma/vk_mem_alloc.h.orig	2024-08-06 19:53:30.195454600 +0000
+++ third_party/vulkan-validation-layers/src/layers/external/vma/vk_mem_alloc.h
@@ -2740,7 +2740,7 @@ static void* vma_aligned_alloc(size_t al
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
+#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC)) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <cstdlib>
 
 #if defined(__APPLE__)
