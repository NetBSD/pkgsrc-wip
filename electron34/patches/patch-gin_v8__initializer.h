$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/v8_initializer.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/v8_initializer.h
@@ -7,6 +7,8 @@
 
 #include <stdint.h>
 
+#include <string_view>
+
 #include "base/files/file.h"
 #include "base/files/memory_mapped_file.h"
 #include "build/build_config.h"
@@ -31,7 +33,8 @@ class GIN_EXPORT V8Initializer {
   // This should be called by IsolateHolder::Initialize().
   static void Initialize(IsolateHolder::ScriptMode mode,
                          const std::string& js_command_line_flags = {},
-                         v8::OOMErrorCallback oom_error_callback = nullptr);
+                         v8::OOMErrorCallback oom_error_callback = nullptr,
+                         bool create_v8_platform = true);
 
   // Get address and size information for currently loaded snapshot.
   // If no snapshot is loaded, the return values are null for addresses
@@ -41,6 +44,7 @@ class GIN_EXPORT V8Initializer {
                                         int* snapshot_size_out);
 
 #if defined(V8_USE_EXTERNAL_STARTUP_DATA)
+  static void LoadV8SnapshotFromFileName(std::string_view file_name, V8SnapshotFileType snapshot_file_type);
   // Load V8 snapshot from default resources, if they are available.
   static void LoadV8Snapshot(
       V8SnapshotFileType snapshot_file_type = V8SnapshotFileType::kDefault);
