$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc
@@ -56,6 +56,10 @@ bool ElectronRuntimeAPIDelegate::GetPlat
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "openbsd") {
     info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+  } else if (os == "freebsd") {
+    info->os = extensions::api::runtime::PlatformOs::kFreebsd;
+  } else if (os == "netbsd") {
+    info->os = extensions::api::runtime::PlatformOs::kNetbsd;
   } else {
     NOTREACHED();
   }
