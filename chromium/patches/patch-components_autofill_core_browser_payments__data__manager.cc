$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments_data_manager.cc.orig	2024-10-26 07:00:06.309434700 +0000
+++ components/autofill/core/browser/payments_data_manager.cc
@@ -1054,7 +1054,7 @@ bool PaymentsDataManager::ShouldShowCard
 // The feature is only for Linux, Windows, Mac, and Fuchsia.
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
