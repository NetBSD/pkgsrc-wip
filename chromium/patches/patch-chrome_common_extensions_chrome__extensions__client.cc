$NetBSD$

--- chrome/common/extensions/chrome_extensions_client.cc.orig	2017-02-02 02:02:50.000000000 +0000
+++ chrome/common/extensions/chrome_extensions_client.cc
@@ -105,7 +105,10 @@ ChromeChannelForHistogram GetChromeChann
 static base::LazyInstance<ChromeExtensionsClient> g_client =
     LAZY_INSTANCE_INITIALIZER;
 
-ChromeExtensionsClient::ChromeExtensionsClient() {}
+ChromeExtensionsClient::ChromeExtensionsClient()
+    : chrome_api_permissions_(ChromeAPIPermissions()),
+      extensions_api_permissions_(ExtensionsAPIPermissions()) {
+}
 
 ChromeExtensionsClient::~ChromeExtensionsClient() {
 }
