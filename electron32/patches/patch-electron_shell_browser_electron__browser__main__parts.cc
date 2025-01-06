$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/electron_browser_main_parts.cc.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/shell/browser/electron_browser_main_parts.cc
@@ -78,7 +78,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "chrome/browser/ui/views/dark_mode_manager_linux.h"
 #include "device/bluetooth/bluetooth_adapter_factory.h"
@@ -131,7 +131,7 @@ namespace electron {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class LinuxUiGetterImpl : public ui::LinuxUiGetter {
  public:
   LinuxUiGetterImpl() = default;
@@ -209,7 +209,7 @@ int ElectronBrowserMainParts::PreEarlyIn
 #if BUILDFLAG(IS_POSIX)
   HandleSIGCHLD();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DetectOzonePlatform();
   ui::OzonePlatform::PreEarlyInitialization();
 #endif
@@ -299,7 +299,7 @@ int ElectronBrowserMainParts::PreCreateT
   // happen before the ResourceBundle is loaded
   if (locale.empty())
     l10n_util::OverrideLocaleWithCocoaLocale();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // l10n_util::GetApplicationLocaleInternal uses g_get_language_names(),
   // which keys off of getenv("LC_ALL").
   // We must set this env first to make ui::ResourceBundle accept the custom
@@ -330,7 +330,7 @@ int ElectronBrowserMainParts::PreCreateT
   ElectronBrowserClient::SetApplicationLocale(app_locale);
   fake_browser_process_->SetApplicationLocale(app_locale);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reset to the original LC_ALL since we should not be changing it.
   if (!locale.empty()) {
     if (lc_all)
@@ -390,7 +390,7 @@ void ElectronBrowserMainParts::PostDestr
 }
 
 void ElectronBrowserMainParts::ToolkitInitialized() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::GetDefaultLinuxUi();
   CHECK(linux_ui);
   linux_ui_getter_ = std::make_unique<LinuxUiGetterImpl>();
@@ -496,7 +496,7 @@ void ElectronBrowserMainParts::WillRunMa
 }
 
 void ElectronBrowserMainParts::PostCreateMainMessageLoop() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::string app_name = electron::Browser::Get()->GetName();
 #endif
 #if BUILDFLAG(IS_LINUX)
@@ -508,7 +508,9 @@ void ElectronBrowserMainParts::PostCreat
 
   if (!bluez::BluezDBusManager::IsInitialized())
     bluez::DBusBluezManagerWrapperLinux::Initialize();
+#endif
 
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
   // network service for encrypted cookie storage.
@@ -609,7 +611,7 @@ void ElectronBrowserMainParts::PostMainM
   fake_browser_process_->PostMainMessageLoopRun();
   content::DevToolsAgentHost::StopRemoteDebuggingPipeHandler();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
