$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/clipboard/clipboard_non_backed.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ ui/base/clipboard/clipboard_non_backed.cc
@@ -461,7 +461,7 @@ ClipboardNonBacked::ClipboardNonBacked()
   // so create internal clipboards for platform supported clipboard buffers.
   constexpr ClipboardBuffer kClipboardBuffers[] = {
     ClipboardBuffer::kCopyPaste,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     ClipboardBuffer::kSelection,
 #endif
 #if BUILDFLAG(IS_MAC)
