$NetBSD$

--- src/wtmp-helper.c.orig	2014-11-04 03:46:00.000000000 +0000
+++ src/wtmp-helper.c
@@ -56,12 +56,12 @@ user_previous_login_free (UserPreviousLo
 static gboolean
 wtmp_helper_start (void)
 {
-#if defined(UTXDB_LOG)
+#if defined(HAVE_SETUTXDB)
                 if (setutxdb (UTXDB_LOG, NULL) != 0) {
                         return FALSE;
                 }
-#elif defined(WTMPX_FILENAME)
-                if (utmpxname (WTMPX_FILENAME) != 0) {
+#elif defined(PATH_WTMP)
+                if (utmpxname (PATH_WTMP) != 0) {
                         return FALSE;
                 }
 
@@ -212,13 +212,7 @@ wtmp_helper_entry_generator (GHashTable 
 const gchar *
 wtmp_helper_get_path_for_monitor (void)
 {
-#if defined(WTMPX_FILENAME)
-        return WTMPX_FILENAME;
-#elif defined(__FreeBSD__)
-        return "/var/log/utx.log";
-#else
-#error Do not know which filename to watch for wtmp changes
-#endif
+        return PATH_WTMP;
 }
 
 #else /* HAVE_UTMPX_H */
