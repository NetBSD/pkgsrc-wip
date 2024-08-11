$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manual_fallback_flow.cc.orig	2024-07-24 02:44:34.596583800 +0000
+++ components/password_manager/core/browser/password_manual_fallback_flow.cc
@@ -192,7 +192,7 @@ void PasswordManualFallbackFlow::DidAcce
                          payload.password));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       if (payload.is_cross_domain) {
         cross_domain_confirmation_popup_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
