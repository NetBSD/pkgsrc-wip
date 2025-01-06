$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_buffer.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_buffer.h
@@ -29,7 +29,7 @@ namespace node {
 
 namespace Buffer {
 
-static const size_t kMaxLength = v8::TypedArray::kMaxLength;
+static const size_t kMaxLength = v8::TypedArray::kMaxByteLength;
 
 typedef void (*FreeCallback)(char* data, void* hint);
 
