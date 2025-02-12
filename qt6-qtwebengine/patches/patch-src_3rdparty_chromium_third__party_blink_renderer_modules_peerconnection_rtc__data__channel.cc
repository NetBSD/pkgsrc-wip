$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc
@@ -493,6 +493,7 @@ void RTCDataChannel::send(Blob* data, Ex
   ThrowNoBlobSupportException(&exception_state);
 }
 
+#undef close
 void RTCDataChannel::close() {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   if (state_ == webrtc::DataChannelInterface::kClosing ||
