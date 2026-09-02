$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -641,7 +641,7 @@ void PasswordsPrivateDelegateImpl::OnFet
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event_router_) {
     event_router_->OnPasswordManagerAuthTimeout();
   }
