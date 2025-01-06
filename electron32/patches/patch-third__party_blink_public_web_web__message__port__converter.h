$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_message_port_converter.h.orig	2024-10-18 12:34:34.704506600 +0000
+++ third_party/blink/public/web/web_message_port_converter.h
@@ -13,6 +13,7 @@
 namespace v8 {
 class Isolate;
 class Value;
+class Context;
 }  // namespace v8
 
 namespace blink {
@@ -25,6 +26,9 @@ class BLINK_EXPORT WebMessagePortConvert
   // neutered, it will return nullopt.
   static std::optional<MessagePortChannel>
   DisentangleAndExtractMessagePortChannel(v8::Isolate*, v8::Local<v8::Value>);
+
+  BLINK_EXPORT static v8::Local<v8::Value>
+  EntangleAndInjectMessagePortChannel(v8::Local<v8::Context>, MessagePortChannel);
 };
 
 }  // namespace blink
