$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/sandbox/policy/features.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/features.cc
@@ -20,9 +20,13 @@ namespace sandbox::policy::features {
 // (Only causes an effect when feature kNetworkServiceInProcess is disabled.)
 BASE_FEATURE(kNetworkServiceSandbox,
              "NetworkServiceSandbox",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables a fine-grained seccomp-BPF syscall filter for the network service.
 // Only has an effect if IsNetworkSandboxEnabled() returns true.
 // If the network service sandbox is enabled and |kNetworkServiceSyscallFilter|
@@ -134,7 +138,7 @@ BASE_FEATURE(kSpectreVariant2Mitigation,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enabling the kNetworkServiceSandbox feature automatically enables Spectre
 // variant 2 mitigations in the network service. This can lead to performance
 // regressions, so enabling this feature will turn off the Spectre Variant 2
