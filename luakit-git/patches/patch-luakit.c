$NetBSD$

luakit is used to generate the API documentation, so allow
it to run without GTK when DISPLAY is not set.

--- luakit.c.orig	2017-06-05 03:20:23.000000000 +0000
+++ luakit.c
@@ -171,13 +171,20 @@ glib_log_writer(GLogLevelFlags log_level
 gint
 main(gint argc, gchar *argv[])
 {
+    char *display = NULL;
     gboolean *nonblock = NULL;
+    gboolean havedisplay = TRUE;
 
     globalconf.starttime = l_time();
 
+    display = getenv("DISPLAY");
+    if (display == NULL || strcmp(display, "") == 0)
+        havedisplay = FALSE;
+
     /* set numeric locale to C (required for compatibility with
        LuaJIT and luakit scripts) */
-    gtk_disable_setlocale();
+    if (havedisplay)
+        gtk_disable_setlocale();
     setlocale(LC_ALL, "");
     setlocale(LC_NUMERIC, "C");
 
@@ -205,7 +212,8 @@ main(gint argc, gchar *argv[])
         }
     }
 
-    gtk_init(&argc, &argv);
+    if (havedisplay)
+        gtk_init(&argc, &argv);
 
 #if __GLIBC__ == 2 && __GLIBC_MINOR__ >= 50
     g_log_set_writer_func(glib_log_writer, NULL, NULL);
@@ -222,7 +230,8 @@ main(gint argc, gchar *argv[])
     if (!globalconf.windows->len)
         fatal("no windows spawned by rc file, exiting");
 
-    gtk_main();
+    if (havedisplay)
+        gtk_main();
     return EXIT_SUCCESS;
 }
 
