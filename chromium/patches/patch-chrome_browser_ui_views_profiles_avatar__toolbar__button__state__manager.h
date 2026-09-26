$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h.orig	2026-09-17 03:47:47.000000000 +0000
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.h
@@ -269,7 +269,7 @@ class AvatarToolbarButtonStateManager
 
   // Shared IPH methods.
   void MaybeShowProfileSwitchIPH();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH();
   void MaybeShowSignInBenefitsIPH();
 #endif
