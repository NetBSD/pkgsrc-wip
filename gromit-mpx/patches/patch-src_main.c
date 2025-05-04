$NetBSD$

Disable appindicator3 support to avoid dbus dependency.

From OpenBSD ports.

--- src/main.c.orig	2024-09-09 18:39:05.000000000 +0000
+++ src/main.c
@@ -864,15 +864,6 @@ void setup_main_app (GromitData *data, i
   if (activate)
     acquire_grab (data, NULL); /* grab all */
 
-  /*
-     TRAY ICON
-  */
-  data->trayicon = app_indicator_new (PACKAGE_NAME,
-				      "net.christianbeier.Gromit-MPX",
-				      APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
-
-  app_indicator_set_status (data->trayicon, APP_INDICATOR_STATUS_ACTIVE);
-
 
 
   /* create the menu */
@@ -1019,7 +1010,6 @@ void setup_main_app (GromitData *data, i
   gtk_widget_show (quit_item);
 
 
-  app_indicator_set_menu (data->trayicon, GTK_MENU(menu));
 
   /*
     Build the support menu
@@ -1267,8 +1257,4 @@ int main (int argc, char **argv)
 
 void indicate_active(GromitData *data, gboolean YESNO)
 {
-    if(YESNO)
-	app_indicator_set_icon(data->trayicon, "net.christianbeier.Gromit-MPX.active");
-    else
-	app_indicator_set_icon(data->trayicon, "net.christianbeier.Gromit-MPX");
 }
