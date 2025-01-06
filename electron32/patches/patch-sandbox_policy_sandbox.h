$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/policy/sandbox.h.orig	2024-10-18 12:34:31.997764600 +0000
+++ sandbox/policy/sandbox.h
@@ -12,6 +12,14 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if BUILDFLAG(IS_OPENBSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#elif BUILDFLAG(IS_NETBSD)
+#include "sandbox/policy/netbsd/sandbox_netbsd.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+#endif
+
 namespace sandbox {
 namespace mojom {
 enum class Sandbox;
@@ -32,7 +40,7 @@ namespace policy {
 
 class SANDBOX_POLICY_EXPORT Sandbox {
  public:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static bool Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options);
