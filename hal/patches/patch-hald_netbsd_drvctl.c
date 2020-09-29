$NetBSD$

--- hald/netbsd/drvctl.c.orig	2020-09-28 21:35:53.183246491 +0000
+++ hald/netbsd/drvctl.c
@@ -25,6 +25,7 @@
 #include <sys/stat.h>
 #include <sys/drvctlio.h>
 #include <glib.h>
+#include <glib/gprintf.h>
 
 #include "../osspec.h"
 #include "../logger.h"
@@ -46,22 +47,19 @@ static void	drvctl_dev_branch(gchar *);
 static int drvctl_fd;
 static GIOChannel *drvctl_iochannel;
 
+#define	FIFODEV	"/tmp/halfifo"
 gboolean
 drvctl_init(void)
 {
-	drvctl_fd = open (DRVCTLDEV, O_RDWR);
-	if (drvctl_fd == -1) {
-		HAL_INFO (("open(%s, O_RDWR) failed: %s", DRVCTLDEV, strerror(errno)));
-		return FALSE;
-	}
+	GError           *rc=NULL;
 
-        drvctl_iochannel = g_io_channel_unix_new (drvctl_fd);
+	drvctl_fd = open (DRVCTLDEV, O_RDWR);
+        drvctl_iochannel = g_io_channel_new_file(FIFODEV,"r",&rc);
 	if (drvctl_iochannel == NULL) {
-                HAL_INFO (("g_io_channel_unix_new failed"));
+                HAL_INFO (("g_io_channel_new_file failed"));
 		return FALSE;
 	}
         g_io_add_watch (drvctl_iochannel, G_IO_IN, drvctl_iochannel_data, NULL);
-
 	return TRUE;
 }
 
@@ -76,37 +74,22 @@ drvctl_iochannel_data (GIOChannel *sourc
                     GIOCondition condition,
                     gpointer user_data)
 {
-	prop_dictionary_t ev;
-	const char *event, *device;
-	int res;
-
-	HAL_INFO (("drvctl_iochannel_data"));
-
-	res = prop_dictionary_recv_ioctl (drvctl_fd, DRVGETEVENT, &ev);
-	if (res) {
-		HAL_WARNING (("DRVGETEVENT failed: %s", strerror(errno)));
-		return FALSE;
-	}
-
-	if (!prop_dictionary_get_cstring_nocopy (ev, "event", &event)) {
-		HAL_WARNING (("DRVGETEVENT missing \"event\" parameter"));
-		goto done;
-	}
-	if (!prop_dictionary_get_cstring_nocopy (ev, "device", &device)) {
-		HAL_WARNING (("DRVGETEVENT missing \"device\" parameter"));
-		goto done;
-	}
-
-	HAL_INFO (("DRVGETEVENT event=%s device=%s", event, device));
-
-	if (strcmp (event, "device-attach") == 0) {
-		drvctl_dev_add (device);
-	} else {
-		drvctl_dev_remove (device);
-	}
-
-done:
-	prop_object_release(ev);
+	GError		*rc=NULL;
+	gint		i;
+	struct timeval	timeout={1,0};
+	gchar		**vect,*line;
+
+	g_io_channel_read_line(source,&line,NULL,NULL,&rc);
+	if (!line)
+		return TRUE;
+	g_strstrip(line);
+	vect=g_strsplit(line," ",3);
+	if (! strcmp (vect[0], "device-attach")) 
+		drvctl_dev_add (vect[1]);
+	else if (! strcmp (vect[0], "device-detach"))
+		drvctl_dev_remove (vect[1]);
+	g_strfreev(vect);
+	g_free(line);
 	return TRUE;
 }
 
@@ -179,6 +162,7 @@ drvctl_list(const gchar *name, struct de
 	}
 	if (children != laa->l_children)
 		HAL_WARNING (("DRVLISTDEV/3 expected %d children, got %d", children, laa->l_childname));
+	return 0;
 }
 
 gboolean
@@ -187,7 +171,7 @@ drvctl_find_device(const gchar *devnode,
 	prop_dictionary_t command_dict;
 	prop_dictionary_t args_dict;
 	prop_dictionary_t results_dict;
-	int err;
+	signed char err;
 	   
 	command_dict = prop_dictionary_create ();
 	args_dict = prop_dictionary_create ();
