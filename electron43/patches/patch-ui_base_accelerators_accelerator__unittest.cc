$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/accelerators/accelerator_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/accelerators/accelerator_unittest.cc
@@ -58,7 +58,7 @@ TEST(AcceleratorTest, MAYBE_GetShortcutT
 #if BUILDFLAG(IS_MAC)
       {VKEY_T, EF_COMMAND_DOWN | EF_CONTROL_DOWN, nullptr, u"⌃⌘T"},
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {VKEY_T, EF_COMMAND_DOWN | EF_CONTROL_DOWN, u"Super+Ctrl+T", nullptr},
 #endif
   };
