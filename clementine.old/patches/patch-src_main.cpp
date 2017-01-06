$NetBSD$

Remove echonest support, see
https://github.com/clementine-player/Clementine/commit/a8a0f2e4fdd3d4b2fd23b8628a3abc27c290d01d

--- src/main.cpp.orig	2016-04-19 15:08:35.000000000 +0000
+++ src/main.cpp
@@ -76,8 +76,6 @@
 #include <glib.h>
 #include <gst/gst.h>
 
-#include <echonest/Config.h>
-
 #ifdef Q_OS_DARWIN
 #include <sys/resource.h>
 #include <sys/sysctl.h>
@@ -440,10 +438,6 @@ int main(int argc, char* argv[]) {
   Application app;
   app.set_language_name(language);
 
-  Echonest::Config::instance()->setAPIKey("DFLFLJBUF4EGTXHIG");
-  Echonest::Config::instance()->setNetworkAccessManager(
-      new NetworkAccessManager);
-
   // Network proxy
   QNetworkProxyFactory::setApplicationProxyFactory(
       NetworkProxyFactory::Instance());
