$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/app/content_main_delegate.h.orig	2024-10-18 12:34:14.370406400 +0000
+++ content/public/app/content_main_delegate.h
@@ -10,6 +10,7 @@
 #include <string>
 #include <vector>
 
+#include "base/strings/string_piece.h"
 #include "build/build_config.h"
 #include "content/common/content_export.h"
 #include "content/public/common/main_function_params.h"
@@ -176,6 +177,8 @@ class CONTENT_EXPORT ContentMainDelegate
   virtual bool ShouldHandleConsoleControlEvents();
 #endif
 
+  virtual base::StringPiece GetBrowserV8SnapshotFilename();
+
  protected:
   friend class ContentClientCreator;
   friend class ContentClientInitializer;
