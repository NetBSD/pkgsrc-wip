$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_menu_view_base.cc.orig	2025-01-27 17:37:37.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_menu_view_base.cc
@@ -698,7 +698,7 @@ void ProfileMenuViewBase::SetProfileIden
       image_model, management_badge, this,
       ProfileMenuViewBase::kIdentityImageSize, kIdentityImageBorder);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // crbug.com/1161166: Orca does not read the accessible window title of the
   // bubble, so we duplicate it in the top-level menu item. To be revisited
   // after considering other options, including fixes on the AT side.
