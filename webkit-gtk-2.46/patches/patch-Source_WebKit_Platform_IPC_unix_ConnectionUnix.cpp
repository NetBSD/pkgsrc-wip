$NetBSD: patch-Source_WebKit_Platform_IPC_unix_ConnectionUnix.cpp,v 1.3 2021/01/12 15:21:31 jperkin Exp $

On NetBSD we see "Error sending IPC message: Message too long" due to
the use of sendmsg with a large message body (EMSGSIZE).

WebKit already uses shared memory to communicate the message body when
the message is too large, so force it to always use this method to avoid
encountering EMSGSIZE.

--- Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp.orig	2025-05-17 14:36:17.895637982 +0000
+++ Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp
@@ -64,6 +64,10 @@
 #endif
 #endif // SOCK_SEQPACKET
 
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL   0
+#endif
+
 WTF_ALLOW_UNSAFE_BUFFER_USAGE_BEGIN // Unix port
 
 namespace IPC {
@@ -424,8 +428,12 @@ bool Connection::sendOutgoingMessage(Uni
         return false;
     }
 
+#if 0
     size_t messageSizeWithBodyInline = sizeof(MessageInfo) + (outputMessage.attachments().size() * sizeof(AttachmentInfo)) + outputMessage.bodySize();
     if (messageSizeWithBodyInline > messageMaxSize && outputMessage.bodySize()) {
+#else
+    {
+#endif
         RefPtr oolMessageBody = WebCore::SharedMemory::allocate(outputMessage.bodySize());
         if (!oolMessageBody)
             return false;
