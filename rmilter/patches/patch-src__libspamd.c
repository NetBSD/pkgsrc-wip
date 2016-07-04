$NetBSD$

Fix for platform without sendfile

--- src/libspamd.c.orig	2016-06-20 10:08:56.000000000 +0000
+++ src/libspamd.c
@@ -357,11 +357,13 @@ rspamdscan_socket(SMFICTX *ctx, struct m
 		return -1;
 	}
 #else
+#warning There is sendfile code for this platform
+#endif
+#else
 	while ((r = read (fd, buf, sizeof (buf))) > 0) {
 		write (s, buf, r);
 	}
-#endif
-#endif
+#endif /* HAVE_SENDFILE */
 
 	fcntl (s, F_SETFL, ofl|O_NONBLOCK);
 	close (fd);
