$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/password_manager/core/browser/password_form_manager.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/password_manager/core/browser/password_form_manager.cc
@@ -61,7 +61,7 @@
 #include "components/webauthn/android/webauthn_cred_man_delegate.h"
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/os_crypt.h"
 #endif
 
@@ -233,7 +233,7 @@ bool ShouldUploadCrowdsourcingVotes(cons
   return false;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool ShouldShowKeychainErrorBubble(
     std::optional<PasswordStoreBackendError> backend_error) {
   if (!backend_error.has_value()) {
@@ -892,7 +892,7 @@ void PasswordFormManager::OnFetchComplet
         error.value().type);
   }
 
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ShouldShowKeychainErrorBubble(
           form_fetcher_->GetProfileStoreBackendError())) {
     client_->NotifyKeychainError();
