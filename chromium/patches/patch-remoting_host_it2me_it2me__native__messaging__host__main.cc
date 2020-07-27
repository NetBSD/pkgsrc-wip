$NetBSD$

--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc
@@ -29,7 +29,7 @@
 #include "remoting/host/switches.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
@@ -112,7 +112,7 @@ int It2MeNativeMessagingHostMain(int arg
 
   remoting::LoadResources("");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Required in order for us to run multiple X11 threads.
   XInitThreads();
 
