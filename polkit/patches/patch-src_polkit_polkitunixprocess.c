$NetBSD: patch-src_polkit_polkitunixprocess.c,v 1.3 2015/04/02 14:55:36 bsiegert Exp $

* NetBSD support

--- src/polkit/polkitunixprocess.c.orig	2014-01-14 22:42:25.000000000 +0000
+++ src/polkit/polkitunixprocess.c
@@ -29,6 +29,10 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #endif
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
@@ -89,6 +93,9 @@ static gint _polkit_unix_process_get_own
 #ifdef HAVE_FREEBSD
 static gboolean get_kinfo_proc (gint pid, struct kinfo_proc *p);
 #endif
+#if defined(__NetBSD__)
+static gboolean get_kinfo_proc (gint pid, struct kinfo_proc2 *p);
+#endif
 
 G_DEFINE_TYPE_WITH_CODE (PolkitUnixProcess, polkit_unix_process, G_TYPE_OBJECT,
                          G_IMPLEMENT_INTERFACE (POLKIT_TYPE_SUBJECT, subject_iface_init)
@@ -554,12 +561,38 @@ get_kinfo_proc (pid_t pid, struct kinfo_
 }
 #endif
 
+#ifdef __NetBSD__
+static gboolean
+get_kinfo_proc (pid_t pid, struct kinfo_proc2 *p)
+{
+  int name[6];
+  u_int namelen;
+  size_t sz;
+
+  sz = sizeof(*p);
+  namelen = 0;
+  name[namelen++] = CTL_KERN;
+  name[namelen++] = KERN_PROC2;
+  name[namelen++] = KERN_PROC_PID;
+  name[namelen++] = pid;
+  name[namelen++] = sz;
+  name[namelen++] = 1;
+
+  if (sysctl (name, namelen, p, &sz, NULL, 0) == -1) {
+    perror("sysctl kern.proc2.pid");
+    return FALSE;
+  }
+
+  return TRUE;
+}
+#endif
+
 static guint64
 get_start_time_for_pid (pid_t    pid,
                         GError **error)
 {
   guint64 start_time;
-#ifndef HAVE_FREEBSD
+#if !defined(HAVE_FREEBSD) || !defined(__NetBSD__)
   gchar *filename;
   gchar *contents;
   size_t length;
@@ -631,6 +664,26 @@ get_start_time_for_pid (pid_t    pid,
  out:
   g_free (filename);
   g_free (contents);
+#elif defined(__NetBSD__)
+  struct kinfo_proc2 p;
+
+  start_time = 0;
+
+  if (! get_kinfo_proc (pid, &p))
+    {
+      g_set_error (error,
+                   POLKIT_ERROR,
+                   POLKIT_ERROR_FAILED,
+                   "Error obtaining start time for %d (%s)",
+                   (gint) pid,
+                   g_strerror (errno));
+      goto out;
+    }
+
+  start_time = (guint64) p.p_ustart_sec;
+
+out:
+
 #else
   struct kinfo_proc p;
 
@@ -664,6 +717,8 @@ _polkit_unix_process_get_owner (PolkitUn
   gchar **lines;
 #ifdef HAVE_FREEBSD
   struct kinfo_proc p;
+#elif defined(__NetBSD__)
+  struct kinfo_proc2 p;
 #else
   gchar filename[64];
   guint n;
@@ -676,7 +731,7 @@ _polkit_unix_process_get_owner (PolkitUn
   lines = NULL;
   contents = NULL;
 
-#ifdef HAVE_FREEBSD
+#if defined(HAVE_FREEBSD) || defined(__NetBSD__)
   if (get_kinfo_proc (process->pid, &p) == 0)
     {
       g_set_error (error,
@@ -688,7 +743,11 @@ _polkit_unix_process_get_owner (PolkitUn
       goto out;
     }
 
+#ifdef __NetBSD__
+  result = p.p_uid;
+#else
   result = p.ki_uid;
+#endif
 #else
 
   /* see 'man proc' for layout of the status file
