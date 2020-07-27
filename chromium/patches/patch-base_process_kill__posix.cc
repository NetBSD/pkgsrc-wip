$NetBSD$

--- base/process/kill_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ base/process/kill_posix.cc
@@ -168,7 +168,7 @@ void EnsureProcessTerminated(Process pro
       0, new BackgroundReaper(std::move(process), TimeDelta::FromSeconds(2)));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
