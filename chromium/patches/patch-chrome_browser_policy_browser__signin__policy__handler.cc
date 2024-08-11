$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/policy/browser_signin_policy_handler.cc.orig	2024-07-24 02:44:27.927937700 +0000
+++ chrome/browser/policy/browser_signin_policy_handler.cc
@@ -45,7 +45,7 @@ void BrowserSigninPolicyHandler::ApplyPo
       policies.GetValue(policy_name(), base::Value::Type::INTEGER);
   switch (static_cast<BrowserSigninMode>(value->GetInt())) {
     case BrowserSigninMode::kForced:
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
       prefs->SetValue(prefs::kForceBrowserSignin, base::Value(true));
 #endif
       [[fallthrough]];
