$NetBSD$

--- ui/app_list/app_list_constants.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/app_list/app_list_constants.cc
@@ -154,7 +154,7 @@ const char kSearchQueryLength[] = "Apps.
 const char kSearchResultDistanceFromOrigin[] =
     "Apps.AppListSearchResultDistanceFromOrigin";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #if defined(GOOGLE_CHROME_BUILD)
 const char kAppListWMClass[] = "chrome_app_list";
 #else  // CHROMIUM_BUILD
