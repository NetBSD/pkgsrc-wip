$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/plugins/plugin_response_interceptor_url_loader_throttle.cc.orig	2024-10-18 12:34:01.837113100 +0000
+++ chrome/browser/plugins/plugin_response_interceptor_url_loader_throttle.cc
@@ -12,8 +12,8 @@
 #include "base/numerics/safe_conversions.h"
 #include "base/unguessable_token.h"
 #include "base/uuid.h"
-#include "chrome/browser/extensions/api/streams_private/streams_private_api.h"
-#include "chrome/browser/plugins/plugin_utils.h"
+#include "electron/shell/browser/extensions/api/streams_private/streams_private_api.h"
+#include "electron/shell/browser/plugins/plugin_utils.h"
 #include "content/public/browser/browser_task_traits.h"
 #include "content/public/browser/browser_thread.h"
 #include "content/public/browser/download_utils.h"
