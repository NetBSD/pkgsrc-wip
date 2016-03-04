$NetBSD$

rpmatch is only in glibc.

--- gnome-session/main.c.orig	2015-02-17 19:53:01.000000000 +0000
+++ gnome-session/main.c
@@ -260,7 +260,7 @@ main (int argc, char **argv)
 
         debug_string = g_getenv ("GNOME_SESSION_DEBUG");
         if (debug_string != NULL) {
-                debug = rpmatch (debug_string) == TRUE || atoi (debug_string) == 1;
+                debug = atoi (debug_string) == 1;
         }
 
         error = NULL;
