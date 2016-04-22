$NetBSD$

Use installed data path.

--- options.c.orig	2016-01-02 13:32:48.000000000 +0000
+++ options.c
@@ -285,7 +285,7 @@ static int ini_callback(const char *sect
 
 void load_options() {
     use_default_options();
-    ini_load("SDLPoP.ini", ini_callback);
+    ini_load(PKGSRC_DATA_PATH "SDLPoP.ini", ini_callback);
     if (!options.use_fixes_and_enhancements) disable_fixes_and_enhancements();
 }
 
