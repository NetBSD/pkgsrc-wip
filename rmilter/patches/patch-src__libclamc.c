$NetBSD$

Fix for platform without sendfile

--- src/libclamc.c.orig	2016-06-20 10:08:56.000000000 +0000
+++ src/libclamc.c
@@ -147,6 +147,9 @@ static int clamscan_socket(const char *f
 		return -1;
 	}
 #else
+#warning There is no sendfile code for this platform
+#endif
+#else
 	while ((r = read (fd, buf, sizeof(buf))) > 0) {
 		if (write (s, buf, r) <= 0) {
 			msg_warn("<%s>; clamav: write (%s): %s", priv->mlfi_id,
@@ -156,8 +159,7 @@ static int clamscan_socket(const char *f
 			return -1;
 		}
 	}
-#endif
-#endif
+#endif /* HAVE_SENDFILE */
 	close (fd);
 
 	/* Send zero chunk */
