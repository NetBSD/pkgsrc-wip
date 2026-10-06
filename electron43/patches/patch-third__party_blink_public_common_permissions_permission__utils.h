$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/common/permissions/permission_utils.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/common/permissions/permission_utils.h
@@ -64,6 +64,7 @@ enum class PermissionType {
   AUTOMATIC_FULLSCREEN = 40,
   HAND_TRACKING = 41,
   WEB_APP_INSTALLATION = 42,
+  DEPRECATED_SYNC_CLIPBOARD_READ = 43,
 
   // Always keep this at the end.
   NUM,
