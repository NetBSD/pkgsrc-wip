$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_window_features.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/web/web_window_features.h
@@ -35,6 +35,7 @@
 
 #include "third_party/blink/public/platform/web_string.h"
 #include "third_party/blink/public/platform/web_vector.h"
+#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
 
 namespace blink {
 
@@ -74,6 +75,8 @@ struct WebWindowFeatures {
   // TODO(apaseltiner): Investigate moving this field to a non-public struct
   // since it is only needed within //third_party/blink.
   std::optional<WebVector<WebString>> attribution_srcs;
+
+  String raw_features;
 };
 
 }  // namespace blink
