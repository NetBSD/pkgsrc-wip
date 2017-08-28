$NetBSD$

This file is installed globally for pkgsrc users rather than making
them install it manually in their home dir. There's no reason to be
editing it.

--- libretro/libretro.cpp.orig	2016-01-09 23:34:38.000000000 +0000
+++ libretro/libretro.cpp
@@ -720,7 +720,7 @@ bool retro_load_game(const struct retro_
    if (!environ_cb(RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY, &dir) || !dir)
       return false;
 
-   snprintf(db_path, sizeof(db_path), "%s%cNstDatabase.xml", dir, slash);
+   snprintf(db_path, sizeof(db_path), "%s/share/libretro/nestopia/NstDatabase.xml", PREFIX);
 
    if (log_cb)
       log_cb(RETRO_LOG_INFO, "NstDatabase.xml path: %s\n", db_path);
