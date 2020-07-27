$NetBSD$

--- chrome/browser/sharing/sharing_handler_registry_impl.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/sharing/sharing_handler_registry_impl.cc
@@ -25,7 +25,7 @@
 #endif  // defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/sharing/shared_clipboard/remote_copy_message_handler.h"
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
         // defined(OS_CHROMEOS)
@@ -74,7 +74,7 @@ SharingHandlerRegistryImpl::SharingHandl
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   if (sharing_device_registration->IsRemoteCopySupported()) {
     AddSharingHandler(
         std::make_unique<RemoteCopyMessageHandler>(profile),
