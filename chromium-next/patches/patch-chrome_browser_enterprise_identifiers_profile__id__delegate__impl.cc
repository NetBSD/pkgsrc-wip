$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/identifiers/profile_id_delegate_impl.cc.orig	2025-01-27 17:37:37.000000000 +0000
+++ chrome/browser/enterprise/identifiers/profile_id_delegate_impl.cc
@@ -13,7 +13,7 @@
 #include "components/enterprise/browser/identifiers/identifiers_prefs.h"
 #include "components/prefs/pref_service.h"
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "components/enterprise/browser/controller/browser_dm_token_storage.h"
 #if BUILDFLAG(IS_WIN)
 #include "base/strings/utf_string_conversions.h"
@@ -94,7 +94,7 @@ std::string ProfileIdDelegateImpl::GetDe
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Gets the device ID from the BrowserDMTokenStorage.
 std::string ProfileIdDelegateImpl::GetId() {
   std::string device_id =
