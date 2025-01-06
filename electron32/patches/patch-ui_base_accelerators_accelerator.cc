$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/accelerators/accelerator.cc.orig	2024-10-18 12:35:12.344421900 +0000
+++ ui/base/accelerators/accelerator.cc
@@ -12,6 +12,7 @@
 #include "base/i18n/rtl.h"
 #include "base/notreached.h"
 #include "base/strings/string_util.h"
+#include "base/strings/stringprintf.h"
 #include "base/strings/utf_string_conversions.h"
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
@@ -184,6 +185,11 @@ std::u16string Accelerator::GetShortcutT
 #endif
 
   if (shortcut.empty()) {
+    // When a shifted char is explicitly specified, for example Ctrl+Plus,
+    // use the shifted char directly.
+    if (shifted_char) {
+      shortcut += *shifted_char;
+    } else {
 #if BUILDFLAG(IS_WIN)
     // Our fallback is to try translate the key code to a regular character
     // unless it is one of digits (VK_0 to VK_9). Some keyboard
@@ -207,6 +213,10 @@ std::u16string Accelerator::GetShortcutT
       shortcut +=
           static_cast<std::u16string::value_type>(base::ToUpperASCII(c));
 #endif
+    }
+    if (key_code_ > VKEY_F1 && key_code_ <= VKEY_F24)
+      shortcut = base::UTF8ToUTF16(
+          base::StringPrintf("F%d", key_code_ - VKEY_F1 + 1));
   }
 
 #if BUILDFLAG(IS_MAC)
@@ -391,7 +401,7 @@ std::u16string Accelerator::ApplyLongFor
     const std::u16string& shortcut) const {
   std::u16string result = shortcut;
 
-  if (IsShiftDown())
+  if (!shifted_char && IsShiftDown())
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SHIFT_KEY);
 
   // Note that we use 'else-if' in order to avoid using Ctrl+Alt as a shortcut.
@@ -399,7 +409,7 @@ std::u16string Accelerator::ApplyLongFor
   // more information.
   if (IsCtrlDown())
     result = ApplyModifierToAcceleratorString(result, IDS_APP_CTRL_KEY);
-  else if (IsAltDown())
+  if (IsAltDown())
     result = ApplyModifierToAcceleratorString(result, IDS_APP_ALT_KEY);
 
   if (IsCmdDown()) {
@@ -409,6 +419,8 @@ std::u16string Accelerator::ApplyLongFor
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SEARCH_KEY);
 #elif BUILDFLAG(IS_WIN)
     result = ApplyModifierToAcceleratorString(result, IDS_APP_WINDOWS_KEY);
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+    result = ApplyModifierToAcceleratorString(result, IDS_APP_SUPER_KEY);
 #else
     NOTREACHED_IN_MIGRATION();
 #endif
