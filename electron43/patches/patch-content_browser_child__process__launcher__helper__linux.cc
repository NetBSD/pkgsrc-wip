$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/child_process_launcher_helper_linux.cc.orig	2026-08-17 18:32:36.000000000 +0000
+++ content/browser/child_process_launcher_helper_linux.cc
@@ -73,7 +73,25 @@ bool ChildProcessLauncherHelper::BeforeL
       options->fds_to_remap.emplace_back(sandbox_fd, GetSandboxFD());
     }
 
+    for (const auto& remapped_fd : file_data_->additional_remapped_fds) {
+      options->fds_to_remap.emplace_back(remapped_fd.second.get(),
+                                         remapped_fd.first);
+    }
+
+#if !BUILDFLAG(IS_BSD)
+    // (For Electron), if we're launching without zygote, that means we're
+    // launching an unsandboxed process (since all sandboxed processes are
+    // forked from the zygote). Relax the allow_new_privs option to permit
+    // launching suid processes from unsandboxed child processes.
+    if (!base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote) &&
+        delegate_->GetZygote() == nullptr) {
+      options->allow_new_privs = true;
+    }
+#endif
+
+    options->current_directory = delegate_->GetCurrentDirectory();
     options->environment = delegate_->GetEnvironment();
+    options->clear_environment = !delegate_->ShouldInheritEnvironment();
   } else {
 #if !BUILDFLAG(IS_BSD)
     DCHECK(GetZygoteForLaunch());
