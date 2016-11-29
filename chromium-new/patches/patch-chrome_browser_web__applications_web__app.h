$NetBSD$

--- chrome/browser/web_applications/web_app.h.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/web_applications/web_app.h
@@ -224,7 +224,7 @@ typedef std::vector<WebApplicationInfo::
 void GetIconsInfo(const WebApplicationInfo& app_info, IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
