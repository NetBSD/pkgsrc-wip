$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/signin/accounts_policy_manager.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/signin/accounts_policy_manager.cc
@@ -39,7 +39,7 @@
 #include "chrome/browser/ui/webui/profile_helper.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/policy/core/common/features.h"
 #include "components/signin/public/identity_manager/accounts_mutator.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -207,7 +207,7 @@ void AccountsPolicyManager::Initialize()
           &AccountsPolicyManager::OnGoogleServicesUsernamePatternChanged,
           weak_pointer_factory_.GetWeakPtr()));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* identity_manager = IdentityManagerFactory::GetForProfile(profile_);
   identity_manager_observation_.Observe(identity_manager);
   profile_pref_change_registrar_.Init(profile_->GetPrefs());
@@ -222,7 +222,7 @@ void AccountsPolicyManager::Initialize()
 }
 
 void AccountsPolicyManager::Shutdown() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   profile_pref_change_registrar_.RemoveAll();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
   local_state_pref_registrar_.RemoveAll();
@@ -339,7 +339,7 @@ void AccountsPolicyManager::OnUserConfir
 }
 #endif  // defined(TOOLKIT_VIEWS) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AccountsPolicyManager::OnRefreshTokensLoaded() {
   RemoveUnallowedAccounts();
   identity_manager_observation_.Reset();
