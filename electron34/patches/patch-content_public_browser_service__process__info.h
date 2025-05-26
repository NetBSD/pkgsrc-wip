$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/service_process_info.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/service_process_info.h
@@ -64,7 +64,13 @@ class CONTENT_EXPORT ServiceProcessInfo 
   const std::optional<GURL>& site() const { return site_; }
   const base::Process& GetProcess() const { return process_; }
 
+  void set_exit_code(int exit_code) { exit_code_ = exit_code; }
+  int exit_code() const { return exit_code_; }
+
  private:
+  // The exit code of the process, if it has exited.
+  int exit_code_ = 0;
+
   // The name of the service interface for which the process was launched.
   std::string service_interface_name_;
 
