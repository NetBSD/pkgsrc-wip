$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/app/content_main_delegate.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/app/content_main_delegate.h
@@ -8,6 +8,7 @@
 #include <memory>
 #include <optional>
 #include <string>
+#include <string_view>
 #include <vector>
 
 #include "build/build_config.h"
@@ -173,6 +174,8 @@ class CONTENT_EXPORT ContentMainDelegate
   virtual bool ShouldHandleConsoleControlEvents();
 #endif
 
+  virtual std::string_view GetBrowserV8SnapshotFilename();
+
  protected:
   friend class ContentClientCreator;
   friend class ContentClientInitializer;
