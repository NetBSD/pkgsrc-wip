$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.h.orig	2024-10-18 12:34:32.161688000 +0000
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.h
@@ -6,7 +6,13 @@
 #define SERVICES_SCREEN_AI_SANDBOX_SCREEN_AI_SANDBOX_HOOK_LINUX_H_
 
 #include "base/files/file_path.h"
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace screen_ai {
 
