$NetBSD$

--- extensions/browser/api/messaging/message_service.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ extensions/browser/api/messaging/message_service.cc
@@ -61,7 +61,7 @@ namespace {
 
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -391,7 +391,7 @@ void MessageService::OpenChannelToNative
   if (!opener_port->IsValidPort())
     return;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   bool has_permission = extension->permissions_data()->HasAPIPermission(
       APIPermission::kNativeMessaging);
   if (!has_permission) {
@@ -441,7 +441,7 @@ void MessageService::OpenChannelToNative
   channel->opener->IncrementLazyKeepaliveCount();
 
   AddChannel(std::move(channel), receiver_port_id);
-#else  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX))
+#else  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)) || defined(OS_BSD)
   const char kNativeMessagingNotSupportedError[] =
       "Native Messaging is not supported on this platform.";
   opener_port->DispatchOnDisconnect(kNativeMessagingNotSupportedError);
