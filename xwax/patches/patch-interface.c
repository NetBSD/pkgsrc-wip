$NetBSD$

Avoid broken locale code.

--- interface.c.orig	2018-01-19 20:40:49.000000000 +0000
+++ interface.c
@@ -139,13 +139,7 @@
 /* List of directories to use as search path for fonts. */
 
 static const char *font_dirs[] = {
-    "/usr/X11R6/lib/X11/fonts/TTF",
-    "/usr/share/fonts/truetype/ttf-dejavu/",
-    "/usr/share/fonts/ttf-dejavu",
-    "/usr/share/fonts/dejavu",
-    "/usr/share/fonts/TTF",
-    "/usr/share/fonts/truetype/dejavu",
-    "/usr/share/fonts/truetype/ttf-dejavu",
+    "@PREFIX@/share/fonts/X11/TTF",
     NULL
 };
 
@@ -413,27 +407,7 @@ static int do_draw_text(SDL_Surface *sf,
         src.h = 0;
 
     } else {
-        if (!locale) {
             rendered = TTF_RenderText_Shaded(font, buf, fg, bg);
-        } else {
-            char ubuf[256], /* fixed buffer is reasonable for rendering */
-                *in, *out;
-            size_t len, fill;
-
-            out = ubuf;
-            fill = sizeof(ubuf) - 1; /* always leave space for \0 */
-
-            if (iconv(utf, NULL, NULL, &out, &fill) == -1)
-                abort();
-
-            in = strdupa(buf);
-            len = strlen(in);
-
-            (void)iconv(utf, &in, &len, &out, &fill);
-            *out = '\0';
-
-            rendered = TTF_RenderUTF8_Shaded(font, ubuf, fg, bg);
-        }
 
         src.x = 0;
         src.y = 0;
@@ -1875,7 +1849,7 @@ int interface_start(struct library *lib,
     if (load_fonts() == -1)
         return -1;
 
-    utf = iconv_open("UTF8", "");
+    utf = iconv_open("utf8", "c99");
     if (utf == (iconv_t)-1) {
         perror("iconv_open");
         return -1;
