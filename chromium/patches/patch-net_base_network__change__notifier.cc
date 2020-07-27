$NetBSD$

--- net/base/network_change_notifier.cc.orig	2020-07-15 18:56:47.000000000 +0000
+++ net/base/network_change_notifier.cc
@@ -35,7 +35,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif defined(OS_MACOSX)
 #include "net/base/network_change_notifier_mac.h"
-#elif defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#elif defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "net/base/network_change_notifier_posix.h"
 #elif defined(OS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -229,7 +229,7 @@ std::unique_ptr<NetworkChangeNotifier> N
   // service in a separate process.
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
-#elif defined(OS_CHROMEOS)
+#elif defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
 #elif defined(OS_LINUX)
@@ -240,6 +240,8 @@ std::unique_ptr<NetworkChangeNotifier> N
 #elif defined(OS_FUCHSIA)
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       0 /* required_features */);
+#elif defined(OS_BSD)
+  return NULL;
 #else
   NOTIMPLEMENTED();
   return NULL;
