$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/child/child_process.cc.orig	2024-10-18 12:34:14.198494700 +0000
+++ content/child/child_process.cc
@@ -35,7 +35,7 @@
 #include "content/common/android/cpu_time_metrics.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -70,7 +70,7 @@ ChildProcess::ChildProcess(base::ThreadT
                                thread_pool_init_params)
     : resetter_(&child_process, this, nullptr),
       io_thread_(std::make_unique<ChildIOThread>()) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   const bool is_embedded_in_browser_process =
@@ -199,7 +199,7 @@ void ChildProcess::set_main_thread(Child
   main_thread_.reset(thread);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ChildProcess::SetIOThreadType(base::ThreadType thread_type) {
   if (!io_thread_) {
     return;
