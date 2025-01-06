$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/app/content_main_delegate.cc.orig	2024-10-18 12:34:14.370406400 +0000
+++ content/public/app/content_main_delegate.cc
@@ -5,6 +5,7 @@
 #include "content/public/app/content_main_delegate.h"
 
 #include "base/check.h"
+#include "base/strings/string_piece.h"
 #include "build/build_config.h"
 #include "content/public/browser/content_browser_client.h"
 #include "content/public/common/content_client.h"
@@ -91,6 +92,10 @@ std::optional<int> ContentMainDelegate::
   return std::nullopt;
 }
 
+base::StringPiece ContentMainDelegate::GetBrowserV8SnapshotFilename() {
+  return base::StringPiece();
+}
+
 ContentClient* ContentMainDelegate::CreateContentClient() {
   return new ContentClient();
 }
