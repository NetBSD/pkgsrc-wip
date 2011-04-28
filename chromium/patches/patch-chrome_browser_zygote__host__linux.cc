$NetBSD: patch-chrome_browser_zygote__host__linux.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/zygote_host_linux.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/zygote_host_linux.cc
@@ -61,7 +61,12 @@ ZygoteHost::ZygoteHost()
 }
 
 ZygoteHost::~ZygoteHost() {
+    Pickle pickle;
   if (init_)
+#if defined(OS_BSD)
+    pickle.WriteInt(kCmdEnd);
+    HANDLE_EINTR(write(control_fd_, pickle.data(), pickle.size()));
+#endif
     close(control_fd_);
 }
 
@@ -81,7 +86,12 @@ void ZygoteHost::Init(const std::string&
   cmd_line.AppendSwitchASCII(switches::kProcessType, switches::kZygoteProcess);
 
   int fds[2];
+#if defined(OS_BSD)
+  if (socketpair(PF_UNIX, SOCK_SEQPACKET, 0, fds) != 0)
+    CHECK(socketpair(PF_UNIX, SOCK_DGRAM, 0, fds) == 0);
+#else
   CHECK(socketpair(PF_UNIX, SOCK_SEQPACKET, 0, fds) == 0);
+#endif
   base::file_handle_mapping_vector fds_to_map;
   fds_to_map.push_back(std::make_pair(fds[1], 3));
 
@@ -149,6 +159,7 @@ void ZygoteHost::Init(const std::string&
     // We need to look for it.
     // But first, wait for the zygote to tell us it's running.
     // The sending code is in chrome/browser/zygote_main_linux.cc.
+#if defined(OS_LINUX)
     std::vector<int> fds_vec;
     const int kExpectedLength = sizeof(kZygoteMagic);
     char buf[kExpectedLength];
@@ -179,6 +190,7 @@ void ZygoteHost::Init(const std::string&
       // Reap the sandbox.
       ProcessWatcher::EnsureProcessGetsReaped(process);
     }
+#endif // defined(OS_LINUX)
   } else {
     // Not using the SUID sandbox.
     pid_ = process;
@@ -246,12 +258,15 @@ pid_t ZygoteHost::ForkRenderer(
       return base::kNullProcessHandle;
   }
 
+#if defined(OS_LINUX)
   const int kRendererScore = 5;
   AdjustRendererOOMScore(pid, kRendererScore);
+#endif
 
   return pid;
 }
 
+#if defined(OS_LINUX)
 void ZygoteHost::AdjustRendererOOMScore(base::ProcessHandle pid, int score) {
   // 1) You can't change the oom_adj of a non-dumpable process (EPERM) unless
   //    you're root. Because of this, we can't set the oom_adj from the browser
@@ -303,6 +318,7 @@ void ZygoteHost::AdjustRendererOOMScore(
       PLOG(ERROR) << "Failed to adjust OOM score of renderer with pid " << pid;
   }
 }
+#endif  // defined(OS_LINUX)
 
 void ZygoteHost::EnsureProcessTerminated(pid_t process) {
   DCHECK(init_);
