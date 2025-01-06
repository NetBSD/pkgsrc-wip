$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/child_process_launcher_helper_mac.cc.orig	2024-10-18 12:34:12.251504000 +0000
+++ content/browser/child_process_launcher_helper_mac.cc
@@ -123,7 +123,8 @@ bool ChildProcessLauncherHelper::BeforeL
       'mojo', base::MachRendezvousPort(endpoint.TakeMachReceiveRight())));
 
   options->environment = delegate_->GetEnvironment();
-
+  options->clear_environment = !delegate_->ShouldInheritEnvironment();
+  options->current_directory = delegate_->GetCurrentDirectory();
   options->disclaim_responsibility = delegate_->DisclaimResponsibility();
   options->enable_cpu_security_mitigations =
       delegate_->EnableCpuSecurityMitigations();
@@ -193,6 +194,11 @@ bool ChildProcessLauncherHelper::BeforeL
         base::StringPrintf("%s%d", sandbox::switches::kSeatbeltClient, pipe));
   }
 
+  for (const auto& remapped_fd : file_data_->additional_remapped_fds) {
+    options->fds_to_remap.emplace_back(remapped_fd.second.get(),
+                                       remapped_fd.first);
+  }
+
   return true;
 }
 
