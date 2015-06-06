$NetBSD: patch-src_wtmp-helper.c,v 1.1 2015/06/06 13:52:41 krytarowski Exp $

Use portable symbol _PATH_WTMPX in the place of WTMPX_FILENAME.

--- src/wtmp-helper.c.orig	2014-11-04 03:46:00.000000000 +0000
+++ src/wtmp-helper.c
@@ -60,8 +60,8 @@ wtmp_helper_start (void)
                 if (setutxdb (UTXDB_LOG, NULL) != 0) {
                         return FALSE;
                 }
-#elif defined(WTMPX_FILENAME)
-                if (utmpxname (WTMPX_FILENAME) != 0) {
+#elif defined(_PATH_WTMPX)
+                if (utmpxname (_PATH_WTMPX) != 0) {
                         return FALSE;
                 }
 
@@ -212,8 +212,8 @@ wtmp_helper_entry_generator (GHashTable 
 const gchar *
 wtmp_helper_get_path_for_monitor (void)
 {
-#if defined(WTMPX_FILENAME)
-        return WTMPX_FILENAME;
+#if defined(_PATH_WTMPX)
+        return _PATH_WTMPX;
 #elif defined(__FreeBSD__)
         return "/var/log/utx.log";
 #else
