$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/include/v8-fast-api-calls.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/include/v8-fast-api-calls.h
@@ -340,7 +340,7 @@ struct V8_DEPRECATE_SOON(
 };
 
 template <typename T>
-struct V8_DEPRECATED(
+struct V8_DEPRECATE_SOON(
     "When an API function expects a TypedArray as a parameter, the type in the "
     "signature should be `v8::Local<v8::Value>` instead of "
     "FastApiTypedArray<>. The API function then has to type-check the "
