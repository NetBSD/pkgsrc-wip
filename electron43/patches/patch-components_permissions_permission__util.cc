$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/permissions/permission_util.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/permissions/permission_util.cc
@@ -364,6 +364,7 @@ ContentSettingsType PermissionUtil::Perm
       return ContentSettingsType::AUTOMATIC_FULLSCREEN;
     case PermissionType::WEB_APP_INSTALLATION:
       return ContentSettingsType::WEB_APP_INSTALLATION;
+    case PermissionType::DEPRECATED_SYNC_CLIPBOARD_READ:
     case PermissionType::NUM:
       break;
   }
