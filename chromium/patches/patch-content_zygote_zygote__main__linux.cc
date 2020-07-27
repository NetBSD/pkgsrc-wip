$NetBSD$

--- content/zygote/zygote_main_linux.cc.orig	2020-07-15 18:56:47.000000000 +0000
+++ content/zygote/zygote_main_linux.cc
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -100,6 +102,9 @@ static bool CreateInitProcessReaper(
 // created through the setuid sandbox.
 static bool EnterSuidSandbox(sandbox::SetuidSandboxClient* setuid_sandbox,
                              base::OnceClosure post_fork_parent_callback) {
+#if defined(OS_BSD)
+  return false;
+#else
   DCHECK(setuid_sandbox);
   DCHECK(setuid_sandbox->IsSuidSandboxChild());
 
@@ -132,6 +137,7 @@ static bool EnterSuidSandbox(sandbox::Se
 
   CHECK(service_manager::SandboxDebugHandling::SetDumpableStatusAndHandlers());
   return true;
+#endif
 }
 
 static void DropAllCapabilities(int proc_fd) {
