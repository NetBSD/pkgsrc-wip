$NetBSD$

--- content/public/common/content_constants.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ content/public/common/content_constants.cc
@@ -46,7 +46,7 @@ const int kDefaultDetachableCancelDelayM
 const char kCorsExemptPurposeHeaderName[] = "Purpose";
 const char kCorsExemptRequestedWithHeaderName[] = "X-Requested-With";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const int kLowestRendererOomScore = 300;
 const int kHighestRendererOomScore = 1000;
 
