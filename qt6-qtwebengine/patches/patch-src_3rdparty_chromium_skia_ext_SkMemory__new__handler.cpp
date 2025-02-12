$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/skia/ext/SkMemory_new_handler.cpp.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/skia/ext/SkMemory_new_handler.cpp
@@ -86,7 +86,7 @@ static void* malloc_nothrow(size_t size)
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   result = malloc(size);
 #else
   // It's the responsibility of the caller to check the return value.
