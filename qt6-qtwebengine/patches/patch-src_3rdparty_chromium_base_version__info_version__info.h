$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/version_info/version_info.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/version_info/version_info.h
@@ -74,6 +74,8 @@ constexpr std::string_view GetOSType() {
   return "FreeBSD";
 #elif BUILDFLAG(IS_OPENBSD)
   return "OpenBSD";
+#elif BUILDFLAG(IS_NETBSD)
+  return "NetBSD";
 #elif BUILDFLAG(IS_SOLARIS)
   return "Solaris";
 #elif BUILDFLAG(IS_FUCHSIA)
