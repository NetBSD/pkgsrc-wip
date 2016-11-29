$NetBSD$

--- content/browser/utility_process_host_impl.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/utility_process_host_impl.cc
@@ -44,7 +44,7 @@
 #include "services/shell/public/cpp/interface_provider.h"
 #include "ui/base/ui_base_switches.h"
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/browser/zygote_handle_linux.h"
 #endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
 
@@ -55,7 +55,7 @@
 
 namespace content {
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 namespace {
 ZygoteHandle g_utility_zygote;
 }  // namespace
@@ -75,7 +75,7 @@ class UtilitySandboxedProcessLauncherDel
         launch_elevated_(launch_elevated)
 #elif defined(OS_POSIX)
         env_(env),
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         no_sandbox_(no_sandbox),
 #endif  // !defined(OS_MACOSX)  && !defined(OS_ANDROID)
         ipc_fd_(host->TakeClientFileDescriptor())
@@ -107,7 +107,7 @@ class UtilitySandboxedProcessLauncherDel
 
 #elif defined(OS_POSIX)
 
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     if (no_sandbox_ || !exposed_dir_.empty())
       return nullptr;
@@ -129,7 +129,7 @@ class UtilitySandboxedProcessLauncherDel
   bool launch_elevated_;
 #elif defined(OS_POSIX)
   base::EnvironmentMap env_;
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   bool no_sandbox_;
 #endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID)
   base::ScopedFD ipc_fd_;
@@ -157,7 +157,7 @@ UtilityProcessHostImpl::UtilityProcessHo
       is_batch_mode_(false),
       no_sandbox_(false),
       run_elevated_(false),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
@@ -238,7 +238,7 @@ void UtilityProcessHostImpl::SetName(con
   name_ = name;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void UtilityProcessHostImpl::EarlyZygoteLaunch() {
   DCHECK(!g_utility_zygote);
