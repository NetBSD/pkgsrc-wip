$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc
@@ -557,6 +557,7 @@ void RTCDataChannel::send(Blob* data, Ex
   pending_messages_.push_back(message);
 }
 
+#undef close
 void RTCDataChannel::close() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   if (state_ == webrtc::DataChannelInterface::kClosing ||
