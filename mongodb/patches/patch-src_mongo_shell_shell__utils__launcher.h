$NetBSD: patch-src_mongo_shell_shell__utils__launcher.h,v 1.1 2013/06/03 13:58:35 fhajny Exp $

Fix as per https://jira.mongodb.org/browse/SERVER-9753
--- src/mongo/shell/shell_utils_launcher.h.orig	2013-04-22 14:48:39.000000000 +0000
+++ src/mongo/shell/shell_utils_launcher.h	2013-05-30 12:43:17.108737513 +0000
@@ -73,7 +73,7 @@ namespace mongo {
             /** @return pid for a registered port. */
             pid_t pidForPort( int port ) const;
             /** @return port (-1 if doesn't exist) for a registered pid. */
-            int portForPid( int port ) const;
+            int portForPid( pid_t pid ) const;
             /** Register an unregistered port. */
             void registerPort( int port, pid_t pid, int output );
             void deletePort( int port );
