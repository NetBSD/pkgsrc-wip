$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager_switches.h.orig	2024-07-24 02:44:34.596583800 +0000
+++ components/password_manager/core/browser/password_manager_switches.h
@@ -10,7 +10,7 @@
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kPasswordStore[];
 extern const char kEnableEncryptionSelection[];
 #endif  // BUILDFLAG(IS_LINUX)
