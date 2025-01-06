$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/v8_initializer.cc.orig	2024-10-18 12:34:18.336388300 +0000
+++ gin/v8_initializer.cc
@@ -486,7 +486,8 @@ void SetFlags(IsolateHolder::ScriptMode 
 // static
 void V8Initializer::Initialize(IsolateHolder::ScriptMode mode,
                                const std::string js_command_line_flags,
-                               v8::OOMErrorCallback oom_error_callback) {
+                               v8::OOMErrorCallback oom_error_callback,
+                               bool create_v8_platform) {
   static bool v8_is_initialized = false;
   if (v8_is_initialized)
     return;
@@ -496,7 +497,8 @@ void V8Initializer::Initialize(IsolateHo
   // See https://crbug.com/v8/11043
   SetFlags(mode, js_command_line_flags);
 
-  v8::V8::InitializePlatform(V8Platform::Get());
+  if (create_v8_platform)
+    v8::V8::InitializePlatform(V8Platform::Get());
 
   // Set this as early as possible in order to ensure OOM errors are reported
   // correctly.
@@ -596,8 +598,7 @@ void V8Initializer::GetV8ExternalSnapsho
 
 #if defined(V8_USE_EXTERNAL_STARTUP_DATA)
 
-// static
-void V8Initializer::LoadV8Snapshot(V8SnapshotFileType snapshot_file_type) {
+void V8Initializer::LoadV8SnapshotFromFileName(base::StringPiece file_name, V8SnapshotFileType snapshot_file_type) {
   if (g_mapped_snapshot) {
     // TODO(crbug.com/40558459): Confirm not loading different type of snapshot
     // files in a process.
@@ -606,11 +607,18 @@ void V8Initializer::LoadV8Snapshot(V8Sna
 
   base::MemoryMappedFile::Region file_region;
   base::File file =
-      OpenV8File(GetSnapshotFileName(snapshot_file_type), &file_region);
+      OpenV8File(file_name.data(), &file_region);
   LoadV8SnapshotFromFile(std::move(file), &file_region, snapshot_file_type);
 }
 
 // static
+void V8Initializer::LoadV8Snapshot(V8SnapshotFileType snapshot_file_type) {
+  const char* file_name = GetSnapshotFileName(snapshot_file_type);
+
+  LoadV8SnapshotFromFileName(file_name, snapshot_file_type);
+}
+
+// static
 void V8Initializer::LoadV8SnapshotFromFile(
     base::File snapshot_file,
     base::MemoryMappedFile::Region* snapshot_file_region,
