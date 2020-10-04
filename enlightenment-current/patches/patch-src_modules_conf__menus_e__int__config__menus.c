$NetBSD$

* NetBSD support

--- src/modules/conf_menus/e_int_config_menus.c.orig	2020-07-26 16:39:12.093981000 +0000
+++ src/modules/conf_menus/e_int_config_menus.c
@@ -110,6 +110,7 @@ get_menus(Eina_List **menus)
         "/etc/xdg",
         "/usr/etc/xdg",
         "/usr/local/etc/xdg",
+        "@PREFIX@/etc/xdg",
         "/usr/opt/etc/xdg",
         "/usr/opt/xdg",
         "/usr/local/opt/etc/xdg",
