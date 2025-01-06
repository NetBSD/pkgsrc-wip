$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/service_process_host_impl.cc.orig	2024-10-18 12:34:13.730736300 +0000
+++ content/browser/service_process_host_impl.cc
@@ -73,12 +73,15 @@ class ServiceProcessTracker {
     processes_.erase(iter);
   }
 
-  void NotifyCrashed(ServiceProcessId id) {
+  void NotifyCrashed(ServiceProcessId id, int exit_code) {
     DCHECK_CURRENTLY_ON(BrowserThread::UI);
     auto iter = processes_.find(id);
     CHECK(iter != processes_.end(), base::NotFatalUntil::M130);
-    for (auto& observer : observers_)
-      observer.OnServiceProcessCrashed(iter->second.Duplicate());
+    for (auto& observer : observers_) {
+      auto params = iter->second.Duplicate();
+      params.set_exit_code(exit_code);
+      observer.OnServiceProcessCrashed(params);
+    }
     processes_.erase(iter);
   }
 
@@ -154,7 +157,7 @@ class UtilityProcessClient : public Util
         process_info_->service_process_id());
   }
 
-  void OnProcessCrashed() override {
+  void OnProcessCrashed(int exit_code) override {
     // TODO(crbug.com/40654042): It is unclear how we can observe
     // |OnProcessCrashed()| without observing |OnProcessLaunched()| first, but
     // it can happen on Android. Ignore the notification in this case.
@@ -162,7 +165,7 @@ class UtilityProcessClient : public Util
       return;
 
     GetServiceProcessTracker().NotifyCrashed(
-        process_info_->service_process_id());
+        process_info_->service_process_id(), exit_code);
   }
 
  private:
@@ -205,6 +208,16 @@ void LaunchServiceProcess(mojo::GenericP
       options.allow_gpu_client.value()) {
     host->SetAllowGpuClient();
   }
+
+#if BUILDFLAG(IS_WIN)
+  host->SetStdioHandles(std::move(options.stdout_handle), std::move(options.stderr_handle));
+#elif BUILDFLAG(IS_POSIX)
+  host->SetAdditionalFds(std::move(options.fds_to_remap));
+#endif
+  host->SetCurrentDirectory(options.current_directory);
+  host->SetEnv(options.environment);
+  if (options.clear_environment)
+    host->ClearEnvironment();
   host->Start();
   host->GetChildProcess()->BindServiceInterface(std::move(receiver));
 }
