$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/v8_initializer.h.orig	2024-10-18 12:34:18.336388300 +0000
+++ gin/v8_initializer.h
@@ -9,6 +9,7 @@
 
 #include "base/files/file.h"
 #include "base/files/memory_mapped_file.h"
+#include "base/strings/string_piece.h"
 #include "build/build_config.h"
 #include "gin/array_buffer.h"
 #include "gin/gin_export.h"
@@ -31,7 +32,8 @@ class GIN_EXPORT V8Initializer {
   // This should be called by IsolateHolder::Initialize().
   static void Initialize(IsolateHolder::ScriptMode mode,
                          const std::string js_command_line_flags = {},
-                         v8::OOMErrorCallback oom_error_callback = nullptr);
+                         v8::OOMErrorCallback oom_error_callback = nullptr,
+                         bool create_v8_platform = true);
 
   // Get address and size information for currently loaded snapshot.
   // If no snapshot is loaded, the return values are null for addresses
@@ -41,6 +43,7 @@ class GIN_EXPORT V8Initializer {
                                         int* snapshot_size_out);
 
 #if defined(V8_USE_EXTERNAL_STARTUP_DATA)
+  static void LoadV8SnapshotFromFileName(base::StringPiece file_name, V8SnapshotFileType snapshot_file_type);
   // Load V8 snapshot from default resources, if they are available.
   static void LoadV8Snapshot(
       V8SnapshotFileType snapshot_file_type = V8SnapshotFileType::kDefault);
