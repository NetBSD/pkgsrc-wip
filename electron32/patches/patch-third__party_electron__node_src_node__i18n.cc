$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_i18n.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_i18n.cc
@@ -106,7 +106,7 @@ namespace {
 
 template <typename T>
 MaybeLocal<Object> ToBufferEndian(Environment* env, MaybeStackBuffer<T>* buf) {
-  MaybeLocal<Object> ret = Buffer::New(env, buf);
+  MaybeLocal<Object> ret = Buffer::Copy(env, reinterpret_cast<char*>(buf->out()), buf->length() * sizeof(T));
   if (ret.IsEmpty())
     return ret;
 
@@ -183,7 +183,7 @@ MaybeLocal<Object> TranscodeLatin1ToUcs2
     return {};
   }
 
-  return Buffer::New(env, &destbuf);
+  return Buffer::Copy(env, reinterpret_cast<char*>(destbuf.out()), destbuf.length() * sizeof(UChar));
 }
 
 MaybeLocal<Object> TranscodeFromUcs2(Environment* env,
@@ -228,7 +228,7 @@ MaybeLocal<Object> TranscodeUcs2FromUtf8
     return {};
   }
 
-  return Buffer::New(env, &destbuf);
+  return Buffer::Copy(env, reinterpret_cast<char*>(destbuf.out()), destbuf.length() * sizeof(UChar));
 }
 
 MaybeLocal<Object> TranscodeUtf8FromUcs2(Environment* env,
@@ -252,7 +252,7 @@ MaybeLocal<Object> TranscodeUtf8FromUcs2
     return {};
   }
 
-  return Buffer::New(env, &destbuf);
+  return Buffer::Copy(env, reinterpret_cast<char*>(destbuf.out()), destbuf.length() * sizeof(char));
 }
 
 constexpr const char* EncodingName(const enum encoding encoding) {
