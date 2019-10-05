$NetBSD$

Avoid strdupa.

--- interface.c.orig	2018-01-19 20:40:49.000000000 +0000
+++ interface.c
@@ -426,10 +426,9 @@ static int do_draw_text(SDL_Surface *sf,
             if (iconv(utf, NULL, NULL, &out, &fill) == -1)
                 abort();
 
-            in = strdupa(buf);
             len = strlen(in);
 
-            (void)iconv(utf, &in, &len, &out, &fill);
+            (void)iconv(utf, &buf, &len, &out, &fill);
             *out = '\0';
 
             rendered = TTF_RenderUTF8_Shaded(font, ubuf, fg, bg);
@@ -1875,7 +1874,7 @@ int interface_start(struct library *lib,
     if (load_fonts() == -1)
         return -1;
 
-    utf = iconv_open("UTF8", "");
+    utf = iconv_open("utf8", "c99");
     if (utf == (iconv_t)-1) {
         perror("iconv_open");
         return -1;
