$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/editing/commands/clipboard_commands.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/editing/commands/clipboard_commands.cc
@@ -121,7 +121,7 @@ bool ClipboardCommands::CanReadClipboard
     return true;
   }
   return frame.GetContentSettingsClient() &&
-         frame.GetContentSettingsClient()->AllowReadFromClipboard();
+         frame.GetContentSettingsClient()->AllowReadFromClipboardSync();
 }
 
 bool ClipboardCommands::CanWriteClipboard(LocalFrame& frame,
@@ -300,7 +300,7 @@ bool ClipboardCommands::PasteSupported(L
     return true;
   }
   return frame->GetContentSettingsClient() &&
-         frame->GetContentSettingsClient()->AllowReadFromClipboard();
+         frame->GetContentSettingsClient()->AllowReadFromClipboardSync();
 }
 
 bool ClipboardCommands::ExecuteCopy(LocalFrame& frame,
