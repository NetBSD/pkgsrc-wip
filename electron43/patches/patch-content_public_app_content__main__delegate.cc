$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/app/content_main_delegate.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/app/content_main_delegate.cc
@@ -4,6 +4,8 @@
 
 #include "content/public/app/content_main_delegate.h"
 
+#include <string_view>
+
 #include "base/check.h"
 #include "build/build_config.h"
 #include "content/public/browser/content_browser_client.h"
@@ -91,6 +93,10 @@ std::optional<int> ContentMainDelegate::
   return std::nullopt;
 }
 
+std::string_view ContentMainDelegate::GetBrowserV8SnapshotFilename() {
+  return std::string_view();
+}
+
 ContentClient* ContentMainDelegate::CreateContentClient() {
   return new ContentClient();
 }
