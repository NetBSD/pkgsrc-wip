$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/browser_process_impl.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/browser_process_impl.cc
@@ -50,7 +50,7 @@
 #include "chrome/browser/printing/print_job_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
@@ -149,7 +149,7 @@ void BrowserProcessImpl::PostEarlyInitia
   OSCrypt::RegisterLocalPrefs(pref_registry.get());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   os_crypt_async::SecretPortalKeyProvider::RegisterLocalPrefs(
       pref_registry.get());
 #endif
@@ -404,7 +404,7 @@ electron::ResolveProxyHelper* BrowserPro
   return resolve_proxy_helper_.get();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserProcessImpl::SetLinuxStorageBackend(
     os_crypt::SelectedLinuxBackend selected_backend) {
   switch (selected_backend) {
@@ -427,7 +427,7 @@ void BrowserProcessImpl::SetLinuxStorage
       NOTREACHED();
   }
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void BrowserProcessImpl::SetApplicationLocale(const std::string& locale) {
   locale_ = locale;
@@ -479,7 +479,7 @@ void BrowserProcessImpl::CreateOSCryptAs
       std::make_unique<os_crypt_async::DPAPIKeyProvider>(local_state()));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   const auto password_store =
       cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore);
@@ -507,7 +507,7 @@ void BrowserProcessImpl::CreateOSCryptAs
       std::make_unique<os_crypt_async::FreedesktopSecretKeyProvider>(
           password_store, electron::GetApplicationName(), freedesktop_config,
           nullptr));
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
   // On other POSIX systems, this is the only key provider. On Linux, it is used
