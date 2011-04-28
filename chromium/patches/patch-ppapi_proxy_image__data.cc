$NetBSD: patch-ppapi_proxy_image__data.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- ppapi/proxy/image_data.cc.orig	2011-04-13 08:01:10.000000000 +0000
+++ ppapi/proxy/image_data.cc
@@ -8,7 +8,7 @@
 #include <sys/shm.h>
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include <sys/stat.h>
 #include <sys/mman.h>
 #endif
@@ -37,7 +37,7 @@ void* ImageData::Map() {
 #if defined(OS_WIN)
   NOTIMPLEMENTED();
   return NULL;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   struct stat st;
   if (fstat(handle_.fd, &st) != 0)
     return NULL;
@@ -62,7 +62,7 @@ void* ImageData::Map() {
 void ImageData::Unmap() {
 #if defined(OS_WIN)
   NOTIMPLEMENTED();
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   if (mapped_data_) {
     struct stat st;
     if (fstat(handle_.fd, &st) == 0)
@@ -77,7 +77,7 @@ void ImageData::Unmap() {
 
 #if defined(OS_WIN)
 const ImageHandle ImageData::NullHandle = NULL;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
 const ImageHandle ImageData::NullHandle = ImageHandle();
 #else
 const ImageHandle ImageData::NullHandle = 0;
@@ -86,7 +86,7 @@ const ImageHandle ImageData::NullHandle 
 ImageHandle ImageData::HandleFromInt(int32_t i) {
 #if defined(OS_WIN)
     return reinterpret_cast<ImageHandle>(i);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
     return ImageHandle(i, false);
 #else
     return static_cast<ImageHandle>(i);
