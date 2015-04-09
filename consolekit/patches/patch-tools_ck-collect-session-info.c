$NetBSD: patch-tools_ck-collect-session-info.c,v 1.3 2015/04/09 13:56:05 krytarowski Exp $

XXX revert 4f88228f31a63c026c424a92827f26ad7535275c
The Kit people assume the world runs Linux and PAM, see
https://bugs.freedesktop.org/show_bug.cgi?id=28377

--- tools/ck-collect-session-info.c.orig	2010-09-03 13:54:31.000000000 +0000
+++ tools/ck-collect-session-info.c
@@ -274,7 +274,8 @@ fill_x11_info (SessionInfo *si)
         si->x11_display_device = ck_process_stat_get_tty (xorg_stat);
         ck_process_stat_free (xorg_stat);
 
-        /* don't set is-local here - let the daemon do that */
+        si->is_local = TRUE;
+        si->is_local_is_set = TRUE;
 
         g_free (si->remote_host_name);
         si->remote_host_name = NULL;
@@ -303,6 +304,13 @@ fill_session_info (SessionInfo *si)
 
         fill_x11_info (si);
 
+        if (! si->is_local_is_set) {
+               /* FIXME: how should we set this? */
+               /* non x11 sessions must be local I guess */
+               si->is_local = TRUE;
+               si->is_local_is_set = TRUE;
+        }
+
         res = ck_unix_pid_get_login_session_id (si->pid, &si->login_session_id);
         if (! res) {
                 si->login_session_id = NULL;
