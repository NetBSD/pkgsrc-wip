$NetBSD$

NetBSD does not have fgetpwent_r.

--- src/io.c.orig	2023-08-18 20:31:44.042534550 +0000
+++ src/io.c
@@ -1208,7 +1208,7 @@ static void idcache_load_users(int root_
 	do {
 #ifdef HAVE_FGETPWENT_R
 		fgetpwent_r(in, &pwent, buf, sizeof(buf), &pwd);
-#elif !defined(__APPLE__)
+#elif !defined(__NetBSD__)
 		pwd = fgetpwent(in);
 #else
 # warning macOS does not support nested /etc/passwd databases, using system one.
@@ -1241,7 +1241,7 @@ static void idcache_load_groups(int root
 	do {
 #ifdef HAVE_FGETGRENT_R
 		fgetgrent_r(in, &grent, buf, sizeof(buf), &grp);
-#elif !defined(__APPLE__)
+#elif !defined(__NetBSD__)
 		grp = fgetgrent(in);
 #else
 # warning macOS does not support nested /etc/group databases, using system one.
