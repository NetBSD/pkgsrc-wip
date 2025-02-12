$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.cc
@@ -27,7 +27,7 @@ BlinkCategorizedWorkerPoolDelegate& Blin
 
 void BlinkCategorizedWorkerPoolDelegate::NotifyThreadWillRun(
     base::PlatformThreadId tid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   scoped_refptr<base::TaskRunner> task_runner =
       Thread::MainThread()->GetTaskRunner(MainThreadTaskRunnerRestricted());
   task_runner->PostTask(FROM_HERE, base::BindOnce(
