$NetBSD: patch-chrome_browser_net_connection__tester.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/net/connection_tester.cc.orig	2011-04-13 08:01:40.000000000 +0000
+++ chrome/browser/net/connection_tester.cc
@@ -189,7 +189,7 @@ class ExperimentURLRequestContext : publ
   // Otherwise returns a network error code.
   int CreateSystemProxyConfigService(
       scoped_ptr<net::ProxyConfigService>* config_service) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(eroman): This is not supported on Linux yet, because of how
     // construction needs ot happen on the UI thread.
     return net::ERR_NOT_IMPLEMENTED;
