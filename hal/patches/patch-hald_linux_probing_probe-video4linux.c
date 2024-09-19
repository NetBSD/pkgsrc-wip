$NetBSD$

--- hald/linux/probing/probe-video4linux.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/probing/probe-video4linux.c
@@ -30,7 +30,9 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/ioctl.h>
+#ifdef HAVE_LINUX_VIDEODEV_H
 #include <linux/videodev.h>
+#endif
 #include <linux/videodev2.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -50,7 +52,9 @@ main (int argc, char *argv[])
 	int ret = -1;
 	char *udi;
 	char *device_file;
+#ifdef HAVE_LINUX_VIDEODEV_H
 	struct video_capability v1cap;
+#endif
 	struct v4l2_capability v2cap;
 	LibHalContext *ctx = NULL;
 	LibHalChangeSet *cset;
@@ -106,7 +110,9 @@ main (int argc, char *argv[])
 			LIBHAL_FREE_DBUS_ERROR (&error);
 			libhal_device_add_capability (ctx, udi, "video4linux.radio", &error);
 		}
-	} else {
+	}
+#ifdef HAVE_LINUX_VIDEODEV_H
+	else {
 		HAL_DEBUG (("ioctl VIDIOC_QUERYCAP failed"));
 
 		if (ioctl (fd, VIDIOCGCAP, &v1cap) == 0) {
@@ -133,6 +139,7 @@ main (int argc, char *argv[])
 			HAL_DEBUG (("ioctl VIDIOCGCAP failed"));
 		}
 	}
+#endif
 
 	LIBHAL_FREE_DBUS_ERROR (&error);
 	libhal_device_commit_changeset (ctx, cset, &error);
