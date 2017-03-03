$NetBSD$

--- source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerLLGS.cpp.orig	2017-02-27 20:47:52.000000000 +0000
+++ source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerLLGS.cpp
@@ -2666,7 +2666,7 @@ GDBRemoteCommunication::PacketResult
 GDBRemoteCommunicationServerLLGS::Handle_qXfer_auxv_read(
     StringExtractorGDBRemote &packet) {
 // *BSD impls should be able to do this too.
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   Log *log(GetLogIfAnyCategoriesSet(LIBLLDB_LOG_PROCESS));
 
   // Parse out the offset.
@@ -3222,7 +3222,7 @@ void GDBRemoteCommunicationServerLLGS::C
 
 // Clear any auxv cached data.
 // *BSD impls should be able to do this too.
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   if (log)
     log->Printf("GDBRemoteCommunicationServerLLGS::%s clearing auxv buffer "
                 "(previously %s)",
