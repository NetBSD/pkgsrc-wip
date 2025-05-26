$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_errors.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_errors.h
@@ -235,7 +235,7 @@ inline v8::Local<v8::Object> ERR_BUFFER_
   char message[128];
   snprintf(message, sizeof(message),
       "Cannot create a Buffer larger than 0x%zx bytes",
-      v8::TypedArray::kMaxLength);
+      v8::TypedArray::kMaxByteLength);
   return ERR_BUFFER_TOO_LARGE(isolate, message);
 }
 
