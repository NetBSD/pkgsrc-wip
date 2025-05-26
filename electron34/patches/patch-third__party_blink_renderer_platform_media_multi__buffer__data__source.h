$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/media/multi_buffer_data_source.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/media/multi_buffer_data_source.h
@@ -17,6 +17,7 @@
 #include "media/base/data_source.h"
 #include "media/base/ranges.h"
 #include "media/base/tuneable.h"
+#include "third_party/blink/public/platform/web_common.h"
 #include "third_party/blink/renderer/platform/media/url_index.h"
 #include "third_party/blink/renderer/platform/platform_export.h"
 #include "third_party/blink/renderer/platform/wtf/vector.h"
@@ -34,6 +35,8 @@ namespace blink {
 class BufferedDataSourceHost;
 class MultiBufferReader;
 
+void BLINK_PLATFORM_EXPORT AddStreamingScheme(const char* new_scheme);
+
 // A data source capable of loading URLs and buffering the data using an
 // in-memory sliding window.
 //
