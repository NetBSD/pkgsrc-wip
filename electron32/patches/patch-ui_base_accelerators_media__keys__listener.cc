$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/accelerators/media_keys_listener.cc.orig	2024-10-18 12:35:12.344421900 +0000
+++ ui/base/accelerators/media_keys_listener.cc
@@ -13,7 +13,8 @@ MediaKeysListener::~MediaKeysListener() 
 // static
 bool MediaKeysListener::IsMediaKeycode(KeyboardCode key_code) {
   return key_code == VKEY_MEDIA_PLAY_PAUSE || key_code == VKEY_MEDIA_STOP ||
-         key_code == VKEY_MEDIA_PREV_TRACK || key_code == VKEY_MEDIA_NEXT_TRACK;
+         key_code == VKEY_MEDIA_PREV_TRACK || key_code == VKEY_MEDIA_NEXT_TRACK ||
+         key_code == VKEY_VOLUME_UP || key_code == VKEY_VOLUME_DOWN || key_code == VKEY_VOLUME_MUTE;
 }
 
 }  // namespace ui
