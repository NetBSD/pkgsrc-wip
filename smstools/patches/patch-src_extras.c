$NetBSD$

No NAME_MAX in POSIX.

--- src/extras.c.orig	2010-09-21 09:15:45.000000000 +0000
+++ src/extras.c
@@ -519,7 +519,7 @@ int getfile(int trust_directory, char *d
   // 3.1.12: Collect filenames:
   typedef struct
   {
-    char fname[NAME_MAX + 1];
+    char fname[FILENAME_MAX + 1];
     time_t mtime;
   } _candidate;
 
