$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/config/gpu_control_list.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gpu/config/gpu_control_list.cc
@@ -276,7 +276,7 @@ bool GpuControlList::More::GLVersionInfo
 GpuControlList::GLType GpuControlList::More::GetDefaultGLType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return kGLTypeGL;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kGLTypeGL;
 #elif BUILDFLAG(IS_MAC)
   return kGLTypeGL;
@@ -847,7 +847,7 @@ GpuControlList::OsType GpuControlList::G
   return kOsAndroid;
 #elif BUILDFLAG(IS_FUCHSIA)
   return kOsFuchsia;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_MAC)
   return kOsMacosx;
