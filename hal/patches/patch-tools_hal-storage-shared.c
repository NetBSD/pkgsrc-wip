$NetBSD$

--- tools/hal-storage-shared.c.orig	2008-08-10 13:50:10.000000000 +0000
+++ tools/hal-storage-shared.c
@@ -31,7 +31,7 @@
 #include <string.h>
 #include <glib.h>
 #include <glib/gstdio.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 #include <fstab.h>
 #include <sys/param.h>
 #include <sys/ucred.h>
@@ -42,6 +42,10 @@
 #include <fcntl.h>
 #include <sys/mnttab.h>
 #include <sys/vfstab.h>
+#elif __NetBSD__
+#include <fstab.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #else
 #include <mntent.h>
 #endif
@@ -53,20 +57,27 @@
 
 #include "hal-storage-shared.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 struct mtab_handle
 {
   struct statfs	*mounts;
   int		n_mounts;
   int		iter;
 };
+#elif __NetBSD__
+struct mtab_handle
+{
+  struct statvfs *mounts;
+  int		n_mounts;
+  int		iter;
+};
 #endif
 
 
 gboolean
 mtab_open (gpointer *handle)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 	struct mtab_handle *mtab;
 
 	mtab = g_new0 (struct mtab_handle, 1);
@@ -90,7 +101,7 @@ mtab_open (gpointer *handle)
 char *
 mtab_next (gpointer handle, char **mount_point)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 	struct mtab_handle *mtab = handle;
 
 	if (mtab->iter < mtab->n_mounts) {
@@ -131,7 +142,7 @@ mtab_next (gpointer handle, char **mount
 void
 mtab_close (gpointer handle)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 	g_free (handle);
 #else
 	fclose (handle);
@@ -143,7 +154,7 @@ mtab_close (gpointer handle)
 gboolean
 fstab_open (gpointer *handle)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 	return setfsent () == 1;
 #elif sun
 	*handle = fopen (VFSTAB, "r");
@@ -157,7 +168,7 @@ fstab_open (gpointer *handle)
 char *
 fstab_next (gpointer handle, char **mount_point)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 	struct fstab *fstab;
 
 	fstab = getfsent ();
@@ -188,14 +199,16 @@ fstab_next (gpointer handle, char **moun
 void
 fstab_close (gpointer handle)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 	endfsent ();
 #else
 	fclose (handle);
 #endif
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define UMOUNT		"/sbin/umount"
+#elif __NetBSD__
 #define UMOUNT		"/sbin/umount"
 #elif sun
 #define UMOUNT		"/sbin/umount"
@@ -467,7 +480,7 @@ line_found:
 	/* construct arguments to /bin/umount */
 	na = 0;
 	args[na++] = UMOUNT;
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 	if (option_lazy)
 		args[na++] = "-l";
 #endif
@@ -625,13 +638,18 @@ try_open_excl_again:
 	/* construct arguments to EJECT_PROGRAM (e.g. /usr/bin/eject) */
 	na = 0;
 	args[na++] = EJECT_PROGRAM;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 	args[na++] = "-f";
 	args[na++] = (char *) device;
 	if (closetray)
 		args[na++] = "close";
 	else
 		args[na++] = "eject";
+#elif __NetBSD__
+	args[na++] = "-f";
+	if (closetray)
+		args[na++] = "-l";
+	args[na++] = (char *) device;
 #else
 	if (closetray) {
 		args[na++] = "-t";
