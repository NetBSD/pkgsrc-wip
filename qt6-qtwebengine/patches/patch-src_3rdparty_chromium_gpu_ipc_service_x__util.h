$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/ipc/service/x_util.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/service/x_util.h
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_config.h"
 #include "ui/base/ozone_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 
 namespace gpu {
 
