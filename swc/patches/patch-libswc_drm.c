$NetBSD$

--- libswc/drm.c.orig	2019-07-11 06:33:41.000000000 +0000
+++ libswc/drm.c
@@ -196,7 +196,7 @@ find_available_crtc(drmModeRes *resource
 static bool
 find_available_id(uint32_t *id)
 {
-	int index = ffsl(~drm.taken_ids);
+	int index = __builtin_ffsl(~drm.taken_ids);
 
 	if (index == 0)
 		return false;
