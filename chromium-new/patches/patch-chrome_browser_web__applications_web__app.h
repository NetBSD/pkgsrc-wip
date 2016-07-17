$NetBSD$

--- chrome/browser/web_applications/web_app.h.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/browser/web_applications/web_app.h
@@ -227,7 +227,7 @@ typedef std::vector<WebApplicationInfo::
 void GetIconsInfo(const WebApplicationInfo& app_info, IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
