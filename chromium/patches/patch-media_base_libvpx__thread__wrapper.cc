$NetBSD: patch-media_base_libvpx__thread__wrapper.cc,v 1.1 2025/02/06 09:58:11 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/libvpx_thread_wrapper.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/base/libvpx_thread_wrapper.cc
@@ -5,11 +5,14 @@
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
                       VPxWorkerStatus, VPX_WORKER_STATUS_NOT_OK,
@@ -17,6 +20,7 @@ void InitLibVpxThreadWrapper() {
                       VPX_WORKER_STATUS_WORKING>::GetCodecWorkerInterface();
 
   CHECK(vpx_set_worker_interface(&interface));
+#endif
 }
 
 }  // namespace media
