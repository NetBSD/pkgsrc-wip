$NetBSD$

--- components/feature_engagement/public/event_constants.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/feature_engagement/public/event_constants.cc
@@ -12,13 +12,13 @@ namespace feature_engagement {
 namespace events {
 
 #if defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
 #endif  // defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) ||
         // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kSixthTabOpened[] = "sixth_tab_opened";
 const char kTabGroupCreated[] = "tab_group_created";
 
