$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_navigation_observer.cc.orig	2024-07-24 02:44:28.932035200 +0000
+++ chrome/browser/supervised_user/supervised_user_navigation_observer.cc
@@ -47,7 +47,7 @@
 #include "chrome/browser/supervised_user/android/supervised_user_web_content_handler_impl.h"
 #elif BUILDFLAG(IS_CHROMEOS)
 #include "chrome/browser/supervised_user/chromeos/supervised_user_web_content_handler_impl.h"
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/linux_mac_windows/supervised_user_web_content_handler_impl.h"
 #endif
 
@@ -67,7 +67,7 @@ std::unique_ptr<supervised_user::WebCont
 #elif BUILDFLAG(IS_ANDROID)
   return std::make_unique<SupervisedUserWebContentHandlerImpl>(
       web_contents, frame_id, navigation_id);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return std::make_unique<SupervisedUserWebContentHandlerImpl>(
       web_contents, frame_id, navigation_id);
 #endif
