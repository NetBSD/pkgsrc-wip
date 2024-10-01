$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/network_session_configurator/browser/network_session_configurator.cc.orig	2024-09-24 20:49:25.193573200 +0000
+++ components/network_session_configurator/browser/network_session_configurator.cc
@@ -839,7 +839,7 @@ net::URLRequestContextBuilder::HttpCache
   // backport, having it behave differently than in stable would be a bigger
   // problem. TODO: Does this work in later macOS releases?
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
