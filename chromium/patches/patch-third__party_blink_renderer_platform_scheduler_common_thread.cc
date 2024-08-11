$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2024-07-24 02:44:46.925778000 +0000
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -82,7 +82,7 @@ void Thread::CreateAndSetCompositorThrea
       std::make_unique<scheduler::CompositorThread>(params);
   compositor_thread->Init();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(&base::PlatformThread::CurrentId),
       base::BindOnce([](base::PlatformThreadId compositor_thread_id) {
