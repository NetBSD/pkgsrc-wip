$NetBSD$

Disable tests that rely on uselocale()

--- tests/wallclock-reftest.c.orig	2020-04-29 01:53:29.099934300 +0000
+++ tests/wallclock-reftest.c
@@ -433,6 +433,7 @@ static void
 test_ui_file (GFile         *file,
               gconstpointer  user_data)
 {
+#if !defined(__NetBSD__)
   char *ui_file, *reference_file, *locale;
   cairo_surface_t *ui_image, *reference_image, *diff_image;
   GtkStyleProvider *provider;
@@ -494,6 +495,7 @@ test_ui_file (GFile         *file,
     }
 
   remove_extra_css (provider);
+#endif
 }
 
 static int
@@ -612,3 +614,4 @@ main (int argc, char **argv)
 
   return g_test_run ();
 }
+
