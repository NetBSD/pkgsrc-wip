$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/glic/glic_status_icon.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ chrome/browser/background/glic/glic_status_icon.cc
@@ -83,7 +83,7 @@ GlicStatusIcon::GlicStatusIcon(GlicContr
   if (!status_icon_) {
     return;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   //  Set a vector icon for proper themeing on Linux.
   status_icon_->SetIcon(
       GlicVectorIconManager::GetVectorIcon(IDR_GLIC_BUTTON_VECTOR_ICON));
@@ -113,7 +113,7 @@ GlicStatusIcon::GlicStatusIcon(GlicContr
 GlicStatusIcon::~GlicStatusIcon() {
   context_menu_ = nullptr;
   if (status_icon_) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     status_icon_->RemoveObserver(this);
 #endif
     std::unique_ptr<StatusIcon> removed_icon =
@@ -201,7 +201,7 @@ std::unique_ptr<StatusIconMenuModel> Gli
   menu->AddItem(
       IDC_GLIC_STATUS_ICON_MENU_REMOVE_ICON,
       l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_REMOVE_ICON));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_EXIT,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_EXIT));
 #endif
