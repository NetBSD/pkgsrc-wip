$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc.orig	2024-09-24 20:49:29.739972000 +0000
+++ extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc
@@ -44,7 +44,7 @@ void ShellRuntimeAPIDelegate::OpenURL(co
 bool ShellRuntimeAPIDelegate::GetPlatformInfo(PlatformInfo* info) {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   info->os = api::runtime::PlatformOs::kCros;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   info->os = api::runtime::PlatformOs::kLinux;
 #endif
   return true;
