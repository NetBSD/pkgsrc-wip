$NetBSD$

* No Flatpak support

--- src/xdp-app-info-flatpak.c.orig	2026-01-12 10:33:38.074348687 +0000
+++ src/xdp-app-info-flatpak.c
@@ -643,6 +643,10 @@ static int
 open_flatpak_info (int      pid,
                    GError **error)
 {
+  g_set_error (error, XDP_APP_INFO_ERROR, XDP_APP_INFO_ERROR_WRONG_APP_KIND,
+                           "Certainly not a flatpak");
+  return -1;
+#if 0
   g_autofree char *root_path = NULL;
   g_autofd int root_fd = -1;
   g_autofd int info_fd = -1;
@@ -695,6 +699,7 @@ open_flatpak_info (int      pid,
     }
 
   return g_steal_fd (&info_fd);
+#endif
 }
 
 gboolean
