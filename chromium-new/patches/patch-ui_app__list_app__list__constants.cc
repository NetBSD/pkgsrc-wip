$NetBSD$

--- ui/app_list/app_list_constants.cc.orig	2016-06-24 01:02:52.000000000 +0000
+++ ui/app_list/app_list_constants.cc
@@ -148,7 +148,7 @@ const char kSearchQueryLength[] = "Apps.
 const char kSearchResultDistanceFromOrigin[] =
     "Apps.AppListSearchResultDistanceFromOrigin";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
 #if defined(GOOGLE_CHROME_BUILD)
 const char kAppListWMClass[] = "chrome_app_list";
 #else  // CHROMIUM_BUILD
