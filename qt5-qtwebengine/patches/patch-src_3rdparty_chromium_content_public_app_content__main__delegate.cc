$NetBSD$

--- src/3rdparty/chromium/content/public/app/content_main_delegate.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/content/public/app/content_main_delegate.cc
@@ -27,7 +27,7 @@ int ContentMainDelegate::RunProcess(
   return -1;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 void ContentMainDelegate::ZygoteStarting(
     std::vector<std::unique_ptr<service_manager::ZygoteForkDelegate>>*
