$NetBSD: patch-net_base_network__change__notifier.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/base/network_change_notifier.cc.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/base/network_change_notifier.cc
@@ -42,7 +42,6 @@ NetworkChangeNotifier* NetworkChangeNoti
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
