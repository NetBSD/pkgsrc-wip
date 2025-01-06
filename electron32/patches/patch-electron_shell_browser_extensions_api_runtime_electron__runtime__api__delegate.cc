$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc
@@ -55,6 +55,10 @@ bool ElectronRuntimeAPIDelegate::GetPlat
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kFreebsd;
+  } else if (strcmp(os, "netbsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kNetbsd;
   } else {
     NOTREACHED();
   }
