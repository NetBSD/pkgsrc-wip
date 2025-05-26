$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/script_injection_tracker.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ extensions/browser/script_injection_tracker.cc
@@ -174,7 +174,6 @@ std::vector<const UserScript*> GetLoaded
   UserScriptManager* manager =
       ExtensionSystem::Get(process.GetBrowserContext())->user_script_manager();
   if (!manager) {
-    CHECK_IS_TEST();
     return std::vector<const UserScript*>();
   }
 
