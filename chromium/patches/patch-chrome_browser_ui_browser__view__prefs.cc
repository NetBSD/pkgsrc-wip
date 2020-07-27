$NetBSD$

--- chrome/browser/ui/browser_view_prefs.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/ui/browser_view_prefs.cc
@@ -26,7 +26,7 @@ namespace {
 // Old values: 0 = SHRINK (default), 1 = STACKED.
 const char kTabStripLayoutType[] = "tab_strip_layout_type";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 bool GetCustomFramePrefDefault() {
 #if defined(USE_OZONE)
   if (features::IsUsingOzonePlatform()) {
@@ -51,7 +51,7 @@ void RegisterBrowserViewLocalPrefs(PrefR
 
 void RegisterBrowserViewProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   registry->RegisterBooleanPref(prefs::kUseCustomChromeFrame,
                                 GetCustomFramePrefDefault());
 #endif  // defined(OS_LINUX) && defined(!OS_CHROMEOS)
