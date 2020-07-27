$NetBSD$

--- extensions/browser/browser_context_keyed_service_factories.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ extensions/browser/browser_context_keyed_service_factories.cc
@@ -92,7 +92,7 @@ void EnsureBrowserContextKeyedServiceFac
 #if defined(OS_CHROMEOS)
   NetworkingConfigServiceFactory::GetInstance();
 #endif
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
