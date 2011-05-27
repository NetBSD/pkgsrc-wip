$NetBSD: patch-ppapi_proxy_ppb__image__data__proxy.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ppapi/proxy/ppb_image_data_proxy.cc.orig	2011-05-24 08:01:06.000000000 +0000
+++ ppapi/proxy/ppb_image_data_proxy.cc
@@ -23,7 +23,7 @@
 
 #if defined(OS_LINUX)
 #include <sys/shm.h>
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
 #include <sys/stat.h>
 #include <sys/mman.h>
 #endif
@@ -80,7 +80,7 @@ void* ImageData::Map() {
 #if defined(OS_WIN)
   NOTIMPLEMENTED();
   return NULL;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   struct stat st;
   if (fstat(handle_.fd, &st) != 0)
     return NULL;
@@ -105,7 +105,7 @@ void* ImageData::Map() {
 void ImageData::Unmap() {
 #if defined(OS_WIN)
   NOTIMPLEMENTED();
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   if (mapped_data_) {
     struct stat st;
     if (fstat(handle_.fd, &st) == 0)
@@ -120,7 +120,7 @@ void ImageData::Unmap() {
 
 #if defined(OS_WIN)
 const ImageHandle ImageData::NullHandle = NULL;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
 const ImageHandle ImageData::NullHandle = ImageHandle();
 #else
 const ImageHandle ImageData::NullHandle = 0;
@@ -129,7 +129,7 @@ const ImageHandle ImageData::NullHandle 
 ImageHandle ImageData::HandleFromInt(int32_t i) {
 #if defined(OS_WIN)
     return reinterpret_cast<ImageHandle>(i);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
     return ImageHandle(i, false);
 #else
     return static_cast<ImageHandle>(i);
