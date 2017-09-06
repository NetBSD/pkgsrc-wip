$NetBSD$

NstDatabase.xml is installed globally for pkgsrc users rather than
making them install it manually in their home dir. There's no reason
to be editing it.

--- libretro/libretro.cpp.orig	2017-09-03 20:32:25.000000000 +0000
+++ libretro/libretro.cpp
@@ -17,7 +17,7 @@
 #include "../source/core/api/NstApiUser.hpp"
 #include "../source/core/api/NstApiFds.hpp"
 
-#define NST_VERSION "1.48-WIP"
+#define NST_VERSION "1.48"
 
 #ifdef _WIN32
 #define snprintf _snprintf
@@ -308,11 +308,7 @@ void retro_get_system_info(struct retro_
 {
    memset(info, 0, sizeof(*info));
    info->library_name     = "Nestopia";
-#ifdef GIT_VERSION
-   info->library_version  = NST_VERSION GIT_VERSION;
-#else
    info->library_version  = NST_VERSION;
-#endif
    info->need_fullpath    = false;
    info->valid_extensions = "nes|fds|unf|unif";
 }
@@ -957,7 +953,7 @@ bool retro_load_game(const struct retro_
    }
    delete custompalette;
    
-   snprintf(db_path, sizeof(db_path), "%s%cNstDatabase.xml", dir, slash);
+   snprintf(db_path, sizeof(db_path), "%s/share/libretro/nestopia/NstDatabase.xml", PREFIX);
 
    if (log_cb)
       log_cb(RETRO_LOG_INFO, "NstDatabase.xml path: %s\n", db_path);
