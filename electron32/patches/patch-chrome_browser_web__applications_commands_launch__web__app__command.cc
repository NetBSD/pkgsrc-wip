$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/web_applications/commands/launch_web_app_command.cc.orig	2024-10-18 12:34:03.724068900 +0000
+++ chrome/browser/web_applications/commands/launch_web_app_command.cc
@@ -98,7 +98,7 @@ void LaunchWebAppCommand::StartWithLock(
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     lock_->os_integration_manager().Synchronize(
