$NetBSD$

--- tools/debugserver/source/MacOSX/DarwinLog/DarwinLogCollector.cpp.orig	2016-12-17 10:30:47.000000000 +0000
+++ tools/debugserver/source/MacOSX/DarwinLog/DarwinLogCollector.cpp
@@ -28,6 +28,8 @@
 #include "RNBDefs.h"
 #include "RNBRemote.h"
 
+using namespace llvm;
+
 // Use an anonymous namespace for variables and methods that have no
 // reason to leak out through the interface.
 namespace {
@@ -46,10 +48,10 @@ static os_activity_stream_set_event_hand
     s_os_activity_stream_set_event_handler;
 
 bool LookupSPICalls() {
-  static std::once_flag s_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
   static bool s_has_spi;
 
-  std::call_once(s_once_flag, [] {
+  llvm::call_once(s_once_flag, [] {
     s_os_activity_stream_for_pid = (os_activity_stream_for_pid_t)dlsym(
         RTLD_DEFAULT, "os_activity_stream_for_pid");
     s_os_activity_stream_resume = (os_activity_stream_resume_t)dlsym(
