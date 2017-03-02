$NetBSD$

--- source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerCommon.cpp.orig	2017-02-27 20:47:52.000000000 +0000
+++ source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerCommon.cpp
@@ -837,7 +837,7 @@ GDBRemoteCommunicationServerCommon::Hand
   response.PutCString(";QThreadSuffixSupported+");
   response.PutCString(";QListThreadsInStopReply+");
   response.PutCString(";qEcho+");
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   response.PutCString(";QPassSignals+");
   response.PutCString(";qXfer:auxv:read+");
 #endif
