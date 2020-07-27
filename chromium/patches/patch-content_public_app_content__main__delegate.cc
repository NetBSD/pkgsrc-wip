$NetBSD$

--- content/public/app/content_main_delegate.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ content/public/app/content_main_delegate.cc
@@ -24,7 +24,7 @@ int ContentMainDelegate::RunProcess(
   return -1;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 void ContentMainDelegate::ZygoteStarting(
     std::vector<std::unique_ptr<ZygoteForkDelegate>>* delegates) {}
