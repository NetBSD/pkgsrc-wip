$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_i18n.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_i18n.cc
@@ -103,7 +103,7 @@ namespace {
 
 template <typename T>
 MaybeLocal<Object> ToBufferEndian(Environment* env, MaybeStackBuffer<T>* buf) {
-  MaybeLocal<Object> ret = Buffer::New(env, buf);
+  MaybeLocal<Object> ret = Buffer::Copy(env, reinterpret_cast<char*>(buf->out()), buf->length() * sizeof(T));
   if (ret.IsEmpty())
     return ret;
 
@@ -180,7 +180,7 @@ MaybeLocal<Object> TranscodeLatin1ToUcs2
     return {};
   }
 
-  return Buffer::New(env, &destbuf);
+  return Buffer::Copy(env, reinterpret_cast<char*>(destbuf.out()), destbuf.length() * sizeof(UChar));
 }
 
 MaybeLocal<Object> TranscodeFromUcs2(Environment* env,
@@ -225,7 +225,7 @@ MaybeLocal<Object> TranscodeUcs2FromUtf8
     return {};
   }
 
-  return Buffer::New(env, &destbuf);
+  return Buffer::Copy(env, reinterpret_cast<char*>(destbuf.out()), destbuf.length() * sizeof(UChar));
 }
 
 MaybeLocal<Object> TranscodeUtf8FromUcs2(Environment* env,
@@ -249,7 +249,7 @@ MaybeLocal<Object> TranscodeUtf8FromUcs2
     return {};
   }
 
-  return Buffer::New(env, &destbuf);
+  return Buffer::Copy(env, reinterpret_cast<char*>(destbuf.out()), destbuf.length() * sizeof(char));
 }
 
 constexpr const char* EncodingName(const enum encoding encoding) {
