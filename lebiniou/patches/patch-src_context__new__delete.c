$NetBSD$

Will be fixed in 3.67.0.

--- src/context_new_delete.c.orig	2022-03-19 23:06:55.000000000 +0000
+++ src/context_new_delete.c
@@ -58,7 +58,7 @@ Context_open_webcam(Context_t *ctx)
 
   /* remove trailing digits to get the first cam: "/dev/video12" => video_base= "/dev/video", first_cam= 12 */
   char *last_char = &video_base[base_len-1];
-  while ((base_len > 1) && isdigit(*last_char)) {
+  while ((base_len > 1) && isdigit((int)*last_char)) {
     last_char--;
     base_len--;
   }
