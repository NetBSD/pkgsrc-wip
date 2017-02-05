$NetBSD$

--- tools/debugserver/source/MacOSX/DarwinLog/DarwinLogCollector.cpp.orig	2017-01-28 19:35:15.000000000 +0000
+++ tools/debugserver/source/MacOSX/DarwinLog/DarwinLogCollector.cpp
@@ -46,10 +46,10 @@ static os_activity_stream_set_event_hand
     s_os_activity_stream_set_event_handler;
 
 bool LookupSPICalls() {
-  static std::once_flag s_once_flag;
+  static llvm::once_flag s_once_flag;
   static bool s_has_spi;
 
-  std::call_once(s_once_flag, [] {
+  llvm::call_once(s_once_flag, [] {
     dlopen ("/System/Library/PrivateFrameworks/LoggingSupport.framework/LoggingSupport", RTLD_NOW);
     s_os_activity_stream_for_pid = (os_activity_stream_for_pid_t)dlsym(
         RTLD_DEFAULT, "os_activity_stream_for_pid");
