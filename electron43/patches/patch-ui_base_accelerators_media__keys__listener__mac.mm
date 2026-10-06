$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/accelerators/media_keys_listener_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/accelerators/media_keys_listener_mac.mm
@@ -32,6 +32,12 @@ KeyboardCode MediaKeyCodeToKeyboardCode(
     case NX_KEYTYPE_NEXT:
     case NX_KEYTYPE_FAST:
       return VKEY_MEDIA_NEXT_TRACK;
+    case NX_KEYTYPE_SOUND_UP:
+      return VKEY_VOLUME_UP;
+    case NX_KEYTYPE_SOUND_DOWN:
+      return VKEY_VOLUME_DOWN;
+    case NX_KEYTYPE_MUTE:
+      return VKEY_VOLUME_MUTE;
   }
   return VKEY_UNKNOWN;
 }
@@ -190,7 +196,10 @@ CGEventRef MediaKeysListenerImpl::EventT
   int key_code = (data1 & 0xFFFF0000) >> 16;
   if (key_code != NX_KEYTYPE_PLAY && key_code != NX_KEYTYPE_NEXT &&
       key_code != NX_KEYTYPE_PREVIOUS && key_code != NX_KEYTYPE_FAST &&
-      key_code != NX_KEYTYPE_REWIND) {
+      key_code != NX_KEYTYPE_REWIND &&
+      key_code != NX_KEYTYPE_SOUND_UP &&
+      key_code != NX_KEYTYPE_SOUND_DOWN &&
+      key_code != NX_KEYTYPE_MUTE) {
     return event;
   }
 
