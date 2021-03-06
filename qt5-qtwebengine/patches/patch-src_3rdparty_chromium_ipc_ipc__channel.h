$NetBSD$

--- src/3rdparty/chromium/ipc/ipc_channel.h.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_channel.h
@@ -244,7 +244,7 @@ class COMPONENT_EXPORT(IPC) Channel : pu
   static std::string GenerateUniqueRandomChannelID();
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
