$NetBSD$

--- daemon/control/gkd-control-server.c.orig	2015-06-29 15:24:02.000000000 +0000
+++ daemon/control/gkd-control-server.c
@@ -431,11 +431,6 @@ gkd_control_listen (void)
 		return FALSE;
 	}
 
-	if (egg_unix_credentials_setup (sock) < 0) {
-		close (sock);
-		return FALSE;
-	}
-
 	channel = g_io_channel_unix_new (sock);
 	g_io_add_watch (channel, G_IO_IN | G_IO_HUP, control_accept, NULL);
 	g_io_channel_set_close_on_unref (channel, TRUE);
