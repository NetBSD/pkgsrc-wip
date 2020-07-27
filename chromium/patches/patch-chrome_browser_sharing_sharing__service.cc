$NetBSD$

--- chrome/browser/sharing/sharing_service.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/sharing/sharing_service.cc
@@ -31,7 +31,7 @@ SharingMessageSender::DelegateType GetSe
     const syncer::DeviceInfo& device,
     const chrome_browser_sharing::SharingMessage& message) {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   // Messages other than SharedClipboard are always sent via FCM.
   if (message.payload_case() !=
       chrome_browser_sharing::SharingMessage::kSharedClipboardMessage) {
