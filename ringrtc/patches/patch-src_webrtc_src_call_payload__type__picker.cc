$NetBSD$

* Fix build with system libcxx

--- src/webrtc/src/call/payload_type_picker.cc.orig	2026-11-12 14:54:25.001398765 +0000
+++ src/webrtc/src/call/payload_type_picker.cc
@@ -370,7 +370,7 @@ void PayloadTypeRecorder::Rollback() {
 RTCError RtpHeaderExtensionRecorder::AddMapping(RtpHeaderExtensionId id,
                                                 absl::string_view uri,
                                                 bool encrypt) {
-  auto it = uri_to_id_.find(std::pair{uri, encrypt});
+  auto it = uri_to_id_.find(std::pair<std::string, bool>(std::string(uri), encrypt));
   if (it != uri_to_id_.end()) {
     if (it->second != id) {
       RTC_HISTOGRAM_BOOLEAN(
@@ -393,7 +393,7 @@ RTCError RtpHeaderExtensionRecorder::Add
 RTCErrorOr<RtpHeaderExtensionId> RtpHeaderExtensionRecorder::LookupId(
     absl::string_view uri,
     bool encrypt) const {
-  auto it = uri_to_id_.find(std::pair{uri, encrypt});
+  auto it = uri_to_id_.find(std::pair<std::string, bool>(std::string(uri), encrypt));
   if (it == uri_to_id_.end()) {
     return RTCError(RTCErrorType::INVALID_PARAMETER,
                     "No ID found for extension");
