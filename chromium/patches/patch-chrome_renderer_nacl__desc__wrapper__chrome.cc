$NetBSD: patch-chrome_renderer_nacl__desc__wrapper__chrome.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/nacl_desc_wrapper_chrome.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/nacl_desc_wrapper_chrome.cc
@@ -14,7 +14,7 @@ namespace nacl {
 DescWrapper* DescWrapperFactory::ImportPepperSharedMemory(intptr_t shm_int,
                                                           size_t size) {
   base::SharedMemory* shm = reinterpret_cast<base::SharedMemory*>(shm_int);
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_POSIX)
   return ImportShmHandle(shm->handle().fd, size);
 #elif defined(OS_WIN)
   return ImportShmHandle(shm->handle(), size);
@@ -28,7 +28,7 @@ DescWrapper* DescWrapperFactory::ImportP
 #if defined(OS_LINUX)
   // TransportDIBs use SysV (X) shared memory on Linux.
   return ImportSysvShm(dib->handle(), dib->size());
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   // TransportDIBs use mmap shared memory on OSX.
   return ImportShmHandle(dib->handle().fd, dib->size());
 #elif defined(OS_WIN)
