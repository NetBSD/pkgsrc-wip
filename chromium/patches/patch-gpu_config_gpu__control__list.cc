$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_control_list.cc.orig	2024-09-24 20:49:29.974992800 +0000
+++ gpu/config/gpu_control_list.cc
@@ -282,7 +282,7 @@ bool GpuControlList::More::GLVersionInfo
 GpuControlList::GLType GpuControlList::More::GetDefaultGLType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return kGLTypeGL;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kGLTypeGL;
 #elif BUILDFLAG(IS_MAC)
   return kGLTypeGL;
@@ -819,7 +819,7 @@ GpuControlList::OsType GpuControlList::G
   return kOsAndroid;
 #elif BUILDFLAG(IS_FUCHSIA)
   return kOsFuchsia;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_MAC)
   return kOsMacosx;
