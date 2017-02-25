$NetBSD$

--- src/daemon.c.orig	2017-01-23 19:49:04.000000000 +0000
+++ src/daemon.c
@@ -117,7 +117,7 @@ int become_user(const char *username, in
         ngroups = 0;
     }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
     if(setregid(gid, gid) != 0) {
 #else
     if(setresgid(gid, gid, gid) != 0) {
@@ -126,7 +126,7 @@ int become_user(const char *username, in
         return -1;
     }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
     if(setreuid(uid, uid) != 0) {
 #else
     if(setresuid(uid, uid, uid) != 0) {
