$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/system_cpu/cpu_probe.cc.orig	2025-01-27 17:37:37.000000000 +0000
+++ components/system_cpu/cpu_probe.cc
@@ -30,6 +30,9 @@ std::unique_ptr<CpuProbe> CpuProbe::Crea
   return CpuProbeWin::Create();
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create();
+#elif BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return nullptr;
 #else
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
