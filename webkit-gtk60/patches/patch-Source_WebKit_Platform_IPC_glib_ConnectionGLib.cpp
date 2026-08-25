$NetBSD$

On NetBSD we see "Error sending IPC message: Message too long" due to
the use of sendmsg with a large message body (EMSGSIZE).

WebKit already uses shared memory to communicate the message body when
the message is too large, so force it to always use this method to avoid
encountering EMSGSIZE.

--- Source/WebKit/Platform/IPC/glib/ConnectionGLib.cpp.orig	2026-08-25 07:43:57.268996834 +0000
+++ Source/WebKit/Platform/IPC/glib/ConnectionGLib.cpp
@@ -343,8 +343,12 @@ bool Connection::sendOutgoingMessage(UniqueRef<Encoder
         return false;
     }
 
+#if !defined(__NetBSD__)
     size_t messageSizeWithBodyInline = sizeof(MessageInfo) + (outputMessage.attachments().size() * sizeof(AttachmentInfo)) + outputMessage.bodySize();
     if (messageSizeWithBodyInline > s_messageMaxSize && outputMessage.bodySize()) {
+#else
+    {
+#endif
         if (!outputMessage.setBodyOutOfLine())
             return false;
     }
