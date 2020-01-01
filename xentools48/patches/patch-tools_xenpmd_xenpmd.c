$NetBSD$

char buffer too small

--- tools/xenpmd/xenpmd.c.orig	2018-12-03 18:03:57.000000000 +0900
+++ tools/xenpmd/xenpmd.c	2020-01-01 19:55:28.942003628 +0900
@@ -71,7 +71,7 @@
     unsigned long           capacity_granularity_2;
     char                    model_number[32];
     char                    serial_number[32];
-    char                    battery_type[32];
+    char                    battery_type[128];
     char                    oem_info[32];
 };
 
@@ -100,7 +100,7 @@
 {
     FILE *file = 0;
     struct dirent *dir_entries;
-    char file_name[32];
+    char file_name[540];
     
     do 
     {
@@ -110,10 +110,10 @@
         if ( strlen(dir_entries->d_name) < 4 )
             continue;
         if ( battery_info_type == BIF ) 
-            snprintf(file_name, 32, BATTERY_INFO_FILE_PATH,
+            snprintf(file_name, 540, BATTERY_INFO_FILE_PATH,
                      dir_entries->d_name);
         else 
-            snprintf(file_name, 32, BATTERY_STATE_FILE_PATH,
+            snprintf(file_name, 540, BATTERY_STATE_FILE_PATH,
                      dir_entries->d_name);
         file = fopen(file_name, "r");
     } while ( !file );
