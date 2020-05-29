$NetBSD$

--- src/user.c.orig	2019-04-23 15:16:09.000000000 +0000
+++ src/user.c
@@ -202,7 +202,20 @@ user_update_from_pwent (User          *u
         if (spent)
                 passwd = spent->sp_pwdp;
 
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+        pw = getpwnam_shadow (pwent->pw_name);
+        if (pw)
+                passwd = pw->pw_passwd;
+        if (g_strcmp0(passwd, "skey") == 0)
+                passwd = NULL;
+#endif
+
+
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+        if (passwd && passwd[0] == '*') {
+#else
         if (passwd && passwd[0] == '!') {
+#endif
                 locked = TRUE;
         }
         else {
@@ -1602,7 +1615,11 @@ user_change_locked_authorized_cb (Daemon
                          accounts_user_get_user_name (ACCOUNTS_USER (user)),
                          accounts_user_get_uid (ACCOUNTS_USER (user)));
                 argv[0] = "/usr/sbin/usermod";
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+                argv[1] = locked ? "-Z" : "-U";
+#else
                 argv[1] = locked ? "-L" : "-U";
+#endif
                 argv[2] = "--";
                 argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
                 argv[4] = NULL;
