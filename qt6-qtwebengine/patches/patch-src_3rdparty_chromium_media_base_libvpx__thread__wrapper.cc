$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/base/libvpx_thread_wrapper.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/media/base/libvpx_thread_wrapper.cc
@@ -5,17 +5,21 @@
 #include "media/base/libvpx_thread_wrapper.h"
 
 #include "media/base/codec_worker_impl.h"
+#if !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_NETBSD)
 #include "third_party/libvpx/source/libvpx/vpx_util/vpx_thread.h"
+#endif
 
 namespace media {
 
 void InitLibVpxThreadWrapper() {
+#if !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_NETBSD)
   const VPxWorkerInterface interface =
       CodecWorkerImpl<VPxWorkerInterface, VPxWorkerImpl, VPxWorker,
                       VPxWorkerStatus, NOT_OK, OK,
                       WORK>::GetCodecWorkerInterface();
 
   CHECK(vpx_set_worker_interface(&interface));
+#endif
 }
 
 }  // namespace media
