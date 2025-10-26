$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/memory/protected_memory_posix.cc.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/base/memory/protected_memory_posix.cc
@@ -6,7 +6,7 @@
 
 #include <sys/mman.h>
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -34,7 +34,7 @@ bool SetMemory(void* start, void* end, i
 }  // namespace
 
 namespace internal {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void CheckMemoryReadOnly(const void* ptr) {
   const uintptr_t page_start =
       bits::AlignDown(reinterpret_cast<uintptr_t>(ptr), GetPageSize());
