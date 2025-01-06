$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/nan/test/cpp/indexedinterceptors.cpp.orig	2023-09-12 12:23:33.000000000 +0000
+++ third_party/nan/test/cpp/indexedinterceptors.cpp
@@ -90,9 +90,9 @@ NAN_INDEX_SETTER(IndexedInterceptor::Pro
         interceptor->buf
       , *Nan::Utf8String(value)
       , sizeof (interceptor->buf));
-    info.GetReturnValue().Set(info.This());
+    info.GetReturnValue().Set(True());
   } else {
-    info.GetReturnValue().Set(info.This());
+    info.GetReturnValue().Set(True());
   }
 }
 
