$NetBSD$

--- src/wayland-server.c.orig	2015-11-25 09:48:11.000000000 +0000
+++ src/wayland-server.c
@@ -88,6 +88,9 @@ struct wl_client {
 	struct wl_map objects;
 	struct wl_signal destroy_signal;
 #ifdef HAVE_SYS_UCRED_H
+#ifdef __NetBSD__
+# define xucred uucred
+#endif
 	/* FreeBSD */
 	struct xucred xucred;
 #else
