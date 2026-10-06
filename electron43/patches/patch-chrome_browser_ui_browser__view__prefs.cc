$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/browser_view_prefs.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/browser_view_prefs.cc
@@ -15,7 +15,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GetCustomFramePrefDefault() {
 #if BUILDFLAG(IS_OZONE)
   return ui::OzonePlatform::GetInstance()
@@ -31,7 +31,7 @@ bool GetCustomFramePrefDefault() {
 
 void RegisterBrowserViewProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kUseCustomChromeFrame,
                                 GetCustomFramePrefDefault());
 #endif
