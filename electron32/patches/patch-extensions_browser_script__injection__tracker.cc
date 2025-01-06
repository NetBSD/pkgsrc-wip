$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/script_injection_tracker.cc.orig	2024-10-18 12:34:17.876619800 +0000
+++ extensions/browser/script_injection_tracker.cc
@@ -170,7 +170,6 @@ std::vector<const UserScript*> GetLoaded
   UserScriptManager* manager =
       ExtensionSystem::Get(process.GetBrowserContext())->user_script_manager();
   if (!manager) {
-    CHECK_IS_TEST();
     return std::vector<const UserScript*>();
   }
 
