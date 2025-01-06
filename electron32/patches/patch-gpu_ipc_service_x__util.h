$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/ipc/service/x_util.h.orig	2024-10-18 12:34:18.928091000 +0000
+++ gpu/ipc/service/x_util.h
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_config.h"
 #include "ui/base/ozone_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 
 namespace gpu {
 
