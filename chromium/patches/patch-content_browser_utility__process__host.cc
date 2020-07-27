$NetBSD$

--- content/browser/utility_process_host.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ content/browser/utility_process_host.cc
@@ -275,7 +275,7 @@ UtilityProcessHost::UtilityProcessHost()
 
 UtilityProcessHost::UtilityProcessHost(std::unique_ptr<Client> client)
     : sandbox_type_(service_manager::SandboxType::kUtility),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
@@ -487,7 +487,7 @@ bool UtilityProcessHost::StartProcess() 
       switches::kMuteAudio,
       switches::kUseFileForFakeAudioCapture,
       switches::kAgcStartupMinVolume,
-#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_SOLARIS)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
       switches::kAlsaInputDevice,
       switches::kAlsaOutputDevice,
 #endif
