$NetBSD$

--- ipc/ipc_channel.h.orig	2016-11-10 20:02:15.000000000 +0000
+++ ipc/ipc_channel.h
@@ -290,7 +290,7 @@ class IPC_EXPORT Channel : public Endpoi
       IPC::ChannelHandle* handle0,
       IPC::ChannelHandle* handle1);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
