$NetBSD$

--- chrome/browser/policy/browser_signin_policy_handler.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/policy/browser_signin_policy_handler.cc
@@ -52,7 +52,7 @@ void BrowserSigninPolicyHandler::ApplyPo
     }
     switch (static_cast<BrowserSigninMode>(int_value)) {
       case BrowserSigninMode::kForced:
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
         prefs->SetValue(prefs::kForceBrowserSignin, base::Value(true));
 #endif
         FALLTHROUGH;
