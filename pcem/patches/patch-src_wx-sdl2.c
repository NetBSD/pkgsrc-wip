$NetBSD$

Assume non-Windows is unixy.

--- src/wx-sdl2.c.orig	2020-12-01 20:40:51.000000000 +0000
+++ src/wx-sdl2.c
@@ -238,7 +238,7 @@ int dir_exists(char* path)
 
 void get_pcem_path(char *s, int size)
 {
-#ifdef __linux
+#if !defined(__APPLE__) && !defined(__WINDOWS__)
         wx_get_home_directory(s);
         strcat(s, ".pcem/");
 #else
@@ -399,8 +399,6 @@ void wx_initmenu()
                         wx_appendmenu(cdrom_submenu, IDM_CDROM_REAL+c, s, wxITEM_RADIO);
                 }
         }
-#elif __linux__
-        wx_appendmenu(cdrom_submenu, IDM_CDROM_REAL+1, "Host CD/DVD Drive (/dev/cdrom)", wxITEM_RADIO);
 #elif __APPLE__
         int c;
         
@@ -421,6 +419,8 @@ void wx_initmenu()
                         wx_appendmenu(cdrom_submenu, IDM_CDROM_REAL+c, name, wxITEM_RADIO);
                 }
         }
+#else
+        wx_appendmenu(cdrom_submenu, IDM_CDROM_REAL+1, "Host CD/DVD Drive (/dev/cdrom)", wxITEM_RADIO);
 #endif
 }
 
@@ -511,7 +511,7 @@ int pc_main(int argc, char** argv)
 {
         paths_init();
 
-#ifdef __linux__
+#if !defined(__APPLE__) && !defined(__WINDOWS__)
         char s[1024];
         /* create directories if they don't exist */
         if (!wx_setup(pcem_path))
@@ -538,7 +538,8 @@ int pc_main(int argc, char** argv)
 
         sound_init();
 
-#ifdef __linux__
+#if !defined(__APPLE__) && !defined(__WINDOWS__)
+        char s[1024];
         /* check if cfg exists, and if not create it */
         append_filename(s, pcem_path, "pcem.cfg", 511);
         if (!wx_file_exists(s))
