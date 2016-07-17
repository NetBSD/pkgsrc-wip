$NetBSD$

--- chrome/browser/ui/panels/panel_manager.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/browser/ui/panels/panel_manager.cc
@@ -143,7 +143,7 @@ bool PanelManager::ShouldUsePanels(const
 // static
 bool PanelManager::IsPanelStackingEnabled() {
   // Stacked panel mode is not supported in linux-aura.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   return false;
 #else
   return true;
