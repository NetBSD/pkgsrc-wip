$NetBSD$

--- egg/egg-unix-credentials.h.orig	2014-09-23 07:45:13.000000000 +0000
+++ egg/egg-unix-credentials.h
@@ -43,8 +43,6 @@ int        egg_unix_credentials_read    
 
 int        egg_unix_credentials_write          (int sock);
 
-int        egg_unix_credentials_setup          (int sock);
-
 char*      egg_unix_credentials_executable     (pid_t pid);
 
 #endif /*EGGUNIXCREDENTIALS_H_*/
