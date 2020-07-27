$NetBSD$

--- net/url_request/url_request_context_builder.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ net/url_request/url_request_context_builder.cc
@@ -485,7 +485,7 @@ std::unique_ptr<URLRequestContext> URLRe
   }
 
   if (!proxy_resolution_service_) {
-#if !defined(OS_LINUX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     // TODO(willchan): Switch to using this code when
     // ConfiguredProxyResolutionService::CreateSystemProxyConfigService()'s
     // signature doesn't suck.
