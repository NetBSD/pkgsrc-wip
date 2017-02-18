$NetBSD$

--- ipc/ipc_channel_common.cc.orig	2017-02-02 02:02:55.000000000 +0000
+++ ipc/ipc_channel_common.cc
@@ -9,7 +9,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
