$NetBSD$

--- chrome/app/shutdown_signal_handlers_posix.cc.orig	2020-07-15 18:55:49.000000000 +0000
+++ chrome/app/shutdown_signal_handlers_posix.cc
@@ -186,6 +186,11 @@ void InstallShutdownSignalHandlers(
   g_pipe_pid = getpid();
   g_shutdown_pipe_read_fd = pipefd[0];
   g_shutdown_pipe_write_fd = pipefd[1];
+#if defined(OS_BSD)
+  // PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+  // we request the default pthread stack size by specifying 0 here.
+  const size_t kShutdownDetectorThreadStackSize = 0;
+#else
 #if !defined(ADDRESS_SANITIZER)
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 2;
 #else
@@ -193,6 +198,7 @@ void InstallShutdownSignalHandlers(
   // stack size to avoid hitting the guard page.
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 4;
 #endif
+#endif
   ShutdownDetector* detector = new ShutdownDetector(
       g_shutdown_pipe_read_fd, std::move(shutdown_callback), task_runner);
   // PlatformThread does not delete its delegate.
