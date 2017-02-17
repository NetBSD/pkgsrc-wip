$NetBSD$

--- ui/app_list/app_list_constants.cc.orig	2017-02-02 02:03:13.000000000 +0000
+++ ui/app_list/app_list_constants.cc
@@ -140,7 +140,7 @@ const char kSearchQueryLength[] = "Apps.
 const char kSearchResultDistanceFromOrigin[] =
     "Apps.AppListSearchResultDistanceFromOrigin";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #if defined(GOOGLE_CHROME_BUILD)
 const char kAppListWMClass[] = "chrome_app_list";
 #else  // CHROMIUM_BUILD
