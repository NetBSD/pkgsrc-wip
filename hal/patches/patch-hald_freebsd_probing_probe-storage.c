$NetBSD$

--- hald/freebsd/probing/probe-storage.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/probing/probe-storage.c
@@ -32,7 +32,11 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
+#ifdef __DragonFly__
+#include <sys/diskslice.h>
+#else
 #include <sys/disk.h>
+#endif
 #include <netinet/in.h>
 #include <glib.h>
 #include <libvolume_id.h>
@@ -171,6 +175,9 @@ int
 main (int argc, char **argv)
 {
   char *device_file;
+#ifdef __DragonFly__
+  struct partinfo device_info;
+#endif
   char *drive_type;
   char *parent;
   int ret = 0;			/* no media/filesystem */
@@ -221,10 +228,17 @@ main (int argc, char **argv)
 	  fd = open(device_file, O_RDONLY | O_NONBLOCK);
 	  if (fd > -1)
             {
+#ifdef __DragonFly__
+              if (ioctl (fd, DIOCGPART, &device_info) == 0)
+                {
+                  libhal_device_set_property_uint64(hfp_ctx, hfp_udi, "storage.removable.media_size", device_info.media_size, &hfp_error);
+                }
+#else
               if (ioctl (fd, DIOCGMEDIASIZE, &size) == 0)
                 {
                   libhal_device_set_property_uint64(hfp_ctx, hfp_udi, "storage.removable.media_size", size, &hfp_error);
 		}
+#endif
 	      close(fd);
 	    }
 	  ret = 2;		/* has media */
