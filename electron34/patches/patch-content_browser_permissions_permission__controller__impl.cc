$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/permissions/permission_controller_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/permissions/permission_controller_impl.cc
@@ -94,6 +94,7 @@ PermissionToSchedulingFeature(Permission
     case PermissionType::POINTER_LOCK:
     case PermissionType::AUTOMATIC_FULLSCREEN:
     case PermissionType::WEB_APP_INSTALLATION:
+    case PermissionType::DEPRECATED_SYNC_CLIPBOARD_READ:
       return std::nullopt;
   }
 }
