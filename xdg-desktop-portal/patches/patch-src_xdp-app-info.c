$NetBSD$

* Fix build without O_PATH

--- src/xdp-app-info.c.orig	2026-01-12 10:29:35.457923446 +0000
+++ src/xdp-app-info.c
@@ -585,6 +585,7 @@ xdp_app_info_get_path_for_fd (XdpAppInfo
   if (path == NULL)
     return NULL;
 
+#ifdef O_PATH
   if ((fd_flags & O_PATH) == O_PATH)
     {
       int read_access_mode;
@@ -634,6 +635,7 @@ xdp_app_info_get_path_for_fd (XdpAppInfo
         writable = TRUE;
     }
   else /* Regular file with no O_PATH */
+#endif
     {
       int accmode = fd_flags & O_ACCMODE;
 
