$NetBSD$

Permit to disable appindicator3 support to avoid dbus dependency.
Inspired by OpenBSD ports.

--- src/main.c.orig	2024-09-09 18:39:05.000000000 +0000
+++ src/main.c
@@ -864,6 +864,7 @@ void setup_main_app (GromitData *data, i
   if (activate)
     acquire_grab (data, NULL); /* grab all */
 
+#ifdef ENABLE_APPINDICATOR
   /*
      TRAY ICON
   */
@@ -872,6 +873,7 @@ void setup_main_app (GromitData *data, i
 				      APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
 
   app_indicator_set_status (data->trayicon, APP_INDICATOR_STATUS_ACTIVE);
+#endif
 
 
 
@@ -1019,7 +1021,9 @@ void setup_main_app (GromitData *data, i
   gtk_widget_show (quit_item);
 
 
+#ifdef ENABLE_APPINDICATOR
   app_indicator_set_menu (data->trayicon, GTK_MENU(menu));
+#endif
 
   /*
     Build the support menu
@@ -1267,8 +1271,10 @@ int main (int argc, char **argv)
 
 void indicate_active(GromitData *data, gboolean YESNO)
 {
+#ifdef ENABLE_APPINDICATOR
     if(YESNO)
 	app_indicator_set_icon(data->trayicon, "net.christianbeier.Gromit-MPX.active");
     else
 	app_indicator_set_icon(data->trayicon, "net.christianbeier.Gromit-MPX");
+#endif
 }
