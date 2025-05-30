$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/v8_snapshot_files.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/v8_snapshot_files.cc
@@ -17,7 +17,7 @@ namespace content {
 std::map<std::string, absl::variant<base::FilePath, base::ScopedFD>>
 GetV8SnapshotFilesToPreload(base::CommandLine& process_command_line) {
   std::map<std::string, absl::variant<base::FilePath, base::ScopedFD>> files;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_V8_CONTEXT_SNAPSHOT)
   files[kV8ContextSnapshotDataDescriptor] = base::FilePath(
       FILE_PATH_LITERAL(BUILDFLAG(V8_CONTEXT_SNAPSHOT_FILENAME)));
