$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/corewm/tooltip_aura.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/corewm/tooltip_aura.cc
@@ -38,7 +38,7 @@ static constexpr int kTooltipMaxWidth = 
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
