$NetBSD: patch-third__party_perfetto_src_base_utils.cc,v 1.1 2025/02/06 09:58:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/utils.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/perfetto/src/base/utils.cc
@@ -38,8 +38,9 @@
 #include <mach/vm_page_size.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 #include <sys/prctl.h>
 
 #ifndef PR_GET_TAGGED_ADDR_CTRL
@@ -278,14 +279,22 @@ void Daemonize(std::function<int()> pare
 
 std::string GetCurExecutablePath() {
   std::string self_path;
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_FUCHSIA)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FUCHSIA)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   char buf[PATH_MAX];
   ssize_t size = readlink("/proc/self/exe", buf, sizeof(buf));
   PERFETTO_CHECK(size != -1);
   // readlink does not null terminate.
   self_path = std::string(buf, static_cast<size_t>(size));
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+  char *buf;
+  const char *cpath = "@PREFIX@/lib/chromium/chrome";
+  if ((buf = getenv("CHROME_EXE_PATH")) != NULL)
+    self_path = std::string(buf);
+  else
+    self_path = std::string(cpath);
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   uint32_t size = 0;
   PERFETTO_CHECK(_NSGetExecutablePath(nullptr, &size));
@@ -337,8 +346,9 @@ void AlignedFree(void* ptr) {
 }
 
 bool IsSyncMemoryTaggingEnabled() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   // Compute only once per lifetime of the process.
   static bool cached_value = [] {
     const int res = prctl(PR_GET_TAGGED_ADDR_CTRL, 0, 0, 0, 0);
