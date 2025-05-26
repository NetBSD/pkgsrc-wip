$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/common/permissions/permission_utils.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/common/permissions/permission_utils.cc
@@ -99,6 +99,8 @@ std::string GetPermissionString(Permissi
       return "AutomaticFullscreen";
     case PermissionType::WEB_APP_INSTALLATION:
       return "WebAppInstallation";
+    case PermissionType::DEPRECATED_SYNC_CLIPBOARD_READ:
+      return "DeprecatedSyncClipboardRead";
     case PermissionType::NUM:
       NOTREACHED();
   }
@@ -171,6 +173,7 @@ PermissionTypeToPermissionsPolicyFeature
     case PermissionType::NOTIFICATIONS:
     case PermissionType::KEYBOARD_LOCK:
     case PermissionType::POINTER_LOCK:
+    case PermissionType::DEPRECATED_SYNC_CLIPBOARD_READ:
       return std::nullopt;
 
     case PermissionType::NUM:
