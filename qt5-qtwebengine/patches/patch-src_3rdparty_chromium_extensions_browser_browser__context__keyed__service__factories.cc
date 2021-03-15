$NetBSD$

--- src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc
@@ -81,7 +81,7 @@ void EnsureBrowserContextKeyedServiceFac
   IdleManagerFactory::GetInstance();
 #endif // !defined(TOOLKIT_QT)
   ManagementAPI::GetFactoryInstance();
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
