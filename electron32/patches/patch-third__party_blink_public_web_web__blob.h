$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_blob.h.orig	2024-10-18 12:34:34.704506600 +0000
+++ third_party/blink/public/web/web_blob.h
@@ -67,6 +67,7 @@ class BLINK_EXPORT WebBlob {
   void Reset();
   void Assign(const WebBlob&);
   WebString Uuid();
+  std::string Path();
 
   bool IsNull() const { return private_.IsNull(); }
 
