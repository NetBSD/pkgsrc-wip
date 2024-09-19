$NetBSD$

--- src/session-child.c.orig	2018-09-05 01:33:31.000000000 +0000
+++ src/session-child.c
@@ -13,7 +13,9 @@
 #include <grp.h>
 #include <glib.h>
 #include <security/pam_appl.h>
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 #include <utmp.h>
+#endif
 #include <utmpx.h>
 #include <sys/mman.h>
 
@@ -192,6 +194,7 @@ read_xauth (void)
     return x_authority_new (x_authority_family, x_authority_address, x_authority_address_length, x_authority_number, x_authority_name, x_authority_data, x_authority_data_length);
 }
 
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 /* GNU provides this but we can't rely on that so let's make our own version */
 static void
 updwtmpx (const gchar *wtmp_file, struct utmpx *ut)
@@ -213,6 +216,7 @@ updwtmpx (const gchar *wtmp_file, struct
 
     updwtmp (wtmp_file, &u);
 }
+#endif
 
 #if HAVE_LIBAUDIT
 static void
@@ -363,7 +367,9 @@ session_child_run (int argc, char **argv
             ut.ut_tv.tv_sec = tv.tv_sec;
             ut.ut_tv.tv_usec = tv.tv_usec;
 
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
             updwtmpx ("/var/log/btmp", &ut);
+#endif
 
 #if HAVE_LIBAUDIT
             audit_event (AUDIT_USER_LOGIN, username, -1, remote_host_name, tty, FALSE);
@@ -708,7 +714,9 @@ session_child_run (int argc, char **argv
             if (!pututxline (&ut))
                 g_printerr ("Failed to write utmpx: %s\n", strerror (errno));
             endutxent ();
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
             updwtmpx ("/var/log/wtmp", &ut);
+#endif
 
 #if HAVE_LIBAUDIT
             audit_event (AUDIT_USER_LOGIN, username, uid, remote_host_name, tty, TRUE);
@@ -749,7 +757,9 @@ session_child_run (int argc, char **argv
             if (!pututxline (&ut))
                 g_printerr ("Failed to write utmpx: %s\n", strerror (errno));
             endutxent ();
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
             updwtmpx ("/var/log/wtmp", &ut);
+#endif
 
 #if HAVE_LIBAUDIT
             audit_event (AUDIT_USER_LOGOUT, username, uid, remote_host_name, tty, TRUE);
