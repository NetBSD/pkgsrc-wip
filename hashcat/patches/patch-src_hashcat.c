$NetBSD$

Use standard paths for all platforms.

--- src/hashcat.c.orig	2016-07-31 12:49:32.000000000 +0000
+++ src/hashcat.c
@@ -6134,7 +6134,7 @@ int main (int argc, char **argv)
 
   char *exec_path = get_exec_path ();
 
-  #ifdef LINUX
+  #if 1
 
   char *resolved_install_folder = realpath (INSTALL_FOLDER, NULL);
   char *resolved_exec_path      = realpath (exec_path, NULL);
