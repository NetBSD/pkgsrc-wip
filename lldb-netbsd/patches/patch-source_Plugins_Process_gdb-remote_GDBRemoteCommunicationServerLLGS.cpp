$NetBSD$

--- source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerLLGS.cpp.orig	2017-03-18 01:35:30.062550938 +0000
+++ source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerLLGS.cpp
@@ -2665,7 +2665,7 @@ GDBRemoteCommunication::PacketResult
 GDBRemoteCommunicationServerLLGS::Handle_qXfer_auxv_read(
     StringExtractorGDBRemote &packet) {
 // *BSD impls should be able to do this too.
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   Log *log(GetLogIfAnyCategoriesSet(LIBLLDB_LOG_PROCESS));
 
   // Parse out the offset.
