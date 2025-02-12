$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/base/libaom_thread_wrapper.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/media/base/libaom_thread_wrapper.cc
@@ -5,16 +5,20 @@
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
                       AVxWorkerStatus, NOT_OK, OK,
                       WORK>::GetCodecWorkerInterface();
   CHECK(aom_set_worker_interface(&interface));
+#endif
 }
 
 }  // namespace media
