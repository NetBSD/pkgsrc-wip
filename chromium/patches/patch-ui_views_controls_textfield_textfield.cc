$NetBSD: patch-ui_views_controls_textfield_textfield.cc,v 1.1 2025/02/06 09:58:35 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/controls/textfield/textfield.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/views/controls/textfield/textfield.cc
@@ -87,7 +87,7 @@
 #include "base/win/win_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
 #include "ui/linux/linux_ui.h"
@@ -185,7 +185,7 @@ bool IsControlKeyModifier(int flags) {
 // Control-modified key combination, but we cannot extend it to other platforms
 // as Control has different meanings and behaviors.
 // https://crrev.com/2580483002/#msg46
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return flags & ui::EF_CONTROL_DOWN;
 #else
   return false;
@@ -763,7 +763,7 @@ bool Textfield::OnKeyPressed(const ui::K
   if (!textfield)
     return handled;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   std::vector<ui::TextEditCommandAuraLinux> commands;
   if (!handled && linux_ui &&
@@ -946,7 +946,7 @@ void Textfield::AboutToRequestFocusFromT
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Skip any accelerator handling that conflicts with custom keybindings.
   auto* linux_ui = ui::LinuxUi::instance();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -1997,7 +1997,7 @@ bool Textfield::ShouldDoLearning() {
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/41452689): Implement this method to support Korean IME
 // reconversion feature on native text fields (e.g. find bar).
 bool Textfield::SetCompositionFromExistingText(
@@ -2503,14 +2503,14 @@ ui::TextEditCommand Textfield::GetComman
 #endif
         return ui::TextEditCommand::DELETE_BACKWARD;
       }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return ui::TextEditCommand::DELETE_TO_BEGINNING_OF_LINE;
 #endif
       return ui::TextEditCommand::DELETE_WORD_BACKWARD;
     case ui::VKEY_DELETE:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift && control)
         return ui::TextEditCommand::DELETE_TO_END_OF_LINE;
