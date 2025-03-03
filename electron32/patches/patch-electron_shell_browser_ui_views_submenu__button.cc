$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/ui/views/submenu_button.cc.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/ui/views/submenu_button.cc
@@ -22,7 +22,7 @@ SubmenuButton::SubmenuButton(PressedCall
                              const SkColor& background_color)
     : views::MenuButton(std::move(callback), gfx::RemoveAccelerator(title)),
       background_color_(background_color) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Dont' use native style border.
   SetBorder(CreateDefaultBorder());
 #endif
