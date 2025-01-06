$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/password_manager/core/browser/password_manual_fallback_flow.cc.orig	2024-10-18 12:34:07.238157700 +0000
+++ components/password_manager/core/browser/password_manual_fallback_flow.cc
@@ -204,7 +204,7 @@ void PasswordManualFallbackFlow::DidAcce
                          payload.password));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       if (payload.is_cross_domain) {
         cross_domain_confirmation_popup_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
