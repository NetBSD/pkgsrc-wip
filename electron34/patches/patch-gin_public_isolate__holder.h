$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/public/isolate_holder.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/public/isolate_holder.h
@@ -87,7 +87,8 @@ class GIN_EXPORT IsolateHolder {
       scoped_refptr<base::SingleThreadTaskRunner> user_visible_task_runner =
           nullptr,
       scoped_refptr<base::SingleThreadTaskRunner> best_effort_task_runner =
-          nullptr);
+          nullptr,
+      v8::Isolate* isolate = nullptr);
   IsolateHolder(
       scoped_refptr<base::SingleThreadTaskRunner> task_runner,
       AccessMode access_mode,
@@ -97,7 +98,8 @@ class GIN_EXPORT IsolateHolder {
       scoped_refptr<base::SingleThreadTaskRunner> user_visible_task_runner =
           nullptr,
       scoped_refptr<base::SingleThreadTaskRunner> best_effort_task_runner =
-          nullptr);
+          nullptr,
+      v8::Isolate* isolate = nullptr);
   IsolateHolder(const IsolateHolder&) = delete;
   IsolateHolder& operator=(const IsolateHolder&) = delete;
   ~IsolateHolder();
@@ -117,7 +119,8 @@ class GIN_EXPORT IsolateHolder {
                          const intptr_t* reference_table = nullptr,
                          const std::string js_command_line_flags = {},
                          v8::FatalErrorCallback fatal_error_callback = nullptr,
-                         v8::OOMErrorCallback oom_error_callback = nullptr);
+                         v8::OOMErrorCallback oom_error_callback = nullptr,
+                         bool create_v8_platform = true);
 
   // Returns whether `Initialize` has already been invoked in the process.
   // Initialization is a one-way operation (i.e., this method cannot return
@@ -127,6 +130,8 @@ class GIN_EXPORT IsolateHolder {
   // Should only be called after v8::IsolateHolder::Initialize() is invoked.
   static std::unique_ptr<v8::Isolate::CreateParams> getDefaultIsolateParams();
 
+  static bool DestroyedMicrotasksRunner();
+
   v8::Isolate* isolate() { return isolate_; }
 
   // This method returns if v8::Locker is needed to access isolate.
@@ -140,6 +145,9 @@ class GIN_EXPORT IsolateHolder {
 
   void EnableIdleTasks(std::unique_ptr<V8IdleTaskRunner> idle_task_runner);
 
+  void WillCreateMicrotasksRunner();
+  void WillDestroyMicrotasksRunner();
+
   // This method returns V8IsolateMemoryDumpProvider of this isolate, used for
   // testing.
   V8IsolateMemoryDumpProvider* isolate_memory_dump_provider_for_testing()
