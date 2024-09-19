$NetBSD$

--- tools/hal-storage-mount.c.orig	2009-05-27 20:26:03.000000000 +0000
+++ tools/hal-storage-mount.c
@@ -31,7 +31,7 @@
 #include <string.h>
 #include <glib.h>
 #include <glib/gstdio.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 #include <fstab.h>
 #include <sys/param.h>
 #include <sys/ucred.h>
@@ -41,6 +41,14 @@
 #elif sun
 #include <sys/mnttab.h>
 #include <sys/vfstab.h>
+#elif __NetBSD__
+#include <fstab.h>
+#include <sys/param.h>
+#include <sys/mount.h>
+#include <fcntl.h>
+#include <sys/stat.h>
+#include <unistd.h>
+#include <pwd.h>
 #else
 #include <mntent.h>
 #endif
@@ -54,10 +62,14 @@
 
 #include "hal-storage-shared.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define MOUNT		"/sbin/mount"
 #define MOUNT_OPTIONS	"noexec,nosuid"
 #define MOUNT_TYPE_OPT	"-t"
+#elif __NetBSD__
+#define MOUNT		"/sbin/mount"
+#define MOUNT_OPTIONS	"noexec,nosuid,nodev"
+#define	MOUNT_TYPE_OPT	"-t"
 #elif sun
 #define MOUNT		"/sbin/mount"
 #define MOUNT_OPTIONS	"noexec,nosuid"
@@ -421,7 +433,7 @@ device_is_mounted (const char *device, c
 static const char *
 map_fstype (const char *fstype)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 	if (! strcmp (fstype, "iso9660"))
 		return "cd9660";
 	else if (! strcmp (fstype, "ext2"))
@@ -430,6 +442,13 @@ map_fstype (const char *fstype)
 		return "ext2fs";
 	else if (! strcmp (fstype, "vfat"))
 		return "msdosfs";
+#elif __NetBSD__
+	if (! strcmp (fstype, "iso9660"))
+		return "cd9660";
+	else if (! strcmp (fstype, "ext2"))
+		return "ext2fs";
+	else if (! strcmp (fstype, "vfat"))
+		return "msdos";
 #elif sun
 	if (! strcmp (fstype, "iso9660"))
 		return "hsfs";
@@ -471,11 +490,16 @@ handle_mount (LibHalContext *hal_ctx, 
 	gboolean explicit_mount_point_given;
 	gboolean found_alternative_fstype = FALSE;
 	const char *end;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 	struct passwd *pw;
 	uid_t calling_uid;
 	gid_t calling_gid;
 #endif
+	gboolean have_rump = FALSE;
+#ifdef __NetBSD__
+	char *rump_cmd;
+	struct stat st;
+#endif
 	const char *label;
 	const char *uuid;
 
@@ -646,8 +670,6 @@ handle_mount (LibHalContext *hal_ctx, 
 	/* construct arguments to mount */
 	na = 0;
 	
-	args[na++] = MOUNT;
-
 	if (strlen (mount_fstype) > 0) {
 		mount_do_fstype = (char *) map_fstype (mount_fstype);
 		if (volume && strcmp(mount_do_fstype, mount_fstype) == 0) {
@@ -797,8 +819,28 @@ handle_mount (LibHalContext *hal_ctx, 
 		}
 	}
 
-	args[na++] = MOUNT_TYPE_OPT;
-	args[na++] = mount_do_fstype;
+#ifdef __NetBSD__
+	rump_cmd = g_strdup_printf ("/usr/sbin/rump_%s", mount_do_fstype);
+	if (stat (rump_cmd, &st) == 0) {
+		int rump_fd = open ("/dev/puffs", O_RDONLY);
+		if (rump_fd >= 0) {
+			have_rump = TRUE;
+			close (rump_fd);
+		}
+	}
+
+	/* XXX rump_* option handling is different, disable for now */
+	have_rump = FALSE;
+
+	if (have_rump == TRUE)
+		args[na++] = rump_cmd;
+	else
+#endif
+	{
+		args[na++] = MOUNT;
+		args[na++] = MOUNT_TYPE_OPT;
+		args[na++] = mount_do_fstype;
+	}
 
 	args[na++] = "-o";
 #ifdef HAVE_UMOUNT_HAL
@@ -869,7 +911,7 @@ handle_mount (LibHalContext *hal_ctx, 
 			unknown_error ("Cannot create mount directory");
 		}
 		
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 		calling_uid = (uid_t) strtol (invoked_by_uid, (char **) NULL, 10);
 		pw = getpwuid (calling_uid);
 		if (pw != NULL) {
