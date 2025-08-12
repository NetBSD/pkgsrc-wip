$NetBSD$

--- src/modules/module-protocol-pulse/utils.c.orig	2024-09-27 10:02:20.000000000 +0000
+++ src/modules/module-protocol-pulse/utils.c
@@ -21,6 +21,10 @@
 #ifdef HAVE_PWD_H
 #include <pwd.h>
 #endif
+#if defined(__NetBSD__)
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
 
 #include <spa/utils/result.h>
 #include <pipewire/context.h>
@@ -92,9 +96,11 @@ int check_flatpak(struct client *client,
 			 * filesystem, such as in a toolbox container. We will never have a fuse rootfs
 			 * in the flatpak case, so in that case its safe to ignore this and
 			 * continue to detect other types of apps. */
+#if !defined(__NetBSD__)
 			if (statfs(root_path, &buf) == 0 &&
 			    buf.f_type == 0x65735546) /* FUSE_SUPER_MAGIC */
 				return 0;
+#endif
 		}
 		/* Not able to open the root dir shouldn't happen. Probably the app died and
 		 * we're failing due to /proc/$pid not existing. In that case fail instead
