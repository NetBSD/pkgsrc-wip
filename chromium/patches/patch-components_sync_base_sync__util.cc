$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/base/sync_util.cc.orig	2024-10-26 07:00:11.282456000 +0000
+++ components/sync/base/sync_util.cc
@@ -45,6 +45,8 @@ std::string GetSystemString() {
   system = "FREEBSD ";
 #elif BUILDFLAG(IS_OPENBSD)
   system = "OPENBSD ";
+#elif BUILDFLAG(IS_NETBSD)
+  system = "NETBSD ";
 #elif BUILDFLAG(IS_MAC)
   system = "MAC ";
 #endif
