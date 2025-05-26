$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_document_loader.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/web/web_document_loader.h
@@ -38,6 +38,7 @@
 #include "third_party/blink/public/platform/cross_variant_mojo_util.h"
 #include "third_party/blink/public/platform/web_archive_info.h"
 #include "third_party/blink/public/platform/web_common.h"
+#include "third_party/blink/public/platform/web_loader_freeze_mode.h"
 #include "third_party/blink/public/platform/web_source_location.h"
 #include "third_party/blink/public/web/web_navigation_type.h"
 
@@ -63,6 +64,8 @@ class BLINK_EXPORT WebDocumentLoader {
     virtual std::unique_ptr<ExtraData> Clone() = 0;
   };
 
+  virtual void SetDefersLoading(WebLoaderFreezeMode) = 0;
+
   static bool WillLoadUrlAsEmpty(const WebURL&);
 
   // Returns the http referrer of original request which initited this load.
