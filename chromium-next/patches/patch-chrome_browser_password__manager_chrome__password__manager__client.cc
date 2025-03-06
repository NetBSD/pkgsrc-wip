$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -637,7 +637,7 @@ void ChromePasswordManagerClient::
 bool ChromePasswordManagerClient::IsReauthBeforeFillingRequired(
     device_reauth::DeviceAuthenticator* authenticator) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -915,7 +915,7 @@ void ChromePasswordManagerClient::Notify
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   if (manage_passwords_ui_controller) {
