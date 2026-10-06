$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/services/on_device_translation/sandbox_hook.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/services/on_device_translation/sandbox_hook.h
@@ -5,7 +5,13 @@
 #ifndef COMPONENTS_SERVICES_ON_DEVICE_TRANSLATION_SANDBOX_HOOK_H_
 #define COMPONENTS_SERVICES_ON_DEVICE_TRANSLATION_SANDBOX_HOOK_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace on_device_translation {
 
