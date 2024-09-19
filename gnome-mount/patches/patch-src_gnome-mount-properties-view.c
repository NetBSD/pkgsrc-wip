$NetBSD$

--- src/gnome-mount-properties-view.c.orig	2008-02-25 21:55:05.000000000 +0000
+++ src/gnome-mount-properties-view.c
@@ -35,7 +35,7 @@
 #include <string.h>
 #include <gconf/gconf-client.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <fstab.h>
 #include <sys/param.h>
 #include <sys/ucred.h>
@@ -59,7 +59,31 @@ struct _GnomeMountPropertiesViewClass {
 	GtkVBoxClass base_class;
 };
 
-#ifdef __FreeBSD__
+#ifdef __NetBSD__
+static struct opt {
+	int o_opt;
+	const char *o_name;
+} optnames[] = {
+	{ MNT_ASYNC,		"async" },
+	{ MNT_NOCOREDUMP,	"nocoredump" },
+	{ MNT_NODEV,		"nodev" },
+	{ MNT_NODEVMTIME,	"nodevmtime" },
+	{ MNT_NOEXEC,		"noexec" },
+	{ MNT_NOSUID,		"nosuid" },
+	{ MNT_RDONLY,		"rdonly" },
+	{ MNT_SYNCHRONOUS,	"sync" },
+	{ MNT_UNION,		"union" },
+	{ MNT_NOATIME,		"noatime" },
+	{ MNT_SYMPERM,		"symperm" },
+	{ MNT_SOFTDEP,		"softdep" },
+#ifdef MNT_LOG
+	{ MNT_LOG,		"log" },
+#endif
+	{ MNT_IGNORE,		"hidden" },
+	{ 0, NULL }
+};
+#endif
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 static struct opt {
 	int o_opt;
 	const char *o_name;
@@ -79,8 +103,12 @@ static struct opt {
 	{ MNT_NOCLUSTERW,	"noclusterw" },
 	{ MNT_SUIDDIR,		"suiddir" },
 	{ MNT_SOFTDEP,		"soft-updates" },
+#ifdef MNT_MULTILABEL
 	{ MNT_MULTILABEL,	"multilabel" },
+#endif
+#ifdef MNT_ACLS
 	{ MNT_ACLS,		"acls" },
+#endif
 #ifdef MNT_GJOURNAL
 	{ MNT_GJOURNAL,		"gjournal" },
 #endif
@@ -337,7 +365,7 @@ populate_ui_from_gconf (GnomeMountProper
 	g_object_unref (gconf_client);
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 struct mtab_handle
 {
   struct statfs	*mounts;
@@ -345,6 +373,14 @@ struct mtab_handle
   int		iter;
 };
 #endif
+#ifdef __NetBSD__
+struct mtab_handle
+{
+  struct statvfs *mounts;
+  int		n_mounts;
+  int		iter;
+};
+#endif
 
 /* borrowed from gtk/gtkfilesystemunix.c in GTK+ on 02/23/2006 */
 static void
@@ -454,7 +490,7 @@ out:
 static gboolean
 mtab_open (gpointer *handle)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	struct mtab_handle *mtab;
 
 	mtab = g_new0 (struct mtab_handle, 1);
@@ -475,7 +511,7 @@ mtab_open (gpointer *handle)
 static gboolean
 mtab_next (gpointer handle, char **device_file, char **mount_options, char **mount_fstype)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	struct mtab_handle *mtab = handle;
 
 	if (mtab->iter < mtab->n_mounts) {
@@ -484,7 +520,11 @@ mtab_next (gpointer handle, char **devic
 		GString *optstr;
 
 		optstr = g_string_new("");
+#if defined(__NetBSD__)
+		flags = mtab->mounts[mtab->iter].f_flag & MNT_VISFLAGMASK;
+#else
 		flags = mtab->mounts[mtab->iter].f_flags & MNT_VISFLAGMASK;
+#endif
 
 		for (o = optnames; flags && o->o_opt; o++) {
 			if (flags & o->o_opt) {
@@ -517,7 +557,7 @@ mtab_next (gpointer handle, char **devic
 static void
 mtab_close (gpointer handle)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	g_free (handle);
 #else
 	fclose (handle);
