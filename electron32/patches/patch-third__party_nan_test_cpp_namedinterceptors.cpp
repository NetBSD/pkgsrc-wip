$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/nan/test/cpp/namedinterceptors.cpp.orig	2023-09-12 12:23:33.000000000 +0000
+++ third_party/nan/test/cpp/namedinterceptors.cpp
@@ -90,10 +90,8 @@ NAN_PROPERTY_SETTER(NamedInterceptor::Pr
         interceptor->buf
       , *Nan::Utf8String(value)
       , sizeof (interceptor->buf));
-    info.GetReturnValue().Set(info.This());
-  } else {
-    info.GetReturnValue().Set(info.This());
   }
+  info.GetReturnValue().Set(True());
 }
 
 NAN_PROPERTY_ENUMERATOR(NamedInterceptor::PropertyEnumerator) {
