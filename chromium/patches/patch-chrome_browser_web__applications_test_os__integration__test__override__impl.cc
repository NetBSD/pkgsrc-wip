$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/test/os_integration_test_override_impl.cc.orig	2024-09-24 20:49:21.242226400 +0000
+++ chrome/browser/web_applications/test/os_integration_test_override_impl.cc
@@ -46,7 +46,7 @@
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkColor.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -131,7 +131,7 @@ std::vector<std::wstring> GetFileExtensi
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Performs a blocking read of app icons from the disk.
 SkColor IconManagerReadIconTopLeftColorForSize(WebAppIconManager& icon_manager,
                                                const webapps::AppId& app_id,
@@ -266,7 +266,7 @@ bool OsIntegrationTestOverrideImpl::Simu
       GetShortcutPath(profile, chrome_apps_folder(), app_id, app_name);
   CHECK(base::PathExists(app_folder_shortcut_path));
   return base::DeletePathRecursively(app_folder_shortcut_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop_shortcut_path =
       GetShortcutPath(profile, desktop(), app_id, app_name);
   LOG(INFO) << desktop_shortcut_path;
@@ -314,7 +314,7 @@ bool OsIntegrationTestOverrideImpl::Dele
 }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OsIntegrationTestOverrideImpl::DeleteDesktopDirOnLinux() {
   if (desktop_.IsValid()) {
     return desktop_.Delete();
@@ -328,7 +328,7 @@ bool OsIntegrationTestOverrideImpl::IsRu
     Profile* profile,
     const webapps::AppId& app_id,
     const std::string& app_name) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string shortcut_filename =
       "chrome-" + app_id + "-" + profile->GetBaseName().value() + ".desktop";
   return base::PathExists(startup().Append(shortcut_filename));
@@ -384,7 +384,7 @@ bool OsIntegrationTestOverrideImpl::IsFi
   is_file_handled =
       shell_integration::CanApplicationHandleURL(app_path, test_file_url);
   base::DeleteFile(test_file_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath user_applications_dir = applications();
   bool database_update_called = false;
   for (const LinuxFileRegistration& command : linux_file_registration_) {
@@ -427,7 +427,7 @@ OsIntegrationTestOverrideImpl::GetShortc
     return std::nullopt;
   }
   return GetIconTopLeftColorFromShortcutFile(shortcut_path);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForLocalAppsUnchecked(profile);
   if (!provider) {
     return std::nullopt;
@@ -477,7 +477,7 @@ base::FilePath OsIntegrationTestOverride
       app_installed_profiles.end()) {
     return shortcut_path;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string shortcut_filename =
       "chrome-" + app_id + "-" + profile->GetBaseName().value() + ".desktop";
   base::FilePath shortcut_path = shortcut_dir.Append(shortcut_filename);
@@ -502,7 +502,7 @@ bool OsIntegrationTestOverrideImpl::IsSh
   base::FilePath app_shortcut_path =
       GetShortcutPath(profile, chrome_apps_folder(), app_id, app_name);
   return base::PathExists(app_shortcut_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop_shortcut_path =
       GetShortcutPath(profile, desktop(), app_id, app_name);
   return base::PathExists(desktop_shortcut_path);
@@ -690,7 +690,7 @@ void OsIntegrationTestOverrideImpl::Enab
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 base::FilePath OsIntegrationTestOverrideImpl::desktop() {
   return desktop_.GetPath();
 }
@@ -741,7 +741,7 @@ OsIntegrationTestOverrideImpl::OsIntegra
   success = chrome_apps_folder_.CreateUniqueTempDirUnderPath(
       outer_temp_dir_.GetPath());
   CHECK(success);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   success = desktop_.CreateUniqueTempDirUnderPath(outer_temp_dir_.GetPath());
   CHECK(success);
   success = startup_.CreateUniqueTempDirUnderPath(outer_temp_dir_.GetPath());
@@ -754,7 +754,7 @@ OsIntegrationTestOverrideImpl::OsIntegra
   CHECK(success);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto callback = base::BindRepeating([](base::FilePath filename_in,
                                          std::string xdg_command,
                                          std::string file_contents) {
@@ -826,7 +826,7 @@ OsIntegrationTestOverrideImpl::~OsIntegr
   EXPECT_TRUE(!startup_.IsValid() || startup_.Delete());
 #elif BUILDFLAG(IS_MAC)
   EXPECT_TRUE(!chrome_apps_folder_.IsValid() || DeleteChromeAppsDir());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_TRUE(!desktop_.IsValid() || desktop_.Delete());
   EXPECT_TRUE(!startup_.IsValid() || startup_.Delete());
   EXPECT_TRUE(!xdg_data_home_dir_.IsValid() || xdg_data_home_dir_.Delete());
