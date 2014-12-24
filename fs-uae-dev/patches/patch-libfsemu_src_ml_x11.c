$NetBSD: patch-libfsemu_src_ml_x11.c,v 1.5 2014/12/24 20:17:47 rhialto Exp $

Don't map control and caps lock keys: the user might have them swapped.

--- libfsemu/src/ml/x11.c.orig	2014-09-23 10:39:54.000000000 +0000
+++ libfsemu/src/ml/x11.c
@@ -356,7 +356,7 @@ void fs_ml_initialize_keymap() {
     g_key_map[35] = FS_ML_KEY_RIGHTBRACKET;
     g_key_map[36] = FS_ML_KEY_RETURN;
 
-    g_key_map[66] = FS_ML_KEY_CAPSLOCK;
+    /*g_key_map[66] = FS_ML_KEY_CAPSLOCK;*/
     g_key_map[38] = FS_ML_KEY_A;
     g_key_map[39] = FS_ML_KEY_S;
     g_key_map[40] = FS_ML_KEY_D;
@@ -384,7 +384,7 @@ void fs_ml_initialize_keymap() {
     g_key_map[61] = FS_ML_KEY_SLASH;
     g_key_map[62] = FS_ML_KEY_RSHIFT;
 
-    g_key_map[37] = FS_ML_KEY_LCTRL;
+    /*g_key_map[37] = FS_ML_KEY_LCTRL;*/
     g_key_map[64] = FS_ML_KEY_LALT;
     g_key_map[65] = FS_ML_KEY_SPACE;
 
