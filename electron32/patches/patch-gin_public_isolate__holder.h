$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/public/isolate_holder.h.orig	2024-10-18 12:34:18.336388300 +0000
+++ gin/public/isolate_holder.h
@@ -85,7 +85,8 @@ class GIN_EXPORT IsolateHolder {
       v8::CreateHistogramCallback create_histogram_callback = nullptr,
       v8::AddHistogramSampleCallback add_histogram_sample_callback = nullptr,
       scoped_refptr<base::SingleThreadTaskRunner> low_priority_task_runner =
-          nullptr);
+          nullptr,
+      v8::Isolate* isolate = nullptr);
   IsolateHolder(
       scoped_refptr<base::SingleThreadTaskRunner> task_runner,
       AccessMode access_mode,
@@ -93,7 +94,8 @@ class GIN_EXPORT IsolateHolder {
       std::unique_ptr<v8::Isolate::CreateParams> params,
       IsolateCreationMode isolate_creation_mode = IsolateCreationMode::kNormal,
       scoped_refptr<base::SingleThreadTaskRunner> low_priority_task_runner =
-          nullptr);
+          nullptr,
+      v8::Isolate* isolate = nullptr);
   IsolateHolder(const IsolateHolder&) = delete;
   IsolateHolder& operator=(const IsolateHolder&) = delete;
   ~IsolateHolder();
@@ -113,7 +115,8 @@ class GIN_EXPORT IsolateHolder {
                          const intptr_t* reference_table = nullptr,
                          const std::string js_command_line_flags = {},
                          v8::FatalErrorCallback fatal_error_callback = nullptr,
-                         v8::OOMErrorCallback oom_error_callback = nullptr);
+                         v8::OOMErrorCallback oom_error_callback = nullptr,
+                         bool create_v8_platform = true);
 
   // Returns whether `Initialize` has already been invoked in the process.
   // Initialization is a one-way operation (i.e., this method cannot return
