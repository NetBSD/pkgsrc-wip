$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/linux/x11_util.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/linux/x11_util.cc
@@ -10,7 +10,7 @@
 namespace x11_util {
 
 bool IsX11() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const bool is = ui::GetOzonePlatformId() == ui::kPlatformX11;
   return is;
 #else
@@ -19,7 +19,7 @@ bool IsX11() {
 }
 
 bool IsWayland() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const bool is = ui::GetOzonePlatformId() == ui::kPlatformWayland;
   return is;
 #else
