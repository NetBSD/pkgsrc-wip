$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/supervised_user/google_auth_state_waiter_mixin.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/test/supervised_user/google_auth_state_waiter_mixin.cc
@@ -24,7 +24,7 @@ GoogleAuthStateWaiterMixin::GoogleAuthSt
 GoogleAuthStateWaiterMixin::~GoogleAuthStateWaiterMixin() = default;
 
 void GoogleAuthStateWaiterMixin::SetUpOnMainThread() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ChildAccountService* child_account_service =
       ChildAccountServiceFactory::GetForProfile(
           test_base_->browser()->profile());
