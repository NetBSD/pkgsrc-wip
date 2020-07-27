$NetBSD$

--- components/feature_engagement/public/event_constants.h.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/feature_engagement/public/event_constants.h
@@ -14,7 +14,7 @@ namespace events {
 
 // Desktop and IOS.
 #if defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
@@ -23,7 +23,7 @@ extern const char kNewTabOpened[];
 
 // Desktop
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 // A new tab was opened when 5 (or more) tabs were already open.
 extern const char kSixthTabOpened[];
 // The user made a new tab group.
