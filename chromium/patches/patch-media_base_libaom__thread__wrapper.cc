$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/libaom_thread_wrapper.cc.orig	2024-07-24 02:44:41.005204400 +0000
+++ media/base/libaom_thread_wrapper.cc
@@ -5,17 +5,21 @@
 #include "base/logging.h"
 #include "media/base/codec_worker_impl.h"
 #include "media/base/libvpx_thread_wrapper.h"
+#if !BUILDFLAG(IS_BSD)
 #include "third_party/libaom/source/libaom/aom_util/aom_thread.h"
+#endif
 
 namespace media {
 
 void InitLibAomThreadWrapper() {
+#if !BUILDFLAG(IS_BSD)
   const AVxWorkerInterface interface =
       CodecWorkerImpl<AVxWorkerInterface, AVxWorkerImpl, AVxWorker,
                       AVxWorkerStatus, AVX_WORKER_STATUS_NOT_OK,
                       AVX_WORKER_STATUS_OK,
                       AVX_WORKER_STATUS_WORKING>::GetCodecWorkerInterface();
   CHECK(aom_set_worker_interface(&interface));
+#endif
 }
 
 }  // namespace media
