$NetBSD$

--- net/base/network_change_notifier.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/base/network_change_notifier.cc
@@ -532,7 +532,6 @@ NetworkChangeNotifier* NetworkChangeNoti
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
