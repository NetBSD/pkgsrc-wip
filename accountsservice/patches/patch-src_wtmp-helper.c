$NetBSD$

--- src/wtmp-helper.c.orig	2014-11-04 03:46:00.000000000 +0000
+++ src/wtmp-helper.c
@@ -56,21 +56,32 @@ user_previous_login_free (UserPreviousLo
 static gboolean
 wtmp_helper_start (void)
 {
-#if defined(UTXDB_LOG)
-                if (setutxdb (UTXDB_LOG, NULL) != 0) {
-                        return FALSE;
-                }
-#elif defined(WTMPX_FILENAME)
-                if (utmpxname (WTMPX_FILENAME) != 0) {
-                        return FALSE;
-                }
+#if HAVE_FREEBSD
+        if (setutxdb (UTXDB_LOG, NULL) != 0) {
+                return FALSE;
+        }
+#elif HAVE_LINUX
+        if (utmpxname (WTMPX_FILENAME) != 0) {
+                return FALSE;
+        }
+
+        setutxent ();
+#elif HAVE_NETBSD
+        if (utmpxname (_PATH_WTMPX) != 0) {
+                return FALSE;
+        }
 
-                setutxent ();
+        setutxent ();
+#elif HAVE_SOLARIS
+        if (utmpxname (WTMPX_FILE) != 0) {
+                return FALSE;
+        }
+
+        setutxent ();
 #else
 #error You have utmpx.h, but no known way to use it for wtmp entries
 #endif
-
-                return TRUE;
+        return TRUE;
 }
 
 struct passwd *
@@ -212,12 +223,16 @@ wtmp_helper_entry_generator (GHashTable 
 const gchar *
 wtmp_helper_get_path_for_monitor (void)
 {
-#if defined(WTMPX_FILENAME)
-        return WTMPX_FILENAME;
-#elif defined(__FreeBSD__)
+#if HAVE_FREEBSD
         return "/var/log/utx.log";
+#elif HAVE_LINUX
+        return WTMPX_FILENAME;
+#elif HAVE_NETBSD
+        return _PATH_WTMPX;
+#elif HAVE_SOLARIS
+        return WTMPX_FILE;
 #else
-#error Do not know which filename to watch for wtmp changes
+#error You have utmpx.h, but no known way to use it for wtmp entries
 #endif
 }
 
