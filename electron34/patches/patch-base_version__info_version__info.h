$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/version_info/version_info.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/version_info/version_info.h
@@ -74,6 +74,8 @@ constexpr std::string_view GetOSType() {
   return "FreeBSD";
 #elif BUILDFLAG(IS_OPENBSD)
   return "OpenBSD";
+#elif BUILDFLAG(IS_NETBSD)
+  return "NetBSD";
 #elif BUILDFLAG(IS_SOLARIS)
   return "Solaris";
 #elif BUILDFLAG(IS_FUCHSIA)
