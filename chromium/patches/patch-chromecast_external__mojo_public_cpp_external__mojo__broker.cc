$NetBSD$

--- chromecast/external_mojo/public/cpp/external_mojo_broker.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chromecast/external_mojo/public/cpp/external_mojo_broker.cc
@@ -7,7 +7,7 @@
 #include <map>
 #include <utility>
 
-#if OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/stat.h>
 #endif
 
@@ -400,7 +400,7 @@ ExternalMojoBroker::ExternalMojoBroker(c
       named_channel.TakeServerEndpoint();
   DCHECK(server_endpoint.is_valid());
 
-#if OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
   chmod(broker_path.c_str(), 0770);
 #endif
 
