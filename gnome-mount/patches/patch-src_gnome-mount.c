$NetBSD$

--- src/gnome-mount.c.orig	2008-04-16 23:41:32.000000000 +0000
+++ src/gnome-mount.c
@@ -30,6 +30,7 @@
 #include <fcntl.h>
 #include <string.h>
 #include <stdlib.h>
+#include <locale.h>
 
 #include <dbus/dbus.h>
 #include <dbus/dbus-glib-lowlevel.h>
@@ -39,6 +40,7 @@
 #include <glib/gi18n.h>
 #include <gconf/gconf-client.h>
 #include <gdk/gdkx.h>
+#include <gtk/gtk.h>
 #include "copy-paste/gnome-password-dialog.h"
 #include <gnome-keyring.h>
 #include <libnotify/notify.h>
@@ -51,9 +53,9 @@
 #define NOTIFY_EXPIRES_DEFAULT -1
 #endif
 
-#if !defined(sun) && !defined(__FreeBSD__)
+#if !defined(sun) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 #include <mntent.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <fstab.h>
 #include <sys/param.h>
 #include <sys/ucred.h>
@@ -677,15 +679,19 @@ static char *
 get_mntent_mount_point(const char *device_file)
 {
 	char *mount_point;
-#if! defined(sun) && !defined(__FreeBSD__)
+#if! defined(sun) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 	FILE *f;
 	struct mntent mnt;
 	struct mntent *mnte;
 	char buf[512];
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 	struct statfs *mounts;
 	int n_mounts;
 	int i;
+#elif defined(__NetBSD__)
+	struct statvfs *mounts;
+	int n_mounts;
+	int i;
 #elif defined(sun)
 	FILE *f;
 	struct mnttab mnt;
@@ -694,7 +700,7 @@ get_mntent_mount_point(const char *devic
 
 	mount_point = NULL;
 
-#if !defined(sun) && !defined(__FreeBSD__)
+#if !defined(sun) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 	if ((f = setmntent ("/proc/mounts", "r")) != NULL) {
 		
 		while ((mnte = getmntent_r (f, &mnt, buf, sizeof(buf))) != NULL) {
@@ -717,13 +723,13 @@ get_mntent_mount_point(const char *devic
 		}
 		fclose(f);
 	}
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	n_mounts = getmntinfo(&mounts, MNT_NOWAIT);
 	for (i = 0; i < n_mounts; i++) {
 		if (!strcmp(mounts[i].f_mntfromname, device_file))
 			mount_point = g_strdup (mounts[i].f_mntonname);
 	}
-#endif /* sun && __FreeBSD__ */
+#endif /* sun && __FreeBSD__ && __NetBSD__ && __DragonFly__ */
 
 out:
 	return (mount_point);
@@ -862,7 +868,7 @@ out:
 static gboolean
 fstab_open (gpointer *handle)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	return setfsent () == 1;
 #else
 	*handle = fopen ("/etc/fstab", "r");
@@ -873,7 +879,7 @@ fstab_open (gpointer *handle)
 static char *
 fstab_next (gpointer handle, char **mount_point)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	struct fstab *fstab;
 
 	fstab = getfsent ();
@@ -901,7 +907,7 @@ fstab_next (gpointer handle, char **moun
 static void
 fstab_close (gpointer handle)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	endfsent ();
 #else
 	fclose (handle);
@@ -1116,7 +1122,7 @@ out:
 	return ret;
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #define MOUNT		"/sbin/mount"
 #define UMOUNT		"/sbin/umount"
 #else
@@ -1451,7 +1457,7 @@ volume_mount (const char *udi, LibHalVol
 	if (volume == NULL && (mount_options->len == 0)) {
 		/* volume from a non-pollable drive, just set uid.. */
 		
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 		snprintf (uidbuf, sizeof (uidbuf) - 1, "uid=%u", getuid ());
 #else
 		snprintf (uidbuf, sizeof (uidbuf) - 1, "-u=%u", getuid ());
@@ -1482,7 +1488,7 @@ volume_mount (const char *udi, LibHalVol
 				g_debug ("read default option '%s' from gconf strlist key %s", option, key);
 
 				/* special workaround to replace "uid=" with "uid=<actual uid of caller>" */
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 				if (strcmp (option, "uid=") == 0) {
 					g_free (option);
 					option = g_strdup_printf ("uid=%u", getuid ());
@@ -1577,8 +1583,7 @@ unmount_cache_timeout_func (gpointer dat
 		message = g_strdup_printf (_("There is data that needs to be written to the device %s before it can be removed. Please do not remove the media or disconnect the drive."), unmount_note_drive_name);
 		unmount_note = notify_notification_new (summary,
 							message,
-							"gnome-dev-harddisk", /* TODO: use appropriate icon */
-							NULL);
+							"gnome-dev-harddisk");
 		if (unmount_note == NULL) {
 			g_warning ("Cannot create note for unmount cache sync");
 		} else {
