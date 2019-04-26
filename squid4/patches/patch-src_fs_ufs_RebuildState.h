$NetBSD$

--- src/fs/ufs/RebuildState.h.orig	2019-02-19 02:46:22.000000000 +0000
+++ src/fs/ufs/RebuildState.h
@@ -54,7 +54,7 @@ public:
     dirent_t *entry;
     DIR *td;
     char fullpath[MAXPATHLEN];
-    char fullfilename[MAXPATHLEN*2];
+    char fullfilename[MAXPATHLEN*3];
 
     StoreRebuildData counts;
 
