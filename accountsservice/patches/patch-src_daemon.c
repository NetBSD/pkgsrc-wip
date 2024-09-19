$NetBSD$

--- src/daemon.c.orig	2019-04-23 15:16:09.000000000 +0000
+++ src/daemon.c
@@ -36,6 +36,10 @@
 #include <errno.h>
 #include <sys/types.h>
 
+#ifdef HAVE_GRP_H
+#include <grp.h> /* getgrnam */
+#endif
+
 #include <glib.h>
 #include <glib/gi18n.h>
 #include <glib-object.h>
@@ -49,7 +53,11 @@
 #include "util.h"
 
 #define PATH_PASSWD "/etc/passwd"
+#if defined (HAVE_SHADOW_H)
 #define PATH_SHADOW "/etc/shadow"
+#elif defined (_PATH_MASTERPASSWD)
+#define PATH_SHADOW _PATH_MASTERPASSWD
+#endif
 #define PATH_GROUP "/etc/group"
 
 enum {
@@ -1096,7 +1104,7 @@ daemon_create_user_authorized_cb (Daemon
         CreateUserData *cd = data;
         User *user;
         g_autoptr(GError) error = NULL;
-        const gchar *argv[9];
+        const gchar *argv[11];
         g_autofree gchar *admin_groups = NULL;
 
         if (getpwnam (cd->user_name) != NULL) {
@@ -1119,9 +1127,17 @@ daemon_create_user_authorized_cb (Daemon
 
                 argv[4] = "-G";
                 argv[5] = admin_groups;
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+		argv[6] = "-L";
+		argv[7] = "staff";
+		argv[8] = "--";
+		argv[9] = cd->user_name;
+		argv[10] = NULL;
+#else
                 argv[6] = "--";
                 argv[7] = cd->user_name;
                 argv[8] = NULL;
+#endif
         }
         else if (cd->account_type == ACCOUNT_TYPE_STANDARD) {
                 argv[4] = "--";
@@ -1302,6 +1318,34 @@ daemon_delete_user_authorized_cb (Daemon
                 return;
         }
 
+/*
+ * Under OpenBSD there is no /etc/login.defs (for USERGROUPS_ENAB), so
+ * we need to explicitely remove the user's group if it contains no more
+ * members and matches the username.
+ */
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+        struct group *grp;
+        GError *grperror;
+        const gchar *grpargv[3];
+
+        grp = getgrnam (pwent->pw_name);
+
+        if ((grp != NULL) && (*grp->gr_name == *pwent->pw_name) && (*grp->gr_mem == NULL)) {
+                sys_log (context, "delete group '%d'", pwent->pw_gid);
+
+                grpargv[0] = "/usr/sbin/groupdel";
+                grpargv[1] = pwent->pw_name;
+                grpargv[2] = NULL;
+
+                grperror = NULL;
+                if (!spawn_with_login_uid (context, grpargv, &grperror)) {
+                    throw_error (context, ERROR_FAILED, "running '%s' failed: %s", grpargv[0], grperror->message);
+                    g_error_free (grperror);
+                    return;
+                }
+        }
+#endif
+
         sys_log (context, "delete user '%s' (%d)", pwent->pw_name, ud->uid);
 
         user = daemon_local_find_user_by_id (daemon, ud->uid);
@@ -1320,11 +1364,18 @@ daemon_delete_user_authorized_cb (Daemon
 
         argv[0] = "/usr/sbin/userdel";
         if (ud->remove_files) {
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+                argv[1] = "-r";
+                argv[2] = "--";
+                argv[3] = pwent->pw_name;
+                argv[4] = NULL;
+#else
                 argv[1] = "-f";
                 argv[2] = "-r";
                 argv[3] = "--";
                 argv[4] = pwent->pw_name;
                 argv[5] = NULL;
+#endif
         }
         else {
                 argv[1] = "-f";
