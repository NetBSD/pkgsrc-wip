$NetBSD$

A set-user-ID-root program wishing to temporarily drop root privileges, assume
the identity of an unprivileged user, and then regain root privileges afterward
cannot use setuid(2). It can accomplish this with seteuid(2).

--- common/privileges.c.orig	2018-04-10 03:07:52.000000000 +0000
+++ common/privileges.c
@@ -23,13 +23,11 @@ privileges_drop (uid_t uid, gid_t gid)
 #ifdef HAVE_SETRESGID
     g_assert (setresgid (gid, gid, -1) == 0);
 #else
-    g_assert (setgid (gid) == 0);
     g_assert (setegid (gid) == 0);
 #endif
 #ifdef HAVE_SETRESUID
     g_assert (setresuid (uid, uid, -1) == 0);
 #else
-    g_assert (setuid (uid) == 0);
     g_assert (seteuid (uid) == 0);
 #endif
 }
@@ -40,13 +38,11 @@ privileges_reclaim (void)
 #ifdef HAVE_SETRESUID
     g_assert (setresuid (0, 0, -1) == 0);
 #else
-    g_assert (setuid (0) == 0);
     g_assert (seteuid (0) == 0);
 #endif
 #ifdef HAVE_SETRESGID
     g_assert (setresgid (0, 0, -1) == 0);
 #else
-    g_assert (setgid (0) == 0);
     g_assert (setegid (0) == 0);
 #endif
 }
