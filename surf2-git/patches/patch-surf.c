$NetBSD$

Revert the kbd patch to support older gtk3.

--- surf.c.orig	2016-09-12 08:04:23.000000000 +0000
+++ surf.c
@@ -174,6 +174,7 @@ static void destroyclient(Client *c);
 static void cleanup(void);
 
 /* GTK/WebKit */
+static GdkDevice *getkbdevice(void);
 static WebKitWebView *newview(Client *c, WebKitWebView *rv);
 static GtkWidget *createview(WebKitWebView *v, WebKitNavigationAction *a,
                              Client *c);
@@ -287,7 +288,7 @@ setup(void)
 	scriptfile = buildfile(scriptfile);
 	cachedir   = buildpath(cachedir);
 
-	gdkkb = gdk_seat_get_keyboard(gdk_display_get_default_seat(gdpy));
+	gdkkb = getkbdevice();
 
 	if (!stylefile) {
 		styledir = buildpath(styledir);
@@ -902,6 +903,22 @@ cleanup(void)
 	g_free(cachedir);
 }
 
+static GdkDevice *
+getkbdevice(void)
+{
+	GList *l, *gdl = gdk_device_manager_list_devices(
+	           gdk_display_get_device_manager(gdk_display_get_default()),
+		   GDK_DEVICE_TYPE_MASTER);
+	GdkDevice *gd = NULL;
+
+	for (l = gdl; l != NULL; l = l->next)
+		if (gdk_device_get_source(l->data) == GDK_SOURCE_KEYBOARD)
+			gd = l->data;
+
+	g_list_free(gdl);
+	return gd;
+}
+
 WebKitWebView *
 newview(Client *c, WebKitWebView *rv)
 {
