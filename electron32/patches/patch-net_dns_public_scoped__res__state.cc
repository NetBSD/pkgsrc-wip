$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/dns/public/scoped_res_state.cc.orig	2024-10-18 12:34:30.278572800 +0000
+++ net/dns/public/scoped_res_state.cc
@@ -28,7 +28,7 @@ ScopedResState::~ScopedResState() {
 #if !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_FUCHSIA)
 
   // Prefer res_ndestroy where available.
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   res_ndestroy(&res_);
 #else
   res_nclose(&res_);
