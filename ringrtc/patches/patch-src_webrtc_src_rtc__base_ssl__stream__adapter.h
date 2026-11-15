$NetBSD$

* Fix build with system libcxx

--- src/webrtc/src/rtc_base/ssl_stream_adapter.h.orig	2026-11-11 19:19:22.149794513 +0000
+++ src/webrtc/src/rtc_base/ssl_stream_adapter.h
@@ -129,7 +129,7 @@ class SSLStreamAdapter : public StreamIn
   static std::unique_ptr<SSLStreamAdapter> Create(
       std::unique_ptr<StreamInterface> stream,
       absl::AnyInvocable<void(SSLHandshakeError)> handshake_error,
-      nullptr_t /*field_trials*/) {
+      std::nullptr_t /*field_trials*/) {
     return Create(std::move(stream), std::move(handshake_error));
   }
 
